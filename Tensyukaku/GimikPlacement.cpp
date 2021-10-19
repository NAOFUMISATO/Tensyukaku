/*****************************************************************//**
 * \file   GimikPlacement.cpp
 * \brief  ギミック関係のインスタンス生成クラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "GimikPlacement.h"
#include "Game.h"
#include "Stair.h"
#include "PoisonNinja.h"
#include "Andon.h"
#include "MugenAndon.h"
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
      RestObjAppear(g);
}

//階段のインスタンス生成関数
void GimikPlacement::StairAppear(Game& g) {
   auto st1 = new Stair(STAIR1A_X, STAIR1A_Y, STAIR1A_FLIP);
   g.GetOS()->Add(st1);
   auto st2 = new Stair(STAIR2A_X, STAIR2A_Y, STAIR2A_FLIP);
   g.GetOS()->Add(st2);
   auto st3 = new Stair(STAIR3A_X, STAIR3A_Y, STAIR3A_FLIP);
   g.GetOS()->Add(st3);
   auto st4 = new Stair(STAIR4A_X, STAIR4A_Y, STAIR4A_FLIP);
   g.GetOS()->Add(st4);
   auto st5 = new Stair(STAIR5A_X, STAIR5A_Y, STAIR5A_FLIP);
   g.GetOS()->Add(st5);
   auto st6a = new Stair(STAIR6A_X, STAIR6A_Y, STAIR6A_FLIP);
   g.GetOS()->Add(st6a);
   auto st6b = new Stair(STAIR6B_X, STAIR6B_Y, STAIR6B_FLIP);
   g.GetOS()->Add(st6b);
   auto st7a = new Stair(STAIR7A_X, STAIR7A_Y, STAIR7A_FLIP);
   g.GetOS()->Add(st7a);
   auto st7b = new Stair(STAIR7B_X, STAIR7B_Y, STAIR7B_FLIP);
   g.GetOS()->Add(st7b);
   auto st8 = new Stair(STAIR8A_X, STAIR8A_Y, STAIR8A_FLIP);
   g.GetOS()->Add(st8);
   auto st9 = new Stair(STAIR9A_X, STAIR9A_Y, STAIR9A_FLIP);
   g.GetOS()->Add(st9);
   auto bs = new BossStair(STAIR10A_X, STAIR10A_Y);
   g.GetOS()->Add(bs);
   auto st11 = new Stair(STAIR11A_X, STAIR11A_Y, STAIR11A_FLIP);
   g.GetOS()->Add(st11);
}

//行燈のインスタンス生成関数
void GimikPlacement::AndonAppear(Game& g) {
   auto an5a = new Andon(ANDON5A_X, ANDON5A_Y);
   g.GetOS()->Add(an5a);
   auto an5b = new Andon(ANDON5B_X, ANDON5B_Y);
   g.GetOS()->Add(an5b);
   auto an6a = new Andon(ANDON6A_X, ANDON6A_Y);
   g.GetOS()->Add(an6a);
   auto an8a = new Andon(ANDON8A_X, ANDON8A_Y);
   g.GetOS()->Add(an8a);
   auto an8b = new Andon(ANDON8B_X, ANDON8B_Y);
   g.GetOS()->Add(an8b);
   auto an8c = new Andon(ANDON8C_X, ANDON8C_Y);
   g.GetOS()->Add(an8c);
   auto an8d = new Andon(ANDON8D_X, ANDON8D_Y);
   g.GetOS()->Add(an8d);
   auto an8e = new Andon(ANDON8E_X, ANDON8E_Y);
   g.GetOS()->Add(an8e);
   auto ma11a = new MugenAndon(ANDON11A_X, ANDON11A_Y);
   g.GetOS()->Add(ma11a);
   auto ma11b = new  MugenAndon(ANDON11B_X, ANDON11B_Y);
   g.GetOS()->Add(ma11b);
   auto ma11c = new MugenAndon(ANDON11C_X, ANDON11C_Y);
   g.GetOS()->Add(ma11c);
   auto ma11d = new MugenAndon(ANDON11D_X, ANDON11D_Y);
   g.GetOS()->Add(ma11d);
   auto ma11e = new MugenAndon(ANDON11E_X, ANDON11E_Y);
   g.GetOS()->Add(ma11e);
}

//休息ポイント用掛け軸のインスタンス生成関数
void GimikPlacement::RestObjAppear(Game& g){
   auto rp6a = new RestPoint(REST_POINT6A_X, REST_POINT6A_Y);
   g.GetOS()->Add(rp6a);
   auto rp7a = new RestPoint(REST_POINT7A_X, REST_POINT7A_Y);
   g.GetOS()->Add(rp7a);
}