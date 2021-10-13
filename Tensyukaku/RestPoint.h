#pragma once
#include "ObjectBase.h"

class RestPoint :public ObjectBase {
public:
   RestPoint(int x,int y);
   ~RestPoint();
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::RESTPOINT; }
   void Init()override;
   void Process(Game& g)override;
   void Draw(Game& g)override;
private:
   int _graph_no;
   bool _hit_flag;
};