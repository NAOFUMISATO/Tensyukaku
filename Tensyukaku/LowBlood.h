#pragma once
#include "EfectBase.h"

class LowBlood :public EfectBase {
public:
	LowBlood(int x, int y, bool flip, int bloodtype);
	~LowBlood();
	virtual EFECTTYPE GetEfeType() { return EFECTTYPE::LOWBLOOD; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
private:
	int  _blood_type;
};