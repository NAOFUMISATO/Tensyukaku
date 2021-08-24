#pragma once
#include	"ObjectBase.h"
#include	<vector>

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
	bool	GetFlip() { return _isFlip; }
private:
	//�v���C���[�̏�ԗ�
	enum class PLAYERSTATE { IDLE, MOVE, MIDDLEATTACK, LOWATTACK, KICK, IAI, SWAY, DAMAGE, DEAD,STAIRUP,STAIRMOVE};
	
	void	Idle(Game& g);			//�ҋ@��Ԏ��̏���
	void	Move(Game& g);			//�ړ����̏���
	void	MidAttack(Game& g);		//���i�U�����̏���
	void	LowAttack(Game& g);		//���i�U�����̏���
	void	Kick(Game& g);			//�R�莞�̏���
	void	Iai(Game& g);			//����������
	//void	Sway(Game& g);			//�X�E�F�C���̏���
	void	Damage(Game& g);		//��_�����̏���
	void	Dead(Game& g);			//���S���̏���
	void	StairMove(Game& g);		//�K�i�ʒu�����̏���
	void	StairUp(Game& g);		//�K�i�㏸�̏���
	void	LoadActionGraph();		//�v���C���[�̉摜�ǂݍ��݊֐�
	void	LoadActionSE();			//�v���C���[�̌��ʉ��ǂݍ��݊֐�
	void	AnimeUpdate(Game& g);	//�v���C���[�̃A�j���[�V�����֐�
	void	UIDraw(Game& g);		//�v���C���[��UI�`��֐�

	/*---------�����o�ϐ�----------*/
	PLAYERSTATE	_State;		//��ԑJ�ڕϐ�
	
	//�ҋ@��ԕ`��p�ϐ�
	std::vector<int>	_Idle_GrAll;
	int		_Idle_AnimeNo;

	//�ړ���ԕ`��p�ϐ�
	std::vector<int>	_Move_GrAll;
	int		_Move_AnimeNo;

	//���i�U����ԕ`��p�ϐ�
	std::vector<int>	_MiddleAttack_GrAll;
	int		_MiddleAttack_AnimeNo;

	//���i�U����ԕ`��p�ϐ�
	std::vector<int>	_LowAttack_GrAll;
	int		_LowAttack_AnimeNo;

	//�R���ԕ`��p�ϐ�
	std::vector<int>	_Kick_GrAll;
	int		_Kick_AnimeNo;

	//������ԕ`��p�ϐ�
	std::vector<int>	_Iai_GrAll;
	int		_Iai_AnimeNo;

	//�X�E�F�C��ԕ`��p�ϐ�
	std::vector<int>	_Sway_GrAll;
	int		_Sway_AnimeNo;

	//��_����ԕ`��p�ϐ�
	std::vector<int>	_Damage_GrAll;
	int		_Damage_AnimeNo;

	//���S��ԕ`��p�ϐ�
	std::vector<int>	_Dead_GrAll;
	int		_Dead_AnimeNo;
	
	//���G��ԊǗ��ϐ�
	bool	_Star_Flag;		//���G��ԊǗ��t���O
	int		_Star_Cnt;		//���G��Ԍo�ߎ��ԋL�^�ϐ�
	int		_Iai_Gauge;		//�����Q�[�W�ϐ�
	//�K�i����
	Vector2 _velocityDir;	//���x����
	float	_Stairup_Spd;	//�K�i�㏸���x
	float	_angle;			//�p�x
	//SE�n���h��
	int		_Walk_SEHandle;
	int		_MiddleAttack_SEHandle;
	int		_LowAttack_SEHandle;
	int		_Kick_SEHandle;
	int		_Damage_SEHandle;
	int		_SwordIn_SEHandle;
	int		_Iai_SEHandle;
};


namespace PInfo {

