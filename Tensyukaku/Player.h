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
		void	Delete(Game& g)override;
	private:
		//�v���C���[�̏�ԗ�
		enum class PLAYERSTATE { IDLE, MOVE, MIDDLEATTACK, LOWATTACK, KICK, IAI, SWAY, DAMAGE, DEAD};
		
		void	Idle(Game& g);		//�ҋ@��Ԏ��̏���
		void	Move(Game& g);		//�ړ����̏���
		void	MidAttack(Game& g);	//���i�U�����̏���
		void	LowAttack(Game& g);	//���i�U�����̏���
		void	Kick(Game& g);		//�R�莞�̏���
		void	Iai(Game& g);		//����������
		void	Sway(Game& g);		//�X�E�F�C���̏���
		void	Damage(Game& g);	//��_�����̏���
		void	Dead(Game& g);		//���S���̏���
		void	LoadActionGraph();	//�v���C���[�̉摜�ǂݍ��݊֐�
		void	LoadActionSE();		//�v���C���[�̌��ʉ��ǂݍ��݊֐�

		/*---------�����o�ϐ�----------*/
		PLAYERSTATE	_State;		//��ԑJ�ڕϐ�
		
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

		//�R���ԕ`��p�ϐ�
		int		_Kick_GrHandle;
		std::vector<int>	_Kick_GrAll;
		int		_Kick_AnimeNo;

		//������ԕ`��p�ϐ�
		int		_Iai_GrHandle;
		std::vector<int>	_Iai_GrAll;
		int		_Iai_AnimeNo;

		//�X�E�F�C��ԕ`��p�ϐ�
		int		_Sway_GrHandle;
		std::vector<int>	_Sway_GrAll;
		int		_Sway_AnimeNo;

		//��_����ԕ`��p�ϐ�
		int		_Damage_GrHandle;
		std::vector<int>	_Damage_GrAll;
		int		_Damage_AnimeNo;

		//���S��ԕ`��p�ϐ�
		int		_Dead_GrHandle;
		std::vector<int>	_Dead_GrAll;
		int		_Dead_AnimeNo;
		
		//���G��ԊǗ��ϐ�
		bool	_Star_Flag;		//���G��ԊǗ��t���O
		int		_Star_Cnt;		//���G��Ԍo�ߎ��ԋL�^�ϐ�

		//SE�n���h��
		int		_Walk_SEHandle;
		int		_MiddleAttack_SEHandle;
		int		_LowAttack_SEHandle;
		int		_Kick_SEHandle;
	};
}

namespace PInfo {

	/*----------�v���C���[�̊e���W�֌W----------*/
	constexpr auto PositionX =500;				//���������ʒu�i��������j
	constexpr auto PositionY = 900;				//�c�������ʒu�i��������j
	constexpr auto GraphPointX = 0;				//X�ʒu����`��_�܂ł̍���
	constexpr auto GraphPointY = -210;			//Y�ʒu����`��_�܂ł̍���
	constexpr auto PositionHitX = -30;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto PositionHitY = -90;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto CollisionWidth = 60;			//�v���C���[�̓����蔻�艡��
	constexpr auto CollisionHeight = 300;		//�v���C���[�̓����蔻��c��

	/*----------�e���[�V�����̓����蔻��֌W----------*/
	constexpr auto MiddleAttackWidth = 150;		//���i�U�������蔻�艡��
	constexpr auto MiddleAttackHeight = 100;	//���i�U�������蔻��c��
	constexpr auto LowAttackWidth = 150;		//���i�U�������蔻�艡��
	constexpr auto LowAttackHeight = 100;		//���i�U�������蔻��c��
	constexpr auto KickWidth = 150;				//�R�蓖���蔻�艡��
	constexpr auto KickHeight = 100;			//�R�蓖���蔻��c��
	constexpr auto IaikWidth = 150;				//���������蔻�艡��
	constexpr auto IaikHeight = 100;			//���������蔻��c��

	/*----------�p�����[�^�[�֌W----------*/
	constexpr auto LifeMax = 3;					//�̗�
	constexpr auto Speed = 4;					//�ړ����x

	/*----------�A�j���[�V����&�����蔻��֌W----------*/
	//�e��ԃA�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto AnimeSpeed_Idle = 8;			//�ҋ@���
	constexpr auto AnimeSpeed_Move = 10;		//�ړ����
	constexpr auto AnimeSpeed_MiddleAttack = 5;	//���i�U��
	constexpr auto AnimeSpeed_LowAttack = 5;	//���i�U��
	constexpr auto AnimeSpeed_Kick = 8;			//�R��
	constexpr auto AnimeSpeed_Sway = 5;			//�X�E�F�C
	constexpr auto AnimeSpeed_Damage = 5;		//��_��
	constexpr auto AnimeSpeed_Dead = 5;			//���S
	constexpr auto AnimeSpeed_Star = 10;		//���G��Ԏ��̓_�ő��x
	//�e���[�V�����̃t���[����
	constexpr auto MiddleAttack_Frame = 40;		//���i�U���S�t���[��
	constexpr auto LowAttack_Frame = 40;		//���i�U���S�t���[��
	constexpr auto Kick_Frame = 48;				//�R��S�t���[��
	constexpr auto Iai_Frame = 40;				//�����t���[��
	constexpr auto Sway_Frame = 40;				//�X�E�F�C�t���[��
	constexpr auto Damage_Frame = 40;			//��_���S�t���[��
	constexpr auto Dead_Frame = 180;			//���S�S�t���[��
	constexpr auto MABegin_Frame = 15;			//���i�U�����蔭���t���[��
	constexpr auto MAEnd_Frame= 20;				//���i�U������I���t���[��(�������Ă���̃t���[�����j
	constexpr auto LABegin_Frame = 15;			//���i�U�����蔭���t���[��
	constexpr auto LAEnd_Frame= 20;				//���i�U������I���t���[��(�������Ă���̃t���[����)
	constexpr auto KIBegin_Frame = 24;			//�R�蔻�蔭���t���[��
	constexpr auto KIEnd_Frame = 16;			//�R�蔻��I���t���[��(�������Ă���̃t���[����)
	constexpr auto IABegin_Frame = 15;			//�������蔭���t���[��
	constexpr auto IAEnd_Frame = 20;			//��������I���t���[��(�������Ă���̃t���[����)
	constexpr auto Star_Frame = 180;			//��_�����̖��G�t���[��

