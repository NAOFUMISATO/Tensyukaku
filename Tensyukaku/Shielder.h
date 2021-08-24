#pragma once
#include "EnemyBase.h"

class Shielder :public EnemyBase {
public:
	Shielder();
	~Shielder();
	virtual ENEMYTYPE	GetEneType() { return ENEMYTYPE::SHIELDER; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;
private:
	void	ShieldDraw(Game& g);	//���̏���
	void	Patrol(Game& g);		//�����Ԏ��̏���
	void	Coming(Game& g);		//�ǐՏ�Ԏ��̏���
	void	Attack(Game& g);		//�U����Ԏ��̏���
	void	GuardBreak(Game& g);	//��������Ԏ��̏���
	void	Dead(Game& g);			//���S��Ԏ��̏���
	void	LoadActionGraph();		//�E�҂̉摜�ǂݍ��݊֐�
	void	LoadActionSE();			//�E�҂�SE�ǂݍ��݊֐�
	void	AnimeUpdate(Game& g);	//�E�҂̃A�j���[�V�����֐�

	/*----------�����o�ϐ�----------*/

	//�����ԕ`��p�ϐ�
	std::vector<int>	_Patrol_GrAll;
	int		_Patrol_AnimeNo;

	//�ړ���ԕ`��p�ϐ�
	std::vector<int>	_Coming_GrAll;
	int		_Coming_AnimeNo;

	//�U����ԕ`��p�ϐ�
	std::vector<int>	_Attack_GrAll;
	int		_Attack_AnimeNo;

	//��_����ԕ`��p�ϐ�
	std::vector<int>	_GuardBreak_GrAll;
	int		_GuardBreak_AnimeNo;

	//���S��ԕ`��p�ϐ�
	std::vector<int>	_Dead_GrAll;
	int		_Dead_AnimeNo;

	//SE�n���h��
	int		_Walk_SEHandle;
	int		_Attack_SEHandle;

	bool	_Shield_Flag;		//���̐����t���O
	int		_Shield_Cnt;		
};

namespace SInfo {
	/*----------�����̊e���W�֌W----------*/
	constexpr auto PositionX = 1000;			//���������ʒu�i��������j
	constexpr auto PositionY = 2200;			//�c�������ʒu�i��������j
	constexpr auto GraphPointX = 0;				//X�ʒu����`��_�܂ł̍���
	constexpr auto GraphPointY = -210;			//Y�ʒu����`��_�܂ł̍���
	constexpr auto PositionHitX = -30;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto PositionHitY = -90;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto CollisionWidth = 60;			//�����蔻�艡��
	constexpr auto CollisionHeight = 300;		//�����蔻��c��
	
	/*----------�e���[�V�����̓����蔻��֌W----------*/
	constexpr auto PatrolWidth = 500;			//���G�͈͓����蔻�艡��
	constexpr auto PatrolHeight = 100;			//���G�͈͓����蔻��c��
	constexpr auto ComingWidth = 200;			//�U�������͈͓����蔻�艡��
	constexpr auto ComingHeight = 100;			//�U�������͈͓����蔻��c��
	constexpr auto AttackWidth = 150;			//�U�������蔻�艡��
	constexpr auto AttackHeight = 100;			//�U�������蔻��c��

	/*----------�p�����[�^�[�֌W----------*/
	constexpr auto LifeMax = 1;					//�̗�
	constexpr auto Speed = 1;					//�ړ����x

	/*----------�摜�ǂݍ���&�A�j���[�V����&����t���[���֌W----------*/
	//����
	constexpr auto GraphWidth = 540;			//1��������̉摜�T�C�Y�i���j
	constexpr auto GraphHeight = 420;			//1��������̉摜�T�C�Y�i�c�j
	constexpr auto GraphScale = 1.0;			//�g�嗦
	constexpr auto GraphAngle = 0;				//�p�x
	//����
	constexpr auto Patrol_GraphName = "res/Shielder/T_Stand.png";	//�摜�t�@�C����
	constexpr auto Patrol_AnimeMax = 1;			//�S�Ẳ摜����
	constexpr auto Patrol_WidthCount = 1;		//���̉摜����
	constexpr auto Patrol_HeightCount = 1;		//�c�̉摜����
	constexpr auto AnimeSpeed_Patrol = 5;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto Patrol_Frame = 180;			//����S�t���[��
	//�ړ�
	constexpr auto Coming_GraphName = "res/Shielder/T_Walk.png";	//�摜�t�@�C����
	constexpr auto Coming_AnimeMax = 4;			//�S�Ẳ摜����
	constexpr auto Coming_WidthCount = 4;		//���̉摜����
	constexpr auto Coming_HeightCount = 1;		//�c�̉摜����	
	constexpr auto AnimeSpeed_Coming = 30;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	//�U��
	constexpr auto Attack_GraphName = "res/Shielder/T_Attack.png";	//�摜�t�@�C����
	constexpr auto Attack_AnimeMax = 3;			//�S�Ẳ摜����
	constexpr auto Attack_WidthCount = 3;		//���̉摜����
	constexpr auto Attack_HeightCount = 1;		//�c�̉摜����
	constexpr auto AnimeSpeed_Attack = 15;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto Attack_Frame = 40;			//�U���S�t���[��
	constexpr auto ABegin_Frame = 15;			//�U�����蔭���t���[��
	constexpr auto AEnd_Frame = 15;				//�U������I���t���[��
	//��_��
	constexpr auto GuardBreak_GraphName = "res/Shielder/T_Damage.png";	//�摜�t�@�C����
	constexpr auto GuardBreak_AnimeMax = 1;			//�S�Ẳ摜����
	constexpr auto GuardBreak_WidthCount = 1;		//���̉摜����
	constexpr auto GuardBreak_HeightCount = 1;		//�c�̉摜����
	constexpr auto AnimeSpeed_GuardBreak = 60;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto GuardBreak_Frame = 50;			//��_���S�t���[��
	//���S
	constexpr auto Dead_GraphName = "res/Shielder/T_Dead.png";		//�摜�t�@�C����
	constexpr auto Dead_AnimeMax = 1;			//�S�Ẳ摜����
	constexpr auto Dead_WidthCount = 1;			//���̉摜����
	constexpr auto Dead_HeightCount = 1;		//�c�̉摜����
	constexpr auto AnimeSpeed_Dead = 60;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto Dead_Frame = 50;				//���S�S�t���[��
	/*----------SE�֌W----------*/
	constexpr auto Walk_SE = "se/Footstep.wav";			//����
	constexpr auto Attack_SE = "se/slash3.wav";			//�U��	

};