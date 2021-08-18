#pragma once
#include "ObjectBase.h"


class PlayerHp :public ObjectBase {
public:
	PlayerHp();
	~PlayerHp();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::UI; }
	void Init()override;
	void Process(Game& g)override;
	int GetHp1() { return _Hp1_GrHandle; }
	int GetHp2() { return _Hp2_GrHandle; }
	int GetHp3() { return _Hp3_GrHandle; }
private:
	int _Hp1_GrHandle;
	int _Hp2_GrHandle;
	int _Hp3_GrHandle;
};