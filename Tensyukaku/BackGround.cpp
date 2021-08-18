/*
** 背景
*/

#include "DxLib.h"
#include "BackGround.h"
#include "ResourceServer.h"
#include "Game.h"

BackGround::BackGround()
{
	_GrHandle = ResourceServer::LoadGraph("res/Map/Back.png");		// 背景画像をロードする
}

BackGround::~BackGround()
{
}

void	BackGround::Draw(Game& g)
{
	// カメラスクロール分から、背景の位置を算出する
    int x, y;
    for (y = 0; y < g.GetmapH()+1; y+=1520)
    {
        int pos_y = y  - g.GetcvY();
        // 画面内に画像範囲が入っているか確認（高速化用）
        if (0 <= pos_y < SCREEN_H)
        {
            for (x = 0; x < g.GetmapW()  + 1; x+=3840)
            {
                
                int pos_x = x- g.GetcvX();
                // 画面内に画像範囲が入っているか確認（高速化用）
                if (0 <= pos_x < SCREEN_W)
                {
                    DrawGraph(pos_x, pos_y, _GrHandle, FALSE);
                }
            }
        }
    }
}

