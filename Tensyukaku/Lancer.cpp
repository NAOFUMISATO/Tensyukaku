/*
	槍兵
*/
#include <DxLib.h>
#include <vector>
#include <sstream>
#include "EnemyBase.h"
#include "Lancer.h"
#include "LancerMotionCollision.h"
#include "MiddleBlood.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
#include "PrivateCollision.h"

using namespace LInfo;
//槍兵のコンストラクタ 	:	引数（X座標,Y座標,反転判定）
Lancer::Lancer(int x, int y, bool flip)
{
	_x = x;
	_y = y;
	_isflip = flip;
	Init();
	LoadPicture();
	LoadSE();
	VolumeInit();
};

Lancer::~Lancer() {

};
/*----------初期化----------*/
void Lancer::Init() {
	_sort = 6;
	_w = GRAPH_WIDTH;
	_h = GRAPH_HEIGHT;
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
	_state = ENEMYSTATE::APPEAR;
	_life = LIFE_MAX;
	_spd = SPEED;
	_alpha = 0;
}
/*----------更新-----------*/
void Lancer::Process(Game& g) {
	EnemyBase::Process(g);
	//効果音ボリューム変更
	VolumeChange();
	/*---状態毎の処理---*/
	switch (_state) {
		//出現状態
	case ENEMYSTATE::APPEAR:
		Appear(g);
		break;
		//索敵状態
	case ENEMYSTATE::PATROL:
		Patrol(g);
		break;
		//追跡状態
	case ENEMYSTATE::COMING:
		Coming(g);
		break;
		//攻撃状態
	case ENEMYSTATE::ATTACK:
		Attack(g);
		break;
		//死亡状態
	case ENEMYSTATE::DEAD:
		Dead(g);
		break;
	}
	//当たり判定の処理
	HitJudge(g);
}
/*----------描画----------*/
void Lancer::Draw(Game& g) {
#ifdef _DEBUG
	DebugDraw(g);
#endif 
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
	EnemyBase::Draw(g);
}
void Lancer::Delete(Game& g) {
	g.GetOS()->Del(this);
}
//被ダメ判定&押し出しの処理
void Lancer::HitJudge(Game& g) {
	//敵とプレイヤーアクションオブジェクトの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++){
		OBJECTTYPE objType = (*ite)->GetObjType();
		switch (objType) {
			//プレイヤーの攻撃
		case ObjectBase::OBJECTTYPE::MIDDLEATTACK:
		case ObjectBase::OBJECTTYPE::LOWATTACK:
			if (IsHit(*(*ite)) == true){
				(*ite)->Delete(g);
				_life--;
				_action_cnt = _cnt;
				_state = ENEMYSTATE::DEAD;
				//SE
				PlaySoundMem(_se["DeadV"],DX_PLAYTYPE_BACK,true);
				//居合ゲージの増加
				for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++){
					// iteはプレイヤーか？
					if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER){
						//プレイヤーの居合ゲージがMAXでないならプレイヤーの居合ゲージを増加させる
						auto ig = (*ite)->GetGauge();
						if (ig < PLAYER_IAI_MAX) {
							(*ite)->SetGauge(ig += 1);
						}
						//エフェクト
						auto flip = (*ite)->GetFlip();
						auto bloodtype = GetRand(2);
						auto mb = new MiddleBlood(_x + _gx, _y + _gy, flip, bloodtype);
						g.GetOS()->Add(mb);
					}
				}
			}
			break;
			//居合及び行燈の炎
		case ObjectBase::OBJECTTYPE::IAI:
		case ObjectBase::OBJECTTYPE::FLAME:
		case ObjectBase::OBJECTTYPE::MUGENFLAME:
			// 敵とプレイヤーの居合オブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true){
				_life--;
				_action_cnt = _cnt;
				_state = ENEMYSTATE::DEAD;
			}
			break;
			//プレイヤー
		case ObjectBase::OBJECTTYPE::PLAYER:
			// プレイヤーとその敵の当たり判定を行う
			if (IsHit(*(*ite)) == true) {
				_x = _before_x;
			}
			break;
		default:
			break;
		}
	}
}

//盾兵の画像読み込み関数
void Lancer::LoadPicture() {
	_grall["Appear"].resize(APPEAR_ANIMEMAX);
	ResourceServer::LoadDivGraph(APPEAR_GRAPHNAME, APPEAR_ANIMEMAX, APPEAR_WIDTHCOUNT, APPEAR_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Appear"].data());
	_grall["Patrol"].resize(PATROL_ANIMEMAX);
	ResourceServer::LoadDivGraph(PATROL_GARAPHNAME, PATROL_ANIMEMAX, PATROL_WIDTHCOUNT, PATROL_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Patrol"].data());
	_grall["Coming"].resize(COMING_ANIMEMAX);
	ResourceServer::LoadDivGraph(COMING_GRAPHNAME, COMING_ANIMEMAX, COMING_WIDTHCOUNT, COMING_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Coming"].data());
	_grall["Attack"].resize(ATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(ATTACK_GRAPHNAME, ATTACK_ANIMEMAX, ATTACK_WIDTHCOUNT, ATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Attack"].data());
	_grall["Dead"].resize(DEAD_ANIMEMAX);
	ResourceServer::LoadDivGraph(DEAD_GRAPHNAME, DEAD_ANIMEMAX, DEAD_WIDTHCOUNT, DEAD_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Dead"].data());
}

//効果音読み込み関数
void Lancer::LoadSE() {
	_se["Attack"] = ResourceServer::LoadSoundMem("se/Enemy/LancerAttack.wav");
	_se["DeadV"] = ResourceServer::LoadSoundMem("se/Voice/Dead06.wav");
}

//効果音ボリューム初期値設定関数
void	Lancer::VolumeInit() {
	_vpal["Attack"] = 255;
	_vpal["DeadV"] = 180;
}

//ボリューム変更関数
void	Lancer::VolumeChange() {
	ChangeVolumeSoundMem(_vpal["Attack"], _se["Attack"]);
	ChangeVolumeSoundMem(_vpal["DeadV"], _se["DeadV"]);
}


//デバッグ用関数
void Lancer::DebugDraw(Game& g) {
	switch (_state) {
	case ENEMYSTATE::PATROL:
		if (_isflip == false) {
			PrivateCollision pc(_x + _hit_x - PATROL_WIDTH, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);
			PrivateCollision bpc(_x - _hit_x, _y - _hit_h, PATROL_BACKWIDTH, PATROL_HEIGHT);
			pc.SetColor(std::make_tuple(0, 255, 0));
			bpc.SetColor(std::make_tuple(0, 128, 128));
			pc.Draw(g);
			bpc.Draw(g);
		}
		if (_isflip == true) {
			PrivateCollision pc(_x - _hit_x, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);
			PrivateCollision bpc(_x + _hit_x - PATROL_BACKWIDTH, _y - _hit_h, PATROL_BACKWIDTH, PATROL_HEIGHT);
			pc.SetColor(std::make_tuple(0, 255, 0));
			bpc.SetColor(std::make_tuple(0, 128, 128));
			pc.Draw(g);
			bpc.Draw(g);
		}
		break;
	case ENEMYSTATE::COMING:
		if (_isflip == false) {
			PrivateCollision cc(_x + _hit_x - COMING_WIDTH, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
			cc.SetColor(std::make_tuple(2555, 255, 0));
			cc.Draw(g);
		}
		if (_isflip == true) {
			PrivateCollision cc(_x - _hit_x, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
			cc.SetColor(std::make_tuple(255, 255, 0));
			cc.Draw(g);
		}
		break;
	}
}
