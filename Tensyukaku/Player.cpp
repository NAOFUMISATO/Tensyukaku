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
	_isFlip = FIRST_FLIP;
	_alpha = FIRST_ALPHA;
	_Position = { 0,0 };
}


void Player::Process(Game& g)
{
	ObjectBase::Process(g);
	AnimeUpdate(g);

	/*---��Ԗ��̏���---*/
		//���G���
	if (_Star_Flag == true) {
		_alpha = FIRST_ALPHA;
		if ((_Cnt / ANIMESPEED_STAR % 2) == 0) {
			_alpha = STAR_ALPHA;
		}
		if (_Cnt - _Star_Cnt == STAR_ALLFRAME) {
			_alpha = FIRST_ALPHA;
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
#ifdef _DEBUG
	DebugDraw(g);
#endif
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
	ObjectBase::Draw(g);
	UIDraw(g);
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
}

//�v���C���[�̌��ʉ��ǂݍ��݊֐�
void Player::LoadActionSE() {
	_Se["Walk"] = ResourceServer::LoadSoundMem(WALK_SE);
	_Se["MiddleAttack"] = ResourceServer::LoadSoundMem(MIDDLEATTACK_SE);
	_Se["LowAttack"] = ResourceServer::LoadSoundMem(LOWATTACK_SE);
	_Se["Kick"] = ResourceServer::LoadSoundMem(KICK_SE);
	_Se["Damage"] = ResourceServer::LoadSoundMem(DAMAGE_SE);
	_Se["SwordIn"] = ResourceServer::LoadSoundMem(SWORDIN_SE);
	_Se["Iai"] = ResourceServer::LoadSoundMem(IAI_SE);
}

//�v���C���[�̃A�j���[�V�����֐�
void Player::AnimeUpdate(Game& g) {
	auto frame = _Cnt - _Action_Cnt;
	_Anime["Idle"] = (_Cnt / ANIMESPEED_IDLE) % IDLE_ANIMEMAX;
	_Anime["Move"] = (_Cnt / ANIMESPEED_MOVE) % MOVE_ANIMEMAX;
	_Anime["MiddleAttack"] = ((frame) / ANIMESPEED_MIDDLEATTACK) % MIDDLEATTACK_ANIMEMAX;
	_Anime["LowAttack"] = ((frame) / ANIMESPEED_LOWATTACK) % LOWATTACK_ANIMEMAX;
	_Anime["Kick"] = ((frame) / ANIMESPEED_KICK) % KICK_ANIMEMAX;
	_Anime["Iai"] = ((frame) / ANIMESPEED_IAI) % IAI_ANIMEMAX;
	_Anime["Sway"] = ((frame) / ANIMESPEED_IAI) % SWAY_ANIMEMAX;
	_Anime["Damage"] = ((frame) / ANIMESPEED_DAMAGE) % DAMAGE_ANIMEMAX;
	_Anime["Dead"] = ((frame) / ANIMESPEED_DEAD) % DEAD_ANIMEMAX;
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