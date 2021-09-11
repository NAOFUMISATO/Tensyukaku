#pragma once
#include	"ObjectBase.h"

// プレイヤーの中段攻撃当たり判定クラス

class Game;
class MiddleAttackCollision : public ObjectBase {
public:
	MiddleAttackCollision(int x, int y);
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
	LowAttackCollision(int x, int y);
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
	KickCollision(int x, int y);
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
	IaiCollision(int x, int y);
	~IaiCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::IAI; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;
};

//プレイヤーの特殊攻撃当たり判定クラス
class SpecialCollision : public ObjectBase {
public:
	SpecialCollision(int x, int y);
	~SpecialCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::IAI; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;
};
