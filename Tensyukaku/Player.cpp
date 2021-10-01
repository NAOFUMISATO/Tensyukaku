/*
** �v���C���[
*/

#include <DxLib.h>
#include "ResourceServer.h"
#include "Player.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ModeGame.h"
#include "ModePause.h"
#include "OverlayFlame.h"
#include "PlayerHp.h"
#include "IaiGauge.h"
#include "Button.h"
#include <vector>
#include <sstream>

using namespace PInfo;
Player::Player(int x,int y) :
	_move_animespeed(0),
	_star_flag(false),
	_ui_flag(false),
	_nohit_flag(false),
	_restartcheck_flag(false),
	_firststart_flag(true),
	_tutorialhit_flag(false),
	_stairup_flag(false),
	_gaugeup_flag(false),
	_pauseinput_flag(false)
{
	_x = x;
	_y = y;
	Init();
	LoadPicture();
	LoadSE();
	VolumeInit();
}

Player::~Player()
{	
}

void Player::Init()
{
	// �v���C���[���̏�����
	_sort = 13;
	_state = PLAYERSTATE::APPEAR;
	_grhandle = -1;
	_w = GRAPH_WIDTH;
	_h = GRAPH_HEIGHT;
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
	_life = LIFE_MAX;
	_action_cnt = _cnt;
	_spd = 0;
	_iai_gauge = 0;
	_isflip = FIRST_FLIP;
	_alpha = FIRST_ALPHA;
	_position = { 0,0 };
	_CameraX = 500;
}


void Player::Process(Game& g)
{
	ObjectBase::Process(g);
	VolumeChange();
	//UI�̃C���X�^���X����
	UIAppear(g);
	//���X�e�B�b�N�̓��͗ʂɂ��X�e�[�^�X�ݒ�
	BufSetting(g);
	if (g.GetRestartFlag() == true) {
		PLAYERSTATE::SWORDOUT;
	}
	//�����Q�[�WMAX����SE����
	if (_iai_gauge == 5 && _gaugeup_flag == false) {
		PlaySoundMem(_se["Gage"], DX_PLAYTYPE_BACK, true);
		_gaugeup_flag = true;
	}
	//�|�[�Y�̓��͊Ǘ��֐�
	PauseInput(g);
	/*---��Ԗ��̏���---*/
	//�ċN����̃X�^�[�g�Ȃ�A��Ԃ𔲓���Ԃɂ���
	RestartCheck(g);
		//���G���
		Star(g);
	switch (_state) {
		//�o�����
	case	PLAYERSTATE::APPEAR:
		Appear(g);
		break;
		//�������
	case PLAYERSTATE::SWORDOUT:
		Swordout(g);
		break;
		//�ҋ@���
	case PLAYERSTATE::IDLE:
		Idle(g);
		break;
		//�ړ����
	case PLAYERSTATE::MOVE:
		Move(g);
		break;
		//���i�U�����
	case PLAYERSTATE::MIDDLEATTACK:
		MidAttack(g);
		break;
		//���i�U�����
	case PLAYERSTATE::LOWATTACK:
		LowAttack(g);
		break;
		//�R����
	case PLAYERSTATE::KICK:
		Kick(g);
		break;
		//�������
	case PLAYERSTATE::IAI:
		Iai(g);
		break;
		//	//�X�E�F�C���
	case PLAYERSTATE::SWAY:
		Sway(g);
		break;
		//��_�����
	case PLAYERSTATE::DAMAGE:
		Damage(g);
		break;
		//���S���
	case PLAYERSTATE::DEAD:
		Dead(g);
		break;
		//�K�i�ʒu�������
	case PLAYERSTATE::STAIRMOVE:
		StairMove(g);
		break;
		//�K�i�㏸���
	case PLAYERSTATE::STAIRUP:
		StairUp(g);
		break;
		//�{�X�K�i�ʒu�������
	case PLAYERSTATE::BOSSSTAIRMOVE:
		BossStairMove(g);
		break;
		//�{�X�K�i�㏸���
	case PLAYERSTATE::BOSSSTAIRUP:
		BossStairUp(g);
		break;
		//�C�x���gA���
	case PLAYERSTATE::EVENTA:
		BossEventA(g);
		break;
		//�C�x���gB���
	case PLAYERSTATE::EVENTB:
		BossEventB(g);
		break;
		//����U�����
	case PLAYERSTATE::SPECIALATTACK:
		SpecialAttack(g);
		break;
	}
	//�����蔻��̏���
	HitJudge(g);
	//�v���C���[�ʒu����̃J�����ʒu�ݒ�
	CameraSetting(g);
}

