/*
** �v���C���[
*/

#include <DxLib.h>
#include "ResourceServer.h"
#include "Player.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ModeGame.h"
#include "PlayerHp.h"
#include "IaiGauge.h"
#include <vector>
#include <sstream>

using namespace PInfo;
Player::Player(int x,int y) :
	_State(PLAYERSTATE::IDLE),
	_Move_AnimeSpeed(0),
	_Star_Flag(false),
	_UI_Flag(false)
{
	_x = x;
	_y = y;
	Init();
	LoadActionGraph();
	LoadActionSE();
}

Player::~Player()
{	
}

void Player::Init()
{
	// �v���C���[���̏�����
	_GrHandle = -1;
	_w = GRAPH_WIDTH;
	_h = GRAPH_HEIGHT;
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
	_Life = LIFE_MAX;
	_Spd = 0;
	_Iai_Gauge = 0;
	_isFlip = FIRST_FLIP;
	_Alpha = FIRST_ALPHA;
	_Position = { 0,0 };
	_CameraX = 500;
}


void Player::Process(Game& g)
{
	ObjectBase::Process(g);
	//UI�̃C���X�^���X����
	UIAppear(g);
	//���X�e�B�b�N�̓��͗ʂɂ��X�e�[�^�X�ݒ�
	BufSetting(g);
	//�v���C���[�̃C�x���g����
	EventChange(g);
	/*---��Ԗ��̏���---*/
		//���G���
		Star(g);
	switch (_State) {
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
	//�v���C���[�ʒu����̃J�����ʒu�ݒ�
	CameraSetting(g);
}

void Player::Draw(Game& g) {
#ifdef _DEBUG
	DebugDraw(g);
#endif
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Alpha);
	ObjectBase::Draw(g);
}

