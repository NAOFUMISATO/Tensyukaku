#pragma once
#include	"ObjectBase.h"
#include	<vector>
namespace Tsk {
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
		enum class PLAYERSTATE { IDLE, MOVE, MIDDLEATTACK, LOWATTACK, KICK, IAI, SWAY, DAMAGE, DEAD};
		
		void	Idle(Game& g);		//待機状態時の処理
		void	Move(Game& g);		//移動時の処理
		void	MidAttack(Game& g);	//中段攻撃時の処理
		void	LowAttack(Game& g);	//下段攻撃時の処理
		void	Kick(Game& g);		//蹴り時の処理
		void	Iai(Game& g);		//居合時処理
		void	Sway(Game& g);		//スウェイ時の処理
		void	Damage(Game& g);	//被ダメ時の処理
		void	Dead(Game& g);		//死亡時の処理
		void	LoadActionGraph();	//プレイヤーの画像読み込み関数
		void	LoadActionSE();		//プレイヤーの効果音読み込み関数

		/*---------メンバ変数----------*/
		PLAYERSTATE	_State;		//状態遷移変数
		
		//待機状態描画用変数
		int		_Idle_GrHandle;
		std::vector<int>	_Idle_GrAll;
		int		_Idle_AnimeNo;

		//移動状態描画用変数
		int		_Move_GrHandle;
		std::vector<int>	_Move_GrAll;
		int		_Move_AnimeNo;

		//中段攻撃状態描画用変数
		int		_MiddleAttack_GrHandle;
		std::vector<int>	_MiddleAttack_GrAll;
		int		_MiddleAttack_AnimeNo;

		//下段攻撃状態描画用変数
		int		_LowAttack_GrHandle;
		std::vector<int>	_LowAttack_GrAll;
		int		_LowAttack_AnimeNo;

		//蹴り状態描画用変数
		int		_Kick_GrHandle;
		std::vector<int>	_Kick_GrAll;
		int		_Kick_AnimeNo;

		//居合状態描画用変数
		int		_Iai_GrHandle;
		std::vector<int>	_Iai_GrAll;
		int		_Iai_AnimeNo;

		//スウェイ状態描画用変数
		int		_Sway_GrHandle;
		std::vector<int>	_Sway_GrAll;
		int		_Sway_AnimeNo;

		//被ダメ状態描画用変数
		int		_Damage_GrHandle;
		std::vector<int>	_Damage_GrAll;
		int		_Damage_AnimeNo;

		//死亡状態描画用変数
		int		_Dead_GrHandle;
		std::vector<int>	_Dead_GrAll;
		int		_Dead_AnimeNo;
		
		//無敵状態管理変数
		bool	_Star_Flag;		//無敵状態管理フラグ
		int		_Star_Cnt;		//無敵状態経過時間記録変数

		//SEハンドル
		int		_Walk_SEHandle;
		int		_MiddleAttack_SEHandle;
		int		_LowAttack_SEHandle;
		int		_Kick_SEHandle;
	};
}

namespace PInfo {

	/*----------プレイヤーの各座標関係----------*/
	constexpr auto PositionX =500;				//横軸初期位置（足下が基準）
	constexpr auto PositionY = 900;				//縦軸初期位置（足下が基準）
	constexpr auto GraphPointX = 0;				//X位置から描画点までの差分
	constexpr auto GraphPointY = -210;			//Y位置から描画点までの差分
	constexpr auto PositionHitX = -30;			//描画点から当たり判定左上座標までの差分
	constexpr auto PositionHitY = -90;			//描画点から当たり判定左上座標までの差分
	constexpr auto CollisionWidth = 60;			//プレイヤーの当たり判定横幅
	constexpr auto CollisionHeight = 300;		//プレイヤーの当たり判定縦幅

	/*----------各モーションの当たり判定関係----------*/
	constexpr auto MiddleAttackWidth = 150;		//中段攻撃当たり判定横幅
	constexpr auto MiddleAttackHeight = 100;	//中段攻撃当たり判定縦幅
	constexpr auto LowAttackWidth = 150;		//下段攻撃当たり判定横幅
	constexpr auto LowAttackHeight = 100;		//下段攻撃当たり判定縦幅
	constexpr auto KickWidth = 150;				//蹴り当たり判定横幅
	constexpr auto KickHeight = 100;			//蹴り当たり判定縦幅
	constexpr auto IaikWidth = 150;				//居合当たり判定横幅
	constexpr auto IaikHeight = 100;			//居合当たり判定縦幅

	/*----------パラメーター関係----------*/
	constexpr auto LifeMax = 3;					//体力
	constexpr auto Speed = 4;					//移動速度

