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
	bool	GetFlip() { return _isFlip; }
private:
	//プレイヤーの状態列挙
	enum class PLAYERSTATE { IDLE, MOVE, MIDDLEATTACK, LOWATTACK, KICK, IAI, SWAY, DAMAGE, DEAD,STAIRUP,STAIRMOVE};
	
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
	void	LoadActionGraph();		//プレイヤーの画像読み込み関数
	void	LoadActionSE();			//プレイヤーの効果音読み込み関数
	void	AnimeUpdate(Game& g);	//プレイヤーのアニメーション関数
	void	DebugDraw(Game& g);		//デバッグ用関数
	void	UIDraw(Game& g);		//プレイヤーのUI描画関数

	/*---------メンバ変数----------*/
	PLAYERSTATE	_State;		//状態遷移変数
	
	//待機状態描画用変数
	std::vector<int>	_Idle_GrAll;
	int		_Idle_AnimeNo;

	//移動状態描画用変数
	std::vector<int>	_Move_GrAll;
	int		_Move_AnimeNo;

	//中段攻撃状態描画用変数
	std::vector<int>	_MiddleAttack_GrAll;
	int		_MiddleAttack_AnimeNo;

	//下段攻撃状態描画用変数
	std::vector<int>	_LowAttack_GrAll;
	int		_LowAttack_AnimeNo;

	//蹴り状態描画用変数
	std::vector<int>	_Kick_GrAll;
	int		_Kick_AnimeNo;

	//居合状態描画用変数
	std::vector<int>	_Iai_GrAll;
	int		_Iai_AnimeNo;

	//スウェイ状態描画用変数
	std::vector<int>	_Sway_GrAll;
	int		_Sway_AnimeNo;

	//被ダメ状態描画用変数
	std::vector<int>	_Damage_GrAll;
	int		_Damage_AnimeNo;

	//死亡状態描画用変数
	std::vector<int>	_Dead_GrAll;
	int		_Dead_AnimeNo;
	
	//無敵状態管理変数
	bool	_Star_Flag;		//無敵状態管理フラグ
	int		_Star_Cnt;		//無敵状態経過時間記録変数
	int		_Iai_Gauge;		//居合ゲージ変数
	
	//階段処理
	Vector2 _velocityDir;	//速度方向
	float	_Stairup_Spd;	//階段上昇速度
	float	_angle;			//角度
	bool	_StairFlip_Flag;//階段の反転判定保存フラグ
	int		_Stair_x;		//階段のX座標保存変数
	int		_Player_y;		//階段用プレイヤーY座標保存変数

};


namespace PInfo {

	/*----------プレイヤーの各座標関係----------*/
	constexpr auto POSITION_X = 200;			//横軸初期位置（足下が基準）
	constexpr auto POSITION_Y = 2200;			//縦軸初期位置（足下が基準）
	constexpr auto GRAPHPOINT_X = 0;			//X位置から描画点までの差分
	constexpr auto GRAPHPOINT_Y = -210;			//Y位置から描画点までの差分
	constexpr auto POSITION_HITX = -30;			//描画点から当たり判定左上座標までの差分
	constexpr auto POSITION_HITY = -90;			//描画点から当たり判定左上座標までの差分
	constexpr auto COLLISION_WIDTH = 60;		//プレイヤーの当たり判定横幅
	constexpr auto COLLISION_HEIGHT = 300;		//プレイヤーの当たり判定縦幅
	constexpr auto BACK_CAMERA_X = 50;			//背景をプレイヤ-のカメラを画面の何％に置くか（横軸）
	constexpr auto BACK_CAMERA_Y = 93;			//背景をプレイヤ-のカメラを画面の何％に置くか（縦軸）
	constexpr auto CHIP_CAMERA_X = 50;			//マップチップをプレイヤ-のカメラを画面の何％に置くか（横軸）
	constexpr auto CHIP_CAMERA_Y = 93;			//マップチップをプレイヤ-のカメラを画面の何％に置くか（縦軸）

