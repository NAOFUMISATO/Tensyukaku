#include "EventHappen.h"
#include "RecoveryBlock.h"
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
}