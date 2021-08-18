#pragma once
#include "ObjectBase.h"
#include <tuple>
#include <utility>
class Game;
class ParticleBase :public ObjectBase {
public:
	ParticleBase();
	~ParticleBase();
	virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::PARTICLE; }

	enum class PARTICLETYPE {
		LOWATTACK1, LOWATTACK2,MIDDLEATTACK1,MIDDLEATTACK2
	};
	virtual PARTICLETYPE GetParType() = 0;
	virtual void Init();
	virtual void Process(Game& g);
	virtual void Draw(Game& g);
protected:
	std::pair<double, double> _xy;
	std::pair<double, double> _dxy;
	std::pair<double, double> _mxy;
	int	_a;
	int _bm;
	std::tuple<int, int, int> _rgb;
	std::pair<double, double> _drg;
};

namespace ParInfo {
	/*----------下段攻撃1----------*/
	constexpr auto LowAttackPar1_Graph = "res/Particle/LowAttack.png";			//画像ファイル名
	constexpr auto LowAttackPar1_PozX = 0.0;									//基準点(足下)から描画点へのX座標差分
	constexpr auto LowAttackPar1_PozY = -150.0;									//基準点(足下)から描画点へのX座標差分
	constexpr auto LowAttackPar1_BLENDMODE = DX_BLENDMODE_SUB;					//ブレンドモード設定
	constexpr auto LowAttackPar1_Pal = 64;										//ブレンド値(0～255)
	constexpr auto LowAttackPar1_Red = 128;										//赤色値(0～255)
	constexpr auto LowAttackPar1_Green = 128;									//緑色値(0～255)
	constexpr auto LowAttackPar1_Blue = 128;									//青色値(0～255)
	constexpr auto LowAttackPar1_Scale = 1.0;									//拡縮値(1.0がデフォルト)
	constexpr auto LowAttackPar1_Angle = 0.0;									//描画角度(3.14=180°)
	constexpr auto LowAttackPar1_Cnt = 20;										//パーティクル1個あたりの生存時間
	constexpr auto LAP1_Xrand1 = 20;											//パーティクルのXランダム値
	constexpr auto LAP1_Xrand2 = 10.0;											//		〃
	constexpr auto LAP1_Xrand3 = 8.0;											//		〃
	constexpr auto LAP1_Yrand1 = 20;											//パーティクルのYランダム値
	constexpr auto LAP1_Yrand2 = 10.0;											//		〃
	constexpr auto LAP1_Yrand3 = 8.0;											//		〃

	/*----------下段攻撃2----------*/
	constexpr auto LowAttackPar2_Graph = "res/Particle/LowAttacksub.png";		//画像ファイル名
	constexpr auto LowAttackPar2_PozX = 0.0;									//基準点(足下)から描画点へのX座標差分
	constexpr auto LowAttackPar2_PozY = -150.0;									//基準点(足下)から描画点へのX座標差分
	constexpr auto LowAttackPar2_BLENDMODE = DX_BLENDMODE_SUB;					//ブレンドモード設定
	constexpr auto LowAttackPar2_Pal = 128;										//ブレンド値(0～255)
	constexpr auto LowAttackPar2_Red = 200;										//赤色値(0～255)
	constexpr auto LowAttackPar2_Green = 200;									//緑色値(0～255)
	constexpr auto LowAttackPar2_Blue = 200;									//青色値(0～255)
	constexpr auto LowAttackPar2_Scale = 1.0;									//拡縮値(1.0がデフォルト)
	constexpr auto LowAttackPar2_Angle = 0.0;									//描画角度(3.14=180°)
	constexpr auto LowAttackPar2_Cnt = 20;										//パーティクル1個あたりの生存時間
	constexpr auto LAP2_Xrand1 = 20;											//パーティクルのXランダム値
	constexpr auto LAP2_Xrand2 = 5.0;											//		〃
	constexpr auto LAP2_Xrand3 = 2.0;											//		〃
	constexpr auto LAP2_Yrand1 = 20;											//パーティクルのYランダム値
	constexpr auto LAP2_Yrand2 = 5.0;											//		〃
	constexpr auto LAP2_Yrand3 = 2.0;											//		〃

