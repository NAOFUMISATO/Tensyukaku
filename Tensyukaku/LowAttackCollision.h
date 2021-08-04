#pragma once
#include	"ObjectBase.h"

// プレイヤーの中段攻撃当たり判定クラス
namespace Tsk {
	class Game;
	class LowAttackCollision : public ObjectBase {
	public:
		LowAttackCollision();
		~LowAttackCollision();
		virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::LOWATTACK; }

		void	Init()override;
		void	Process(Game& g)override;
		void	Draw(Game& g)override;
		void	Damage(Game& g)override;

	};
}