#pragma once
#include "EnemyBase.h"
#include <vector>
// 武士クラス
namespace Tsk {
	class Bushi : public EnemyBase {
	public:
		Bushi();
		~Bushi();
		virtual ENEMYTYPE	GetEneType() { return ENEMYTYPE::BUSHI; }

		void	Init();
		void	Process(Game& g);
		void	Draw(Game& g);
	private:
		void	Patrol(Game& g);
		void	Coming(Game& g);
		void	Attack(Game& g);

		/*----------メンバ変数----------*/
		int		_Action_Cnt;	//アクション経過時間記録変数

		//待機状態描画用変数
		int		_Idle_GrHandle;
		std::vector<int>	_Idle_GrAll;
		int		_Idle_AnimeNo;

		//移動状態描画用変数
		int		_Move_GrHandle;
		std::vector<int>	_Move_GrAll;
		int		_Move_AnimeNo;

		//攻撃状態描画用変数
		int		_Attack_GrHandle;
		std::vector<int>	_Attack_GrAll;
		int		_Attack_AnimeNo;

		//SEハンドル
		int		_Walk_SEHandle;
		int		_Attack_SEHandle;
	};
}
namespace BInfo {
	/*----------武士の各座標関係----------*/
	constexpr auto PositionX = 1800;			//横軸初期位置（足下が基準）
	constexpr auto PositionY = 900;				//縦軸初期位置（足下が基準）
	constexpr auto GraphPointX = 0;				//X位置から描画点までの差分
	constexpr auto GraphPointY = -170;			//Y位置から描画点までの差分
	constexpr auto PositionHitX = -30;			//描画点から当たり判定左上座標までの差分
	constexpr auto PositionHitY = -80;			//描画点から当たり判定左上座標までの差分
	constexpr auto CollisionWidth = 60;			//当たり判定横幅
	constexpr auto CollisionHeight = 250;		//当たり判定縦幅

	/*----------パラメーター関係----------*/
	constexpr auto Speed = 2;					//移動速度

	/*----------アニメーション関係----------*/
	//各状態アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto AnimeSpeed_Idle = 8;			//待機状態
	constexpr auto AnimeSpeed_Move = 5;			//移動状態
	constexpr auto AnimeSpeed_Attack = 5;		//攻撃

	//各モーションのフレーム数
	constexpr auto Attack_Frame = 40;		//攻撃


	/*----------画像読み込み&描画関係----------*/
	constexpr auto GraphWidth = 540;			//1枚当たりの画像サイズ（横）
	constexpr auto GraphHeight = 420;			//1枚当たりの画像サイズ（縦）
	//待機
	constexpr auto Idle_GraphName = "res/B_Stand.png";	//画像ファイル名
	constexpr auto Idle_AnimeMax = 1;			//全ての画像枚数
	constexpr auto Idle_WidthCount = 1;			//横の画像枚数
	constexpr auto Idle_HeightCount = 1;		//縦の画像枚数
	constexpr auto Idle_Scale = 1.0;			//拡大率
	constexpr auto Idle_Angle = 0;				//角度
	//移動
	constexpr auto Move_GraphName = "res/B_Walk.png";	//画像ファイル名
	constexpr auto Move_AnimeMax = 13;			//全ての画像枚数
	constexpr auto Move_WidthCount = 5;			//横の画像枚数
	constexpr auto Move_HeightCount = 3;		//縦の画像枚数	
	constexpr auto Move_Scale = 1.0;			//拡大率
	constexpr auto Move_Angle = 0;				//角度
	//攻撃
	constexpr auto Attack_GraphName = "res/B_MidAttack.png";	//画像ファイル名
	constexpr auto Attack_AnimeMax = 8;			//全ての画像枚数
	constexpr auto Attack_WidthCount = 8;		//横の画像枚数
	constexpr auto Attack_HeightCount = 1;		//縦の画像枚数
	constexpr auto Attack_Scale = 1.0;			//拡大率
	constexpr auto Attack_Angle = 0;			//角度
}