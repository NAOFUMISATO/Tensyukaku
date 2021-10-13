#pragma once
#include "ObjectBase.h"

class RecoveryBlock :public ObjectBase {
public:
   RecoveryBlock(int x,int y);
   ~RecoveryBlock();
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::RECOVERYBLOCK; }
   void Init()override;
   void Draw(Game& g)override;
   void Delete(Game& g)override;
};