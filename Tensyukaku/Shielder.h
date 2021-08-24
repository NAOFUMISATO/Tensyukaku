#pragma once
#include "EnemyBase.h"

class Shielder :public EnemyBase {
public:
	Shielder();
	~Shielder();
	virtual ENEMYTYPE	GetEneType() { return ENEMYTYPE::SHIELDER; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;
private:
	void	ShieldDraw(Game& g);	//盾の処理
	void	Patrol(Game& g);		//巡回状態時の処理
	void	Coming(Game& g);		//追跡状態時の処理
	void	Attack(Game& g);		//攻撃状態時の処理
	void	GuardBreak(Game& g);	//盾崩し状態時の処理
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

	//被ダメ状態描画用変数
	std::vector<int>	_GuardBreak_GrAll;
	int		_GuardBreak_AnimeNo;

	//死亡状態描画用変数
	std::vector<int>	_Dead_GrAll;
	int		_Dead_AnimeNo;

	//SEハンドル
	int		_Walk_SEHandle;
	int		_Attack_SEHandle;

	bool	_Shield_Flag;		//盾の生存フラグ
	int		_Shield_Cnt;		
};

namespace SInfo {
	/*----------盾兵の各座標関係----------*/
	constexpr auto PositionX = 1000;			//横軸初期位置（足下が基準）
	constexpr auto PositionY = 2200;			//縦軸初期位置（足下が基準）
	constexpr auto GraphPointX = 0;				//X位置から描画点までの差分
	constexpr auto GraphPointY = -210;			//Y位置から描画点までの差分
	constexpr auto PositionHitX = -30;			//描画点から当たり判定左上座標までの差分
	constexpr auto PositionHitY = -90;			//描画点から当たり判定左上座標までの差分
	constexpr auto CollisionWidth = 60;			//当たり判定横幅
	constexpr auto CollisionHeight = 300;		//当たり判定縦幅
	
	/*----------各モーションの当たり判定関係----------*/
	constexpr auto PatrolWidth = 500;			//索敵範囲当たり判定横幅
	constexpr auto PatrolHeight = 100;			//索敵範囲当たり判定縦幅
	constexpr auto ComingWidth = 200;			//攻撃発生範囲当たり判定横幅
	constexpr auto ComingHeight = 100;			//攻撃発生範囲当たり判定縦幅
	constexpr auto AttackWidth = 150;			//攻撃当たり判定横幅
	constexpr auto AttackHeight = 100;			//攻撃当たり判定縦幅

	/*----------パラメーター関係----------*/
	constexpr auto LifeMax = 1;					//体力
	constexpr auto Speed = 1;					//移動速度

	/*----------画像読み込み&アニメーション&判定フレーム関係----------*/
	//共通
	constexpr auto GraphWidth = 540;			//1枚当たりの画像サイズ（横）
	constexpr auto GraphHeight = 420;			//1枚当たりの画像サイズ（縦）
	constexpr auto GraphScale = 1.0;			//拡大率
	constexpr auto GraphAngle = 0;				//角度
	//巡回
	constexpr auto Patrol_GraphName = "res/Shielder/T_Stand.png";	//画像ファイル名
	constexpr auto Patrol_AnimeMax = 1;			//全ての画像枚数
	constexpr auto Patrol_WidthCount = 1;		//横の画像枚数
	constexpr auto Patrol_HeightCount = 1;		//縦の画像枚数
	constexpr auto AnimeSpeed_Patrol = 5;		//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto Patrol_Frame = 180;			//巡回全フレーム
	//移動
	constexpr auto Coming_GraphName = "res/Shielder/T_Walk.png";	//画像ファイル名
	constexpr auto Coming_AnimeMax = 4;			//全ての画像枚数
	constexpr auto Coming_WidthCount = 4;		//横の画像枚数
	constexpr auto Coming_HeightCount = 1;		//縦の画像枚数	
	constexpr auto AnimeSpeed_Coming = 30;		//アニメスピード（何フレームごとに画像を切り替えるか）
	//攻撃
	constexpr auto Attack_GraphName = "res/Shielder/T_Attack.png";	//画像ファイル名
	constexpr auto Attack_AnimeMax = 3;			//全ての画像枚数
	constexpr auto Attack_WidthCount = 3;		//横の画像枚数
	constexpr auto Attack_HeightCount = 1;		//縦の画像枚数
	constexpr auto AnimeSpeed_Attack = 15;		//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto Attack_Frame = 40;			//攻撃全フレーム
	constexpr auto ABegin_Frame = 15;			//攻撃判定発生フレーム
	constexpr auto AEnd_Frame = 15;				//攻撃判定終了フレーム
	//被ダメ
	constexpr auto GuardBreak_GraphName = "res/Shielder/T_Damage.png";	//画像ファイル名
	constexpr auto GuardBreak_AnimeMax = 1;			//全ての画像枚数
	constexpr auto GuardBreak_WidthCount = 1;		//横の画像枚数
	constexpr auto GuardBreak_HeightCount = 1;		//縦の画像枚数
	constexpr auto AnimeSpeed_GuardBreak = 60;		//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto GuardBreak_Frame = 50;			//被ダメ全フレーム
	//死亡
	constexpr auto Dead_GraphName = "res/Shielder/T_Dead.png";		//画像ファイル名
	constexpr auto Dead_AnimeMax = 1;			//全ての画像枚数
	constexpr auto Dead_WidthCount = 1;			//横の画像枚数
	constexpr auto Dead_HeightCount = 1;		//縦の画像枚数
	constexpr auto AnimeSpeed_Dead = 60;		//アニメスピード（何フレームごとに画像を切り替えるか）
	constexpr auto Dead_Frame = 50;				//死亡全フレーム
	/*----------SE関係----------*/
	constexpr auto Walk_SE = "se/Footstep.wav";			//巡回
	constexpr auto Attack_SE = "se/slash3.wav";			//攻撃	

};