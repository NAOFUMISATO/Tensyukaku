#pragma once
#include "ParticleBase.h"
#include <tuple>
#include <utility>
class MiddleAttackParticle1 : public ParticleBase {
public:
	MiddleAttackParticle1(std::pair<double, double> xy, std::pair<double, double> vxy,bool flip);
	~MiddleAttackParticle1();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::MIDDLEATTACK1; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
class MiddleAttackParticle2 : public ParticleBase {
public:
	MiddleAttackParticle2(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~MiddleAttackParticle2();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::MIDDLEATTACK2; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};