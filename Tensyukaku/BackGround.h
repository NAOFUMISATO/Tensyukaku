#pragma once
namespace Tsk {
	class Game;
	// �w�i�N���X
	class BackGround {
	public:
		BackGround();
		~BackGround();

		void	Draw(Game& g);

	private:
		int		_GrHandle;		// �摜
	};
}