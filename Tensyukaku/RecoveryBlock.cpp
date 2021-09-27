#include "RecoveryBlock.h"
#include "Game.h"
namespace {
	constexpr auto GRAPHPOINT_X = 0;		//X�ʒu����`��_�܂ł̍���
	constexpr auto GRAPHPOINT_Y = -50;		//Y�ʒu����`��_�܂ł̍���
	constexpr auto POSITION_HITX = -50;		//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto POSITION_HITY = -50;		//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto COLLISION_WIDTH = 100;	//�����蔻�艡��
	constexpr auto COLLISION_HEIGHT = 100;	//�����蔻��c��
}
RecoveryBlock::RecoveryBlock(int x, int y) {
	_x = x;
	_y = y;
	Init();
}
RecoveryBlock::~RecoveryBlock() {
};

void RecoveryBlock::Init() {
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
#ifdef _DEBUG
	_debug_color = std::make_tuple(255, 100, 5);
	_debug_alpha = 128;
	_debug_fill = true;
#endif
}
void  RecoveryBlock::Draw(Game& g) {
	ObjectBase::Draw(g);
}

void RecoveryBlock::Delete(Game& g) {
	g.GetOS()->Del(this);
}