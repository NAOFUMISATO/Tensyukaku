#pragma once
#include	"ObjectBase.h"

// �v���C���[�̒��i�U�������蔻��N���X

class Game;
class MiddleAttackCollision : public ObjectBase {
public:
	MiddleAttackCollision();
	~MiddleAttackCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::MIDDLEATTACK; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;
};
	
// �v���C���[�̉��i�U�������蔻��N���X
class LowAttackCollision : public ObjectBase {
public:
	LowAttackCollision();
	~LowAttackCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::LOWATTACK; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;
};

//�v���C���[�̏R�蓖���蔻��N���X
class KickCollision : public ObjectBase {
public:
	KickCollision();
	~KickCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::KICK; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;
};
	
//�v���C���[�̋��������蔻��N���X
class IaiCollision : public ObjectBase {
public:
	IaiCollision();
	~IaiCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::IAI; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;
};
