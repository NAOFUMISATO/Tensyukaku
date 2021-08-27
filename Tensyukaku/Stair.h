#pragma once
#include "ObjectBase.h"


class Stair :public ObjectBase {
public:
	Stair(int x,int y,bool flip);
	~Stair();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::STAIR; }
	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
};

namespace StInfo {
	constexpr auto GRAPHPOINT_X = 0;			//X�ʒu����`��_�܂ł̍���
	constexpr auto GRAPHPOINT_Y = -400;			//Y�ʒu����`��_�܂ł̍���
	constexpr auto POSITION_HITX = -120;		//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto POSITION_HITY = -360;		//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto COLLISION_WIDTH = 240;		//�K�i�̓����蔻�艡��
	constexpr auto COLLISION_HEIGHT = 760;		//�K�i�̓����蔻��c��
}
