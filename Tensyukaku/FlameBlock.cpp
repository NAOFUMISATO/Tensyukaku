#include "FlameBlock.h"
#include "OverlayFlame.h"
#include "Game.h"
namespace {
	constexpr auto GRAPHPOINT_X = 0;		//X�ʒu����`��_�܂ł̍���
	constexpr auto GRAPHPOINT_Y = -50;		//Y�ʒu����`��_�܂ł̍���
	constexpr auto POSITION_HITX = -50;		//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto POSITION_HITY = -50;		//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto COLLISION_WIDTH = 100;	//�K�i�̓����蔻�艡��
	constexpr auto COLLISION_HEIGHT = 100;	//�K�i�̓����蔻��c��
}
FlameBlock::FlameBlock(int x, int y) {
	_x = x;
	_y = y;
	Init();
}
FlameBlock::~FlameBlock() {
};

void FlameBlock::Init() {
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
#ifdef _DEBUG
	_Color = std::make_tuple(255, 0, 0);
	_Dalpha = 128;
	_Fill = true;
#endif
}
void  FlameBlock::Draw(Game& g) {
	ObjectBase::Draw(g);
	//�����o�u���b�N�ƃv���C���[�̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�̓v���C���[���H
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
		{
			// //�����o�u���b�N�ƃv���C���[�̓����蔻����s��
			if (IsHit(*(*ite)) == true)
			{
				Delete(g);
				auto of = new OverlayFlame();
				g.GetMS()->Add(of, 1, "Flame");
			}
		}
	}
}

void FlameBlock::Delete(Game& g) {
	g.GetOS()->Del(this);
}