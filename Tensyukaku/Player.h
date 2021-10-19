/*****************************************************************//**
 * \file   Player.h
 * \brief �v���C���[�N���X�i�I�u�W�F�N�g�x�[�X�N���X�̃T�u�N���X�j
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include   "ObjectBase.h"
//��d�C���N���[�h�h�~
class Game;
/** �v���C���[ */
class Player : public ObjectBase {
public:
   /**
    * \brief      �R���X�g���N�^
    * \param x    X���W
    * \param y    Y���W
    * \param flip ���]����
    */
   Player( int x,int y,bool flip);
   /**
    * \brief �f�X�g���N�^
    */
   ~Player();
   /**
    * \brief                     �������z�֐��̃I�[�o�[���C�h
    * \return OBJECTTYPE::PLAYER �I�u�W�F�N�g�̎�ʁi�v���C���[�j��Ԃ�
    */
   virtual OBJECTTYPE   GetObjType() { return OBJECTTYPE::PLAYER; }
   /**
    * \brief �������֐�
    */
   void Init()override;
   /**
    * \brief   �X�V�֐�
    * \param g �Q�[���̎Q��
    */
   void Process(Game& g)override;
   /**
    * \brief   �`��֐�
    * \param g �Q�[���̎Q��
    */
   void Draw(Game& g)override;

private:
   /** �v���C���[�̏�ԗ� */
   enum class PLAYERSTATE { 
      APPEAR,       //!< �o��
      SWORDOUT,     //!< ����
      IDLE,         //!< �ҋ@
      MOVE,         //!< �ړ�
      MIDDLEATTACK, //!< ���i�U��
      LOWATTACK,    //!< ���i�U��
      KICK,         //!< �R��
      IAI,          //!< ����
      SWAY,         //!< �X�E�F�C
      DAMAGE,       //!< ��_��
      DEAD,         //!< ���S
      STAIRMOVE,    //!< �K�i�ʒu����
      STAIRUP,      //!< �K�i�㏸
      BOSSSTAIRMOVE,//!< �{�X�K�i�ʒu����
      BOSSSTAIRUP,  //!< �{�X�K�i�㏸
      EVENTA,       //!< �C�x���gA
      EVENTB,       //!< �C�x���gB
      SPECIALATTACK //!< ����U��
   };
   /**
    * \brief   ���G��Ԋ֐�
    * \param g �Q�[���̎Q��
    */
   void Star(Game& g);
   /**
    * \brief   �o����Ԋ֐�
    * \param g �Q�[���̎Q��
    */
   void Appear(Game& g);
   /**
    * \brief   ������Ԋ֐�
    * \param g �Q�[���̎Q��
    */
   void Swordout(Game& g);
   /**
    * \brief   �ҋ@��Ԋ֐�
    * \param g �Q�[���̎Q��
    */
   void Idle(Game& g);
   /**
    * \brief   �ړ���Ԋ֐�
    * \param g �Q�[���̎Q��
    */
   void Move(Game& g);
   /**
    * \brief   ���i�U����Ԋ֐�
    * \param g �Q�[���̎Q��
    */
   void MidAttack(Game& g);
   /**
    * \brief   ���i�U����Ԋ֐�
    * \param g �Q�[���̎Q��
    */
   void LowAttack(Game& g);
   /**
    * \brief   �R���Ԋ֐�
    * \param g �Q�[���̎Q��
    */
   void Kick(Game& g);
   /**
    * \brief   ������Ԋ֐�
    * \param g �Q�[���̎Q��
    */
   void Iai(Game& g);
   /**
    * \brief   �X�E�F�C��Ԋ֐�
    * \param g �Q�[���̎Q��
    */
   void Sway(Game& g);
   /**
    * \brief   ��_����Ԋ֐�
    * \param g �Q�[���̎Q��
    */
   void Damage(Game& g);
   /**
    * \brief   ���S��Ԋ֐�
    * \param g �Q�[���̎Q��
    */
   void Dead(Game& g);
   /**
    * \brief   �K�i�ʒu������Ԋ֐�
    * \param g �Q�[���̎Q��
    */
   void StairMove(Game& g);
   /**
    * \brief   �K�i�㏸��Ԋ֐�
    * \param g �Q�[���̎Q��
    */
   void StairUp(Game& g);
   /**
    * \brief   �{�X�K�i�ʒu������Ԋ֐�
    * \param g �Q�[���̎Q��
    */
   void BossStairMove(Game& g);
   /**
    * \brief   �{�X�K�i�㏸��Ԋ֐�
    * \param g �Q�[���̎Q��
    */
   void BossStairUp(Game& g);
   /**
    * \brief   �{�X�C�x���gA��Ԋ֐�
    * \param g �Q�[���̎Q��
    */
   void BossEventA(Game& g);
   /**
    * \brief   �{�X�C�x���gB��Ԋ֐�
    * \param g �Q�[���̎Q��
    */
   void BossEventB(Game& g);
   /**
    * \brief   ����U����Ԋ֐�
    * \param g �Q�[���̎Q��
    */
   void SpecialAttack(Game& g);
   /**
    * \brief   �e�����蔻��֐�
    * \param g �Q�[���̎Q��
    */
   void HitJudge(Game& g);
   /**
    * \brief   �v���C���[�ʒu����J�������W�ݒ�֐�
    * \param g �Q�[���̎Q��
    */
   void CameraSetting(Game& g);
   /**
    * \brief   UI�̃C���X�^���X�����֐�
    * \param g �Q�[���̎Q��
    */
   void UIAppear(Game& g);
   /**
    * \brief   �����Q�[�WMAX���Ɏ��@����&SE�����֐�
    * \param g �Q�[���̎Q��
    */
   void GaugeMax(Game& g);
   /**
    * \brief   ���X�e�B�b�N�̓��͗ʂɂ��X�e�[�^�X�ݒ�֐�
    * \param g �Q�[���̎Q��
    */
   void BufSetting(Game& g);
   /**
    * \brief   �ċN����̊J�n�Ȃ�Δ�����Ԃ���J�n������֐�
    * \param g �Q�[���̎Q��
    */
   void RestartCheck(Game& g);
   /**
    * \brief   �|�[�Y�̓��͊Ǘ��֐�
    * \param g �Q�[���̎Q��
    */
   void PauseInput(Game& g);
   /**
    * \brief   �f�o�b�O�p�֐�
    * \param g �Q�[���̎Q��
    */
   void DebugDraw(Game& g);
   /**
    * \brief �摜�ǂݍ��݊֐�
    */
   void LoadPicture();
   /**
    * \brief SE�ݍ��݊֐�
    */
   void LoadSE();
   /**
    * \brief SE�{�����[���ݒ�֐�
    */
   void VolumeInit();
   /**
    * \brief SE�{�����[���ύX�֐�
    */
   void VolumeChange();

