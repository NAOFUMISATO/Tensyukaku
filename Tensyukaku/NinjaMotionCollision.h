#pragma once
#include	"ObjectBase.h"

// ”EÒ‚ÌUŒ‚“–‚½‚è”»’èƒNƒ‰ƒX
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
