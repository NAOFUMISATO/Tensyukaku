#include <DxLib.h>
#include "LancerMotionCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Lancer.h"


using namespace LInfo;
/*
‘„•º‚ÌŠeƒ‚[ƒVƒ‡ƒ“Žž‚Ì“–‚½‚è”»’èŽÀ‘Ì
*/

//UŒ‚“–‚½‚è”»’èŽÀ‘Ì
LancerAttackCollision::LancerAttackCollision(int x, int y) {
   _x = x;
   _y = y;
   Init();
}
LancerAttackCollision::~LancerAttackCollision() {
}

void LancerAttackCollision::Init() {
   _gx = 0;
   _gy = 0;
   _hit_x = 0;
   _hit_y = 0;
   _hit_w = ATTACK_WIDTH;
   _hit_h = ATTACK_HEIGHT;
   _action_cnt = _cnt;
#ifdef _DEBUG
   _debug_color = std::make_tuple(255, 0, 0);
   _debug_alpha = 128;
   _debug_fill = true;
#endif
}

void LancerAttackCollision::Process(Game& g) {
   ObjectBase::Process(g);
   if (_cnt - _action_cnt == ATTACK_ENDFRAME) {
      g.GetOS()->Del(this);
   }
}
void LancerAttackCollision::Draw(Game& g) {
   ObjectBase::Draw(g);
}
void LancerAttackCollision::Delete(Game& g) {
   g.GetOS()->Del(this);
}


