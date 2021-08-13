#pragma once
#include	"ObjectBase.h"

// プレイヤーの中段攻撃当たり判定クラス

class Game;
class MiddleAttackCollision : public ObjectBase {
public:
	MiddleAttackCollision();
	~MiddleAttackCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::MIDDLEATTACK; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;
};
	
// プレイヤーの下段攻撃当たり判定クラス
class LowAttackCollision : public ObjectBase {
public:
	LowAttackCollision();
	~LowAttackCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::LOWATTACK; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;
};

//プレイヤーの蹴り当たり判定クラス
class KickCollision : public ObjectBase {
public:
	KickCollision();
	~KickCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::KICK; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;
};
	
//プレイヤーの居合当たり判定クラス
class IaiCollision : public ObjectBase {
public:
	IaiCollision();
	~IaiCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::IAI; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;
};
