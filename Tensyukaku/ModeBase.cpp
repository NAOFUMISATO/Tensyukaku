#include <DxLib.h>
#include "ModeBase.h"

namespace{
	constexpr auto RED = 0;
	constexpr auto GREEN = 1;
	constexpr auto BLUE = 2;
}
ModeBase::ModeBase() {
	_szName = "";
	_uid = 1;
	_layer = 0;

	_cntMode = 0;
	_tmMode = 0;
	_tmStep = 0;
	_tmModeBase = 0;
	_tmPauseBase = 0;
	_tmPauseStep = 0;
	_tmOldFrame = 0;

	SetCallPerFrame(1);
	SetCallOfCount(1);
}

ModeBase::~ModeBase() {
}


// ModeServer�ɐڑ����AProcess()�̑O�Ɉ�x�����Ă΂��
bool	ModeBase::Initialize(Game& g) {
	_GrHandle = -1;
	_Cnt = 0;
	_Pal = 255;
	_Trans_Flag = true;
	_drg = std::make_pair(1.0, 0.0);
	_rgb = std::make_tuple(255,255,255);
	return true;
}

// ModeServer����폜�����ہA��x�����Ă΂��
bool	ModeBase::Terminate(Game& g) {

	return true;
}


// --------------------------------------------------------------------------
/// @brief ���t���[���Ă΂��B���������L�q
// --------------------------------------------------------------------------
bool	ModeBase::Process(Game& g)
{
	_Cnt++;
	return	true;
}

// --------------------------------------------------------------------------
/// @brief ���t���[���Ă΂��B�`�敔���L�q
// --------------------------------------------------------------------------
bool	ModeBase::Draw(Game& g)
{
	auto scale = _drg.first;
	auto angle = _drg.second;
	int& re = std::get<RED>(_rgb);
	int& gr = std::get<GREEN>(_rgb);
	int& bl = std::get<BLUE>(_rgb);
	SetDrawBright(re,gr,bl);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Pal);
	DrawRotaGraph(_x, _y, scale, angle,_GrHandle, _Trans_Flag,FALSE);
	SetDrawBright(255, 255, 255);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	return	true;
}

// ���Ԍo�߂�������
void ModeBase::StepTime(unsigned long tmNow) {
	// ���Ԍo�ߏ���
	if (_cntMode == 0) {
		_tmMode = 0;
		_tmStep = 0;
		_tmModeBase = tmNow;
		_tmPauseBase = 0;
		_tmPauseStep = 0;
	}
	else {
		_tmMode = tmNow - _tmModeBase + _tmPauseStep;
		_tmStep = tmNow - _tmOldFrame;
	}
	_tmOldFrame = tmNow;
}

// �J�E���g��i�߂�
void ModeBase::StepCount() {
	_cntMode++;
}
