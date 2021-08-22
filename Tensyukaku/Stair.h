#pragma once
#include "ObjectBase.h"

class Stair :public ObjectBase {
public:
	Stair();
	~Stair();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::STAIR; }
	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
};

namespace SInfo {
	constexpr auto PositionX = 1200;			//���������ʒu�i��������j
	constexpr auto PositionY = 2200;			//�c�������ʒu�i��������j
	constexpr auto GraphPointX = 0;				//X�ʒu����`��_�܂ł̍���
	constexpr auto GraphPointY = -400;			//Y�ʒu����`��_�܂ł̍���
	constexpr auto PositionHitX = -140;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto PositionHitY = -360;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto CollisionWidth = 200;		//�K�i�̓����蔻�艡��
	constexpr auto CollisionHeight = 760;		//�K�i�̓����蔻��c��
}
