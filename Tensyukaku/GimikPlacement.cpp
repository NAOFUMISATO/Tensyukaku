#include <DxLib.h>
#include "GimikPlacement.h"
#include "Game.h"
#include "Stair.h"
#include "PoisonNinja.h"
#include "Andon.h"
#include "BossStair.h"
#include "RestPoint.h"

using namespace GInfo;
GimikPlacement::GimikPlacement(Game& g){
	Init(g);
}
GimikPlacement::~GimikPlacement() {
}

void GimikPlacement::Init(Game& g) {
		StairAppear(g);
		AndonAppear(g);
		auto rp = new RestPoint();
		g.GetOS()->Add(rp);
}

//階段のインスタンス生成関数
void GimikPlacement::StairAppear(Game& g) {
	auto st1 = new Stair(FLOOR1_STAIR_X, FLOOR1_STAIR_Y, FLOOR1_STAIR_FLIP);
	g.GetOS()->Add(st1);
	auto st2 = new Stair(FLOOR2_STAIR_X, FLOOR2_STAIR_Y, FLOOR2_STAIR_FLIP);
	g.GetOS()->Add(st2);
	auto st3 = new Stair(FLOOR3_STAIR_X, FLOOR3_STAIR_Y, FLOOR3_STAIR_FLIP);
	g.GetOS()->Add(st3);
	auto st4 = new Stair(FLOOR4_STAIR_X, FLOOR4_STAIR_Y, FLOOR4_STAIR_FLIP);
	g.GetOS()->Add(st4);
	auto st5 = new Stair(FLOOR5_STAIR_X, FLOOR5_STAIR_Y, FLOOR5_STAIR_FLIP);
	g.GetOS()->Add(st5);
	auto st6 = new Stair(FLOOR6_STAIR_X, FLOOR6_STAIR_Y, FLOOR6_STAIR_FLIP);
	g.GetOS()->Add(st6);
	auto st7a = new Stair(FLOOR7A_STAIR_X, FLOOR7A_STAIR_Y, FLOOR7A_STAIR_FLIP);
	g.GetOS()->Add(st7a);
	auto st7b = new Stair(FLOOR7B_STAIR_X, FLOOR7B_STAIR_Y, FLOOR7B_STAIR_FLIP);
	g.GetOS()->Add(st7b);
	auto st8a = new Stair(FLOOR8A_STAIR_X, FLOOR8A_STAIR_Y, FLOOR8A_STAIR_FLIP);
	g.GetOS()->Add(st8a);
	auto st8b = new Stair(FLOOR8B_STAIR_X, FLOOR8B_STAIR_Y, FLOOR8B_STAIR_FLIP);
	g.GetOS()->Add(st8b);
	auto st9 = new Stair(FLOOR9_STAIR_X, FLOOR9_STAIR_Y, FLOOR9_STAIR_FLIP);
	g.GetOS()->Add(st9);
	auto bs = new BossStair(FLOOR10_STAIR_X, FLOOR10_STAIR_Y);
	g.GetOS()->Add(bs);
	auto st11 = new Stair(FLOOR11_STAIR_X, FLOOR11_STAIR_Y, FLOOR11_STAIR_FLIP);
	g.GetOS()->Add(st11);
}


//行燈のインスタンス生成関数
void GimikPlacement::AndonAppear(Game& g) {
	auto an6 = new Andon(FLOOR6_ANDON_X, FLOOR6_ANDON_Y);
	g.GetOS()->Add(an6);
	auto an7 = new Andon(FLOOR7_ANDON_X, FLOOR7_ANDON_Y);
	g.GetOS()->Add(an7);
	auto an10 = new Andon(FLOOR10_ANDON_X, FLOOR10_ANDON_Y);
	g.GetOS()->Add(an10);
	auto an11a = new Andon(FLOOR11A_ANDON_X, FLOOR11A_ANDON_Y);
	g.GetOS()->Add(an11a);
	auto an11b = new Andon(FLOOR11B_ANDON_X, FLOOR11B_ANDON_Y);
	g.GetOS()->Add(an11b);
	auto an11c = new Andon(FLOOR11C_ANDON_X, FLOOR11C_ANDON_Y);
	g.GetOS()->Add(an11c);
	auto an11d = new Andon(FLOOR11D_ANDON_X, FLOOR11D_ANDON_Y);
	g.GetOS()->Add(an11d);
	auto an12 = new Andon(FLOOR12A_ANDON_X, FLOOR12A_ANDON_Y);
	g.GetOS()->Add(an12);
	
}