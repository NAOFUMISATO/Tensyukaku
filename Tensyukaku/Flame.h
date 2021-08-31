#pragma once
#include "ObjectBase.h"

class Flame :public ObjectBase {
public:
	Flame(int x,int y);
	~Flame();

	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::FLAME; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
};

namespace FInfo {
	/*----------炎の各座標関係----------*/
	constexpr auto GRAPHPOINT_X = 0;		//X位置から描画点までの差分
	constexpr auto GRAPHPOINT_Y = -150;		//Y位置から描画点までの差分
	constexpr auto POSITION_HITX = -150;	//描画点から当たり判定左上座標までの差分
	constexpr auto POSITION_HITY = -150;	//描画点から当たり判定左上座標までの差分
	constexpr auto COLLISION_WIDTH = 300;	//当たり判定横幅
	constexpr auto COLLISION_HEIGHT = 300;	//当たり判定縦幅
	/*----------画像読み込み&アニメーション&判定フレーム関係----------*/
	constexpr auto GRAPH_WIDTH = 300;		//1枚当たりの画像サイズ（横）
	constexpr auto GRAPH_HEIGHT = 300;		//1枚当たりの画像サイズ（縦）
	//炎
	constexpr auto FLAME_GRAPHNAME = "res/Gimik/Flame.png";	//画像ファイル名
	constexpr auto FLAME_ANIMEMAX = 7;		//全ての画像枚数
	constexpr auto FLAME_WIDTHCOUNT = 7;		//横の画像枚数
	constexpr auto FLAME_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_FLAME = 15;		//各状態アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto FLAME_ANIMEFRAME = FLAME_ANIMEMAX * ANIMESPEED_FLAME;		//アニメーションフレーム（全ての画像枚数×アニメスピード）
	constexpr auto FLAME_ALLFLAME = 135;
	constexpr auto FLAME_FADEOUTSPEED = 4;		//フェードスピード
	
}