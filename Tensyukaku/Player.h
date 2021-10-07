#pragma once
#include	"ObjectBase.h"
#include	<vector>

// プレイヤークラス
class Game;
class Player : public ObjectBase {
public:
	Player( int x,int y,bool flip);
	~Player();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::PLAYER; }

	void	Init()override;								 //初期化
	void	Process(Game& g)override;		//処理
	void	Draw(Game& g)override;			//描画
	
private:
	//プレイヤーの状態列挙
	enum class PLAYERSTATE { APPEAR,SWORDOUT,IDLE, MOVE, MIDDLEATTACK, LOWATTACK, KICK, IAI, SWAY, DAMAGE, DEAD, STAIRUP, STAIRMOVE, BOSSSTAIRMOVE, BOSSSTAIRUP, EVENTA, EVENTB,SPECIALATTACK};
	void	Star(Game& g);							//無敵状態時の処理
	void	Appear(Game& g);					//出現状態の処理
	void	Swordout(Game& g);				//抜刀状態の処理
	void	Idle(Game& g);							//待機状態時の処理
	void	Move(Game& g);						//移動時の処理
	void	MidAttack(Game& g);				//中段攻撃時の処理
	void	LowAttack(Game& g);				//下段攻撃時の処理
	void	Kick(Game& g);							//蹴り時の処理
	void	Iai(Game& g);							//居合時処理
	void	Sway(Game& g);						//スウェイ時の処理
	void	Damage(Game& g);					//被ダメ時の処理
	void	Dead(Game& g);						//死亡時の処理
	void	StairMove(Game& g);				//階段位置調整の処理
	void	StairUp(Game& g);					//階段上昇の処理
	void	BossStairMove(Game& g);		//ボス階段位置調整の処理
	void	BossStairUp(Game& g);			//ボス階段上昇時の処理
	void	BossEventA(Game& g);			//ボスイベント処理A
	void	BossEventB(Game& g);			//ボスイベント処理B
	void	SpecialAttack(Game& g);		//特殊攻撃の処理
	void	HitJudge(Game& g);					//各当たり判定の処理
	void	CameraSetting(Game& g);		//プレイヤー位置からカメラ座標設定
	void	UIAppear(Game& g);				//UIインスタンス生成関数
	void	GaugeMax(Game& g);				//居合ゲージMAX時に自機発光&SE発生	
	void	BufSetting(Game& g);				//左スティックの入力量によるステータス設定
	void	RestartCheck(Game& g);		//再起からの開始ならば抜刀状態から開始
	void PauseInput(Game& g);			//ポーズの入力管理関数
	void	DebugDraw(Game& g);			//デバッグ用関数
	void	LoadPicture();							//画像読み込み関数
	void	LoadSE();									//効果音読み込み関数
	void	VolumeInit();								//効果音ボリューム初期値設定関数
	void	VolumeChange();						//ボリューム変更関数
	/*---------メンバ変数----------*/
	PLAYERSTATE	_state;							//状態遷移変数
	int		_move_animespeed;			//移動時のアニメスピード
	int		_camera_x;								//カメラ位置
	bool	_ui_flag;									//UI描画用フラグ
	bool	_gaugemax_flag;					//居合ゲージがMAXになったかのフラグ
	bool	_nohit_flag;							//モーション中に当たり判定を行わないフラグ
	bool	_tutorialhit_flag;					//チュートリアルボードとの当たり判定フラグ
	bool	_restartcheck_flag;				//再起からの開始かどうか確認するフラグ
	bool	_pauseinput_flag;					//ポーズの入力を受けつけるかどうかのフラグ
	//無敵状態管理変数
	bool	_star_flag;								//無敵状態管理フラグ
	int		_star_cnt;								//無敵状態経過時間記録変数
	//階段処理変数
	Vector2 _velocityDir;						//速度方向
	float	_stairup_spd;						//階段上昇速度
	float	_angle;									//角度
	bool	_stairup_flag;							//階段上昇の受付判定用フラグ
	bool	_stairflip_flag;						//階段の反転判定保存フラグ
	int		_stair_x;									//階段のX座標保存変数
	int		_player_y;								//階段上昇時のプレイヤーY座標保存変数
};


namespace PInfo {

