#pragma once
#include	"ObjectBase.h"

// ��E�̍U�������蔻��N���X
class ZyouninAttackCollision : public ObjectBase {
public:
	ZyouninAttackCollision(int x, int y);
	~ZyouninAttackCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::ZYOUNINATTACK; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;

};
