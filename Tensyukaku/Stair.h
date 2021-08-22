#pragma once
#include "ObjectBase.h"

class Stair :public ObjectBase {
public:
	Stair();
	~Stair();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::STAIR; }
	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
};

namespace SInfo {
	constexpr auto PositionX = 1200;			//横軸初期位置（足下が基準）
	constexpr auto PositionY = 2200;			//縦軸初期位置（足下が基準）
	constexpr auto GraphPointX = 0;				//X位置から描画点までの差分
	constexpr auto GraphPointY = -400;			//Y位置から描画点までの差分
	constexpr auto PositionHitX = -140;			//描画点から当たり判定左上座標までの差分
	constexpr auto PositionHitY = -360;			//描画点から当たり判定左上座標までの差分
	constexpr auto CollisionWidth = 200;		//階段の当たり判定横幅
	constexpr auto CollisionHeight = 760;		//階段の当たり判定縦幅
}