	/*----------プレイヤーの各座標関係----------*/
	constexpr auto POSITION_X = 4000;							//横軸初期位置（足下が基準）
	constexpr auto POSITION_Y = 7840;							//縦軸初期位置（足下が基準）
	constexpr auto CPOINT_POSITION_X = 3500;			//チェックポイントX座標
	constexpr auto CPOINT_POSITION_Y = 4040;				//チェックポイントY座標
	constexpr auto GRAPHPOINT_X = 0;							//X位置から描画点までの差分
	constexpr auto GRAPHPOINT_Y = -315;						//Y位置から描画点までの差分
	constexpr auto POSITION_HITX = -60;							//描画点から当たり判定左上座標までの差分
	constexpr auto POSITION_HITY = -135;						//描画点から当たり判定左上座標までの差分
	constexpr auto COLLISION_WIDTH = 120;					//プレイヤーの当たり判定横幅
	constexpr auto COLLISION_HEIGHT = 450;					//プレイヤーの当たり判定縦幅
	constexpr auto BACK_CAMERA_X = 50;						//背景をプレイヤ-のカメラを画面の何％に置くか（横軸）
	constexpr auto BACK_CAMERA_Y = 93;						//背景をプレイヤ-のカメラを画面の何％に置くか（縦軸）
	constexpr auto CHIP_CAMERA_X = 50;							//マップチップをプレイヤ-のカメラを画面の何％に置くか（横軸）
	constexpr auto CHIP_CAMERA_Y = 93;							//マップチップをプレイヤ-のカメラを画面の何％に置くか（縦軸）

	/*----------各モーションの当たり判定関係----------*/
	constexpr auto MIDDLEATTACK_WIDTH = 275;			//中段攻撃当たり判定横幅
	constexpr auto MIDDLEATTACK_HEIGHT = 150;			//中段攻撃当たり判定縦幅
	constexpr auto LOWATTACK_WIDTH = 275;				//下段攻撃当たり判定横幅
	constexpr auto LOWATTACK_HEIGHT = 200;				//下段攻撃当たり判定縦幅
	constexpr auto KICK_WIDTH = 225;								//蹴り当たり判定横幅
	constexpr auto KICK_HEIGHT = 150;							//蹴り当たり判定縦幅
	constexpr auto IAI_WIDTH = 780;									//居合当たり判定横幅
	constexpr auto IAI_HEIGHT = 100;								//居合当たり判定縦幅
	constexpr auto SPECIALATTACK_WIDTH = 300;			//特殊攻撃当たり判定横幅
	constexpr auto SPECIALATTACK_HEIGHT = 100;			//特殊攻撃当たり判定縦幅

	/*----------パラメーター&入力量関係----------*/
	constexpr auto LIFE_MAX = 3;										//体力
	constexpr auto WALKSPEED = 5;									//歩き移動速度
	constexpr auto RUNSPEED = 9;										//走り移動速度
	constexpr auto STAIRMOVE_SPEED = 3;						//階段位置調整スピード
	constexpr auto STAIRUP_SPEED = 5.01f;						//階段上昇速度
	constexpr auto BOSSSTAIRUP_SPEED = 3.0f;				//ボス階段上昇速度
	constexpr auto IAI_MAX = 5;											//居合ゲージの最大値
	constexpr auto MAX_BUF = 1000;									//入力量限界値
	constexpr auto RUN_XBUF = 800;									//走り状態になるための必要なX入力量
	constexpr auto UP_YBUF = 800;									//階段を上がるための必要なY入力量
	/*----------描画関係初期化値----------*/
	constexpr auto FIRST_FLIP = true;								//反転
	constexpr auto FIRST_ALPHA = 255;								//透明度

