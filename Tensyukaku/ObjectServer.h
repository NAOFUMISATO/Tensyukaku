/*****************************************************************//**
 * \file   ObjectServer.h
 * \brief  �I�u�W�F�N�g�T�[�o�[�N���X
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include   <vector>
#include   "ObjectBase.h"
//��d�C���N���[�h�h�~
class Game;
/** �I�u�W�F�N�g�T�[�o�[ */
class ObjectServer {
public:
   ObjectServer();
   ~ObjectServer();
   void   Clear();
   void   Add(ObjectBase* obj);
   void   Del(ObjectBase* obj);
   void   Process(Game& g);
   void   Draw(Game& g);
   std::vector<ObjectBase*> *List() { return &_vObject; }

private:
   void   AddListObjects();
   void   DelListObjects();

protected:
   std::vector<ObjectBase*>   _vObject;// ObjectBase��o�^���郊�X�g
   std::vector<ObjectBase*>   _vAdd;   // �\�[�g�����w�肷��I�u�W�F�N�g���X�g
   std::vector<ObjectBase*>   _vDel;   // �폜����I�u�W�F�N�g���X�g
};
