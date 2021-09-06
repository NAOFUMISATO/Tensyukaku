/*
** �I�u�W�F�N�g
*/

#include "DxLib.h"
#include "ObjectBase.h"
#include "Game.h"
namespace {
	constexpr auto RED = 0;
	constexpr auto GREEN = 1;
	constexpr auto Blue = 2;
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
	_OState = OBJECTSTATE::ALLIBE;
	_GrHandle = -1;	
	_Cnt = 0;
	_hit_judge.first = 1;
	_hit_judge.second = 1;
	_drg.first = 1.0;
	_drg.second = 0.0;
	_Color = std::make_tuple(255,0,255);
	_Dalpha = 128;
	_Fill = false;
}

void ObjectBase::Process(Game& g)
{
	++_Cnt;
}

void ObjectBase::Draw(Game& g) {
	// �J�������猩�����W�ɕύX�i���[���h���W���r���[���W�j
	auto GC = g.GetChip();
	auto x = _x + _gx - GC->GetscrX();
	auto y = _y + _gy - GC->GetscrY();
	auto scale = _drg.first;
	auto angle = _drg.second;
	_Before_x = _x + _gx;
	_Before_y = _y + _gy;
	DrawRotaGraph(x, y, scale, angle, _GrHandle, true, _isFlip);
#ifdef _DEBUG
	//int& re = std::get<RED>(_Color);
	//int& gr = std::get<GREEN>(_Color);
	//int& bl = std::get<Blue>(_Color);
	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Dalpha);		// �������`��w��
	//DrawBox(x + _hit_x, y + _hit_y, x + _hit_x + _hit_w, y + _hit_y + _hit_h, GetColor(re, gr, bl), _Fill);	// �������̐Ԃœ����蔻��`��
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
