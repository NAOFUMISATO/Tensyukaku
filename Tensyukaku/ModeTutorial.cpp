/*****************************************************************//**
 * \file   ModeTutorial.cpp
 * \brief  �C���Q�[���ł̃`���[�g���A���N���X�i���[�h�x�[�X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ResourceServer.h"
#include "Game.h"
#include "ModeTutorial.h"
#include "ModeGame.h"

using namespace TuInfo;
/*-----������-----*/
bool ModeTutorial::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 960;							//X���W�̏�����
	_y = 250;							//Y���W�̏�����
	_pal = 255;							//�����x�̏�����
	_mode_cnt = _cnt;			//�t���[���̏�����
	_trans_flag = true;				//�w�i���߃t���O����^�ŏ�����
	LoadPicture();					//�摜�ǂݍ���
	return true;
}
/*-----�I��------*/
bool ModeTutorial::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}
/*-----�X�V-----*/
bool ModeTutorial::Process(Game& g) {
	base::Process(g);
	//�`���[�g���A���̎�ނɂ��A�`�悷��摜�̕ύX
	if (_tutorial_type == "1A") {
		_grhandle = _grall["1A"][0];
	}
	else if (_tutorial_type == "1B") {
		_grhandle = _grall["1B"][0];
	}
	else if (_tutorial_type == "2A"){
		_grhandle = _grall["2A"][0];
	}
	else if (_tutorial_type == "3A") {
		_grhandle = _grall["3A"][0];
	}
	else if (_tutorial_type == "3B") {
		_grhandle = _grall["3B"][0];
	}
	else if (_tutorial_type == "4A") {
		_grhandle = _grall["4A"][0];
	}
	else if (_tutorial_type == "5A") {
		_grhandle = _grall["5A"][0];
	}
	return true;
}
/*-----�`��-----*/
bool ModeTutorial::Draw(Game& g) {
	base::Draw(g);
	return true;
}
//�摜�ǂݍ��݊֐�
void  ModeTutorial::LoadPicture() {
	_grall["1A"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/Tutorial1.png", 1, 1, 1, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["1A"].data());
	_grall["1B"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/Tutorial2.png", 1, 1, 1, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["1B"].data());
	_grall["2A"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/Tutorial3.png", 1, 1, 1, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["2A"].data());
	_grall["3A"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/Tutorial4.png", 1, 1, 1, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["3A"].data());
	_grall["3B"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/Tutorial5.png", 1, 1, 1, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["3B"].data());
	_grall["4A"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/Tutorial6.png", 1, 1, 1, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["4A"].data());
	_grall["5A"].resize(1);
	ResourceServer::LoadDivGraph("res/Mode/Tutorial7.png", 1, 1, 1, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["5A"].data());
}
