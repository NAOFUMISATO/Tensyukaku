#pragma once
#include "EnemyBase.h"
/*
	盾兵
*/
class Shielder :public EnemyBase {
public:
	Shielder(int x, int y, bool flip);
	~Shielder();
	virtual ENEMYTYPE	GetEneType() { return ENEMYTYPE::SHIELDER; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;
private:
	void	Appear(Game& g);		//出現状態時の処理
	void	Patrol(Game& g);		//巡回状態時の処理
	void	Coming(Game& g);		//追跡状態時の処理
	void	Attack(Game& g);		//攻撃状態時の処理
	void	GuardAttack(Game& g);	//盾持ち攻撃状態時の処理
	void	GuardBreak(Game& g);	//盾崩し状態時の処理
	void	Dead(Game& g);			//死亡状態時の処理
	void	ShieldDraw(Game& g);	//盾の描画関数
	void	LoadActionGraph();		//忍者の画像読み込み関数
	void	LoadActionSE();			//忍者のSE読み込み関数
	void	DebugDraw(Game& g);		//デバッグ用関数

	/*---------メンバ変数---------*/
	bool	_Shield_Flag;		//盾の生存フラグ
	int		_Shield_Cnt;		//盾用の動作カウンタ保存変数
};

namespace SInfo {
	/*----------盾兵の各座標関係----------*/
	constexpr auto GRAPHPOINT_X = 0;			//X位置から描画点までの差分
	constexpr auto GRAPHPOINT_Y = -315;			//Y位置から描画点までの差分
	constexpr auto POSITION_HITX = -45;			//描画点から当たり判定左上座標までの差分
	constexpr auto POSITION_HITY = -135;		//描画点から当たり判定左上座標までの差分
	constexpr auto COLLISION_WIDTH = 90;		//当たり判定横幅
	constexpr auto COLLISION_HEIGHT = 450;		//当たり判定縦幅
	
	/*----------各モーションの当たり判定関係----------*/
	constexpr auto PATROL_WIDTH = 500;			//索敵範囲当たり判定横幅
	constexpr auto PATROL_HEIGHT = 100;			//索敵範囲当たり判定縦幅
	constexpr auto COMING_WIDTH = 250;			//攻撃発生範囲当たり判定横幅
	constexpr auto COMING_HEIGHT = 100;			//攻撃発生範囲当たり判定縦幅
	constexpr auto ATTACK_WIDTH = 250;			//攻撃当たり判定横幅
	constexpr auto ATTACK_HEIGHT = 150;			//攻撃当たり判定縦幅
	constexpr auto COMINGCANCEL_WIDTH = 1000;	//追跡中止当たり判定横幅
	constexpr auto COMINGCANCEL_HEIGHT = 100;	//追跡中止当たり判定縦幅
	constexpr auto ATTACKCANCEL_WIDTH = 250;	//攻撃中止当たり判定横幅
	constexpr auto ATTACKCANCEL_HEIGHT = 100;	//攻撃中止当たり判定縦幅

	/*----------パラメーター関係----------*/
	constexpr auto LIFE_MAX = 1;				//体力
	constexpr auto SPEED = 1;					//移動速度

