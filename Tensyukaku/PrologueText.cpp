#include <DxLib.h>
#include "ModePrologue.h"
#include "PrologueText.h"
#include "ModeGame.h"
#include "Game.h"
#include "OverlayBlack.h"
#include "ResourceServer.h"
using namespace ProInfo;
bool PrologueText::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 1600;
	_y = 540;
	_pal = 0;
	_GraphNo = 0;
	_mode_cnt = _cnt;
	_trans_flag = true;
	_Skip_Flag = false;
	_grall["PText"].resize(TEXT_ANIMEMAX);
	ResourceServer::LoadDivGraph(TEXT_GRAPHNAME, TEXT_ANIMEMAX, TEXT_WIDTHCOUNT, TEXT_HEIGHTCOUNT, TEXT_GRAPH_WIDTH, TEXT_GRAPH_HEIGHT, _grall["PText"].data());
	LoadSE();
	VolumeInit();
	return true;
}

bool PrologueText::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool PrologueText::Process(Game& g) {
	base::Process(g);
	VolumeChange();
	auto frame = _cnt - _mode_cnt;
	_grhandle = _grall["PText"][_anime["PText"]];
	_anime["PText"] = _GraphNo;
	//�e�L�X�g1
	if (_Skip_Flag == false) {
		if (frame == 1) {
			PlaySoundMem(_se["Text1"], DX_PLAYTYPE_BACK, true);
		}
		if (frame < TEXT1_FADEIN_FRAME) {
			_pal += TEXT_FADE_SPEED;
		}
		if (frame == TEXT1_FADEIN_FRAME) {
			_pal = 255;
			auto as = new PrologueASkip();
			g.GetMS()->Add(as, 1, "PASkip");
		}
		if (frame >= TEXT1_FADEOUT_BEGINFRAME && TEXT1_FADEOUT_ENDFRAME > frame) {
			_pal -= TEXT_FADE_SPEED;
		}
		if (frame == TEXT1_FADEOUT_ENDFRAME) {
			_pal = 0;
			_GraphNo = 1;
		}
		//�e�L�X�g2
		if (frame == TEXT2_FADEIN_BEGINFRAME) {
			PlaySoundMem(_se["Text2"], DX_PLAYTYPE_BACK, true);
		}
		if (frame >= TEXT2_FADEIN_BEGINFRAME && TEXT2_FADEIN_ENDFRAME > frame) {
			_pal += TEXT_FADE_SPEED;
		}
		if (frame == TEXT2_FADEIN_ENDFRAME) {
			_pal = 255;
		}
		if (frame >= TEXT2_FADEOUT_BEGINFRAME && TEXT2_FADEOUT_ENDFRAME > frame) {
			_pal -= TEXT_FADE_SPEED;
		}
		if (frame == TEXT2_FADEOUT_ENDFRAME) {
			_pal = 0;
			_GraphNo = 2;
		}
		//�e�L�X�g3
		if (frame == TEXT3_FADEIN_BEGINFRAME) {
			PlaySoundMem(_se["Text3"], DX_PLAYTYPE_BACK, true);
		}
		if (frame >= TEXT3_FADEIN_BEGINFRAME && TEXT3_FADEIN_ENDFRAME > frame) {
			_pal += TEXT_FADE_SPEED;
		}
		if (frame == TEXT3_FADEIN_ENDFRAME) {
			_pal = 255;
		}
		if (frame >= TEXT3_FADEOUT_BEGINFRAME && TEXT3_FADEOUT_ENDFRAME > frame) {
			_pal -= TEXT_FADE_SPEED;
		}
		if (frame == TEXT3_FADEOUT_ENDFRAME) {
			_pal = 0;
			_GraphNo = 3;
		}
		//�e�L�X�g4
		if (frame == TEXT4_FADEIN_BEGINFRAME) {
			PlaySoundMem(_se["Text4"], DX_PLAYTYPE_BACK, true);
		}
		if (frame >= TEXT4_FADEIN_BEGINFRAME && TEXT4_FADEIN_ENDFRAME > frame) {
			_pal += TEXT_FADE_SPEED;
		}
		if (frame == TEXT4_FADEIN_ENDFRAME) {
			_pal = 255;
		}
		if (frame >= TEXT4_FADEOUT_BEGINFRAME && TEXT4_FADEOUT_ENDFRAME > frame) {
			_pal -= TEXT_FADE_SPEED;
		}
		if (frame == TEXT4_FADEOUT_ENDFRAME) {
			_pal = 0;
			_x = 1500;
			_y = 850;
			_GraphNo = 4;
		}
		//�e�L�X�g5
		if (frame == TEXT5_FADEIN_BEGINFRAME) {
			PlaySoundMem(_se["Text5"], DX_PLAYTYPE_BACK, true);
		}
		if (frame >= TEXT5_FADEIN_BEGINFRAME && TEXT5_FADEIN_ENDFRAME > frame) {
			_pal += TEXT_FADE_SPEED;
		}
		if (frame == TEXT5_FADEIN_ENDFRAME) {
			_pal = 255;
		}
		if (frame >= TEXT5_FADEOUT_BEGINFRAME && TEXT5_FADEOUT_ENDFRAME > frame) {
			_pal -= TEXT_FADE_SPEED;
		}
		if (frame == TEXT5_FADEOUT_ENDFRAME) {
			_pal = 0;
			g.GetMS()->Del(this);
		}
	}
	/*----------�{�^�������ɂ��X�L�b�v----------*/
	auto fadeoutframe =85;
	if (g.GetTrg() & PAD_INPUT_3&&_Skip_Flag==false) {
		_mode_cnt = _cnt;
		_Skip_Flag = true;
		//���[�h�I�[�o�[���C����
		auto ol = new OverlayBlack();
		ol->SetFade(fadeoutframe, 480, 600, 3);
		g.GetMS()->Add(ol, 2, "OverlayBlack");
	}
	//�X�L�b�v���̉����̃t�F�[�h�A�E�g
	if (frame >= 0 && frame < fadeoutframe && _Skip_Flag == true) {
		auto vpal = g.GetVpal();
		vpal["Prologue"] -= 1;
		g.SetVpal(vpal);
		_vpal["Text1"]-=4;
		_vpal["Text2"]-=4;
		_vpal["Text3"]-=4;
		_vpal["Text4"]-=4;
		_vpal["Text5"]-=4;
	}
	//�����ɂ���莞�Ԍ�A����Ă��鉹���̒�~&���[�h�Q�[������
	if (frame == fadeoutframe&& _Skip_Flag == true) {
		StopSoundMem(_se["Text1"]);
		StopSoundMem(_se["Text2"]);
		StopSoundMem(_se["Text3"]);
		StopSoundMem(_se["Text4"]);
		StopSoundMem(_se["Text5"]);
		StopSoundMem(g.GetBgm() ["Prologue"]);
		g.GetMS()->Del(g.GetMS()->Get("PASkip"));
		g.GetMS()->Del(g.GetMS()->Get("Prologue"));
		g.GetMS()->Del(this);
		auto mg = new ModeGame();
		g.GetMS()->Add(mg, 0, "Game");
	}
	return true;
}

