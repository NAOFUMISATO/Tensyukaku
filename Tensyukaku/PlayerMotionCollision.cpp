#include <DxLib.h>
#include "PlayerMotionCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ResourceServer.h"
#include "Player.h"



using namespace PInfo;


//’†’iUŒ‚“–‚½‚è”»’èŽÀ‘Ì
MiddleAttackCollision::MiddleAttackCollision(int x,int y) {
   _x = x;
   _y = y;
   Init();
}
MiddleAttackCollision::~MiddleAttackCollision() {
}

void MiddleAttackCollision::Init() {
   _w = MIDDLEATTACK_WIDTH;
   _h = MIDDLEATTACK_HEIGHT;
   _gx = 0;
   _gy = 0;
   _hit_x = 0;
   _hit_y = 0;
   _hit_w = MIDDLEATTACK_WIDTH;
   _hit_h = MIDDLEATTACK_HEIGHT;
   _action_cnt = _cnt;
#ifdef _DEBUG
   _debug_color = std::make_tuple(255, 0, 0);
   _debug_alpha = 128;
   _debug_fill = true;
#endif
}

void MiddleAttackCollision::Process(Game& g) {
   ObjectBase::Process(g);
   if (_cnt - _action_cnt == MIDDLEATTACK_ENDFRAME) {
      g.GetOS()->Del(this);
   }
}
void MiddleAttackCollision::Draw(Game& g) {
   ObjectBase::Draw(g);
}
void MiddleAttackCollision::Delete(Game& g) {
   g.GetOS()->Del(this);
}

//‰º’iUŒ‚“–‚½‚è”»’èŽÀ‘Ì
LowAttackCollision::LowAttackCollision(int x, int y) {
   _x = x;
   _y = y;
   Init();
}
LowAttackCollision::~LowAttackCollision() {
}

void LowAttackCollision::Init() {
   _w = LOWATTACK_WIDTH;
   _h = LOWATTACK_HEIGHT;
   _gx = 0;
   _gy = 0;
   _hit_x = 0;
   _hit_y = 0;
   _hit_w = LOWATTACK_WIDTH;
   _hit_h = LOWATTACK_HEIGHT;
   _action_cnt = _cnt;
#ifdef _DEBUG
   _debug_color = std::make_tuple(255, 0, 0);
   _debug_alpha = 128;
   _debug_fill = true;
#endif
}

void LowAttackCollision::Process(Game& g) {
   ObjectBase::Process(g);
   if (_cnt - _action_cnt == LOWATTACK_ENDFRAME) {
      g.GetOS()->Del(this);
   }
}
void LowAttackCollision::Draw(Game& g) {
   ObjectBase::Draw(g);
}
void LowAttackCollision::Delete(Game& g) {
   g.GetOS()->Del(this);
}

//R‚è“–‚½‚è”»’èŽÀ‘Ì
KickCollision::KickCollision(int x, int y) {
   _x = x;
   _y = y;
   Init();
}
KickCollision::~KickCollision() {
}

void KickCollision::Init() {
   _w = KICK_WIDTH;
   _h = KICK_HEIGHT;
   _gx = 0;
   _gy = 0;
   _hit_x = 0;
   _hit_y = 0;
   _hit_w = KICK_WIDTH;
   _hit_h = KICK_HEIGHT;
   _action_cnt = _cnt;
#ifdef _DEBUG
   _debug_color = std::make_tuple(255, 0, 0);
   _debug_alpha = 128;
   _debug_fill = true;
#endif
}

void KickCollision::Process(Game& g) {
   ObjectBase::Process(g);
   if (_cnt - _action_cnt == KICK_ENDFRAME) {
      g.GetOS()->Del(this);
   }
}
void KickCollision::Draw(Game& g) {
   ObjectBase::Draw(g);
}
void KickCollision::Delete(Game& g) {
   g.GetOS()->Del(this);
}

//‹‡“–‚½‚è”»’èŽÀ‘Ì
IaiCollision::IaiCollision(int x, int y) {
   _x = x;
   _y = y;
   Init();
}
IaiCollision::~IaiCollision() {
}

void IaiCollision::Init() {
   _w = IAI_WIDTH;
   _h = IAI_HEIGHT;
   _gx = 0;
   _gy = 0;
   _hit_x = 0;
   _hit_y = 0;
   _hit_w = IAI_WIDTH;
   _hit_h = IAI_HEIGHT;
   _action_cnt = _cnt;
#ifdef _DEBUG
   _debug_color = std::make_tuple(255,0, 0);
   _debug_alpha = 128;
   _debug_fill = true;
#endif
}

void IaiCollision::Process(Game& g) {
   ObjectBase::Process(g);
   if (_cnt - _action_cnt == IAI_ENDFRAME) {
      g.GetOS()->Del(this);
   }
}
void IaiCollision::Draw(Game& g) {
   ObjectBase::Draw(g);
}
void IaiCollision::Delete(Game& g) {
   g.GetOS()->Del(this);
}


//“ÁŽêUŒ‚“–‚½‚è”»’èŽÀ‘Ì
SpecialCollision::SpecialCollision(int x, int y) {
   _x = x;
   _y = y;
   Init();
}
SpecialCollision::~SpecialCollision() {
}

void SpecialCollision::Init() {
   _w = SPECIALATTACK_WIDTH;
   _h = SPECIALATTACK_HEIGHT;
   _gx = 0;
   _gy = 0;
   _hit_x = 0;
   _hit_y = 0;
   _hit_w = SPECIALATTACK_WIDTH;
   _hit_h = SPECIALATTACK_HEIGHT;
   _action_cnt = _cnt;
#ifdef _DEBUG
   _debug_color = std::make_tuple(255, 0, 0);
   _debug_alpha = 128;
   _debug_fill = true;
#endif
}

void SpecialCollision::Process(Game& g) {
   ObjectBase::Process(g);
   if (_cnt - _action_cnt == SPECIALATTACK_ENDFRAME) {
      g.GetOS()->Del(this);
   }
}
void SpecialCollision::Draw(Game& g) {
   ObjectBase::Draw(g);
}
void SpecialCollision::Delete(Game& g) {
   g.GetOS()->Del(this);
}
