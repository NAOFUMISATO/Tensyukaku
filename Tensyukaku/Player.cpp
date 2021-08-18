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
	_w = GraphWidth;
	_h = GraphHeight;
	_x = PositionX;
	_y = PositionY;
	_gx = GraphPointX;
	_gy = GraphPointY;
	_hit_x = PositionHitX;
	_hit_y = PositionHitY;
	_hit_w = CollisionWidth;
	_hit_h = CollisionHeight;
	_Life = LifeMax;
	_Spd = Speed;
	_isFlip = false;
}


void Player::Process(Game& g)
{
	ObjectBase::Process(g);
	
	AnimeUpdate(g);

	/*---��Ԗ��̏���---*/
		//���G���
	if (_Star_Flag == true) {
		if (_Cnt - _Star_Cnt == Star_Frame) {
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
	}
	// ��l���ʒu����J�������W����
	g.SetcvX(_x - (SCREEN_W * BackCameraX / 100));
	g.SetcvY(_y - (SCREEN_H * BackCameraY / 100));
	if (g.GetcvX() < 0) { g.SetcvX(0); }
	if (g.GetcvX() > g.GetmapW()-SCREEN_W) { g.SetcvX(g.GetmapW() - SCREEN_W); }
	if (g.GetcvY() < 0) { g.SetcvY(0); }
	if (g.GetcvY() > g.GetmapH() - SCREEN_H) { g.SetcvY(g.GetmapH() - SCREEN_H); }
	auto GC = g.GetChip();
	GC->SetscrX(_x - (SCREEN_W * ChipCameraX / 100));		// ��ʂ̉������ɃL������u��
	GC->SetscrY(_y - (SCREEN_H * ChipCameraY / 100));	// ��ʂ̏c92.55%�ɃL������u��
	if (GC->GetscrX() < 0) { GC->SetscrX(0); }
	if (GC->GetscrX() > GC->GetMSW() * GC->GetCSW() - SCREEN_W) { GC->SetscrX(GC->GetMSW() * GC->GetCSW() - SCREEN_W); }
	if (GC->GetscrY() < 0) { GC->SetscrY(0); }
	if (GC->GetscrY() > GC->GetMSH() * GC->GetCSH() - SCREEN_H) { GC->SetscrY(GC->GetMSH() * GC->GetCSH() - SCREEN_H); }
}

void Player::Draw(Game& g) {
	UIDraw(g);
	//���G��Ԃ̕`�揈��
	if (_Star_Flag == true && (_Cnt / AnimeSpeed_Star % 2) == 0) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	}
	ObjectBase::Draw(g);
#ifdef _DEBUG
	std::stringstream ss;
	ss << "_Cnt=" << _Cnt << "\n";
	ss << "_scrX=" << g.GetChip()->GetscrX() << "\n";
	ss << "_scrY=" << g.GetChip()->GetscrY() << "\n";
	ss << "PlayerX=" << _x << "\n";
	ss << "PlayerY=" << _y << "\n";
	ss << "MidNo=" <<_MiddleAttack_AnimeNo<< "\n";
	ss << "LowNo=" << _LowAttack_AnimeNo << "\n";
	DrawString(10, 10, ss.str().c_str(), GetColor(255, 50, 255));
#endif

}

