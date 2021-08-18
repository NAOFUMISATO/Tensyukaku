#pragma once
#include "ParticleBase.h"
#include <tuple>
#include <utility>
class HitBushiParticle : public ParticleBase {
public:
	HitBushiParticle(std::pair<double, double> xy, std::pair<double, double> vxy);
	~HitBushiParticle();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::HITBUSHI; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};