void Player::Draw(Game& g) {
#ifdef _DEBUG
	//DebugDraw(g);
#endif
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
	ObjectBase::Draw(g);
}

void Player::Delete(Game& g) {
		g.GetOS()->Del(this);
}

//�摜�ǂݍ��݊֐�
void Player::LoadPicture() {
	_grall["Appear"].resize(APPEAR_ANIMEMAX);
	ResourceServer::LoadDivGraph(APPEAR_GRAPHNAME, APPEAR_ANIMEMAX, APPEAR_WIDTHCOUNT, APPEAR_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Appear"].data());
	_grall["Swordout"].resize(SWORDOUT_ANIMEMAX);
	ResourceServer::LoadDivGraph(SWORDOUT_GRAPHNAME, SWORDOUT_ANIMEMAX, SWORDOUT_WIDTHCOUNT, SWORDOUT_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Swordout"].data());
	_grall["Idle"].resize(IDLE_ANIMEMAX);
	ResourceServer::LoadDivGraph(IDLE_GRAPHNAME, IDLE_ANIMEMAX, IDLE_WIDTHCOUNT, IDLE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Idle"].data());
	_grall["Move"].resize(MOVE_ANIMEMAX);
	ResourceServer::LoadDivGraph(MOVE_GRAPHNAME, MOVE_ANIMEMAX, MOVE_WIDTHCOUNT, MOVE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Move"].data());
	_grall["MiddleAttack"].resize(MIDDLEATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(MIDDLEATTACK_GRAPHNAME, MIDDLEATTACK_ANIMEMAX, MIDDLEATTACK_WIDTHCOUNT, MIDDLEATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["MiddleAttack"].data());
	_grall["LowAttack"].resize(LOWATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(LOWATTACK_GRAPHNAME, LOWATTACK_ANIMEMAX, LOWATTACK_WIDTHCOUNT, LOWATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["LowAttack"].data());
	_grall["Kick"].resize(KICK_ANIMEMAX);
	ResourceServer::LoadDivGraph(KICK_GRAPHNAME, KICK_ANIMEMAX, KICK_WIDTHCOUNT, KICK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Kick"].data());
	_grall["Iai"].resize(IAI_ANIMEMAX);
	ResourceServer::LoadDivGraph(IAI_GRAPHNAME, IAI_ANIMEMAX, IAI_WIDTHCOUNT, IAI_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Iai"].data());
	_grall["Sway"].resize(SWAY_ANIMEMAX);
	ResourceServer::LoadDivGraph(SWAY_GRAPHNAME, SWAY_ANIMEMAX, SWAY_WIDTHCOUNT, SWAY_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Sway"].data());
	_grall["Damage"].resize(DAMAGE_ANIMEMAX);
	ResourceServer::LoadDivGraph(DAMAGE_GRAPHNAME, DAMAGE_ANIMEMAX, DAMAGE_WIDTHCOUNT, DAMAGE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Damage"].data());
	_grall["Dead"].resize(DEAD_ANIMEMAX);
	ResourceServer::LoadDivGraph(DEAD_GRAPHNAME, DEAD_ANIMEMAX, DEAD_WIDTHCOUNT, DEAD_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Dead"].data());
	_grall["Special"].resize(SPECIALATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(SPECIALATTACK_GRAPHNAME, SPECIALATTACK_ANIMEMAX, SPECIALATTACK_WIDTHCOUNT, SPECIALATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Special"].data());
}

//���ʉ��ǂݍ��݊֐�
void Player::LoadSE() {
	_se["BStartGame"] = ResourceServer::LoadSoundMem("se/Player/BStartGame.wav");
	_se["Walk"] = ResourceServer::LoadSoundMem("se/Player/Footstep.wav");
	_se["MiddleAttack"] = ResourceServer::LoadSoundMem("se/Player/MiddleAttack.wav");
	_se["LowAttack"] = ResourceServer::LoadSoundMem("se/Player/LowAttack.wav");
	_se["Kick"] = ResourceServer::LoadSoundMem("se/Player/Kick.wav");
	_se["Sway"] = ResourceServer::LoadSoundMem("se/Player/Sway.wav");
	_se["Damage"] = ResourceServer::LoadSoundMem("se/Player/Damage.wav");
	_se["Dead"] = ResourceServer::LoadSoundMem("se/Player/Dead.wav");
	_se["Iai"] = ResourceServer::LoadSoundMem("se/Player/Iai.wav");
	_se["Gage"] = ResourceServer::LoadSoundMem("se/Player/Gage.wav");
}

//���ʉ��{�����[�������l�ݒ�֐�
void	Player::VolumeInit() {
	_vpal["BStartGame"] = 255;
	_vpal["Walk"] = 255;
	_vpal["MiddleAttack"] = 255;
	_vpal["LowAttack"] = 255;
	_vpal["Kick"] = 255;
	_vpal["Sway"] = 255;
	_vpal["Damage"] = 255;
	_vpal["Dead"] = 255;
	_vpal["Iai"] = 255;
	_vpal["Gage"] = 255;

}

//�{�����[���ύX�֐�
void	Player::VolumeChange() {
	ChangeVolumeSoundMem(_vpal["BStartGame"],_se["BStartGame"]);
	ChangeVolumeSoundMem(_vpal["Walk"], _se["Walk"]);
	ChangeVolumeSoundMem(_vpal["MiddleAttack"], _se["MiddleAttack"]);
	ChangeVolumeSoundMem(_vpal["LowAttack"], _se["LowAttack"]);
	ChangeVolumeSoundMem(_vpal["Kick"], _se["Kick"]);
	ChangeVolumeSoundMem(_vpal["Sway"], _se["Sway"]);
	ChangeVolumeSoundMem(_vpal["Damage"], _se["Damage"]);
	ChangeVolumeSoundMem(_vpal["Dead"], _se["Dead"]);
	ChangeVolumeSoundMem(_vpal["Iai"], _se["Iai"]);
	ChangeVolumeSoundMem(_vpal["Gage"], _se["Gage"]);
}
//�v���C���[�̔�_��&�����o��&�e�C�x���g�u���b�N����̏���
void	Player::HitJudge(Game& g) {
	//�{�X�X�e�[�W�̃C�x���g������ԑJ�ڗp����
	if (_bosseventA_flag == true) {
		_action_cnt = _cnt;
		_state = PLAYERSTATE::EVENTA;
		_bosseventA_flag = false;
	}
	if (_bosseventB_flag == true) {
		_action_cnt = _cnt;
		_state = PLAYERSTATE::EVENTB;
		_bosseventB_flag = false;
	}
	//�ҋ@�ƈړ����̂݊K�i������󂯕t���鏈��
	if (_state == PLAYERSTATE::IDLE || _state == PLAYERSTATE::MOVE) {
		_stairup_flag = true;
	}
	else { _stairup_flag = false; }
	//�G�̍U���̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		OBJECTTYPE objType = (*ite)->GetObjType();
		switch (objType) {
		case ObjectBase::OBJECTTYPE::BUSHIATTACK:
		case ObjectBase::OBJECTTYPE::BUSYOATTACK:
		case ObjectBase::OBJECTTYPE::NINJAATTACK:
		case ObjectBase::OBJECTTYPE::ZYOUNINATTACK:
		case ObjectBase::OBJECTTYPE::SHIELDERATTACK:
		case ObjectBase::OBJECTTYPE::LANCERATTACK:
		case ObjectBase::OBJECTTYPE::POISON:
		case ObjectBase::OBJECTTYPE::STRPOISON:
		case ObjectBase::OBJECTTYPE::KUNAI:
			// �v���C���[�Ƃ��̍U���̓����蔻����s��
			if (IsHit(*(*ite)) == true && _star_flag == false&&_nohit_flag==false)
			{
				// �v���C���[�̏�ԑJ�ڂƍU���I�u�W�F�N�g�̃_���[�W����
				(*ite)->Delete(g);		// (*ite) �͍U���I�u�W�F�N�g
				_life--;
				_action_cnt = _cnt;
				_state = PLAYERSTATE::DAMAGE;
				PlaySoundMem(_se["Damage"], DX_PLAYTYPE_BACK, true);
			}
			break;
		//�K�i�Ƃ̓����蔻��
		case ObjectBase::OBJECTTYPE::STAIR:
			// �v���C���[�Ƃ��̊K�i�̓����蔻����s��
			if (IsHit(*(*ite)) == true&&_stairup_flag==true)
			{
				if (g.GetKey() & PAD_INPUT_UP && g.GetYBuf() < -UP_YBUF) {
					_Player_y = _y;
					_Stair_x = (*ite)->GetX();
					_StairFlip_Flag = (*ite)->GetFlip();
					_state = PLAYERSTATE::STAIRMOVE;
				}
			}
			break;
		case ObjectBase::OBJECTTYPE::BOSSSTAIR:
			// �v���C���[�Ƃ��̊K�i�̓����蔻����s��
			if (IsHit(*(*ite)) == true && _stairup_flag == true)
			{
				if (g.GetKey() & PAD_INPUT_UP && g.GetYBuf() < -UP_YBUF) {
					_Player_y = _y;
					_Stair_x = (*ite)->GetX();
					_StairFlip_Flag = (*ite)->GetFlip();
					_state = PLAYERSTATE::BOSSSTAIRMOVE;
				}
			}
			break;
		case ObjectBase::OBJECTTYPE::ENEMY:
			// ite�͓G���H
			if ((*ite)->GetObjType() == OBJECTTYPE::ENEMY)
			{
				// �v���C���[�Ƃ��̓G�̓����蔻����s��
				if (IsHit(*(*ite)) == true) {
					_x = _before_x;

				}
			}
			break;
		case ObjectBase::OBJECTTYPE::RECOVERYBLOCK:
				// �v���C���[�Ƃ��̉񕜔���̓����蔻����s��
				if (IsHit(*(*ite)) == true) {
					(*ite)->Delete(g);
					_life = 3;
				}
				break;
		case ObjectBase::OBJECTTYPE::FLAMEBLOCK:
			// �v���C���[�Ƃ��̉����o�̓����蔻����s��
			if (IsHit(*(*ite)) == true) {
				(*ite)->Delete(g);
				auto of = new OverlayFlame();
				g.GetMS()->Add(of, 1, "Flame");
				PlaySoundMem(g.GetBgm()["Flame"], DX_PLAYTYPE_LOOP, true);
			}
			break;
		case ObjectBase::OBJECTTYPE::TUTORIALBOARD:
			// �v���C���[�Ƃ��̃`���[�g���A���{�[�h�̓����蔻����s��
			if (IsHit(*(*ite)) == true) {
				_tutorialhit_flag = true;
			}
			if (IsHit(*(*ite)) == false) {
				_tutorialhit_flag = false;
			}
			break;
		default:
			break;
		}
	}
}
//�f�o�b�N�p�֐�
void Player::DebugDraw(Game& g) {
	std::stringstream ss;
	ss << "X�X�N���[���l=" << g.GetChip()->GetscrX() << "\n";
	ss << "Y�X�N���[���l=" << g.GetChip()->GetscrY() << "\n";
	ss << "�v���C���[X���W=" << _x << "\n";
	ss << "�v���C���[Y���W=" << _y << "\n";
	ss<<"���X�e�B�b�N���͗�X="<<g.GetXBuf()<< "\n";
	ss <<"���X�e�B�b�N���͗�Y="<<g.GetYBuf()<< "\n";
	ss << "�̗�=" << _life << "\n";
	ss << "����=" << _spd << "\n";
	ss << "�J��������=" << _CameraX << "\n";
	ss << "�t���[��=" << _cnt-_action_cnt << "\n";
	DrawString(10, 10, ss.str().c_str(), GetColor(255, 0, 0));
}

//UI�C���X�^���X�����֐�
void Player::UIAppear(Game& g){
	if (_ui_flag == false) {
		auto hp1 = new PlayerHp(0);
		g.GetOS()->Add(hp1);
		auto hp2 = new PlayerHp(1);
		g.GetOS()->Add(hp2);
		auto hp3 = new PlayerHp(2);
		g.GetOS()->Add(hp3);
		auto ig = new IaiGauge();
		g.GetOS()->Add(ig);
		_ui_flag = true;
	}
}
//�v���C���[�ʒu����̃J�����ʒu�ݒ�
void Player::CameraSetting(Game& g) {
	g.SetcvX(_x - (SCREEN_W * _CameraX / 1000));				// �w�i�̉������ɃL������u��
	g.SetcvY(_y - (SCREEN_H * BACK_CAMERA_Y / 100));		// �w�i�̏c93%�ɃL������u��
	if (g.GetcvX() < 0) { g.SetcvX(0); }
	if (g.GetcvX() > g.GetmapW() - SCREEN_W) { g.SetcvX(g.GetmapW() - SCREEN_W); }
	if (g.GetcvY() < 0) { g.SetcvY(0); }
	if (g.GetcvY() > g.GetmapH() - SCREEN_H) { g.SetcvY(g.GetmapH() - SCREEN_H); }

	auto GC = g.GetChip();
	GC->SetscrX(_x - (SCREEN_W * _CameraX / 1000));			// �}�b�v�`�b�v�̉������ɃL������u��
	GC->SetscrY(_y - (SCREEN_H * CHIP_CAMERA_Y / 100));		// �}�b�v�`�b�v�̏c93%�ɃL������u��
	if (GC->GetscrX() < 0) { GC->SetscrX(0); }
	if (GC->GetscrX() > GC->GetMSW() * GC->GetCSW() - SCREEN_W) { GC->SetscrX(GC->GetMSW() * GC->GetCSW() - SCREEN_W); }
	if (GC->GetscrY() < 0) { GC->SetscrY(0); }
	if (GC->GetscrY() > GC->GetMSH() * GC->GetCSH() - SCREEN_H) { GC->SetscrY(GC->GetMSH() * GC->GetCSH() - SCREEN_H); }
}

//�ċN����̊J�n���ǂ����m�F����֐�
void Player::RestartCheck(Game& g) {
	if (_restartcheck_flag == false) {
		if (g.GetRestartFlag() == true) {
			_state = PLAYERSTATE::SWORDOUT;
		}
		_restartcheck_flag = true;
	}
	if (_firststart_flag == true) {
		if (g.GetCPointFlag()["2A"] == true) {
			_firststart_flag = false;
		}
	}
}
//���G��Ԏ��̏���
void Player::Star(Game& g) {
	if (_star_flag == true) {
		_alpha = FIRST_ALPHA;
		if ((_cnt / ANIMESPEED_STAR % 2) == 0) {
			_alpha = STAR_ALPHA;
		}
		if (_cnt - _Star_Cnt == STAR_ALLFRAME) {
			_alpha = FIRST_ALPHA;
			_star_flag = false;
		}
	}
}
//���X�e�B�b�N�̓��͗ʂɂ��X�e�[�^�X�ݒ�
void Player::BufSetting(Game& g) {
	auto xbuf = g.GetXBuf();
	if (xbuf < MAX_BUF - RUN_XBUF && -(MAX_BUF - RUN_XBUF) < xbuf) {
		_spd = WALKSPEED;
		_move_animespeed = ANIMESPEED_WALK;
	}
	if (xbuf >= RUN_XBUF || -RUN_XBUF >= xbuf) {
		_spd = RUNSPEED;
		_move_animespeed = ANIMESPEED_RUN;
	}
}

void Player::PauseInput(Game& g) {
	if (_state == PLAYERSTATE::IDLE || _state == PLAYERSTATE::MOVE || _state == PLAYERSTATE::MOVE) {
		_pauseinput_flag = true;
	}
	else { _pauseinput_flag = false; }
	if (g.GetTrg() & PAD_INPUT_12 && _pauseinput_flag == true) {
		auto mp = new ModePause();
		g.GetMS()->Add(mp, 20, "Pause");
		auto mg = (ModeGame*)g.GetMS()->Get("Game");
		mg->SetStopObjProcess(true);
	}
}