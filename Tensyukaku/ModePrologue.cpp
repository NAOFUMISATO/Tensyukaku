/*****************************************************************//**
 * \file   ModePrologue.cpp
 * \brief  �v�����[�O�N���X�i���[�h�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModePrologue.h"
#include "PrologueText.h"
#include "OverlayBlack.h"
#include "ModeGame.h"
#include "Game.h"
#include "ResourceServer.h"

using namespace ProInfo;
/*-----������-----*/
bool ModePrologue::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 1920;										//X���W������
	_y = 1080;										//Y���W�̏�����
	_pal = 0;											//�t�F�[�h�C�����Ă������߁A�����x�O�ŏ�����
	_GraphNo = 0;								//�V�[�g�ԍ��̏�����
	_mode_cnt = _cnt;						//�t���[���̏�����
	_grall["Prologue"].resize(BG_ANIMEMAX);
	ResourceServer::LoadDivGraph(BG_GRAPHNAME,BG_ANIMEMAX,BG_WIDTHCOUNT, BG_HEIGHTCOUNT,BG_GRAPH_WIDTH, BG_GRAPH_HEIGHT,_grall["Prologue"].data());		//�摜�ǂݍ���
	PlaySoundMem(g.GetBgm()["Prologue"], DX_PLAYTYPE_LOOP, true);				//BGM�Đ�
	return true;
}
/*-----�I��------*/
bool ModePrologue::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}
/*-----�X�V-----*/
bool ModePrologue::Process(Game& g) {
	base::Process(g);
	auto frame = _cnt - _mode_cnt;
	_grhandle = _grall["Prologue"][_anime["Prologue"]];
	_anime["Prologue"] = _GraphNo;
	/*----------�t�F�[�h�֌W----------*/
	if (frame < BG1_FADEIN_FRAME) {
		_pal += BG1_FADEIN_SPEED;
	}
	if (frame == BG1_FADEIN_FRAME) {
		_pal = 255;
		auto pt = new PrologueText();				//�v�����[�O�e�L�X�g����
		g.GetMS()->Add(pt, 1, "PText");
	}
	if (frame >= BG1_FADEOUT_BEGINFRAME&& BG1_FADEOUT_ENDFRAME>frame) {
		_pal -= BG1_FADEOUT_SPEED;
	}
	if (frame == BG1_FADEOUT_ENDFRAME) {
		_pal = 0;
		_GraphNo = 1;				//�V�[�g�ԍ��ύX
	}
	if (frame >= BG2_FADEIN_BEGINFRAME&& BG2_FADEIN_ENDFRAME>frame) {
		_pal += BG2_FADEIN_SPEED;
	}
	if (frame == BG2_FADEIN_ENDFRAME) {
		_pal = 255;
	}
	auto fadeoutendframe = 85;
	//�v�����[�O�I����̏���
	if (frame == PROLOGUE_FADEOUT_FRAME) {
		auto ol = new OverlayBlack();								//�t�F�[�h�A�E�g�̂��߂́A�I�[�o�[���C�u���b�N���[�h����
		ol->SetFade(fadeoutendframe, 480, 600, 4);	//�t�F�[�h���Ԃ̐ݒ�
		g.GetMS()->Add(ol, 2, "OverlayBlack");	
	}
	if (frame == PROLOGUE_FADEOUT_FRAME + fadeoutendframe) {
		StopSoundMem(g.GetBgm() ["Prologue"]);		//BGM���Ȃ��Ă���Ȃ�BGM��~
		g.GetMS()->Del(g.GetMS()->Get("Prologue"));	//�v�����[�O���[�h�폜
		auto mg = new ModeGame();								//���[�h�Q�[������
		g.GetMS()->Add(mg,0,"Game");
	}
	//�v�����[�O�e�L�X�g�ɍ��킹�A�w�i���X�N���[��������
	if (frame >= BG_XMOVE_FRAME && _x <= 3840) {
		_x += BG_XMOVE_SPEED;
	}
	if (frame >= BG_YMOVE_FRAME && _y < 2160) {
		_y += BG_YMOVE_SPEED;
	}
	return true;
}
/*-----�`��-----*/
bool ModePrologue::Draw(Game& g) {
	auto posx = _x - 1920;
	auto posy = _y - 1080;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _pal);
	DrawRotaGraph(posx, posy, 1.0,0.0,_grhandle, _trans_flag,false);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	return true;
}

