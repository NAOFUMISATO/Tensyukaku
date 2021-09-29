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
	
}
void SpawnBlockBase::Draw(Game& g) {
	ObjectBase::Draw(g);
}
void SpawnBlockBase::Delete(Game& g) {
	g.GetOS()->Del(this);
}