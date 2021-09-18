#pragma once
#include "ObjectBase.h"

class PoisonNinja :public  ObjectBase {
public:
	PoisonNinja(int x,int y,bool flip);
	~PoisonNinja();

	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::POISONNINJA; }
	void Init();
	void Process(Game& g)override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
private:
	//敵の状態列挙
	enum class ENEMYSTATE{
	APPEAR,PATROL,POISING
	};
	void Appear(Game& g);
	void Patrol(Game& g);
	void Poising(Game& g);

/*-----メンバ変数-----*/
	ENEMYSTATE _State;
	int _Appear_y;
	bool _Keep_Flag;
};


namespace PNInfo{
/*----------毒液忍者の各座標関係----------*/
constexpr auto GRAPHPOINT_X = 0;			//X位置から描画点までの差分
constexpr auto GRAPHPOINT_Y = -315;			//Y位置から描画点までの差分
/*----------各モーションの当たり判定関係----------*/
constexpr auto PATROL_WIDTH = 500;			//索敵範囲当たり判定横幅
constexpr auto PATROL_HEIGHT = 500;			//索敵範囲当たり判定縦幅
constexpr auto POISINGCANCEL_WIDTH = 500;	//毒液垂らし中止当たり判定横幅
constexpr auto POISINGCANCEL_HEIGHT = 500;	//毒液垂らし中止当たり判定縦幅

/*----------画像読み込み&アニメーション&判定フレーム関係----------*/
//共通
constexpr auto GRAPH_WIDTH = 630;			//1枚当たりの画像サイズ（横）
constexpr auto GRAPH_HEIGHT = 630;			//1枚当たりの画像サイズ（縦）
//出現
constexpr auto APPEAR_GRAPHNAME = "res/Gimik/N_Poison_Stand.png";	//画像ファイル名
constexpr auto APPEAR_ANIMEMAX = 1;			//全ての画像枚数
constexpr auto APPEAR_WIDTHCOUNT = 1;		//横の画像枚数
constexpr auto APPEAR_HEIGHTCOUNT = 1;		//縦の画像枚数
constexpr auto ANIMESPEED_APPEAR = 60;		//アニメスピード（何フレームごとに画像を切り替えるか）
constexpr auto FADEIN_SPEED = 4;			//アッパー時のフェードインスピード
constexpr auto APPEAR_ALLFRAME = 60;		//出現全フレーム
//索敵
constexpr auto PATROL_GRAPHNAME = "res/Gimik/N_Poison_Stand.png";	//画像ファイル名
constexpr auto PATROL_ANIMEMAX = 1;			//全ての画像枚数
constexpr auto PATROL_WIDTHCOUNT = 1;		//横の画像枚数
constexpr auto PATROL_HEIGHTCOUNT = 1;		//縦の画像枚数
constexpr auto ANIMESPEED_PATROL = 60;		//アニメスピード（何フレームごとに画像を切り替えるか）
constexpr auto PATROL_TURNFRAME = 120;		//索敵時の振り向きフレーム
//毒液垂らし
constexpr auto POISING_GRAPHNAME = "res/Gimik/N_Poison.png";	//画像ファイル名
constexpr auto POISING_ANIMEMAX = 2;		//全ての画像枚数
constexpr auto POISING_WIDTHCOUNT = 2;		//横の画像枚数
constexpr auto POISING_HEIGHTCOUNT = 1;		//縦の画像枚数
constexpr auto ANIMESPEED_POISING = 40;		//各状態アニメスピード（何フレームごとに画像を切り替えるか）
constexpr auto POISING_ANIMEFRAME = POISING_ANIMEMAX * ANIMESPEED_POISING;		//アニメーションフレーム（全ての画像枚数×アニメスピード）
constexpr auto POISING_ALLFRAME = 230;		//毒液垂らし全フレーム
constexpr auto POISON_SPAWN_X = 170;		//忍者からの毒液が染み込む座標へのX差分
constexpr auto POISON_SPAWN_Y = 80;			//忍者からの毒液が染み込む座標へのY差分
//消去
constexpr auto DELETE_HEIGHT = 500;			//毒液忍者が消えるYの移動量
constexpr auto FADEOUT_SPEED = 10;			//フェードスピード
}