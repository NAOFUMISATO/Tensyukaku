#pragma once
#include "ObjectBase.h"
#include <tuple>
#include <utility>
class Game;
class ParticleBase :public ObjectBase {
public:
	ParticleBase();
	~ParticleBase();
	virtual OBJECTTYPE GetObjType() { return OBJECTTYPE::PARTICLE; }

	enum class PARTICLETYPE {
		LOWATTACK1, LOWATTACK2,MIDDLEATTACK1,MIDDLEATTACK2,IAI1,IAI2,IAI3
	};
	virtual PARTICLETYPE GetParType() = 0;
	virtual void Init();
	virtual void Process(Game& g);
	virtual void Draw(Game& g);
protected:
	std::pair<double, double> _xy;
	std::pair<double, double> _dxy;
	std::pair<double, double> _mxy;
	int	_pal;
	int _bm;
	std::tuple<int, int, int> _rgb;
	std::pair<double, double> _drg;
};

namespace ParInfo {
	/*----------���i�U��1----------*/
	constexpr auto MiddleAttackPar1_Graph = "res/Particle/MiddleAttack.png";	//�摜�t�@�C����
	constexpr auto MiddleAttackPar1_PozX = 0.0;									//��_(����)����`��_�ւ�X���W����
	constexpr auto MiddleAttackPar1_PozY = -150.0;								//��_(����)����`��_�ւ�X���W����
	constexpr auto MiddleAttackPar1_BLENDMODE = DX_BLENDMODE_SUB;				//�u�����h���[�h�ݒ�
	constexpr auto MiddleAttackPar1_Pal = 64;									//�u�����h�l(0�`255)
	constexpr auto MiddleAttackPar1_Red = 128;									//�ԐF�l(0�`255)
	constexpr auto MiddleAttackPar1_Green = 128;								//�ΐF�l(0�`255)
	constexpr auto MiddleAttackPar1_Blue = 128;									//�F�l(0�`255)
	constexpr auto MiddleAttackPar1_Scale = 1.0;								//�g�k�l(1.0���f�t�H���g)
	constexpr auto MiddleAttackPar1_Angle = 0.0;								//�`��p�x(3.14=180��)
	constexpr auto MiddleAttackPar1_Cnt = 20;									//�p�[�e�B�N��1������̐�������
	constexpr auto MiddleAttackPar1_qty = 5;									//1�t���[��������̃p�[�e�B�N����
	//�p�[�e�B�N��1������̈ړ������̃����_���l����
	constexpr auto MAP1_Xrand1 = 20;											//�p�[�e�B�N����X�����_���l
	constexpr auto MAP1_Xrand2 = 10.0;											//		�V
	constexpr auto MAP1_Xrand3 = 8.0;											//		�V
	constexpr auto MAP1_Yrand1 = 20;											//�p�[�e�B�N����Y�����_���l
	constexpr auto MAP1_Yrand2 = 10.0;											//		�V
	constexpr auto MAP1_Yrand3 = 8.0;											//		�V

	/*----------���i�U��2----------*/
	constexpr auto MiddleAttackPar2_Graph = "res/Particle/MiddleAttacksub.png";	//�摜�t�@�C����
	constexpr auto MiddleAttackPar2_PozX = 0.0;									//��_(����)����`��_�ւ�X���W����
	constexpr auto MiddleAttackPar2_PozY = -150.0;								//��_(����)����`��_�ւ�X���W����
	constexpr auto MiddleAttackPar2_BLENDMODE = DX_BLENDMODE_SUB;				//�u�����h���[�h�ݒ�
	constexpr auto MiddleAttackPar2_Pal = 128;									//�u�����h�l(0�`255)
	constexpr auto MiddleAttackPar2_Red = 200;									//�ԐF�l(0�`255)
	constexpr auto MiddleAttackPar2_Green = 200;								//�ΐF�l(0�`255)
	constexpr auto MiddleAttackPar2_Blue = 200;									//�F�l(0�`255)
	constexpr auto MiddleAttackPar2_Scale = 1.0;								//�g�k�l(1.0���f�t�H���g)
	constexpr auto MiddleAttackPar2_Angle = 0.0;								//�`��p�x(3.14=180��)
	constexpr auto MiddleAttackPar2_Cnt = 20;									//�p�[�e�B�N��1������̐�������
	constexpr auto MiddleAttackPar2_qty = 5;									//1�t���[��������̃p�[�e�B�N����
	//�p�[�e�B�N��1������̈ړ������̃����_���l����
	constexpr auto MAP2_Xrand1 = 20;											//�p�[�e�B�N����X�����_���l
	constexpr auto MAP2_Xrand2 = 5.0;											//		�V
	constexpr auto MAP2_Xrand3 = 2.0;											//		�V
	constexpr auto MAP2_Yrand1 = 20;											//�p�[�e�B�N����Y�����_���l
	constexpr auto MAP2_Yrand2 = 5.0;											//		�V
	constexpr auto MAP2_Yrand3 = 2.0;											//		�V

