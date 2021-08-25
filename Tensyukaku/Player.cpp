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
#include <vector>
#include <sstream>

using namespace PInfo;
Player::Player() :
	_Idle_AnimeNo(0),
	_Move_AnimeNo(0),
	_MiddleAttack_AnimeNo(0),
	_LowAttack_AnimeNo(0),
	_Kick_AnimeNo(0),
	_Iai_AnimeNo(0),
	/*_Sway_GrHandle(-1),
	_Sway_AnimeNo(0),*/
	_Damage_AnimeNo(0),
	_Dead_AnimeNo(0),
	_Walk_SEHandle(-1),
	_MiddleAttack_SEHandle(-1),
	_LowAttack_SEHandle(-1),
	_Kick_SEHandle(-1),
	_Damage_SEHandle(-1),
	_SwordIn_SEHandle(-1),
	_Iai_SEHandle(-1),
	_State(PLAYERSTATE::IDLE),
	_Star_Flag(false)
{
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
	_x = POSITION_X;
	_y = POSITION_Y;
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
	_Life = LIFE_MAX;
	_Spd = SPEED;
	_isFlip = true;
	_position = { 0,0 };
}


void Player::Process(Game& g)
{
	ObjectBase::Process(g);
	AnimeUpdate(g);

	/*---��Ԗ��̏���---*/
		//���G���
	if (_Star_Flag == true) {
		if (_Cnt - _Star_Cnt == STAR_ALLFRAME) {
			_Star_Flag = false;
		}
	}
	
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
	//case PLAYERSTATE::SWAY:
	//	Sway(g);
	//	break;
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
	}
	// ��l���ʒu����J�������W����
	g.SetcvX(_x- (SCREEN_W * BACK_CAMERA_X / 100));// �w�i�̉������ɃL������u��
	g.SetcvY(_y - (SCREEN_H * BACK_CAMERA_Y / 100));// �w�i�̏c93%�ɃL������u��
	if (g.GetcvX() < 0) { g.SetcvX(0); }
	if (g.GetcvX() > g.GetmapW()-SCREEN_W) { g.SetcvX(g.GetmapW() - SCREEN_W); }
	if (g.GetcvY() < 0) { g.SetcvY(0); }
	if (g.GetcvY() > g.GetmapH() - SCREEN_H) { g.SetcvY(g.GetmapH() - SCREEN_H); }
	auto GC = g.GetChip();
	GC->SetscrX(_x - (SCREEN_W * CHIP_CAMERA_X / 100));	// �}�b�v�`�b�v�̉������ɃL������u��
	GC->SetscrY(_y - (SCREEN_H * CHIP_CAMERA_Y / 100));	// �}�b�v�`�b�v�̏c93%�ɃL������u��
	if (GC->GetscrX() < 0) { GC->SetscrX(0); }
	if (GC->GetscrX() > GC->GetMSW() * GC->GetCSW() - SCREEN_W) { GC->SetscrX(GC->GetMSW() * GC->GetCSW() - SCREEN_W); }
	if (GC->GetscrY() < 0) { GC->SetscrY(0); }
	if (GC->GetscrY() > GC->GetMSH() * GC->GetCSH() - SCREEN_H) { GC->SetscrY(GC->GetMSH() * GC->GetCSH() - SCREEN_H); }
	
	
}

void Player::Draw(Game& g) {
	//���G��Ԃ̕`�揈��
	if (_Star_Flag == true && (_Cnt / ANIMESPEED_STAR % 2) == 0) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	}
#ifdef _DEBUG
	DebugDraw(g);
#endif
	ObjectBase::Draw(g);
	UIDraw(g);
}

