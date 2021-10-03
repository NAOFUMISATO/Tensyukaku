#pragma once
#include "ObjectBase.h"

class Boss :public ObjectBase {
public:
	Boss(int x,int y,bool flip);
	~Boss();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::BOSS; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
private:
	//ボスの状態列挙
	enum class BOSSSTATE {IDLE, EVENTA, EVENTB,DAMAGE, DEAD };
	void Idle(Game& g);				//待機状態時の処理
	void BossEventA(Game& g);		//イベントA時の処理
	void BossEventB(Game& g);		//イベントB時の処理
	void Damage(Game& g);			//被ダメ時の処理
	void Dead(Game& g);				//死亡時の処理
	void EventChange(Game& g);		//ボスイベントへの状態遷移処理
	void LoadPicture();			//ボスの画像読み込み関数
	void LoadSE();			//ボスの効果音読み込み関数
	void VolumeInit();	//効果音ボリューム初期値設定関数
	void VolumeChange();	//ボリューム変更関数
	/*----------メンバ変数-----------*/
	BOSSSTATE _State;
	int _WalkSpeed;

};

namespace BossInifo {
	constexpr auto GRAPHPOINT_X = 0;
	constexpr auto GRAPHPOINT_Y = -315;
	constexpr auto POSITION_HITX = -45;			//描画点から当たり判定左上座標までの差分
	constexpr auto POSITION_HITY = -135;		//描画点から当たり判定左上座標までの差分
	constexpr auto COLLISION_WIDTH = 90;		//ボスの当たり判定横幅
	constexpr auto COLLISION_HEIGHT = 450;		//ボスの当たり判定縦幅

	/*----------画像読み込み&アニメーション&判定フレーム関係----------*/
	//共通
	constexpr auto GRAPH_WIDTH = 630;			//1枚当たりの画像サイズ（横）
	constexpr auto GRAPH_HEIGHT = 630;			//1枚当たりの画像サイズ（縦）
	//待機
	constexpr auto IDLE_GRAPHNAME = "res/Boss/BossIdle.png";	//画像ファイル名
	constexpr auto IDLE_ANIMEMAX = 1;			//全ての画像枚数
	constexpr auto IDLE_WIDTHCOUNT = 1;		//横の画像枚数
	constexpr auto IDLE_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_IDLE = 1;			//アニメスピード（何フレームごとに画像を切り替えるか）
	//移動
	constexpr auto MOVE_GRAPHNAME = "res/Boss/BossWalk.png";	//画像ファイル名
	constexpr auto MOVE_ANIMEMAX = 6;			//全ての画像枚数
	constexpr auto MOVE_WIDTHCOUNT = 3;			//横の画像枚数
	constexpr auto MOVE_HEIGHTCOUNT = 2;		//縦の画像枚数	
	constexpr auto ANIMESPEED_WALK = 10;		//歩きアニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto ANIMESPEED_RUN = 6;			//走りアニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto MOVE_SEFRAME = 120;			//移動SEの管理フレーム
	//後ずさり
	constexpr auto BACK_GRAPHNAME = "res/Boss/BossBack.png";	//画像ファイル名
	constexpr auto BACK_ANIMEMAX = 6;			//全ての画像枚数
	constexpr auto BACK_WIDTHCOUNT =3;			//横の画像枚数
	constexpr auto BACK_HEIGHTCOUNT =2;			//縦の画像枚数	
	constexpr auto ANIMESPEED_BACK = 10;		//後ずさりアニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto BACK_SEFRAME = 120;			//移動SEの管理フレーム
	//被ダメ
	constexpr auto DAMAGE_GRAPHNAME = "res/Boss/BossDamage.png";	//画像ファイル名
	constexpr auto DAMAGE_ANIMEMAX = 1;	//全ての画像枚数
	constexpr auto DAMAGE_WIDTHCOUNT = 1;	//横の画像枚数
	constexpr auto DAMAGE_HEIGHTCOUNT = 1;//縦の画像枚数
	constexpr auto ANIMESPEED_DAMAGE = 60;	//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto DAMAGE_ANIMEFRAME = DAMAGE_ANIMEMAX * ANIMESPEED_DAMAGE; //アニメーションフレーム
	constexpr auto DAMAGE_ALLFRAME = 80;		//死亡全フレーム(全フレームーアニメーションフレーム＝猶予時間)
	//死亡
	constexpr auto DEAD_GRAPHNAME = "res/Boss/BossDead2.png";	//画像ファイル名
	constexpr auto DEAD_ANIMEMAX = 3;	//全ての画像枚数
	constexpr auto DEAD_WIDTHCOUNT = 3;	//横の画像枚数
	constexpr auto DEAD_HEIGHTCOUNT = 1;//縦の画像枚数
	constexpr auto ANIMESPEED_DEAD = 60;	//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto DEAD_ANIMEFRAME = DEAD_ANIMEMAX * ANIMESPEED_DEAD; //アニメーションフレーム
	constexpr auto DEAD_ALLFRAME = 180;		//死亡全フレーム(全フレームーアニメーションフレーム＝猶予時間)
}