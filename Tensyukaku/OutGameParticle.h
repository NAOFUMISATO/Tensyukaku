#pragma once
#include "ParticleBase.h"
#include <tuple>
#include <utility>
//カーソル
class CursorParticle1: public ParticleBase {
public:
	CursorParticle1(std::pair<double, double> xy, std::pair<double, double> vxy,int colortype);
	~CursorParticle1();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::CURSOR1; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
private:
	int _ColorType;
};

namespace CParInfo {
	/*----------カーソル----------*/
	constexpr auto CURSOR_PARTICLE1_GRAPH = "res/Particle/Cursor.png";				//画像ファイル名
	constexpr auto CURSOR_PARTICLE1_POSITIONX = 0.0;								//基準点(足下)から描画点へのX座標差分
	constexpr auto CURSOR_PARTICLE1_POSITIONY = -10.0;								//基準点(足下)から描画点へのY座標差分
	constexpr auto CURSOR_PARTICLE1_BLENDMODE = DX_BLENDMODE_PMA_ADD;				//ブレンドモード設定
	constexpr auto CURSOR_PARTICLE1_PAL = 50;										//ブレンド値
	constexpr auto CURSOR_PARTICLE1_SCALE = 1.0;									//拡縮値
	constexpr auto CURSOR_PARTICLE1_ANGLE = 0.0;									//描画角度(3.14=180°)
	constexpr auto CURSOR_PARTICLE1_CNT = 30;										//パーティクル1個あたりの生存時間
	constexpr auto CURSOR_PARTICLE1_QTY = 7;										//1フレーム当たりのパーティクル数
	//パーティクル1個当たりの移動方向のランダム値調整
	constexpr auto CURSOR_PARTICLE1_RANDOMX1 = 30;									//パーティクルのXランダム値
	constexpr auto CURSOR_PARTICLE1_RANDOMX2 = 10.5;								//		〃
	constexpr auto CURSOR_PARTICLE1_RANDOMX3 = 10.5;								//		〃
	constexpr auto CURSOR_PARTICLE1_RANDOMY1 = 17;									//パーティクルのYランダム値
	constexpr auto CURSOR_PARTICLE1_RANDOMY2 = 19.5;								//		〃
	constexpr auto CURSOR_PARTICLE1_RANDOMY3 = 8.5;									//		〃
	
}