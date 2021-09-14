#pragma once
#include "ParticleBase.h"
#include <tuple>
#include <utility>
//中段攻撃1
class MiddleAttackParticle1 : public ParticleBase {
public:
	MiddleAttackParticle1(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~MiddleAttackParticle1();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::MIDDLEATTACK1; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
//中段攻撃2
class MiddleAttackParticle2 : public ParticleBase {
public:
	MiddleAttackParticle2(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~MiddleAttackParticle2();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::MIDDLEATTACK2; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
//下段攻撃1
class LowAttackParticle1 : public ParticleBase {
public:
	LowAttackParticle1(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~LowAttackParticle1();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::LOWATTACK1; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
//下段攻撃2
class LowAttackParticle2 : public ParticleBase {
public:
	LowAttackParticle2(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~LowAttackParticle2();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::LOWATTACK2; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
//居合1
class IaiParticle1 : public ParticleBase {
public:
	IaiParticle1(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~IaiParticle1();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::IAI1; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
//居合2
class IaiParticle2 : public ParticleBase {
public:
	IaiParticle2(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~IaiParticle2();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::IAI2; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
//居合3
class IaiParticle3 : public ParticleBase {
public:
	IaiParticle3(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~IaiParticle3();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::IAI3; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
//居合ゲージ
class IaiGaugeParticle : public ParticleBase {
public:
	IaiGaugeParticle(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~IaiGaugeParticle();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::IAIGAUGE; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};

namespace PParInfo {
	/*----------中段攻撃1----------*/
	constexpr auto MIDDLEATTACK_PARTICLE1_GRAPH = "res/Particle/MiddleAttack.png";		//画像ファイル名
	constexpr auto MIDDLEATTACK_PARTICLE1_POSITIONX = 0.0;								//基準点(足下)から描画点へのX座標差分
	constexpr auto MIDDLEATTACK_PARTICLE1_POSITIONY = -325.0;							//基準点(足下)から描画点へのY座標差分
	constexpr auto MIDDLEATTACK_PARTICLE1_BLENDMODE = DX_BLENDMODE_SUB;					//ブレンドモード設定
	constexpr auto MIDDLEATTACK_PARTICLE1_PAL = 64;										//ブレンド値(0～255)
	constexpr auto MIDDLEATTACK_PARTICLE1_RED = 128;									//赤色値(0～255)
	constexpr auto MIDDLEATTACK_PARTICLE1_GREEN = 128;									//緑色値(0～255)
	constexpr auto MIDDLEATTACK_PARTICLE1_BLUE = 128;									//青色値(0～255)
	constexpr auto MIDDLEATTACK_PARTICLE1_SCALE = 1.0;									//拡縮値(1.0がデフォルト)
	constexpr auto MIDDLEATTACK_PARTICLE1_ANGLE = 0.0;									//描画角度(3.14=180°)
	constexpr auto MIDDLEATTACK_PARTICLE1_CNT = 20;										//パーティクル1個あたりの生存時間
	constexpr auto MIDDLEATTACK_PARTICLE1_QTY = 10;										//1フレーム当たりのパーティクル数
	//パーティクル1個当たりの移動方向のランダム値調整
	constexpr auto MIDDLEATTACK_PARTICLE1_RANDOMX1 = 20;								//パーティクルのXランダム値
	constexpr auto MIDDLEATTACK_PARTICLE1_RANDOMX2 = 10.0;								//		〃
	constexpr auto MIDDLEATTACK_PARTICLE1_RANDOMX3 = 8.0;								//		〃
	constexpr auto MIDDLEATTACK_PARTICLE1_RANDOMY1 = 20;								//パーティクルのYランダム値
	constexpr auto MIDDLEATTACK_PARTICLE1_RANDOMY2 = 10.0;								//		〃
	constexpr auto MIDDLEATTACK_PARTICLE1_RANDOMY3 = 8.0;								//		〃

	/*----------中段攻撃2----------*/
	constexpr auto MIDDLEATTACK_PARTICLE2_GRAPH = "res/Particle/MiddleSibuki.png";	//画像ファイル名
	constexpr auto MIDDLEATTACK_PARTICLE2_POSITIONX = 0.0;								//基準点(足下)から描画点へのX座標差分
	constexpr auto MIDDLEATTACK_PARTICLE2_POSITIONY = -325.0;							//基準点(足下)から描画点へのY座標差分
	constexpr auto MIDDLEATTACK_PARTICLE2_BLENDMODE = DX_BLENDMODE_SUB;					//ブレンドモード設定
	constexpr auto MIDDLEATTACK_PARTICLE2_PAL = 128;									//ブレンド値(0～255)
	constexpr auto MIDDLEATTACK_PARTICLE2_RED = 200;									//赤色値(0～255)
	constexpr auto MIDDLEATTACK_PARTICLE2_GREEN = 200;									//緑色値(0～255)
	constexpr auto MIDDLEATTACK_PARTICLE2_BLUE = 200;									//青色値(0～255)
	constexpr auto MIDDLEATTACK_PARTICLE2_SCALE = 1.0;									//拡縮値(1.0がデフォルト)
	constexpr auto MIDDLEATTACK_PARTICLE2_ANGLE = 0.0;									//描画角度(3.14=180°)
	constexpr auto MIDDLEATTACK_PARTICLE2_CNT = 20;										//パーティクル1個あたりの生存時間
	constexpr auto MIDDLEATTACK_PARTICLE2_QTY = 5;										//1フレーム当たりのパーティクル数
	//パーティクル1個当たりの移動方向のランダム値調整
	constexpr auto MIDDLEATTACK_PARTICLE2_RANDOMX1 = 20;								//パーティクルのXランダム値
	constexpr auto MIDDLEATTACK_PARTICLE2_RANDOMX2 = 5.0;								//		〃
	constexpr auto MIDDLEATTACK_PARTICLE2_RANDOMX3 = 2.0;								//		〃
	constexpr auto MIDDLEATTACK_PARTICLE2_RANDOMY1 = 20;								//パーティクルのYランダム値
	constexpr auto MIDDLEATTACK_PARTICLE2_RANDOMY2 = 5.0;								//		〃
	constexpr auto MIDDLEATTACK_PARTICLE2_RANDOMY3 = 2.0;								//		〃
	/*----------下段攻撃1----------*/
	constexpr auto LOWATTACK_PARTICLE1_GRAPH = "res/Particle/LowAttack.png";			//画像ファイル名
	constexpr auto LOWATTACK_PARTICLE1_POSITIONX = 0.0;									//基準点(足下)から描画点へのX座標差分
	constexpr auto LOWATTACK_PARTICLE1_POSITIONY = -225.0;								//基準点(足下)から描画点へのY座標差分
	constexpr auto LOWATTACK_PARTICLE1_BLENDMODE = DX_BLENDMODE_SUB;					//ブレンドモード設定
	constexpr auto LOWATTACK_PARTICLE1_PAL = 64;										//ブレンド値(0～255)
	constexpr auto LOWATTACK_PARTICLE1_RED = 128;										//赤色値(0～255)
	constexpr auto LOWATTACK_PARTICLE1_GREEN = 128;										//緑色値(0～255)
	constexpr auto LOWATTACK_PARTICLE1_BLUE = 128;										//青色値(0～255)
	constexpr auto LOWATTACK_PARTICLE1_SCALE = 1.0;										//拡縮値(1.0がデフォルト)
	constexpr auto LOWATTACK_PARTICLE1_ANGLE = 0.0;										//描画角度(3.14=180°)
	constexpr auto LOWATTACK_PARTICLE1_CNT = 20;										//パーティクル1個あたりの生存時間
	constexpr auto LOWATTACK_PARTICLE1_QTY = 5;											//1フレーム当たりのパーティクル数
	//パーティクル1個当たりの移動方向のランダム値調整
	constexpr auto LOWATTACK_PARTICLE1_RANDOMX1 = 20;									//パーティクルのXランダム値
	constexpr auto LOWATTACK_PARTICLE1_RANDOMX2 = 10.0;									//		〃
	constexpr auto LOWATTACK_PARTICLE1_RANDOMX3 = 8.0;									//		〃
	constexpr auto LOWATTACK_PARTICLE1_RANDOMY1 = 20;									//パーティクルのYランダム値
	constexpr auto LOWATTACK_PARTICLE1_RANDOMY2 = 10.0;									//		〃
	constexpr auto LOWATTACK_PARTICLE1_RANDOMY3 = 8.0;									//		〃
	/*----------下段攻撃2----------*/
	constexpr auto LOWATTACK_PARTICLE2_GRAPH = "res/Particle/LowAttacksub.png";			//画像ファイル名
	constexpr auto LOWATTACK_PARTICLE2_POSITIONX = 0.0;									//基準点(足下)から描画点へのX座標差分
	constexpr auto LOWATTACK_PARTICLE2_POSITIONY = -225.0;								//基準点(足下)から描画点へのY座標差分
	constexpr auto LOWATTACK_PARTICLE2_BLENDMODE = DX_BLENDMODE_SUB;					//ブレンドモード設定
	constexpr auto LOWATTACK_PARTICLE2_PAL = 128;										//ブレンド値(0～255)
	constexpr auto LOWATTACK_PARTICLE2_RED = 200;										//赤色値(0～255)
	constexpr auto LOWATTACK_PARTICLE2_GREEN = 200;										//緑色値(0～255)
	constexpr auto LOWATTACK_PARTICLE2_BLUE = 200;										//青色値(0～255)
	constexpr auto LOWATTACK_PARTICLE2_SCALE = 1.0;										//拡縮値(1.0がデフォルト)
	constexpr auto LOWATTACK_PARTICLE2_ANGLE = 0.0;										//描画角度(3.14=180°)
	constexpr auto LOWATTACK_PARTICLE2_CNT = 20;										//パーティクル1個あたりの生存時間
	constexpr auto LOWATTACK_PARTICLE2_QTY = 5;											//1フレーム当たりのパーティクル数
	//パーティクル1個当たりの移動方向のランダム値調整
	constexpr auto LOWATTACK_PARTICLE2_RANDOMX1 = 20;									//パーティクルのXランダム値
	constexpr auto LOWATTACK_PARTICLE2_RANDOMX2 = 5.0;									//		〃
	constexpr auto LOWATTACK_PARTICLE2_RANDOMX3 = 2.0;									//		〃
	constexpr auto LOWATTACK_PARTICLE2_RANDOMY1 = 20;									//パーティクルのYランダム値
	constexpr auto LOWATTACK_PARTICLE2_RANDOMY2 = 5.0;									//		〃
	constexpr auto LOWATTACK_PARTICLE2_RANDOMY3 = 2.0;									//		〃

	/*----------居合1----------*/
	constexpr auto IAI_PARTICLE1_GRAPH = "res/Particle/Iai1.png";						//画像ファイル名
	constexpr auto IAI_PARTICLE1_POSITIONX = 0.0;										//基準点(足下)から描画点へのX座標差分
	constexpr auto IAI_PARTICLE1_POSITIONY = -225.0;									//基準点(足下)から描画点へのY座標差分
	constexpr auto IAI_PARTICLE1_BLENDMODE = DX_BLENDMODE_ADD;							//ブレンドモード設定
	constexpr auto IAI_PARTICLE1_PAL = 128;												//ブレンド値(0～255)
	constexpr auto IAI_PARTICLE1_RED = 80;												//赤色値(0～255)
	constexpr auto IAI_PARTICLE1_GREEN = 80;											//緑色値(0～255)
	constexpr auto IAI_PARTICLE1_BLUE = 60;												//青色値(0～255)
	constexpr auto IAI_PARTICLE1_SCALE = 0.8;											//拡縮値(1.0がデフォルト)
	constexpr auto IAI_PARTICLE1_ANGLE = 0.0;											//描画角度(3.14=180°)
	constexpr auto IAI_PARTICLE1_CNT = 20;												//パーティクル1個あたりの生存時間
	constexpr auto IAI_PARTICLE1_QTY = 5;												//1フレーム当たりのパーティクル数
	//パーティクル1個当たりの移動方向のランダム値調整
	constexpr auto IAI_PARTICLE1_RANDOMX1 = 20;											//パーティクルのXランダム値
	constexpr auto IAI_PARTICLE1_RANDOMX2 = 10.0;										//		〃
	constexpr auto IAI_PARTICLE1_RANDOMX3 = 8.0;										//		〃
	constexpr auto IAI_PARTICLE1_RANDOMY1 = 20;											//パーティクルのYランダム値
	constexpr auto IAI_PARTICLE1_RANDOMY2 = 10.00;										//		〃
	constexpr auto IAI_PARTICLE1_RANDOMY3 = 8.0;										//		〃

	/*----------居合2----------*/
	constexpr auto IAI_PARTICLE2_GRAPH = "res/Particle/Iai.png";						//画像ファイル名
	constexpr auto IAI_PARTICLE2_POSITIONX = 0.0;										//基準点(足下)から描画点へのX座標差分
	constexpr auto IAI_PARTICLE2_POSITIONY = -225.0;									//基準点(足下)から描画点へのY座標差分
	constexpr auto IAI_PARTICLE2_BLENDMODE = DX_BLENDMODE_SUB;							//ブンドモード設定
	constexpr auto IAI_PARTICLE2_PAL = 128;												//ブレンド値(0～255)
	constexpr auto IAI_PARTICLE2_RED = 64;												//赤色値(0～255)
	constexpr auto IAI_PARTICLE2_GREEN = 200;											//緑色値(0～255)
	constexpr auto IAI_PARTICLE2_BLUE = 64;												//青色値(0～255)
	constexpr auto IAI_PARTICLE2_SCALE = 1.0;											//拡縮値(1.0がデフォルト)
	constexpr auto IAI_PARTICLE2_ANGLE = 0.0;											//描画角度(3.14=180°)
	constexpr auto IAI_PARTICLE2_CNT = 20;												//パーティクル1個あたりの生存時間
	constexpr auto IAI_PARTICLE2_QTY = 5;												//1フレーム当たりのパーティクル数
	//パーティクル1個当たりの移動方向のランダム値調整
	constexpr auto IAI_PARTICLE2_RANDOMX1 = 20;											//パーティクルのXランダム値
	constexpr auto IAI_PARTICLE2_RANDOMX2 = 10.0;										//		〃
	constexpr auto IAI_PARTICLE2_RANDOMX3 = 8.0;										//		〃
	constexpr auto IAI_PARTICLE2_RANDOMY1 = 20;											//パーティクルのYランダム値
	constexpr auto IAI_PARTICLE2_RANDOMY2 = 10.0;										//		〃
	constexpr auto IAI_PARTICLE2_RANDOMY3 = 8.0;										//		〃

	/*----------居合3----------*/
	constexpr auto IAI_PARTICLE3_GRAPH = "res/Particle/Iai3.png";						//画像ファイル名
	constexpr auto IAI_PARTICLE3_POSITIONX = 0.0;										//基準点(足下)から描画点へのX座標差分
	constexpr auto IAI_PARTICLE3_POSITIONY = -225.0;									//基準点(足下)から描画点へのY座標差分
	constexpr auto IAI_PARTICLE3_BLENDMODE = DX_BLENDMODE_SUB;							//ブレンドモード設定
	constexpr auto IAI_PARTICLE3_PAL = 128;												//ブレンド値(0～255)
	constexpr auto IAI_PARTICLE3_RED = 200;												//赤色値(0～255)
	constexpr auto IAI_PARTICLE3_GREEN = 200;											//緑色値(0～255)
	constexpr auto IAI_PARTICLE3_BLUE = 200;											//青色値(0～255)
	constexpr auto IAI_PARTICLE3_SCALE = 1.0;											//拡縮値(1.0がデフォルト)
	constexpr auto IAI_PARTICLE3_ANGLE = 0.0;											//描画角度(3.14=180°)
	constexpr auto IAI_PARTICLE3_CNT = 20;												//パーティクル1個あたりの生存時間
	constexpr auto IAI_PARTICLE3_QTY = 5;												//1フレーム当たりのパーティクル数
	//パーティクル1個当たりの移動方向のランダム値調整
	constexpr auto IAI_PARTICLE3_RANDOMX1 = 20;											//パーティクルのXランダム値
	constexpr auto IAI_PARTICLE3_RANDOMX2 = 5.0;										//		〃
	constexpr auto IAI_PARTICLE3_RANDOMX3 = 2.0;										//		〃
	constexpr auto IAI_PARTICLE3_RANDOMY1 = 20;											//パーティクルのYランダム値
	constexpr auto IAI_PARTICLE3_RANDOMY2 = 5.0;										//		〃
	constexpr auto IAI_PARTICLE3_RANDOMY3 = 2.0;										//		〃

	/*----------居合ゲージ----------*/
	constexpr auto IAIG_PARTICLE_GRAPH = "res/Particle/IaiGaugeP.png";					//画像ファイル名
	constexpr auto IAIG_PARTICLE_POSITIONX = 0.0;									//基準点(足下)から描画点へのX座標差分
	constexpr auto IAIG_PARTICLE_POSITIONY = 0.0;										//基準点(足下)から描画点へのY座標差分
	constexpr auto IAIG_PARTICLE_BLENDMODE = DX_BLENDMODE_ADD;							//ブレンドモード設定
	constexpr auto IAIG_PARTICLE_PAL = 128;												//ブレンド値(0～255)
	constexpr auto IAIG_PARTICLE_RED = 230;												//赤色値(0～255)
	constexpr auto IAIG_PARTICLE_GREEN = 70;											//緑色値(0～255)
	constexpr auto IAIG_PARTICLE_BLUE = 5;												//青色値(0～255)
	constexpr auto IAIG_PARTICLE_SCALE = 1.0;											//拡縮値(1.0がデフォルト)
	constexpr auto IAIG_PARTICLE_ANGLE = 0.0;											//描画角度(3.14=180°)
	constexpr auto IAIG_PARTICLE_CNT = 10;												//パーティクル1個あたりの生存時間
	constexpr auto IAIG_PARTICLE_QTY = 5;												//1フレーム当たりのパーティクル数
	//パーティクル1個当たりの移動方向のランダム値調整
	constexpr auto IAIG_PARTICLE_RANDOMX1 = 10;											//パーティクルのXランダム値
	constexpr auto IAIG_PARTICLE_RANDOMX2 = 5.0;										//		〃
	constexpr auto IAIG_PARTICLE_RANDOMX3 = 4.0;										//		〃
	constexpr auto IAIG_PARTICLE_RANDOMY1 = 10;											//パーティクルのYランダム値
	constexpr auto IAIG_PARTICLE_RANDOMY2 = 5.0;										//		〃
	constexpr auto IAIG_PARTICLE_RANDOMY3 = 4.0;										//		〃
}