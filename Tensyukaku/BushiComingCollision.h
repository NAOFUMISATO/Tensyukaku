#pragma once
#include	"ObjectBase.h"

// ���m�̍��G�͈͓����蔻��N���X
namespace Tsk {
	class Game;
	class BushiComingCollision : public ObjectBase {
	public:
		BushiComingCollision();
		~BushiComingCollision();
		virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::BUSHICOMING; }

		void	Init()override;
		void	Process(Game& g)override;
		void	Draw(Game& g)override;

	};
}
