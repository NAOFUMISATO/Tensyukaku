#pragma once
#include	"ObjectBase.h"

// �v���C���[�̒��i�U�������蔻��N���X
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