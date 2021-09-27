#include <DxLib.h>
#include "PoisonNinja.h"
#include "Poison.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
#include "Game.h"
#include "PrivateCollision.h"

using namespace PNInfo;
PoisonNinja::PoisonNinja(int x, int y, bool flip):
_Keep_Flag(true)
{
	_x = x;
	_y = y;
	_isflip = flip;
	Init();
	_grall["Appear"].resize(APPEAR_ANIMEMAX);
	ResourceServer::LoadDivGraph(APPEAR_GRAPHNAME, APPEAR_ANIMEMAX, APPEAR_WIDTHCOUNT, APPEAR_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Appear"].data());
	_grall["Patrol"].resize(PATROL_ANIMEMAX);
	ResourceServer::LoadDivGraph(PATROL_GRAPHNAME, PATROL_ANIMEMAX, PATROL_WIDTHCOUNT, PATROL_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Patrol"].data());
	_grall["Poising"].resize(POISING_ANIMEMAX);
	ResourceServer::LoadDivGraph(POISING_GRAPHNAME, POISING_ANIMEMAX, POISING_WIDTHCOUNT, POISING_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Poising"].data());
}

PoisonNinja::~PoisonNinja() {
}

void PoisonNinja::Init() {
	_sort = 10;
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_alpha = 0;
	_State = ENEMYSTATE::APPEAR;
}

void PoisonNinja::Process(Game& g) {
	ObjectBase::Process(g);
	//状態毎の処理
	switch (_State) {
	case ENEMYSTATE::APPEAR:
		Appear(g);
		break;
	case ENEMYSTATE::PATROL:
		Patrol(g);
		break;
	case ENEMYSTATE::POISING:
		Poising(g);
		break;
	}
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
		{
			//プレイヤーとY座標が同じなら消去
			auto py=(*ite)->GetY();
			if (py <= _y) {
				_alpha -= FADEOUT_SPEED;
				if (_alpha <0) {
					Delete(g);
				}
			}
		}
	}
}

void PoisonNinja::Draw(Game& g) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
	ObjectBase::Draw(g);
}
void PoisonNinja::Delete(Game& g) {
	g.GetOS()->Del(this);
}

//出現状態時の処理
void PoisonNinja::Appear(Game& g) {
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["Appear"][_anime["Appear"]];
	_anime["Appear"] = (_cnt / ANIMESPEED_APPEAR) % APPEAR_ANIMEMAX;
	if (frame < APPEAR_ALLFRAME) {
		_alpha += FADEIN_SPEED;
	}
	if (frame == APPEAR_ALLFRAME) {
		_alpha = 255;
		_action_cnt=_cnt;
		_State = ENEMYSTATE::PATROL;
	}
}

//巡回状態時の処理
void PoisonNinja::Patrol(Game& g) {
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["Patrol"][_anime["Patrol"]];
	_anime["Patrol"] = (_cnt / ANIMESPEED_PATROL) % PATROL_ANIMEMAX;
	if (frame == PATROL_TURNFRAME) {
		if (_isflip == false) {
			_isflip = true;
		}
		else { _isflip = false; }
	}
	if (frame == PATROL_TURNFRAME * 2) {
		if (_isflip == false) {
			_isflip = true;
		}
		else { _isflip = false; }
		_action_cnt = _cnt;
	}
	if (_isflip == false) {
		//索敵範囲判定オブジェクトの生成
		PrivateCollision pc(_x + _hit_x - PATROL_WIDTH, _y , PATROL_WIDTH, PATROL_HEIGHT);
		//索敵範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 索敵範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(pc) == true)
				{
					_State = ENEMYSTATE::POISING;
					_action_cnt = _cnt;
				}
			}
		}
	}
	if (_isflip == true) {
		//毒液忍者の索敵範囲判定オブジェクトの生成
		PrivateCollision pc(_x - _hit_x, _y, PATROL_WIDTH, PATROL_HEIGHT);
		//索敵範囲オブジェクトはプレイヤーに当たったか？
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーか？
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{
				// 索敵範囲オブジェクトとプレイヤーの当たり判定を行う
				if ((*ite)->IsHit(pc) == true)
				{
					_State = ENEMYSTATE::POISING;
					_action_cnt = _cnt;
				}
			}
		}
	}
}

//毒液垂らし状態の処理
void PoisonNinja::Poising(Game& g) {
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["Poising"][_anime["Poising"]];
	if (frame < POISING_ANIMEFRAME) {
		_anime["Poising"] = ((frame) / ANIMESPEED_POISING) % POISING_ANIMEMAX;
	}
	if (frame == POISING_ANIMEFRAME) {
		if (_isflip == false) {
			auto pr = new PoisonReserve(_x - POISON_SPAWN_X, _y + POISON_SPAWN_Y);
			g.GetOS()->Add(pr);
		}
		if (_isflip == true) {
			auto pr = new PoisonReserve(_x + POISON_SPAWN_X, _y + POISON_SPAWN_Y);
			g.GetOS()->Add(pr);
		}
	}
	if (_isflip == false) {
		PrivateCollision acc(_x + _hit_x - POISINGCANCEL_WIDTH, _y, POISINGCANCEL_WIDTH, POISINGCANCEL_HEIGHT);
		if (frame == POISING_ALLFRAME) {
			//毒液垂らし中止範囲オブジェクトはプレイヤーに当たったか？
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// iteはプレイヤーか？
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// 攻撃中止範囲オブジェクトとプレイヤーの当たり判定を行う
					if ((*ite)->IsHit(acc) == false)
					{
						_State = ENEMYSTATE::PATROL;
						_action_cnt = _cnt;
						_anime["Poising"] = 0;
					}
				}
			}
		}
	}
	if (_isflip == true) {
		PrivateCollision acc(_x - _hit_x, _y - _hit_h, POISINGCANCEL_WIDTH, POISINGCANCEL_HEIGHT);
		if (frame == POISING_ALLFRAME) {
			//毒液垂らし中止範囲オブジェクトはプレイヤーに当たったか？
			for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
			{
				// iteはプレイヤーか？
				if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
				{
					// 毒液垂らし中止範囲オブジェクトとプレイヤーの当たり判定を行う
					if ((*ite)->IsHit(acc) == false)
					{
						_State = ENEMYSTATE::PATROL;
						_action_cnt = _cnt;
						_anime["Poising"] = 0;
					}
				}
			}
		}
	}
	if (frame == POISING_ALLFRAME) {
		_action_cnt = _cnt;
	}
}