	/*----------画像読み込み&アニメーション&判定フレーム関係----------*/
	//共通
	constexpr auto GRAPH_WIDTH = 840;			//1枚当たりの画像サイズ（横）
	constexpr auto GRAPH_HEIGHT = 630;			//1枚当たりの画像サイズ（縦）
	constexpr auto GRAPH_SCALE = 1.0;			//拡大率
	constexpr auto GRAPH_ANGLE = 0;				//角度
	//出現
	constexpr auto APPEAR_GRAPHNAME = "res/Shielder/T_Stand.png";	//画像ファイル名
	constexpr auto APPEAR_ANIMEMAX = 1;			//全ての画像枚数
	constexpr auto APPEAR_WIDTHCOUNT = 1;		//横の画像枚数
	constexpr auto APPEAR_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_APPEAR = 60;		//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto FADEIN_SPEED = 4;			//アッパー時のフェードインスピード
	constexpr auto APPEAR_ALLFRAME = 60;		//出現全フレーム
	//巡回
	constexpr auto PATROL_GARAPHNAME = "res/Shielder/T_Stand.png";	//画像ファイル名
	constexpr auto PATROL_ANIMEMAX = 1;			//全ての画像枚数
	constexpr auto PATROL_WIDTHCOUNT = 1;		//横の画像枚数
	constexpr auto PATROL_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_PATROL = 5;		//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto PATROL_TURNFRAME = 180;		//巡回の振り向きフレーム
	//追跡
	constexpr auto COMING_GRAPHNAME = "res/Shielder/T_Walk.png";	//画像ファイル名
	constexpr auto COMING_ANIMEMAX = 4;			//全ての画像枚数
	constexpr auto COMING_WIDTHCOUNT = 4;		//横の画像枚数
	constexpr auto COMING_HEIGHTCOUNT = 1;		//縦の画像枚数	
	constexpr auto ANIMESPEED_COMING = 30;		//アニメスピード（何フレームごとに画像を切り替えるか）
	//攻撃
	constexpr auto ATTACK_GRAPHNAME = "res/Shielder/T_Attack.png";	//画像ファイル名
	constexpr auto ATTACK_ANIMEMAX = 4;			//全ての画像枚数
	constexpr auto ATTACK_WIDTHCOUNT = 4;		//横の画像枚数
	constexpr auto ATTACK_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_ATTACK = 20;		//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto ATTACK_ANIMEFRAME = ATTACK_ANIMEMAX * ANIMESPEED_ATTACK;		//アニメーションフレーム（全ての画像枚数×アニメスピード）
	constexpr auto ATTACK_ALLFRAME = 100;		//攻撃全フレーム（全フレーム-アニメーションフレーム＝攻撃猶予時間）
	constexpr auto ATTACK_BEGINFRAME = 20;		//攻撃判定発生フレーム
	constexpr auto ATTACK_ENDFRAME = 40;		//攻撃判定終了フレーム
	//盾持ち攻撃
	constexpr auto GUARDATTACK_GRAPHNAME = "res/Shielder/T_GuardAttack.png";	//画像ファイル名
	constexpr auto GUARDATTACK_ANIMEMAX = 4;		//全ての画像枚数
	constexpr auto GUARDATTACK_WIDTHCOUNT = 4;		//横の画像枚数
	constexpr auto GUARDATTACK_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_GUARDATTACK = 20;		//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto GUARDATTACK_ANIMEFRAME = GUARDATTACK_ANIMEMAX * ANIMESPEED_GUARDATTACK;//アニメーションフレーム（全ての画像枚数×アニメスピード）
	constexpr auto GUARDATTACK_ALLFRAME = 100;		//攻撃全フレーム（全フレーム-アニメーションフレーム＝攻撃猶予時間）
	constexpr auto GUARDATTACK_BEGINFRAME = 20;		//攻撃判定発生フレーム
	constexpr auto GUARDATTACK_ENDFRAME = 40;		//攻撃判定終了フレーム
	//盾崩し
	constexpr auto GUARDBREAK_GRAPHNAME = "res/Shielder/T_Damage.png";	//画像ファイル名
	constexpr auto GUARDBREAK_ANIMEMAX = 3;		//全ての画像枚数
	constexpr auto GUARDBREAK_WIDTHCOUNT = 3;	//横の画像枚数
	constexpr auto GUARDBREAK_HEIGHTCOUNT = 1;	//縦の画像枚数
	constexpr auto ANIMESPEED_GUARDBREAK = 15;	//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto GUARDBREAK_ANIMEFRAME = GUARDBREAK_ANIMEMAX * ANIMESPEED_GUARDBREAK;	//アニメーションフレーム（全ての画像枚数×アニメスピード）
	constexpr auto GUARDBREAK_ALLFRAME = 55;	//被ダメ全フレーム
	//死亡
	constexpr auto DEAD_GRAPHNAME = "res/Shielder/T_Dead.png";		//画像ファイル名
	constexpr auto DEAD_ANIMEMAX = 3;			//全ての画像枚数
	constexpr auto DEAD_WIDTHCOUNT = 3;			//横の画像枚数
	constexpr auto DEAD_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_DEAD = 20;		//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto DEAD_ANIMEFRAME = DEAD_ANIMEMAX * ANIMESPEED_DEAD;		//アニメーションフレーム（全ての画像枚数×アニメスピード）
	constexpr auto DEAD_ALLFRAME = 120;			//死亡全フレーム
	constexpr auto FADEOUT_SPEED = 4;			//フェードアウトスピード
	
	/*----------盾の座標関係----------*/
	constexpr auto SHIELD_WIDTH = 840;			//盾の横幅
	constexpr auto SHIELD_HEIGHT = 630;			//盾の縦幅
	constexpr auto SHIELD_GRAPH_POINTX = 0;		//X位置から描画点までの差分
	constexpr auto SHIELD_GRAPH_POINTY = -120;	//Y位置から描画点までの差分

	/*----------盾の挙動関係----------*/
	constexpr auto SHIELD_ANGLE = -0.0;
	constexpr auto SHIELD_DIFFPOINTX = -0;
	constexpr auto SHIELD_DIFFPOINTY = -180;
	constexpr auto SHIELD_ALPHA = 255;
	constexpr auto SHIELD_ANGLECHANGE = 0.03;
	constexpr auto SHIELD_ALPHACHANGE = 5;
	constexpr auto SHIELD_XCHANGE = 1;
	constexpr auto SHIELD_YCHANGE = 5;

	/*----------SE関係----------*/
	constexpr auto WALK_SE = "se/Footstep.wav";			//巡回
	constexpr auto ATTACK_SE = "se/slash3.wav";			//攻撃	

};