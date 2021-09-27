#include "SpawnBlockBase.h"
#include "Game.h"
namespace {
	constexpr auto GRAPHPOINT_X = 0;		//XˆÊ’u‚©‚ç•`‰æ“_‚Ü‚Å‚Ì·•ª
	constexpr auto GRAPHPOINT_Y = -50;		//YˆÊ’u‚©‚ç•`‰æ“_‚Ü‚Å‚Ì·•ª
	constexpr auto POSITION_HITX = -50;		//•`‰æ“_‚©‚ç“–‚½‚è”»’è¶ãÀ•W‚Ü‚Å‚Ì·•ª
	constexpr auto POSITION_HITY = -50;		//•`‰æ“_‚©‚ç“–‚½‚è”»’è¶ãÀ•W‚Ü‚Å‚Ì·•ª
	constexpr auto COLLISION_WIDTH = 100;	//ŠK’i‚Ì“–‚½‚è”»’è‰¡•
	constexpr auto COLLISION_HEIGHT = 100;	//ŠK’i‚Ì“–‚½‚è”»’èc•
}
SpawnBlockBase::SpawnBlockBase() {
	Init();
}
SpawnBlockBase::~SpawnBlockBase() {
}

void SpawnBlockBase::Init() {
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
#ifdef _DEBUG
	_debug_color = std::make_tuple(255, 0, 255);
	_debug_alpha = 128;
	_debug_fill = true;
#endif
}
void SpawnBlockBase::Draw(Game& g) {
	ObjectBase::Draw(g);
}
void SpawnBlockBase::Delete(Game& g) {
	g.GetOS()->Del(this);
}