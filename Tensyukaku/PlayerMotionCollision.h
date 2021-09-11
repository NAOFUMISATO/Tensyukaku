#pragma once
#include	"ObjectBase.h"

// �v���C���[�̒��i�U�������蔻��N���X

class Game;
class MiddleAttackCollision : public ObjectBase {
public:
	MiddleAttackCollision(int x, int y);
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
	LowAttackCollision(int x, int y);
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
	KickCollision(int x, int y);
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
	IaiCollision(int x, int y);
	~IaiCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::IAI; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;
};

//�v���C���[�̓���U�������蔻��N���X
class SpecialCollision : public ObjectBase {
public:
	SpecialCollision(int x, int y);
	~SpecialCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::IAI; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;
};
