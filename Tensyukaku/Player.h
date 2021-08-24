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
	//void	Sway(Game& g);			//スウェイ時の処理
	void	Damage(Game& g);		//被ダメ時の処理
	void	Dead(Game& g);			//死亡時の処理
	void	StairMove(Game& g);		//階段位置調整の処理
	void	StairUp(Game& g);		//階段上昇の処理
	void	LoadActionGraph();		//プレイヤーの画像読み込み関数
	void	LoadActionSE();			//プレイヤーの効果音読み込み関数
	void	AnimeUpdate(Game& g);	//プレイヤーのアニメーション関数
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
	//SEハンドル
	int		_Walk_SEHandle;
	int		_MiddleAttack_SEHandle;
	int		_LowAttack_SEHandle;
	int		_Kick_SEHandle;
	int		_Damage_SEHandle;
	int		_SwordIn_SEHandle;
	int		_Iai_SEHandle;
};


namespace PInfo {

	/*----------プレイヤーの各座標関係----------*/
	constexpr auto PositionX = 200;				//横軸初期位置（足下が基準）
	constexpr auto PositionY = 2200;			//縦軸初期位置（足下が基準）
	constexpr auto GraphPointX = 0;				//X位置から描画点までの差分
	constexpr auto GraphPointY = -210;			//Y位置から描画点までの差分
	constexpr auto PositionHitX = -30;			//描画点から当たり判定左上座標までの差分
	constexpr auto PositionHitY = -90;			//描画点から当たり判定左上座標までの差分
	constexpr auto CollisionWidth = 60;			//プレイヤーの当たり判定横幅
	constexpr auto CollisionHeight = 300;		//プレイヤーの当たり判定縦幅
	constexpr auto BackCameraX = 50;			//背景をプレイヤ-のカメラを画面の何％に置くか（横軸）
	constexpr auto BackCameraY = 93;			//背景をプレイヤ-のカメラを画面の何％に置くか（縦軸）
	constexpr auto ChipCameraX = 50;			//マップチップをプレイヤ-のカメラを画面の何％に置くか（横軸）
	constexpr auto ChipCameraY = 93;			//マップチップをプレイヤ-のカメラを画面の何％に置くか（縦軸）

	/*----------各モーションの当たり判定関係----------*/
	constexpr auto MiddleAttackWidth = 150;		//中段攻撃当たり判定横幅
	constexpr auto MiddleAttackHeight = 100;	//中段攻撃当たり判定縦幅
	constexpr auto LowAttackWidth = 150;		//下段攻撃当たり判定横幅
	constexpr auto LowAttackHeight = 100;		//下段攻撃当たり判定縦幅
	constexpr auto KickWidth = 150;				//蹴り当たり判定横幅
	constexpr auto KickHeight = 100;			//蹴り当たり判定縦幅
	constexpr auto IaiWidth = 600;				//居合当たり判定横幅
	constexpr auto IaiHeight = 100;				//居合当たり判定縦幅

	/*----------パラメーター関係----------*/
	constexpr auto LifeMax = 3;					//体力
	constexpr auto Speed = 7;					//移動速度

