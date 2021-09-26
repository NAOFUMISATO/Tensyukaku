#include <DxLib.h>
#include <vector>
#include <sstream>
#include "EnemyBase.h"
#include "Shielder.h"
#include "ShielderMotionCollision.h"
#include "Shield.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
#include "player.h"
#include "PrivateCollision.h"

/*
	盾兵
*/
using namespace SInfo;
Shielder::Shielder(int x, int y, bool flip) :
	_ShieldAlive_Flag(true),
	_ShieldAttack_Flag(false),
	_ShieldBreak_Flag(false),
	_ShieldDraw_Flag(true),
	_Shield_Cnt(0)
{
	_x = x;
	_y = y;
	_isflip = flip;
	Init();
	LoadPicture();
	LoadSE();
	VolumeInit();
};

Shielder::~Shielder() {

};

void Shielder::Init() {
	_sort = 6;
	_w = GRAPH_WIDTH;
	_h = GRAPH_HEIGHT;
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
	_State = ENEMYSTATE::APPEAR;
	_life = LIFE_MAX;
	_spd = SPEED;
	_alpha = 0;
}
void Shielder::Process(Game& g) {
	EnemyBase::Process(g);
	VolumeChange();
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
	case ENEMYSTATE::GUARDATTACK:
		GuardAttack(g);
		break;
	case ENEMYSTATE::GUARDBREAK:
		GuardBreak(g);
		break;
	case ENEMYSTATE::DEAD:
		Dead(g);
		break;
	}
	HitJudge(g);
}
void Shielder::Draw(Game& g) {	
#ifdef _DEBUG
	DebugDraw(g);
#endif 
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
	EnemyBase::Draw(g);
	ShieldDraw(g);
}
void Shielder::Delete(Game& g) {
	g.GetOS()->Del(this);
}

