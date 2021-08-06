/*
** �I�u�W�F�N�g
*/

#include "DxLib.h"
#include "ObjectBase.h"
#include "Game.h"
using namespace Tsk;
ObjectBase::ObjectBase()
{
	Init();
}

ObjectBase::~ObjectBase()
{
}

void ObjectBase::Init()
{
	_Cnt = 0;
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
	//// �d�͏������s��
	//_g += 1;			// �L�����́A�d�͂ɂ������l��傫������
	//_y += _g;			// �d�͂ɂ������l�̕������ړ�����
	//_stand = 0;			// ���ɓ������ĂȂ����Ƃ�O��ɁA���t���O���Z�b�g

	//// �㉺�̓����蔻��
	//if (g.GetChips().IsHit(*this, 0, _g) != 0)
	//{
	//	
	//	if (_g > 0) // ���������B���������̂͏����H�i�d�͒l�̓v���X���������H�j
	//	{
	//		_stand = 1;	//���ɓ��������̂Ńt���O�Z�b�g
	//	}
	//	_g = 0;		// �d�͉����l�����Z�b�g
	//}
	
}

void ObjectBase::Draw(Game& g) {
}
bool ObjectBase::IsHitCO(ObjectBase& o) {
	// ���̃I�u�W�F�N�g�ƁA�ʃI�u�W�F�N�go���Ax,y,w,h�Ŕ�r����
	if (_x +_gx+ _hit_x < o._x +o._hit_x + o._hit_w && o._x + o._hit_x < _x +_gx+ _hit_x + _hit_w		// x�����̔���
		&& _y +_gy+ _hit_y < o._y + o._hit_y + o._hit_h && o._y+ o._hit_y < _y+_gy + _hit_y + _hit_h	// y�����̔���
		&& _hit_noCnt == 0 && o._hit_noCnt == 0													// 2�̃I�u�W�F�N�g�̓����蔻��J�E���^��0�ł���
		&& _hit_sub == 1 && o._hit_main == 1													// �����Ƒ���̓����蔻��t���O
		)
	{
		// 2��box�͓������Ă���
		return true;
	}

	// 2��box�͓������Ă��Ȃ�
	return false;
}
bool ObjectBase::IsHitOC(ObjectBase& o) {
	// ���̃I�u�W�F�N�g�ƁA�ʃI�u�W�F�N�go���Ax,y,w,h�Ŕ�r����
	if (_x + _hit_x < o._x +o._gx + o._hit_x + o._hit_w && o._x +o._gx + o._hit_x < _x + _hit_x + _hit_w		// x�����̔���
		&& _y + _hit_y < o._y +o._gy + o._hit_y + o._hit_h && o._y + o._gy + o._hit_y < _y + _hit_y + _hit_h	// y�����̔���
		&& _hit_noCnt == 0 && o._hit_noCnt == 0													// 2�̃I�u�W�F�N�g�̓����蔻��J�E���^��0�ł���
		&& _hit_sub == 1 && o._hit_main == 1													// �����Ƒ���̓����蔻��t���O
		)
	{
		// 2��box�͓������Ă���
		return true;
	}

	// 2��box�͓������Ă��Ȃ�
	return false;
}
bool ObjectBase::IsHitOO(ObjectBase& o) {// ���̃I�u�W�F�N�g�ƁA�ʃI�u�W�F�N�go���Ax,y,w,h�Ŕ�r����
	if (_x + _hit_x < o._x + o._hit_x + o._hit_w && o._x + o._hit_x < _x + _hit_x + _hit_w		// x�����̔���
		&& _y + _hit_y < o._y + o._hit_y + o._hit_h && o._y + o._hit_y < _y + _hit_y + _hit_h	// y�����̔���
		&& _hit_noCnt == 0 && o._hit_noCnt == 0													// 2�̃I�u�W�F�N�g�̓����蔻��J�E���^��0�ł���
		&& _hit_sub == 1 && o._hit_main == 1													// �����Ƒ���̓����蔻��t���O
		)
	{
		// 2��box�͓������Ă���
		return true;
	}
	// 2��box�͓������Ă��Ȃ�
	return false;
}