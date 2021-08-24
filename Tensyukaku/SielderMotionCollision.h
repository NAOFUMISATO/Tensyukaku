#pragma once
#include	"ObjectBase.h"

// 盾兵の索敵範囲当たり判定クラス
class Game;
class ShielderPatrolCollision : public ObjectBase {
public:
	ShielderPatrolCollision();
	~ShielderPatrolCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::SIELDERPATROL; }

	void	Init()override;
	void	Process(Game& g)override;
};

// 盾兵の攻撃発生範囲当たり判定クラス
class ShielderComingCollision : public ObjectBase {
public:
	ShielderComingCollision();
	~ShielderComingCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::SIELDERCOMING; }

	void	Init()override;
	void	Process(Game& g)override;
};

// 盾兵の攻撃当たり判定クラス
class ShielderAttackCollision : public ObjectBase {
public:
	ShielderAttackCollision();
	~ShielderAttackCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::SIELDERATTACK; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;

};



