#pragma once

class Game;
class EnemySpawn {
public:
   EnemySpawn(Game& g);
   ~EnemySpawn();

   void Init(Game& g);
};
