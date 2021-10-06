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
		TITLELOGO,GAMESTART, EXPLAIN,GAMEEND,CREDIT, CURSOR,
		PLAYER, ENEMY,BOSS, UI, PARTICLE,EFECT,
		MIDDLEATTACK, LOWATTACK, KICK, IAI,SPECIAL,
		PRIVATECOLLISION,BUSHIATTACK,NINJAATTACK,KUNAI,SHIELDERATTACK,SHIELD, LANCERATTACK,BUSYOATTACK,ZYOUNINATTACK,
		STAIR,BOSSSTAIR, RESTPOINT,POISONNINJA,POISON,ANDON,FLAME, MUGENANDON,MUGENFLAME,SPAWNBLOCK, EVENTBLOCK, RECOVERYBLOCK,CPOINTBLOCK,BOSSEVENTBLOCK,FLAMEBLOCK, TUTORIALBOARD,BOSSSPAWN
	};
	virtual OBJECTTYPE	GetObjType() = 0;

	virtual	void	Init();										//初期化
	virtual	void	Process(Game& g);				//処理
	virtual	void	Draw(Game& g);					//描画
	virtual	bool IsHit(ObjectBase& o);			//当たり判定の処理
	virtual	void	Delete(Game& g) {};				//オブジェクトの消去
	//各ゲッター関数
	int		GetX() { return _x; }
	int		GetY() { return _y; }
	int		GetHp() { return _life; }
	int		GetGauge() { return _iai_gauge; }
	int		GetSpd() { return _spd; }
	int		GetSort() { return _sort; }
	bool	GetFlip() { return _isflip; }
	HitBox	GetHB() { return { _x,_y,_gx,_gy,_hit_x,_hit_y,_hit_w,_hit_h }; }
	Vector2 GetPosition() { return _position; }
	
	//各セッター関数
	void	SetGauge(int ig) {_iai_gauge=ig; }
	void	SetPosition(int x, int y) { _x = x; _y = y; }
	void	SetX(int x) { _x = x; }
	void	SetY(int y) { _y = y; }
	void	SetFlip(bool isflip) { _isflip = isflip; }
	void	SetBEventA(bool beventAflag) { _bosseventA_flag =beventAflag; }
	void	SetBEventB(bool beventBflag) { _bosseventB_flag =beventBflag; }
	
	
protected:
	Vector2 _position;	// 位置ベクトル

	int		_grhandle;		// 画像ハンドル
	int		_sort;				//キャラ描画ソート用変数
	std::unordered_map<std::string, std::vector<int>> _grall;	//全ての画像ハンドルマップ
	std::unordered_map<std::string, int> _anime;						//アニメーションマップ
	std::unordered_map<std::string, int> _se;								//SEマップ
	std::unordered_map<std::string, int> _vpal;							//ボリュームマップ
	int		_x, _y;													// 座標（基準位置）
	int		_gx, _gy;												// 基準位置から描画時の差分
	int		_w, _h;													// 大きさ
	int		_life;													// 体力
	int		_spd;													// 移動速度
	bool	_isflip;													// 反転判定
	int		_alpha;												// 透明度
	int		_iai_gauge;										// 居合ゲージ
	int		_hit_x, _hit_y;										//描画点から左上座標までの差分
	int		_hit_w, _hit_h;									//当たり判定の幅
	bool	_draw_flag;										//XY座標が画面+400以内ならば描画するフラグ
	int		_dx;														//描画判定用変数
	int		_dy;														//描画判定用変数
	std::pair <int, int>_hit_judge;						//当たり判定用変数
	std::pair <double, double>_drg;				//DrawRotaGraph用変数
	int		_debug_alpha;									//デバック用矩形透明度
	bool	_debug_fill;										//デバッグ用矩形塗りつぶしフラグ
	std::tuple<int, int,int>_debug_color;			//デバック用矩形カラー
	int		_cnt;													//動作カウンタ
	int		_action_cnt;										//アクション経過時間保存変数
	int		_before_x;											//前回のX座標保存変数
	int		_before_y;											//前回のY座標保存変数
	bool	_bosseventA_flag;							//ボスイベントAフラグ
	bool	_bosseventB_flag;							//ボスイベントBフラグ
};
