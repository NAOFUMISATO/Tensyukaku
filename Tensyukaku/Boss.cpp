#include <DxLib.h>
#include "ResourceServer.h"
#include "ModeEpilogue.h"
#include "OverlayBlack.h"
#include "Boss.h"
#include "Game.h"
using namespace BossInifo;
Boss::Boss(int x,int y,bool flip) {
	_x = x;
	_y = y;
	_isFlip = flip;
	Init();
	LoadActionGraph();
}
Boss::~Boss() {
}

void Boss::Init() {
	_Sort = 12;
	_w = GRAPH_WIDTH;
	_h = GRAPH_HEIGHT;
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
	_Alpha = 255;
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
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Alpha);
	ObjectBase::Draw(g);
}

/*---------状態毎の処理----------*/
void Boss::Idle(Game& g) {
	_GrHandle = _GrAll["Idle"][_Anime["Idle"]];
	_Anime["Idle"] = 0;
}
void Boss::BossEventA(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	if (frame >= 0 && 120 >= frame) {
		_GrHandle = _GrAll["Idle"][_Anime["Idle"]];
		_Anime["Idle"] = 0;
	}
	if (frame == 60) {
		_isFlip = false;
	}
	if (frame == 120) {
		_isFlip = true;
	}
	if (frame > 120&&360>frame){
		_GrHandle = _GrAll["Move"][_Anime["Move"]];
		_Anime["Move"] = (_Cnt / ANIMESPEED_WALK) % MOVE_ANIMEMAX;
		_x -= 4;
	}
	if (frame ==360) {
		g.GetOS()->Del(this);
	}
}
void Boss::BossEventB(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_Spd = 3;
	_GrHandle = _GrAll["Idle"][_Anime["Idle"]];
	_Anime["Idle"] = 0;
	if (frame == 30) {
		_isFlip = true;
	}
	if (frame >= 90 && 250 > frame) {
		_GrHandle = _GrAll["Back"][_Anime["Back"]];
		_Anime["Back"] = (_Cnt / ANIMESPEED_BACK) % BACK_ANIMEMAX;
		_x += _Spd;
	}
	if (frame >= 250) {
		_GrHandle = _GrAll["Idle"][_Anime["Idle"]];
		_Anime["Idle"] = 0;
	}
	if (frame == 270) {
		_isFlip = false;
	}
	if (frame == 290) {
		_isFlip = true;
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
					_Action_Cnt = _Cnt;
					_State = BOSSSTATE::DAMAGE;
				}
			}
		}
	}
}
void Boss::Damage(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Damage"][_Anime["Damage"]];
	_Anime["Damage"] = 0;
	if (frame == DAMAGE_ALLFRAME) {
		_Action_Cnt = _Cnt;
		_State = BOSSSTATE::DEAD;
}
}

void Boss::Dead(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_GrHandle = _GrAll["Dead"][_Anime["Dead"]];
	if (frame < DEAD_ANIMEFRAME) {
		_Anime["Dead"] = ((frame) / ANIMESPEED_DEAD) % DEAD_ANIMEMAX;
	}
	auto modechangeframe = 120;
	if (frame == DEAD_ALLFRAME) {
		auto ol = new OverlayBlack();
		ol->FadeSetting(modechangeframe, 240, 300, 4);
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
	if (_BEventA_Flag == true) {
		_State = BOSSSTATE::EVENTA;
		_Action_Cnt = _Cnt;
		_BEventA_Flag = false;
	}
	if (_BEventB_Flag == true) {
		_State = BOSSSTATE::EVENTB;
		_Action_Cnt = _Cnt;
		_BEventB_Flag = false;
	}
}
//ボスの画像読み込み関数
void Boss::LoadActionGraph() {
	_GrAll["Idle"].resize(IDLE_ANIMEMAX);
	ResourceServer::LoadDivGraph(IDLE_GRAPHNAME, IDLE_ANIMEMAX, IDLE_WIDTHCOUNT, IDLE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Idle"].data());
	_GrAll["Move"].resize(MOVE_ANIMEMAX);
	ResourceServer::LoadDivGraph(MOVE_GRAPHNAME, MOVE_ANIMEMAX, MOVE_WIDTHCOUNT, MOVE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Move"].data());
	_GrAll["Back"].resize(BACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(BACK_GRAPHNAME, BACK_ANIMEMAX, BACK_WIDTHCOUNT, BACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Back"].data());
	_GrAll["Damage"].resize(DAMAGE_ANIMEMAX);
	ResourceServer::LoadDivGraph(DAMAGE_GRAPHNAME, DAMAGE_ANIMEMAX, DAMAGE_WIDTHCOUNT, DAMAGE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Damage"].data());
	_GrAll["Dead"].resize(DEAD_ANIMEMAX);
	ResourceServer::LoadDivGraph(DEAD_GRAPHNAME, DEAD_ANIMEMAX, DEAD_WIDTHCOUNT, DEAD_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Dead"].data());
}
//ボスの効果音読み込み関数
void Boss::LoadActionSE() {

}