   /*---------�����o�ϐ�----------*/
   int _move_animespeed;    //!< �ړ����̃A�j���X�s�[�h
   int _camera_x;           //!< �J�����ʒu
   int _stair_x;            //!< �K�i��X���W�ۑ��ϐ�
   int _player_y;           //!< �K�i�㏸���̃v���C���[Y���W�ۑ��ϐ�
   int _star_cnt;           //!< ���G��Ԍo�ߎ��ԋL�^�ϐ�
   float _stairup_spd;      //!< �K�i�㏸���x
   float _angle;            //!< �p�x
   bool _stairup_flag;      //!< �K�i�㏸�̎�t����p�t���O
   bool _stairflip_flag;    //!< �K�i�̔��]����ۑ��t���O
   bool _star_flag;         //!< ���G��ԊǗ��t���O
   bool _ui_flag;           //!< UI�`��p�t���O
   bool _gaugemax_flag;     //!< �����Q�[�W��MAX�ɂȂ������̃t���O
   bool _nohit_flag;        //!< ���[�V�������ɓ����蔻����s��Ȃ��t���O
   bool _tutorialhit_flag;  //!< �`���[�g���A���{�[�h�Ƃ̓����蔻��t���O
   bool _restartcheck_flag; //!< �ċN����̊J�n���ǂ����m�F����t���O
   bool _pauseinput_flag;   //!< �|�[�Y�̓��͂��󂯂��邩�ǂ����̃t���O
   Vector2 _velocity_dir;   //!< ���x����
   PLAYERSTATE _state;      //!< ��ԑJ�ڕϐ�
};