	/*----------各モーションの当たり判定関係----------*/
	constexpr auto MIDDLEATTACK_WIDTH = 150;	//中段攻撃当たり判定横幅
	constexpr auto MIDDLEATTACK_HEIGHT = 100;	//中段攻撃当たり判定縦幅
	constexpr auto LOWATTACK_WIDTH = 150;		//下段攻撃当たり判定横幅
	constexpr auto LOWATTACK_HEIGHT = 100;		//下段攻撃当たり判定縦幅
	constexpr auto KICK_WIDTH = 150;			//蹴り当たり判定横幅
	constexpr auto KICK_HEIGHT = 100;			//蹴り当たり判定縦幅
	constexpr auto IAI_WIDTH = 600;				//居合当たり判定横幅
	constexpr auto IAI_HEIGHT = 100;			//居合当たり判定縦幅

	/*----------パラメーター関係----------*/
	constexpr auto LIFE_MAX = 3;				//体力
	constexpr auto SPEED = 7;					//移動速度

	/*----------画像読み込み&アニメーション&判定フレーム関係----------*/
	//共通
	constexpr auto GRAPH_WIDTH = 720;			//1枚当たりの画像サイズ（横）
	constexpr auto GRAPH_HEIGHT = 420;			//1枚当たりの画像サイズ（縦）
	constexpr auto GRAPH_SCALE = 1.0;			//拡大率
	constexpr auto GRAPH_ANGLE = 0;				//角度
	//待機
	constexpr auto IDLE_GRAPHNAME = "res/Samurai/S_Stand.png";	//画像ファイル名
	constexpr auto IDLE_ANIMEMAX = 1;			//全ての画像枚数
	constexpr auto IDLE_WIDTHCOUNT = 1;			//横の画像枚数
	constexpr auto IDLE_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_IDLE = 1;			//アニメスピード（何フレームごとに画像を切り替えるか）
	//移動
	constexpr auto MOVE_GRAPHNAME = "res/Samurai/S_Walk.png";	//画像ファイル名
	constexpr auto MOVE_ANIMEMAX = 6;			//全ての画像枚数
	constexpr auto MOVE_WIDTHCOUNT = 6;			//横の画像枚数
	constexpr auto MOVE_HEIGHTCOUNT = 1;		//縦の画像枚数	
	constexpr auto ANIMESPEED_MOVE = 6;			//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto MOVE_SEFRAME = 120;			//移動SEの管理フレーム
	//中段攻撃
	constexpr auto MIDDLEATTACK_GRAPHNAME = "res/Samurai/S_MidAttack.png";	//画像ファイル名
	constexpr auto MIDDLEATTACK_ANIMEMAX = 8;	//全ての画像枚数
	constexpr auto MIDDLEATTACK_WIDTHCOUNT = 8;	//横の画像枚数
	constexpr auto MIDDLEATTACK_HEIGHTCOUNT = 1;//縦の画像枚数
	constexpr auto ANIMESPEED_MIDDLEATTACK = 4;	//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto MIDDLEATTACK_ALLFRAME = 30;	//中段攻撃全フレーム
	constexpr auto MIDDLEATTACK_BEGINFRAME = 12;//中段攻撃判定発生フレーム
	constexpr auto MIDDLEATTACK_ENDFRAME = 12;	//中段攻撃判定終了フレーム(発生してからのフレーム数）
	//下段攻撃
	constexpr auto LOWATTACK_GRAPHNAME = "res/Samurai/S_LowAttack.png";	//画像ファイル名
	constexpr auto LOWATTACK_ANIMEMAX = 8;		//全ての画像枚数
	constexpr auto LOWATTACK_WIDTHCOUNT = 8;	//横の画像枚数
	constexpr auto LOWATTACK_HEIGHTCOUNT = 1;	//縦の画像枚数
	constexpr auto ANIMESPEED_LOWATTACK = 4;	//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto LOWATTACK_ALLFRAME = 30;		//下段攻撃全フレーム
	constexpr auto LOWATTACK_BEGINFRAME = 12;	//下段攻撃判定発生フレーム
	constexpr auto LOWATTACK_ENDFRAME = 12;		//下段攻撃判定終了フレーム(発生してからのフレーム数)
	//蹴り
	constexpr auto KICK_GRAPHNAME = "res/Samurai/S_Kick.png";		//画像ファイル名
	constexpr auto KICK_ANIMEMAX = 6;			//全ての画像枚数
	constexpr auto KICK_WIDTHCOUNT = 6;			//横の画像枚数
	constexpr auto KICK_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_KICK = 5;			//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto KICK_ALLFRAME = 28;			//蹴り全フレーム
	constexpr auto KICK_BEGINFRAME = 10;		//蹴り判定発生フレーム
	constexpr auto KICK_ENDFRAME = 10;			//蹴り判定終了フレーム(発生してからのフレーム数)
	//居合
	constexpr auto IAI_GRAPHNAME = "res/Samurai/S_Iai.png";			//画像ファイル名
	constexpr auto IAI_ANIMEMAX = 8;			//全ての画像枚数
	constexpr auto IAI_WIDTHCOUNT = 8;			//横の画像枚数
	constexpr auto IAI_HEIGHTCOUNT = 1;			//縦の画像枚数
	constexpr auto ANIMESPEED_IAI = 5;			//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto IAI_ALLFRAME = 38;			//居合全フレーム
	constexpr auto IAI_BEGINFRAME = 26;			//居合判定発生フレーム
	constexpr auto IAI_ENDFRAME = 12;			//居合判定終了フレーム(発生してからのフレーム数)
	//スウェイ
	constexpr auto SWAY_GRAPHNAME = "res/Samurai/S_Sway.png";		//画像ファイル名
	constexpr auto SWAY_ANIMEMAX = 1;			//全ての画像枚数
	constexpr auto SWAY_WIDTHCOUNT = 1;			//横の画像枚数
	constexpr auto SWAY_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_SWAY = 5;			//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto SWAY_ALLFRAME = 40;			//スウェイ全フレーム
	constexpr auto SWAY_BEGINFRAME = 15;		//無敵判定発生フレーム
	constexpr auto SWAY_ENDFRAME = 15;			//無敵判定終了フレーム(発生してからのフレーム数)
	//被ダメ
	constexpr auto DAMAGE_GRAPHNAME = "res/Samurai/S_Damage.png";	//画像ファイル名
	constexpr auto DAMAGE_ANIMEMAX = 1;			//全ての画像枚数
	constexpr auto DAMAGE_WIDTHCOUNT = 1;		//横の画像枚数
	constexpr auto DAMAGE_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto ANIMESPEED_DAMAGE = 40;		//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto DAMAGE_ALLFRAME = 38;		//被ダメ全フレーム
	//無敵
	constexpr auto ANIMESPEED_STAR = 8;			//無敵状態時の点滅速度 
	constexpr auto STAR_ALLFRAME = 180;			//被ダメ時の無敵フレーム
	//死亡
	constexpr auto DEAD_GRAPHNAME = "res/Samurai/S_Dead.png";		//画像ファイル名
	constexpr auto DEAD_ANIMEMAX = 1;			//全ての画像枚数
	constexpr auto DEAD_WIDTHCOUNT = 1;			//横の画像枚数
	constexpr auto DEAD_HEIGHTCOUNT = 1;		//縦の画像枚数
	constexpr auto DEAD_ALLFRAME = 160;			//死亡全フレーム
	constexpr auto ANIMESPEED_DEAD = 120;		//アニメスピード（何フレームごとに画像を切り替えるか）
	
	/*----------SE関係----------*/
	constexpr auto WALK_SE = "se/Footstep.wav";			//移動
	constexpr auto MIDDLEATTACK_SE = "se/slash3.wav";	//中段攻撃
	constexpr auto LOWATTACK_SE = "se/Slash.wav";		//下段攻撃
	constexpr auto KICK_SE = "se/Kick.wav";				//蹴り
	constexpr auto DAMAGE_SE = "se/Damage.wav";			//被ダメ
	constexpr auto SWORDIN_SE = "se/Close.wav";			//納刀
	constexpr auto IAI_SE = "se/Iai.wav";				//居合

}