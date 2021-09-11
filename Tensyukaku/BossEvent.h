#pragma once
#include "ObjectBase.h"

class BossEventA :public ObjectBase {
public:
	BossEventA(int x,int y);
	~BossEventA();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::BOSSEVENTBLOCK; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
};

class BossEventB :public ObjectBase {
public:
	BossEventB(int x, int y);
	~BossEventB();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::BOSSEVENTBLOCK; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
};


namespace BEInfo {
	constexpr auto GRAPHPOINT_X = 0;		//X位置から描画点までの差分
	constexpr auto GRAPHPOINT_Y = -50;		//Y位置から描画点までの差分
	constexpr auto POSITION_HITX = -50;		//描画点から当たり判定左上座標までの差分
	constexpr auto POSITION_HITY = -50;		//描画点から当たり判定左上座標までの差分
	constexpr auto COLLISION_WIDTH = 100;	//当たり判定横幅
	constexpr auto COLLISION_HEIGHT = 100;	//当たり判定縦幅


}