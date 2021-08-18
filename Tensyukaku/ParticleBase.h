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
		HITBUSHI,
	};
	virtual PARTICLETYPE GetParType() = 0;
	virtual void Init();
	virtual void Process(Game& g);
	virtual void Draw(Game& g);
protected:
	std::pair<double, double> _xy;
	std::pair<double, double> _dxy;
	std::pair<double, double> _mxy;
	int	_a;
	int _bm;
	std::tuple<int, int, int> _rgb;
	std::tuple<double, double, bool> _drg;
};

namespace ParInfo {
	/*----------ïêémîÌÉ_ÉÅ----------*/
	constexpr auto HitBushiPar_Graph = "res/Particle/slash.png";
	constexpr auto HitBushiPar_PozX = 0.0;
	constexpr auto HitBushiPar_PozY = -150.0;
	constexpr auto HitBushiPar_BLENDMODE = DX_BLENDMODE_SUB;
	constexpr auto HitBushiPar_Pal = 200;
	constexpr auto HitBushiPar_Red = 150;
	constexpr auto HitBushiPar_Green = 0;
	constexpr auto HitBushiPar_Blue = 0;
	constexpr auto HitBushiPar_Scale = 1.0;
	constexpr auto HitBushiPar_Angle = 2.0;
	constexpr auto HitBushiPar_Flip = false;
	constexpr auto HitBushiPar_Cnt = 10;
	constexpr auto HBP_Xrand1 = 1;
	constexpr auto HBP_Xrand2 = 1.5;
	constexpr auto HBP_Xrand3 = 1.0;
	constexpr auto HBP_Yrand1 = 1;
	constexpr auto HBP_Yrand2 = 1.5;
	constexpr auto HBP_Yrand3 = 1.0;
	/*----------Tupleå^â¬ì«ê´å¸è„---------*/
	constexpr auto Red = 0;
	constexpr auto Green = 1;
	constexpr auto Blue = 2;
	constexpr auto Scale = 0;
	constexpr auto Angle = 1;
	constexpr auto Flip = 2;
}