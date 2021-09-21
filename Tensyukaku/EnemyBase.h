#pragma once
#include "ObjectBase.h"
//“G‚ÌŠî’êƒNƒ‰ƒX

class EnemyBase : public ObjectBase {
protected:
	//“G‚Ìó‘Ô—ñ‹“
	enum class ENEMYSTATE { APPEAR, PATROL, COMING, ATTACK,GUARDATTACK,THROW,GUARDBREAK, DAMAGE, DEAD };
public:
	EnemyBase();
	~EnemyBase();

	virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::ENEMY; }

	//“G‚Ìí—Ş—ñ‹“
	enum class ENEMYTYPE {
		BUSHI, BUSYO,NINJA,ZYOUNIN, LANCER, SHIELDER
	};
	virtual ENEMYTYPE GetEneType() = 0;

	virtual	void	Init();
	virtual	void	Process(Game& g);
	virtual	void	Draw(Game& g);
	virtual	void	Delete(Game& g) {};

protected:
	ENEMYTYPE _Type;
	ENEMYSTATE _State;
};

