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

		void	Init()override;
		void	Process(Game& g)override;
		void	Draw(Game& g)override;
		void	Damage(Game& g)override;
	
	private:
		void	Patrol(Game& g);	//巡回状態時の処理
		void	Coming(Game& g);	//追跡状態時の処理
		void	Attack(Game& g);	//攻撃状態時の処理
		void	LoadActionGraph();	//プレイヤーの画像読み込み関数

		/*----------メンバ変数----------*/

		//巡回状態描画用変数
		int		_Patrol_GrHandle;
		std::vector<int>	_Patrol_GrAll;
		int		_Patrol_AnimeNo;

		//移動状態描画用変数
		int		_Coming_GrHandle;
		std::vector<int>	_Coming_GrAll;
		int		_Coming_AnimeNo;

		//攻撃状態描画用変数
		int		_Attack_GrHandle;
		std::vector<int>	_Attack_GrAll;
		int		_Attack_AnimeNo;

		//各モーションフラグ管理変数
		bool	_Patrol_Flag;
		//SEハンドル
		int		_Walk_SEHandle;
		int		_Attack_SEHandle;
	};
}
namespace BInfo {
	/*----------武士の各座標関係----------*/
	constexpr auto PositionX = 1700;			//横軸初期位置（足下が基準）
	constexpr auto PositionY = 900;				//縦軸初期位置（足下が基準）
	constexpr auto GraphPointX = 0;				//X位置から描画点までの差分
	constexpr auto GraphPointY = -210;			//Y位置から描画点までの差分
	constexpr auto PositionHitX = -30;			//描画点から当たり判定左上座標までの差分
	constexpr auto PositionHitY = -90;			//描画点から当たり判定左上座標までの差分
	constexpr auto CollisionWidth = 60;			//当たり判定横幅
	constexpr auto CollisionHeight = 300;		//当たり判定縦幅

	/*----------パラメーター関係----------*/
	constexpr auto LifeMax = 1;					//体力
	constexpr auto Speed = 1;					//移動速度
	
	/*----------アニメーション関係----------*/
	//各状態アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto AnimeSpeed_Patrol = 240;		//巡回状態
	constexpr auto AnimeSpeed_Move = 5;			//移動状態
	constexpr auto AnimeSpeed_Attack = 20;		//攻撃

	//各モーションのフレーム数
	constexpr auto Patrol_Frame = 240;			//巡回フレーム
	constexpr auto Attack_Frame = 60;			//攻撃全フレーム
	constexpr auto ABegin_Frame = 20;			//攻撃発生フレーム
	constexpr auto AEnd_Frame = 20;				//攻撃終了フレーム

	/*----------画像読み込み&描画関係----------*/
	constexpr auto GraphWidth = 540;			//1枚当たりの画像サイズ（横）
	constexpr auto GraphHeight = 420;			//1枚当たりの画像サイズ（縦）
	constexpr auto GraphScale = 1.0;			//拡大率
	constexpr auto GraphAngle = 0;				//角度

	//待機
	constexpr auto Patrol_GraphName = "res/B_Stand.png";	//画像ファイル名
	constexpr auto Patrol_AnimeMax = 1;			//全ての画像枚数
	constexpr auto Patrol_WidthCount = 1;		//横の画像枚数
	constexpr auto Patrol_HeightCount = 1;		//縦の画像枚数
	//移動
	constexpr auto Coming_GraphName = "res/B_Stand.png";	//画像ファイル名
	constexpr auto Coming_AnimeMax = 1;			//全ての画像枚数
	constexpr auto Coming_WidthCount = 1;		//横の画像枚数
	constexpr auto Coming_HeightCount = 1;		//縦の画像枚数	
	//攻撃
	constexpr auto Attack_GraphName = "res/B_Attack.png";	//画像ファイル名
	constexpr auto Attack_AnimeMax = 3;			//全ての画像枚数
	constexpr auto Attack_WidthCount = 3;		//横の画像枚数
	constexpr auto Attack_HeightCount = 1;		//縦の画像枚数
	
}