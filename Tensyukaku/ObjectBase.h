/*****************************************************************//**
 * \file   ObjectBase.h
 * \brief  �e�I�u�W�F�N�g�̃x�[�X�N���X
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "HitBox.h"
#include <vector>
#include "Math.h"
#include <utility>
#include <tuple>
#include <unordered_map>
//��d�C���N���[�h�h�~
class Game;
/** �e�I�u�W�F�N�g�̃x�[�X */
class ObjectBase {
public:
   /**
    * \brief �R���X�g���N�^
    */
   ObjectBase();
   /**
    * \brief �f�X�g���N�^
    */
   ~ObjectBase();
   /** �I�u�W�F�N�g�̎�ޗ� */
   enum class OBJECTTYPE {
      TITLELOGO,       //!< �^�C�g�����S
      GAMESTART,       //!< �Q�[���X�^�[�g�Z���N�g
      EXPLAIN,         //!< ������ʃZ���N�g
      GAMEEND,         //!< �Q�[���I���Z���N�g
      CREDIT,          //!< �N���W�b�g�Z���N�g
      CURSOR,          //!< �^�C�g���J�[�\��
      PLAYER,          //!< �v���C���[
      ENEMY,           //!< �G
      SHIELD,          //!< ��
      BOSS,            //!< �{�X
      UI,              //!< UI
      PARTICLE,        //!< �p�[�e�B�N��
      EFECT,           //!< �G�t�F�N�g
      MIDDLEATTACK,    //!< ���i�U�������蔻��
      LOWATTACK,       //!< ���i�U�������蔻��
      KICK,            //!< �R�蓖���蔻��
      IAI,             //!< ���������蔻��
      SPECIAL,         //!< ����U�������蔻��
      PRIVATECOLLISION,//!< �󂯑��Ŕ�����s��Ȃ������蔻��
      BUSHIATTACK,     //!< ���m�̍U�������蔻��
      NINJAATTACK,     //!< �E�҂̍U�������蔻��
      KUNAI,           //!< �N�i�C�����蔻��
      SHIELDERATTACK,  //!< �����̍U�������蔻��
      LANCERATTACK,    //!< �����̍U�������蔻��
      BUSYOATTACK,     //!< �����̍U�������蔻��
      ZYOUNINATTACK,   //!< ��E�̍U�������蔻��
      STAIR,           //!< �K�i
      BOSSSTAIR,       //!< �{�X�K�i
      RESTPOINT,       //!< �񕜃|�C���g�p�|����
      POISONNINJA,     //!< �ŉt�E��
      POISON,          //!< �ŉt
      ANDON,           //!< �s��
      FLAME,           //!< �s���̉�
      MUGENANDON,      //!< �����s��
      MUGENFLAME,      //!< �����s���̖�����
      TUTORIALBOARD,   //!< �`���[�g���A���{�[�h
      RECOVERYBLOCK,   //!< �񕜃u���b�N
      CPOINTBLOCK,     //!< �`�F�b�N�|�C���g�u���b�N
      BOSSEVENTBLOCK,  //!< �{�X�C�x���g�u���b�N
      FLAMEBLOCK,      //!< �����o�u���b�N
      SPAWNBLOCK,      //!< �X�|�[���u���b�N
      FLOORTEXTBLOCK   //!< �K�w�\���u���b�N
   };
   /**
    * \brief    �������z�֐���
    * \return 0 �h����Œ�`
    */
   virtual OBJECTTYPE GetObjType() = 0;
   /**
    * \brief �������֐�
    */
   virtual void Init();
   /**
    * \brief   �X�V�֐�
    * \param g �Q�[���̎Q��
    */
   virtual void Process(Game& g);
   /**
    * \brief   �`��֐�
    * \param g �Q�[���̎Q��
    */
   virtual void Draw(Game& g);
   /**
    * \brief   �����蔻����s���֐�
    * \param o �I�u�W�F�N�g�̎��
    */
   virtual bool IsHit(ObjectBase& o);
   /**
    * \brief   �I�u�W�F�N�g�̏����֐�
    * \param g �Q�[���̎Q��
    */
   virtual void Delete(Game& g) {};

