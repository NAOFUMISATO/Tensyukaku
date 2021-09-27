#include <DxLib.h>
#include "ResourceServer.h"
#include "Button.h"
#include "Game.h"
namespace {
	constexpr auto GRAPHPOINT_X = 0;				//XˆÊ’u‚©‚ç•`‰æ“_‚Ü‚Å‚Ì·•ª
	constexpr auto GRAPHPOINT_Y = -30;			//YˆÊ’u‚©‚ç•`‰æ“_‚Ü‚Å‚Ì·•ª
	constexpr auto POSITION_HITX = -30;			//•`‰æ“_‚©‚ç“–‚½‚è”»’è¶ãÀ•W‚Ü‚Å‚Ì·•ª
	constexpr auto POSITION_HITY = -30;			//•`‰æ“_‚©‚ç“–‚½‚è”»’è¶ãÀ•W‚Ü‚Å‚Ì·•ª
	constexpr auto COLLISION_WIDTH = 60;		//“–‚½‚è”»’è‰¡•
	constexpr auto COLLISION_HEIGHT = 60;		//“–‚½‚è”»’èc•
}
Button::Button(int x, int y, int buttonnum) {
	_x = x;
	_y = y;
	_ButtonNum = buttonnum;
	Init();
	_grall["BButton"].resize(1);
	ResourceServer::LoadDivGraph("res/UI/BButton.png", 1, 1, 1, 60, 60, _grall["BButton"].data());
	_grall["YButton"].resize(1);
	ResourceServer::LoadDivGraph("res/UI/YButton.png", 1, 1, 1, 60, 60, _grall["YButton"].data());
	_grall["GButton"].resize(1);
	ResourceServer::LoadDivGraph("res/UI/GButton.png", 1, 1, 1, 60, 60, _grall["GButton"].data());
	_grall["RButton"].resize(1);
	ResourceServer::LoadDivGraph("res/UI/RButton.png", 1, 1, 1, 60, 60, _grall["RButton"].data());
}

Button::~Button() {

}

void Button::Init() {
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
}

void Button::Process(Game& g) {
	ObjectBase::Process(g);
	auto frame = _cnt - _action_cnt;
	switch (_ButtonNum) {
	case	1:
		_grhandle = _grall["BButton"][_anime["BButton"]];
		break;
	case	2:
		_grhandle = _grall["YButton"][_anime["YButton"]];
		break;
	case 3:
		_grhandle = _grall["GButton"][_anime["GButton"]];
		break;
	case 4:
		_grhandle = _grall["RButton"][_anime["RButton"]];
		break;
	}
}

void Button::Draw(Game& g) {
	ObjectBase::Draw(g);
}

void Button::Delete(Game& g) {
	g.GetOS()->Del(this);
}