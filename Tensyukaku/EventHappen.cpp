#include "EventHappen.h"
#include "RecoveryBlock.h"
#include "GimikPlacement.h"
#include "BossEventBlock.h"
#include "CPointBlock.h"
#include "FloorTextBlock.h"
#include "FlameBlock.h"
#include "TutorialBoard.h"
#include "Game.h"

using namespace CPInfo;
using namespace GInfo;
namespace {
   constexpr auto BOSSA_NUM = 1;   //!< ボスイベントブロックA種別番号
   constexpr auto BOSSB_NUM = 2;   //!< ボスイベントブロックB種別番号
   constexpr auto FLAME_X = 500;   //!< 炎演出ブロックX座標
   constexpr auto FLAME_Y = 1760;  //!< 炎演出ブロックY座標
}
EventHappen::EventHappen(Game& g) {
   Init(g);
}
EventHappen::~EventHappen() {
}

void EventHappen::Init(Game& g) {
   TutorialAppear(g);
   CPointAppear(g);
   BossEventAppear(g);
   IngameTextAppear(g);
   FlameAppear(g); 
   RecoveryAppear(g);
}
//チュートリアルブロック生成関数
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
//チェックポイントブロック生成関数
void EventHappen::CPointAppear(Game& g) {
   auto cp2 = new CPointBlock("2A");
   g.GetOS()->Add(cp2);
   auto cp3 = new CPointBlock("3A");
   g.GetOS()->Add(cp3);
   auto cp4 = new CPointBlock("4A");
   g.GetOS()->Add(cp4);
   auto cp5a = new CPointBlock("5A");
   g.GetOS()->Add(cp5a);
   auto cp5b = new CPointBlock("5B");
   g.GetOS()->Add(cp5b);
   auto cp8a = new CPointBlock("8A");
   g.GetOS()->Add(cp8a);
   auto cp11 = new CPointBlock("11A");
   g.GetOS()->Add(cp11);
}
//ボスイベントブロック生成関数
void EventHappen::BossEventAppear(Game& g) {
   if (g.GetCPointFlag()["11A"] == false) {
      auto bsa = new BossEventBlock(BOSSA_NUM);
      g.GetOS()->Add(bsa);
   }
   auto bsb = new BossEventBlock(BOSSB_NUM);
   g.GetOS()->Add(bsb);
}
//インゲームテキスト生成関数
void EventHappen::IngameTextAppear(Game& g) {
   auto fttop = new FloorTextBlock("TOP");
   g.GetOS()->Add(fttop);
   auto ftupper = new FloorTextBlock("UPPER");
   g.GetOS()->Add(ftupper);
   auto ftmiddle = new FloorTextBlock("MIDDLE");
   g.GetOS()->Add(ftmiddle);
   auto ftunder = new FloorTextBlock("UNDER");
   g.GetOS()->Add(ftunder);
}
//回復ブロック生成関数
void EventHappen::RecoveryAppear(Game& g) {
   auto rb6a = new RecoveryBlock(REST_POINT6A_X, REST_POINT6A_Y);
   g.GetOS()->Add(rb6a);
   auto rb7a = new RecoveryBlock(REST_POINT7A_X, REST_POINT7A_Y);
   g.GetOS()->Add(rb7a);
}
//炎演出ブロック生成関数
void EventHappen::FlameAppear(Game& g) {
   auto fb = new FlameBlock(FLAME_X, FLAME_Y);
   g.GetOS()->Add(fb);
}