void Player::Delete(Game& g) {
		g.GetOS()->Del(this);
}
//�v���C���[�̉摜�ǂݍ��݊֐�
void Player::LoadActionGraph() {
	_Idle_GrAll.resize(IDLE_ANIMEMAX);
	ResourceServer::LoadDivGraph(IDLE_GRAPHNAME, IDLE_ANIMEMAX, IDLE_WIDTHCOUNT, IDLE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _Idle_GrAll.data());
	_Move_GrAll.resize(MOVE_ANIMEMAX);
	ResourceServer::LoadDivGraph(MOVE_GRAPHNAME, MOVE_ANIMEMAX, MOVE_WIDTHCOUNT, MOVE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _Move_GrAll.data());
	_MiddleAttack_GrAll.resize(MIDDLEATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(MIDDLEATTACK_GRAPHNAME, MIDDLEATTACK_ANIMEMAX, MIDDLEATTACK_WIDTHCOUNT, MIDDLEATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _MiddleAttack_GrAll.data());
	_LowAttack_GrAll.resize(LOWATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(LOWATTACK_GRAPHNAME, LOWATTACK_ANIMEMAX, LOWATTACK_WIDTHCOUNT, LOWATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _LowAttack_GrAll.data());
	_Kick_GrAll.resize(KICK_ANIMEMAX);
	ResourceServer::LoadDivGraph(KICK_GRAPHNAME, KICK_ANIMEMAX, KICK_WIDTHCOUNT, KICK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _Kick_GrAll.data());
	_Iai_GrAll.resize(IAI_ANIMEMAX);
	ResourceServer::LoadDivGraph(IAI_GRAPHNAME, IAI_ANIMEMAX, IAI_WIDTHCOUNT, IAI_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _Iai_GrAll.data());
	/*_Sway_GrAll.resize(SWAY_ANIMEMAX);
	ResourceServer::LoadDivGraph(SWAY_GRAPHNAME, SWAY_ANIMEMAX, SWAY_WIDTHCOUNT, SWAY_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _Sway_GrAll.data());*/
	_Damage_GrAll.resize(DAMAGE_ANIMEMAX);
	ResourceServer::LoadDivGraph(DAMAGE_GRAPHNAME, DAMAGE_ANIMEMAX, DAMAGE_WIDTHCOUNT, DAMAGE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _Damage_GrAll.data());
	_Dead_GrAll.resize(DEAD_ANIMEMAX);
	ResourceServer::LoadDivGraph(DEAD_GRAPHNAME, DEAD_ANIMEMAX, DEAD_WIDTHCOUNT, DEAD_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _Dead_GrAll.data());
}

//�v���C���[�̌��ʉ��ǂݍ��݊֐�
void Player::LoadActionSE() {
	_Walk_SEHandle = ResourceServer::LoadSoundMem(WALK_SE);
	_MiddleAttack_SEHandle = ResourceServer::LoadSoundMem(MIDDLEATTACK_SE);
	_LowAttack_SEHandle = ResourceServer::LoadSoundMem(LOWATTACK_SE);
	_Kick_SEHandle= ResourceServer::LoadSoundMem(KICK_SE);
	_Damage_SEHandle= ResourceServer::LoadSoundMem(DAMAGE_SE);
	_SwordIn_SEHandle = ResourceServer::LoadSoundMem(SWORDIN_SE);
	_Iai_SEHandle = ResourceServer::LoadSoundMem(IAI_SE);
}

//�v���C���[�̃A�j���[�V�����֐�
void Player::AnimeUpdate(Game& g) {
	_Idle_AnimeNo = (_Cnt / ANIMESPEED_IDLE) % IDLE_ANIMEMAX;
	_Move_AnimeNo = (_Cnt / ANIMESPEED_MOVE) % MOVE_ANIMEMAX;
	_MiddleAttack_AnimeNo = ((_Cnt - _Action_Cnt) / ANIMESPEED_MIDDLEATTACK) % MIDDLEATTACK_ANIMEMAX;
	_LowAttack_AnimeNo = ((_Cnt - _Action_Cnt) / ANIMESPEED_LOWATTACK) % LOWATTACK_ANIMEMAX;
	_Kick_AnimeNo = ((_Cnt - _Action_Cnt) / ANIMESPEED_KICK) % KICK_ANIMEMAX;
	_Iai_AnimeNo = ((_Cnt - _Action_Cnt) / ANIMESPEED_IAI) % IAI_ANIMEMAX;
	_Damage_AnimeNo = ((_Cnt - _Action_Cnt) / ANIMESPEED_DAMAGE) % DAMAGE_ANIMEMAX;
	_Dead_AnimeNo = ((_Cnt - _Action_Cnt) / ANIMESPEED_DEAD) % DEAD_ANIMEMAX;
}

//�f�o�b�N�p�֐�
void Player::DebugDraw(Game& g) {
	std::stringstream ss;
	ss << "X�X�N���[���l=" << g.GetChip()->GetscrX() << "\n";
	ss << "Y�X�N���[���l=" << g.GetChip()->GetscrY() << "\n";
	ss << "�v���C���[X���W=" << _x << "\n";
	ss << "�v���C���[Y���W=" << _y << "\n";
	DrawString(10, 10, ss.str().c_str(), GetColor(255, 50, 255));
}

//�v���C���[��UI�`��֐�
void Player::UIDraw(Game& g) {
		PlayerHp* HP = new PlayerHp();
		HP->SetPosition(SCREEN_W - SCREEN_W+300 , SCREEN_H - 40);
		g.GetOS()->Add(HP);
	if (_Life >= 3) {
		DrawRotaGraph(HP->GetX(), HP->GetY(), GRAPH_SCALE, GRAPH_ANGLE, HP->GetHp3(), true, false);
		g.GetOS()->Del(HP);
	}
	else if (_Life == 2) {
		DrawRotaGraph(HP->GetX(), HP->GetY(), GRAPH_SCALE, GRAPH_ANGLE, HP->GetHp2(), true, false);
		g.GetOS()->Del(HP);
	}
	else if (_Life == 1) {
		DrawRotaGraph(HP->GetX(), HP->GetY(), GRAPH_SCALE, GRAPH_ANGLE, HP->GetHp1(), true, false);
		g.GetOS()->Del(HP);
	}
	else if(_Life <= 0) { g.GetOS()->Del(HP); }
}