#include <DxLib.h>
#include "EnemyBase.h"
#include "Bushi.h"
#include "Game.h"
#include "BushiComingCollision.h"
#include "ObjectBase.h"
using namespace Tsk;
using namespace BInfo;
void Bushi::Coming(Game& g) {
	if (_isFlip == false) {
		_x -= _Spd;
		//���m�̍��G�͈͔���I�u�W�F�N�g�̐���
		BushiComingCollision BCC;

		// ���m�̍��G�͈͔���I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
		BCC.SetPosition(_x + _hit_x - BCC.GetW(), _y - _hit_h);
		BCC.GetHitW();
		BCC.GetHitH();
		//���G�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{

				// ���G�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(BCC) == true)
				{
					_Action_Cnt = _Cnt;
					_State = Bushi::ENEMYSTATE::ATTACK;
				}
			}
		}
	}
	if (_isFlip == true) {
		_x += _Spd;
		//���m�̍��G�͈͔���I�u�W�F�N�g�̐���
		BushiComingCollision BCC;
		// ���m�̍��G�͈͔���I�u�W�F�N�g�̊J�n�ʒu���v���C���[�ʒu����Z�o
		BCC.SetPosition(_x - _hit_x, _y - _hit_h);
		BCC.GetHitW();
		BCC.GetHitH();
		BCC.Draw(g);
		//���G�͈̓I�u�W�F�N�g�̓v���C���[�ɓ����������H
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite�̓v���C���[���H
			if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
			{

				// ���G�͈̓I�u�W�F�N�g�ƃv���C���[�̓����蔻����s��
				if ((*ite)->IsHit(BCC) == true)
				{
					_Action_Cnt = _Cnt;
					_State = Bushi::ENEMYSTATE::ATTACK;
				}
			}
		}
	}
}