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
	//�񕜃u���b�N����
	auto eb = new RecoveryBlock(RECOVERY_X, RECOVERY_Y);
	g.GetOS()->Add(eb);
	//�`�F�b�N�|�C���g�u���b�N����
	auto cb = new CPointBlock(CPOINT_X, CPOINT_Y);
	g.GetOS()->Add(cb);
	//�{�X�C�x���g�u���b�N�쐬
	auto bsa = new BossEventA(BOSSA_X, BOSSA_Y);
	g.GetOS()->Add(bsa);
	auto bsb = new BossEventB(BOSSB_X, BOSSB_Y);
	g.GetOS()->Add(bsb);
	//�����o�u���b�N�̍쐬
	auto fb = new FlameBlock(FLAME_X, FLAME_Y);
	g.GetOS()->Add(fb);
}