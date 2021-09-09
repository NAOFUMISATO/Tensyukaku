#pragma once
#include	"ObjectBase.h"
#include	<vector>

// プレイヤークラス
class Game;
class Player : public ObjectBase {
public:
	Player();
	~Player();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::PLAYER; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;

private:
	//プレイヤーの状態列挙
	enum class PLAYERSTATE { IDLE, MOVE, MIDDLEATTACK, LOWATTACK, KICK, IAI, SWAY, DAMAGE, DEAD,STAIRUP,STAIRMOVE,BOSSSTAIRMOVE,BOSSSTAIRUP};
	
	void	Star(Game& g);			//無敵状態時の処理
	void	Idle(Game& g);			//待機状態時の処理
	void	Move(Game& g);			//移動時の処理
	void	MidAttack(Game& g);		//中段攻撃時の処理
	void	LowAttack(Game& g);		//下段攻撃時の処理
	void	Kick(Game& g);			//蹴り時の処理
	void	Iai(Game& g);			//居合時処理
	void	Sway(Game& g);			//スウェイ時の処理
	void	Damage(Game& g);		//被ダメ時の処理
	void	Dead(Game& g);			//死亡時の処理
	void	StairMove(Game& g);		//階段位置調整の処理
	void	StairUp(Game& g);		//階段上昇の処理
	void	BossStairMove(Game& g);	//ボス階段位置調整の処理
	void	BossStairUp(Game& g);	//ボス階段上昇時の処理
	void	CameraSetting(Game& g);	//プレイヤー位置からカメラ座標設定
	void	UIAppear(Game& g);		//UIインスタンス生成関数
	void	BufSetting(Game& g);	//左スティックの入力量によるステータス設定
	void	Recovery(Game& g);		//プレイヤーの体力回復
	void	LoadActionGraph();		//プレイヤーの画像読み込み関数
	void	LoadActionSE();			//プレイヤーの効果音読み込み関数
	void	DebugDraw(Game& g);		//デバッグ用関数
	
	/*---------メンバ変数----------*/
	PLAYERSTATE	_State;		//状態遷移変数
	
	int		_alpha;			//SetDrawBlendMode用a値変数
	int		_Move_AnimeSpeed;//移動時のアニメスピード

	//無敵状態管理変数
	bool	_Star_Flag;		//無敵状態管理フラグ
	int		_Star_Cnt;		//無敵状態経過時間記録変数
	
	//階段処理変数
	Vector2 _velocityDir;	//速度方向
	float	_Stairup_Spd;	//階段上昇速度
	float	_angle;			//角度
	bool	_StairFlip_Flag;//階段の反転判定保存フラグ
	int		_Stair_x;		//階段のX座標保存変数
	int		_Player_y;		//階段上昇時のプレイヤーY座標保存変数
	bool	_UI_Flag;		//UI描画用フラグ
};


namespace PInfo {

	/*----------プレイヤーの各座標関係----------*/
	constexpr auto POSITION_X = 4000;			//横軸初期位置（足下が基準）
	constexpr auto POSITION_Y = 7840;			//縦軸初期位置（足下が基準）
	constexpr auto GRAPHPOINT_X = 0;			//X位置から描画点までの差分
	constexpr auto GRAPHPOINT_Y = -315;			//Y位置から描画点までの差分
	constexpr auto POSITION_HITX = -45;			//描画点から当たり判定左上座標までの差分
	constexpr auto POSITION_HITY = -135;			//描画点から当たり判定左上座標までの差分
	constexpr auto COLLISION_WIDTH = 90;		//プレイヤーの当たり判定横幅
	constexpr auto COLLISION_HEIGHT = 450;		//プレイヤーの当たり判定縦幅
	constexpr auto BACK_CAMERA_X = 50;			//背景をプレイヤ-のカメラを画面の何％に置くか（横軸）
	constexpr auto BACK_CAMERA_Y = 93;			//背景をプレイヤ-のカメラを画面の何％に置くか（縦軸）
	constexpr auto CHIP_CAMERA_X = 50;			//マップチップをプレイヤ-のカメラを画面の何％に置くか（横軸）
	constexpr auto CHIP_CAMERA_Y = 93;			//マップチップをプレイヤ-のカメラを画面の何％に置くか（縦軸）

	/*----------各モーションの当たり判定関係----------*/
	constexpr auto MIDDLEATTACK_WIDTH = 225;	//中段攻撃当たり判定横幅
	constexpr auto MIDDLEATTACK_HEIGHT = 150;	//中段攻撃当たり判定縦幅
	constexpr auto LOWATTACK_WIDTH = 225;		//下段攻撃当たり判定横幅
	constexpr auto LOWATTACK_HEIGHT = 200;		//下段攻撃当たり判定縦幅
	constexpr auto KICK_WIDTH = 225;			//蹴り当たり判定横幅
	constexpr auto KICK_HEIGHT = 150;			//蹴り当たり判定縦幅
	constexpr auto IAI_WIDTH = 600;				//居合当たり判定横幅
	constexpr auto IAI_HEIGHT = 100;			//居合当たり判定縦幅

