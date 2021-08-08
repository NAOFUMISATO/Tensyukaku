#pragma once
#include	"ObjectBase.h"

// �E�҂̍��G�͈͓����蔻��N���X
namespace Tsk {
	class Game;
	class NinjaPatrolCollision : public ObjectBase {
	public:
		NinjaPatrolCollision();
		~NinjaPatrolCollision();
		virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::NINJAPATROL; }

		void	Init()override;
		void	Process(Game& g)override;
	};

// �E�҂̍U�������͈͓����蔻��N���X
	class NinjaComingCollision : public ObjectBase {
	public:
		NinjaComingCollision();
		~NinjaComingCollision();
		virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::NINJACOMING; }

		void	Init()override;
		void	Process(Game& g)override;
	};

// �E�҂̍U�������蔻��N���X
	class NinjaAttackCollision : public ObjectBase {
	public:
		NinjaAttackCollision();
		~NinjaAttackCollision();
		virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::NINJAATTACK; }

		void	Init()override;
		void	Process(Game& g)override;
		void	Draw(Game& g)override;
		void	Delete(Game& g)override;

	};
}
