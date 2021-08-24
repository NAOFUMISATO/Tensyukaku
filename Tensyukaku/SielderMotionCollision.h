#pragma once
#include	"ObjectBase.h"

// �����̍��G�͈͓����蔻��N���X
class Game;
class ShielderPatrolCollision : public ObjectBase {
public:
	ShielderPatrolCollision();
	~ShielderPatrolCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::SIELDERPATROL; }

	void	Init()override;
	void	Process(Game& g)override;
};

// �����̍U�������͈͓����蔻��N���X
class ShielderComingCollision : public ObjectBase {
public:
	ShielderComingCollision();
	~ShielderComingCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::SIELDERCOMING; }

	void	Init()override;
	void	Process(Game& g)override;
};

// �����̍U�������蔻��N���X
class ShielderAttackCollision : public ObjectBase {
public:
	ShielderAttackCollision();
	~ShielderAttackCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::SIELDERATTACK; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;

};



