#include <DxLib.h>
#include "GimikPlacement.h"
#include "Game.h"
#include "Stair.h"

using namespace GInfo;
GimikPlacement::GimikPlacement(Game& g):_Appear_Flag(false) {
	
}
GimikPlacement::~GimikPlacement() {
}

void GimikPlacement::Process(Game& g) {
	if (_Appear_Flag == false) {
		_Appear_Flag = true;
		StairAppear(g);
	}
}
//階段のインスタンス生成関数
void GimikPlacement::StairAppear(Game& g) {
	//1F
	Stair* st1 = new Stair();
	st1->SetPosition(FLOOR1STAIR_X, FLOOR1STAIR_Y);
	st1->SetFlip(FLOOR1STAIR_FLIP);
	g.GetOS()->Add(st1);
	//2F
	Stair* st2 = new Stair();
	st2->SetPosition(FLOOR2STAIR_X, FLOOR2STAIR_Y);
	st2->SetFlip(FLOOR2STAIR_FLIP);
	g.GetOS()->Add(st2);
	//3F
	Stair* st3 = new Stair();
	st3->SetPosition(FLOOR3STAIR_X, FLOOR3STAIR_Y);
	st3->SetFlip(FLOOR3STAIR_FLIP);
	g.GetOS()->Add(st3);
}
