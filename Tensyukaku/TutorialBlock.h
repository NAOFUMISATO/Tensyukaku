#pragma once
#include  "ObjectBase.h"

class TutorialBlock :public ObjectBase {
public:
	TutorialBlock(int x,int y,int num);
	~TutorialBlock();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::TUTORIALBLOCK; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
private:
	int _TutorialNum;
	bool _Appear_Flag;
	bool _Touch_Flag;
};