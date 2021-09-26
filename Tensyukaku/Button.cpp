#include <DxLib.h>
#include "ResourceServer.h"
#include "Button.h"
#include "Game.h"
namespace {
	constexpr auto GRAPHPOINT_X = 0;				//X�ʒu����`��_�܂ł̍���
	constexpr auto GRAPHPOINT_Y = -30;			//Y�ʒu����`��_�܂ł̍���
	constexpr auto POSITION_HITX = -30;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto POSITION_HITY = -30;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto COLLISION_WIDTH = 60;		//�����蔻�艡��
	constexpr auto COLLISION_HEIGHT = 60;		//�����蔻��c��
}
Button::Button(int x, int y, int buttonnum) {
	_x = x;
	_y = y;
	_ButtonNum = buttonnum;
	Init();
	_GrAll["BButton"].resize(1);
	ResourceServer::LoadDivGraph("res/UI/BButton.png", 1, 1, 1, 60, 60, _GrAll["BButton"].data());
	_GrAll["YButton"].resize(1);
	ResourceServer::LoadDivGraph("res/UI/YButton.png", 1, 1, 1, 60, 60, _GrAll["YButton"].data());
	_GrAll["GButton"].resize(1);
	ResourceServer::LoadDivGraph("res/UI/GButton.png", 1, 1, 1, 60, 60, _GrAll["GButton"].data());
	_GrAll["RButton"].resize(1);
	ResourceServer::LoadDivGraph("res/UI/RButton.png", 1, 1, 1, 60, 60, _GrAll["RButton"].data());
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
		_GrHandle = _GrAll["BButton"][_Anime["BButton"]];
		break;
	case	2:
		_GrHandle = _GrAll["YButton"][_Anime["YButton"]];
		break;
	case 3:
		_GrHandle = _GrAll["GButton"][_Anime["GButton"]];
		break;
	case 4:
		_GrHandle = _GrAll["RButton"][_Anime["RButton"]];
		break;
	}
}

void Button::Draw(Game& g) {
	ObjectBase::Draw(g);
}