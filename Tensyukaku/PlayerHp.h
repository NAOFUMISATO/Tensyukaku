#pragma once
#include "ObjectBase.h"

class PlayerHp :public ObjectBase {
public:
   PlayerHp(int hp);
   ~PlayerHp();
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::UI; }
   void Init()override;
   void Process(Game& g)override;
   void Draw(Game& g)override;
   void Delete(Game& g)override;
};

