#pragma once
#include "ObjectBase.h"
//�G�̊��N���X

class EnemyBase : public ObjectBase {
protected:
	//�G�̏�ԗ�
	enum class ENEMYSTATE { APPEAR, PATROL, COMING, ATTACK,GUARDATTACK,THROW,GUARDBREAK, DAMAGE, DEAD };
public:
	EnemyBase();
	~EnemyBase();

	virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::ENEMY; }

	//�G�̎�ޗ�
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

