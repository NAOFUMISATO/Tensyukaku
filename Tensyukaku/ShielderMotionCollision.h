#pragma once
#include	"ObjectBase.h"

// 盾兵の索敵範囲当たり判定クラス
class Game;
class ShielderPatrolCollision : public ObjectBase {
public:
	ShielderPatrolCollision(int x, int y);
	~ShielderPatrolCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::SHIELDERPATROL; }

	void	Init()override;
};

// 盾兵の攻撃発生範囲当たり判定クラス
class ShielderComingCollision : public ObjectBase {
public:
	ShielderComingCollision(int x,int y);
	~ShielderComingCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::SHIELDERCOMING; }

	void	Init()override;
};

// 盾兵の攻撃当たり判定クラス
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



