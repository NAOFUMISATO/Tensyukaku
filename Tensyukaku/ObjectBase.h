#pragma once
#include "HitBox.h"
#include <vector>
#include "Math.h"
#include <utility>
#include <tuple>
#include <unordered_map>

class Game;
// オブジェクトクラス
class ObjectBase {
public:
	ObjectBase();
	~ObjectBase();
	//オブジェクトの種類列挙
	enum class OBJECTTYPE {
		PLAYER, ENEMY,UI,PARTICLE,STAIR,
		MIDDLEATTACK, LOWATTACK, KICK, IAI,
		BUSHIPATROL, BUSHICOMING, BUSHIATTACK,
		NINJAPATROL, NINJACOMING, NINJAATTACK,
		SHIELDERPATROL,SHIELDERCOMING,SHIELDERATTACK,SHIELD,
		SCENARIO,ENEMYSPAWN
	};
	virtual OBJECTTYPE	GetObjType() = 0;

	virtual	void	Init();
	virtual	void	Process(Game& g);
	virtual	void	Draw(Game& g);
	virtual	bool	IsHit(ObjectBase& o);
	virtual	void	Delete(Game& g) {};

	
	int		GetX() { return _x; }
	int		GetY() { return _y; }
	int		GetGX() { return _gx; }
	int		GetGY() { return _gy; }
	int		GetW() { return _w; }
	int		GetH() { return _h; }
	int		GetHitW() { return _hit_w; }
	int		GetHitH() { return _hit_h; }
	int		GetHitX() { return _hit_x; }
	int		GetHitY() { return _hit_y; }
	bool	GetFlip() { return _isFlip; }
	HitBox	GetHB() { return { _x,_y,_gx,_gy,_hit_x,_hit_y,_hit_w,_hit_h }; }
	Vector2 GetPosition() { return _Position; }		//座標の取得

	void	SetPosition(int x, int y) { _x = x; _y = y; }
	void	SetX(int x) { _x = x; }
	void	SetY(int y) { _y = y; }
	void	SetFlip(bool isflip) { _isFlip = isflip; }
	
protected:
	Vector2 _Position;	// 位置ベクトル
	int		_GrHandle;	// 画像ハンドル
	std::unordered_map<std::string, std::vector<int>> _GrAll;	//全ての画像ハンドルマップ
	std::unordered_map<std::string, int> _Anime;				//アニメーションマップ
	std::unordered_map<std::string, int> _Se;					//SEマップ
	int		_x, _y;		// 座標（基準位置）
	int		_gx, _gy;	// 基準位置から描画時の差分
	int		_w, _h;		// 大きさ
	int		_Life;		// 体力
	int		_Spd;		// 移動速度
	bool	_isFlip;	//反転判定
	int		_hit_x, _hit_y;				//描画点から左上座標までの差分
	int		_hit_w, _hit_h;				//当たり判定の幅
	std::pair <int, int>_hit_judge;		//当たり判定用変数
	std::pair <double, double>_Drg;		//DrawRotaGraph用変数
	int		_Dalpha;					//デバック用矩形透明度
	bool	_Fill;						//デバッグ用矩形塗りつぶしフラグ
	std::tuple<int, int,int>_Color;		//デバック用矩形カラー
	int		_Cnt;						//動作カウンタ
	int		_Action_Cnt;				//アクション経過時間保存変数
	
};