	/*----------���i�U��1----------*/
	constexpr auto LowAttackPar1_Graph = "res/Particle/LowAttack.png";			//�摜�t�@�C����
	constexpr auto LowAttackPar1_PozX = 0.0;									//��_(����)����`��_�ւ�X���W����
	constexpr auto LowAttackPar1_PozY = -150.0;									//��_(����)����`��_�ւ�X���W����
	constexpr auto LowAttackPar1_BLENDMODE = DX_BLENDMODE_SUB;					//�u�����h���[�h�ݒ�
	constexpr auto LowAttackPar1_Pal = 64;										//�u�����h�l(0�`255)
	constexpr auto LowAttackPar1_Red = 128;										//�ԐF�l(0�`255)
	constexpr auto LowAttackPar1_Green = 128;									//�ΐF�l(0�`255)
	constexpr auto LowAttackPar1_Blue = 128;									//�F�l(0�`255)
	constexpr auto LowAttackPar1_Scale = 1.0;									//�g�k�l(1.0���f�t�H���g)
	constexpr auto LowAttackPar1_Angle = 0.0;									//�`��p�x(3.14=180��)
	constexpr auto LowAttackPar1_Cnt = 20;										//�p�[�e�B�N��1������̐�������
	constexpr auto LowAttackPar1_qty = 5;										//1�t���[��������̃p�[�e�B�N����
	//�p�[�e�B�N��1������̈ړ������̃����_���l����
	constexpr auto LAP1_Xrand1 = 20;											//�p�[�e�B�N����X�����_���l
	constexpr auto LAP1_Xrand2 = 10.0;											//		�V
	constexpr auto LAP1_Xrand3 = 8.0;											//		�V
	constexpr auto LAP1_Yrand1 = 20;											//�p�[�e�B�N����Y�����_���l
	constexpr auto LAP1_Yrand2 = 10.0;											//		�V
	constexpr auto LAP1_Yrand3 = 8.0;											//		�V

	/*----------���i�U��2----------*/
	constexpr auto LowAttackPar2_Graph = "res/Particle/LowAttacksub.png";		//�摜�t�@�C����
	constexpr auto LowAttackPar2_PozX = 0.0;									//��_(����)����`��_�ւ�X���W����
	constexpr auto LowAttackPar2_PozY = -150.0;									//��_(����)����`��_�ւ�X���W����
	constexpr auto LowAttackPar2_BLENDMODE = DX_BLENDMODE_SUB;					//�u�����h���[�h�ݒ�
	constexpr auto LowAttackPar2_Pal = 128;										//�u�����h�l(0�`255)
	constexpr auto LowAttackPar2_Red = 200;										//�ԐF�l(0�`255)
	constexpr auto LowAttackPar2_Green = 200;									//�ΐF�l(0�`255)
	constexpr auto LowAttackPar2_Blue = 200;									//�F�l(0�`255)
	constexpr auto LowAttackPar2_Scale = 1.0;									//�g�k�l(1.0���f�t�H���g)
	constexpr auto LowAttackPar2_Angle = 0.0;									//�`��p�x(3.14=180��)
	constexpr auto LowAttackPar2_Cnt = 20;										//�p�[�e�B�N��1������̐�������
	constexpr auto LowAttackPar2_qty = 5;										//1�t���[��������̃p�[�e�B�N����
	//�p�[�e�B�N��1������̈ړ������̃����_���l����
	constexpr auto LAP2_Xrand1 = 20;											//�p�[�e�B�N����X�����_���l
	constexpr auto LAP2_Xrand2 = 5.0;											//		�V
	constexpr auto LAP2_Xrand3 = 2.0;											//		�V
	constexpr auto LAP2_Yrand1 = 20;											//�p�[�e�B�N����Y�����_���l
	constexpr auto LAP2_Yrand2 = 5.0;											//		�V
	constexpr auto LAP2_Yrand3 = 2.0;											//		�V

	/*----------����1----------*/
	constexpr auto IaiPar1_Graph = "res/Particle/Iai1.png";						//�摜�t�@�C����
	constexpr auto IaiPar1_PozX = 0.0;											//��_(����)����`��_�ւ�X���W����
	constexpr auto IaiPar1_PozY = -150.0;										//��_(����)����`��_�ւ�X���W����
	constexpr auto IaiPar1_BLENDMODE = DX_BLENDMODE_ADD;						//�u�����h���[�h�ݒ�
	constexpr auto IaiPar1_Pal = 128;											//�u�����h�l(0�`255)
	constexpr auto IaiPar1_Red = 80;											//�ԐF�l(0�`255)
	constexpr auto IaiPar1_Green = 80;											//�ΐF�l(0�`255)
	constexpr auto IaiPar1_Blue =60;											//�F�l(0�`255)
	constexpr auto IaiPar1_Scale = 0.8;											//�g�k�l(1.0���f�t�H���g)
	constexpr auto IaiPar1_Angle = 0.0;											//�`��p�x(3.14=180��)
	constexpr auto IaiPar1_Cnt = 20;											//�p�[�e�B�N��1������̐�������
	constexpr auto Iai1_qty = 5;												//1�t���[��������̃p�[�e�B�N����
	//�p�[�e�B�N��1������̈ړ������̃����_���l����
	constexpr auto IAI1_Xrand1 = 20;											//�p�[�e�B�N����X�����_���l
	constexpr auto IAI1_Xrand2 = 10.0;											//		�V
	constexpr auto IAI1_Xrand3 = 8.0;											//		�V
	constexpr auto IAI1_Yrand1 = 20;											//�p�[�e�B�N����Y�����_���l
	constexpr auto IAI1_Yrand2 = 10.0;											//		�V
	constexpr auto IAI1_Yrand3 = 8.0;											//		�V

