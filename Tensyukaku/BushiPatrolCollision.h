#pragma once
#include	"ObjectBase.h"

// •m‚Ìõ“G”ÍˆÍ“–‚½‚è”»’èƒNƒ‰ƒX
namespace Tsk {
	class Game;
	class BushiPatrolCollision : public ObjectBase {
	public:
		BushiPatrolCollision();
		~BushiPatrolCollision();
		virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::BUSHIPATROL; }

		void	Init()override;
		void	Process(Game& g)override;
	};
}
