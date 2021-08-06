#pragma once
#include	"ObjectBase.h"
#include	<vector>
namespace Tsk {
	// �v���C���[�N���X
	class Game;
	class Player : public ObjectBase {
	public:
		Player();
		~Player();
		virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::PLAYER; }

		void	Init()override;
		void	Process(Game& g)override;
		void	Draw(Game& g)override;

	private:
		//�v���C���[�̃A�N�V������
		enum class PLAYERACTION { IDLE, MOVE, MIDDLEATTACK, LOWATTACK };
		//�v���C���[�̏�ԗ�
		enum class PLAYERSTATE { ALLIBE, DAMAGE, DEAD };

		void	Idle(Game& g);		//�ҋ@��Ԏ��̏���
		void	Move(Game& g);		//�ړ����̏���
		void	MidAttack(Game& g);	//���i�U�����̏���
		void	LowAttack(Game& g);	//���i�U�����̏���
		void	LoadActionGraph();	//�v���C���[�̉摜�ǂݍ��݊֐�
		void	LoadActionSE();		//�v���C���[�̌��ʉ��ǂݍ��݊֐�

		/*---------�����o�ϐ�----------*/
		PLAYERACTION	_Action;		//��ԑJ�ڕϐ�
		

		//�ҋ@��ԕ`��p�ϐ�
		int		_Idle_GrHandle;
		std::vector<int>	_Idle_GrAll;
		int		_Idle_AnimeNo;

		//�ړ���ԕ`��p�ϐ�
		int		_Move_GrHandle;
		std::vector<int>	_Move_GrAll;
		int		_Move_AnimeNo;

		//���i�U����ԕ`��p�ϐ�
		int		_MiddleAttack_GrHandle;
		std::vector<int>	_MiddleAttack_GrAll;
		int		_MiddleAttack_AnimeNo;

		//���i�U����ԕ`��p�ϐ�
		int		_LowAttack_GrHandle;
		std::vector<int>	_LowAttack_GrAll;
		int		_LowAttack_AnimeNo;

		//SE�n���h��
		int		_Walk_SEHandle;
		int		_MiddleAttack_SEHandle;
		int		_LowAttack_SEHandle;
	};
}

namespace PInfo {

	/*----------�v���C���[�̊e���W�֌W----------*/
	constexpr auto PositionX =500;				//���������ʒu�i��������j
	constexpr auto PositionY = 900;				//�c�������ʒu�i��������j
	constexpr auto GraphPointX = 0;				//X�ʒu����`��_�܂ł̍���
	constexpr auto GraphPointY = -190;			//Y�ʒu����`��_�܂ł̍���
	constexpr auto PositionHitX = -30;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto PositionHitY = -60;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto CollisionWidth = 60;			//�����蔻�艡��
	constexpr auto CollisionHeight = 250;		//�����蔻��c��

	/*----------�e���[�V�����̓����蔻��֌W----------*/
	constexpr auto MiddleAttackWidth = 150;		//���i�U�������蔻�艡��
	constexpr auto MiddleAttackHeight = 100;	//���i�U�������蔻��c��
	constexpr auto LowAttackWidth = 150;		//���i�U���͈͓����蔻�艡��
	constexpr auto LowAttackHeight = 100;		//���i�U���͈͓����蔻��c��

	/*----------�p�����[�^�[�֌W----------*/
	constexpr auto LifeMax = 3;					//�̗�
	constexpr auto Speed = 4;					//�ړ����x

	/*----------�A�j���[�V����&�����蔻��֌W----------*/
	//�e��ԃA�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto AnimeSpeed_Idle = 8;			//�ҋ@���
	constexpr auto AnimeSpeed_Move = 20;		//�ړ����
	constexpr auto AnimeSpeed_MiddleAttack = 5;	//���i�U��
	constexpr auto AnimeSpeed_LowAttack = 5;	//���i�U��
	//�e���[�V�����̃t���[����
	constexpr auto MiddleAttack_Frame = 40;		//���i�U���S�t���[��
	constexpr auto LowAttack_Frame = 40;		//���i�U���S�t���[��
	constexpr auto MABegin_Frame = 15;			//���i�U�����蔭���t���[��
	constexpr auto LABegin_Frame = 15;			//���i�U�����蔭���t���[��
	constexpr auto MAEnd_Frame= 20;				//���i�U������I���t���[��(�������Ă���̃t���[�����j
	constexpr auto LAEnd_Frame= 20;				//���i�U������I���t���[��(�������Ă���̃t���[����)

	/*----------�摜�ǂݍ���&�`��֌W----------*/
	constexpr auto GraphWidth = 720;			//1��������̉摜�T�C�Y�i���j
	constexpr auto GraphHeight = 420;			//1��������̉摜�T�C�Y�i�c�j
	constexpr auto GraphScale = 1.0;			//�g�嗦
	constexpr auto GraphAngle = 0;				//�p�x

	//�ҋ@
	constexpr auto Idle_GraphName = "res/S_Stand.png";	//�摜�t�@�C����
	constexpr auto Idle_AnimeMax = 1;			//�S�Ẳ摜����
	constexpr auto Idle_WidthCount = 1;			//���̉摜����
	constexpr auto Idle_HeightCount = 1;		//�c�̉摜����

	//�ړ�
	constexpr auto Move_GraphName = "res/S_Walk.png";	//�摜�t�@�C����
	constexpr auto Move_AnimeMax = 6;			//�S�Ẳ摜����
	constexpr auto Move_WidthCount = 6;			//���̉摜����
	constexpr auto Move_HeightCount = 1;		//�c�̉摜����	

	//���i�U��
	constexpr auto MiddleAttack_GraphName = "res/S_MidAttack.png";	//�摜�t�@�C����
	constexpr auto MiddleAttack_AnimeMax = 8;	//�S�Ẳ摜����
	constexpr auto MiddleAttack_WidthCount = 8;	//���̉摜����
	constexpr auto MiddleAttack_HeightCount = 1;//�c�̉摜����

	//���i�U��
	constexpr auto LowdleAttack_GraphName = "res/S_LowAttack.png";	//�摜�t�@�C����
	constexpr auto LowAttack_AnimeMax = 8;		//�S�Ẳ摜����
	constexpr auto LowAttack_WidthCount = 8;	//���̉摜����
	constexpr auto LowAttack_HeightCount = 1;	//�c�̉摜����

	/*----------SE�֌W----------*/
	constexpr auto Walk_SE = "se/walk.wav";				//�ړ�
	constexpr auto MiddleAttack_SE = "se/slash1.wav";	//���i�U��
	constexpr auto LowAttack_SE = "se/slash2.wav";		//���i�U��
}