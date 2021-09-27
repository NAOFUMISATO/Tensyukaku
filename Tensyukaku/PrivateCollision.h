#pragma once
#include "ObjectBase.h"
#include <tuple>
/*
�󂯑��Ŕ�������Ȃ��ۂ̓����蔻��N���X
*/
class PrivateCollision : public ObjectBase {
public:
	PrivateCollision(int x, int y, int hit_w, int hit_h);
	~PrivateCollision();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::PRIVATECOLLISION; }

	void	Init()override;
	void	SetColor(std::tuple<int, int, int> color) { _debug_color = color; }
};