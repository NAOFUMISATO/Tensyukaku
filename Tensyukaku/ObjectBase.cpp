/*
** �I�u�W�F�N�g
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
	 //�d�͏������s��
	//_g += 1;			// �L�����́A�d�͂ɂ������l��傫������
	//_y += _g;			// �d�͂ɂ������l�̕������ړ�����
	//_stand = 0;			// ���ɓ������ĂȂ����Ƃ�O��ɁA���t���O���Z�b�g

	//// �㉺�̓����蔻��
	//if (g.GetChip()->IsHit(*this, 0, _g) != 0)
	//{

	//	if (_g > 0) // ���������B���������̂͏����H�i�d�͒l�̓v���X���������H�j
	//	{
	//		_stand = 1;	//���ɓ��������̂Ńt���O�Z�b�g
	//	}
	//	_g = 0;		// �d�͉����l�����Z�b�g
	//}
	
}

void ObjectBase::Draw(Game& g) {
	// �J�������猩�����W�ɕύX�i���[���h���W���r���[���W�j
	auto GC = g.GetChip();
	auto x = _x + _gx - GC->GetscrX();
	auto y = _y + _gy - GC->GetscrY();
	DrawRotaGraph(x, y, GraphScale, GraphAngle, _GrHandle, true, _isFlip);

#ifdef _DEBUG
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// �������`��w��
	DrawBox(x + _hit_x, y + _hit_y, x + _hit_x + _hit_w, y + _hit_y + _hit_h, GetColor(255, 0, 0), FALSE);	// �������̐Ԃœ����蔻��`��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// �s�����`��w��
#endif
}
bool ObjectBase::IsHit(ObjectBase& o) {
	// ���̃I�u�W�F�N�g�ƁA�ʃI�u�W�F�N�go���Ax,y,w,h�Ŕ�r����
	if (_x +_gx+ _hit_x < o._x +o._hit_x + o._hit_w && o._x + o._hit_x < _x +_gx+ _hit_x + _hit_w		// x�����̔���
		&& _y +_gy+ _hit_y < o._y +o._gy + o._hit_y + o._hit_h && o._y+ o._gy+ o._hit_y < _y+_gy + _hit_y + _hit_h	// y�����̔���
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
