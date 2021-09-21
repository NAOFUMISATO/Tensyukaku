#pragma once
#include "ObjectBase.h"

class MugenFlame :public ObjectBase {
public:
	MugenFlame(int x, int y);
	~MugenFlame();

	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::MUGENFLAME; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
};

namespace MFInfo {
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
	constexpr auto MFLAME_GRAPHNAME = "res/Gimik/Flame.png";	//画像ファイル名
	constexpr auto MFLAME_ANIMEMAX = 7;		//全ての画像枚数
	constexpr auto MFLAME_WIDTHCOUNT = 7;		//横の画像枚数
	constexpr auto MFLAME_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_MFLAME = 15;		//各状態アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto MFLAME_ANIMEFRAME = MFLAME_ANIMEMAX * ANIMESPEED_MFLAME;		//アニメーションフレーム（全ての画像枚数×アニメスピード）
	constexpr auto MFLAME_ALLFLAME = 135;
	constexpr auto MFLAME_FADEOUTSPEED = 4;		//フェードスピード

}