#pragma once
#include	"ObjectBase.h"



// •m‚Ìõ“G”ÍˆÍ“–‚½‚è”»’èƒNƒ‰ƒX
class Game;
class BushiPatrolCollision : public ObjectBase {
public:
	BushiPatrolCollision(int x, int y);
	~BushiPatrolCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::BUSHIPATROL; }

	void	Init()override;
};

// •m‚ÌUŒ‚”­¶”ÍˆÍ“–‚½‚è”»’èƒNƒ‰ƒX
class BushiComingCollision : public ObjectBase {
public:
	BushiComingCollision(int x, int y);
	~BushiComingCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::BUSHICOMING; }

	void	Init()override;
};

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


