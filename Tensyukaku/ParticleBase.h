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
		LOWATTACK1, LOWATTACK2,MIDDLEATTACK1,MIDDLEATTACK2,IAI1,IAI2,IAI3
	};
	virtual PARTICLETYPE GetParType() = 0;
	virtual void Init();
	virtual void Process(Game& g);
	virtual void Draw(Game& g);
protected:
	std::pair<double, double> _xy;
	std::pair<double, double> _dxy;
	std::pair<double, double> _mxy;
	int	_pal;
	int _bm;
	std::tuple<int, int, int> _rgb;
	std::pair<double, double> _drg;
};

namespace ParInfo {
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
	constexpr auto MiddleAttackPar1_qty = 5;									//1フレーム当たりのパーティクル数
	//パーティクル1個当たりの移動方向のランダム値調整
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
	constexpr auto MiddleAttackPar2_qty = 5;									//1フレーム当たりのパーティクル数
	//パーティクル1個当たりの移動方向のランダム値調整
	constexpr auto MAP2_Xrand1 = 20;											//パーティクルのXランダム値
	constexpr auto MAP2_Xrand2 = 5.0;											//		〃
	constexpr auto MAP2_Xrand3 = 2.0;											//		〃
	constexpr auto MAP2_Yrand1 = 20;											//パーティクルのYランダム値
	constexpr auto MAP2_Yrand2 = 5.0;											//		〃
	constexpr auto MAP2_Yrand3 = 2.0;											//		〃

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
	constexpr auto LowAttackPar1_qty = 5;										//1フレーム当たりのパーティクル数
	//パーティクル1個当たりの移動方向のランダム値調整
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
	constexpr auto LowAttackPar2_qty = 5;										//1フレーム当たりのパーティクル数
	//パーティクル1個当たりの移動方向のランダム値調整
	constexpr auto LAP2_Xrand1 = 20;											//パーティクルのXランダム値
	constexpr auto LAP2_Xrand2 = 5.0;											//		〃
	constexpr auto LAP2_Xrand3 = 2.0;											//		〃
	constexpr auto LAP2_Yrand1 = 20;											//パーティクルのYランダム値
	constexpr auto LAP2_Yrand2 = 5.0;											//		〃
	constexpr auto LAP2_Yrand3 = 2.0;											//		〃

	/*----------居合1----------*/
	constexpr auto IaiPar1_Graph = "res/Particle/Iai1.png";						//画像ファイル名
	constexpr auto IaiPar1_PozX = 0.0;											//基準点(足下)から描画点へのX座標差分
	constexpr auto IaiPar1_PozY = -150.0;										//基準点(足下)から描画点へのX座標差分
	constexpr auto IaiPar1_BLENDMODE = DX_BLENDMODE_ADD;						//ブレンドモード設定
	constexpr auto IaiPar1_Pal = 128;											//ブレンド値(0～255)
	constexpr auto IaiPar1_Red = 80;											//赤色値(0～255)
	constexpr auto IaiPar1_Green = 80;											//緑色値(0～255)
	constexpr auto IaiPar1_Blue =60;											//青色値(0～255)
	constexpr auto IaiPar1_Scale = 0.8;											//拡縮値(1.0がデフォルト)
	constexpr auto IaiPar1_Angle = 0.0;											//描画角度(3.14=180°)
	constexpr auto IaiPar1_Cnt = 20;											//パーティクル1個あたりの生存時間
	constexpr auto Iai1_qty = 5;												//1フレーム当たりのパーティクル数
	//パーティクル1個当たりの移動方向のランダム値調整
	constexpr auto IAI1_Xrand1 = 20;											//パーティクルのXランダム値
	constexpr auto IAI1_Xrand2 = 10.0;											//		〃
	constexpr auto IAI1_Xrand3 = 8.0;											//		〃
	constexpr auto IAI1_Yrand1 = 20;											//パーティクルのYランダム値
	constexpr auto IAI1_Yrand2 = 10.0;											//		〃
	constexpr auto IAI1_Yrand3 = 8.0;											//		〃

