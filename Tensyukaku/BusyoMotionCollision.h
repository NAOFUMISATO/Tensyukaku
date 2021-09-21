#pragma once
#include	"ObjectBase.h"

// �����̍U�������蔻��N���X
class BusyoAttackCollision : public ObjectBase {
public:
	BusyoAttackCollision(int x, int y);
	~BusyoAttackCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::BUSYOATTACK; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;

};
