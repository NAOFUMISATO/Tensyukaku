/*****************************************************************//**
 * \file   BackGround.h
 * \brief  インゲームでの背景クラス
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
//二重インクルード防止
class Game;
class BackGround {
public:
   BackGround();
   ~BackGround();

   void Draw(Game& g);

private:
   int _grhandle; //!< 画像ハンドル
};