#pragma once
#include	"ObjectBase.h"

// •m‚ÌUŒ‚“–‚½‚è”»’èƒNƒ‰ƒX
class BushiAttackCollision : public ObjectBase {
public:
	BushiAttackCollision(int x, int y);
	~BushiAttackCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::BUSHIATTACK; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;

};