	/*----------アニメーション&当たり判定関係----------*/
	//各状態アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto AnimeSpeed_Idle = 8;			//待機状態
	constexpr auto AnimeSpeed_Move = 10;		//移動状態
	constexpr auto AnimeSpeed_MiddleAttack = 5;	//中段攻撃
	constexpr auto AnimeSpeed_LowAttack = 5;	//下段攻撃
	constexpr auto AnimeSpeed_Kick = 8;			//蹴り
	constexpr auto AnimeSpeed_Sway = 5;			//スウェイ
	constexpr auto AnimeSpeed_Damage = 5;		//被ダメ
	constexpr auto AnimeSpeed_Dead = 5;			//死亡
	constexpr auto AnimeSpeed_Star = 10;		//無敵状態時の点滅速度
	//各モーションのフレーム数
	constexpr auto MiddleAttack_Frame = 40;		//中段攻撃全フレーム
	constexpr auto LowAttack_Frame = 40;		//下段攻撃全フレーム
	constexpr auto Kick_Frame = 48;				//蹴り全フレーム
	constexpr auto Iai_Frame = 40;				//居合フレーム
	constexpr auto Sway_Frame = 40;				//スウェイフレーム
	constexpr auto Damage_Frame = 40;			//被ダメ全フレーム
	constexpr auto Dead_Frame = 180;			//死亡全フレーム
	constexpr auto MABegin_Frame = 15;			//中段攻撃判定発生フレーム
	constexpr auto MAEnd_Frame= 20;				//中段攻撃判定終了フレーム(発生してからのフレーム数）
	constexpr auto LABegin_Frame = 15;			//下段攻撃判定発生フレーム
	constexpr auto LAEnd_Frame= 20;				//下段攻撃判定終了フレーム(発生してからのフレーム数)
	constexpr auto KIBegin_Frame = 24;			//蹴り判定発生フレーム
	constexpr auto KIEnd_Frame = 16;			//蹴り判定終了フレーム(発生してからのフレーム数)
	constexpr auto IABegin_Frame = 15;			//居合判定発生フレーム
	constexpr auto IAEnd_Frame = 20;			//居合判定終了フレーム(発生してからのフレーム数)
	constexpr auto Star_Frame = 180;			//被ダメ時の無敵フレーム

	/*----------画像読み込み&描画関係----------*/
	constexpr auto GraphWidth = 720;			//1枚当たりの画像サイズ（横）
	constexpr auto GraphHeight = 420;			//1枚当たりの画像サイズ（縦）
	constexpr auto GraphScale = 1.0;			//拡大率
	constexpr auto GraphAngle = 0;				//角度
	//待機
	constexpr auto Idle_GraphName = "res/Samurai/S_Stand.png";	//画像ファイル名
	constexpr auto Idle_AnimeMax = 1;			//全ての画像枚数
	constexpr auto Idle_WidthCount = 1;			//横の画像枚数
	constexpr auto Idle_HeightCount = 1;		//縦の画像枚数
	//移動
	constexpr auto Move_GraphName = "res/Samurai/S_Walk.png";	//画像ファイル名
	constexpr auto Move_AnimeMax = 6;			//全ての画像枚数
	constexpr auto Move_WidthCount = 6;			//横の画像枚数
	constexpr auto Move_HeightCount = 1;		//縦の画像枚数	
	//中段攻撃
	constexpr auto MiddleAttack_GraphName = "res/Samurai/S_MidAttack.png";	//画像ファイル名
	constexpr auto MiddleAttack_AnimeMax = 8;	//全ての画像枚数
	constexpr auto MiddleAttack_WidthCount = 8;	//横の画像枚数
	constexpr auto MiddleAttack_HeightCount = 1;//縦の画像枚数
	//下段攻撃
	constexpr auto LowdAttack_GraphName = "res/Samurai/S_LowAttack.png";	//画像ファイル名
	constexpr auto LowAttack_AnimeMax = 8;		//全ての画像枚数
	constexpr auto LowAttack_WidthCount = 8;	//横の画像枚数
	constexpr auto LowAttack_HeightCount = 1;	//縦の画像枚数
	//蹴り
	constexpr auto Kick_GraphName = "res/Samurai/S_Kick.png";		//画像ファイル名
	constexpr auto Kick_AnimeMax = 6;			//全ての画像枚数
	constexpr auto Kick_WidthCount = 6;			//横の画像枚数
	constexpr auto Kick_HeightCount = 1;		//縦の画像枚数
	//居合
	constexpr auto Iai_GraphName = "res/Samurai/S_Iai.png";			//画像ファイル名
	constexpr auto Iai_AnimeMax = 8;			//全ての画像枚数
	constexpr auto Iai_WidthCount = 8;			//横の画像枚数
	constexpr auto Iai_HeightCount = 1;			//縦の画像枚数
	//スウェイ
	constexpr auto Sway_GraphName = "res/Samurai/S_Iai.png";			//画像ファイル名
	constexpr auto Sway_AnimeMax = 1;			//全ての画像枚数
	constexpr auto Sway_WidthCount = 1;			//横の画像枚数
	constexpr auto Sway_HeightCount = 1;		//縦の画像枚数
	//被ダメ
	constexpr auto Damage_GraphName = "res/Samurai/S_Damage.png";	//画像ファイル名
	constexpr auto Damage_AnimeMax = 1;			//全ての画像枚数
	constexpr auto Damage_WidthCount = 1;		//横の画像枚数
	constexpr auto Damage_HeightCount = 1;		//縦の画像枚数
	//死亡
	constexpr auto Dead_GraphName = "res/Samurai/S_Dead.png";		//画像ファイル名
	constexpr auto Dead_AnimeMax = 1;			//全ての画像枚数
	constexpr auto Dead_WidthCount = 1;			//横の画像枚数
	constexpr auto Dead_HeightCount = 1;		//縦の画像枚数
	
	/*----------SE関係----------*/
	constexpr auto Walk_SE = "se/walk.wav";				//移動
	constexpr auto MiddleAttack_SE = "se/slash3.wav";	//中段攻撃
	constexpr auto LowAttack_SE = "se/slash2.wav";		//下段攻撃
	constexpr auto Kick_SE = "se/Kick.wav";				//蹴り
}