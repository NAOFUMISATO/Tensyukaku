/*****************************************************************//**
 * \file   BackGround.cpp
 * \brief  �w�i�N���X
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include "DxLib.h"
#include "BackGround.h"
#include "ResourceServer.h"
#include "Game.h"

BackGround::BackGround()
{
   _GrHandle = ResourceServer::LoadGraph("res/Map/Back.png");   
}

BackGround::~BackGround()
{
}

void   BackGround::Draw(Game& g)
{
   // �J�����X�N���[��������A�w�i�̈ʒu���Z�o����
    int x, y;
    for (y = 0; y < g.GetmapH()+1; y+=9440)
    {
        int pos_y = y  - g.GetcvY();
        // ��ʓ��ɉ摜�͈͂������Ă��邩�m�F�i�������p�j
        if (0 <= pos_y ||pos_y< SCREEN_H)
        {
            for (x = 0; x < g.GetmapW()  + 1; x+=5760)
            {
                
                int pos_x = x- g.GetcvX();
                // ��ʓ��ɉ摜�͈͂������Ă��邩�m�F�i�������p�j
                if (0 <= pos_x || pos_x < SCREEN_W)
                {
                    DrawGraph(pos_x, pos_y, _GrHandle, TRUE);
                }
            }
        }
    }
}

