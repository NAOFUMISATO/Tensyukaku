#pragma once
#include "EnemyBase.h"
#include "ObjectBase.h"
#include <vector>
// 武士クラス

class Bushi : public EnemyBase {
public:
	Bushi(int x, int y, bool flip);
	~Bushi();
	virtual ENEMYTYPE	GetEneType() { return ENEMYTYPE::BUSHI; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;

private:
	void	Patrol(Game& g);		//巡回状態時の処理
	void	Coming(Game& g);		//追跡状態時の処理
	void	Attack(Game& g);		//攻撃状態時の処理
	void	Damage(Game& g);		//被ダメ状態時の処理
	void	Dead(Game& g);			//死亡状態時の処理
	void	LoadActionGraph();		//武士の画像読み込み関数
	void	LoadActionSE();			//武士のSE読み込み関数
	void	AnimeUpdate(Game& g);	//武士のアニメーション関数
	void	DebugDraw(Game& g);		//デバッグ用関数
};

namespace BInfo {
	/*----------武士の各座標関係----------*/
	constexpr auto GRAPHPOINT_X = 0;				//X位置から描画点までの差分
	constexpr auto GRAPHPOINT_Y = -210;			//Y位置から描画点までの差分
	constexpr auto POSITION_HITX = -30;			//描画点から当たり判定左上座標までの差分
	constexpr auto POSITION_HITY = -90;			//描画点から当たり判定左上座標までの差分
	constexpr auto COLLISION_WIDTH = 60;			//当たり判定横幅
	constexpr auto COLLISION_HEIGHT = 300;		//当たり判定縦幅

	/*----------各モーションの当たり判定関係----------*/
	constexpr auto PATROL_WIDTH = 500;			//索敵範囲当たり判定横幅
	constexpr auto PATROL_HEIGHT = 100;			//索敵範囲当たり判定縦幅
	constexpr auto COMING_WIDTH = 200;			//攻撃発生範囲当たり判定横幅
	constexpr auto COMING_HEIGHT = 100;			//攻撃発生範囲当たり判定縦幅
	constexpr auto ATTACK_WIDTH = 150;			//攻撃当たり判定横幅
	constexpr auto ATTACK_HEIGHT = 100;			//攻撃当たり判定縦幅

	/*----------パラメーター関係----------*/
	constexpr auto LIFE_MAX = 3;					//体力
	constexpr auto SPEED = 2;					//移動速度
	
	/*----------画像読み込み&アニメーション&判定フレーム関係----------*/
	//共通
	constexpr auto GRAPH_WIDTH = 540;			//1枚当たりの画像サイズ（横）
	constexpr auto GRAPH_HEIGHT = 420;			//1枚当たりの画像サイズ（縦）
	constexpr auto GRAPH_SCALE = 1.0;			//拡大率
	constexpr auto GRAPH_ANGLE = 0;				//角度
	//巡回
	constexpr auto PATROL_GRAPHNAME = "res/Bushi/B_Stand.png";	//画像ファイル名
	constexpr auto PATROL_ANIMEMAX = 1;			//全ての画像枚数
	constexpr auto PATROL_WIDTHCOUNT = 1;		//横の画像枚数
	constexpr auto PATROL_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_PATROL = 5;		//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto PATROL_FRAME = 180;			//巡回全フレーム
	//移動
	constexpr auto COMING_GRAPHNAME = "res/Bushi/B_Walk.png";	//画像ファイル名
	constexpr auto COMING_ANIMEMAX = 4;			//全ての画像枚数
	constexpr auto COMING_WIDTHCOUNT = 4;		//横の画像枚数
	constexpr auto COMING_HEIGHTCOUNT = 1;		//縦の画像枚数	
	constexpr auto ANIMESPEED_COMING = 30;		//アニメスピード（何フレームごとに画像を切り替えるか）
	//攻撃
	constexpr auto ATTACK_GRAPHNAME = "res/Bushi/B_Attack.png";	//画像ファイル名
	constexpr auto ATTACK_ANIMEMAX = 3;			//全ての画像枚数
	constexpr auto ATTACK_WIDTHCOUNT = 3;		//横の画像枚数
	constexpr auto ATTACK_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_ATTACK = 15;		//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto ATTACK_ALLFRAME = 40;		//攻撃全フレーム
	constexpr auto ATTACK_BEGINFRAME = 15;		//攻撃判定発生フレーム
	constexpr auto ATTACK_ENDFRAME = 15;		//攻撃判定終了フレーム
	//被ダメ
	constexpr auto DAMAGE_GRAPHNAME = "res/Bushi/B_Damage.png";	//画像ファイル名
	constexpr auto DAMAGE_ANIMEMAX = 3;			//全ての画像枚数
	constexpr auto DAMAGE_WIDTHCOUNT = 3;		//横の画像枚数
	constexpr auto DAMAGE_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_DAMAGE = 15;		//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto DAMAGE_ALLFRAME = 44;		//被ダメ全フレーム
	//死亡
	constexpr auto DEAD_GRAPHNAME = "res/Bushi/B_Dead.png";		//画像ファイル名
	constexpr auto DEAD_ANIMEMAX = 1;			//全ての画像枚数
	constexpr auto DEAD_WIDTHCOUNT = 1;			//横の画像枚数
	constexpr auto DEAD_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_DEAD = 60;		//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto DEAD_ALLFRAME = 50;			//死亡全フレーム
	/*----------SE関係----------*/
	constexpr auto WALK_SE = "se/Footstep.wav";			//巡回
	constexpr auto ATTACK_SE = "se/slash3.wav";			//攻撃	

}