	/*----------�v���C���[�̊e���W�֌W----------*/
	constexpr auto PositionX = 200;				//���������ʒu�i��������j
	constexpr auto PositionY = 2200;			//�c�������ʒu�i��������j
	constexpr auto GraphPointX = 0;				//X�ʒu����`��_�܂ł̍���
	constexpr auto GraphPointY = -210;			//Y�ʒu����`��_�܂ł̍���
	constexpr auto PositionHitX = -30;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto PositionHitY = -90;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto CollisionWidth = 60;			//�v���C���[�̓����蔻�艡��
	constexpr auto CollisionHeight = 300;		//�v���C���[�̓����蔻��c��
	constexpr auto BackCameraX = 50;			//�w�i���v���C��-�̃J��������ʂ̉����ɒu�����i�����j
	constexpr auto BackCameraY = 93;			//�w�i���v���C��-�̃J��������ʂ̉����ɒu�����i�c���j
	constexpr auto ChipCameraX = 50;			//�}�b�v�`�b�v���v���C��-�̃J��������ʂ̉����ɒu�����i�����j
	constexpr auto ChipCameraY = 93;			//�}�b�v�`�b�v���v���C��-�̃J��������ʂ̉����ɒu�����i�c���j

	/*----------�e���[�V�����̓����蔻��֌W----------*/
	constexpr auto MiddleAttackWidth = 150;		//���i�U�������蔻�艡��
	constexpr auto MiddleAttackHeight = 100;	//���i�U�������蔻��c��
	constexpr auto LowAttackWidth = 150;		//���i�U�������蔻�艡��
	constexpr auto LowAttackHeight = 100;		//���i�U�������蔻��c��
	constexpr auto KickWidth = 150;				//�R�蓖���蔻�艡��
	constexpr auto KickHeight = 100;			//�R�蓖���蔻��c��
	constexpr auto IaiWidth = 600;				//���������蔻�艡��
	constexpr auto IaiHeight = 100;				//���������蔻��c��

	/*----------�p�����[�^�[�֌W----------*/
	constexpr auto LifeMax = 3;					//�̗�
	constexpr auto Speed = 7;					//�ړ����x

