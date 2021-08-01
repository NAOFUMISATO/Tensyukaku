#pragma once
namespace Tsk {
	class Game;
	// ”wŒiƒNƒ‰ƒX
	class BackGround {
	public:
		BackGround();
		~BackGround();

		void	Draw(Game& g);

	private:
		int		_GrHandle;		// ‰æ‘œ
	};
}