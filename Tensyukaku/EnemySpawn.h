#pragma once

class Game;
class EnemySpawn {
public:
	EnemySpawn(Game& g);
	~EnemySpawn();

	void Process(Game& g);

private:
	bool _Appear_Flag;
};
