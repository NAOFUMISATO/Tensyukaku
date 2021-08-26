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
	void	Sway(Game& g);			//�X�E�F�C���̏���
	void	Damage(Game& g);		//��_�����̏���
	void	Dead(Game& g);			//���S���̏���
	void	StairMove(Game& g);		//�K�i�ʒu�����̏���
	void	StairUp(Game& g);		//�K�i�㏸�̏���
	void	LoadActionGraph();		//�v���C���[�̉摜�ǂݍ��݊֐�
	void	LoadActionSE();			//�v���C���[�̌��ʉ��ǂݍ��݊֐�
	void	AnimeUpdate(Game& g);	//�v���C���[�̃A�j���[�V�����֐�
	void	DebugDraw(Game& g);		//�f�o�b�O�p�֐�
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
	bool	_StairFlip_Flag;//�K�i�̔��]����ۑ��t���O
	int		_Stair_x;		//�K�i��X���W�ۑ��ϐ�
	int		_Player_y;		//�K�i�p�v���C���[Y���W�ۑ��ϐ�

};


namespace PInfo {

	/*----------�v���C���[�̊e���W�֌W----------*/
	constexpr auto POSITION_X = 200;			//���������ʒu�i��������j
	constexpr auto POSITION_Y = 2200;			//�c�������ʒu�i��������j
	constexpr auto GRAPHPOINT_X = 0;			//X�ʒu����`��_�܂ł̍���
	constexpr auto GRAPHPOINT_Y = -210;			//Y�ʒu����`��_�܂ł̍���
	constexpr auto POSITION_HITX = -30;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto POSITION_HITY = -90;			//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto COLLISION_WIDTH = 60;		//�v���C���[�̓����蔻�艡��
	constexpr auto COLLISION_HEIGHT = 300;		//�v���C���[�̓����蔻��c��
	constexpr auto BACK_CAMERA_X = 50;			//�w�i���v���C��-�̃J��������ʂ̉����ɒu�����i�����j
	constexpr auto BACK_CAMERA_Y = 93;			//�w�i���v���C��-�̃J��������ʂ̉����ɒu�����i�c���j
	constexpr auto CHIP_CAMERA_X = 50;			//�}�b�v�`�b�v���v���C��-�̃J��������ʂ̉����ɒu�����i�����j
	constexpr auto CHIP_CAMERA_Y = 93;			//�}�b�v�`�b�v���v���C��-�̃J��������ʂ̉����ɒu�����i�c���j

	/*----------�e���[�V�����̓����蔻��֌W----------*/
	constexpr auto MIDDLEATTACK_WIDTH = 150;	//���i�U�������蔻�艡��
	constexpr auto MIDDLEATTACK_HEIGHT = 100;	//���i�U�������蔻��c��
	constexpr auto LOWATTACK_WIDTH = 150;		//���i�U�������蔻�艡��
	constexpr auto LOWATTACK_HEIGHT = 100;		//���i�U�������蔻��c��
	constexpr auto KICK_WIDTH = 150;			//�R�蓖���蔻�艡��
	constexpr auto KICK_HEIGHT = 100;			//�R�蓖���蔻��c��
	constexpr auto IAI_WIDTH = 600;				//���������蔻�艡��
	constexpr auto IAI_HEIGHT = 100;			//���������蔻��c��

	/*----------�p�����[�^�[�֌W----------*/
	constexpr auto LIFE_MAX = 3;				//�̗�
	constexpr auto SPEED = 7;					//�ړ����x

