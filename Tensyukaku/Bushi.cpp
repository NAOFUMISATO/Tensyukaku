#include <DxLib.h>
#include <vector>
#include <sstream>
#include "EnemyBase.h"
#include "Bushi.h"
#include "Game.h"
#include "ResourceServer.h"
#include "ObjectBase.h"
using namespace Tsk;
using namespace BInfo;
Bushi::Bushi() :
	_Patrol_GrHandle(-1),
	_Patrol_AnimeNo(0),
	_Coming_GrHandle(-1),
	_Coming_AnimeNo(0),
	_Attack_GrHandle(-1),
	_Attack_AnimeNo(0),
	_Walk_SEHandle(-1),
	_Attack_SEHandle(-1),
	_Patrol_Flag(false)
{
	Init();
	LoadActionGraph();
};

Bushi::~Bushi() {};

void Bushi::Init() {
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
	ENEMYSTATE::PATROL;
	_Life = LifeMax;
	_Spd = Speed;
	_isFlip = false;
}
void Bushi::Process(Game& g) {
	EnemyBase::Process(g);
	switch (_State) {
	case ENEMYSTATE::PATROL:
		Patrol(g);
		break;
	case ENEMYSTATE::COMING:
		
	case ENEMYSTATE::ATTACK:
		break;
	case ENEMYSTATE::DAMAGE:
		break;
	case ENEMYSTATE::DEAD:
		break;
	}
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�̓v���C���[�̍U���I�u�W�F�N�g���H
		if ((*ite)->GetObjType() == OBJECTTYPE::MIDDLEATTACK)
		{ 
			// �G�Ƃ��̍U���̓����蔻����s��
		if (IsHitCO(*(*ite)) == true)
			{
				// �G�ƍU�����ꂼ��̃_���[�W����
				Damage(g);				// this �͂��̃I�u�W�F�N�g�i�G�j
				(*ite)->Damage(g);		// (*ite) �͍U���I�u�W�F�N�g
			}
		}
	}
}
void Bushi::Draw(Game& g) {
	auto x = _x + _gx;
	auto y = _y + _gy;

	//���m�̏�Ԃɂ��A�j���[�V�����J��
	switch (_State) {
		//������
	case ENEMYSTATE::PATROL:
		_Patrol_AnimeNo = (_Cnt / AnimeSpeed_Patrol) % Patrol_AnimeMax;
		_Patrol_GrHandle = _Patrol_GrAll[_Patrol_AnimeNo];
		DrawRotaGraph(x, y, GraphScale, GraphAngle, _Patrol_GrHandle, true, _isFlip);
		break;
		//�ǐՏ��
	case ENEMYSTATE::COMING:
		_Coming_AnimeNo = (_Cnt / AnimeSpeed_Move) % Coming_AnimeMax;
		_Coming_GrHandle = _Coming_GrAll[_Coming_AnimeNo];
		if (g.GetKey() & PAD_INPUT_LEFT) {
			DrawRotaGraph(x, y, GraphScale, GraphAngle, _Coming_GrHandle, true, _isFlip);
		}
		else if (g.GetKey() & PAD_INPUT_RIGHT) {
			DrawRotaGraph(x, y, GraphScale, GraphAngle, _Coming_GrHandle, true, _isFlip);
		}
		break;
		//�U�����
	case ENEMYSTATE::ATTACK:
		_Attack_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Attack) % Attack_AnimeMax;
		_Attack_GrHandle = _Attack_GrAll[_Attack_AnimeNo];
		DrawRotaGraph(x, y, GraphScale, GraphAngle, _Attack_GrHandle, true, _isFlip);
		break;
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// �������`��w��
	DrawBox(x + _hit_x, y + _hit_y, x + _hit_x + _hit_w, y + _hit_y + _hit_h, GetColor(255, 0, 0), FALSE);	// �������̐Ԃœ����蔻��`��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// �s�����`��w��
	std::stringstream ss;
	ss << "_Cnt=" << _Cnt << "\n";
	ss << "_ActionCnt=" << _Action_Cnt << "\n";
	
	DrawString(x - 100, y + 100, ss.str().c_str(), GetColor(255, 50, 255));
}
void Bushi::Damage(Game& g) {
	--_Life;
	
	if (_Life == 0) {
		g.GetOS()->Del(this);
	}
}
//���m�̉摜�ǂݍ��݊֐�
void Bushi::LoadActionGraph() {
	_Patrol_GrAll.resize(Patrol_AnimeMax);
	ResourceServer::LoadDivGraph(Patrol_GraphName, Patrol_AnimeMax, Patrol_WidthCount, Patrol_HeightCount, GraphWidth, GraphHeight, _Patrol_GrAll.data());
	_Coming_GrAll.resize(Coming_AnimeMax);
	ResourceServer::LoadDivGraph(Coming_GraphName, Coming_AnimeMax, Coming_WidthCount, Coming_HeightCount, GraphWidth, GraphHeight, _Coming_GrAll.data());
	_Attack_GrAll.resize(Attack_AnimeMax);
	ResourceServer::LoadDivGraph(Attack_GraphName, Attack_AnimeMax, Attack_WidthCount, Attack_HeightCount, GraphWidth, GraphHeight, _Attack_GrAll.data());
}