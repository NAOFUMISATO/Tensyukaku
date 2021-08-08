#pragma once
#include	"ObjectBase.h"

// ”EÒ‚Ìõ“G”ÍˆÍ“–‚½‚è”»’èƒNƒ‰ƒX
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

// ”EÒ‚ÌUŒ‚”­¶”ÍˆÍ“–‚½‚è”»’èƒNƒ‰ƒX
	class NinjaComingCollision : public ObjectBase {
	public:
		NinjaComingCollision();
		~NinjaComingCollision();
		virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::NINJACOMING; }

		void	Init()override;
		void	Process(Game& g)override;
	};

// ”EÒ‚ÌUŒ‚“–‚½‚è”»’èƒNƒ‰ƒX
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
