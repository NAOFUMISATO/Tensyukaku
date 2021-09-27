#pragma once
#include "ObjectBase.h"
#include <tuple>
/*
ó‚¯‘¤‚Å”»’è‚ğæ‚ç‚È‚¢Û‚Ì“–‚½‚è”»’èƒNƒ‰ƒX
*/
class PrivateCollision : public ObjectBase {
public:
	PrivateCollision(int x, int y, int hit_w, int hit_h);
	~PrivateCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::PRIVATECOLLISION; }

	void	Init()override;
	void	SetColor(std::tuple<int, int, int> color) { _debug_color = color; }
};