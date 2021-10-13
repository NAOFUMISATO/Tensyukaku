#include "SpawnBlockBase.h"
#include "Game.h"
namespace {
   constexpr auto GRAPHPOINT_X = 0;      //X位置から描画点までの差分
   constexpr auto GRAPHPOINT_Y = -50;      //Y位置から描画点までの差分
   constexpr auto POSITION_HITX = -50;      //描画点から当たり判定左上座標までの差分
   constexpr auto POSITION_HITY = -50;      //描画点から当たり判定左上座標までの差分
   constexpr auto COLLISION_WIDTH = 100;   //階段の当たり判定横幅
   constexpr auto COLLISION_HEIGHT = 100;   //階段の当たり判定縦幅
}
SpawnBlockBase::SpawnBlockBase() {
   Init();
}
SpawnBlockBase::~SpawnBlockBase() {
}

void SpawnBlockBase::Init() {
   
}
void SpawnBlockBase::Draw(Game& g) {
   ObjectBase::Draw(g);
}
void SpawnBlockBase::Delete(Game& g) {
   g.GetOS()->Del(this);
}