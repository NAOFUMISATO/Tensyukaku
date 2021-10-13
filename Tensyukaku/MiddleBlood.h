#pragma once
#include "EfectBase.h"

class MiddleBlood :public EfectBase {
public:
   MiddleBlood(int x, int y,  bool flip, int bloodtype);
   ~MiddleBlood();
   virtual EFECTTYPE GetEfeType() { return EFECTTYPE::MIDDLEBLOOD; }
   void Init()override;
   void Process(Game& g)override;
   void Draw(Game& g)override;
   void Delete(Game& g)override;
private:
   int  _blood_type;
};