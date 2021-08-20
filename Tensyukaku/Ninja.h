#pragma once
#include "EnemyBase.h"
#include <vector>
// 忍者クラス

class Ninja : public EnemyBase {
public:
	Ninja();
	~Ninja();
	virtual ENEMYTYPE	GetEneType() { return ENEMYTYPE::NINJA; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;
	bool	isDead() { return _State == ENEMYSTATE::DEAD; };

private:
	void	Patrol(Game& g);		//巡回状態時の処理
	void	Coming(Game& g);		//追跡状態時の処理
	void	Attack(Game& g);		//攻撃状態時の処理
	void	Dead(Game& g);			//死亡状態時の処理
	void	LoadActionGraph();		//忍者の画像読み込み関数
	void	LoadActionSE();			//忍者のSE読み込み関数
	void	AnimeUpdate(Game& g);	//忍者のアニメーション関数
	
	/*----------メンバ変数----------*/

	//巡回状態描画用変数
	std::vector<int>	_Patrol_GrAll;
	int		_Patrol_AnimeNo;

	//移動状態描画用変数
	std::vector<int>	_Coming_GrAll;
	int		_Coming_AnimeNo;

	//攻撃状態描画用変数
	std::vector<int>	_Attack_GrAll;
	int		_Attack_AnimeNo;

	//死亡状態描画用変数
	std::vector<int>	_Dead_GrAll;
	int		_Dead_AnimeNo;

	//SEハンドル
	int		_Walk_SEHandle;
	int		_Attack_SEHandle;
};
namespace NInfo {
	/*----------忍者の各座標関係----------*/
	constexpr auto PositionX = 2800;			//横軸初期位置（足下が基準）
	constexpr auto PositionY = 2200;			//縦軸初期位置（足下が基準）
	constexpr auto GraphPointX = 0;				//X位置から描画点までの差分
	constexpr auto GraphPointY = -210;			//Y位置から描画点までの差分
	constexpr auto PositionHitX = -40;			//描画点から当たり判定左上座標までの差分
	constexpr auto PositionHitY = 70;			//描画点から当たり判定左上座標までの差分
	constexpr auto CollisionWidth = 80;			//当たり判定横幅
	constexpr auto CollisionHeight = 140;		//当たり判定縦幅

	/*----------各モーションの当たり判定関係----------*/
	constexpr auto PatrolWidth = 1000;			//索敵範囲当たり判定横幅
	constexpr auto PatrolHeight = 100;			//索敵範囲当たり判定縦幅
	constexpr auto ComingWidth = 200;			//攻撃発生範囲当たり判定横幅
	constexpr auto ComingHeight = 100;			//攻撃発生範囲当たり判定縦幅
	constexpr auto AttackWidth = 100;			//攻撃当たり判定横幅
	constexpr auto AttackHeight = 100;			//攻撃当たり判定縦幅

	/*----------パラメーター関係----------*/
	constexpr auto LifeMax = 1;					//体力
	constexpr auto Speed = 3;					//移動速度

	/*----------画像読み込み&アニメーション&判定フレーム関係----------*/
	//共通
	constexpr auto GraphWidth = 420;			//1枚当たりの画像サイズ（横）
	constexpr auto GraphHeight = 420;			//1枚当たりの画像サイズ（縦）
	constexpr auto GraphScale = 1.0;			//拡大率
	constexpr auto GraphAngle = 0;				//角度
	//待機
	constexpr auto Patrol_GraphName = "res/Ninja/N_Stand.png";	//画像ファイル名
	constexpr auto Patrol_AnimeMax = 1;			//全ての画像枚数
	constexpr auto Patrol_WidthCount = 1;		//横の画像枚数
	constexpr auto Patrol_HeightCount = 1;		//縦の画像枚数
	constexpr auto AnimeSpeed_Patrol = 5;		//各状態アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto Patrol_Frame = 120;			//巡回全フレーム
	//移動
	constexpr auto Coming_GraphName = "res/Ninja/N_Walk.png";	//画像ファイル名
	constexpr auto Coming_AnimeMax = 4;			//全ての画像枚数
	constexpr auto Coming_WidthCount = 4;		//横の画像枚数
	constexpr auto Coming_HeightCount = 1;		//縦の画像枚数	
	constexpr auto AnimeSpeed_Coming = 10;		//各状態アニメスピード（何フレームごとに画像を切り替えるか）
	//攻撃
	constexpr auto Attack_GraphName = "res/Ninja/N_Attack.png";	//画像ファイル名
	constexpr auto Attack_AnimeMax = 3;			//全ての画像枚数
	constexpr auto Attack_WidthCount = 3;		//横の画像枚数
	constexpr auto Attack_HeightCount = 1;		//縦の画像枚数
	constexpr auto AnimeSpeed_Attack = 15;		//各状態アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto Attack_Frame = 40;			//攻撃全フレーム
	constexpr auto ABegin_Frame = 30;			//攻撃発生フレーム
	constexpr auto AEnd_Frame = 10;				//攻撃終了フレーム
	//死亡
	constexpr auto Dead_GraphName = "res/Ninja/N_Dead.png";		//画像ファイル名
	constexpr auto Dead_AnimeMax = 1;			//全ての画像枚数
	constexpr auto Dead_WidthCount = 1;			//横の画像枚数
	constexpr auto Dead_HeightCount = 1;		//縦の画像枚数
	constexpr auto AnimeSpeed_Dead = 60;		//各状態アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto Dead_Frame = 50;				//死亡全フレーム
	/*----------SE関係----------*/
	constexpr auto Walk_SE = "se/Footstep.wav";			//巡回
	constexpr auto Attack_SE = "se/slash3.wav";			//攻撃
}