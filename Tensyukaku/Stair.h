#pragma once
#include "ObjectBase.h"


class Stair :public ObjectBase {
public:
	Stair(int x,int y,bool flip);
	~Stair();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::STAIR; }
	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
};

namespace StInfo {
	constexpr auto GRAPHPOINT_X = 0;			//X位置から描画点までの差分
	constexpr auto GRAPHPOINT_Y = -400;			//Y位置から描画点までの差分
	constexpr auto POSITION_HITX = -120;		//描画点から当たり判定左上座標までの差分
	constexpr auto POSITION_HITY = -360;		//描画点から当たり判定左上座標までの差分
	constexpr auto COLLISION_WIDTH = 240;		//階段の当たり判定横幅
	constexpr auto COLLISION_HEIGHT = 760;		//階段の当たり判定縦幅
}
