#pragma once
#include	"ObjectBase.h"



// ���m�̍��G�͈͓����蔻��N���X
class Game;
class BushiPatrolCollision : public ObjectBase {
public:
	BushiPatrolCollision();
	~BushiPatrolCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::BUSHIPATROL; }

	void	Init()override;
};

// ���m�̍U�������͈͓����蔻��N���X
class BushiComingCollision : public ObjectBase {
public:
	BushiComingCollision();
	~BushiComingCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::BUSHICOMING; }

	void	Init()override;
};

// ���m�̍U�������蔻��N���X
class BushiAttackCollision : public ObjectBase {
public:
	BushiAttackCollision();
	~BushiAttackCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::BUSHIATTACK; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;

};


