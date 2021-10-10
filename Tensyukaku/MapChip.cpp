/*****************************************************************//**
 * \file   MapChip.cpp
 * \brief  �}�b�v�`�b�v�N���X
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#define	_CRT_SECURE_NO_WARNINGS
#include <DxLib.h>
#include <string>
#include "MapChip.h"
#include "ResourceServer.h"
#include "Game.h"
#include "ObjectBase.h"
#include "picojson/picojson.h"

MapChip::MapChip(std::string filePath, std::string tiledFileName)
{
	// json�f�[�^����}�b�v�f�[�^�����[�h����
	TiledJsonLoad(filePath, tiledFileName + ".json");

	// �`�b�v�摜�����[�h
	_cgChip = new int[CHIPCOUNT];		// �}�b�v�`�b�v�摜
	ResourceServer::LoadDivGraph((filePath + _strChipFile).c_str(), CHIPCOUNT, CHIPCOUNT_W, CHIPCOUNT_H, CHIPSIZE_W, CHIPSIZE_H, _cgChip);

	// �X�N���[���l
	_scrX = 0;
	_scrY = 0;

}

MapChip::~MapChip()
{
	// �m�ۂ������������������
	delete[]	_cgChip;
	delete[]	_mapData;
}

// ������̃t�@�C�������[�h����
std::string MapChip::StringFileLoad(std::string strFileName)
{
	// �t�@�C�����J��
	FILE* fp;
	fp = fopen(strFileName.c_str(), "rb");
	if (fp == NULL)
	{
		// �t�@�C�����J���Ȃ������i�t�@�C�������Ⴄ�Ȃǁj
		return "";
	}
	// �t�@�C���̃T�C�Y���擾
	fseek(fp, 0, SEEK_END); int size = ftell(fp); fseek(fp, 0, SEEK_SET);
	// ���������m�ۂ���
	char* p;
	p = new char[size + 1];
	// �������Ƀf�[�^��ǂݍ���
	fread(p, 1, size, fp);
	// �t�@�C�������
	fclose(fp);
	p[size] = '\0';

	// �ǂݍ��񂾃f�[�^��string�ɂ���
	std::string s = (char*)p;

	// ���������������
	delete[] p;

	// string��Ԃ�
	return s;
}

// Tiled-json�f�[�^���[�h
int		MapChip::TiledJsonLoad(std::string filePath, std::string strFileName)
{
	// �t�@�C�����J����string���擾����
	std::string strJson = StringFileLoad(filePath + strFileName);
	if (strJson == "")
	{
		// �t�@�C�����J���Ȃ�����
		return 0;
	}

	// �ǂݍ���string��json�I�u�W�F�N�g������
	picojson::value json;
	picojson::parse(json, strJson);
	picojson::object jsRoot = json.get<picojson::object>();

	// �p�����[�^��json����擾
	MAPSIZE_W = (int)jsRoot["width"].get<double>();
	MAPSIZE_H = (int)jsRoot["height"].get<double>();

	// �^�C���Z�b�g�擾(1�̂ݑΉ�)
	picojson::array aTileSets = jsRoot["tilesets"].get<picojson::array>();
	picojson::object jsTile = aTileSets[0].get<picojson::object>();
	CHIPCOUNT = (int)jsTile["tilecount"].get<double>();
	CHIPCOUNT_W = (int)jsTile["columns"].get<double>();
	CHIPCOUNT_H = (CHIPCOUNT / CHIPCOUNT_W);		// �v�Z�ŏo��
	CHIPSIZE_W = (int)jsRoot["tilewidth"].get<double>();
	CHIPSIZE_H = (int)jsRoot["tileheight"].get<double>();
	_strChipFile = jsTile["image"].get<std::string>();

	// ���C���[���̎擾
	picojson::array aLayers = jsRoot["layers"].get<picojson::array>();
	// �}�b�v��"tilelayer"���C���[���𐔂���
	int layer;
	layer = 0;
	for (int i = 0; i < aLayers.size(); i++)
	{
		picojson::object jsLayer = aLayers[i].get<picojson::object>();		// ���C���[�I�u�W�F�N�g
		// ���C���[��ނ��utilelayer�v�̂��̂��J�E���g����
		if (jsLayer["type"].get<std::string>() == "tilelayer")
		{
			layer++;
		}
	}
	MAPSIZE_LAYER = layer;

	// ���C���[���f�[�^�̎擾
	_mapData = new int[(int)(MAPSIZE_LAYER * MAPSIZE_W * MAPSIZE_H)];
	layer = 0;
	for (int i = 0; i < aLayers.size(); i++)
	{
		picojson::object jsLayer = aLayers[i].get<picojson::object>();		// ���C���[�I�u�W�F�N�g
		// ���C���[��ނ��utilelayer�v�̂��̂��J�E���g����
		if (jsLayer["type"].get<std::string>() == "tilelayer")
		{
			picojson::array aData = jsLayer["data"].get<picojson::array>();			// �}�b�v�z��
			for (int y = 0; y < MAPSIZE_H; y++)
			{
				for (int x = 0; x < MAPSIZE_W; x++)
				{
					int layerstart = MAPSIZE_W * MAPSIZE_H * layer;
					int index = y * MAPSIZE_W + x;
					_mapData[layerstart + index] = (int)aData[index].get<double>();

				}
			}
			layer++;
		}
	}

	return 1;
}

void	MapChip::Process(Game& g)
{
	// �J�������}�b�v�f�[�^�𒴂��Ȃ��悤�ɂ���
	if (_scrX < 0) { _scrX = 0; }
	if (_scrX > MAPSIZE_W * CHIPSIZE_W - SCREEN_W) { _scrX = MAPSIZE_W * CHIPSIZE_W - SCREEN_W; }
	if (_scrY < 0) { _scrY = 0; }
	if (_scrY > MAPSIZE_H * CHIPSIZE_H - SCREEN_H) { _scrY = MAPSIZE_H * CHIPSIZE_H - SCREEN_H; }

}
void	MapChip::Draw(Game& g)
{
	int x, y, layer;
	for (layer = 0; layer < MAPSIZE_LAYER; layer++)
	{
		for (y = _scrY / CHIPSIZE_H; y <= (_scrY + SCREEN_H) / CHIPSIZE_H + 1; y++)
		{
			if (y < 0 || MAPSIZE_H <= y) { continue; }
			for (x =_scrX/CHIPSIZE_W; x <= (_scrX+SCREEN_W)/ CHIPSIZE_W+1; x++)
			{
				if (x < 0 || MAPSIZE_W <= x) { continue; }
				int layerstart = MAPSIZE_W * MAPSIZE_H * layer;
				int index = y * MAPSIZE_W + x;
				int pos_x = x * CHIPSIZE_W - _scrX;
				int pos_y = y * CHIPSIZE_H - _scrY;
				int chip_no = _mapData[layerstart + index];
				// .tmx��csv�`���́A������0�Ƃ��A�摜�̃`�b�v��[1]����n�܂�B
				// ���̂��߁A�S�̓I�ɐ��l��-1����B������-1�ƂȂ�̂ŁAif�����ǉ�
				chip_no--;
				if (chip_no >= 0)
				{
					DrawGraph(pos_x, pos_y, _cgChip[chip_no], TRUE);

					// �J���p�F���̃`�b�v�͓����蔻����s�����̂��H
					if (CheckHit(x, y) != 0)
					{
						
						//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);		// �������`��w��
						//DrawBox(pos_x, pos_y, pos_x + CHIPSIZE_W, pos_y + CHIPSIZE_H, GetColor(255, 0, 0), TRUE);	// �������̐Ԃœ����蔻��`��
						//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// �s�����`��w��
						
					}
				}
			}
		}
	}
}





// �}�b�v�`�b�v�Ƃ̓����蔻��
// �����F
//   x,y = �}�b�v�`�b�v�̈ʒu(x,y) �`�b�v�P��
// �ߒl�F
//   0 : �����蔻����s��Ȃ�
//   0�ȊO : �����蔻����s���i�`�b�v�ԍ���Ԃ��j
int MapChip::CheckHit(int x, int y)
{
	// �}�b�v�`�b�v�ʒu�̓}�b�v�f�[�^����͂ݏo�Ă��邩�H
	if (0 <= x && x < MAPSIZE_W && 0 <= y && y < MAPSIZE_H)
	{	// �݂͂łĂ��Ȃ�

		// �}�b�v�`�b�vID��0�ȊO�͓����蔻����s��
		// ���݁A���C���[�͍l������Ă��Ȃ�
		int chip_no = _mapData[y * MAPSIZE_W + x];

		// ������ID���ǂ������`�F�b�N
		int idtable[] =
		{
		27,28,29,30, 40,41,42,43, 53,54,55,56, 66,67,68,69,79,80,81,82, 92,93,94,95, 105,106,107,108, 118,119,120,121,131,132,133,134,144,145,146,147,157,158,159,160,161,
			
			-1		// �Ō�
		};
		int i = 0;
		while (idtable[i] != -1)
		{
			if (chip_no == idtable[i])
			{
				// ��������
				return chip_no;
			}
			i++;
		}
	}

	// �������Ă��Ȃ�
	return 0;
}


// �I�u�W�F�N�g�ƃ}�b�v�`�b�v�������������̔���A����ѓ��������ꍇ�̏���
// �����F
//   o = �I�u�W�F�N�g
//   mx = X�̈ړ�����(�}�C�i�X:0:�v���X)
//   my = Y�̈ړ�����(�}�C�i�X:0:�v���X)
// �ߒl�F
//   0 : �������ĂȂ�
//   1 : ��������
int MapChip::IsHit(ObjectBase& o, int mx, int my)
{
	int x, y;


	// �L������`���쐬����
	int l, t, r, b;		// ����(left,top) - �E��(right,bottom)
	auto HB = o.GetHB();
	l = HB._x + HB._hit_x;
	t = HB._y + HB._gy + HB._hit_y;
	r = HB._x + HB._hit_x + HB._hit_w;
	b = HB._y + HB._gy + HB._hit_y + HB._hit_h - 1;

	// �L�����̍�����W�`�E�����W�ɂ�����}�b�v�`�b�v�ƁA�����蔻����s��
	for (y = t / CHIPSIZE_H; y <= b / CHIPSIZE_H; y++)
	{
		for (x = l / CHIPSIZE_W; x <= r / CHIPSIZE_W; x++)
		{
			// (x,y)�́A�}�b�v�`�b�v�̍��W�i�`�b�v�P�ʁj
			// ���̈ʒu�̃`�b�v�͓����邩�H
			int chip_no = CheckHit(x, y);
			if (chip_no != 0)
			{	// ���̃`�b�v�Ɠ��������B
				// X,Y�̈ړ����������āA���̔��Ε����ɕ␳����z
				if (mx < 0)
				{	// ���ɓ����Ă����̂ŁA�E�ɕ␳
					o.SetX(x * CHIPSIZE_W + CHIPSIZE_W - (HB._hit_x));
				}
				if (mx > 0)
				{	// �E�ɓ����Ă����̂ŁA���ɕ␳
					o.SetX(x * CHIPSIZE_W  - (HB._hit_x + HB._hit_w));
				}
				if (my > 0)
				{	// ���ɓ����Ă����̂ŁA��ɕ␳
					o.SetY(y * CHIPSIZE_H - (HB._hit_y +HB._hit_h));
				}
				if (my < 0)
				{	// ��ɓ����Ă����̂ŁA���ɕ␳
					o.SetY(y * CHIPSIZE_H + CHIPSIZE_H - (HB._hit_y));
				}
				// ���������̂Ŗ߂�
				return 1;
			}
		}
	}

	// ������Ȃ�����
	return 0;
	
}