//被ダメ判定&押し出しの処理
void Shielder::HitJudge(Game& g) {
	//敵とプレイヤーアクションオブジェクトの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		OBJECTTYPE objType = (*ite)->GetObjType();
		switch (objType) {
		case ObjectBase::OBJECTTYPE::MIDDLEATTACK:
		case ObjectBase::OBJECTTYPE::LOWATTACK:
			// 敵とプレイヤーの中段攻撃&下段攻撃オブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
				if (_ShieldAlive_Flag == false) {
					_life--;
					_action_cnt = _cnt;
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
			}
			break;
		case ObjectBase::OBJECTTYPE::KICK:
			// 敵とプレイヤーのキックオブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				(*ite)->Delete(g);		// (*ite) はキックオブジェクト
				if (_ShieldAlive_Flag == true) {
					_Anime["Attack"] = 0;
					_ShieldBreak_Flag = true;
					_ShieldAlive_Flag = false;
					_Shield_Cnt = _cnt;
					_action_cnt = _cnt;
					_State = ENEMYSTATE::GUARDBREAK;
				}
			}
			break;
		case ObjectBase::OBJECTTYPE::IAI:
		case ObjectBase::OBJECTTYPE::FLAME:
		case ObjectBase::OBJECTTYPE::MUGENFLAME:
			// 敵とプレイヤーの居合オブジェクトの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				_life--;
				_ShieldBreak_Flag = true;
				_Shield_Cnt = _cnt;
				_action_cnt = _cnt;
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
//盾の描画関数
void Shielder::ShieldDraw(Game& g) {
	if (_ShieldDraw_Flag == true) {
		Shield Sh;
		auto x = _x + SHIELD_DIFFPOINTX;
		auto y = _y + SHIELD_DIFFPOINTY;
		auto gr = Sh.GetHandle();
		auto a = _alpha;
		auto frame = _cnt - _Shield_Cnt;
		if (_ShieldAttack_Flag == true) {
			if (frame >= 0 && frame < 40) {
				if (_isflip == false) {
					Sh.SetAngle(-0.5);
					x -= 40;
				}
				if (_isflip == true) {
					Sh.SetAngle(0.5);
					x += 40;
				}
				y += 20;
			}
			else {
				Sh.SetAngle(0.0);
				x = _x + SHIELD_DIFFPOINTX;
				y = _y + SHIELD_DIFFPOINTY;
			}
		}
		if (_ShieldBreak_Flag == true) {
			if (_isflip == false) {
				auto angle = Sh.GetAngle();
				if (frame >= 0 && GUARDBREAK_ALLFRAME >= frame) {
					a -= frame * SHIELD_ALPHACHANGE;
					angle += frame * SHIELD_ANGLECHANGE;
					x += frame * SHIELD_XCHANGE;
					y += frame * SHIELD_YCHANGE;
				}
				Sh.SetAngle(angle);
				if (frame == GUARDBREAK_ALLFRAME) {
					_ShieldDraw_Flag = false;
				}
			}
			if (_isflip == true) {
				auto angle = -Sh.GetAngle();
				if (frame >= 0 && GUARDBREAK_ALLFRAME >= frame) {
					a -= frame * SHIELD_ALPHACHANGE;
					angle -= frame * SHIELD_ANGLECHANGE;
					x -= frame * SHIELD_XCHANGE;
					y += frame * SHIELD_YCHANGE;
				}
				Sh.SetAngle(angle);
				if (frame == GUARDBREAK_ALLFRAME) {
					_ShieldDraw_Flag = false;
				}
			}
		}
		gr = SetDrawBlendMode(DX_BLENDMODE_ALPHA, a);
		Sh.SetPosition(x, y);
		Sh.SetFlip(_isflip);
		Sh.Draw(g);
		gr = SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
}

//画像読み込み関数
void Shielder::LoadPicture() {
	_GrAll["Appear"].resize(APPEAR_ANIMEMAX);
	ResourceServer::LoadDivGraph(APPEAR_GRAPHNAME, APPEAR_ANIMEMAX, APPEAR_WIDTHCOUNT, APPEAR_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Appear"].data());
	_GrAll["Patrol"].resize(PATROL_ANIMEMAX);
	ResourceServer::LoadDivGraph(PATROL_GARAPHNAME, PATROL_ANIMEMAX, PATROL_WIDTHCOUNT, PATROL_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Patrol"].data());
	_GrAll["Coming"].resize(COMING_ANIMEMAX);
	ResourceServer::LoadDivGraph(COMING_GRAPHNAME, COMING_ANIMEMAX, COMING_WIDTHCOUNT, COMING_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Coming"].data());
	_GrAll["Attack"].resize(ATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(ATTACK_GRAPHNAME, ATTACK_ANIMEMAX, ATTACK_WIDTHCOUNT, ATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Attack"].data());
	_GrAll["GuardAttack"].resize(GUARDATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(GUARDATTACK_GRAPHNAME, GUARDATTACK_ANIMEMAX, GUARDATTACK_WIDTHCOUNT, GUARDATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["GuardAttack"].data());
	_GrAll["GuardBreak"].resize(GUARDBREAK_ANIMEMAX);
	ResourceServer::LoadDivGraph(GUARDBREAK_GRAPHNAME, GUARDBREAK_ANIMEMAX, GUARDBREAK_WIDTHCOUNT, GUARDBREAK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["GuardBreak"].data());
	_GrAll["Dead"].resize(DEAD_ANIMEMAX);
	ResourceServer::LoadDivGraph(DEAD_GRAPHNAME, DEAD_ANIMEMAX, DEAD_WIDTHCOUNT, DEAD_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Dead"].data());
}

//効果音読み込み関数
void Shielder::LoadSE() {
	_Se["Attack"] = ResourceServer::LoadSoundMem("se/Enemy/ShieldAttack.wav");
}

//効果音ボリューム初期値設定関数
void	Shielder::VolumeInit() {
	_Vpal["Attack"] = 255;
}

//ボリューム変更関数
void	Shielder::VolumeChange() {
	ChangeVolumeSoundMem(_Vpal["Attack"], _Se["Attack"]);
}

//デバッグ用関数
void Shielder::DebugDraw(Game& g) {
	switch (_State) {
	case ENEMYSTATE::PATROL:
		if (_isflip == false) {
			PrivateCollision pc(_x + _hit_x -PATROL_WIDTH, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);
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