void Player::Delete(Game& g) {
		g.GetOS()->Del(this);
}
//�v���C���[�̉摜�ǂݍ��݊֐�
void Player::LoadActionGraph() {
	_GrAll["Idle"].resize(IDLE_ANIMEMAX);
	ResourceServer::LoadDivGraph(IDLE_GRAPHNAME, IDLE_ANIMEMAX, IDLE_WIDTHCOUNT, IDLE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Idle"].data());
	_GrAll["Move"].resize(MOVE_ANIMEMAX);
	ResourceServer::LoadDivGraph(MOVE_GRAPHNAME, MOVE_ANIMEMAX, MOVE_WIDTHCOUNT, MOVE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Move"].data());
	_GrAll["MiddleAttack"].resize(MIDDLEATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(MIDDLEATTACK_GRAPHNAME, MIDDLEATTACK_ANIMEMAX, MIDDLEATTACK_WIDTHCOUNT, MIDDLEATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["MiddleAttack"].data());
	_GrAll["LowAttack"].resize(LOWATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(LOWATTACK_GRAPHNAME, LOWATTACK_ANIMEMAX, LOWATTACK_WIDTHCOUNT, LOWATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["LowAttack"].data());
	_GrAll["Kick"].resize(KICK_ANIMEMAX);
	ResourceServer::LoadDivGraph(KICK_GRAPHNAME, KICK_ANIMEMAX, KICK_WIDTHCOUNT, KICK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Kick"].data());
	_GrAll["Iai"].resize(IAI_ANIMEMAX);
	ResourceServer::LoadDivGraph(IAI_GRAPHNAME, IAI_ANIMEMAX, IAI_WIDTHCOUNT, IAI_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Iai"].data());
	_GrAll["Sway"].resize(SWAY_ANIMEMAX);
	ResourceServer::LoadDivGraph(SWAY_GRAPHNAME, SWAY_ANIMEMAX, SWAY_WIDTHCOUNT, SWAY_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Sway"].data());
	_GrAll["Damage"].resize(DAMAGE_ANIMEMAX);
	ResourceServer::LoadDivGraph(DAMAGE_GRAPHNAME, DAMAGE_ANIMEMAX, DAMAGE_WIDTHCOUNT, DAMAGE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Damage"].data());
	_GrAll["Dead"].resize(DEAD_ANIMEMAX);
	ResourceServer::LoadDivGraph(DEAD_GRAPHNAME, DEAD_ANIMEMAX, DEAD_WIDTHCOUNT, DEAD_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Dead"].data());
	_GrAll["Special"].resize(SPECIALATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(SPECIALATTACK_GRAPHNAME, SPECIALATTACK_ANIMEMAX, SPECIALATTACK_WIDTHCOUNT, SPECIALATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Special"].data());
}

//�v���C���[�̌��ʉ��ǂݍ��݊֐�
void Player::LoadActionSE() {
	_Se["Walk"] =		ResourceServer::LoadSoundMem("se/Footstep.wav");
	_Se["MiddleAttack"]=ResourceServer::LoadSoundMem("se/slash3.wav");
	_Se["LowAttack"] =	ResourceServer::LoadSoundMem("se/Slash.wav");
	_Se["Kick"] =		ResourceServer::LoadSoundMem("se/Kick.wav");
	_Se["Damage"] =		ResourceServer::LoadSoundMem("se/Damage.wav");
	_Se["SwordIn"] =	ResourceServer::LoadSoundMem("se/Close.wav");
	_Se["Iai"] =		ResourceServer::LoadSoundMem("se/Iai.wav");
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
	ss << "�̗�=" << _Life << "\n";
	ss << "����=" << _Spd << "\n";
	ss << "�J��������=" << _CameraX << "\n";
	ss << "�t���[��=" << _Cnt-_Action_Cnt << "\n";
	DrawString(10, 10, ss.str().c_str(), GetColor(255, 0, 0));
}

//UI�C���X�^���X�����֐�
void Player::UIAppear(Game& g){
	if (_UI_Flag == false) {
		auto hp1 = new PlayerHp(0);
		g.GetOS()->Add(hp1);
		auto hp2 = new PlayerHp(1);
		g.GetOS()->Add(hp2);
		auto hp3 = new PlayerHp(2);
		g.GetOS()->Add(hp3);
		auto ig = new IaiGauge();
		g.GetOS()->Add(ig);
		_UI_Flag = true;
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
//���G��Ԏ��̏���
void Player::Star(Game& g) {
	if (_Star_Flag == true) {
		_Alpha = FIRST_ALPHA;
		if ((_Cnt / ANIMESPEED_STAR % 2) == 0) {
			_Alpha = STAR_ALPHA;
		}
		if (_Cnt - _Star_Cnt == STAR_ALLFRAME) {
			_Alpha = FIRST_ALPHA;
			_Star_Flag = false;
		}
	}
}
//���X�e�B�b�N�̓��͗ʂɂ��X�e�[�^�X�ݒ�
void Player::BufSetting(Game& g) {
	auto xbuf = g.GetXBuf();
	if (xbuf < MAX_BUF - RUN_XBUF && -(MAX_BUF - RUN_XBUF) < xbuf) {
		_Spd = WALKSPEED;
		_Move_AnimeSpeed = ANIMESPEED_WALK;
	}
	if (xbuf >= RUN_XBUF || -RUN_XBUF >= xbuf) {
		_Spd = RUNSPEED;
		_Move_AnimeSpeed = ANIMESPEED_RUN;
	}
}
//�v���C���[�̃C�x���g����
void Player::EventChange(Game& g) {
	//�{�X�X�e�[�W�̃C�x���g������ԑJ�ڗp�֐�
	if (_BEventA_Flag == true) {
		_Action_Cnt = _Cnt;
		_State = PLAYERSTATE::EVENTA;
		_BEventA_Flag = false;
	}
	if (_BEventB_Flag == true) {
		_Action_Cnt = _Cnt;
		_State = PLAYERSTATE::EVENTB;
		_BEventB_Flag = false;
	}
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�͉񕜔��肩�H
		if ((*ite)->GetObjType() == OBJECTTYPE::RECOVERYBLOCK)
		{
			// �v���C���[�Ƃ��̉񕜔���̓����蔻����s��
			if (IsHit(*(*ite)) == true) {
				(*ite)->Delete(g);
				_Life = 3;
			}
		}
	}
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�̓`�F�b�N�|�C���g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::CPOINTBLOCK)
		{
			// �v���C���[�Ƃ��̉񕜔���̓����蔻����s��
			if (IsHit(*(*ite)) == true) {
				(*ite)->Delete(g);
				g.SetCPointFlag(true);
			}
		}
	}
}