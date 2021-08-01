#pragma once

#include	"ModeBase.h"

namespace Tsk {
	class ModeTitle : public ModeBase
	{
		typedef ModeBase base;
	public:
		virtual bool Initialize(Game& g);
		virtual bool Terminate(Game& g);
		virtual bool Process(Game& g);
		virtual bool Draw(Game& g);

	protected:

		// ƒ^ƒCƒgƒ‹
		int		_cgTitle;


	};
}