	/*----------����2----------*/
	constexpr auto IaiPar2_Graph = "res/Particle/Iai2.png";						//�摜�t�@�C����
	constexpr auto IaiPar2_PozX = 0.0;											//��_(����)����`��_�ւ�X���W����
	constexpr auto IaiPar2_PozY = -150.0;										//��_(����)����`��_�ւ�X���W����
	constexpr auto IaiPar2_BLENDMODE = DX_BLENDMODE_SUB;						//�u�����h���[�h�ݒ�
	constexpr auto IaiPar2_Pal = 128;											//�u�����h�l(0�`255)
	constexpr auto IaiPar2_Red = 64;											//�ԐF�l(0�`255)
	constexpr auto IaiPar2_Green = 200;											//�ΐF�l(0�`255)
	constexpr auto IaiPar2_Blue = 64;											//�F�l(0�`255)
	constexpr auto IaiPar2_Scale = 1.0;											//�g�k�l(1.0���f�t�H���g)
	constexpr auto IaiPar2_Angle = 0.0;											//�`��p�x(3.14=180��)
	constexpr auto IaiPar2_Cnt = 20;											//�p�[�e�B�N��1������̐�������
	constexpr auto Iai2_qty = 5;												//1�t���[��������̃p�[�e�B�N����
	//�p�[�e�B�N��1������̈ړ������̃����_���l����
	constexpr auto IAI2_Xrand1 = 20;											//�p�[�e�B�N����X�����_���l
	constexpr auto IAI2_Xrand2 = 10.0;											//		�V
	constexpr auto IAI2_Xrand3 = 8.0;											//		�V
	constexpr auto IAI2_Yrand1 = 20;											//�p�[�e�B�N����Y�����_���l
	constexpr auto IAI2_Yrand2 = 10.0;											//		�V
	constexpr auto IAI2_Yrand3 = 8.0;											//		�V

	/*----------����3----------*/
	constexpr auto IaiPar3_Graph = "res/Particle/Iai3.png";						//�摜�t�@�C����
	constexpr auto IaiPar3_PozX = 0.0;											//��_(����)����`��_�ւ�X���W����
	constexpr auto IaiPar3_PozY = -150.0;										//��_(����)����`��_�ւ�X���W����
	constexpr auto IaiPar3_BLENDMODE = DX_BLENDMODE_SUB;						//�u�����h���[�h�ݒ�
	constexpr auto IaiPar3_Pal = 128;											//�u�����h�l(0�`255)
	constexpr auto IaiPar3_Red = 200;											//�ԐF�l(0�`255)
	constexpr auto IaiPar3_Green = 200;											//�ΐF�l(0�`255)
	constexpr auto IaiPar3_Blue = 200;											//�F�l(0�`255)
	constexpr auto IaiPar3_Scale = 1.0;											//�g�k�l(1.0���f�t�H���g)
	constexpr auto IaiPar3_Angle = 0.0;											//�`��p�x(3.14=180��)
	constexpr auto IaiPar3_Cnt = 20;											//�p�[�e�B�N��1������̐�������
	constexpr auto Iai3_qty = 5;												//1�t���[��������̃p�[�e�B�N����
	//�p�[�e�B�N��1������̈ړ������̃����_���l����
	constexpr auto IAI3_Xrand1 = 20;											//�p�[�e�B�N����X�����_���l
	constexpr auto IAI3_Xrand2 = 5.0;											//		�V
	constexpr auto IAI3_Xrand3 = 2.0;											//		�V
	constexpr auto IAI3_Yrand1 = 20;											//�p�[�e�B�N����Y�����_���l
	constexpr auto IAI3_Yrand2 = 5.0;											//		�V
	constexpr auto IAI3_Yrand3 = 2.0;											//		�V
	
	/*----------Tuple�^�ǐ�����---------*/
	constexpr auto Red = 0;
	constexpr auto Green = 1;
	constexpr auto Blue = 2;
	constexpr auto Scale = 0;
	constexpr auto Angle = 1;
	constexpr auto Flip = 2;
}