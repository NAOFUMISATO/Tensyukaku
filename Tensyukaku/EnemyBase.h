#pragma once
#include "ObjectBase.h"
//�G�N���X
namespace Tsk {
	class EnemyBase : public ObjectBase {
	protected:
		//�G�̏�ԗ�
		enum class ENEMYSTATE { PATROL, COMING, ATTACK, DAMAGE, DEAD };
	public:
		EnemyBase();
		~EnemyBase();

		virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::ENEMY; }

		//�G�̎�ޗ�
		enum class ENEMYTYPE {
			BUSHI, NINJA, SHIELD
		};
		virtual ENEMYTYPE GetEneType() = 0;

		virtual	void	Init();
		virtual	void	Process(Game& g);
		/*virtual	void	Damage(Game& g);
		virtual	void	Draw(Game& g);*/

	protected:
		int		_Life;
		ENEMYTYPE _Type;
		ENEMYSTATE _State;
	};

}