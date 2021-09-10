#pragma once
#include "ObjectBase.h"

class BossEventA :public ObjectBase {
public:
	BossEventA();
	~BossEventA();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::BOSSEVENTBLOCK; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
};

class BossEventB :public ObjectBase {
public:
	BossEventB();
	~BossEventB();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::BOSSEVENTBLOCK; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
};

class BossEventC :public ObjectBase {
public:
	BossEventC();
	~BossEventC();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::BOSSEVENTBLOCK; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
};

namespace BEInfo {
	constexpr auto GRAPHPOINT_X = 0;		//X�ʒu����`��_�܂ł̍���
	constexpr auto GRAPHPOINT_Y = 25;		//Y�ʒu����`��_�܂ł̍���
	constexpr auto POSITION_HITX = -20;		//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto POSITION_HITY = -30;		//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto COLLISION_WIDTH = 40;	//�����蔻�艡��
	constexpr auto COLLISION_HEIGHT = 60;	//�����蔻��c��


}