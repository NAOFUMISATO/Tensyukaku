#pragma once
#include "ParticleBase.h"
#include <tuple>
#include <utility>
//�N�i�C�����\������̌�
class KunaiReserveLight : public ParticleBase {
public:
	KunaiReserveLight(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~KunaiReserveLight();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::KUNAIRESERVELIGHT; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
//�����\������̌�
class LanceReserveLight : public ParticleBase {
public:
	LanceReserveLight(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~LanceReserveLight();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::LANCERESERVELIGHT; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
namespace EPInfo {
	//�N�i�C�����\������̌�
	constexpr auto KRESERVELIGHT_PARTICLE_GRAPH = "res/Particle/KunaiReserveLight.png";		//�摜�t�@�C����
	constexpr auto KRESERVELIGHT_PARTICLE_POSITIONX = 0.0;								//��_(����)����`��_�ւ�X���W����
	constexpr auto KRESERVELIGHT_PARTICLE_POSITIONY = -100.0;							//��_(����)����`��_�ւ�Y���W����
	constexpr auto KRESERVELIGHT_PARTICLE_BLENDMODE = DX_BLENDMODE_ADD;					//�u�����h���[�h�ݒ�
	constexpr auto KRESERVELIGHT_PARTICLE_PAL = 128;										//�u�����h�l(0�`255)
	constexpr auto KRESERVELIGHT_PARTICLE_RED = 128;									//�ԐF�l(0�`255)
	constexpr auto KRESERVELIGHT_PARTICLE_GREEN = 128;									//�ΐF�l(0�`255)
	constexpr auto KRESERVELIGHT_PARTICLE_BLUE = 128;									//�F�l(0�`255)
	constexpr auto KRESERVELIGHT_PARTICLE_SCALE = 1.0;									//�g�k�l(1.0���f�t�H���g)
	constexpr auto KRESERVELIGHT_PARTICLE_ANGLE = 0.0;									//�`��p�x(3.14=180��)
	constexpr auto KRESERVELIGHT_PARTICLE_CNT = 20;										//�p�[�e�B�N��1������̐�������
	constexpr auto KRESERVELIGHT_PARTICLE_QTY = 10;										//1�t���[��������̃p�[�e�B�N����
	//�p�[�e�B�N��1������̈ړ������̃����_���l����
	constexpr auto KRESERVELIGHT_PARTICLE_RANDOMX1 = 20;								//�p�[�e�B�N����X�����_���l
	constexpr auto KRESERVELIGHT_PARTICLE_RANDOMX2 = 10.0;								//		�V
	constexpr auto KRESERVELIGHT_PARTICLE_RANDOMX3 = 8.0;								//		�V
	constexpr auto KRESERVELIGHT_PARTICLE_RANDOMY1 = 20;								//�p�[�e�B�N����Y�����_���l
	constexpr auto KRESERVELIGHT_PARTICLE_RANDOMY2 = 10.0;								//		�V
	constexpr auto KRESERVELIGHT_PARTICLE_RANDOMY3 = 8.0;								//		�V
	//�����\������̌�
	constexpr auto LRESERVELIGHT_PARTICLE_GRAPH = "res/Particle/LanceReserveLight.png";		//�摜�t�@�C����
	constexpr auto LRESERVELIGHT_PARTICLE_POSITIONX = 0.0;								//��_(����)����`��_�ւ�X���W����
	constexpr auto LRESERVELIGHT_PARTICLE_POSITIONY = -250.0;							//��_(����)����`��_�ւ�Y���W����
	constexpr auto LRESERVELIGHT_PARTICLE_BLENDMODE = DX_BLENDMODE_ADD;					//�u�����h���[�h�ݒ�
	constexpr auto LRESERVELIGHT_PARTICLE_PAL = 128;										//�u�����h�l(0�`255)
	constexpr auto LRESERVELIGHT_PARTICLE_RED = 128;									//�ԐF�l(0�`255)
	constexpr auto LRESERVELIGHT_PARTICLE_GREEN = 128;									//�ΐF�l(0�`255)
	constexpr auto LRESERVELIGHT_PARTICLE_BLUE = 128;									//�F�l(0�`255)
	constexpr auto LRESERVELIGHT_PARTICLE_SCALE = 1.0;									//�g�k�l(1.0���f�t�H���g)
	constexpr auto LRESERVELIGHT_PARTICLE_ANGLE = 0.0;									//�`��p�x(3.14=180��)
	constexpr auto LRESERVELIGHT_PARTICLE_CNT = 20;										//�p�[�e�B�N��1������̐�������
	constexpr auto LRESERVELIGHT_PARTICLE_QTY = 10;										//1�t���[��������̃p�[�e�B�N����
	//�p�[�e�B�N��1������̈ړ������̃����_���l����
	constexpr auto LRESERVELIGHT_PARTICLE_RANDOMX1 = 20;								//�p�[�e�B�N����X�����_���l
	constexpr auto LRESERVELIGHT_PARTICLE_RANDOMX2 = 10.0;								//		�V
	constexpr auto LRESERVELIGHT_PARTICLE_RANDOMX3 = 8.0;								//		�V
	constexpr auto LRESERVELIGHT_PARTICLE_RANDOMY1 = 20;								//�p�[�e�B�N����Y�����_���l
	constexpr auto LRESERVELIGHT_PARTICLE_RANDOMY2 = 10.0;								//		�V
	constexpr auto LRESERVELIGHT_PARTICLE_RANDOMY3 = 8.0;								//		�V
}