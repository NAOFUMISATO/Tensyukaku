#include "EventHappen.h"
#include "RecoveryBlock.h"
#include "BossEvent.h"
#include "CPointBlock.h"
#include "FlameBlock.h"
#include "TutorialBlock.h"
#include "Game.h"

using namespace EHInfo;
EventHappen::EventHappen(Game& g) {
	Init(g);
}
EventHappen::~EventHappen() {
}

void EventHappen::Init(Game& g) {
	//チュートリアルブロック生成
	TutorialAppear(g);
	//回復ブロック生成
	auto eb = new RecoveryBlock(RECOVERY_X, RECOVERY_Y);
	g.GetOS()->Add(eb);
	//チェックポイントブロック生成
	auto cb = new CPointBlock(CPOINT_X, CPOINT_Y);
	g.GetOS()->Add(cb);
	//ボスイベントブロック作成
	if (g.GetCPointFlag() == false) {
		auto bsa = new BossEventA(BOSSA_X, BOSSA_Y);
		g.GetOS()->Add(bsa);
	}
	auto bsb = new BossEventB(BOSSB_X, BOSSB_Y);
	g.GetOS()->Add(bsb);
	//炎演出ブロックの作成
	auto fb = new FlameBlock(FLAME_X, FLAME_Y);
	g.GetOS()->Add(fb);
}
//チュートリアルブロック生成
void EventHappen::TutorialAppear(Game& g) {
	auto tb1 = new TutorialBlock(TUTORIAL1_X, TUTORIAL1_Y, TUTORIAL1_NUM);
	g.GetOS()->Add(tb1);
	auto tb2 = new TutorialBlock(TUTORIAL2_X, TUTORIAL2_Y, TUTORIAL2_NUM);
	g.GetOS()->Add(tb2);
	auto tb3 = new TutorialBlock(TUTORIAL3_X, TUTORIAL3_Y, TUTORIAL3_NUM);
	g.GetOS()->Add(tb3);
	auto tb4 = new TutorialBlock(TUTORIAL4_X, TUTORIAL4_Y, TUTORIAL4_NUM);
	g.GetOS()->Add(tb4);
	auto tb5 = new TutorialBlock(TUTORIAL5_X, TUTORIAL5_Y, TUTORIAL5_NUM);
	g.GetOS()->Add(tb5);
}