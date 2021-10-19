/*****************************************************************//**
 * \file   ObjectServer.h
 * \brief  オブジェクトサーバークラス
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include   <vector>
#include   "ObjectBase.h"
//二重インクルード防止
class Game;
/** オブジェクトサーバー */
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
   std::vector<ObjectBase*>   _vObject;// ObjectBaseを登録するリスト
   std::vector<ObjectBase*>   _vAdd;   // ソート順を指定するオブジェクトリスト
   std::vector<ObjectBase*>   _vDel;   // 削除するオブジェクトリスト
};
