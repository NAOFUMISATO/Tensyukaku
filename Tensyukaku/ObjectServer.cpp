/*
** �I�u�W�F�N�g�T�[�o
*/

#include "DxLib.h"
#include "ObjectServer.h"
#include "Game.h"
#include <algorithm>

ObjectServer::ObjectServer()
{
   _vObject.clear();
   _vAdd.clear();
   _vDel.clear();
}

ObjectServer::~ObjectServer()
{
   Clear();
}

// ���X�g�ɓo�^����Ă���I�u�W�F�N�g�����ׂď���
void   ObjectServer::Clear()
{
   for (auto ite = _vObject.begin(); ite != _vObject.end(); ite++)
   {
      delete (*ite);
   }
   _vObject.clear();
}

// Add���X�g�ɃI�u�W�F�N�g��o�^����
void   ObjectServer::Add(ObjectBase* obj)
{
   _vAdd.push_back(obj);
}

// Del���X�g�ɃI�u�W�F�N�g��o�^����
void   ObjectServer::Del(ObjectBase* obj)
{
   _vDel.push_back(obj);
}

// Add���X�g�̃I�u�W�F�N�g��ǉ�����
void   ObjectServer::AddListObjects()
{

   for (auto iteAdd = _vAdd.begin(); iteAdd != _vAdd.end(); iteAdd++)
   {
      auto sort = (*iteAdd)->GetSort();
      auto ret = std::find_if(_vObject.begin(), _vObject.end(),
         [sort](auto&& obj) { return obj->GetSort()>sort; });
      if (ret == _vObject.end()) {
         _vObject.push_back((*iteAdd));
      }
      else {
         _vObject.insert(ret, (*iteAdd));
      }
   }
   _vAdd.clear();
}

// Del���X�g�̃I�u�W�F�N�g���폜����
void   ObjectServer::DelListObjects()
{
   for (auto iteDel = _vDel.begin(); iteDel != _vDel.end(); iteDel++)
   {
      for (auto ite = _vObject.begin(); ite != _vObject.end();)
      {
         if ((*ite) == (*iteDel))
         {
            delete (*ite);
            ite = _vObject.erase(ite);
         }
         else
         {
            ite++;
         }
      }
   }
   _vDel.clear();
}


// Process()��o�^���ɉ�
void   ObjectServer::Process(Game& g)
{
   // Add���X�g�ɂ���I�u�W�F�N�g�����X�g�ɓo�^����
   AddListObjects();

   // Process()�̌Ăяo��
   for (auto ite = _vObject.begin(); ite != _vObject.end(); ite++)
   {
      (*ite)->Process(g);
   }

   // Del���X�g�ɂ���I�u�W�F�N�g�����X�g����폜����
   DelListObjects();
}

// Draw()��o�^���ɉ�
void   ObjectServer::Draw(Game& g)
{
   for (auto ite = _vObject.begin(); ite != _vObject.end(); ite++)
   {
      (*ite)->Draw(g);
   }
}
