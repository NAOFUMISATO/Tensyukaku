/*****************************************************************//**
 * \file   BackGround.h
 * \brief  �C���Q�[���ł̔w�i�N���X
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
//��d�C���N���[�h�h�~
class Game;
class BackGround {
public:
   BackGround();
   ~BackGround();

   void Draw(Game& g);

private:
   int _grhandle; //!< �摜�n���h��
};