/** �v���C���[�N���X�p�萔 */
namespace PInfo {
   /*----------�v���C���[�̊e���W�֌W----------*/
   constexpr auto POSITION_X = 4000;          //!< ���������ʒu�i��������j
   constexpr auto POSITION_Y = 7840;          //!< �c�������ʒu�i��������j
   constexpr auto CPOINT_POSITION_X = 3500;   //!< �`�F�b�N�|�C���gX���W
   constexpr auto CPOINT_POSITION_Y = 4040;   //!< �`�F�b�N�|�C���gY���W
   constexpr auto GRAPHPOINT_X = 0;           //!< X�ʒu����`��_�܂ł̍���
   constexpr auto GRAPHPOINT_Y = -315;        //!< Y�ʒu����`��_�܂ł̍���
   constexpr auto POSITION_HITX = -60;        //!< �`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto POSITION_HITY = -135;       //!< �`��_���瓖���蔻�荶����W�܂ł̍���
   constexpr auto COLLISION_WIDTH = 120;      //!< �v���C���[�̓����蔻�艡��
   constexpr auto COLLISION_HEIGHT = 450;     //!< �v���C���[�̓����蔻��c��
   constexpr auto BACK_CAMERA_X = 50;         //!< �w�i���v���C���[�̃J��������ʂ̉����ɒu�����i�����j
   constexpr auto BACK_CAMERA_Y = 93;         //!< �w�i���v���C���[�̃J��������ʂ̉����ɒu�����i�c���j
   constexpr auto CHIP_CAMERA_X = 50;         //!< �}�b�v�`�b�v���v���C��-�̃J��������ʂ̉����ɒu�����i�����j
   constexpr auto CHIP_CAMERA_Y = 93;         //!< �}�b�v�`�b�v���v���C��-�̃J��������ʂ̉����ɒu�����i�c���j

   /*----------�e���[�V�����̓����蔻��֌W----------*/
   constexpr auto MIDDLEATTACK_WIDTH = 275;   //!< ���i�U�������蔻�艡��
   constexpr auto MIDDLEATTACK_HEIGHT = 150;  //!< ���i�U�������蔻��c��
   constexpr auto LOWATTACK_WIDTH = 275;      //!< ���i�U�������蔻�艡��
   constexpr auto LOWATTACK_HEIGHT = 200;     //!< ���i�U�������蔻��c��
   constexpr auto KICK_WIDTH = 225;           //!< �R�蓖���蔻�艡��
   constexpr auto KICK_HEIGHT = 150;          //!< �R�蓖���蔻��c��
   constexpr auto IAI_WIDTH = 780;            //!< ���������蔻�艡��
   constexpr auto IAI_HEIGHT = 100;           //!< ���������蔻��c��
   constexpr auto SPECIALATTACK_WIDTH = 300;  //!< ����U�������蔻�艡��
   constexpr auto SPECIALATTACK_HEIGHT = 100; //!< ����U�������蔻��c��

   /*----------�p�����[�^�[&���͗ʊ֌W----------*/
   constexpr auto LIFE_MAX = 3;               //!< �̗�
   constexpr auto WALKSPEED = 5;              //!< �����ړ����x
   constexpr auto RUNSPEED = 9;               //!< ����ړ����x
   constexpr auto STAIRMOVE_SPEED = 3;        //!< �K�i�ʒu�����X�s�[�h
   constexpr auto STAIRUP_SPEED = 5.01f;      //!< �K�i�㏸���x
   constexpr auto BOSSSTAIRUP_SPEED = 3.0f;   //!< �{�X�K�i�㏸���x
   constexpr auto IAI_MAX = 5;                //!< �����Q�[�W�̍ő�l
   constexpr auto MAX_BUF = 1000;             //!< ���͗ʌ��E�l
   constexpr auto RUN_XBUF = 800;             //!< �����ԂɂȂ邽�߂̕K�v��X���͗�
   constexpr auto UP_YBUF = 800;              //!< �K�i���オ�邽�߂̕K�v��Y���͗�
   /*----------�`��֌W�������l----------*/
   constexpr auto FIRST_FLIP = true;          //!< ���]
   constexpr auto FIRST_ALPHA = 255;          //!< �����x