void Player::Delete(Game& g) {
		g.GetOS()->Del(this);
}
//�v���C���[�̉摜�ǂݍ��݊֐�
void Player::LoadActionGraph() {
	_Idle_GrAll.resize(Idle_AnimeMax);
	ResourceServer::LoadDivGraph(Idle_GraphName, Idle_AnimeMax, Idle_WidthCount, Idle_HeightCount, GraphWidth, GraphHeight, _Idle_GrAll.data());
	_Move_GrAll.resize(Move_AnimeMax);
	ResourceServer::LoadDivGraph(Move_GraphName, Move_AnimeMax, Move_WidthCount, Move_HeightCount, GraphWidth, GraphHeight, _Move_GrAll.data());
	_MiddleAttack_GrAll.resize(MiddleAttack_AnimeMax);
	ResourceServer::LoadDivGraph(MiddleAttack_GraphName, MiddleAttack_AnimeMax, MiddleAttack_WidthCount, MiddleAttack_HeightCount, GraphWidth, GraphHeight, _MiddleAttack_GrAll.data());
	_LowAttack_GrAll.resize(LowAttack_AnimeMax);
	ResourceServer::LoadDivGraph(LowdAttack_GraphName, LowAttack_AnimeMax, LowAttack_WidthCount, LowAttack_HeightCount, GraphWidth, GraphHeight, _LowAttack_GrAll.data());
	_Kick_GrAll.resize(Kick_AnimeMax);
	ResourceServer::LoadDivGraph(Kick_GraphName, Kick_AnimeMax, Kick_WidthCount, Kick_HeightCount, GraphWidth, GraphHeight, _Kick_GrAll.data());
	_Iai_GrAll.resize(Iai_AnimeMax);
	ResourceServer::LoadDivGraph(Iai_GraphName, Iai_AnimeMax, Iai_WidthCount, Iai_HeightCount, GraphWidth, GraphHeight, _Iai_GrAll.data());
	/*_Sway_GrAll.resize(Sway_AnimeMax);
	ResourceServer::LoadDivGraph(Sway_GraphName, Sway_AnimeMax, Sway_WidthCount, Sway_HeightCount, GraphWidth, GraphHeight, _Sway_GrAll.data());*/
	_Damage_GrAll.resize(Damage_AnimeMax);
	ResourceServer::LoadDivGraph(Damage_GraphName, Damage_AnimeMax, Damage_WidthCount, Damage_HeightCount, GraphWidth, GraphHeight, _Damage_GrAll.data());
	_Dead_GrAll.resize(Dead_AnimeMax);
	ResourceServer::LoadDivGraph(Dead_GraphName, Dead_AnimeMax, Dead_WidthCount, Dead_HeightCount, GraphWidth, GraphHeight, _Dead_GrAll.data());
}

//�v���C���[�̌��ʉ��ǂݍ��݊֐�
void Player::LoadActionSE() {
	_Walk_SEHandle = ResourceServer::LoadSoundMem(Walk_SE);
	_MiddleAttack_SEHandle = ResourceServer::LoadSoundMem(MiddleAttack_SE);
	_LowAttack_SEHandle = ResourceServer::LoadSoundMem(LowAttack_SE);
	_Kick_SEHandle= ResourceServer::LoadSoundMem(Kick_SE);
	_Damage_SEHandle= ResourceServer::LoadSoundMem(Damage_SE);
	_SwordIn_SEHandle = ResourceServer::LoadSoundMem(SwordIn_SE);
	_Iai_SEHandle = ResourceServer::LoadSoundMem(Iai_SE);
}

//�v���C���[�̃A�j���[�V�����֐�
void Player::AnimeUpdate(Game& g) {
	_Idle_AnimeNo = (_Cnt / AnimeSpeed_Idle) % Idle_AnimeMax;
	_Move_AnimeNo = (_Cnt / AnimeSpeed_Move) % Move_AnimeMax;
	_MiddleAttack_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_MiddleAttack) % MiddleAttack_AnimeMax;
	_LowAttack_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_LowAttack) % LowAttack_AnimeMax;
	_Kick_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Kick) % Kick_AnimeMax;
	_Iai_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Iai) % Iai_AnimeMax;
	_Damage_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Damage) % Damage_AnimeMax;
	_Dead_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Dead) % Dead_AnimeMax;
}

//�v���C���[��UI�`��֐�

void Player::UIDraw(Game& g) {
		PlayerHp* HP = new PlayerHp();
		HP->SetPosition(SCREEN_W - SCREEN_W+300 , SCREEN_H - 40);
		g.GetOS()->Add(HP);
	if (_Life >= 3) {
		DrawRotaGraph(HP->GetX(), HP->GetY(), GraphScale, GraphAngle, HP->GetHp3(), true, false);
		g.GetOS()->Del(HP);
	}
	else if (_Life == 2) {
		DrawRotaGraph(HP->GetX(), HP->GetY(), GraphScale, GraphAngle, HP->GetHp2(), true, false);
		g.GetOS()->Del(HP);
	}
	else if (_Life == 1) {
		DrawRotaGraph(HP->GetX(), HP->GetY(), GraphScale, GraphAngle, HP->GetHp1(), true, false);
		g.GetOS()->Del(HP);
	}
	else if(_Life <= 0) { g.GetOS()->Del(HP); }
}