#pragma once
#include  "ObjectBase.h"

class TutorialBoard :public ObjectBase {
public:
   TutorialBoard(std::string tutorialtype);
   ~TutorialBoard();
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::TUTORIALBOARD; }
   void Init()override;
   void Process(Game& g)override;
   void Draw(Game& g)override;
   void Delete(Game& g)override;
private:
   void TutorialPosition();

   std::string  _tutorial_type;
   bool _tutorialhit_flag;
};

namespace TBInfo{
   constexpr auto TUTORIAL1A_X = 800;
   constexpr auto TUTORIAL1A_Y = 9360;
   constexpr auto TUTORIAL1B_X = 1200;
   constexpr auto TUTORIAL1B_Y = 9360;
   constexpr auto TUTORIAL2A_X = 3200;
   constexpr auto TUTORIAL2A_Y = 8600;
   constexpr auto TUTORIAL3A_X = 500;
   constexpr auto TUTORIAL3A_Y = 7840;
   constexpr auto TUTORIAL3B_X = 2200;
   constexpr auto TUTORIAL3B_Y = 7840;
   constexpr auto TUTORIAL4A_X = 5200;
   constexpr auto TUTORIAL4A_Y = 7080;
   constexpr auto TUTORIAL5A_X = 3800;
   constexpr auto TUTORIAL5A_Y = 6320;
}