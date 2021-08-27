#pragma once
#include "EnemyBase.h"

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
	void	Patrol(Game& g);		//巡回状態時の処理
	void	Coming(Game& g);		//追跡状態時の処理
	void	Attack(Game& g);		//攻撃状態時の処理
	void	GuardBreak(Game& g);	//盾崩し状態時の処理
	void	Dead(Game& g);			//死亡状態時の処理
	void	ShieldDraw(Game& g);	//盾の描画関数
	void	LoadActionGraph();		//忍者の画像読み込み関数
	void	LoadActionSE();			//忍者のSE読み込み関数
	void	AnimeUpdate(Game& g);	//忍者のアニメーション関数
	void	DebugDraw(Game& g);		//デバッグ用関数

	bool	_Shield_Flag;		//盾の生存フラグ
	int		_Shield_Cnt;		
};

namespace SInfo {
	/*----------盾兵の各座標関係----------*/
	constexpr auto GRAPHPOINT_X = 0;				//X位置から描画点までの差分
	constexpr auto GRAPHPOINT_Y = -315;			//Y位置から描画点までの差分
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
	constexpr auto LIFE_MAX = 1;				//体力
	constexpr auto SPEED = 1;					//移動速度

	/*----------画像読み込み&アニメーション&判定フレーム関係----------*/
	//共通
	constexpr auto GRAPH_WIDTH = 840;			//1枚当たりの画像サイズ（横）
	constexpr auto GRAPH_HEIGHT = 630;			//1枚当たりの画像サイズ（縦）
	constexpr auto GRAPH_SCALE = 1.0;			//拡大率
	constexpr auto GRAPH_ANGLE = 0;				//角度
	//巡回
	constexpr auto PATROL_GARAPHNAME = "res/Shielder/T_Stand.png";	//画像ファイル名
	constexpr auto PATROL_ANIMEMAX = 1;			//全ての画像枚数
	constexpr auto PATROL_WIDTHCOUNT = 1;		//横の画像枚数
	constexpr auto PATROL_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_PATROL = 5;		//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto PATROL_TURNFRAME = 180;		//巡回の振り向きフレーム
	//移動
	constexpr auto COMING_GRAPHNAME = "res/Shielder/T_Walk.png";	//画像ファイル名
	constexpr auto COMING_ANIMEMAX = 4;			//全ての画像枚数
	constexpr auto COMING_WIDTHCOUNT = 4;		//横の画像枚数
	constexpr auto COMING_HEIGHTCOUNT = 1;		//縦の画像枚数	
	constexpr auto ANIMESPEED_COMING = 30;		//アニメスピード（何フレームごとに画像を切り替えるか）
	//攻撃
	constexpr auto ATTACK_GRAPHNAME = "res/Shielder/T_Attack.png";	//画像ファイル名
	constexpr auto ATTACK_ANIMEMAX = 3;			//全ての画像枚数
	constexpr auto ATTACK_WIDTHCOUNT = 3;		//横の画像枚数
	constexpr auto ATTACK_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_ATTACK = 20;		//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto ATTACK_ALLFRAME = 40;		//攻撃全フレーム
	constexpr auto ATTACK_BEGINFRAME = 15;		//攻撃判定発生フレーム
	constexpr auto ATTACK_ENDFRAME = 15;		//攻撃判定終了フレーム
	//盾崩し
	constexpr auto GUARDBREAK_GRAPHNAME = "res/Shielder/T_Damage.png";	//画像ファイル名
	constexpr auto GUARDBREAK_ANIMEMAX = 3;		//全ての画像枚数
	constexpr auto GUARDBREAK_WIDTHCOUNT = 3;	//横の画像枚数
	constexpr auto GUARDBREAK_HEIGHTCOUNT = 1;	//縦の画像枚数
	constexpr auto ANIMESPEED_GUARDBREAK = 15;	//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto GUARDBREAK_ALLFRAME = 44;	//被ダメ全フレーム
	//死亡
	constexpr auto DEAD_GRAPHNAME = "res/Shielder/T_Dead.png";		//画像ファイル名
	constexpr auto DEAD_ANIMEMAX = 1;			//全ての画像枚数
	constexpr auto DEAD_WIDTHCOUNT = 1;			//横の画像枚数
	constexpr auto DEAD_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_DEAD = 60;		//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto DEAD_ALLFRAME = 50;				//死亡全フレーム
	
	/*----------盾の座標関係----------*/
	constexpr auto SHIELD_WIDTH = 160;
	constexpr auto SHIELD_HEIGHT = 230;
	constexpr auto SHIELD_GRAPH_POINTX = 0;
	constexpr auto SHIELD_GRAPH_POINTY = -80;

	/*----------盾の挙動関係----------*/
	constexpr auto SHIELD_ANGLE = -0.2;
	constexpr auto SHIELD_DIFFPOINTX = -0;
	constexpr auto SHIELD_DIFFPOINTY = -90;
	constexpr auto SHIELD_ALPHA = 255;
	constexpr auto SHIELD_ANGLECHANGE = 0.03;
	constexpr auto SHIELD_ALPHACHANGE = 5;
	constexpr auto SHIELD_XCHANGE = 1;
	constexpr auto SHIELD_YCHANGE = 5;

	/*----------SE関係----------*/
	constexpr auto WALK_SE = "se/Footstep.wav";			//巡回
	constexpr auto ATTACK_SE = "se/slash3.wav";			//攻撃	

};