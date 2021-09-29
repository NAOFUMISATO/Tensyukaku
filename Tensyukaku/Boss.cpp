#include <DxLib.h>
#include "ResourceServer.h"
#include "ModeEpilogue.h"
#include "OverlayBlack.h"
#include "Boss.h"
#include "BossBlood.h"
#include "Game.h"
using namespace BossInifo;
Boss::Boss(int x,int y,bool flip) {
	_x = x;
	_y = y;
	_isflip = flip;
	Init();
	LoadActionGraph();
}
Boss::~Boss() {
}

void Boss::Init() {
	_sort = 12;
	_w = GRAPH_WIDTH;
	_h = GRAPH_HEIGHT;
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
	_alpha = 255;
	_State = BOSSSTATE::IDLE;
}

void Boss::Process(Game& g) {
	ObjectBase::Process(g);
	EventChange(g);
	/*---状態毎の処理---*/
	switch (_State) {
	case BOSSSTATE::IDLE:
		Idle(g);
		break;
	case BOSSSTATE::EVENTA:
		BossEventA(g);
		break;
	case BOSSSTATE::EVENTB:
		BossEventB(g);
		break;
	case BOSSSTATE::DAMAGE:
		Damage(g);
		break;
	case BOSSSTATE::DEAD:
		Dead(g);
		break;
	}

}
void Boss::Draw(Game& g) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
	ObjectBase::Draw(g);
}

/*---------状態毎の処理----------*/
void Boss::Idle(Game& g) {
	_grhandle = _grall["Idle"][_anime["Idle"]];
	_anime["Idle"] = 0;
}
void Boss::BossEventA(Game& g) {
	auto frame = _cnt - _action_cnt;
	if (frame >= 0 && 120 >= frame) {
		_grhandle = _grall["Idle"][_anime["Idle"]];
		_anime["Idle"] = 0;
	}
	if (frame == 60) {
		_isflip = false;
	}
	if (frame == 120) {
		_isflip = true;
	}
	if (frame > 120&&360>frame){
		_grhandle = _grall["Move"][_anime["Move"]];
		_anime["Move"] = (_cnt / ANIMESPEED_WALK) % MOVE_ANIMEMAX;
		_x -= 4;
	}
	if (frame ==360) {
		g.GetOS()->Del(this);
	}
}
void Boss::BossEventB(Game& g) {
	auto frame = _cnt - _action_cnt;
	_spd = 3;
	_grhandle = _grall["Idle"][_anime["Idle"]];
	_anime["Idle"] = 0;
	if (frame == 30) {
		_isflip = true;
	}
	if (frame >= 90 && 250 > frame) {
		_grhandle = _grall["Back"][_anime["Back"]];
		_anime["Back"] = (_cnt / ANIMESPEED_BACK) % BACK_ANIMEMAX;
		_x += _spd;
	}
	if (frame >= 250) {
		_grhandle = _grall["Idle"][_anime["Idle"]];
		_anime["Idle"] = 0;
	}
	if (frame == 270) {
		_isflip = false;
	}
	if (frame == 290) {
		_isflip = true;
	}
	if (frame > 290) {
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// iteはプレイヤーの特殊攻撃オブジェクトか？
			if ((*ite)->GetObjType() == OBJECTTYPE::SPECIAL)
			{
				// 敵とプレイヤーの特殊攻撃オブジェクトの当たり判定を行う
				if (IsHit(*(*ite)) == true) {
					(*ite)->Delete(g);
					_action_cnt = _cnt;
					_State = BOSSSTATE::DAMAGE;
				}
			}
		}
	}
}
void Boss::Damage(Game& g) {
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["Damage"][_anime["Damage"]];
	_anime["Damage"] = 0;
	if (frame == 1) {
		auto bloodtype = 0;
		auto bb = new BossBlood(_x + _gx, _y + _gy, bloodtype);
		g.GetOS()->Add(bb);
	}
	if (frame == DAMAGE_ALLFRAME) {
		_action_cnt = _cnt;
		_State = BOSSSTATE::DEAD;
		auto bloodtype = 1;
		auto bb = new BossBlood(_x + _gx, _y + _gy, bloodtype);
		g.GetOS()->Add(bb);
	}
}

void Boss::Dead(Game& g) {
	auto frame = _cnt - _action_cnt;
	_grhandle = _grall["Dead"][_anime["Dead"]];
	if (frame < DEAD_ANIMEFRAME) {
		_anime["Dead"] = ((frame) / ANIMESPEED_DEAD) % DEAD_ANIMEMAX;
	}
	auto modechangeframe = 120;
	if (frame == DEAD_ALLFRAME) {
		StopSoundMem(g.GetBgm()["Main"]);//
		auto ol = new OverlayBlack();
		ol->SetFade(modechangeframe, 240, 300, 4);
		g.GetMS()->Add(ol, 2, "OverlayBlack");
	}
	
	if (frame == DEAD_ALLFRAME + modechangeframe) {
		g.GetMS()->Del(g.GetMS()->Get("Game"));
		auto me = new ModeEpilogue();
		g.GetMS()->Add(me, 0, "Epilogue");
	}
}
//ボスのイベント状態遷移関数
void Boss::EventChange(Game& g) {
	if (_bosseventA_flag == true) {
		_State = BOSSSTATE::EVENTA;
		_action_cnt = _cnt;
		_bosseventA_flag = false;
	}
	if (_bosseventB_flag == true) {
		_State = BOSSSTATE::EVENTB;
		_action_cnt = _cnt;
		_bosseventB_flag = false;
	}
}
//ボスの画像読み込み関数
void Boss::LoadActionGraph() {
	_grall["Idle"].resize(IDLE_ANIMEMAX);
	ResourceServer::LoadDivGraph(IDLE_GRAPHNAME, IDLE_ANIMEMAX, IDLE_WIDTHCOUNT, IDLE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Idle"].data());
	_grall["Move"].resize(MOVE_ANIMEMAX);
	ResourceServer::LoadDivGraph(MOVE_GRAPHNAME, MOVE_ANIMEMAX, MOVE_WIDTHCOUNT, MOVE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Move"].data());
	_grall["Back"].resize(BACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(BACK_GRAPHNAME, BACK_ANIMEMAX, BACK_WIDTHCOUNT, BACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Back"].data());
	_grall["Damage"].resize(DAMAGE_ANIMEMAX);
	ResourceServer::LoadDivGraph(DAMAGE_GRAPHNAME, DAMAGE_ANIMEMAX, DAMAGE_WIDTHCOUNT, DAMAGE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Damage"].data());
	_grall["Dead"].resize(DEAD_ANIMEMAX);
	ResourceServer::LoadDivGraph(DEAD_GRAPHNAME, DEAD_ANIMEMAX, DEAD_WIDTHCOUNT, DEAD_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Dead"].data());
}
//ボスの効果音読み込み関数
void Boss::LoadActionSE() {

}