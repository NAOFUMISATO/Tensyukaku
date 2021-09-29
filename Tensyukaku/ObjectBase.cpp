/*
** �I�u�W�F�N�g
*/

#include "DxLib.h"
#include "ObjectBase.h"
#include "Game.h"
namespace {
	constexpr auto RED = 0;
	constexpr auto GREEN = 1;
	constexpr auto BLUE = 2;
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
	_ostate = OBJECTSTATE::ALLIBE;
	_grhandle = -1;	
	_cnt = 0;
	_hit_judge.first = 1;
	_hit_judge.second = 1;
	_drg.first = 1.0;
	_drg.second = 0.0;
	_debug_color = std::make_tuple(255,0,255);
	_debug_alpha = 128;
	_debug_fill = false;
	_bosseventA_flag=false;
	_bosseventB_flag=false;
	_draw_flag = false;
	_dx = 0;
	_dy = 0;
}

void ObjectBase::Process(Game& g)
{
	if (_dx > 0-400 && _dx < SCREEN_W+400 &&_dy>0-400 && _dy < SCREEN_H+400) {
		_draw_flag =true;
	}
	else {
		_draw_flag = false;
	}
	++_cnt;
}

void ObjectBase::Draw(Game& g) {
	
		auto GC = g.GetChip();
		auto x = _x + _gx - GC->GetscrX();
		auto y = _y + _gy - GC->GetscrY();
		auto scale = _drg.first;
		auto angle = _drg.second;
		_before_x = _x + _gx;
		_before_y = _y + _gy;
		_dx = x;
		_dy = y;
		if (_draw_flag == true) {
		DrawRotaGraph(x,y, scale, angle, _grhandle, true, _isflip);
		}
#ifdef _DEBUG
		int& re = std::get<RED>(_debug_color);
		int& gr = std::get<GREEN>(_debug_color);
		int& bl = std::get<BLUE>(_debug_color);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, _debug_alpha);		// �������`��w��
		DrawBox(x + _hit_x, y + _hit_y, x + _hit_x + _hit_w, y + _hit_y + _hit_h, GetColor(re, gr, bl), _debug_fill);	// �������̐Ԃœ����蔻��`��
#endif
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// �s�����`��w��
	
}
bool ObjectBase::IsHit(ObjectBase& o) {
	// ���̃I�u�W�F�N�g�ƁA�ʃI�u�W�F�N�go���Ax,y,w,h�Ŕ�r����
	if (_x +_gx+ _hit_x < o._x +o._hit_x + o._hit_w && o._x + o._hit_x < _x +_gx+ _hit_x + _hit_w		// x�����̔���
		&& _y +_gy+ _hit_y < o._y +o._gy + o._hit_y + o._hit_h && o._y+ o._gy+ o._hit_y < _y+_gy + _hit_y + _hit_h	// y�����̔���
		&& _hit_judge.second == 1 && o._hit_judge.first == 1													// �����Ƒ���̓����蔻��t���O
		)
	{
		// 2��box�͓������Ă���
		return true;
	}

	// 2��box�͓������Ă��Ȃ�
	return false;
}
