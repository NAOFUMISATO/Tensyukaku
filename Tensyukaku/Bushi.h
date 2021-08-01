#pragma once
#include "EnemyBase.h"
#include <vector>
// ���m�N���X
namespace Tsk {
	class Bushi : public EnemyBase {
	public:
		Bushi();
		~Bushi();
		virtual ENEMYTYPE	GetEneType() { return ENEMYTYPE::BUSHI; }

		void	Init();
		void	Process(Game& g);
		void	Draw(Game& g);
	private:
		void	Patrol(Game& g);
		void	Coming(Game& g);
		void	Attack(Game& g);

		/*----------�����o�ϐ�----------*/
		int		_Action_Cnt;	//�A�N�V�����o�ߎ��ԋL�^�ϐ�

		//�ҋ@��ԕ`��p�ϐ�
		int		_Idle_GrHandle;
		std::vector<int>	_Idle_GrAll;
		int		_Idle_AnimeNo;

		//�ړ���ԕ`��p�ϐ�
		int		_Move_GrHandle;
		std::vector<int>	_Move_GrAll;
		int		_Move_AnimeNo;

		//�U����ԕ`��p�ϐ�
		int		_Attack_GrHandle;
		std::vector<int>	_Attack_GrAll;
		int		_Attack_AnimeNo;

		//SE�n���h��
		int		_Walk_SEHandle;
		int		_Attack_SEHandle;
	};
}
namespace BInfo {
	/*----------���m�̊e���W�֌W----------*/
	constexpr auto PositionX = 1800;			//���������ʒu�i��������j
	constexpr auto PositionY = 900;				//�c�������ʒu�i��������j
	constexpr auto GraphPointX = 0;				//X�ʒu����`��_�܂ł̍���
	constexpr auto GraphPointY = -170;			//Y�ʒu����`��_�܂ł̍���
	constexpr auto PositionHitX = -30;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto PositionHitY = -80;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto CollisionWidth = 60;			//�����蔻�艡��
	constexpr auto CollisionHeight = 250;		//�����蔻��c��

	/*----------�p�����[�^�[�֌W----------*/
	constexpr auto Speed = 2;					//�ړ����x

	/*----------�A�j���[�V�����֌W----------*/
	//�e��ԃA�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto AnimeSpeed_Idle = 8;			//�ҋ@���
	constexpr auto AnimeSpeed_Move = 5;			//�ړ����
	constexpr auto AnimeSpeed_Attack = 5;		//�U��

	//�e���[�V�����̃t���[����
	constexpr auto Attack_Frame = 40;		//�U��


	/*----------�摜�ǂݍ���&�`��֌W----------*/
	constexpr auto GraphWidth = 540;			//1��������̉摜�T�C�Y�i���j
	constexpr auto GraphHeight = 420;			//1��������̉摜�T�C�Y�i�c�j
	//�ҋ@
	constexpr auto Idle_GraphName = "res/B_Stand.png";	//�摜�t�@�C����
	constexpr auto Idle_AnimeMax = 1;			//�S�Ẳ摜����
	constexpr auto Idle_WidthCount = 1;			//���̉摜����
	constexpr auto Idle_HeightCount = 1;		//�c�̉摜����
	constexpr auto Idle_Scale = 1.0;			//�g�嗦
	constexpr auto Idle_Angle = 0;				//�p�x
	//�ړ�
	constexpr auto Move_GraphName = "res/B_Walk.png";	//�摜�t�@�C����
	constexpr auto Move_AnimeMax = 13;			//�S�Ẳ摜����
	constexpr auto Move_WidthCount = 5;			//���̉摜����
	constexpr auto Move_HeightCount = 3;		//�c�̉摜����	
	constexpr auto Move_Scale = 1.0;			//�g�嗦
	constexpr auto Move_Angle = 0;				//�p�x
	//�U��
	constexpr auto Attack_GraphName = "res/B_MidAttack.png";	//�摜�t�@�C����
	constexpr auto Attack_AnimeMax = 8;			//�S�Ẳ摜����
	constexpr auto Attack_WidthCount = 8;		//���̉摜����
	constexpr auto Attack_HeightCount = 1;		//�c�̉摜����
	constexpr auto Attack_Scale = 1.0;			//�g�嗦
	constexpr auto Attack_Angle = 0;			//�p�x
}