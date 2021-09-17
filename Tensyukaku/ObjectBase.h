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
	//オブジェクトの状態列挙
	enum class OBJECTSTATE {
		ALLIBE,DEAD
	};
	//オブジェクトの種類列挙
	enum class OBJECTTYPE {
		TITLELOGO,GAMESTART, EXPLAIN,GAMEEND, CURSOR,
		OVERLOGO,OVERRETRY,OVERGOTITLE,OVERBLACK,OVERCURSOR,
		PLAYER, ENEMY,BOSS, UI, PARTICLE,
		MIDDLEATTACK, LOWATTACK, KICK, IAI,SPECIAL,
		PRIVATECOLLISION,BUSHIATTACK,NINJAATTACK,KUNAI,SHIELDERATTACK,SHIELD,
		STAIR,BOSSSTAIR, RESTPOINT,POISONNINJA, POISON,ANDON,FLAME, SPAWNBLOCK, EVENTBLOCK, RECOVERYBLOCK,CPOINTBLOCK,BOSSEVENTBLOCK,FLAMEBLOCK,BOSSSPAWN
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
	int		GetHp() { return _Life; }
	int		GetGauge() { return _Iai_Gauge; }
	bool	GetFlip() { return _isFlip; }
	HitBox	GetHB() { return { _x,_y,_gx,_gy,_hit_x,_hit_y,_hit_w,_hit_h }; }
	Vector2 GetPosition() { return _Position; }		//座標の取得
	bool isDead() const { return _OState == OBJECTSTATE::DEAD; }

	void	SetGauge(int ig) {_Iai_Gauge=ig; }
	void	SetPosition(int x, int y) { _x = x; _y = y; }
	void	SetX(int x) { _x = x; }
	void	SetY(int y) { _y = y; }
	void	SetFlip(bool isflip) { _isFlip = isflip; }
	void	SetBEventA(bool beventAflag) { _BEventA_Flag =beventAflag; }
	void	SetBEventB(bool beventBflag) { _BEventB_Flag =beventBflag; }
	
	
protected:
	Vector2 _Position;	// 位置ベクトル
	OBJECTSTATE _OState;// オブジェクトの状態列挙変数
	int		_GrHandle;	// 画像ハンドル
	std::unordered_map<std::string, std::vector<int>> _GrAll;	//全ての画像ハンドルマップ
	std::unordered_map<std::string, int> _Anime;				//アニメーションマップ
	std::unordered_map<std::string, int> _Se;					//SEマップ
	std::unordered_map<std::string, int> _Vpal;					//BGMのボリューム設定マップ
	int		_x, _y;		// 座標（基準位置）
	int		_gx, _gy;	// 基準位置から描画時の差分
	int		_w, _h;		// 大きさ
	int		_Life;		// 体力
	int		_Spd;		// 移動速度
	bool	_isFlip;	//　反転判定
	int		_Alpha;		//　透明度
	int		_Iai_Gauge;	// 居合ゲージ
	int		_hit_x, _hit_y;				//描画点から左上座標までの差分
	int		_hit_w, _hit_h;				//当たり判定の幅
	bool	_Draw_Flag;					//XY座標が画面内ならば描画するフラグ
	int		_Dx;						//描画判定用変数
	int		_Dy;						//描画判定用変数
	std::pair <int, int>_hit_judge;		//当たり判定用変数
	std::pair <double, double>_drg;		//DrawRotaGraph用変数
	int		_Dalpha;					//デバック用矩形透明度
	bool	_Fill;						//デバッグ用矩形塗りつぶしフラグ
	std::tuple<int, int,int>_Color;		//デバック用矩形カラー
	int		_Cnt;						//動作カウンタ
	int		_Action_Cnt;				//アクション経過時間保存変数
	int		_Before_x;					//前回のX座標保存変数
	int		_Before_y;					//前回のY座標保存変数
	bool	_BEventA_Flag;				//ボスイベントAフラグ
	bool	_BEventB_Flag;				//ボスイベントBフラグ
	
};
