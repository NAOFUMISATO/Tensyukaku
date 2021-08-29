#pragma once
#include "EnemyBase.h"
#include <vector>
// 忍者クラス

class Ninja : public EnemyBase {
public:
	Ninja(int x, int y, bool flip);
	~Ninja();
	virtual ENEMYTYPE	GetEneType() { return ENEMYTYPE::NINJA; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;

private:
	void	Patrol(Game& g);		//巡回状態時の処理
	void	Coming(Game& g);		//追跡状態時の処理
	void	Attack(Game& g);		//攻撃状態時の処理
	void	Dead(Game& g);			//死亡状態時の処理
	void	LoadActionGraph();		//忍者の画像読み込み関数
	void	LoadActionSE();			//忍者のSE読み込み関数
	void	AnimeUpdate(Game& g);	//忍者のアニメーション関数
	void	DebugDraw(Game& g);		//デバッグ用関数
};
namespace NInfo {
	/*----------忍者の各座標関係----------*/
	constexpr auto GRAPHPOINT_X = 0;				//X位置から描画点までの差分
	constexpr auto GRAPHPOINT_Y = -315;			//Y位置から描画点までの差分
	constexpr auto POSITION_HITX = -60;			//描画点から当たり判定左上座標までの差分
	constexpr auto POSITION_HITY = 105;			//描画点から当たり判定左上座標までの差分
	constexpr auto COLLISION_WIDTH = 120;			//当たり判定横幅
	constexpr auto COLLISION_HEIGHT = 210;		//当たり判定縦幅

	/*----------各モーションの当たり判定関係----------*/
	constexpr auto PATROL_WIDTH = 1000;			//索敵範囲当たり判定横幅
	constexpr auto PATROL_HEIGHT = 100;			//索敵範囲当たり判定縦幅
	constexpr auto COMING_WIDTH = 150;			//攻撃発生範囲当たり判定横幅
	constexpr auto COMING_HEIGHT = 100;			//攻撃発生範囲当たり判定縦幅
	constexpr auto ATTACK_WIDTH = 150;			//攻撃当たり判定横幅
	constexpr auto ATTACK_HEIGHT = 150;			//攻撃当たり判定縦幅
	constexpr auto COMINGCANCEL_WIDTH = 1000;	//追跡中止当たり判定横幅
	constexpr auto COMINGCANCEL_HEIGHT = 100;	//追跡中止当たり判定縦幅
	constexpr auto ATTACKCANCEL_WIDTH = 150;	//攻撃中止当たり判定横幅
	constexpr auto ATTACKCANCEL_HEIGHT = 100;	//攻撃中止当たり判定縦幅

	/*----------パラメーター関係----------*/
	constexpr auto LIFE_MAX = 1;				//体力
	constexpr auto SPPED = 3;					//移動速度

	/*----------画像読み込み&アニメーション&判定フレーム関係----------*/
	//共通
	constexpr auto GRAPH_WIDTH = 630;			//1枚当たりの画像サイズ（横）
	constexpr auto GRAPH_HEIGHT = 630;			//1枚当たりの画像サイズ（縦）
	constexpr auto GRAPH_SCALE = 1.0;			//拡大率
	constexpr auto GRAPH_ANGLE = 0;				//角度
	//待機
	constexpr auto PATROL_GRAPHNAME = "res/Ninja/N_Stand.png";	//画像ファイル名
	constexpr auto PATROL_ANIMEMAX = 1;			//全ての画像枚数
	constexpr auto PATROL_WIDTHCOUNT = 1;		//横の画像枚数
	constexpr auto PATROL_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_PATROL = 5;		//各状態アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto PATROL_ALLFRAME = 120;		//巡回全フレーム
	//移動
	constexpr auto COMING_GRAPHNAME = "res/Ninja/N_Walk.png";	//画像ファイル名
	constexpr auto COMING_ANIMEMAX = 4;			//全ての画像枚数
	constexpr auto COMING_WIDTHCOUNT = 4;		//横の画像枚数
	constexpr auto COMING_HEIGHTCOUNT = 1;		//縦の画像枚数	
	constexpr auto ANIMESPEED_COMING = 10;		//各状態アニメスピード（何フレームごとに画像を切り替えるか）
	//攻撃
	constexpr auto ATTACK_GRAPHNAME = "res/Ninja/N_Attack.png";	//画像ファイル名
	constexpr auto ATTACK_ANIMEMAX =4;			//全ての画像枚数
	constexpr auto ATTACK_WIDTHCOUNT = 4;		//横の画像枚数
	constexpr auto ATTACK_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_ATTACK = 10;		//各状態アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto ATTACK_ANIMEFRAME = ATTACK_ANIMEMAX * ANIMESPEED_ATTACK;		//アニメーションフレーム（全ての画像枚数×アニメスピード）
	constexpr auto ATTACK_ALLFRAME = 50;		//攻撃全フレーム（全フレーム-アニメーションフレーム＝攻撃猶予時間）
	constexpr auto ATTACK_BEGINFRAME = 15;		//攻撃判定発生フレーム
	constexpr auto ATTACK_ENDFRAME = 30;		//攻撃判定終了フレーム
	//死亡
	constexpr auto DEAD_GRAPHNAME = "res/Ninja/N_Dead.png";		//画像ファイル名
	constexpr auto DEAD_ANIMEMAX = 3;			//全ての画像枚数
	constexpr auto DEAD_WIDTHCOUNT = 3;			//横の画像枚数
	constexpr auto DEAD_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_DEAD = 20;		//各状態アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto DEAD_FRAME = 55;				//死亡全フレーム
	/*----------SE関係----------*/
	constexpr auto WALK_SE = "se/Footstep.wav";			//巡回
	constexpr auto ATTACK_SE = "se/slash3.wav";			//攻撃
}