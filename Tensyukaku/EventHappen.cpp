#include "EventHappen.h"
#include "RecoveryBlock.h"
#include "BossEvent.h"
#include "CPointBlock.h"
#include "FlameBlock.h"
#include "TutorialBoard.h"
#include "Game.h"

using namespace EHInfo;
using namespace CPInfo;
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
	auto cp2 = new CPointBlock("2A");
	g.GetOS()->Add(cp2);
	auto cp3 = new CPointBlock("3A");
	g.GetOS()->Add(cp3);
	auto cp4 = new CPointBlock("4A");
	g.GetOS()->Add(cp4);
	auto cp5 = new CPointBlock("5A");
	g.GetOS()->Add(cp5);
	auto cp6 = new CPointBlock("5B");
	g.GetOS()->Add(cp6);
	auto cp11 = new CPointBlock("11A");
	g.GetOS()->Add(cp11);
	//ボスイベントブロック作成
	/*if (g.GetCPointFlag() == false) {*/
		auto bsa = new BossEventA(BOSSA_X, BOSSA_Y);
		g.GetOS()->Add(bsa);
	/*}*/
	auto bsb = new BossEventB(BOSSB_X, BOSSB_Y);
	g.GetOS()->Add(bsb);
	//炎演出ブロックの作成
	auto fb = new FlameBlock(FLAME_X, FLAME_Y);
	g.GetOS()->Add(fb);
}
//チュートリアルブロック生成
void EventHappen::TutorialAppear(Game& g) {
	auto tb1a = new TutorialBoard("1A");
		g.GetOS()->Add(tb1a);
		auto tb1b = new TutorialBoard("1B");
		g.GetOS()->Add(tb1b);
		auto tb2a = new TutorialBoard("2A");
		g.GetOS()->Add(tb2a);
		auto tb3a = new TutorialBoard("3A");
		g.GetOS()->Add(tb3a);
		auto tb3b = new TutorialBoard("3B");
		g.GetOS()->Add(tb3b);
		auto tb4a = new TutorialBoard("4A");
		g.GetOS()->Add(tb4a);
		auto tb5a = new TutorialBoard("5A");
		g.GetOS()->Add(tb5a);
}