/*
** �w�i
*/

#include "DxLib.h"
#include "BackGround.h"
#include "ResourceServer.h"
using namespace Tsk;
BackGround::BackGround()
{
	_GrHandle = ResourceServer::LoadGraph("res/platformer_BG.png");		// �w�i�摜�����[�h����
}

BackGround::~BackGround()
{
}

void	BackGround::Draw(Game& g)
{
	DrawGraph(0, 0, _GrHandle, FALSE);
}

