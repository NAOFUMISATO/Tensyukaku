#pragma once
#include  "ObjectBase.h"

class TutorialBoard :public ObjectBase {
public:
	TutorialBoard(int x,int y,int num);
	~TutorialBoard();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::TUTORIALBOARD; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
private:
	int _TutorialNum;
	bool _Appear_Flag;
	bool _Touch_Flag;
};