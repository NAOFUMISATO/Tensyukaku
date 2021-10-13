#pragma once
/*
   �e�I�u�W�F�N�g�̊��N���X
*/
#include "HitBox.h"
#include <vector>
#include "Math.h"
#include <utility>
#include <tuple>
#include <unordered_map>
class Game;
class ObjectBase {
public:
   ObjectBase();
   ~ObjectBase();
   //�I�u�W�F�N�g�̎�ޗ�
   enum class OBJECTTYPE {
      TITLELOGO,GAMESTART, EXPLAIN,GAMEEND,CREDIT, CURSOR,                                                                                                //�Q�[���^�C�g��
      PLAYER, ENEMY,BOSS,                                                                                                                                                         //�L����
      UI, PARTICLE,EFECT,                                                                                                                                                         //UI&�G�t�F�N�g
      MIDDLEATTACK, LOWATTACK, KICK, IAI,SPECIAL,                                                                                                                     //�v���C���[�̍U��
      PRIVATECOLLISION,BUSHIATTACK,NINJAATTACK,KUNAI,SHIELDERATTACK,SHIELD, LANCERATTACK,BUSYOATTACK,ZYOUNINATTACK,      //�G�̍U��&���G�͈͓�
      STAIR,BOSSSTAIR, RESTPOINT,POISONNINJA,POISON,ANDON,FLAME, MUGENANDON,MUGENFLAME, TUTORIALBOARD,                     //�M�~�b�N
      RECOVERYBLOCK,CPOINTBLOCK,BOSSEVENTBLOCK,FLAMEBLOCK, SPAWNBLOCK, EVENTBLOCK,                                                    //�e�M�~�b�N�p�����蔻��
   };
   //�������z�֐�
   virtual OBJECTTYPE   GetObjType() = 0;
   //������
   virtual   void      Init();
   //�X�V
   virtual   void      Process(Game& g);
   //�`��
   virtual   void      Draw(Game& g);
   //�����蔻����s���֐�
   virtual   bool   IsHit(ObjectBase& o);
   //�I�u�W�F�N�g�̏���
   virtual   void      Delete(Game& g) {};

   //X�̒l��Ԃ��֐�
   int   GetX() { return _x; }
   //Y�̒l��Ԃ��֐�
   int   GetY() { return _y; }
   //�̗͂̒l��Ԃ��֐�
   int   GetHp() { return _life; }
   //�Q�[�W�̒l��Ԃ��֐�
   int   GetGauge() { return _iai_gauge; }
   //�����̒l��Ԃ��֐�
   int   GetSpd() { return _spd; }
   //�I�u�W�F�N�g���Ƃ̃\�[�g���Ԃ�Ԃ��֐�
   int   GetSort() { return _sort; }
   //���]�����Ԃ��֐�
   bool   GetFlip() { return _isflip; }
   //�����蔻��p�̒l��Ԃ��֐�
   HitBox   GetHB() { return { _x,_y,_gx,_gy,_hit_x,_hit_y,_hit_w,_hit_h }; }
   //�x�N�g���̒l��Ԃ��֐�
   Vector2   GetPosition() { return _position; }
   //X�̒l��ݒ肷��֐�
   void      SetX(int x) { _x = x; }
   //Y�̒l��ݒ肷��֐�
   void      SetY(int y) { _y = y; }
   //�Q�[�W�̒l��ݒ肷��֐�
   void      SetGauge(int ig) {_iai_gauge=ig; }
   //XY�̒l��ݒ肷��֐�
   void      SetPosition(int x, int y) { _x = x; _y = y; }
   //���]�����ݒ肷��֐�
   void      SetFlip(bool isflip) { _isflip = isflip; }
   //�{�X�C�x���gA�����ݒ肷��֐�
   void      SetBEventA(bool beventAflag) { _bosseventA_flag =beventAflag; }
   //�{�X�C�x���gB�����ݒ肷��֐�
   void      SetBEventB(bool beventBflag) { _bosseventB_flag =beventBflag; }
   
   
protected:
   int      _grhandle;                                 // �摜�n���h��
   int      _sort;                                       //�L�����`��\�[�g�p�ϐ�
   int      _x, _y;                                       // ���W�i��ʒu�j
   int      _gx, _gy;                                    // ��ʒu����`�掞�̍���
   int      _w, _h;                                       // �傫��
   int      _life;                                       // �̗�
   int      _spd;                                       // �ړ����x
   int      _alpha;                                    // �����x
   int      _iai_gauge;                              // �����Q�[�W
   int      _hit_x, _hit_y;                              //�`��_���獶����W�܂ł̍���
   int      _hit_w, _hit_h;                           //�����蔻��̕�
   int      _dx;                                          //�`�攻��p�ϐ�
   int      _dy;                                          //�`�攻��p�ϐ�
   int      _debug_alpha;                           //�f�o�b�N�p��`�����x
   int      _cnt;                                       //����J�E���^
   int      _action_cnt;                              //�A�N�V�����o�ߎ��ԕۑ��ϐ�
   int      _before_x;                                 //�O���X���W�ۑ��ϐ�
   int      _before_y;                                 //�O���Y���W�ۑ��ϐ�
   bool   _draw_flag;                              //XY���W�����+���l�ȓ��Ȃ�Ε`�悷��t���O
   bool   _isflip;                                       // ���]����
   bool   _bosseventA_flag;                     //�{�X�C�x���gA�t���O
   bool   _bosseventB_flag;                     //�{�X�C�x���gB�t���O
   bool   _debug_fill;                              //�f�o�b�O�p��`�h��Ԃ��t���O
   Vector2 _position;                              // �ʒu�x�N�g��
   std::pair <int, int>_hit_judge;                  //�����蔻��p�ϐ�
   std::pair <double, double>_drg;            //DrawRotaGraph�p�ϐ�
   std::tuple<int, int, int>_debug_color;      //�f�o�b�N�p��`�J���[
   std::unordered_map<std::string, std::vector<int>> _grall;   //�S�Ẳ摜�n���h���}�b�v
   std::unordered_map<std::string, int> _anime;                  //�A�j���[�V�����}�b�v
   std::unordered_map<std::string, int> _se;                        //SE�}�b�v
   std::unordered_map<std::string, int> _vpal;                     //�{�����[���}�b�v
};
