#pragma once
#include	"ObjectBase.h"

// ‘„•º‚ÌUŒ‚“–‚½‚è”»’èƒNƒ‰ƒX
class LancerAttackCollision : public ObjectBase {
public:
	LancerAttackCollision(int x, int y);
	~LancerAttackCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::LANCERATTACK; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;

};
