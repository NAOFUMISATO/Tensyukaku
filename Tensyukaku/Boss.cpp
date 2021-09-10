#include <DxLib.h>
#include "ResourceServer.h"
#include "Boss.h"
using namespace BossInifo;
Boss::Boss(int x,int y) {
	Init();
}
Boss::~Boss() {
}

void Boss::Init() {
	_w = GRAPH_WIDTH;
	_h = GRAPH_HEIGHT;
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
	_Alpha = 255;
}

void Boss::Process(Game& g) {
	ObjectBase::Process(g);
	if (_OState == OBJECTSTATE::EVENTA) {
		_State = BOSSSTATE::EVENTA;
	}
	else if (_OState == OBJECTSTATE::EVENTB) {
		_State = BOSSSTATE::EVENTB;
	}
	else if (_OState == OBJECTSTATE::EVENTC) {
		_State = BOSSSTATE::EVENTC;
	}
	else { _State = BOSSSTATE::IDLE; }
	/*---状態毎の処理---*/
	switch (_State) {
	case BOSSSTATE::EVENTA:
		EventA(g);
		break;
	case BOSSSTATE::EVENTB:
		EventB(g);
		break;
	case BOSSSTATE::EVENTC:
		EventC(g);
		break;
	}

}
void Boss::Draw(Game& g) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Alpha);
	ObjectBase::Draw(g);
}

//プレイヤーの画像読み込み関数
void Boss::LoadActionGraph() {
	_GrAll["Idle"].resize(IDLE_ANIMEMAX);
	ResourceServer::LoadDivGraph(IDLE_GRAPHNAME, IDLE_ANIMEMAX, IDLE_WIDTHCOUNT, IDLE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Idle"].data());
	_GrAll["Move"].resize(MOVE_ANIMEMAX);
	ResourceServer::LoadDivGraph(MOVE_GRAPHNAME, MOVE_ANIMEMAX, MOVE_WIDTHCOUNT, MOVE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Move"].data());
	_GrAll["Dead"].resize(DEAD_ANIMEMAX);
	ResourceServer::LoadDivGraph(DEAD_GRAPHNAME, DEAD_ANIMEMAX, DEAD_WIDTHCOUNT, DEAD_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Dead"].data());
	
}

//プレイヤーの効果音読み込み関数
void Boss::LoadActionSE() {
	
}

void Boss::Idle(Game& g) {

}

void Boss::EventA(Game& g) {

}

void Boss::EventB(Game& g) {

}

void Boss::EventC(Game& g) {

}