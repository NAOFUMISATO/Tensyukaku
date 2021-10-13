#include <DxLib.h>
#include "ResourceServer.h"
#include "Shielder.h"
#include "Shield.h"
#include "Game.h"
#include "ObjectBase.h"
#include <utility>

using namespace SInfo;
Shield::Shield() {
   
   Init();
   _grhandle = ResourceServer::LoadGraph("res/Shielder/Shield.png");
}
Shield::~Shield() {
}

void Shield::Init() {
   _gx = SHIELD_GRAPH_POINTX;
   _gy = SHIELD_GRAPH_POINTY;
   _drg.second = SHIELD_ANGLE;
   _debug_alpha = 0;

}

void Shield::Process(Game& g) {
   ObjectBase::Process(g);
}

void Shield::Draw(Game& g) {
   auto GC = g.GetChip();
   auto x = _x + _gx - GC->GetscrX();
   auto y = _y + _gy - GC->GetscrY();
   auto scale = _drg.first;
   auto angle = _drg.second;
   _before_x = _x + _gx;
   _before_y = _y + _gy;
   _dx = x;
   _dy = y;
   DrawRotaGraph(x, y, scale, angle, _grhandle, true, _isflip);
#ifdef _DEBUG
   int& re = std::get<0>(_debug_color);
   int& gr = std::get<1>(_debug_color);
   int& bl = std::get<2>(_debug_color);
   SetDrawBlendMode(DX_BLENDMODE_ALPHA, _debug_alpha);      // ”¼“§–¾•`‰æw’è
   DrawBox(x + _hit_x, y + _hit_y, x + _hit_x + _hit_w, y + _hit_y + _hit_h, GetColor(re, gr, bl), _debug_fill);   // ”¼“§–¾‚ÌÔ‚Å“–‚½‚è”»’è•`‰æ
#endif
   SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);      // •s“§–¾•`‰æw’è

}

