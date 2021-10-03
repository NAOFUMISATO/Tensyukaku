#include <DxLib.h>
#include <vector>
#include <sstream>
#include "EnemyBase.h"
#include "Busyo.h"
#include "Game.h"
#include "MiddleBlood.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
#include "BushiMotionCollision.h"
#include "PrivateCollision.h"
/*
	武将
*/
using namespace BsInfo;
Busyo::Busyo(int x, int y, bool flip):
	_noHit_Flag(false)
{
	_x = x;
	_y = y;
	_isflip = flip;
	Init();
	LoadPicture();
	LoadSE();
	VolumeInit();
};

Busyo::~Busyo() {

};

void Busyo::Init() {
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
void Busyo::Process(Game& g) {
	EnemyBase::Process(g);
	VolumeChange();
	switch (_state) {
	case ENEMYSTATE::APPEAR:
		Appear(g);
		break;
	case ENEMYSTATE::PATROL:
		Patrol(g);
		break;
	case ENEMYSTATE::COMING:
		Coming(g);
		break;
	case ENEMYSTATE::ATTACK:
		Attack(g);
		break;
	case ENEMYSTATE::DAMAGE:
		Damage(g);
		break;
	case ENEMYSTATE::DEAD:
		Dead(g);
		break;
	}
	HitJudge(g);
}

void Busyo::Draw(Game& g) {
#ifdef _DEBUG
	DebugDraw(g);
#endif
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
	EnemyBase::Draw(g);
}

void Busyo::Delete(Game& g) {
	g.GetOS()->Del(this);
}

//被ダメ判定&押し出しの処理
void Busyo::HitJudge(Game& g) {
	//敵とプレイヤーのアクションの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		OBJECTTYPE objType = (*ite)->GetObjType();
		switch (objType) {
		case ObjectBase::OBJECTTYPE::MIDDLEATTACK:
			// 敵とプレイヤーの中段攻撃オブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true&&_noHit_Flag==false)
			{
				(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
				_life -= 3;
				_action_cnt = _cnt;
				if (_life <= 0) {
					PlaySoundMem(_se["DeadV"], DX_PLAYTYPE_BACK, true);
					_state = ENEMYSTATE::DEAD;
					//居合ゲージの増加
					for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
					{
						// iteはプレイヤか？
						if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
						{
							auto ig = (*ite)->GetGauge();
							if (ig < PLAYER_IAI_MAX) {
								(*ite)->SetGauge(ig += 1);
							}
							auto mb = new MiddleBlood(_x + _gx, _y + _gy, (*ite)->GetFlip(), GetRand(2));
							g.GetOS()->Add(mb);
						}
					}
				}else {
					PlaySoundMem(_se["DamageV"], DX_PLAYTYPE_BACK, true);
					_state = ENEMYSTATE::DAMAGE; }
			}
			break;
		case ObjectBase::OBJECTTYPE::LOWATTACK:
			// 敵とプレイヤーの下段攻撃オブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true && _noHit_Flag == false)
			{
				(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
				_life--;
				if (_life <= 0) {
					PlaySoundMem(_se["DeadV"], DX_PLAYTYPE_BACK, true);
					_state = ENEMYSTATE::DEAD;
					//居合ゲージの増加
					for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
					{
						// iteはプレイヤか？
						if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
						{
							auto ig = (*ite)->GetGauge();
							if (ig < PLAYER_IAI_MAX) {
								(*ite)->SetGauge(ig += 1);
							}
							auto mb = new MiddleBlood(_x + _gx, _y + _gy, (*ite)->GetFlip(), GetRand(2));
							g.GetOS()->Add(mb);
						}
					}
				}
				else { 
					PlaySoundMem(_se["DamageV"], DX_PLAYTYPE_BACK, true);
					_state = ENEMYSTATE::DAMAGE; }
				_action_cnt = _cnt;
				_anime["Attack"] = 0;

			}
			break;
		case ObjectBase::OBJECTTYPE::IAI:
		case ObjectBase::OBJECTTYPE::FLAME:
		case ObjectBase::OBJECTTYPE::MUGENFLAME:
			// 敵とプレイヤーの居合&行燈の炎オブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				_life -= 3;
				_action_cnt = _cnt;
				_state = ENEMYSTATE::DEAD;
			}
			break;
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

//画像読み込み関数
void Busyo::LoadPicture() {
	_grall["Appear"].resize(APPEAR_ANIMEMAX);
	ResourceServer::LoadDivGraph(APPEAR_GRAPHNAME, APPEAR_ANIMEMAX, APPEAR_WIDTHCOUNT, APPEAR_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Appear"].data());
	_grall["Patrol"].resize(PATROL_ANIMEMAX);
	ResourceServer::LoadDivGraph(PATROL_GRAPHNAME, PATROL_ANIMEMAX, PATROL_WIDTHCOUNT, PATROL_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Patrol"].data());
	_grall["Coming"].resize(COMING_ANIMEMAX);
	ResourceServer::LoadDivGraph(COMING_GRAPHNAME, COMING_ANIMEMAX, COMING_WIDTHCOUNT, COMING_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Coming"].data());
	_grall["Attack"].resize(ATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(ATTACK_GRAPHNAME, ATTACK_ANIMEMAX, ATTACK_WIDTHCOUNT, ATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Attack"].data());
	_grall["Damage"].resize(DAMAGE_ANIMEMAX);
	ResourceServer::LoadDivGraph(DAMAGE_GRAPHNAME, DAMAGE_ANIMEMAX, DAMAGE_WIDTHCOUNT, DAMAGE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Damage"].data());
	_grall["Dead"].resize(DEAD_ANIMEMAX);
	ResourceServer::LoadDivGraph(DEAD_GRAPHNAME, DEAD_ANIMEMAX, DEAD_WIDTHCOUNT, DEAD_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Dead"].data());
}

//SE読み込み関数
void Busyo::LoadSE() {
	_se["Attack"] = ResourceServer::LoadSoundMem("se/Enemy/BushiAttack.wav");
	_se["DamageV"] = ResourceServer::LoadSoundMem("se/Voice/Dead01.wav");
	_se["DeadV"] = ResourceServer::LoadSoundMem("se/Voice/Dead04.wav");
}
//効果音ボリューム初期値設定関数
void	Busyo::VolumeInit() {
	_vpal["Attack"] = 255;
	_vpal["DamageV"] = 255;
	_vpal["DeadV"] = 255;
}

//ボリューム変更関数
void	Busyo::VolumeChange() {
	ChangeVolumeSoundMem(_vpal["Attack"], _se["Attack"]);
	ChangeVolumeSoundMem(_vpal["DamageV"], _se["DamageV"]);
	ChangeVolumeSoundMem(_vpal["DeadV"], _se["DeadV"]);
}
//デバッグ用関数
void Busyo::DebugDraw(Game& g) {
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
			cc.SetColor(std::make_tuple(255, 255, 0));
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