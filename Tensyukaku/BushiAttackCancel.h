#pragma once
#include	"ObjectBase.h"

// ���m�̍��G�͈͓����蔻��N���X
namespace Tsk {
	class Game;
	class BushiAttackCancel : public ObjectBase {
	public:
		BushiAttackCancel();
		~BushiAttackCancel();
		virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::BUSHIATTACKCANCEL; }

		void	Init()override;
		void	Process(Game& g)override;
		void	Draw(Game& g)override;

	};
}