   /*----------�摜�ǂݍ���&�A�j���[�V����&����t���[���֌W----------*/
   //����
   constexpr auto GRAPH_WIDTH = 1080;         //!< 1��������̉摜�T�C�Y�i���j
   constexpr auto GRAPH_HEIGHT = 630;         //!< 1��������̉摜�T�C�Y�i�c�j
   //�o��
   constexpr auto APPEAR_GRAPHNAME = "res/Samurai/S_Appear.png";   //!< �o���̉摜�t�@�C����
   constexpr auto APPEAR_ANIMEMAX = 20;       //!< �o���̑S�Ẳ摜����
   constexpr auto APPEAR_WIDTHCOUNT = 7;      //!< �o���̉��̉摜����
   constexpr auto APPEAR_HEIGHTCOUNT = 3;     //!< �o���̏c�̉摜����
   constexpr auto ANIMESPEED_APPEAR = 5;      //!< �o���̃A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto APPEAR_ANIMEFRAME = APPEAR_ANIMEMAX * ANIMESPEED_APPEAR; //!< �o���̃A�j���[�V�����t���[��
   //����
   constexpr auto SWORDOUT_GRAPHNAME = "res/Samurai/S_Appear.png";   //!< �����̉摜�t�@�C����
   constexpr auto SWORDOUT_ANIMEMAX = 20;     //!< �����̑S�Ẳ摜����
   constexpr auto SWORDOUT_WIDTHCOUNT = 7;    //!< �����̉��̉摜����
   constexpr auto SWORDOUT_HEIGHTCOUNT = 3;   //!< �����̏c�̉摜����
   constexpr auto ANIMESPEED_SWORDOUT = 5;    //!< �����̃A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto SWORDOUT_ANIMEFRAME = SWORDOUT_ANIMEMAX * ANIMESPEED_SWORDOUT; //!< �����̃A�j���[�V�����t���[��
   //�ҋ@
   constexpr auto IDLE_GRAPHNAME = "res/Samurai/S_Stand.png";   //!< �ҋ@�̉摜�t�@�C����
   constexpr auto IDLE_ANIMEMAX = 10;          //!< �ҋ@�̑S�Ẳ摜����
   constexpr auto IDLE_WIDTHCOUNT = 10;        //!< �ҋ@�̉��̉摜����
   constexpr auto IDLE_HEIGHTCOUNT = 1;        //!< �ҋ@�̏c�̉摜����
   constexpr auto ANIMESPEED_IDLE = 8;         //!< �ҋ@�̃A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   //�ړ�
   constexpr auto MOVE_GRAPHNAME = "res/Samurai/S_Walk.png";   //!< �ړ��̉摜�t�@�C����
   constexpr auto MOVE_ANIMEMAX = 8;           //!< �ړ��̑S�Ẳ摜����
   constexpr auto MOVE_WIDTHCOUNT = 8;         //!< �ړ��̉��̉摜����
   constexpr auto MOVE_HEIGHTCOUNT = 1;        //!< �ړ��̏c�̉摜����
   constexpr auto ANIMESPEED_WALK = 9;         //!< �����A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto ANIMESPEED_RUN = 6;          //!< ����A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   //���i�U��
   constexpr auto MIDDLEATTACK_GRAPHNAME = "res/Samurai/S_MidAttack.png";   //!< ���i�U���̉摜�t�@�C����
   constexpr auto MIDDLEATTACK_ANIMEMAX = 8;   //!< ���i�U���̑S�Ẳ摜����
   constexpr auto MIDDLEATTACK_WIDTHCOUNT = 8; //!< ���i�U���̉��̉摜����
   constexpr auto MIDDLEATTACK_HEIGHTCOUNT = 1;//!< ���i�U���̏c�̉摜����
   constexpr auto ANIMESPEED_MIDDLEATTACK = 5; //!< ���i�U���̃A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto MIDDLEATTACK_ANIMEFRAME = MIDDLEATTACK_ANIMEMAX * ANIMESPEED_MIDDLEATTACK; //!< ���i�U���̃A�j���[�V�����t���[��
   constexpr auto MIDDLEATTACK_ALLFRAME = 40;  //!< ���i�U���S�t���[��(�S�t���[���[�A�j���[�V�����t���[�����P�\����)
   constexpr auto MIDDLEATTACK_BEGINFRAME = 15;//!< ���i�U�����蔭���t���[��
   constexpr auto MIDDLEATTACK_ENDFRAME = 20;  //!< ���i�U������I���t���[��(�������Ă���̃t���[�����j
   //���i�U��
   constexpr auto LOWATTACK_GRAPHNAME = "res/Samurai/S_LowAttack.png";   //!< ���i�U���̉摜�t�@�C����
   constexpr auto LOWATTACK_ANIMEMAX = 10;     //!< ���i�U���̑S�Ẳ摜����
   constexpr auto LOWATTACK_WIDTHCOUNT = 10;   //!< ���i�U���̉��̉摜����
   constexpr auto LOWATTACK_HEIGHTCOUNT = 1;   //!< ���i�U���̏c�̉摜����
   constexpr auto ANIMESPEED_LOWATTACK = 4;    //!< ���i�U���̃A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto LOWATTACK_ANIMEFRAME = LOWATTACK_ANIMEMAX * ANIMESPEED_LOWATTACK; //!< ���i�U���̃A�j���[�V�����t���[��
   constexpr auto LOWATTACK_ALLFRAME = 40;     //!< ���i�U���S�t���[��(�S�t���[���[�A�j���[�V�����t���[�����P�\����)
   constexpr auto LOWATTACK_BEGINFRAME = 16;   //!< ���i�U�����蔭���t���[��
   constexpr auto LOWATTACK_ENDFRAME = 20;     //!< ���i�U������I���t���[��(�������Ă���̃t���[����)
   //�R��
   constexpr auto KICK_GRAPHNAME = "res/Samurai/S_Kick.png";   //!< �R��̉摜�t�@�C����
   constexpr auto KICK_ANIMEMAX = 6;           //!< �R��̑S�Ẳ摜����
   constexpr auto KICK_WIDTHCOUNT = 6;         //!< �R��̉��̉摜����
   constexpr auto KICK_HEIGHTCOUNT = 1;        //!< �R��̏c�̉摜����
   constexpr auto ANIMESPEED_KICK = 5;         //!< �R��̃A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto KICK_ANIMEFRAME = KICK_ANIMEMAX * ANIMESPEED_KICK; //!< �R��̃A�j���[�V�����t���[��
   constexpr auto KICK_ALLFRAME = 30;          //!< �R��S�t���[��(�S�t���[���[�A�j���[�V�����t���[�����P�\����)
   constexpr auto KICK_BEGINFRAME = 12;        //!< �R�蔻�蔭���t���[��
   constexpr auto KICK_ENDFRAME = 10;          //!< �R�蔻��I���t���[��(�������Ă���̃t���[����)
   //����
   constexpr auto IAI_GRAPHNAME = "res/Samurai/S_Iai.png";   //!< �����̉摜�t�@�C����
   constexpr auto IAI_ANIMEMAX = 14;           //!< �����̑S�Ẳ摜����
   constexpr auto IAI_WIDTHCOUNT = 14;         //!< �����̉��̉摜����
   constexpr auto IAI_HEIGHTCOUNT = 1;         //!< �����̏c�̉摜����
   constexpr auto ANIMESPEED_IAI = 5;          //!< �����̃A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto IAI_ANIMEFRAME = IAI_ANIMEMAX * ANIMESPEED_IAI; //!< �����̃A�j���[�V�����t���[��
   constexpr auto IAI_ALLFRAME = 73;           //!< �����S�t���[��(�S�t���[���[�A�j���[�V�����t���[�����P�\����)
   constexpr auto IAI_BEGINFRAME = 40;         //!< �������蔭���t���[��
   constexpr auto IAI_ENDFRAME =55;            //!< ��������I���t���[��(�������Ă���̃t���[����)
   constexpr auto IAI_MOVEMENT = 40;           //!< ��������1�t���[��������̈ړ���
   //�X�E�F�C
   constexpr auto SWAY_GRAPHNAME = "res/Samurai/S_Sway.png";      //!< �X�E�F�C�̉摜�t�@�C����
   constexpr auto SWAY_ANIMEMAX = 4;           //!< �X�E�F�C�̑S�Ẳ摜����
   constexpr auto SWAY_WIDTHCOUNT = 4;         //!< �X�E�F�C�̉��̉摜����
   constexpr auto SWAY_HEIGHTCOUNT = 1;        //!< �X�E�F�C�̏c�̉摜����
   constexpr auto ANIMESPEED_SWAY =6;          //!< �X�E�F�C�̃A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto SWAY_ALLFRAME = 24;          //!< �X�E�F�C�S�t���[��(�S�t���[���[�A�j���[�V�����t���[�����P�\����)
   constexpr auto SWAY_NOHITBEGINFRAME = 0;    //!< �X�E�F�C�̖��G����J�n�t���[��
   constexpr auto SWAY_NOHITENDFRAME = 20;     //!< �X�E�F�C�̖��G����I���t���[��
   constexpr auto SWAY_MOVEFRAME = 20;         //!< �X�E�F�C���̈ړ��t���[��
   constexpr auto SWAY_MOVEMENT = 12;          //!< �X�E�F�C����1�t���[��������̈ړ���
   //��_��
   constexpr auto DAMAGE_GRAPHNAME = "res/Samurai/S_Damage.png";   //!< ��_���̉摜�t�@�C����
   constexpr auto DAMAGE_ANIMEMAX = 4;         //!< ��_���̑S�Ẳ摜����
   constexpr auto DAMAGE_WIDTHCOUNT = 4;       //!< ��_���̉��̉摜����
   constexpr auto DAMAGE_HEIGHTCOUNT = 1;      //!< ��_���̏c�̉摜����
   constexpr auto ANIMESPEED_DAMAGE =7;        //!< ��_���̃A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto DAMAGE_ANIMEFRAME = DAMAGE_ANIMEMAX * ANIMESPEED_DAMAGE; //!< ��_���̃A�j���[�V�����t���[��
   constexpr auto DAMAGE_ALLFRAME = 28;        //!< ��_���S�t���[��
   //���G
   constexpr auto ANIMESPEED_STAR = 8;         //!< ���G��Ԏ��̓_�ő��x 
   constexpr auto STAR_ALPHA = 128;            //!< ���G��Ԏ��̓����x
   constexpr auto STAR_ALLFRAME = 60;          //!< ��_�����̖��G�t���[��
   //���S
   constexpr auto DEAD_GRAPHNAME = "res/Samurai/S_Dead.png";   //!< ���S�̉摜�t�@�C����
   constexpr auto DEAD_ANIMEMAX = 8;           //!< ���S�̑S�Ẳ摜����
   constexpr auto DEAD_WIDTHCOUNT = 8;         //!< ���S�̉��̉摜����
   constexpr auto DEAD_HEIGHTCOUNT = 1;        //!< ���S�̏c�̉摜����
   constexpr auto ANIMESPEED_DEAD = 8;         //!< ���S�̃A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto DEAD_ANIMEFRAME = DEAD_ANIMEMAX * ANIMESPEED_DEAD; //!< ���S�̃A�j���[�V�����t���[��
   constexpr auto DEAD_ALLFRAME = 128;         //!< ���S�S�t���[��
   //����U��
   constexpr auto SPECIALATTACK_GRAPHNAME = "res/Samurai/S_Special.png";   //!< ����U���̉摜�t�@�C����
   constexpr auto SPECIALATTACK_ANIMEMAX = 48;  //!< ����U���̑S�Ẳ摜����
   constexpr auto SPECIALATTACK_WIDTHCOUNT = 16;//!< ����U���̉��̉摜����
   constexpr auto SPECIALATTACK_HEIGHTCOUNT = 3;//!< ����U���̏c�̉摜����
   constexpr auto ANIMESPEED_SPECIALATTACK = 5; //!< ����U���̃A�j���X�s�[�h�i���t���[�����Ƃɉ摜��؂�ւ��邩�j
   constexpr auto SPECIALATTACK_ANIMEFRAME = SPECIALATTACK_ANIMEMAX * ANIMESPEED_SPECIALATTACK; //!< ����U���̃A�j���[�V�����t���[��
   constexpr auto SPECIALATTACK_ALLFRAME = 270; //!< ����U���S�t���[��(�S�t���[���[�A�j���[�V�����t���[�����P�\����)
   constexpr auto SPECIALATTACK_BEGINFRAME = 40;//!< ����U�����蔭���t���[��
   constexpr auto SPECIALATTACK_ENDFRAME = 80;  //!< ����U������I���t���[��(�������Ă���̃t���[�����j
}