	/*----------中段攻撃1----------*/
	constexpr auto MiddleAttackPar1_Graph = "res/Particle/MiddleAttack.png";	//画像ファイル名
	constexpr auto MiddleAttackPar1_PozX = 0.0;									//基準点(足下)から描画点へのX座標差分
	constexpr auto MiddleAttackPar1_PozY = -150.0;								//基準点(足下)から描画点へのX座標差分
	constexpr auto MiddleAttackPar1_BLENDMODE = DX_BLENDMODE_SUB;				//ブレンドモード設定
	constexpr auto MiddleAttackPar1_Pal = 64;									//ブレンド値(0～255)
	constexpr auto MiddleAttackPar1_Red = 128;									//赤色値(0～255)
	constexpr auto MiddleAttackPar1_Green = 128;								//緑色値(0～255)
	constexpr auto MiddleAttackPar1_Blue = 128;									//青色値(0～255)
	constexpr auto MiddleAttackPar1_Scale = 1.0;								//拡縮値(1.0がデフォルト)
	constexpr auto MiddleAttackPar1_Angle = 0.0;								//描画角度(3.14=180°)
	constexpr auto MiddleAttackPar1_Cnt = 20;									//パーティクル1個あたりの生存時間
	constexpr auto MAP1_Xrand1 = 20;											//パーティクルのXランダム値
	constexpr auto MAP1_Xrand2 = 10.0;											//		〃
	constexpr auto MAP1_Xrand3 = 8.0;											//		〃
	constexpr auto MAP1_Yrand1 = 20;											//パーティクルのYランダム値
	constexpr auto MAP1_Yrand2 = 10.0;											//		〃
	constexpr auto MAP1_Yrand3 = 8.0;											//		〃

	/*----------中段攻撃2----------*/
	constexpr auto MiddleAttackPar2_Graph = "res/Particle/MiddleAttacksub.png";	//画像ファイル名
	constexpr auto MiddleAttackPar2_PozX = 0.0;									//基準点(足下)から描画点へのX座標差分
	constexpr auto MiddleAttackPar2_PozY = -150.0;								//基準点(足下)から描画点へのX座標差分
	constexpr auto MiddleAttackPar2_BLENDMODE = DX_BLENDMODE_SUB;				//ブレンドモード設定
	constexpr auto MiddleAttackPar2_Pal = 128;									//ブレンド値(0～255)
	constexpr auto MiddleAttackPar2_Red = 200;									//赤色値(0～255)
	constexpr auto MiddleAttackPar2_Green = 200;								//緑色値(0～255)
	constexpr auto MiddleAttackPar2_Blue = 200;									//青色値(0～255)
	constexpr auto MiddleAttackPar2_Scale = 1.0;								//拡縮値(1.0がデフォルト)
	constexpr auto MiddleAttackPar2_Angle = 0.0;								//描画角度(3.14=180°)
	constexpr auto MiddleAttackPar2_Cnt = 20;									//パーティクル1個あたりの生存時間
	constexpr auto MAP2_Xrand1 = 20;											//パーティクルのXランダム値
	constexpr auto MAP2_Xrand2 = 5.0;											//		〃
	constexpr auto MAP2_Xrand3 = 2.0;											//		〃
	constexpr auto MAP2_Yrand1 = 20;											//パーティクルのYランダム値
	constexpr auto MAP2_Yrand2 = 5.0;											//		〃
	constexpr auto MAP2_Yrand3 = 2.0;											//		〃
	/*----------Tuple型可読性向上---------*/
	constexpr auto Red = 0;
	constexpr auto Green = 1;
	constexpr auto Blue = 2;
	constexpr auto Scale = 0;
	constexpr auto Angle = 1;
	constexpr auto Flip = 2;
}