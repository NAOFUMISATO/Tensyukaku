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
	double	GetAngle() { return _Drg.second; }
	void	SetAngle(double angle) { _Drg.second = angle; }
};
