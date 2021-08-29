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
