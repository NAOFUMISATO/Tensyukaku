#pragma once
#include "ObjectBase.h"

class Kunai :public ObjectBase {
public:
   Kunai(int x,int y,bool flip,int spd);
   ~Kunai();

   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::KUNAI; }
   void Init()override;
   void Process(Game& g)override;
   void Draw(Game& g)override;
   void Delete(Game& g)override;
private:
   bool _Repel_Flag;
};