	/*----------�摜�ǂݍ���&�A�j���[�V����&����t���[���֌W----------*/
	//����
	constexpr auto GraphWidth = 720;			//1��������̉摜�T�C�Y�i���j
	constexpr auto GraphHeight = 420;			//1��������̉摜�T�C�Y�i�c�j
	constexpr auto GraphScale = 1.0;			//�g�嗦
	constexpr auto GraphAngle = 0;				//�p�x
	//�ҋ@
	constexpr auto Idle_GraphName = "res/Samurai/S_Stand.png";	//�摜�t�@�C����
	constexpr auto Idle_AnimeMax = 1;			//�S�Ẳ摜����
	constexpr auto Idle_WidthCount = 1;			//���̉摜����
	constexpr auto Idle_HeightCount = 1;		//�c�̉摜����
	constexpr auto AnimeSpeed_Idle = 1;			//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	//�ړ�
	constexpr auto Move_GraphName = "res/Samurai/S_Walk.png";	//�摜�t�@�C����
	constexpr auto Move_AnimeMax = 6;			//�S�Ẳ摜����
	constexpr auto Move_WidthCount = 6;			//���̉摜����
	constexpr auto Move_HeightCount = 1;		//�c�̉摜����	
	constexpr auto AnimeSpeed_Move = 6;			//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto Move_Frame = 120;			//�ړ�SE�̊Ǘ��t���[��
	//���i�U��
	constexpr auto MiddleAttack_GraphName = "res/Samurai/S_MidAttack.png";	//�摜�t�@�C����
	constexpr auto MiddleAttack_AnimeMax = 8;	//�S�Ẳ摜����
	constexpr auto MiddleAttack_WidthCount = 8;	//���̉摜����
	constexpr auto MiddleAttack_HeightCount = 1;//�c�̉摜����
	constexpr auto AnimeSpeed_MiddleAttack = 4;	//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto MiddleAttack_Frame = 30;		//���i�U���S�t���[��
	constexpr auto MABegin_Frame = 12;			//���i�U�����蔭���t���[��
	constexpr auto MAEnd_Frame = 12;			//���i�U������I���t���[��(�������Ă���̃t���[�����j
	//���i�U��
	constexpr auto LowdAttack_GraphName = "res/Samurai/S_LowAttack.png";	//�摜�t�@�C����
	constexpr auto LowAttack_AnimeMax = 8;		//�S�Ẳ摜����
	constexpr auto LowAttack_WidthCount = 8;	//���̉摜����
	constexpr auto LowAttack_HeightCount = 1;	//�c�̉摜����
	constexpr auto AnimeSpeed_LowAttack = 4;	//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto LowAttack_Frame = 30;		//���i�U���S�t���[��
	constexpr auto LABegin_Frame = 12;			//���i�U�����蔭���t���[��
	constexpr auto LAEnd_Frame = 12;			//���i�U������I���t���[��(�������Ă���̃t���[����)
	//�R��
	constexpr auto Kick_GraphName = "res/Samurai/S_Kick.png";		//�摜�t�@�C����
	constexpr auto Kick_AnimeMax = 6;			//�S�Ẳ摜����
	constexpr auto Kick_WidthCount = 6;			//���̉摜����
	constexpr auto Kick_HeightCount = 1;		//�c�̉摜����
	constexpr auto AnimeSpeed_Kick = 5;			//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto Kick_Frame = 28;				//�R��S�t���[��
	constexpr auto KIBegin_Frame = 10;			//�R�蔻�蔭���t���[��
	constexpr auto KIEnd_Frame = 10;			//�R�蔻��I���t���[��(�������Ă���̃t���[����)
	//����
	constexpr auto Iai_GraphName = "res/Samurai/S_Iai.png";			//�摜�t�@�C����
	constexpr auto Iai_AnimeMax = 8;			//�S�Ẳ摜����
	constexpr auto Iai_WidthCount = 8;			//���̉摜����
	constexpr auto Iai_HeightCount = 1;			//�c�̉摜����
	constexpr auto AnimeSpeed_Iai = 5;			//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto Iai_Frame = 38;				//�����t���[��
	constexpr auto IABegin_Frame = 26;			//�������蔭���t���[��
	constexpr auto IAEnd_Frame = 12;			//��������I���t���[��(�������Ă���̃t���[����)
	//�X�E�F�C
	constexpr auto Sway_GraphName = "res/Samurai/S_Iai.png";			//�摜�t�@�C����
	constexpr auto Sway_AnimeMax = 1;			//�S�Ẳ摜����
	constexpr auto Sway_WidthCount = 1;			//���̉摜����
	constexpr auto Sway_HeightCount = 1;		//�c�̉摜����
	constexpr auto Sway_Frame = 40;				//�X�E�F�C�t���[��
	constexpr auto AnimeSpeed_Sway = 5;			//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	//��_��
	constexpr auto Damage_GraphName = "res/Samurai/S_Damage.png";	//�摜�t�@�C����
	constexpr auto Damage_AnimeMax = 1;			//�S�Ẳ摜����
	constexpr auto Damage_WidthCount = 1;		//���̉摜����
	constexpr auto Damage_HeightCount = 1;		//�c�̉摜����
	constexpr auto Damage_Frame = 38;			//��_���S�t���[��
	constexpr auto AnimeSpeed_Damage = 40;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	//���G
	constexpr auto AnimeSpeed_Star = 8;			//���G��Ԏ��̓_�ő��x 
	constexpr auto Star_Frame = 180;			//��_�����̖��G�t���[��
	//���S
	constexpr auto Dead_GraphName = "res/Samurai/S_Dead.png";		//�摜�t�@�C����
	constexpr auto Dead_AnimeMax = 1;			//�S�Ẳ摜����
	constexpr auto Dead_WidthCount = 1;			//���̉摜����
	constexpr auto Dead_HeightCount = 1;		//�c�̉摜����
	constexpr auto Dead_Frame = 160;			//���S�S�t���[��
	constexpr auto AnimeSpeed_Dead = 120;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	
	/*----------SE�֌W----------*/
	constexpr auto Walk_SE = "se/Footstep.wav";			//�ړ�
	constexpr auto MiddleAttack_SE = "se/slash3.wav";	//���i�U��
	constexpr auto LowAttack_SE = "se/Slash.wav";		//���i�U��
	constexpr auto Kick_SE = "se/Kick.wav";				//�R��
	constexpr auto Damage_SE = "se/Damage.wav";			//��_��
	constexpr auto SwordIn_SE = "se/Close.wav";			//�[��
	constexpr auto Iai_SE = "se/Iai.wav";				//����

}