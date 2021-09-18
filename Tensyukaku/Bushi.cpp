#include <DxLib.h>
#include <vector>
#include <sstream>
#include "EnemyBase.h"
#include "Bushi.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
#include "BushiMotionCollision.h"
#include "PrivateCollision.h"
/*
	武士
*/
using namespace BInfo;
Bushi::Bushi(int x,int y,bool flip)
{
	_x = x;
	_y = y;
	_isFlip = flip;
	Init();
	LoadActionGraph();
	LoadActionSE();
};

Bushi::~Bushi() {
	
};

void Bushi::Init() {
	_w = GRAPH_WIDTH;
	_h = GRAPH_HEIGHT;
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
	_State=ENEMYSTATE::APPEAR;
	_Life = LIFE_MAX;
	_Spd = SPEED;
	_Alpha = 0;
}
void Bushi::Process(Game& g) {
	EnemyBase::Process(g);
	switch (_State) {
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
	default:
		break;
	}
	DamageJudge(g);
}

void Bushi::Draw(Game& g) {	
#ifdef _DEBUG
	DebugDraw(g);
#endif
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,_Alpha);
	EnemyBase::Draw(g);
}

void Bushi::Delete(Game& g) {
		g.GetOS()->Del(this);
}

//被ダメ判定&押し出しの処理
void Bushi::DamageJudge(Game& g) {
	//敵とプレイヤーのアクションの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		OBJECTTYPE objType = (*ite)->GetObjType();
		switch (objType) {
		case ObjectBase::OBJECTTYPE::MIDDLEATTACK:
			// 敵とプレイヤーの中段攻撃オブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
				_Life -= 3;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
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
					}
				}
			}
			break;
		case ObjectBase::OBJECTTYPE::LOWATTACK:
			// 敵とプレイヤーの下段攻撃オブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
				_Life--;
				if (_Life <= 0) {
					_State = ENEMYSTATE::DEAD;
				}
				else { _State = ENEMYSTATE::DAMAGE; }
				_Action_Cnt = _Cnt;
				_Anime["Attack"] = 0;
			
			}
			break;
		case ObjectBase::OBJECTTYPE::IAI:
		case ObjectBase::OBJECTTYPE::FLAME:
			// 敵とプレイヤーの居合&行燈の炎オブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				_Life -= 3;
				_Action_Cnt = _Cnt;
				_State = ENEMYSTATE::DEAD;
			}
			break;
		case ObjectBase::OBJECTTYPE::PLAYER:
			// プレイヤーとその敵の当たり判定を行う
			if (IsHit(*(*ite)) == true) {
				_x = _Before_x;
			}
			break;
		default:
			break;
		}
	}
}

//武士の画像読み込み関数
void Bushi::LoadActionGraph() {
	_GrAll["Appear"].resize(APPEAR_ANIMEMAX);
	ResourceServer::LoadDivGraph(APPEAR_GRAPHNAME, APPEAR_ANIMEMAX, APPEAR_WIDTHCOUNT, APPEAR_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Appear"].data());
	_GrAll["Patrol"].resize(PATROL_ANIMEMAX);
	ResourceServer::LoadDivGraph(PATROL_GRAPHNAME, PATROL_ANIMEMAX, PATROL_WIDTHCOUNT, PATROL_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Patrol"].data());
	_GrAll["Coming"].resize(COMING_ANIMEMAX);
	ResourceServer::LoadDivGraph(COMING_GRAPHNAME, COMING_ANIMEMAX, COMING_WIDTHCOUNT, COMING_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Coming"].data());
	_GrAll["Attack"].resize(ATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(ATTACK_GRAPHNAME, ATTACK_ANIMEMAX, ATTACK_WIDTHCOUNT, ATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Attack"].data());
	_GrAll["Damage"].resize(DAMAGE_ANIMEMAX);
	ResourceServer::LoadDivGraph(DAMAGE_GRAPHNAME, DAMAGE_ANIMEMAX, DAMAGE_WIDTHCOUNT, DAMAGE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Damage"].data());
	_GrAll["Dead"].resize(DEAD_ANIMEMAX);
	ResourceServer::LoadDivGraph(DEAD_GRAPHNAME, DEAD_ANIMEMAX, DEAD_WIDTHCOUNT, DEAD_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Dead"].data());
}

//武士のSE読み込み関数
void Bushi::LoadActionSE() {
	_Se["Attack"] = ResourceServer::LoadSoundMem("se/Enemy/BushiAttack.wav");
}

//デバッグ用関数
void Bushi::DebugDraw(Game& g) {
	switch (_State) {
	case ENEMYSTATE::PATROL:
		if (_isFlip == false) {
			PrivateCollision bpc(_x + _hit_x - PATROL_WIDTH, _y - _hit_h,PATROL_WIDTH,PATROL_HEIGHT);
			bpc.SetColor(std::make_tuple(0, 255, 0));
			bpc.Draw(g);
		}
		if (_isFlip == true) {
			PrivateCollision bpc(_x - _hit_x, _y - _hit_h,PATROL_WIDTH, PATROL_HEIGHT);
			bpc.SetColor(std::make_tuple(0, 255, 0));
			bpc.Draw(g);
		}
		break;
	case ENEMYSTATE::COMING:
		if (_isFlip == false) {
			PrivateCollision bcc(_x + _hit_x - COMING_WIDTH, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
			bcc.SetColor(std::make_tuple(255, 255, 0));
			bcc.Draw(g);
		}
		if (_isFlip == true) {
			PrivateCollision bcc(_x - _hit_x, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
			bcc.SetColor(std::make_tuple(255, 255, 0));
			bcc.Draw(g);
		}
		break;
	}
}