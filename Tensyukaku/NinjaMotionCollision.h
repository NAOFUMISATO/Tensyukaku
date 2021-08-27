#pragma once
#include	"ObjectBase.h"

// �E�҂̍��G�͈͓����蔻��N���X

class Game;
class NinjaPatrolCollision : public ObjectBase {
public:
	NinjaPatrolCollision(int x, int y);
	~NinjaPatrolCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::NINJAPATROL; }

	void	Init()override;
};

// �E�҂̍U�������͈͓����蔻��N���X
class NinjaComingCollision : public ObjectBase {
public:
	NinjaComingCollision(int x, int y);
	~NinjaComingCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::NINJACOMING; }

	void	Init()override;
};

// �E�҂̍U�������蔻��N���X
class NinjaAttackCollision : public ObjectBase {
public:
	NinjaAttackCollision(int x, int y);
	~NinjaAttackCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::NINJAATTACK; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;

};
