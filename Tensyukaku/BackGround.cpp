/*
** �w�i
*/

#include "DxLib.h"
#include "BackGround.h"
#include "ResourceServer.h"

BackGround::BackGround()
{
	_GrHandle = ResourceServer::LoadGraph("res/BG.png");		// �w�i�摜�����[�h����
}

BackGround::~BackGround()
{
}

void	BackGround::Draw(Game& g)
{
	DrawGraph(0, 0, _GrHandle, FALSE);
}

