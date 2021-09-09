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

private:
	//�v���C���[�̏�ԗ�
	enum class PLAYERSTATE { IDLE, MOVE, MIDDLEATTACK, LOWATTACK, KICK, IAI, SWAY, DAMAGE, DEAD,STAIRUP,STAIRMOVE,BOSSSTAIRMOVE,BOSSSTAIRUP};
	
	void	Star(Game& g);			//���G��Ԏ��̏���
	void	Idle(Game& g);			//�ҋ@��Ԏ��̏���
	void	Move(Game& g);			//�ړ����̏���
	void	MidAttack(Game& g);		//���i�U�����̏���
	void	LowAttack(Game& g);		//���i�U�����̏���
	void	Kick(Game& g);			//�R�莞�̏���
	void	Iai(Game& g);			//����������
	void	Sway(Game& g);			//�X�E�F�C���̏���
	void	Damage(Game& g);		//��_�����̏���
	void	Dead(Game& g);			//���S���̏���
	void	StairMove(Game& g);		//�K�i�ʒu�����̏���
	void	StairUp(Game& g);		//�K�i�㏸�̏���
	void	BossStairMove(Game& g);	//�{�X�K�i�ʒu�����̏���
	void	BossStairUp(Game& g);	//�{�X�K�i�㏸���̏���
	void	CameraSetting(Game& g);	//�v���C���[�ʒu����J�������W�ݒ�
	void	UIAppear(Game& g);		//UI�C���X�^���X�����֐�
	void	BufSetting(Game& g);	//���X�e�B�b�N�̓��͗ʂɂ��X�e�[�^�X�ݒ�
	void	Recovery(Game& g);		//�v���C���[�̗͉̑�
	void	LoadActionGraph();		//�v���C���[�̉摜�ǂݍ��݊֐�
	void	LoadActionSE();			//�v���C���[�̌��ʉ��ǂݍ��݊֐�
	void	DebugDraw(Game& g);		//�f�o�b�O�p�֐�
	
	/*---------�����o�ϐ�----------*/
	PLAYERSTATE	_State;		//��ԑJ�ڕϐ�
	
	int		_alpha;			//SetDrawBlendMode�pa�l�ϐ�
	int		_Move_AnimeSpeed;//�ړ����̃A�j���X�s�[�h

	//���G��ԊǗ��ϐ�
	bool	_Star_Flag;		//���G��ԊǗ��t���O
	int		_Star_Cnt;		//���G��Ԍo�ߎ��ԋL�^�ϐ�
	
	//�K�i�����ϐ�
	Vector2 _velocityDir;	//���x����
	float	_Stairup_Spd;	//�K�i�㏸���x
	float	_angle;			//�p�x
	bool	_StairFlip_Flag;//�K�i�̔��]����ۑ��t���O
	int		_Stair_x;		//�K�i��X���W�ۑ��ϐ�
	int		_Player_y;		//�K�i�㏸���̃v���C���[Y���W�ۑ��ϐ�
	bool	_UI_Flag;		//UI�`��p�t���O
};


namespace PInfo {

	/*----------�v���C���[�̊e���W�֌W----------*/
	constexpr auto POSITION_X = 4000;			//���������ʒu�i��������j
	constexpr auto POSITION_Y = 7840;			//�c�������ʒu�i��������j
	constexpr auto GRAPHPOINT_X = 0;			//X�ʒu����`��_�܂ł̍���
	constexpr auto GRAPHPOINT_Y = -315;			//Y�ʒu����`��_�܂ł̍���
	constexpr auto POSITION_HITX = -45;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto POSITION_HITY = -135;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto COLLISION_WIDTH = 90;		//�v���C���[�̓����蔻�艡��
	constexpr auto COLLISION_HEIGHT = 450;		//�v���C���[�̓����蔻��c��
	constexpr auto BACK_CAMERA_X = 50;			//�w�i���v���C��-�̃J��������ʂ̉����ɒu�����i�����j
	constexpr auto BACK_CAMERA_Y = 93;			//�w�i���v���C��-�̃J��������ʂ̉����ɒu�����i�c���j
	constexpr auto CHIP_CAMERA_X = 50;			//�}�b�v�`�b�v���v���C��-�̃J��������ʂ̉����ɒu�����i�����j
	constexpr auto CHIP_CAMERA_Y = 93;			//�}�b�v�`�b�v���v���C��-�̃J��������ʂ̉����ɒu�����i�c���j

	/*----------�e���[�V�����̓����蔻��֌W----------*/
	constexpr auto MIDDLEATTACK_WIDTH = 225;	//���i�U�������蔻�艡��
	constexpr auto MIDDLEATTACK_HEIGHT = 150;	//���i�U�������蔻��c��
	constexpr auto LOWATTACK_WIDTH = 225;		//���i�U�������蔻�艡��
	constexpr auto LOWATTACK_HEIGHT = 200;		//���i�U�������蔻��c��
	constexpr auto KICK_WIDTH = 225;			//�R�蓖���蔻�艡��
	constexpr auto KICK_HEIGHT = 150;			//�R�蓖���蔻��c��
	constexpr auto IAI_WIDTH = 600;				//���������蔻�艡��
	constexpr auto IAI_HEIGHT = 100;			//���������蔻��c��

