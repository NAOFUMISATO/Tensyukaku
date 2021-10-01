#pragma once
#include "ParticleBase.h"
#include <tuple>
#include <utility>
//クナイ投げ予備動作の光
class KunaiReserveLight : public ParticleBase {
public:
	KunaiReserveLight(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~KunaiReserveLight();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::KUNAIRESERVELIGHT; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
//槍兵予備動作の光
class LanceReserveLight : public ParticleBase {
public:
	LanceReserveLight(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~LanceReserveLight();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::LANCERESERVELIGHT; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
namespace EPInfo {
	//クナイ投げ予備動作の光
	constexpr auto KRESERVELIGHT_PARTICLE_GRAPH = "res/Particle/KunaiReserveLight.png";		//画像ファイル名
	constexpr auto KRESERVELIGHT_PARTICLE_POSITIONX = 0.0;								//基準点(足下)から描画点へのX座標差分
	constexpr auto KRESERVELIGHT_PARTICLE_POSITIONY = -100.0;							//基準点(足下)から描画点へのY座標差分
	constexpr auto KRESERVELIGHT_PARTICLE_BLENDMODE = DX_BLENDMODE_ADD;					//ブレンドモード設定
	constexpr auto KRESERVELIGHT_PARTICLE_PAL = 128;										//ブレンド値(0～255)
	constexpr auto KRESERVELIGHT_PARTICLE_RED = 128;									//赤色値(0～255)
	constexpr auto KRESERVELIGHT_PARTICLE_GREEN = 128;									//緑色値(0～255)
	constexpr auto KRESERVELIGHT_PARTICLE_BLUE = 128;									//青色値(0～255)
	constexpr auto KRESERVELIGHT_PARTICLE_SCALE = 1.0;									//拡縮値(1.0がデフォルト)
	constexpr auto KRESERVELIGHT_PARTICLE_ANGLE = 0.0;									//描画角度(3.14=180°)
	constexpr auto KRESERVELIGHT_PARTICLE_CNT = 20;										//パーティクル1個あたりの生存時間
	constexpr auto KRESERVELIGHT_PARTICLE_QTY = 10;										//1フレーム当たりのパーティクル数
	//パーティクル1個当たりの移動方向のランダム値調整
	constexpr auto KRESERVELIGHT_PARTICLE_RANDOMX1 = 20;								//パーティクルのXランダム値
	constexpr auto KRESERVELIGHT_PARTICLE_RANDOMX2 = 10.0;								//		〃
	constexpr auto KRESERVELIGHT_PARTICLE_RANDOMX3 = 8.0;								//		〃
	constexpr auto KRESERVELIGHT_PARTICLE_RANDOMY1 = 20;								//パーティクルのYランダム値
	constexpr auto KRESERVELIGHT_PARTICLE_RANDOMY2 = 10.0;								//		〃
	constexpr auto KRESERVELIGHT_PARTICLE_RANDOMY3 = 8.0;								//		〃
	//槍兵予備動作の光
	constexpr auto LRESERVELIGHT_PARTICLE_GRAPH = "res/Particle/LanceReserveLight.png";		//画像ファイル名
	constexpr auto LRESERVELIGHT_PARTICLE_POSITIONX = 0.0;								//基準点(足下)から描画点へのX座標差分
	constexpr auto LRESERVELIGHT_PARTICLE_POSITIONY = -250.0;							//基準点(足下)から描画点へのY座標差分
	constexpr auto LRESERVELIGHT_PARTICLE_BLENDMODE = DX_BLENDMODE_ADD;					//ブレンドモード設定
	constexpr auto LRESERVELIGHT_PARTICLE_PAL = 128;										//ブレンド値(0～255)
	constexpr auto LRESERVELIGHT_PARTICLE_RED = 128;									//赤色値(0～255)
	constexpr auto LRESERVELIGHT_PARTICLE_GREEN = 128;									//緑色値(0～255)
	constexpr auto LRESERVELIGHT_PARTICLE_BLUE = 128;									//青色値(0～255)
	constexpr auto LRESERVELIGHT_PARTICLE_SCALE = 1.0;									//拡縮値(1.0がデフォルト)
	constexpr auto LRESERVELIGHT_PARTICLE_ANGLE = 0.0;									//描画角度(3.14=180°)
	constexpr auto LRESERVELIGHT_PARTICLE_CNT = 20;										//パーティクル1個あたりの生存時間
	constexpr auto LRESERVELIGHT_PARTICLE_QTY = 10;										//1フレーム当たりのパーティクル数
	//パーティクル1個当たりの移動方向のランダム値調整
	constexpr auto LRESERVELIGHT_PARTICLE_RANDOMX1 = 20;								//パーティクルのXランダム値
	constexpr auto LRESERVELIGHT_PARTICLE_RANDOMX2 = 10.0;								//		〃
	constexpr auto LRESERVELIGHT_PARTICLE_RANDOMX3 = 8.0;								//		〃
	constexpr auto LRESERVELIGHT_PARTICLE_RANDOMY1 = 20;								//パーティクルのYランダム値
	constexpr auto LRESERVELIGHT_PARTICLE_RANDOMY2 = 10.0;								//		〃
	constexpr auto LRESERVELIGHT_PARTICLE_RANDOMY3 = 8.0;								//		〃
}