	/*----------画像読み込み&アニメーション&判定フレーム関係----------*/
	//共通
	constexpr auto GRAPH_WIDTH = 1080;						//1枚当たりの画像サイズ（横）
	constexpr auto GRAPH_HEIGHT = 630;						//1枚当たりの画像サイズ（縦）
	//出現
	constexpr auto APPEAR_GRAPHNAME = "res/Samurai/S_Appear.png";	//画像ファイル名
	constexpr auto APPEAR_ANIMEMAX = 20;					//全ての画像枚数
	constexpr auto APPEAR_WIDTHCOUNT = 7;				//横の画像枚数
	constexpr auto APPEAR_HEIGHTCOUNT = 3;				//縦の画像枚数
	constexpr auto ANIMESPEED_APPEAR = 5;					//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto APPEAR_ANIMEFRAME = APPEAR_ANIMEMAX * ANIMESPEED_APPEAR; //アニメーションフレーム
	//抜刀
	constexpr auto SWORDOUT_GRAPHNAME = "res/Samurai/S_Appear.png";	//画像ファイル名
	constexpr auto SWORDOUT_ANIMEMAX = 20;			//全ての画像枚数
	constexpr auto SWORDOUT_WIDTHCOUNT = 7;		//横の画像枚数
	constexpr auto SWORDOUT_HEIGHTCOUNT = 3;		//縦の画像枚数
	constexpr auto ANIMESPEED_SWORDOUT = 5;			//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto SWORDOUT_ANIMEFRAME = SWORDOUT_ANIMEMAX * ANIMESPEED_SWORDOUT; //アニメーションフレーム
	//待機
	constexpr auto IDLE_GRAPHNAME = "res/Samurai/S_Stand.png";	//画像ファイル名
	constexpr auto IDLE_ANIMEMAX = 10;						//全ての画像枚数
	constexpr auto IDLE_WIDTHCOUNT = 10;					//横の画像枚数
	constexpr auto IDLE_HEIGHTCOUNT = 1;					//縦の画像枚数
	constexpr auto ANIMESPEED_IDLE = 8;						//アニメスピード（何フレームごとに画像を切り替えるか）
	//移動
	constexpr auto MOVE_GRAPHNAME = "res/Samurai/S_Walk.png";	//画像ファイル名
	constexpr auto MOVE_ANIMEMAX = 8;						//全ての画像枚数
	constexpr auto MOVE_WIDTHCOUNT = 8;					//横の画像枚数
	constexpr auto MOVE_HEIGHTCOUNT = 1;					//縦の画像枚数	
	constexpr auto ANIMESPEED_WALK = 9;						//歩きアニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto ANIMESPEED_RUN = 6;						//走りアニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto MOVE_SEFRAME = 120;						//移動SEの管理フレーム
	//中段攻撃
	constexpr auto MIDDLEATTACK_GRAPHNAME = "res/Samurai/S_MidAttack.png";	//画像ファイル名
	constexpr auto MIDDLEATTACK_ANIMEMAX = 8;		//全ての画像枚数
	constexpr auto MIDDLEATTACK_WIDTHCOUNT = 8;	//横の画像枚数
	constexpr auto MIDDLEATTACK_HEIGHTCOUNT = 1;//縦の画像枚数
	constexpr auto ANIMESPEED_MIDDLEATTACK = 5;	//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto MIDDLEATTACK_ANIMEFRAME = MIDDLEATTACK_ANIMEMAX * ANIMESPEED_MIDDLEATTACK; //アニメーションフレーム
	constexpr auto MIDDLEATTACK_ALLFRAME = 40;		//中段攻撃全フレーム(全フレームーアニメーションフレーム＝猶予時間)
	constexpr auto MIDDLEATTACK_BEGINFRAME = 15;//中段攻撃判定発生フレーム
	constexpr auto MIDDLEATTACK_ENDFRAME = 20;		//中段攻撃判定終了フレーム(発生してからのフレーム数）
	//下段攻撃
	constexpr auto LOWATTACK_GRAPHNAME = "res/Samurai/S_LowAttack.png";	//画像ファイル名
	constexpr auto LOWATTACK_ANIMEMAX = 10;		//全ての画像枚数
	constexpr auto LOWATTACK_WIDTHCOUNT = 10;	//横の画像枚数
	constexpr auto LOWATTACK_HEIGHTCOUNT = 1;	//縦の画像枚数
	constexpr auto ANIMESPEED_LOWATTACK = 4;		//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto LOWATTACK_ANIMEFRAME = LOWATTACK_ANIMEMAX * ANIMESPEED_LOWATTACK; //アニメーションフレーム
	constexpr auto LOWATTACK_ALLFRAME = 40;		//下段攻撃全フレーム(全フレームーアニメーションフレーム＝猶予時間)
	constexpr auto LOWATTACK_BEGINFRAME = 16;	//下段攻撃判定発生フレーム
	constexpr auto LOWATTACK_ENDFRAME = 20;		//下段攻撃判定終了フレーム(発生してからのフレーム数)
	//蹴り
	constexpr auto KICK_GRAPHNAME = "res/Samurai/S_Kick.png";		//画像ファイル名
	constexpr auto KICK_ANIMEMAX = 6;				//全ての画像枚数
	constexpr auto KICK_WIDTHCOUNT = 6;			//横の画像枚数
	constexpr auto KICK_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_KICK = 5;			//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto KICK_ANIMEFRAME = KICK_ANIMEMAX * ANIMESPEED_KICK; //アニメーションフレーム
	constexpr auto KICK_ALLFRAME = 30;				//蹴り全フレーム(全フレームーアニメーションフレーム＝猶予時間)
	constexpr auto KICK_BEGINFRAME = 12;		//蹴り判定発生フレーム
	constexpr auto KICK_ENDFRAME = 10;			//蹴り判定終了フレーム(発生してからのフレーム数)
	//居合
	constexpr auto IAI_GRAPHNAME = "res/Samurai/S_Iai.png";			//画像ファイル名
	constexpr auto IAI_ANIMEMAX = 14;				//全ての画像枚数
	constexpr auto IAI_WIDTHCOUNT = 14;			//横の画像枚数
	constexpr auto IAI_HEIGHTCOUNT = 1;			//縦の画像枚数
	constexpr auto ANIMESPEED_IAI = 5;				//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto IAI_ANIMEFRAME = IAI_ANIMEMAX * ANIMESPEED_IAI; //アニメーションフレーム
	constexpr auto IAI_ALLFRAME = 73;					//居合全フレーム(全フレームーアニメーションフレーム＝猶予時間)
	constexpr auto IAI_BEGINFRAME = 40;			//居合判定発生フレーム
	constexpr auto IAI_ENDFRAME =55;					//居合判定終了フレーム(発生してからのフレーム数)
	constexpr auto IAI_MOVEMENT = 40;				//居合時の1フレームあたりの移動量
	//スウェイ
	constexpr auto SWAY_GRAPHNAME = "res/Samurai/S_Sway.png";		//画像ファイル名
	constexpr auto SWAY_ANIMEMAX = 4;				//全ての画像枚数
	constexpr auto SWAY_WIDTHCOUNT = 4;		//横の画像枚数
	constexpr auto SWAY_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_SWAY =6;			//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto SWAY_ALLFRAME = 24;			//スウェイ全フレーム(全フレームーアニメーションフレーム＝猶予時間)
	constexpr auto SWAY_NOHITBEGINFRAME = 0;	//スウェイの無敵判定開始フレーム
	constexpr auto SWAY_NOHITENDFRAME = 20;	//スウェイの無敵判定終了フレーム
	constexpr auto SWAY_MOVEFRAME = 20;			//スウェイ時の移動フレーム
	constexpr auto SWAY_MOVEMENT = 12;				//スウェイ時の1フレームあたりの移動量
	//被ダメ
	constexpr auto DAMAGE_GRAPHNAME = "res/Samurai/S_Damage.png";	//画像ファイル名
	constexpr auto DAMAGE_ANIMEMAX = 4;			//全ての画像枚数
	constexpr auto DAMAGE_WIDTHCOUNT = 4;		//横の画像枚数
	constexpr auto DAMAGE_HEIGHTCOUNT = 1;	//縦の画像枚数
	constexpr auto ANIMESPEED_DAMAGE =7;		//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto DAMAGE_ANIMEFRAME = DAMAGE_ANIMEMAX * ANIMESPEED_DAMAGE; //アニメーションフレーム
	constexpr auto DAMAGE_ALLFRAME = 28;			//被ダメ全フレーム
	//無敵
	constexpr auto ANIMESPEED_STAR = 8;				//無敵状態時の点滅速度 
	constexpr auto STAR_ALPHA = 128;						//無敵状態時の透明度
	constexpr auto STAR_ALLFRAME = 60;					//被ダメ時の無敵フレーム
	//死亡
	constexpr auto DEAD_GRAPHNAME = "res/Samurai/S_Dead.png";		//画像ファイル名
	constexpr auto DEAD_ANIMEMAX = 8;					//全ての画像枚数
	constexpr auto DEAD_WIDTHCOUNT = 8;			//横の画像枚数
	constexpr auto DEAD_HEIGHTCOUNT = 1;			//縦の画像枚数
	constexpr auto ANIMESPEED_DEAD = 8;				//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto DEAD_ANIMEFRAME = DEAD_ANIMEMAX * ANIMESPEED_DEAD; //アニメーションフレーム
	constexpr auto DEAD_ALLFRAME = 128;				//死亡全フレーム
	//特殊攻撃
	constexpr auto SPECIALATTACK_GRAPHNAME = "res/Samurai/S_Special.png";	//画像ファイル名
	constexpr auto SPECIALATTACK_ANIMEMAX = 48;		//全ての画像枚数
	constexpr auto SPECIALATTACK_WIDTHCOUNT = 16;	//横の画像枚数
	constexpr auto SPECIALATTACK_HEIGHTCOUNT = 3;	//縦の画像枚数
	constexpr auto ANIMESPEED_SPECIALATTACK = 5;		//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto SPECIALATTACK_ANIMEFRAME = SPECIALATTACK_ANIMEMAX * ANIMESPEED_SPECIALATTACK; //アニメーションフレーム
	constexpr auto SPECIALATTACK_ALLFRAME = 270;		//特殊攻撃全フレーム(全フレームーアニメーションフレーム＝猶予時間)
	constexpr auto SPECIALATTACK_BEGINFRAME = 40;		//特殊攻撃判定発生フレーム
	constexpr auto SPECIALATTACK_ENDFRAME = 80;		//特殊攻撃判定終了フレーム(発生してからのフレーム数）
}