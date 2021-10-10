/*****************************************************************//**
 * \file   ModeBase.cpp
 * \brief  ���[�h�p�x�[�X�N���X
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModeBase.h"

namespace{
	constexpr auto RED = 0;
	constexpr auto GREEN = 1;
	constexpr auto BLUE = 2;
}

ModeBase::ModeBase() {
	//�e������
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
}

ModeBase::~ModeBase() {
}

/*-----������-----*/
bool	ModeBase::Initialize(Game& g) {
	_grhandle = -1;					//�摜�n���h��������
	_cnt = 0;								//����J�E���^0�ŏ�����
	_pal = 255;							//�����x�̏�����
	_trans_flag = false;			//�w�i���߃t���O���U�ŏ�����
	_drg = std::make_pair(1.0, 0.0);						//DrawRotaGraph�p�A�g�嗦�y�ъp�x�̏�����
	_rgb = std::make_tuple(255,255,255);		//SetDrawBright�p�ARGB�̏�����
	return true;
}

bool	ModeBase::Terminate(Game& g) {
	return true;
}
/*-----�X�V-----*/
bool	ModeBase::Process(Game& g){
	_cnt++;						//���t���[���P������
	return	true;
}
/*-----�`��-----*/
bool	ModeBase::Draw(Game& g)
{
	auto scale = _drg.first;
	auto angle = _drg.second;
	int& re = std::get<RED>(_rgb);
	int& gr = std::get<GREEN>(_rgb);
	int& bl = std::get<BLUE>(_rgb);
	SetDrawBright(re,gr,bl);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _pal);
	DrawRotaGraph(_x, _y, scale, angle,_grhandle, _trans_flag,FALSE);
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
