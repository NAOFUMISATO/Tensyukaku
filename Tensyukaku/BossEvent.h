#pragma once
#include "ObjectBase.h"

class BossEventA :public ObjectBase {
public:
	BossEventA(int x,int y);
	~BossEventA();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::BOSSEVENTBLOCK; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
};

class BossEventB :public ObjectBase {
public:
	BossEventB(int x, int y);
	~BossEventB();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::BOSSEVENTBLOCK; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
};


namespace BEInfo {
	constexpr auto GRAPHPOINT_X = 0;		//X�ʒu����`��_�܂ł̍���
	constexpr auto GRAPHPOINT_Y = -50;		//Y�ʒu����`��_�܂ł̍���
	constexpr auto POSITION_HITX = -50;		//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto POSITION_HITY = -50;		//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto COLLISION_WIDTH = 100;	//�����蔻�艡��
	constexpr auto COLLISION_HEIGHT = 100;	//�����蔻��c��


}