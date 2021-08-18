#pragma once
#include "ParticleBase.h"
#include <tuple>
#include <utility>
class LowAttackParticle1 : public ParticleBase {
public:
	LowAttackParticle1(std::pair<double, double> xy, std::pair<double, double> vxy);
	~LowAttackParticle1();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::LOWATTACK1; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
class LowAttackParticle2 : public ParticleBase {
public:
	LowAttackParticle2(std::pair<double, double> xy, std::pair<double, double> vxy);
	~LowAttackParticle2();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::LOWATTACK2; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
