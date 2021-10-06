/*
**	�v���C���[
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
#include "PlayerParticle.h"
#include <vector>
#include <sstream>
using namespace PParInfo;
using namespace PInfo;
Player::Player(int x,int y,bool flip) :
	_move_animespeed(0),
	_star_flag(false),
	_ui_flag(false),
	_nohit_flag(false),
	_restartcheck_flag(false),
	_tutorialhit_flag(false),
	_stairup_flag(false),
	_gaugemax_flag(false),
	_pauseinput_flag(false)
{
	_x = x;
	_y = y;
	_isflip = flip;
	Init();						// ���̏�����
	LoadPicture();		//�摜�ǂݍ���
	LoadSE();				//���ʉ��ǂݍ���
	VolumeInit();			//���ʉ����ʏ�����
}

Player::~Player(){	
}
//������
void Player::Init()
{
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
	_alpha = FIRST_ALPHA;
	_position = { 0,0 };
	_camera_x = 500;
}

/*---����---*/
void Player::Process(Game& g)
{
	ObjectBase::Process(g);
	VolumeChange();
	//UI�̃C���X�^���X����
	UIAppear(g);
	//���X�e�B�b�N�̓��͗ʂɂ��X�e�[�^�X�ݒ�
	BufSetting(g);
	//�Q�[�WMAX���̎��@����&SE����
	GaugeMax(g);
	//�|�[�Y�̓��͊Ǘ��֐�
	PauseInput(g);
	/*---��Ԗ��̏���---*/
	//�ċN����̃X�^�[�g�Ȃ�A��Ԃ𔲓���Ԃɂ���
	RestartCheck(g);
		//���G���
		Star(g);
	switch (_state) {
		//�o�����
	case PLAYERSTATE::APPEAR:
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
/*---�`��---*/
void Player::Draw(Game& g) {
#ifdef _DEBUG
	DebugDraw(g);
#endif
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
	ObjectBase::Draw(g);
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
	_se["Stair"] = ResourceServer::LoadSoundMem("se/Player/Stair.wav");
	_se["Damage"] = ResourceServer::LoadSoundMem("se/Player/Damage.wav");
	_se["Dead"] = ResourceServer::LoadSoundMem("se/Player/Dead.wav");
	_se["Iai"] = ResourceServer::LoadSoundMem("se/Player/Iai.wav");
	_se["Gage"] = ResourceServer::LoadSoundMem("se/Player/Gage.wav");
	_se["Special"] = ResourceServer::LoadSoundMem("se/Player/SpecialAttack.wav");
}

//���ʉ��{�����[�������l�ݒ�֐�
void	Player::VolumeInit() {
	_vpal["BStartGame"] = 200;
	_vpal["Walk"] = 255;
	_vpal["MiddleAttack"] = 255;
	_vpal["LowAttack"] = 255;
	_vpal["Kick"] = 255;
	_vpal["Sway"] = 255;
	_vpal["Stair"] = 255;
	_vpal["Damage"] = 255;
	_vpal["Dead"] = 255;
	_vpal["Iai"] = 255;
	_vpal["Gage"] = 255;
	_vpal["Special"] = 255;
}

//�{�����[���ύX�֐�
void	Player::VolumeChange() {
	ChangeVolumeSoundMem(_vpal["BStartGame"],_se["BStartGame"]);
	ChangeVolumeSoundMem(_vpal["Walk"], _se["Walk"]);
	ChangeVolumeSoundMem(_vpal["MiddleAttack"], _se["MiddleAttack"]);
	ChangeVolumeSoundMem(_vpal["LowAttack"], _se["LowAttack"]);
	ChangeVolumeSoundMem(_vpal["Kick"], _se["Kick"]);
	ChangeVolumeSoundMem(_vpal["Sway"], _se["Sway"]);
	ChangeVolumeSoundMem(_vpal["Stair"], _se["Stair"]);
	ChangeVolumeSoundMem(_vpal["Damage"], _se["Damage"]);
	ChangeVolumeSoundMem(_vpal["Dead"], _se["Dead"]);
	ChangeVolumeSoundMem(_vpal["Iai"], _se["Iai"]);
	ChangeVolumeSoundMem(_vpal["Gage"], _se["Gage"]);
	ChangeVolumeSoundMem(_vpal["Special"], _se["Special"]);
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
/*----------�e�����蔻��̏���----------*/
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		OBJECTTYPE objType = (*ite)->GetObjType();
		switch (objType) {
			//�e�G�̍U��
		case ObjectBase::OBJECTTYPE::BUSHIATTACK:
		case ObjectBase::OBJECTTYPE::BUSYOATTACK:
		case ObjectBase::OBJECTTYPE::NINJAATTACK:
		case ObjectBase::OBJECTTYPE::ZYOUNINATTACK:
		case ObjectBase::OBJECTTYPE::SHIELDERATTACK:
		case ObjectBase::OBJECTTYPE::LANCERATTACK:
		case ObjectBase::OBJECTTYPE::POISON:
		case ObjectBase::OBJECTTYPE::KUNAI:
			//�G�̍U���ɓ��������Ȃ�_���[�W��Ԃֈڍs
			if (IsHit(*(*ite)) == true && _star_flag == false&&_nohit_flag==false)
			{
				(*ite)->Delete(g);
				_life--;	
				_action_cnt = _cnt;
				_state = PLAYERSTATE::DAMAGE;
				//SE
				PlaySoundMem(_se["Damage"], DX_PLAYTYPE_BACK, true);
			}
			break;
		//�K�i
		case ObjectBase::OBJECTTYPE::STAIR:
			if (IsHit(*(*ite)) == true&&_stairup_flag==true)
			{
				//�K�i�ɓ������Ă����Ԃŏ���͂����Ȃ�K�i�ʒu������Ԃֈڍs
				if (g.GetKey() & PAD_INPUT_UP && g.GetYBuf() < -UP_YBUF) {
					_player_y = _y;
					_stair_x = (*ite)->GetX();
					_stairflip_flag = (*ite)->GetFlip();
					_state = PLAYERSTATE::STAIRMOVE;
				}
			}
			break;
			//�{�X�K�i
		case ObjectBase::OBJECTTYPE::BOSSSTAIR:
			if (IsHit(*(*ite)) == true && _stairup_flag == true)
			{
				//�K�i�ɓ������Ă����Ԃŏ���͂����Ȃ�{�X�K�i�ʒu������Ԃֈڍs
				if (g.GetKey() & PAD_INPUT_UP && g.GetYBuf() < -UP_YBUF) {
					_player_y = _y;
					_stair_x = (*ite)->GetX();
					_stairflip_flag = (*ite)->GetFlip();
					_state = PLAYERSTATE::BOSSSTAIRMOVE;
				}
			}
			break;
			//�G
		case ObjectBase::OBJECTTYPE::ENEMY:
			//�G�ɓ������Ă���Ȃ�O��X���W�ɂ���
			if ((*ite)->GetObjType() == OBJECTTYPE::ENEMY)
			{
				if (IsHit(*(*ite)) == true) {
					_x = _before_x;

				}
			}
			break;
			//�񕜃u���b�N
		case ObjectBase::OBJECTTYPE::RECOVERYBLOCK:
			//���������Ȃ�v���C���[�̗̑͂�S�񕜂�����
				if (IsHit(*(*ite)) == true) {
					(*ite)->Delete(g);
					_life = 3;
				}
				break;
			//�����o�u���b�N
		case ObjectBase::OBJECTTYPE::FLAMEBLOCK:
			//���������Ȃ牊���o���[�h����
			if (IsHit(*(*ite)) == true) {
				(*ite)->Delete(g);
				auto of = new OverlayFlame();
				g.GetMS()->Add(of, 1, "Flame");
				//����SE���Ȃ��Ă��Ȃ��Ȃ牊��SE����
				if (CheckSoundMem(g.GetBgm()["Flame"]) == 0) {
					PlaySoundMem(g.GetBgm()["Flame"], DX_PLAYTYPE_LOOP, true);
				}
			}
			break;
			//�`���[�g���A���{�[�h
		case ObjectBase::OBJECTTYPE::TUTORIALBOARD:
			//�������Ă���Ƃ��̂݃`���[�g���A���q�b�g�t���O��TRUE�ɂ���
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
	ss << "�J��������=" << _camera_x << "\n";
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
	g.SetcvX(_x - (SCREEN_W * _camera_x / 1000));				// �w�i�̉������ɃL������u��
	g.SetcvY(_y - (SCREEN_H * BACK_CAMERA_Y / 100));		// �w�i�̏c93%�ɃL������u��
	if (g.GetcvX() < 0) { g.SetcvX(0); }
	if (g.GetcvX() > g.GetmapW() - SCREEN_W) { g.SetcvX(g.GetmapW() - SCREEN_W); }
	if (g.GetcvY() < 0) { g.SetcvY(0); }
	if (g.GetcvY() > g.GetmapH() - SCREEN_H) { g.SetcvY(g.GetmapH() - SCREEN_H); }

	auto GC = g.GetChip();
	GC->SetscrX(_x - (SCREEN_W * _camera_x / 1000));			// �}�b�v�`�b�v�̉������ɃL������u��
	GC->SetscrY(_y - (SCREEN_H * CHIP_CAMERA_Y / 100));		// �}�b�v�`�b�v�̏c93%�ɃL������u��
	if (GC->GetscrX() < 0) { GC->SetscrX(0); }
	if (GC->GetscrX() > GC->GetMSW() * GC->GetCSW() - SCREEN_W) { GC->SetscrX(GC->GetMSW() * GC->GetCSW() - SCREEN_W); }
	if (GC->GetscrY() < 0) { GC->SetscrY(0); }
	if (GC->GetscrY() > GC->GetMSH() * GC->GetCSH() - SCREEN_H) { GC->SetscrY(GC->GetMSH() * GC->GetCSH() - SCREEN_H); }
}

//�ċN����̊J�n���ǂ����m�F����֐�
void Player::RestartCheck(Game& g) {
	if (_restartcheck_flag == false) {
		//�ċN����̊J�n�Ȃ�Δ�����Ԃ���J�n
		if (g.GetRestartFlag() == true) {
			_state = PLAYERSTATE::SWORDOUT;
		}
		else {
			//SE����
			PlaySoundMem(_se["BStartGame"],DX_PLAYTYPE_BACK,true); }
		_restartcheck_flag = true;
	}
}
//���G��Ԏ��̏���
void Player::Star(Game& g) {
	if (_star_flag == true) {
		_alpha = FIRST_ALPHA;
		if ((_cnt / ANIMESPEED_STAR % 2) == 0) {
			_alpha = STAR_ALPHA;
		}
		if (_cnt - _star_cnt == STAR_ALLFRAME) {
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
	//���X�e�B�b�N���͒l�����ȏ�Ȃ�ړ����x&�A�j���[�V�������x�A�b�v
	if (xbuf >= RUN_XBUF || -RUN_XBUF >= xbuf) {
		_spd = RUNSPEED;
		_move_animespeed = ANIMESPEED_RUN;
	}
}
//�|�[�Y�̓��͊Ǘ��֐�
void Player::PauseInput(Game& g) {
	//�v���C���[���ҋ@��Ԃ܂��͈ړ���Ԏ��̂ݓ��͎�t
	if (_state == PLAYERSTATE::IDLE || _state == PLAYERSTATE::MOVE) {
		_pauseinput_flag = true;
	}
	else { _pauseinput_flag = false; }
	//12�{�^�������Ń|�[�Y��ʐ���&�Q�[���̏����X�g�b�v
	if (g.GetTrg() & PAD_INPUT_12 && _pauseinput_flag == true) {
		auto mp = new ModePause();
		g.GetMS()->Add(mp, 20, "Pause");
		auto mg = (ModeGame*)g.GetMS()->Get("Game");
		mg->SetStopObjProcess(true);
	}
}

//�Q�[�WMAX���̎��@����&SE����
void Player::GaugeMax(Game& g) {
	if (_iai_gauge == 5&& _gaugemax_flag ==false) {
		//���@�����p�[�e�B�N��
		for (int i = 0; i < GAGEMAX_PARTICLE_QTY; i++)
		{
			std::pair<int, int> xy = std::make_pair(_x, _y);
			std::pair<double, double> dxy = std::make_pair(((rand() % GAGEMAX_PARTICLE_RANDOMX1) - GAGEMAX_PARTICLE_RANDOMX2) / GAGEMAX_PARTICLE_RANDOMX3, ((rand() % GAGEMAX_PARTICLE_RANDOMY1) - GAGEMAX_PARTICLE_RANDOMY2) / GAGEMAX_PARTICLE_RANDOMY3);
			auto gm = new GageMax(xy, dxy);
			g.GetOS()->Add(gm);
		}
		//SE
		PlaySoundMem(_se["Gage"], DX_PLAYTYPE_BACK, true);
		_gaugemax_flag = true;
	}
}