#pragma once
#include "ObjectBase.h"
//“GƒNƒ‰ƒX
namespace Tsk {
	class EnemyBase : public ObjectBase {
	protected:
		//“G‚Ìó‘Ô—ñ‹“
		enum class ENEMYSTATE { PATROL, COMING, ATTACK, DAMAGE, DEAD };
	public:
		EnemyBase();
		~EnemyBase();

		virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::ENEMY; }

		//“G‚Ìí—Ş—ñ‹“
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