	/*----------画像読み込み&アニメーション&判定フレーム関係----------*/
	//共通
	constexpr auto GraphWidth = 720;			//1枚当たりの画像サイズ（横）
	constexpr auto GraphHeight = 420;			//1枚当たりの画像サイズ（縦）
	constexpr auto GraphScale = 1.0;			//拡大率
	constexpr auto GraphAngle = 0;				//角度
	//待機
	constexpr auto Idle_GraphName = "res/Samurai/S_Stand.png";	//画像ファイル名
	constexpr auto Idle_AnimeMax = 1;			//全ての画像枚数
	constexpr auto Idle_WidthCount = 1;			//横の画像枚数
	constexpr auto Idle_HeightCount = 1;		//縦の画像枚数
	constexpr auto AnimeSpeed_Idle = 1;			//アニメスピード（何フレームごとに画像を切り替えるか）
	//移動
	constexpr auto Move_GraphName = "res/Samurai/S_Walk.png";	//画像ファイル名
	constexpr auto Move_AnimeMax = 6;			//全ての画像枚数
	constexpr auto Move_WidthCount = 6;			//横の画像枚数
	constexpr auto Move_HeightCount = 1;		//縦の画像枚数	
	constexpr auto AnimeSpeed_Move = 6;			//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto Move_Frame = 120;			//移動SEの管理フレーム
	//中段攻撃
	constexpr auto MiddleAttack_GraphName = "res/Samurai/S_MidAttack.png";	//画像ファイル名
	constexpr auto MiddleAttack_AnimeMax = 8;	//全ての画像枚数
	constexpr auto MiddleAttack_WidthCount = 8;	//横の画像枚数
	constexpr auto MiddleAttack_HeightCount = 1;//縦の画像枚数
	constexpr auto AnimeSpeed_MiddleAttack = 4;	//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto MiddleAttack_Frame = 30;		//中段攻撃全フレーム
	constexpr auto MABegin_Frame = 12;			//中段攻撃判定発生フレーム
	constexpr auto MAEnd_Frame = 12;			//中段攻撃判定終了フレーム(発生してからのフレーム数）
	//下段攻撃
	constexpr auto LowdAttack_GraphName = "res/Samurai/S_LowAttack.png";	//画像ファイル名
	constexpr auto LowAttack_AnimeMax = 8;		//全ての画像枚数
	constexpr auto LowAttack_WidthCount = 8;	//横の画像枚数
	constexpr auto LowAttack_HeightCount = 1;	//縦の画像枚数
	constexpr auto AnimeSpeed_LowAttack = 4;	//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto LowAttack_Frame = 30;		//下段攻撃全フレーム
	constexpr auto LABegin_Frame = 12;			//下段攻撃判定発生フレーム
	constexpr auto LAEnd_Frame = 12;			//下段攻撃判定終了フレーム(発生してからのフレーム数)
	//蹴り
	constexpr auto Kick_GraphName = "res/Samurai/S_Kick.png";		//画像ファイル名
	constexpr auto Kick_AnimeMax = 6;			//全ての画像枚数
	constexpr auto Kick_WidthCount = 6;			//横の画像枚数
	constexpr auto Kick_HeightCount = 1;		//縦の画像枚数
	constexpr auto AnimeSpeed_Kick = 5;			//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto Kick_Frame = 28;				//蹴り全フレーム
	constexpr auto KIBegin_Frame = 10;			//蹴り判定発生フレーム
	constexpr auto KIEnd_Frame = 10;			//蹴り判定終了フレーム(発生してからのフレーム数)
	//居合
	constexpr auto Iai_GraphName = "res/Samurai/S_Iai.png";			//画像ファイル名
	constexpr auto Iai_AnimeMax = 8;			//全ての画像枚数
	constexpr auto Iai_WidthCount = 8;			//横の画像枚数
	constexpr auto Iai_HeightCount = 1;			//縦の画像枚数
	constexpr auto AnimeSpeed_Iai = 5;			//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto Iai_Frame = 38;				//居合フレーム
	constexpr auto IABegin_Frame = 26;			//居合判定発生フレーム
	constexpr auto IAEnd_Frame = 12;			//居合判定終了フレーム(発生してからのフレーム数)
	//スウェイ
	constexpr auto Sway_GraphName = "res/Samurai/S_Iai.png";			//画像ファイル名
	constexpr auto Sway_AnimeMax = 1;			//全ての画像枚数
	constexpr auto Sway_WidthCount = 1;			//横の画像枚数
	constexpr auto Sway_HeightCount = 1;		//縦の画像枚数
	constexpr auto Sway_Frame = 40;				//スウェイフレーム
	constexpr auto AnimeSpeed_Sway = 5;			//アニメスピード（何フレームごとに画像を切り替えるか）
	//被ダメ
	constexpr auto Damage_GraphName = "res/Samurai/S_Damage.png";	//画像ファイル名
	constexpr auto Damage_AnimeMax = 1;			//全ての画像枚数
	constexpr auto Damage_WidthCount = 1;		//横の画像枚数
	constexpr auto Damage_HeightCount = 1;		//縦の画像枚数
	constexpr auto Damage_Frame = 38;			//被ダメ全フレーム
	constexpr auto AnimeSpeed_Damage = 40;		//アニメスピード（何フレームごとに画像を切り替えるか）
	//無敵
	constexpr auto AnimeSpeed_Star = 8;			//無敵状態時の点滅速度 
	constexpr auto Star_Frame = 180;			//被ダメ時の無敵フレーム
	//死亡
	constexpr auto Dead_GraphName = "res/Samurai/S_Dead.png";		//画像ファイル名
	constexpr auto Dead_AnimeMax = 1;			//全ての画像枚数
	constexpr auto Dead_WidthCount = 1;			//横の画像枚数
	constexpr auto Dead_HeightCount = 1;		//縦の画像枚数
	constexpr auto Dead_Frame = 160;			//死亡全フレーム
	constexpr auto AnimeSpeed_Dead = 120;		//アニメスピード（何フレームごとに画像を切り替えるか）
	
	/*----------SE関係----------*/
	constexpr auto Walk_SE = "se/Footstep.wav";			//移動
	constexpr auto MiddleAttack_SE = "se/slash3.wav";	//中段攻撃
	constexpr auto LowAttack_SE = "se/Slash.wav";		//下段攻撃
	constexpr auto Kick_SE = "se/Kick.wav";				//蹴り
	constexpr auto Damage_SE = "se/Damage.wav";			//被ダメ
	constexpr auto SwordIn_SE = "se/Close.wav";			//納刀
	constexpr auto Iai_SE = "se/Iai.wav";				//居合

}