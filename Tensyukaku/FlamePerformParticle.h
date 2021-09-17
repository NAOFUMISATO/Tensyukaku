#pragma once
#include "ParticleBase.h"

class FlamePerform :public ParticleBase {
public:
	FlamePerform(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~FlamePerform();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::FLAMEPERFORM; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};

namespace FParInfo {
	/*----------炎演出----------*/
	constexpr auto FLAME_GRAPH = "res/Particle/Flame.png";			//画像ファイル名
	constexpr auto FLAME_POSITIONX = 0.0;							//基準点(足下)から描画点へのX座標差分
	constexpr auto FLAME_POSITIONY = 350.0;							//基準点(足下)から描画点へのY座標差分
	constexpr auto FLAME_BLENDMODE = DX_BLENDMODE_ADD;				//ブレンドモード設定
	constexpr auto FLAME_PAL = 64;									//ブレンド値(0～255)
	constexpr auto FLAME_RED = 240;									//赤色値(0～255)
	constexpr auto FLAME_GREEN = 70;								//緑色値(0～255)
	constexpr auto FLAME_BLUE = 5;									//青色値(0～255)
	constexpr auto FLAME_SCALE = 1.0;								//拡縮値(1.0がデフォルト)
	constexpr auto FLAME_ANGLE = 0.0;								//描画角度(3.14=180°)
	constexpr auto FLAME_CNT = 130;									//パーティクル1個あたりの生存時間
	constexpr auto FLAME_QTY = 1;									//1フレーム当たりのパーティクル数
	//パーティクル1個当たりの移動方向のランダム値調整
	constexpr auto FLAME_RANDOMX1 = 30;								//パーティクルのXランダム値
	constexpr auto FLAME_RANDOMX2 = 10.5;							//		〃
	constexpr auto FLAME_RANDOMX3 = 10.5;							//		〃
	constexpr auto FLAME_RANDOMY1 = 17;								//パーティクルのYランダム値
	constexpr auto FLAME_RANDOMY2 = 19.5;							//		〃
	constexpr auto FLAME_RANDOMY3 = 8.5;							//		〃
}