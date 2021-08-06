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

		void	Init()override;
		void	Process(Game& g)override;
		void	Draw(Game& g)override;
		void	Damage(Game& g)override;
	
	private:
		void	Patrol(Game& g);	//�����Ԏ��̏���
		void	Coming(Game& g);	//�ǐՏ�Ԏ��̏���
		void	Attack(Game& g);	//�U����Ԏ��̏���
		void	LoadActionGraph();	//�v���C���[�̉摜�ǂݍ��݊֐�

		/*----------�����o�ϐ�----------*/

		//�����ԕ`��p�ϐ�
		int		_Patrol_GrHandle;
		std::vector<int>	_Patrol_GrAll;
		int		_Patrol_AnimeNo;

		//�ړ���ԕ`��p�ϐ�
		int		_Coming_GrHandle;
		std::vector<int>	_Coming_GrAll;
		int		_Coming_AnimeNo;

		//�U����ԕ`��p�ϐ�
		int		_Attack_GrHandle;
		std::vector<int>	_Attack_GrAll;
		int		_Attack_AnimeNo;

		//�e���[�V�����t���O�Ǘ��ϐ�
		bool	_Patrol_Flag;
		//SE�n���h��
		int		_Walk_SEHandle;
		int		_Attack_SEHandle;
	};
}
namespace BInfo {
	/*----------���m�̊e���W�֌W----------*/
	constexpr auto PositionX = 1700;			//���������ʒu�i��������j
	constexpr auto PositionY = 900;				//�c�������ʒu�i��������j
	constexpr auto GraphPointX = 0;				//X�ʒu����`��_�܂ł̍���
	constexpr auto GraphPointY = -210;			//Y�ʒu����`��_�܂ł̍���
	constexpr auto PositionHitX = -30;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto PositionHitY = -90;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto CollisionWidth = 60;			//�����蔻�艡��
	constexpr auto CollisionHeight = 300;		//�����蔻��c��

	/*----------�p�����[�^�[�֌W----------*/
	constexpr auto LifeMax = 1;					//�̗�
	constexpr auto Speed = 1;					//�ړ����x
	
	/*----------�A�j���[�V�����֌W----------*/
	//�e��ԃA�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto AnimeSpeed_Patrol = 240;		//������
	constexpr auto AnimeSpeed_Move = 5;			//�ړ����
	constexpr auto AnimeSpeed_Attack = 20;		//�U��

	//�e���[�V�����̃t���[����
	constexpr auto Patrol_Frame = 240;			//����t���[��
	constexpr auto Attack_Frame = 60;			//�U���S�t���[��
	constexpr auto ABegin_Frame = 20;			//�U�������t���[��
	constexpr auto AEnd_Frame = 20;				//�U���I���t���[��

	/*----------�摜�ǂݍ���&�`��֌W----------*/
	constexpr auto GraphWidth = 540;			//1��������̉摜�T�C�Y�i���j
	constexpr auto GraphHeight = 420;			//1��������̉摜�T�C�Y�i�c�j
	constexpr auto GraphScale = 1.0;			//�g�嗦
	constexpr auto GraphAngle = 0;				//�p�x

	//�ҋ@
	constexpr auto Patrol_GraphName = "res/B_Stand.png";	//�摜�t�@�C����
	constexpr auto Patrol_AnimeMax = 1;			//�S�Ẳ摜����
	constexpr auto Patrol_WidthCount = 1;		//���̉摜����
	constexpr auto Patrol_HeightCount = 1;		//�c�̉摜����
	//�ړ�
	constexpr auto Coming_GraphName = "res/B_Stand.png";	//�摜�t�@�C����
	constexpr auto Coming_AnimeMax = 1;			//�S�Ẳ摜����
	constexpr auto Coming_WidthCount = 1;		//���̉摜����
	constexpr auto Coming_HeightCount = 1;		//�c�̉摜����	
	//�U��
	constexpr auto Attack_GraphName = "res/B_Attack.png";	//�摜�t�@�C����
	constexpr auto Attack_AnimeMax = 3;			//�S�Ẳ摜����
	constexpr auto Attack_WidthCount = 3;		//���̉摜����
	constexpr auto Attack_HeightCount = 1;		//�c�̉摜����
	
}