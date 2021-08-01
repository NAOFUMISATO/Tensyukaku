#pragma once
#include	"ObjectBase.h"

// プレイヤーの中段攻撃当たり判定クラス
namespace Tsk {
	class Game;
	class MiddleAttackCollision : public ObjectBase {
	public:
		MiddleAttackCollision();
		~MiddleAttackCollision();
		virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::MIDDLEATTACK; }

		void	Init()override;
		void	Process(Game& g)override;
		void	Draw(Game& g)override;
		void	Damage(Game& g)override;
		void	DebugDraw();
	};
}