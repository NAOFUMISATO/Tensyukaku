#pragma once
#include "ParticleBase.h"
#include <tuple>
#include <utility>
//攻撃予備動作の光
class ReserveLight : public ParticleBase {
public:
	ReserveLight(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~ReserveLight();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::RESERVELIGHT; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};

namespace EPInfo {
	//攻撃予備動作の光
	constexpr auto RESERVELIGHT_PARTICLE_GRAPH = "res/Particle/ReserveLight.png";		//画像ファイル名
	constexpr auto RESERVELIGHT_PARTICLE_POSITIONX = 0.0;								//基準点(足下)から描画点へのX座標差分
	constexpr auto RESERVELIGHT_PARTICLE_POSITIONY = -100.0;							//基準点(足下)から描画点へのY座標差分
	constexpr auto RESERVELIGHT_PARTICLE_BLENDMODE = DX_BLENDMODE_ADD;					//ブレンドモード設定
	constexpr auto RESERVELIGHT_PARTICLE_PAL = 128;										//ブレンド値(0～255)
	constexpr auto RESERVELIGHT_PARTICLE_RED = 128;									//赤色値(0～255)
	constexpr auto RESERVELIGHT_PARTICLE_GREEN = 128;									//緑色値(0～255)
	constexpr auto RESERVELIGHT_PARTICLE_BLUE = 128;									//青色値(0～255)
	constexpr auto RESERVELIGHT_PARTICLE_SCALE = 1.0;									//拡縮値(1.0がデフォルト)
	constexpr auto RESERVELIGHT_PARTICLE_ANGLE = 0.0;									//描画角度(3.14=180°)
	constexpr auto RESERVELIGHT_PARTICLE_CNT = 20;										//パーティクル1個あたりの生存時間
	constexpr auto RESERVELIGHT_PARTICLE_QTY = 10;										//1フレーム当たりのパーティクル数
	//パーティクル1個当たりの移動方向のランダム値調整
	constexpr auto RESERVELIGHT_PARTICLE_RANDOMX1 = 20;								//パーティクルのXランダム値
	constexpr auto RESERVELIGHT_PARTICLE_RANDOMX2 = 10.0;								//		〃
	constexpr auto RESERVELIGHT_PARTICLE_RANDOMX3 = 8.0;								//		〃
	constexpr auto RESERVELIGHT_PARTICLE_RANDOMY1 = 20;								//パーティクルのYランダム値
	constexpr auto RESERVELIGHT_PARTICLE_RANDOMY2 = 10.0;								//		〃
	constexpr auto RESERVELIGHT_PARTICLE_RANDOMY3 = 8.0;								//		〃

}