	/*----------居合2----------*/
	constexpr auto IaiPar2_Graph = "res/Particle/Iai2.png";						//画像ファイル名
	constexpr auto IaiPar2_PozX = 0.0;											//基準点(足下)から描画点へのX座標差分
	constexpr auto IaiPar2_PozY = -150.0;										//基準点(足下)から描画点へのX座標差分
	constexpr auto IaiPar2_BLENDMODE = DX_BLENDMODE_SUB;						//ブレンドモード設定
	constexpr auto IaiPar2_Pal = 128;											//ブレンド値(0～255)
	constexpr auto IaiPar2_Red = 64;											//赤色値(0～255)
	constexpr auto IaiPar2_Green = 200;											//緑色値(0～255)
	constexpr auto IaiPar2_Blue = 64;											//青色値(0～255)
	constexpr auto IaiPar2_Scale = 1.0;											//拡縮値(1.0がデフォルト)
	constexpr auto IaiPar2_Angle = 0.0;											//描画角度(3.14=180°)
	constexpr auto IaiPar2_Cnt = 20;											//パーティクル1個あたりの生存時間
	constexpr auto Iai2_qty = 5;												//1フレーム当たりのパーティクル数
	//パーティクル1個当たりの移動方向のランダム値調整
	constexpr auto IAI2_Xrand1 = 20;											//パーティクルのXランダム値
	constexpr auto IAI2_Xrand2 = 10.0;											//		〃
	constexpr auto IAI2_Xrand3 = 8.0;											//		〃
	constexpr auto IAI2_Yrand1 = 20;											//パーティクルのYランダム値
	constexpr auto IAI2_Yrand2 = 10.0;											//		〃
	constexpr auto IAI2_Yrand3 = 8.0;											//		〃

	/*----------居合3----------*/
	constexpr auto IaiPar3_Graph = "res/Particle/Iai3.png";						//画像ファイル名
	constexpr auto IaiPar3_PozX = 0.0;											//基準点(足下)から描画点へのX座標差分
	constexpr auto IaiPar3_PozY = -150.0;										//基準点(足下)から描画点へのX座標差分
	constexpr auto IaiPar3_BLENDMODE = DX_BLENDMODE_SUB;						//ブレンドモード設定
	constexpr auto IaiPar3_Pal = 128;											//ブレンド値(0～255)
	constexpr auto IaiPar3_Red = 200;											//赤色値(0～255)
	constexpr auto IaiPar3_Green = 200;											//緑色値(0～255)
	constexpr auto IaiPar3_Blue = 200;											//青色値(0～255)
	constexpr auto IaiPar3_Scale = 1.0;											//拡縮値(1.0がデフォルト)
	constexpr auto IaiPar3_Angle = 0.0;											//描画角度(3.14=180°)
	constexpr auto IaiPar3_Cnt = 20;											//パーティクル1個あたりの生存時間
	constexpr auto Iai3_qty = 5;												//1フレーム当たりのパーティクル数
	//パーティクル1個当たりの移動方向のランダム値調整
	constexpr auto IAI3_Xrand1 = 20;											//パーティクルのXランダム値
	constexpr auto IAI3_Xrand2 = 5.0;											//		〃
	constexpr auto IAI3_Xrand3 = 2.0;											//		〃
	constexpr auto IAI3_Yrand1 = 20;											//パーティクルのYランダム値
	constexpr auto IAI3_Yrand2 = 5.0;											//		〃
	constexpr auto IAI3_Yrand3 = 2.0;											//		〃
	
	/*----------Tuple型可読性向上---------*/
	constexpr auto Red = 0;
	constexpr auto Green = 1;
	constexpr auto Blue = 2;
	constexpr auto Scale = 0;
	constexpr auto Angle = 1;
	constexpr auto Flip = 2;
}