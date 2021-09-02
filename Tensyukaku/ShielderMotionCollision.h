#pragma once
#include	"ObjectBase.h"

// ‚•º‚ÌUŒ‚“–‚½‚è”»’èƒNƒ‰ƒX
class ShielderAttackCollision : public ObjectBase {
public:
	ShielderAttackCollision(int x, int y);
	~ShielderAttackCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::SHIELDERATTACK; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;

};
