/*
** オブジェクト
*/

#include "DxLib.h"
#include "ObjectBase.h"
#include "Game.h"
namespace {
	constexpr auto GraphScale = 1.0;
	constexpr auto GraphAngle = 0;
}

ObjectBase::ObjectBase()
{
	Init();
}

ObjectBase::~ObjectBase()
{
}

void ObjectBase::Init()
{
	_GrHandle = -1;
	_g = 0;
	_Cnt = 0;
	_stand = 0;
	_hit_noCnt = 0;
	_hit_main = 1;
	_hit_sub = 1;
}

void ObjectBase::Process(Game& g)
{
	if (_hit_noCnt > 0)
	{
		_hit_noCnt--;
	}
	++_Cnt;
	 //重力処理を行う
	//_g += 1;			// キャラの、重力による加速値を大きくする
	//_y += _g;			// 重力による加速値の分だけ移動する
	//_stand = 0;			// 床に当たってないことを前提に、床フラグリセット

	//// 上下の当たり判定
	//if (g.GetChip()->IsHit(*this, 0, _g) != 0)
	//{

	//	if (_g > 0) // 当たった。当たったのは床か？（重力値はプラスだったか？）
	//	{
	//		_stand = 1;	//床に当たったのでフラグセット
	//	}
	//	_g = 0;		// 重力加速値をリセット
	//}
	
}

void ObjectBase::Draw(Game& g) {
	// カメラから見た座標に変更（ワールド座標→ビュー座標）
	auto GC = g.GetChip();
	auto x = _x + _gx - GC->GetscrX();
	auto y = _y + _gy - GC->GetscrY();
	DrawRotaGraph(x, y, GraphScale, GraphAngle, _GrHandle, true, _isFlip);

#ifdef _DEBUG
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// 半透明描画指定
	DrawBox(x + _hit_x, y + _hit_y, x + _hit_x + _hit_w, y + _hit_y + _hit_h, GetColor(255, 0, 0), FALSE);	// 半透明の赤で当たり判定描画
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// 不透明描画指定
#endif
}
bool ObjectBase::IsHit(ObjectBase& o) {
	// このオブジェクトと、別オブジェクトoを、x,y,w,hで比較する
	if (_x +_gx+ _hit_x < o._x +o._hit_x + o._hit_w && o._x + o._hit_x < _x +_gx+ _hit_x + _hit_w		// x方向の判定
		&& _y +_gy+ _hit_y < o._y +o._gy + o._hit_y + o._hit_h && o._y+ o._gy+ o._hit_y < _y+_gy + _hit_y + _hit_h	// y方向の判定
		&& _hit_noCnt == 0 && o._hit_noCnt == 0													// 2つのオブジェクトの当たり判定カウンタが0である
		&& _hit_sub == 1 && o._hit_main == 1													// 自分と相手の当たり判定フラグ
		)
	{
		// 2つのboxは当たっている
		return true;
	}

	// 2つのboxは当たっていない
	return false;
}
