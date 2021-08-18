#pragma once
#include "EnemyBase.h"
#include "ObjectBase.h"
#include <vector>
// ���m�N���X

class Bushi : public EnemyBase {
public:
	Bushi();
	~Bushi();
	virtual ENEMYTYPE	GetEneType() { return ENEMYTYPE::BUSHI; }

	void	Init()override;
	void	Process(Game& g)override;
	void	Draw(Game& g)override;
	void	Delete(Game& g)override;

private:
	void	Patrol(Game& g);		//�����Ԏ��̏���
	void	Coming(Game& g);		//�ǐՏ�Ԏ��̏���
	void	Attack(Game& g);		//�U����Ԏ��̏���
	void	Damage(Game& g);		//��_����Ԏ��̏���
	void	Dead(Game& g);			//���S��Ԏ��̏���
	void	LoadActionGraph();		//���m�̉摜�ǂݍ��݊֐�
	void	LoadActionSE();			//���m��SE�ǂݍ��݊֐�
	void	AnimeUpdate(Game& g);	//���m�̃A�j���[�V�����֐�
	

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
	std::vector<int>	_Damage_GrAll;
	int		_Damage_AnimeNo;

	//���S��ԕ`��p�ϐ�
	std::vector<int>	_Dead_GrAll;
	int		_Dead_AnimeNo;

	//SE�n���h��
	int		_Walk_SEHandle;
	int		_Attack_SEHandle;
};

namespace BInfo {
	/*----------���m�̊e���W�֌W----------*/
	constexpr auto PositionX = 1800;			//���������ʒu�i��������j
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
	constexpr auto LifeMax = 3;					//�̗�
	constexpr auto Speed = 1;					//�ړ����x
	
	/*----------�A�j���[�V����&�����蔻��֌W----------*/
	//�e��ԃA�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto AnimeSpeed_Patrol = 5;		//������
	constexpr auto AnimeSpeed_Move = 30;		//�ړ����
	constexpr auto AnimeSpeed_Attack = 15;		//�U��
	constexpr auto AnimeSpeed_Damage = 60;		//��_��
	constexpr auto AnimeSpeed_Dead = 60;		//���S

	//�e���[�V�����̃t���[����
	constexpr auto Patrol_Frame = 180;			//����S�t���[��
	constexpr auto Attack_Frame = 40;			//�U���S�t���[��
	constexpr auto Damage_Frame = 50;			//��_���S�t���[��
	constexpr auto Dead_Frame = 50;				//���S�S�t���[��
	constexpr auto ABegin_Frame = 15;			//�U�����蔭���t���[��
	constexpr auto AEnd_Frame = 15;				//�U������I���t���[��

	/*----------�摜�ǂݍ���&�`��֌W----------*/
	constexpr auto GraphWidth = 540;			//1��������̉摜�T�C�Y�i���j
	constexpr auto GraphHeight = 420;			//1��������̉摜�T�C�Y�i�c�j
	constexpr auto GraphScale = 1.0;			//�g�嗦
	constexpr auto GraphAngle = 0;				//�p�x

	//�ҋ@
	constexpr auto Patrol_GraphName = "res/Bushi/B_Stand.png";	//�摜�t�@�C����
	constexpr auto Patrol_AnimeMax = 1;			//�S�Ẳ摜����
	constexpr auto Patrol_WidthCount = 1;		//���̉摜����
	constexpr auto Patrol_HeightCount = 1;		//�c�̉摜����
	//�ړ�
	constexpr auto Coming_GraphName = "res/Bushi/B_Walk.png";	//�摜�t�@�C����
	constexpr auto Coming_AnimeMax = 4;			//�S�Ẳ摜����
	constexpr auto Coming_WidthCount = 4;		//���̉摜����
	constexpr auto Coming_HeightCount = 1;		//�c�̉摜����	
	//�U��
	constexpr auto Attack_GraphName = "res/Bushi/B_Attack.png";	//�摜�t�@�C����
	constexpr auto Attack_AnimeMax = 3;			//�S�Ẳ摜����
	constexpr auto Attack_WidthCount = 3;		//���̉摜����
	constexpr auto Attack_HeightCount = 1;		//�c�̉摜����
	//��_��
	constexpr auto Damage_GraphName = "res/Bushi/B_Damage.png";	//�摜�t�@�C����
	constexpr auto Damage_AnimeMax = 1;			//�S�Ẳ摜����
	constexpr auto Damage_WidthCount = 1;		//���̉摜����
	constexpr auto Damage_HeightCount = 1;		//�c�̉摜����
	//���S
	constexpr auto Dead_GraphName = "res/Bushi/B_Dead.png";		//�摜�t�@�C����
	constexpr auto Dead_AnimeMax = 1;			//�S�Ẳ摜����
	constexpr auto Dead_WidthCount = 1;			//���̉摜����
	constexpr auto Dead_HeightCount = 1;		//�c�̉摜����
}