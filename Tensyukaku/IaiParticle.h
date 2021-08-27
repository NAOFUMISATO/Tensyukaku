#pragma once
#include "ParticleBase.h"
#include <tuple>
#include <utility>
class IaiParticle1 : public ParticleBase {
public:
	IaiParticle1(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~IaiParticle1();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::IAI1; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
class IaiParticle2 : public ParticleBase {
public:
	IaiParticle2(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~IaiParticle2();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::IAI2; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
class IaiParticle3 : public ParticleBase {
public:
	IaiParticle3(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~IaiParticle3();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::IAI3; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};

