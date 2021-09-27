#include "EventHappen.h"
#include "RecoveryBlock.h"
#include "BossEvent.h"
#include "CPointBlock.h"
#include "FlameBlock.h"
#include "TutorialBoard.h"
#include "Game.h"

using namespace EHInfo;
EventHappen::EventHappen(Game& g) {
	Init(g);
}
EventHappen::~EventHappen() {
}

void EventHappen::Init(Game& g) {
	//�`���[�g���A���u���b�N����
	TutorialAppear(g);
	//�񕜃u���b�N����
	auto eb = new RecoveryBlock(RECOVERY_X, RECOVERY_Y);
	g.GetOS()->Add(eb);
	//�`�F�b�N�|�C���g�u���b�N����
	auto cb = new CPointBlock(CPOINT_X, CPOINT_Y);
	g.GetOS()->Add(cb);
	//�{�X�C�x���g�u���b�N�쐬
	if (g.GetCPointFlag() == false) {
		auto bsa = new BossEventA(BOSSA_X, BOSSA_Y);
		g.GetOS()->Add(bsa);
	}
	auto bsb = new BossEventB(BOSSB_X, BOSSB_Y);
	g.GetOS()->Add(bsb);
	//�����o�u���b�N�̍쐬
	auto fb = new FlameBlock(FLAME_X, FLAME_Y);
	g.GetOS()->Add(fb);
}
//�`���[�g���A���u���b�N����
void EventHappen::TutorialAppear(Game& g) {
	if (g.GetTutorial1Flag() == false || g.GetRestartFlag() == false) {
		auto tb1 = new TutorialBoard(TUTORIAL1_X, TUTORIAL1_Y, TUTORIAL1_NUM);
		g.GetOS()->Add(tb1);
	}
	if (g.GetTutorial2Flag() == false || g.GetRestartFlag() == false) {
		auto tb2 = new TutorialBoard(TUTORIAL2_X, TUTORIAL2_Y, TUTORIAL2_NUM);
		g.GetOS()->Add(tb2);
	}
	if (g.GetTutorial3Flag() == false || g.GetRestartFlag() == false) {
		auto tb3 = new TutorialBoard(TUTORIAL3_X, TUTORIAL3_Y, TUTORIAL3_NUM);
		g.GetOS()->Add(tb3);
	}
	if (g.GetTutorial4Flag() == false || g.GetRestartFlag() == false) {
		auto tb4 = new TutorialBoard(TUTORIAL4_X, TUTORIAL4_Y, TUTORIAL4_NUM);
		g.GetOS()->Add(tb4);
	}
	if (g.GetTutorial5Flag() == false || g.GetRestartFlag() == false) {
		auto tb5 = new TutorialBoard(TUTORIAL5_X, TUTORIAL5_Y, TUTORIAL5_NUM);
		g.GetOS()->Add(tb5);
	}
}