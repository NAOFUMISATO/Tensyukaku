#pragma once
#include	"ObjectBase.h"

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
