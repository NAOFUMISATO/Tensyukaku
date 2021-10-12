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
//�R���X�g���N�^
ModeBase::ModeBase() {
	//�������i���[�h�[�T�[�o�[�p�j
	_sz_name = "";
	_uid = 1;
	_layer = 0;

	_cnt_mode = 0;
	_tm_mode = 0;
	_tm_step = 0;
	_tm_mode_base = 0;
	_tm_pause_base = 0;
	_tm_pause_step = 0;
	_tm_old_frame = 0;
}
//�f�X�g���N�^
ModeBase::~ModeBase() {
}

/*-----������-----*/
bool	ModeBase::Initialize(Game& g) {
	_grhandle = -1;					//�摜�n���h��������
	_cnt = 0;								//����J�E���^0�ŏ�����
	_pal = 255;							//�����x�̏�����
	_trans_flag = false;			//�w�i���߃t���O���U�ŏ�����
	_drg = std::make_pair(1.0, 0.0);						//DrawRotaGraph�p�A�g�嗦�y�ъp�x�̏�����
	_rgb = std::make_tuple(255,255,255);			//SetDrawBright�p�ARGB�̏�����
	return true;
}
/*-----�I��------*/
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
	if (_cnt_mode == 0) {
		_tm_mode = 0;
		_tm_step = 0;
		_tm_mode_base = tmNow;
		_tm_pause_base = 0;
		_tm_pause_step = 0;
	}
	else {
		_tm_mode = tmNow - _tm_mode_base + _tm_pause_step;
		_tm_step = tmNow - _tm_old_frame;
	}
	_tm_old_frame = tmNow;
}

// �J�E���g��i�߂�
void ModeBase::StepCount() {
	_cnt_mode++;
}