bool PrologueText::Draw(Game& g) {
	base::Draw(g);
	return true;
}

//SE�ǂݍ���
void		PrologueText::LoadSE() {
	_se["Text1"] = ResourceServer::LoadSoundMem("se/Voice/Prologue01.wav");
	_se["Text2"] = ResourceServer::LoadSoundMem("se/Voice/Prologue02.wav");
	_se["Text3"] = ResourceServer::LoadSoundMem("se/Voice/Prologue03.wav");
	_se["Text4"] = ResourceServer::LoadSoundMem("se/Voice/Prologue04.wav");
	_se["Text5"] = ResourceServer::LoadSoundMem("se/Voice/Prologue05.wav");
}

//�{�����[�������l
void		PrologueText::VolumeInit() {
	_vpal["Text1"]=255;
	_vpal["Text2"]=255;
	_vpal["Text3"]=255;
	_vpal["Text4"]=255;
	_vpal["Text5"]=255;
}
//�{�����[���ύX
void		PrologueText::VolumeChange() {
	ChangeVolumeSoundMem(_vpal["Text1"],_se["Text1"]);
	ChangeVolumeSoundMem(_vpal["Text2"], _se["Text2"]);
	ChangeVolumeSoundMem(_vpal["Text3"], _se["Text3"]);
	ChangeVolumeSoundMem(_vpal["Text4"], _se["Text4"]);
	ChangeVolumeSoundMem(_vpal["Text5"], _se["Text5"]);
}


//A�{�^���X�X�L�b�v�摜
bool PrologueASkip::Initialize(Game& g) {
	if (!base::Initialize(g)) { return false; }
	_x = 1700;
	_y = 1030;
	_trans_flag = true;
	_mode_cnt = _cnt;
	_grhandle=ResourceServer::LoadGraph("res/Mode/PrologueSkip.png");
	return true;
}

bool PrologueASkip::Terminate(Game& g) {
	base::Terminate(g);
	return true;
}

bool PrologueASkip::Process(Game& g) {
	base::Process(g);
	auto frame = _cnt - _mode_cnt;
	if (frame >=550) {
		_pal -= 5;
	}
	if (_pal == 0) {
		g.GetMS()->Del(this);
	}
	return true;
}

bool PrologueASkip::Draw(Game& g) {
	base::Draw(g);
	return true;
}