   /**
    * \brief     X���W�̒l��Ԃ��֐�
    * \return _x X���W
    */
   int GetX() { return _x; }
   /**
    * \brief     Y���W�̒l��Ԃ��֐�
    * \return _y Y���W
    */
   int GetY() { return _y; }
   /**
    * \brief        �̗͂̒l��Ԃ��֐�
    * \return _life �̗�
    */
   int GetLife() { return _life; }
   /**
    * \brief             �����Q�[�W�̒l��Ԃ��֐�
    * \return _iai_gauge �����Q�[�W
    */
   int GetGauge() { return _iai_gauge; }
   /**
    * \brief       �����̒l��Ԃ��֐�
    * \return _spd ����
    */
   int GetSpd() { return _spd; }
   /**
    * \brief        �I�u�W�F�N�g�̃\�[�g���Ԃ̒l��Ԃ��֐�
    * \return _sort �I�u�W�F�N�g�̃\�[�g����
    */
   int GetSort() { return _sort; }
   /**
    * \brief          ���]�����Ԃ��֐�
    * \return _isflip ���]����
    */
   bool GetFlip() { return _isflip; }
   /**
    * \brief                                              �}�b�v�`�b�v�Ƃ̓����蔻��p�̒l��S�ĕԂ��֐�
    * \return {_x,_y,_gx,_gy,_hit_x,_hit_y,_hit_w,_hit_h} �}�b�v�`�b�v�Ƃ̓����蔻��p�e���W�֌W
    */
   HitBox GetHB() { return { _x,_y,_gx,_gy,_hit_x,_hit_y,_hit_w,_hit_h }; }
   /**
    * \brief            �x�N�g���ł̈ʒu�̒l��Ԃ��֐�
    * \return _position �x�N�g���ł̈ʒu
    */
   Vector2 GetPosition() { return _position; }
   /**
    * \brief   X���W�̒l��ݒ肷��֐�
    * \param x X���W
    */
   void SetX(int x) { _x = x; }
   /**
    * \brief   Y���W�̒l��ݒ肷��֐�
    * \param y Y���W
    */
   void SetY(int y) { _y = y; }
   /**
    * \brief    �����Q�[�W�̒l��ݒ肷��֐�
    * \param ig �����Q�[�W
    */
   void SetGauge(int ig) {_iai_gauge=ig; }
   /**
    * \brief   XY�̒l��ݒ肷��֐�
    * \param x X���W
    * \param y Y���W
    */
   void SetPosition(int x, int y) { _x = x; _y = y; }
   /**
    * \brief        ���]�����ݒ肷��֐�
    * \param isflip ���]����
    */
   void SetFlip(bool isflip) { _isflip = isflip; }
   /**
    * \brief             �{�X�C�x���gA�����ݒ肷��֐�
    * \param beventAflag �{�X�C�x���gA����
    */
   void SetBossEventA(bool beventaflag) { _bossevent_a_flag =beventaflag; }
   /**
    * \brief             �{�X�C�x���gB�����ݒ肷��֐�
    * \param beventBflag �{�X�C�x���gB����
    */
   void SetBossEventB(bool beventbflag) { _bossevent_b_flag =beventbflag; }

protected:
   int _grhandle;         //!< �摜�n���h��
   int _sort;             //!< �L�����`��\�[�g�p�ϐ�
   int _x;                //!< X���W�i��ʒu�j
   int _y;                //!< Y���W�i��ʒu�j
   int _gx;               //!< X���W��ʒu����`�掞�̍���
   int _gy;               //!< Y���W��ʒu����`�掞�̍���
   int _w;                //!< ����
   int _h;                //!< �c��
   int _life;             //!< �̗�
   int _spd;              //!< �ړ����x
   int _alpha;            //!< �����x
   int _iai_gauge;        //!< �����Q�[�W
   int _hit_x;            //!< �`��_���獶����W�܂ł�X���W����
   int _hit_y;            //!< �`��_���獶����W�܂ł�Y���W����
   int _hit_w;            //!< �����蔻��̉���
   int _hit_h;            //!< �����蔻��̏c��
   int _dx;               //!< �`�攻��pX���W
   int _dy;               //!< �`�攻��pY���W
   int _debug_alpha;      //!< �f�o�b�N�p��`�����x
   int _cnt;              //!< ����J�E���^
   int _action_cnt;       //!< �A�N�V�����o�ߎ��ԕۑ��ϐ�
   int _before_x;         //!< �O���X���W�ۑ��ϐ�
   int _before_y;         //!< �O���Y���W�ۑ��ϐ�
   bool _draw_flag;       //!< XY���W�����+���l�ȓ��Ȃ�Ε`�悷��t���O
   bool _isflip;          //!< ���]����
   bool _bossevent_a_flag;//!< �{�X�C�x���gA�t���O
   bool _bossevent_b_flag;//!< �{�X�C�x���gB�t���O
   bool _debug_fill;      //!< �f�o�b�O�p��`�h��Ԃ��t���O
   Vector2 _position;     //!< �ʒu�x�N�g��
   std::pair <int, int>_hit_judge;        //!< �����蔻��p�ϐ�
   std::pair <double, double>_drg;        //!< DrawRotaGraph�p�ϐ�
   std::tuple<int, int, int>_debug_color; //!< �f�o�b�N�p��`�J���[
   std::unordered_map<std::string, std::vector<int>> _grall; //!< �S�Ẳ摜�n���h���}�b�v
   std::unordered_map<std::string, int> _anime;              //!< �A�j���[�V�����}�b�v
   std::unordered_map<std::string, int> _se;                 //!< SE�}�b�v
   std::unordered_map<std::string, int> _vpal;               //!< �{�����[���}�b�v
};
