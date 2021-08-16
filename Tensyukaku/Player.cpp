/*
** �v���C���[
*/

#include <DxLib.h>
#include "ResourceServer.h"
#include "Player.h"
#include "PLayerMotionCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ModeGame.h"
#include "PlayerHp.h"
#include "Ninja.h"
#include "Bushi.h"
#include <vector>
#include <sstream>



using namespace PInfo;
Player::Player() :
	_Idle_GrHandle(-1),
	_Idle_AnimeNo(0),
	_Move_GrHandle(-1),
	_Move_AnimeNo(0),
	_MiddleAttack_GrHandle(-1),
	_MiddleAttack_AnimeNo(0),
	_LowAttack_GrHandle(-1),
	_LowAttack_AnimeNo(0),
	_Kick_GrHandle(-1),
	_Kick_AnimeNo(0),
	/*_Iai_GrHandle(-1),
	_Iai_AnimeNo(0),
	_Sway_GrHandle(-1),
	_Sway_AnimeNo(0),*/
	_Damage_GrHandle(-1),
	_Damage_AnimeNo(0),
	_Dead_GrHandle(-1),
	_Dead_AnimeNo(0),
	_Walk_SEHandle(-1),
	_MiddleAttack_SEHandle(-1),
	_LowAttack_SEHandle(-1),
	_Kick_SEHandle(-1),
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
	g.SetcvX(_x - (SCREEN_W / 2));
	g.SetcvY(_y - (SCREEN_H * 92.55 / 100));
	if (g.GetcvX() < 0) { g.SetcvX(0); }
	if (g.GetcvX() > g.GetmapW()-SCREEN_W) { g.SetcvX(g.GetmapW() - SCREEN_W); }
	if (g.GetcvY() < 0) { g.SetcvY(0); }
	if (g.GetcvY() > g.GetmapH() - SCREEN_H) { g.SetcvY(g.GetmapH() - SCREEN_H); }
	auto GC = g.GetChip();
	GC->SetscrX(_x - (SCREEN_W / 2));		// ��ʂ̉������ɃL������u��
	GC->SetscrY(_y - (SCREEN_H * 92.55 / 100));	// ��ʂ̏c92.55%�ɃL������u��
	if (GC->GetscrX() < 0) { GC->SetscrX(0); }
	if (GC->GetscrX() > GC->GetMSW() * GC->GetCSW() - SCREEN_W) { GC->SetscrX(GC->GetMSW() * GC->GetCSW() - SCREEN_W); }
	if (GC->GetscrY() < 0) { GC->SetscrY(0); }
	if (GC->GetscrY() > GC->GetMSH() * GC->GetCSH() - SCREEN_H) { GC->SetscrY(GC->GetMSH() * GC->GetCSH() - SCREEN_H); }
}
void Player::Draw(Game& g) {
	/*UIDraw(g);*/
	// �J�������猩�����W�ɕύX�i���[���h���W���r���[���W�j
	auto GC = g.GetChip();
	auto x = _x + _gx - GC->GetscrX();
	auto y = _y + _gy - GC->GetscrY();

	//�v���C���[�̏�Ԃɂ��A�j���[�V�����J��
		//���G���
	if (_Star_Flag == true && (_Cnt / AnimeSpeed_Star % 2) == 0) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	}
	switch (_State) {
		//�ҋ@���
	case PLAYERSTATE::IDLE:
		_Idle_AnimeNo = (_Cnt / AnimeSpeed_Idle) % Idle_AnimeMax;
		_Idle_GrHandle = _Idle_GrAll[_Idle_AnimeNo];
		DrawRotaGraph(x, y, GraphScale, GraphAngle, _Idle_GrHandle, true, _isFlip);
		break;
		//�ړ����
	case PLAYERSTATE::MOVE:
		_Move_AnimeNo = (_Cnt / AnimeSpeed_Move) % Move_AnimeMax;
		_Move_GrHandle = _Move_GrAll[_Move_AnimeNo];
		DrawRotaGraph(x, y, GraphScale, GraphAngle, _Move_GrHandle, true, _isFlip);
		break;
		//���i�U�����
	case PLAYERSTATE::MIDDLEATTACK:
		_MiddleAttack_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_MiddleAttack) % MiddleAttack_AnimeMax;
		_MiddleAttack_GrHandle = _MiddleAttack_GrAll[_MiddleAttack_AnimeNo];
		DrawRotaGraph(x, y, GraphScale, GraphAngle, _MiddleAttack_GrHandle, true, _isFlip);
		break;
		//���i�U�����
	case PLAYERSTATE::LOWATTACK:
		_LowAttack_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_LowAttack) % LowAttack_AnimeMax;
		_LowAttack_GrHandle = _LowAttack_GrAll[_LowAttack_AnimeNo];
		DrawRotaGraph(x, y, GraphScale, GraphAngle, _LowAttack_GrHandle, true, _isFlip);
		break;
		//�R����
	case PLAYERSTATE::KICK:
		_Kick_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Kick) % Kick_AnimeMax;
		_Kick_GrHandle = _Kick_GrAll[_Kick_AnimeNo];
		DrawRotaGraph(x, y, GraphScale, GraphAngle, _Kick_GrHandle, true, _isFlip);
		break;
		//�������
	//case PLAYERSTATE::IAI:
	//	break;
	//	//�X�E�F�C���
	//case PLAYERSTATE::SWAY:
	//	break;
		//��_�����
	case PLAYERSTATE::DAMAGE:
		_Damage_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Damage) % Damage_AnimeMax;
		_Damage_GrHandle = _Damage_GrAll[_Damage_AnimeNo];
		DrawRotaGraph(x, y, GraphScale, GraphAngle, _Damage_GrHandle, true, _isFlip);
		break;
		//���S���
	case PLAYERSTATE::DEAD:
		_Dead_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Dead) % Dead_AnimeMax;
		_Dead_GrHandle = _Dead_GrAll[_Dead_AnimeNo];
		DrawRotaGraph(x, y, GraphScale, GraphAngle, _Dead_GrHandle, true, _isFlip);
		break;
	}
	
	/*-----�f�o�b�O�`��-----*/
#ifdef _DEBUG
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// �������`��w��
	DrawBox(x + _hit_x, y + _hit_y, x + _hit_x + _hit_w, y + _hit_y + _hit_h, GetColor(255, 0, 0), FALSE);	// �������̐Ԃœ����蔻��`��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// �s�����`��w��
	std::stringstream ss;
	ss << "_Cnt=" << _Cnt << "\n";
	ss << "_scrX=" << g.GetChip()->GetscrX() << "\n";
	ss << "_scrY=" << g.GetChip()->GetscrY() << "\n";
	ss << "PlayerX=" << _x << "\n";
	ss << "PlayerY=" << _y << "\n";
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
}


//�v���C���[��UI�`��֐�

void Player::UIDraw(Game& g) {
		PlayerHp* HP = new PlayerHp();
		g.GetOS()->Add(HP);
	if (_Life == 3) {
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