	/*----------�摜�ǂݍ���&�`��֌W----------*/
	constexpr auto GraphWidth = 720;			//1��������̉摜�T�C�Y�i���j
	constexpr auto GraphHeight = 420;			//1��������̉摜�T�C�Y�i�c�j
	constexpr auto GraphScale = 1.0;			//�g�嗦
	constexpr auto GraphAngle = 0;				//�p�x
	//�ҋ@
	constexpr auto Idle_GraphName = "res/Samurai/S_Stand.png";	//�摜�t�@�C����
	constexpr auto Idle_AnimeMax = 1;			//�S�Ẳ摜����
	constexpr auto Idle_WidthCount = 1;			//���̉摜����
	constexpr auto Idle_HeightCount = 1;		//�c�̉摜����
	//�ړ�
	constexpr auto Move_GraphName = "res/Samurai/S_Walk.png";	//�摜�t�@�C����
	constexpr auto Move_AnimeMax = 6;			//�S�Ẳ摜����
	constexpr auto Move_WidthCount = 6;			//���̉摜����
	constexpr auto Move_HeightCount = 1;		//�c�̉摜����	
	//���i�U��
	constexpr auto MiddleAttack_GraphName = "res/Samurai/S_MidAttack.png";	//�摜�t�@�C����
	constexpr auto MiddleAttack_AnimeMax = 8;	//�S�Ẳ摜����
	constexpr auto MiddleAttack_WidthCount = 8;	//���̉摜����
	constexpr auto MiddleAttack_HeightCount = 1;//�c�̉摜����
	//���i�U��
	constexpr auto LowdAttack_GraphName = "res/Samurai/S_LowAttack.png";	//�摜�t�@�C����
	constexpr auto LowAttack_AnimeMax = 8;		//�S�Ẳ摜����
	constexpr auto LowAttack_WidthCount = 8;	//���̉摜����
	constexpr auto LowAttack_HeightCount = 1;	//�c�̉摜����
	//�R��
	constexpr auto Kick_GraphName = "res/Samurai/S_Kick.png";		//�摜�t�@�C����
	constexpr auto Kick_AnimeMax = 6;			//�S�Ẳ摜����
	constexpr auto Kick_WidthCount = 6;			//���̉摜����
	constexpr auto Kick_HeightCount = 1;		//�c�̉摜����
	//����
	constexpr auto Iai_GraphName = "res/Samurai/S_Iai.png";			//�摜�t�@�C����
	constexpr auto Iai_AnimeMax = 8;			//�S�Ẳ摜����
	constexpr auto Iai_WidthCount = 8;			//���̉摜����
	constexpr auto Iai_HeightCount = 1;			//�c�̉摜����
	//�X�E�F�C
	constexpr auto Sway_GraphName = "res/Samurai/S_Iai.png";			//�摜�t�@�C����
	constexpr auto Sway_AnimeMax = 1;			//�S�Ẳ摜����
	constexpr auto Sway_WidthCount = 1;			//���̉摜����
	constexpr auto Sway_HeightCount = 1;		//�c�̉摜����
	//��_��
	constexpr auto Damage_GraphName = "res/Samurai/S_Damage.png";	//�摜�t�@�C����
	constexpr auto Damage_AnimeMax = 1;			//�S�Ẳ摜����
	constexpr auto Damage_WidthCount = 1;		//���̉摜����
	constexpr auto Damage_HeightCount = 1;		//�c�̉摜����
	//���S
	constexpr auto Dead_GraphName = "res/Samurai/S_Dead.png";		//�摜�t�@�C����
	constexpr auto Dead_AnimeMax = 1;			//�S�Ẳ摜����
	constexpr auto Dead_WidthCount = 1;			//���̉摜����
	constexpr auto Dead_HeightCount = 1;		//�c�̉摜����
	
	/*----------SE�֌W----------*/
	constexpr auto Walk_SE = "se/walk.wav";				//�ړ�
	constexpr auto MiddleAttack_SE = "se/slash3.wav";	//���i�U��
	constexpr auto LowAttack_SE = "se/slash2.wav";		//���i�U��
	constexpr auto Kick_SE = "se/Kick.wav";				//�R��
}