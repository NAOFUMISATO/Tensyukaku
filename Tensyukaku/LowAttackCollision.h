#pragma once
#include	"ObjectBase.h"

// �v���C���[�̒��i�U�������蔻��N���X
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