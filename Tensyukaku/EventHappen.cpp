#include "EventHappen.h"
#include "RecoveryBlock.h"
#include "BossEvent.h"
#include "CPointBlock.h"
#include "FlameBlock.h"
#include "Game.h"

using namespace EHInfo;
EventHappen::EventHappen(Game& g) {
	Init(g);
}
EventHappen::~EventHappen() {
}

void EventHappen::Init(Game& g) {
	//回復ブロック生成
	auto eb = new RecoveryBlock(RECOVERY_X, RECOVERY_Y);
	g.GetOS()->Add(eb);
	//チェックポイントブロック生成
	auto cb = new CPointBlock(CPOINT_X, CPOINT_Y);
	g.GetOS()->Add(cb);
	//ボスイベントブロック作成
	auto bsa = new BossEventA(BOSSA_X, BOSSA_Y);
	g.GetOS()->Add(bsa);
	auto bsb = new BossEventB(BOSSB_X, BOSSB_Y);
	g.GetOS()->Add(bsb);
	//炎演出ブロックの作成
	auto fb = new FlameBlock(FLAME_X, FLAME_Y);
	g.GetOS()->Add(fb);
}