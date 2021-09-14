#pragma once
#include "ParticleBase.h"
#include <tuple>
#include <utility>
//���i�U��1
class MiddleAttackParticle1 : public ParticleBase {
public:
	MiddleAttackParticle1(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~MiddleAttackParticle1();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::MIDDLEATTACK1; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
//���i�U��2
class MiddleAttackParticle2 : public ParticleBase {
public:
	MiddleAttackParticle2(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~MiddleAttackParticle2();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::MIDDLEATTACK2; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
//���i�U��1
class LowAttackParticle1 : public ParticleBase {
public:
	LowAttackParticle1(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~LowAttackParticle1();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::LOWATTACK1; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
//���i�U��2
class LowAttackParticle2 : public ParticleBase {
public:
	LowAttackParticle2(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~LowAttackParticle2();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::LOWATTACK2; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
//����1
class IaiParticle1 : public ParticleBase {
public:
	IaiParticle1(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~IaiParticle1();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::IAI1; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
//����2
class IaiParticle2 : public ParticleBase {
public:
	IaiParticle2(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~IaiParticle2();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::IAI2; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
//����3
class IaiParticle3 : public ParticleBase {
public:
	IaiParticle3(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~IaiParticle3();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::IAI3; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
//�����Q�[�W
class IaiGaugeParticle : public ParticleBase {
public:
	IaiGaugeParticle(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~IaiGaugeParticle();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::IAIGAUGE; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};

namespace PParInfo {
	/*----------���i�U��1----------*/
	constexpr auto MIDDLEATTACK_PARTICLE1_GRAPH = "res/Particle/MiddleAttack.png";		//�摜�t�@�C����
	constexpr auto MIDDLEATTACK_PARTICLE1_POSITIONX = 0.0;								//��_(����)����`��_�ւ�X���W����
	constexpr auto MIDDLEATTACK_PARTICLE1_POSITIONY = -325.0;							//��_(����)����`��_�ւ�Y���W����
	constexpr auto MIDDLEATTACK_PARTICLE1_BLENDMODE = DX_BLENDMODE_SUB;					//�u�����h���[�h�ݒ�
	constexpr auto MIDDLEATTACK_PARTICLE1_PAL = 64;										//�u�����h�l(0�`255)
	constexpr auto MIDDLEATTACK_PARTICLE1_RED = 128;									//�ԐF�l(0�`255)
	constexpr auto MIDDLEATTACK_PARTICLE1_GREEN = 128;									//�ΐF�l(0�`255)
	constexpr auto MIDDLEATTACK_PARTICLE1_BLUE = 128;									//�F�l(0�`255)
	constexpr auto MIDDLEATTACK_PARTICLE1_SCALE = 1.0;									//�g�k�l(1.0���f�t�H���g)
	constexpr auto MIDDLEATTACK_PARTICLE1_ANGLE = 0.0;									//�`��p�x(3.14=180��)
	constexpr auto MIDDLEATTACK_PARTICLE1_CNT = 20;										//�p�[�e�B�N��1������̐�������
	constexpr auto MIDDLEATTACK_PARTICLE1_QTY = 10;										//1�t���[��������̃p�[�e�B�N����
	//�p�[�e�B�N��1������̈ړ������̃����_���l����
	constexpr auto MIDDLEATTACK_PARTICLE1_RANDOMX1 = 20;								//�p�[�e�B�N����X�����_���l
	constexpr auto MIDDLEATTACK_PARTICLE1_RANDOMX2 = 10.0;								//		�V
	constexpr auto MIDDLEATTACK_PARTICLE1_RANDOMX3 = 8.0;								//		�V
	constexpr auto MIDDLEATTACK_PARTICLE1_RANDOMY1 = 20;								//�p�[�e�B�N����Y�����_���l
	constexpr auto MIDDLEATTACK_PARTICLE1_RANDOMY2 = 10.0;								//		�V
	constexpr auto MIDDLEATTACK_PARTICLE1_RANDOMY3 = 8.0;								//		�V

	/*----------���i�U��2----------*/
	constexpr auto MIDDLEATTACK_PARTICLE2_GRAPH = "res/Particle/MiddleSibuki.png";	//�摜�t�@�C����
	constexpr auto MIDDLEATTACK_PARTICLE2_POSITIONX = 0.0;								//��_(����)����`��_�ւ�X���W����
	constexpr auto MIDDLEATTACK_PARTICLE2_POSITIONY = -325.0;							//��_(����)����`��_�ւ�Y���W����
	constexpr auto MIDDLEATTACK_PARTICLE2_BLENDMODE = DX_BLENDMODE_SUB;					//�u�����h���[�h�ݒ�
	constexpr auto MIDDLEATTACK_PARTICLE2_PAL = 128;									//�u�����h�l(0�`255)
	constexpr auto MIDDLEATTACK_PARTICLE2_RED = 200;									//�ԐF�l(0�`255)
	constexpr auto MIDDLEATTACK_PARTICLE2_GREEN = 200;									//�ΐF�l(0�`255)
	constexpr auto MIDDLEATTACK_PARTICLE2_BLUE = 200;									//�F�l(0�`255)
	constexpr auto MIDDLEATTACK_PARTICLE2_SCALE = 1.0;									//�g�k�l(1.0���f�t�H���g)
	constexpr auto MIDDLEATTACK_PARTICLE2_ANGLE = 0.0;									//�`��p�x(3.14=180��)
	constexpr auto MIDDLEATTACK_PARTICLE2_CNT = 20;										//�p�[�e�B�N��1������̐�������
	constexpr auto MIDDLEATTACK_PARTICLE2_QTY = 5;										//1�t���[��������̃p�[�e�B�N����
	//�p�[�e�B�N��1������̈ړ������̃����_���l����
	constexpr auto MIDDLEATTACK_PARTICLE2_RANDOMX1 = 20;								//�p�[�e�B�N����X�����_���l
	constexpr auto MIDDLEATTACK_PARTICLE2_RANDOMX2 = 5.0;								//		�V
	constexpr auto MIDDLEATTACK_PARTICLE2_RANDOMX3 = 2.0;								//		�V
	constexpr auto MIDDLEATTACK_PARTICLE2_RANDOMY1 = 20;								//�p�[�e�B�N����Y�����_���l
	constexpr auto MIDDLEATTACK_PARTICLE2_RANDOMY2 = 5.0;								//		�V
	constexpr auto MIDDLEATTACK_PARTICLE2_RANDOMY3 = 2.0;								//		�V
	/*----------���i�U��1----------*/
	constexpr auto LOWATTACK_PARTICLE1_GRAPH = "res/Particle/LowAttack.png";			//�摜�t�@�C����
	constexpr auto LOWATTACK_PARTICLE1_POSITIONX = 0.0;									//��_(����)����`��_�ւ�X���W����
	constexpr auto LOWATTACK_PARTICLE1_POSITIONY = -225.0;								//��_(����)����`��_�ւ�Y���W����
	constexpr auto LOWATTACK_PARTICLE1_BLENDMODE = DX_BLENDMODE_SUB;					//�u�����h���[�h�ݒ�
	constexpr auto LOWATTACK_PARTICLE1_PAL = 64;										//�u�����h�l(0�`255)
	constexpr auto LOWATTACK_PARTICLE1_RED = 128;										//�ԐF�l(0�`255)
	constexpr auto LOWATTACK_PARTICLE1_GREEN = 128;										//�ΐF�l(0�`255)
	constexpr auto LOWATTACK_PARTICLE1_BLUE = 128;										//�F�l(0�`255)
	constexpr auto LOWATTACK_PARTICLE1_SCALE = 1.0;										//�g�k�l(1.0���f�t�H���g)
	constexpr auto LOWATTACK_PARTICLE1_ANGLE = 0.0;										//�`��p�x(3.14=180��)
	constexpr auto LOWATTACK_PARTICLE1_CNT = 20;										//�p�[�e�B�N��1������̐�������
	constexpr auto LOWATTACK_PARTICLE1_QTY = 5;											//1�t���[��������̃p�[�e�B�N����
	//�p�[�e�B�N��1������̈ړ������̃����_���l����
	constexpr auto LOWATTACK_PARTICLE1_RANDOMX1 = 20;									//�p�[�e�B�N����X�����_���l
	constexpr auto LOWATTACK_PARTICLE1_RANDOMX2 = 10.0;									//		�V
	constexpr auto LOWATTACK_PARTICLE1_RANDOMX3 = 8.0;									//		�V
	constexpr auto LOWATTACK_PARTICLE1_RANDOMY1 = 20;									//�p�[�e�B�N����Y�����_���l
	constexpr auto LOWATTACK_PARTICLE1_RANDOMY2 = 10.0;									//		�V
	constexpr auto LOWATTACK_PARTICLE1_RANDOMY3 = 8.0;									//		�V
	/*----------���i�U��2----------*/
	constexpr auto LOWATTACK_PARTICLE2_GRAPH = "res/Particle/LowAttacksub.png";			//�摜�t�@�C����
	constexpr auto LOWATTACK_PARTICLE2_POSITIONX = 0.0;									//��_(����)����`��_�ւ�X���W����
	constexpr auto LOWATTACK_PARTICLE2_POSITIONY = -225.0;								//��_(����)����`��_�ւ�Y���W����
	constexpr auto LOWATTACK_PARTICLE2_BLENDMODE = DX_BLENDMODE_SUB;					//�u�����h���[�h�ݒ�
	constexpr auto LOWATTACK_PARTICLE2_PAL = 128;										//�u�����h�l(0�`255)
	constexpr auto LOWATTACK_PARTICLE2_RED = 200;										//�ԐF�l(0�`255)
	constexpr auto LOWATTACK_PARTICLE2_GREEN = 200;										//�ΐF�l(0�`255)
	constexpr auto LOWATTACK_PARTICLE2_BLUE = 200;										//�F�l(0�`255)
	constexpr auto LOWATTACK_PARTICLE2_SCALE = 1.0;										//�g�k�l(1.0���f�t�H���g)
	constexpr auto LOWATTACK_PARTICLE2_ANGLE = 0.0;										//�`��p�x(3.14=180��)
	constexpr auto LOWATTACK_PARTICLE2_CNT = 20;										//�p�[�e�B�N��1������̐�������
	constexpr auto LOWATTACK_PARTICLE2_QTY = 5;											//1�t���[��������̃p�[�e�B�N����
	//�p�[�e�B�N��1������̈ړ������̃����_���l����
	constexpr auto LOWATTACK_PARTICLE2_RANDOMX1 = 20;									//�p�[�e�B�N����X�����_���l
	constexpr auto LOWATTACK_PARTICLE2_RANDOMX2 = 5.0;									//		�V
	constexpr auto LOWATTACK_PARTICLE2_RANDOMX3 = 2.0;									//		�V
	constexpr auto LOWATTACK_PARTICLE2_RANDOMY1 = 20;									//�p�[�e�B�N����Y�����_���l
	constexpr auto LOWATTACK_PARTICLE2_RANDOMY2 = 5.0;									//		�V
	constexpr auto LOWATTACK_PARTICLE2_RANDOMY3 = 2.0;									//		�V

	/*----------����1----------*/
	constexpr auto IAI_PARTICLE1_GRAPH = "res/Particle/Iai1.png";						//�摜�t�@�C����
	constexpr auto IAI_PARTICLE1_POSITIONX = 0.0;										//��_(����)����`��_�ւ�X���W����
	constexpr auto IAI_PARTICLE1_POSITIONY = -225.0;									//��_(����)����`��_�ւ�Y���W����
	constexpr auto IAI_PARTICLE1_BLENDMODE = DX_BLENDMODE_ADD;							//�u�����h���[�h�ݒ�
	constexpr auto IAI_PARTICLE1_PAL = 128;												//�u�����h�l(0�`255)
	constexpr auto IAI_PARTICLE1_RED = 80;												//�ԐF�l(0�`255)
	constexpr auto IAI_PARTICLE1_GREEN = 80;											//�ΐF�l(0�`255)
	constexpr auto IAI_PARTICLE1_BLUE = 60;												//�F�l(0�`255)
	constexpr auto IAI_PARTICLE1_SCALE = 0.8;											//�g�k�l(1.0���f�t�H���g)
	constexpr auto IAI_PARTICLE1_ANGLE = 0.0;											//�`��p�x(3.14=180��)
	constexpr auto IAI_PARTICLE1_CNT = 20;												//�p�[�e�B�N��1������̐�������
	constexpr auto IAI_PARTICLE1_QTY = 5;												//1�t���[��������̃p�[�e�B�N����
	//�p�[�e�B�N��1������̈ړ������̃����_���l����
	constexpr auto IAI_PARTICLE1_RANDOMX1 = 20;											//�p�[�e�B�N����X�����_���l
	constexpr auto IAI_PARTICLE1_RANDOMX2 = 10.0;										//		�V
	constexpr auto IAI_PARTICLE1_RANDOMX3 = 8.0;										//		�V
	constexpr auto IAI_PARTICLE1_RANDOMY1 = 20;											//�p�[�e�B�N����Y�����_���l
	constexpr auto IAI_PARTICLE1_RANDOMY2 = 10.00;										//		�V
	constexpr auto IAI_PARTICLE1_RANDOMY3 = 8.0;										//		�V

	/*----------����2----------*/
	constexpr auto IAI_PARTICLE2_GRAPH = "res/Particle/Iai.png";						//�摜�t�@�C����
	constexpr auto IAI_PARTICLE2_POSITIONX = 0.0;										//��_(����)����`��_�ւ�X���W����
	constexpr auto IAI_PARTICLE2_POSITIONY = -225.0;									//��_(����)����`��_�ւ�Y���W����
	constexpr auto IAI_PARTICLE2_BLENDMODE = DX_BLENDMODE_SUB;							//�u���h���[�h�ݒ�
	constexpr auto IAI_PARTICLE2_PAL = 128;												//�u�����h�l(0�`255)
	constexpr auto IAI_PARTICLE2_RED = 64;												//�ԐF�l(0�`255)
	constexpr auto IAI_PARTICLE2_GREEN = 200;											//�ΐF�l(0�`255)
	constexpr auto IAI_PARTICLE2_BLUE = 64;												//�F�l(0�`255)
	constexpr auto IAI_PARTICLE2_SCALE = 1.0;											//�g�k�l(1.0���f�t�H���g)
	constexpr auto IAI_PARTICLE2_ANGLE = 0.0;											//�`��p�x(3.14=180��)
	constexpr auto IAI_PARTICLE2_CNT = 20;												//�p�[�e�B�N��1������̐�������
	constexpr auto IAI_PARTICLE2_QTY = 5;												//1�t���[��������̃p�[�e�B�N����
	//�p�[�e�B�N��1������̈ړ������̃����_���l����
	constexpr auto IAI_PARTICLE2_RANDOMX1 = 20;											//�p�[�e�B�N����X�����_���l
	constexpr auto IAI_PARTICLE2_RANDOMX2 = 10.0;										//		�V
	constexpr auto IAI_PARTICLE2_RANDOMX3 = 8.0;										//		�V
	constexpr auto IAI_PARTICLE2_RANDOMY1 = 20;											//�p�[�e�B�N����Y�����_���l
	constexpr auto IAI_PARTICLE2_RANDOMY2 = 10.0;										//		�V
	constexpr auto IAI_PARTICLE2_RANDOMY3 = 8.0;										//		�V

	/*----------����3----------*/
	constexpr auto IAI_PARTICLE3_GRAPH = "res/Particle/Iai3.png";						//�摜�t�@�C����
	constexpr auto IAI_PARTICLE3_POSITIONX = 0.0;										//��_(����)����`��_�ւ�X���W����
	constexpr auto IAI_PARTICLE3_POSITIONY = -225.0;									//��_(����)����`��_�ւ�Y���W����
	constexpr auto IAI_PARTICLE3_BLENDMODE = DX_BLENDMODE_SUB;							//�u�����h���[�h�ݒ�
	constexpr auto IAI_PARTICLE3_PAL = 128;												//�u�����h�l(0�`255)
	constexpr auto IAI_PARTICLE3_RED = 200;												//�ԐF�l(0�`255)
	constexpr auto IAI_PARTICLE3_GREEN = 200;											//�ΐF�l(0�`255)
	constexpr auto IAI_PARTICLE3_BLUE = 200;											//�F�l(0�`255)
	constexpr auto IAI_PARTICLE3_SCALE = 1.0;											//�g�k�l(1.0���f�t�H���g)
	constexpr auto IAI_PARTICLE3_ANGLE = 0.0;											//�`��p�x(3.14=180��)
	constexpr auto IAI_PARTICLE3_CNT = 20;												//�p�[�e�B�N��1������̐�������
	constexpr auto IAI_PARTICLE3_QTY = 5;												//1�t���[��������̃p�[�e�B�N����
	//�p�[�e�B�N��1������̈ړ������̃����_���l����
	constexpr auto IAI_PARTICLE3_RANDOMX1 = 20;											//�p�[�e�B�N����X�����_���l
	constexpr auto IAI_PARTICLE3_RANDOMX2 = 5.0;										//		�V
	constexpr auto IAI_PARTICLE3_RANDOMX3 = 2.0;										//		�V
	constexpr auto IAI_PARTICLE3_RANDOMY1 = 20;											//�p�[�e�B�N����Y�����_���l
	constexpr auto IAI_PARTICLE3_RANDOMY2 = 5.0;										//		�V
	constexpr auto IAI_PARTICLE3_RANDOMY3 = 2.0;										//		�V

	/*----------�����Q�[�W----------*/
	constexpr auto IAIG_PARTICLE_GRAPH = "res/Particle/IaiGaugeP.png";					//�摜�t�@�C����
	constexpr auto IAIG_PARTICLE_POSITIONX = 0.0;									//��_(����)����`��_�ւ�X���W����
	constexpr auto IAIG_PARTICLE_POSITIONY = 0.0;										//��_(����)����`��_�ւ�Y���W����
	constexpr auto IAIG_PARTICLE_BLENDMODE = DX_BLENDMODE_ADD;							//�u�����h���[�h�ݒ�
	constexpr auto IAIG_PARTICLE_PAL = 128;												//�u�����h�l(0�`255)
	constexpr auto IAIG_PARTICLE_RED = 230;												//�ԐF�l(0�`255)
	constexpr auto IAIG_PARTICLE_GREEN = 70;											//�ΐF�l(0�`255)
	constexpr auto IAIG_PARTICLE_BLUE = 5;												//�F�l(0�`255)
	constexpr auto IAIG_PARTICLE_SCALE = 1.0;											//�g�k�l(1.0���f�t�H���g)
	constexpr auto IAIG_PARTICLE_ANGLE = 0.0;											//�`��p�x(3.14=180��)
	constexpr auto IAIG_PARTICLE_CNT = 10;												//�p�[�e�B�N��1������̐�������
	constexpr auto IAIG_PARTICLE_QTY = 5;												//1�t���[��������̃p�[�e�B�N����
	//�p�[�e�B�N��1������̈ړ������̃����_���l����
	constexpr auto IAIG_PARTICLE_RANDOMX1 = 10;											//�p�[�e�B�N����X�����_���l
	constexpr auto IAIG_PARTICLE_RANDOMX2 = 5.0;										//		�V
	constexpr auto IAIG_PARTICLE_RANDOMX3 = 4.0;										//		�V
	constexpr auto IAIG_PARTICLE_RANDOMY1 = 10;											//�p�[�e�B�N����Y�����_���l
	constexpr auto IAIG_PARTICLE_RANDOMY2 = 5.0;										//		�V
	constexpr auto IAIG_PARTICLE_RANDOMY3 = 4.0;										//		�V
}