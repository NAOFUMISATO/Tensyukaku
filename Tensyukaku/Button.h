#pragma once
#include "ObjectBase.h"

class Button :public ObjectBase {
public:
	Button(int x,int y,int buttonnum);
	~Button();

	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::UI; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;

private:
	int	_ButtonNum;
};