	/*----------�摜�ǂݍ���&�A�j���[�V����&����t���[���֌W----------*/
	//����
	constexpr auto GRAPH_WIDTH = 720;			//1��������̉摜�T�C�Y�i���j
	constexpr auto GRAPH_HEIGHT = 420;			//1��������̉摜�T�C�Y�i�c�j
	constexpr auto GRAPH_SCALE = 1.0;			//�g�嗦
	constexpr auto GRAPH_ANGLE = 0;				//�p�x
	//�ҋ@
	constexpr auto IDLE_GRAPHNAME = "res/Samurai/S_Stand.png";	//�摜�t�@�C����
	constexpr auto IDLE_ANIMEMAX = 1;			//�S�Ẳ摜����
	constexpr auto IDLE_WIDTHCOUNT = 1;			//���̉摜����
	constexpr auto IDLE_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_IDLE = 1;			//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	//�ړ�
	constexpr auto MOVE_GRAPHNAME = "res/Samurai/S_Walk.png";	//�摜�t�@�C����
	constexpr auto MOVE_ANIMEMAX = 6;			//�S�Ẳ摜����
	constexpr auto MOVE_WIDTHCOUNT = 6;			//���̉摜����
	constexpr auto MOVE_HEIGHTCOUNT = 1;		//�c�̉摜����	
	constexpr auto ANIMESPEED_MOVE = 6;			//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto MOVE_SEFRAME = 120;			//�ړ�SE�̊Ǘ��t���[��
	//���i�U��
	constexpr auto MIDDLEATTACK_GRAPHNAME = "res/Samurai/S_MidAttack.png";	//�摜�t�@�C����
	constexpr auto MIDDLEATTACK_ANIMEMAX = 8;	//�S�Ẳ摜����
	constexpr auto MIDDLEATTACK_WIDTHCOUNT = 8;	//���̉摜����
	constexpr auto MIDDLEATTACK_HEIGHTCOUNT = 1;//�c�̉摜����
	constexpr auto ANIMESPEED_MIDDLEATTACK = 4;	//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto MIDDLEATTACK_ALLFRAME = 30;	//���i�U���S�t���[��
	constexpr auto MIDDLEATTACK_BEGINFRAME = 12;//���i�U�����蔭���t���[��
	constexpr auto MIDDLEATTACK_ENDFRAME = 12;	//���i�U������I���t���[��(�������Ă���̃t���[�����j
	//���i�U��
	constexpr auto LOWATTACK_GRAPHNAME = "res/Samurai/S_LowAttack.png";	//�摜�t�@�C����
	constexpr auto LOWATTACK_ANIMEMAX = 8;		//�S�Ẳ摜����
	constexpr auto LOWATTACK_WIDTHCOUNT = 8;	//���̉摜����
	constexpr auto LOWATTACK_HEIGHTCOUNT = 1;	//�c�̉摜����
	constexpr auto ANIMESPEED_LOWATTACK = 4;	//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto LOWATTACK_ALLFRAME = 30;		//���i�U���S�t���[��
	constexpr auto LOWATTACK_BEGINFRAME = 12;	//���i�U�����蔭���t���[��
	constexpr auto LOWATTACK_ENDFRAME = 12;		//���i�U������I���t���[��(�������Ă���̃t���[����)
	//�R��
	constexpr auto KICK_GRAPHNAME = "res/Samurai/S_Kick.png";		//�摜�t�@�C����
	constexpr auto KICK_ANIMEMAX = 6;			//�S�Ẳ摜����
	constexpr auto KICK_WIDTHCOUNT = 6;			//���̉摜����
	constexpr auto KICK_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_KICK = 5;			//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto KICK_ALLFRAME = 28;			//�R��S�t���[��
	constexpr auto KICK_BEGINFRAME = 10;		//�R�蔻�蔭���t���[��
	constexpr auto KICK_ENDFRAME = 10;			//�R�蔻��I���t���[��(�������Ă���̃t���[����)
	//����
	constexpr auto IAI_GRAPHNAME = "res/Samurai/S_Iai.png";			//�摜�t�@�C����
	constexpr auto IAI_ANIMEMAX = 8;			//�S�Ẳ摜����
	constexpr auto IAI_WIDTHCOUNT = 8;			//���̉摜����
	constexpr auto IAI_HEIGHTCOUNT = 1;			//�c�̉摜����
	constexpr auto ANIMESPEED_IAI = 5;			//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto IAI_ALLFRAME = 38;			//�����S�t���[��
	constexpr auto IAI_BEGINFRAME = 26;			//�������蔭���t���[��
	constexpr auto IAI_ENDFRAME = 12;			//��������I���t���[��(�������Ă���̃t���[����)
	//�X�E�F�C
	constexpr auto SWAY_GRAPHNAME = "res/Samurai/S_Sway.png";		//�摜�t�@�C����
	constexpr auto SWAY_ANIMEMAX = 1;			//�S�Ẳ摜����
	constexpr auto SWAY_WIDTHCOUNT = 1;			//���̉摜����
	constexpr auto SWAY_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_SWAY = 5;			//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto SWAY_ALLFRAME = 40;			//�X�E�F�C�S�t���[��
	constexpr auto SWAY_BEGINFRAME = 15;		//���G���蔭���t���[��
	constexpr auto SWAY_ENDFRAME = 15;			//���G����I���t���[��(�������Ă���̃t���[����)
	//��_��
	constexpr auto DAMAGE_GRAPHNAME = "res/Samurai/S_Damage.png";	//�摜�t�@�C����
	constexpr auto DAMAGE_ANIMEMAX = 1;			//�S�Ẳ摜����
	constexpr auto DAMAGE_WIDTHCOUNT = 1;		//���̉摜����
	constexpr auto DAMAGE_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto ANIMESPEED_DAMAGE = 40;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	constexpr auto DAMAGE_ALLFRAME = 38;		//��_���S�t���[��
	//���G
	constexpr auto ANIMESPEED_STAR = 8;			//���G��Ԏ��̓_�ő��x 
	constexpr auto STAR_ALLFRAME = 180;			//��_�����̖��G�t���[��
	//���S
	constexpr auto DEAD_GRAPHNAME = "res/Samurai/S_Dead.png";		//�摜�t�@�C����
	constexpr auto DEAD_ANIMEMAX = 1;			//�S�Ẳ摜����
	constexpr auto DEAD_WIDTHCOUNT = 1;			//���̉摜����
	constexpr auto DEAD_HEIGHTCOUNT = 1;		//�c�̉摜����
	constexpr auto DEAD_ALLFRAME = 160;			//���S�S�t���[��
	constexpr auto ANIMESPEED_DEAD = 120;		//�A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
	
	/*----------SE�֌W----------*/
	constexpr auto WALK_SE = "se/Footstep.wav";			//�ړ�
	constexpr auto MIDDLEATTACK_SE = "se/slash3.wav";	//���i�U��
	constexpr auto LOWATTACK_SE = "se/Slash.wav";		//���i�U��
	constexpr auto KICK_SE = "se/Kick.wav";				//�R��
	constexpr auto DAMAGE_SE = "se/Damage.wav";			//��_��
	constexpr auto SWORDIN_SE = "se/Close.wav";			//�[��
	constexpr auto IAI_SE = "se/Iai.wav";				//����

}