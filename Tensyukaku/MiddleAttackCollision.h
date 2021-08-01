#pragma once
#include	"ObjectBase.h"

// �v���C���[�̒��i�U�������蔻��N���X
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