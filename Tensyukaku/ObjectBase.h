#pragma once
#include "HitBox.h"
#include <vector>
namespace Tsk {
	class Game;
	// オブジェクトクラス
	class ObjectBase {
	public:
		ObjectBase();
		~ObjectBase();
		//オブジェクトの種類列挙
		enum class OBJECTTYPE {
			PLAYER, ENEMY, MIDDLEATTACK, LOWATTACK
		};
		virtual OBJECTTYPE	GetObjType() = 0;

		virtual	void	Init();
		virtual	void	Process(Game& g);
		virtual	void	Draw(Game& g);
		virtual	bool	IsHit(ObjectBase& o);
		virtual	void	Damage(Game& g) {};

		void	SetPosition(int x, int y) { _x = x; _y = y; }
		int		GetX() { return _x; }
		int		GetY() { return _y; }
		int		GetW() { return _w; }
		int		GetH() { return _h; }
		HitBox	GetHB() { return { _x,_y,_hit_x,_hit_y,_hit_w,_hit_h }; }
		void	SetX(int x) { _x = x; }
		void	SetY(int y) { _y = y; }

	protected:
		int		_x, _y;		// 座標（基準位置）
		int		_gx, _gy;	// 基準位置から描画時の差分
		int		_w, _h;		// 大きさ
		int		_Spd;		// 移動速度
		int		_g;			// 重力加速値
		int		_stand;		// 床フラグ。着地していたら1
		bool	_isFlip;	//反転判定
		// 当たり判定用（座標_x,_y位置からの差分）
		int		_hit_x, _hit_y;
		int		_hit_w, _hit_h;
		int		_hit_noCnt;	// カウンタが1以上の場合は当たり判定しない
		int		_hit_main;	// 攻撃側の場合に当たり判定するなら1
		int		_hit_sub;	// ダメージ側の場合に当たり判定するなら1
		int		_Cnt;		// 動作カウンタ


	};
}