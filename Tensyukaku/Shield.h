#pragma once
#include "ObjectBase.h"

class Shield :public ObjectBase {
public:
	Shield();
	~Shield();

	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::SHIELD; }
	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	int		GetHandle() { return _GrHandle; }
	double	GetAngle() { return _drg.second; }
	void	SetAngle(double angle) { _drg.second = angle; }
};

namespace ShInfo {
	/*----------èÇÇÃç¿ïWä÷åW----------*/
	constexpr auto GraphWidth = 160;
	constexpr auto GraphHeight = 230;
	constexpr auto GraphX = 0;
	constexpr auto GraphY = -80;
	constexpr auto PositionHitX = -30;
	constexpr auto PositionHitY = -115;
	constexpr auto CollisionWidth = 60;
	constexpr auto CollisionHeight = 230;

	/*---------ï`âÊä÷åW----------*/
	constexpr auto Angle = -0.2;

	/*----------èÇïˆÇµÇÃãììÆä÷åW----------*/
	constexpr auto Shield_Frame = 60;
	constexpr auto GraphPointX = 0;
	constexpr auto GraphPointY = -60;
	constexpr auto Alpha = 255;
	constexpr auto AnChange = 0.05;
	constexpr auto AlChange = 5;
	constexpr auto XChange = 2;
	constexpr auto YChange = 10;

}