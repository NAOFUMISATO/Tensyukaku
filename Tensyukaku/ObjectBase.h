#pragma once
#include "HitBox.h"
#include <vector>
namespace Tsk {
	class Game;
	// �I�u�W�F�N�g�N���X
	class ObjectBase {
	public:
		ObjectBase();
		~ObjectBase();
		//�I�u�W�F�N�g�̎�ޗ�
		enum class OBJECTTYPE {
			PLAYER, ENEMY, MIDDLEATTACK, LOWATTACK,
			BUSHIPATROL, BUSHICOMING, BUSHIATTACK,
		};
		virtual OBJECTTYPE	GetObjType() = 0;

		virtual	void	Init();
		virtual	void	Process(Game& g);
		virtual	void	Draw(Game& g);
		virtual	bool	IsHit(ObjectBase& o);
		virtual	void	Damage(Game& g) {};

		void	SetPosition(int x, int y) { _x = x; _y = y; }
		int		GetX() { return _x; }
		int		GetY() { return _y; }
		int		GetW() { return _w; }
		int		GetH() { return _h; }
		int		GetHitX(){ return _hit_x;}
		int		GetHitY() { return _hit_y; }
		int		GetHitW() { return _hit_w; }
		int		GetHitH() { return _hit_h; }
		HitBox	GetHB() { return { _x,_y,_hit_x,_hit_y,_hit_w,_hit_h }; }
		void	SetX(int x) { _x = x; }
		void	SetY(int y) { _y = y; }

	protected:
		int		_x, _y;		// ���W�i��ʒu�j
		int		_gx, _gy;	// ��ʒu����`�掞�̍���
		int		_w, _h;		// �傫��
		int		_Life;		// �̗�
		int		_Spd;		// �ړ����x
		int		_g;			// �d�͉����l
		int		_stand;		// ���t���O�B���n���Ă�����1
		bool	_isFlip;	//���]����
		// �����蔻��p�i���W_x,_y�ʒu����̍����j
		int		_hit_x, _hit_y;
		int		_hit_w, _hit_h;
		int		_hit_noCnt;	// �J�E���^��1�ȏ�̏ꍇ�͓����蔻�肵�Ȃ�
		int		_hit_main;	// �U�����̏ꍇ�ɓ����蔻�肷��Ȃ�1
		int		_hit_sub;	// �_���[�W���̏ꍇ�ɓ����蔻�肷��Ȃ�1
		int		_Cnt;		// ����J�E���^
		int		_Action_Cnt;	//�A�N�V�����o�ߎ��ԋL�^�ϐ�

	};
}