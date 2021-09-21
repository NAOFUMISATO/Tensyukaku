#pragma once
#include "ObjectBase.h"

class MugenAndon :public ObjectBase {
public:
	MugenAndon(int x, int y);
	~MugenAndon();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::MUGENANDON; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
private:
	int _Flame_y;
	bool _AndonDrop_Flag;
	bool _PlayerFlip_Flag;
};

namespace MAInfo {
	/*----------行燈の各座標関係----------*/
	constexpr auto GRAPHPOINT_X = 0;			//X位置から描画点までの差分
	constexpr auto GRAPHPOINT_Y = -112;			//Y位置から描画点までの差分
	constexpr auto POSITION_HITX = -45;			//描画点から当たり判定左上座標までの差分
	constexpr auto POSITION_HITY = -113;		//描画点から当たり判定左上座標までの差分
	constexpr auto COLLISION_WIDTH = 90;		//プレイヤーの当たり判定横幅
	constexpr auto COLLISION_HEIGHT = 225;		//プレイヤーの当たり判定縦幅

	/*----------画像読み込み&アニメーション&判定フレーム関係----------*/
	//共通
	constexpr auto GRAPH_WIDTH = 90;			//1枚当たりの画像サイズ（横）
	constexpr auto GRAPH_HEIGHT = 225;			//1枚当たりの画像サイズ（縦）

	constexpr auto MANDON_GRAPHNAME = "res/Gimik/Andon.png";	//画像ファイル名
	constexpr auto MANDON_ANIMEMAX = 1;			//全ての画像枚数
	constexpr auto MANDON_WIDTHCOUNT = 1;		//横の画像枚数
	constexpr auto MANDON_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto MANDON_ALLFRAME = 90;			//行燈が倒れた際の消滅までのフレーム
	constexpr auto MANDON_DROPFRAME = 30;		//行燈が倒れきるまでのフレーム
	constexpr auto MANDON_DROPANGLE = 0.07;		//1フレーム当たりの行燈が倒れる角度
	constexpr auto MANDON_DROPANGLEMAX = 1.5;	//行燈の倒れる角度の最大値
	constexpr auto MANDON_DROPMOVEX = 4;		//行燈が倒れた際のXの移動量
	constexpr auto MANDON_DROPMOVEY = 2;		//行燈が倒れた際のYの移動量
	constexpr auto MANDON_FIREWIDTH = 100;		//生成される炎ごとの距離(中心点)
	constexpr auto MANDON_FIREFRAME1 = 40;		//炎が生成されるフレーム1
	constexpr auto MANDON_FIREFRAME2 = 60;		//炎が生成されるフレーム2
	constexpr auto MANDON_FIREFRAME3 = 80;		//炎が生成されるフレーム3
	constexpr auto MANDON_FADEOUTSPEED = 4;		//フェードアウトスピード

}