#include "EventHappen.h"
#include "RecoveryBlock.h"
#include "Game.h"

using namespace EHInfo;
EventHappen::EventHappen(Game& g) {

}
EventHappen::~EventHappen() {
}

void EventHappen::Process(Game& g) {
	//‰ñ•œƒuƒƒbƒN¶¬
	auto eb = new RecoveryBlock(RECOVERY_X, RECOVERY_Y);
	g.GetOS()->Add(eb);
}