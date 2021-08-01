///*
//** �}�b�v�`�b�v
//*/
//
//#include "DxLib.h"
//#include "MapChip.h"
//#include "ResourceServer.h"
//#include "Game.h"
//#include "ObjectBase.h"
//using namespace Tsk;
//
//MapChips::MapChips()
//{
//	// �`�b�v�摜�����[�h
//	ResourceServer::LoadDivGraph("res/platformer_simpleA_sheet.png", CHIPCOUNT, CHIPCOUNT_W, CHIPCOUNT_H, CHIPSIZE_W, CHIPSIZE_H, _cgChip);
//
//	// �X�N���[���l
//	_scrX = 0;
//	_scrY = 0;
//
//}
//
//MapChips::~MapChips()
//{
//}
//
//void	MapChips::Process(Game& g)
//{
//	// �J�������}�b�v�f�[�^�𒴂��Ȃ��悤�ɂ���
//	if (_scrX < 0) { _scrX = 0; }
//	if (_scrX > MAPSIZE_W * CHIPSIZE_W - SCREEN_W) { _scrX = MAPSIZE_W * CHIPSIZE_W - SCREEN_W; }
//	if (_scrY < 0) { _scrY = 0; }
//	if (_scrY > MAPSIZE_H * CHIPSIZE_H - SCREEN_H) { _scrY = MAPSIZE_H * CHIPSIZE_H - SCREEN_H; }
//
//}
//
//
//void	MapChips::Draw()
//{
//	int x, y, layer;
//	for (layer = 0; layer < MAPSIZE_LAYER; layer++)
//	{
//		for (y = 0; y < MAPSIZE_H; y++)
//		{
//			for (x = 0; x < MAPSIZE_W; x++)
//			{
//				int layerstart = MAPSIZE_W * MAPSIZE_H * layer;
//				int index = y * MAPSIZE_W + x;
//				int pos_x = x * CHIPSIZE_W - _scrX;
//				int pos_y = y * CHIPSIZE_H - _scrY;
//				int chip_no = _mapData[layerstart + index];
//				// .tmx��csv�`���́A������0�Ƃ��A�摜�̃`�b�v��[1]����n�܂�B
//				// ���̂��߁A�S�̓I�ɐ��l��-1����B������-1�ƂȂ�̂ŁAif�����ǉ�
//				chip_no--;
//				if (chip_no >= 0)
//				{
//					DrawGraph(pos_x, pos_y, _cgChip[chip_no], TRUE);
//
//					// �J���p�F���̃`�b�v�͓����蔻����s�����̂��H
//					if (CheckHit(x, y) != 0)
//					{
//						/*
//						SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// �������`��w��
//						DrawBox(pos_x, pos_y, pos_x + CHIPSIZE_W, pos_y + CHIPSIZE_H, GetColor(255, 0, 0), TRUE);	// �������̐Ԃœ����蔻��`��
//						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// �s�����`��w��
//						*/
//					}
//				}
//			}
//		}
//	}
//}
//
//
//
//
//
//// �}�b�v�`�b�v�Ƃ̓����蔻��
//// �����F
////   x,y = �}�b�v�`�b�v�̈ʒu(x,y) �`�b�v�P��
//// �ߒl�F
////   0 : �����蔻����s��Ȃ�
////   0�ȊO : �����蔻����s���i�`�b�v�ԍ���Ԃ��j
//int MapChips::CheckHit(int x, int y)
//{
//	// �}�b�v�`�b�v�ʒu�̓}�b�v�f�[�^����͂ݏo�Ă��邩�H
//	if (0 <= x && x < MAPSIZE_W && 0 <= y && y < MAPSIZE_H)
//	{	// �݂͂łĂ��Ȃ�
//
//		// �}�b�v�`�b�vID��0�ȊO�͓����蔻����s��
//		// ���݁A���C���[�͍l������Ă��Ȃ�
//		int chip_no = _mapData[y * MAPSIZE_W + x];
//
//		// ������ID���ǂ������`�F�b�N
//		int idtable[] =
//		{
//			2, 3, 4, 7, 8,
//			9, 10, 11, 12, 13, 14, 15, 16,
//			20, 21, 22,
//			-1		// �Ō�
//		};
//		int i = 0;
//		while (idtable[i] != -1)
//		{
//			if (chip_no == idtable[i])
//			{
//				// ��������
//				return chip_no;
//			}
//			i++;
//		}
//	}
//
//	// �������Ă��Ȃ�
//	return 0;
//}
//
//
//// �I�u�W�F�N�g�ƃ}�b�v�`�b�v�������������̔���A����ѓ��������ꍇ�̏���
//// �����F
////   o = �I�u�W�F�N�g
////   mx = X�̈ړ�����(�}�C�i�X:0:�v���X)
////   my = Y�̈ړ�����(�}�C�i�X:0:�v���X)
//// �ߒl�F
////   0 : �������ĂȂ�
////   1 : ��������
//int MapChips::IsHit(ObjectBase& o, int mx, int my)
//{
//	int x, y;
//
//	// �L������`���쐬����
//	int l, t, r, b;		// ����(left,top) - �E��(right,bottom)
//	auto HB = o.GetHB();
//	l = HB._x + HB._hit_x;
//	t = HB._y + HB._hit_y;
//	r = HB._x + HB._hit_x + HB._hit_w - 1;
//	b = HB._y + HB._hit_y + HB._hit_h - 1;
//
//	// �L�����̍�����W�`�E�����W�ɂ�����}�b�v�`�b�v�ƁA�����蔻����s��
//	for (y = t / CHIPSIZE_H; y <= b / CHIPSIZE_H; y++)
//	{
//		for (x = l / CHIPSIZE_W; x <= r / CHIPSIZE_W; x++)
//		{
//			// (x,y)�́A�}�b�v�`�b�v�̍��W�i�`�b�v�P�ʁj
//			// ���̈ʒu�̃`�b�v�͓����邩�H
//			int chip_no = CheckHit(x, y);
//			if (chip_no != 0)
//			{	// ���̃`�b�v�Ɠ��������B
//				// X,Y�̈ړ����������āA���̔��Ε����ɕ␳����
//				if (mx < 0)
//				{	// ���ɓ����Ă����̂ŁA�E�ɕ␳
//					o.SetX(x * CHIPSIZE_W + CHIPSIZE_W - (HB._hit_x));
//				}
//				if (mx > 0)
//				{	// �E�ɓ����Ă����̂ŁA���ɕ␳
//					o.SetX(x * CHIPSIZE_W - (HB._hit_x + HB._hit_w));
//				}
//				if (my > 0)
//				{	// ���ɓ����Ă����̂ŁA��ɕ␳
//					o.SetY(y * CHIPSIZE_H - (HB._hit_y + HB._hit_h));
//				}
//				if (my < 0)
//				{	// ��ɓ����Ă����̂ŁA���ɕ␳
//					o.SetY(y * CHIPSIZE_H + CHIPSIZE_H - (HB._hit_y));
//				}
//				// ���������̂Ŗ߂�
//				return 1;
//			}
//		}
//	}
//
//	// ������Ȃ�����
//	return 0;
//}
//
