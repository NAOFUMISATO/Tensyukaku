#include <DxLib.h>
#include "GimikPlacement.h"
#include "Game.h"
#include "Stair.h"
#include "PoisonNinja.h"
#include "Andon.h"

using namespace GInfo;
GimikPlacement::GimikPlacement(Game& g){
	
}
GimikPlacement::~GimikPlacement() {
}

void GimikPlacement::Process(Game& g) {
		StairAppear(g);
		//AndonAppear(g);
}

//階段のインスタンス生成関数
void GimikPlacement::StairAppear(Game& g) {
	auto st1 = new Stair(FLOOR1STAIR_X, FLOOR1STAIR_Y, FLOOR1STAIR_FLIP);
	g.GetOS()->Add(st1);
	auto st2 = new Stair(FLOOR2STAIR_X, FLOOR2STAIR_Y, FLOOR2STAIR_FLIP);
	g.GetOS()->Add(st2);
	auto st3 = new Stair(FLOOR3STAIR_X, FLOOR3STAIR_Y, FLOOR3STAIR_FLIP);
	g.GetOS()->Add(st3);
	auto st4 = new Stair(FLOOR4STAIR_X, FLOOR4STAIR_Y, FLOOR4STAIR_FLIP);
	g.GetOS()->Add(st4);
}


////行燈のインスタンス生成関数
//void GimikPlacement::AndonAppear(Game& g) {
//	auto an = new Andon(5000, 7080);
//	g.GetOS()->Add(an);
//}