	/*----------パラメーター&入力量関係----------*/
	constexpr auto LIFE_MAX = 3;				//体力
	constexpr auto WALKSPEED = 5;				//歩き移動速度
	constexpr auto RUNSPEED = 9;				//走り移動速度
	constexpr auto IAI_MAX = 6;					//居合ゲージの最大値
	constexpr auto MAX_BUF = 1000;				//入力量限界値
	constexpr auto RUN_XBUF = 800;				//走り状態になるための必要なX入力量
	constexpr auto UP_YBUF = 800;				//階段を上がるための必要なY入力量
	/*----------描画関係初期化値----------*/
	constexpr auto FIRST_FLIP = true;					//反転
	constexpr auto FIRST_ALPHA = 255;					//透明度

	/*----------画像読み込み&アニメーション&判定フレーム関係----------*/
	//共通
	constexpr auto GRAPH_WIDTH = 1080;			//1枚当たりの画像サイズ（横）
	constexpr auto GRAPH_HEIGHT = 630;			//1枚当たりの画像サイズ（縦）
	//待機
	constexpr auto IDLE_GRAPHNAME = "res/Samurai/S_Stand.png";	//画像ファイル名
	constexpr auto IDLE_ANIMEMAX = 10;			//全ての画像枚数
	constexpr auto IDLE_WIDTHCOUNT = 10;		//横の画像枚数
	constexpr auto IDLE_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_IDLE = 8;			//アニメスピード（何フレームごとに画像を切り替えるか）
	//移動
	constexpr auto MOVE_GRAPHNAME = "res/Samurai/S_Walk.png";	//画像ファイル名
	constexpr auto MOVE_ANIMEMAX = 8;			//全ての画像枚数
	constexpr auto MOVE_WIDTHCOUNT = 8;			//横の画像枚数
	constexpr auto MOVE_HEIGHTCOUNT = 1;		//縦の画像枚数	
	constexpr auto ANIMESPEED_WALK = 9;			//歩きアニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto ANIMESPEED_RUN = 6;			//走りアニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto MOVE_SEFRAME = 120;			//移動SEの管理フレーム
	constexpr auto STAIRMOVE_SPEED = 3;			//階段位置調整スピード
	//中段攻撃
	constexpr auto MIDDLEATTACK_GRAPHNAME = "res/Samurai/S_MidAttack.png";	//画像ファイル名
	constexpr auto MIDDLEATTACK_ANIMEMAX = 8;	//全ての画像枚数
	constexpr auto MIDDLEATTACK_WIDTHCOUNT = 8;	//横の画像枚数
	constexpr auto MIDDLEATTACK_HEIGHTCOUNT = 1;//縦の画像枚数
	constexpr auto ANIMESPEED_MIDDLEATTACK = 5;	//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto MIDDLEATTACK_ANIMEFRAME = MIDDLEATTACK_ANIMEMAX * ANIMESPEED_MIDDLEATTACK; //アニメーションフレーム
	constexpr auto MIDDLEATTACK_ALLFRAME = 40;	//中段攻撃全フレーム(全フレームーアニメーションフレーム＝猶予時間)
	constexpr auto MIDDLEATTACK_BEGINFRAME = 15;//中段攻撃判定発生フレーム
	constexpr auto MIDDLEATTACK_ENDFRAME = 20;	//中段攻撃判定終了フレーム(発生してからのフレーム数）
	//下段攻撃
	constexpr auto LOWATTACK_GRAPHNAME = "res/Samurai/S_LowAttack.png";	//画像ファイル名
	constexpr auto LOWATTACK_ANIMEMAX = 10;		//全ての画像枚数
	constexpr auto LOWATTACK_WIDTHCOUNT = 10;	//横の画像枚数
	constexpr auto LOWATTACK_HEIGHTCOUNT = 1;	//縦の画像枚数
	constexpr auto ANIMESPEED_LOWATTACK = 4;	//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto LOWATTACK_ANIMEFRAME = LOWATTACK_ANIMEMAX * ANIMESPEED_LOWATTACK; //アニメーションフレーム
	constexpr auto LOWATTACK_ALLFRAME = 40;		//下段攻撃全フレーム(全フレームーアニメーションフレーム＝猶予時間)
	constexpr auto LOWATTACK_BEGINFRAME = 20;	//下段攻撃判定発生フレーム
	constexpr auto LOWATTACK_ENDFRAME = 16;		//下段攻撃判定終了フレーム(発生してからのフレーム数)
	//蹴り
	constexpr auto KICK_GRAPHNAME = "res/Samurai/S_Kick.png";		//画像ファイル名
	constexpr auto KICK_ANIMEMAX = 6;			//全ての画像枚数
	constexpr auto KICK_WIDTHCOUNT = 6;			//横の画像枚数
	constexpr auto KICK_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_KICK = 6;			//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto KICK_ANIMEFRAME = KICK_ANIMEMAX * ANIMESPEED_KICK; //アニメーションフレーム
	constexpr auto KICK_ALLFRAME = 36;			//蹴り全フレーム(全フレームーアニメーションフレーム＝猶予時間)
	constexpr auto KICK_BEGINFRAME = 18;		//蹴り判定発生フレーム
	constexpr auto KICK_ENDFRAME = 12;			//蹴り判定終了フレーム(発生してからのフレーム数)
	//居合
	constexpr auto IAI_GRAPHNAME = "res/Samurai/S_Iai.png";			//画像ファイル名
	constexpr auto IAI_ANIMEMAX = 14;			//全ての画像枚数
	constexpr auto IAI_WIDTHCOUNT = 14;			//横の画像枚数
	constexpr auto IAI_HEIGHTCOUNT = 1;			//縦の画像枚数
	constexpr auto ANIMESPEED_IAI = 5;			//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto IAI_ANIMEFRAME = IAI_ANIMEMAX * ANIMESPEED_IAI; //アニメーションフレーム
	constexpr auto IAI_ALLFRAME = 73;			//居合全フレーム(全フレームーアニメーションフレーム＝猶予時間)
	constexpr auto IAI_BEGINFRAME = 40;			//居合判定発生フレーム
	constexpr auto IAI_ENDFRAME =15;			//居合判定終了フレーム(発生してからのフレーム数)
	constexpr auto IAI_MOVEMENT = 60;			//居合時の1フレームあたりの移動量
	//スウェイ
	constexpr auto SWAY_GRAPHNAME = "res/Samurai/S_Sway.png";		//画像ファイル名
	constexpr auto SWAY_ANIMEMAX = 4;			//全ての画像枚数
	constexpr auto SWAY_WIDTHCOUNT = 4;			//横の画像枚数
	constexpr auto SWAY_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_SWAY = 6;			//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto SWAY_ALLFRAME = 24;			//スウェイ全フレーム(全フレームーアニメーションフレーム＝猶予時間)
	constexpr auto SWAY_MOVEFRAME = 20;			//スウェイ時の移動フレーム
	constexpr auto SWAY_MOVEMENT = 15;			//スウェイ時の1フレームあたりの移動量
	//被ダメ
	constexpr auto DAMAGE_GRAPHNAME = "res/Samurai/S_Damage.png";	//画像ファイル名
	constexpr auto DAMAGE_ANIMEMAX = 4;			//全ての画像枚数
	constexpr auto DAMAGE_WIDTHCOUNT = 4;		//横の画像枚数
	constexpr auto DAMAGE_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_DAMAGE = 5;		//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto DAMAGE_ANIMEFRAME = DAMAGE_ANIMEMAX * ANIMESPEED_DAMAGE; //アニメーションフレーム
	constexpr auto DAMAGE_ALLFRAME = 25;		//被ダメ全フレーム
	//無敵
	constexpr auto ANIMESPEED_STAR = 8;			//無敵状態時の点滅速度 
	constexpr auto STAR_ALPHA = 128;			//無敵状態時の透明度
	constexpr auto STAR_ALLFRAME = 60;			//被ダメ時の無敵フレーム

	//死亡
	constexpr auto DEAD_GRAPHNAME = "res/Samurai/S_Dead.png";		//画像ファイル名
	constexpr auto DEAD_ANIMEMAX = 8;			//全ての画像枚数
	constexpr auto DEAD_WIDTHCOUNT = 8;			//横の画像枚数
	constexpr auto DEAD_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_DEAD = 8;		//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto DEAD_ANIMEFRAME = DEAD_ANIMEMAX * ANIMESPEED_DEAD; //アニメーションフレーム
	constexpr auto DEAD_ALLFRAME = 128;			//死亡全フレーム
	
	/*----------SE関係----------*/
	constexpr auto WALK_SE = "se/Footstep.wav";			//移動
	constexpr auto MIDDLEATTACK_SE = "se/slash3.wav";	//中段攻撃
	constexpr auto LOWATTACK_SE = "se/Slash.wav";		//下段攻撃
	constexpr auto KICK_SE = "se/Kick.wav";				//蹴り
	constexpr auto DAMAGE_SE = "se/Damage.wav";			//被ダメ
	constexpr auto SWORDIN_SE = "se/Close.wav";			//納刀
	constexpr auto IAI_SE = "se/Iai.wav";				//居合

}