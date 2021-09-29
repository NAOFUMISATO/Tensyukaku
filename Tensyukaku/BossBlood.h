#pragma once
#include "EfectBase.h"

class BossBlood :public EfectBase {
public:
	BossBlood(int x, int y, int bloodtype);
	~BossBlood();
	virtual EFECTTYPE GetEfeType() { return EFECTTYPE::BOSSBLOOD; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
private:
	int  _blood_type;
};