	/*----------�p�����[�^�[&���͗ʊ֌W----------*/
	constexpr auto LIFE_MAX = 3;				//�̗�
	constexpr auto WALKSPEED = 5;				//�����ړ����x
	constexpr auto RUNSPEED = 9;				//����ړ����x
	constexpr auto IAI_MAX = 6;					//�����Q�[�W�̍ő�l
	constexpr auto MAX_BUF = 1000;				//���͗ʌ��E�l
	constexpr auto RUN_XBUF = 800;				//�����ԂɂȂ邽�߂̕K�v��X���͗�
	constexpr auto UP_YBUF = 800;				//�K�i���オ�邽�߂̕K�v��Y���͗�
	/*----------�`��֌W�������l----------*/
	constexpr auto FIRST_FLIP = true;					//���]
	constexpr auto FIRST_ALPHA = 255;					//�����x

	/*----------�摜�ǂݍ���&�A�j���[�V����&����t���[���֌W----------*/
	//����
	constexpr auto GRAPH_WIDTH = 1080;			//1��������̉摜�T�C�Y�i���j
	constexpr auto GRAPH_HEIGHT = 630;			//1��������̉摜�T�C�Y�i�c�j
	//�ҋ@
	constexpr auto IDLE_GRAPHNAME = "res/Samurai/S_Stand.png";	//�摜�t�@�C����
	constexpr auto IDLE_ANIMEMAX = 10;			//�S�Ẳ摜����
	constexpr auto IDLE_WIDTHCOUNT = 10;		//���̉摜����
	constexpr auto IDLE_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_IDLE = 8;			//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	//�ړ�
	constexpr auto MOVE_GRAPHNAME = "res/Samurai/S_Walk.png";	//�摜�t�@�C����
	constexpr auto MOVE_ANIMEMAX = 8;			//�S�Ẳ摜����
	constexpr auto MOVE_WIDTHCOUNT = 8;			//���̉摜����
	constexpr auto MOVE_HEIGHTCOUNT = 1;		//�c�̉摜����	
	constexpr auto ANIMESPEED_WALK = 9;			//�����A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto ANIMESPEED_RUN = 6;			//����A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto MOVE_SEFRAME = 120;			//�ړ�SE�̊Ǘ��t���[��
	constexpr auto STAIRMOVE_SPEED = 3;			//�K�i�ʒu�����X�s�[�h
	//���i�U��
	constexpr auto MIDDLEATTACK_GRAPHNAME = "res/Samurai/S_MidAttack.png";	//�摜�t�@�C����
	constexpr auto MIDDLEATTACK_ANIMEMAX = 8;	//�S�Ẳ摜����
	constexpr auto MIDDLEATTACK_WIDTHCOUNT = 8;	//���̉摜����
	constexpr auto MIDDLEATTACK_HEIGHTCOUNT = 1;//�c�̉摜����
	constexpr auto ANIMESPEED_MIDDLEATTACK = 5;	//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto MIDDLEATTACK_ANIMEFRAME = MIDDLEATTACK_ANIMEMAX * ANIMESPEED_MIDDLEATTACK; //�A�j���[�V�����t���[��
	constexpr auto MIDDLEATTACK_ALLFRAME = 40;	//���i�U���S�t���[��(�S�t���[���[�A�j���[�V�����t���[�����P�\����)
	constexpr auto MIDDLEATTACK_BEGINFRAME = 15;//���i�U�����蔭���t���[��
	constexpr auto MIDDLEATTACK_ENDFRAME = 20;	//���i�U������I���t���[��(�������Ă���̃t���[�����j
	//���i�U��
	constexpr auto LOWATTACK_GRAPHNAME = "res/Samurai/S_LowAttack.png";	//�摜�t�@�C����
	constexpr auto LOWATTACK_ANIMEMAX = 10;		//�S�Ẳ摜����
	constexpr auto LOWATTACK_WIDTHCOUNT = 10;	//���̉摜����
	constexpr auto LOWATTACK_HEIGHTCOUNT = 1;	//�c�̉摜����
	constexpr auto ANIMESPEED_LOWATTACK = 4;	//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto LOWATTACK_ANIMEFRAME = LOWATTACK_ANIMEMAX * ANIMESPEED_LOWATTACK; //�A�j���[�V�����t���[��
	constexpr auto LOWATTACK_ALLFRAME = 40;		//���i�U���S�t���[��(�S�t���[���[�A�j���[�V�����t���[�����P�\����)
	constexpr auto LOWATTACK_BEGINFRAME = 20;	//���i�U�����蔭���t���[��
	constexpr auto LOWATTACK_ENDFRAME = 16;		//���i�U������I���t���[��(�������Ă���̃t���[����)
	//�R��
	constexpr auto KICK_GRAPHNAME = "res/Samurai/S_Kick.png";		//�摜�t�@�C����
	constexpr auto KICK_ANIMEMAX = 6;			//�S�Ẳ摜����
	constexpr auto KICK_WIDTHCOUNT = 6;			//���̉摜����
	constexpr auto KICK_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_KICK = 6;			//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto KICK_ANIMEFRAME = KICK_ANIMEMAX * ANIMESPEED_KICK; //�A�j���[�V�����t���[��
	constexpr auto KICK_ALLFRAME = 36;			//�R��S�t���[��(�S�t���[���[�A�j���[�V�����t���[�����P�\����)
	constexpr auto KICK_BEGINFRAME = 18;		//�R�蔻�蔭���t���[��
	constexpr auto KICK_ENDFRAME = 12;			//�R�蔻��I���t���[��(�������Ă���̃t���[����)
	//����
	constexpr auto IAI_GRAPHNAME = "res/Samurai/S_Iai.png";			//�摜�t�@�C����
	constexpr auto IAI_ANIMEMAX = 14;			//�S�Ẳ摜����
	constexpr auto IAI_WIDTHCOUNT = 14;			//���̉摜����
	constexpr auto IAI_HEIGHTCOUNT = 1;			//�c�̉摜����
	constexpr auto ANIMESPEED_IAI = 5;			//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto IAI_ANIMEFRAME = IAI_ANIMEMAX * ANIMESPEED_IAI; //�A�j���[�V�����t���[��
	constexpr auto IAI_ALLFRAME = 73;			//�����S�t���[��(�S�t���[���[�A�j���[�V�����t���[�����P�\����)
	constexpr auto IAI_BEGINFRAME = 40;			//�������蔭���t���[��
	constexpr auto IAI_ENDFRAME =15;			//��������I���t���[��(�������Ă���̃t���[����)
	constexpr auto IAI_MOVEMENT = 60;			//��������1�t���[��������̈ړ���
	//�X�E�F�C
	constexpr auto SWAY_GRAPHNAME = "res/Samurai/S_Sway.png";		//�摜�t�@�C����
	constexpr auto SWAY_ANIMEMAX = 4;			//�S�Ẳ摜����
	constexpr auto SWAY_WIDTHCOUNT = 4;			//���̉摜����
	constexpr auto SWAY_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_SWAY = 6;			//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto SWAY_ALLFRAME = 24;			//�X�E�F�C�S�t���[��(�S�t���[���[�A�j���[�V�����t���[�����P�\����)
	constexpr auto SWAY_MOVEFRAME = 20;			//�X�E�F�C���̈ړ��t���[��
	constexpr auto SWAY_MOVEMENT = 15;			//�X�E�F�C����1�t���[��������̈ړ���
	//��_��
	constexpr auto DAMAGE_GRAPHNAME = "res/Samurai/S_Damage.png";	//�摜�t�@�C����
	constexpr auto DAMAGE_ANIMEMAX = 4;			//�S�Ẳ摜����
	constexpr auto DAMAGE_WIDTHCOUNT = 4;		//���̉摜����
	constexpr auto DAMAGE_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_DAMAGE = 5;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto DAMAGE_ANIMEFRAME = DAMAGE_ANIMEMAX * ANIMESPEED_DAMAGE; //�A�j���[�V�����t���[��
	constexpr auto DAMAGE_ALLFRAME = 25;		//��_���S�t���[��
	//���G
	constexpr auto ANIMESPEED_STAR = 8;			//���G��Ԏ��̓_�ő��x 
	constexpr auto STAR_ALPHA = 128;			//���G��Ԏ��̓����x
	constexpr auto STAR_ALLFRAME = 60;			//��_�����̖��G�t���[��

	//���S
	constexpr auto DEAD_GRAPHNAME = "res/Samurai/S_Dead.png";		//�摜�t�@�C����
	constexpr auto DEAD_ANIMEMAX = 8;			//�S�Ẳ摜����
	constexpr auto DEAD_WIDTHCOUNT = 8;			//���̉摜����
	constexpr auto DEAD_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_DEAD = 8;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto DEAD_ANIMEFRAME = DEAD_ANIMEMAX * ANIMESPEED_DEAD; //�A�j���[�V�����t���[��
	constexpr auto DEAD_ALLFRAME = 128;			//���S�S�t���[��
	
	/*----------SE�֌W----------*/
	constexpr auto WALK_SE = "se/Footstep.wav";			//�ړ�
	constexpr auto MIDDLEATTACK_SE = "se/slash3.wav";	//���i�U��
	constexpr auto LOWATTACK_SE = "se/Slash.wav";		//���i�U��
	constexpr auto KICK_SE = "se/Kick.wav";				//�R��
	constexpr auto DAMAGE_SE = "se/Damage.wav";			//��_��
	constexpr auto SWORDIN_SE = "se/Close.wav";			//�[��
	constexpr auto IAI_SE = "se/Iai.wav";				//����

}