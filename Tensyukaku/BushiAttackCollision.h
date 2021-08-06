#pragma once
#include	"ObjectBase.h"

// プレイヤーの中段攻撃当たり判定クラス
namespace Tsk {
	class Game;
	class BushiAttackCollision : public ObjectBase {
	public:
		BushiAttackCollision();
		~BushiAttackCollision();
		virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::BUSHIATTACK; }

		void	Init()override;
		void	Process(Game& g)override;
		void	Draw(Game& g)override;
		void	Damage(Game& g)override;

	};
}