#pragma once
#include	"ObjectBase.h"

// �����̍��G�͈͓����蔻��N���X
class Game;
class ShielderPatrolCollision : public ObjectBase {
public:
	ShielderPatrolCollision();
	~ShielderPatrolCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::SHIELDERPATROL; }

	void	Init()override;
};

// �����̍U�������͈͓����蔻��N���X
class ShielderComingCollision : public ObjectBase {
public:
	ShielderComingCollision();
	~ShielderComingCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::SHIELDERCOMING; }

	void	Init()override;
};

// �����̍U�������蔻��N���X
class ShielderAttackCollision : public ObjectBase {
public:
	ShielderAttackCollision();
	~ShielderAttackCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::SHIELDERATTACK; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;

};


