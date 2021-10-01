#pragma once
#include "ObjectBase.h"
#include <tuple>
#include <utility>
class Game;
class ParticleBase :public ObjectBase {
public:
	ParticleBase();
	~ParticleBase();
	virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::PARTICLE; }

	enum class PARTICLETYPE {
		CURSOR1,OVERCURSOR1, FLAMEPERFORM,
		LOWATTACK1, LOWATTACK2,MIDDLEATTACK1,MIDDLEATTACK2,IAI1,IAI2,IAI3,IAIGAUGE,SWAY,
		KUNAIRESERVELIGHT, LANCERESERVELIGHT
	};
	virtual PARTICLETYPE GetParType() = 0;
	virtual void Init();
	virtual void Process(Game& g);
	virtual void Draw(Game& g);
protected:
	std::pair<double, double> _xy;
	std::pair<double, double> _dxy;
	std::pair<double, double> _mxy;
	int	_pal;
	int _bm;
	std::tuple<int, int, int> _rgb;
};