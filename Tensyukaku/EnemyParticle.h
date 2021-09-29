#pragma once
#include "ParticleBase.h"
#include <tuple>
#include <utility>
//�U���\������̌�
class ReserveLight : public ParticleBase {
public:
	ReserveLight(std::pair<double, double> xy, std::pair<double, double> vxy, bool flip);
	~ReserveLight();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::RESERVELIGHT; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};

namespace EPInfo {
	//�U���\������̌�
	constexpr auto RESERVELIGHT_PARTICLE_GRAPH = "res/Particle/ReserveLight.png";		//�摜�t�@�C����
	constexpr auto RESERVELIGHT_PARTICLE_POSITIONX = 0.0;								//��_(����)����`��_�ւ�X���W����
	constexpr auto RESERVELIGHT_PARTICLE_POSITIONY = -100.0;							//��_(����)����`��_�ւ�Y���W����
	constexpr auto RESERVELIGHT_PARTICLE_BLENDMODE = DX_BLENDMODE_ADD;					//�u�����h���[�h�ݒ�
	constexpr auto RESERVELIGHT_PARTICLE_PAL = 128;										//�u�����h�l(0�`255)
	constexpr auto RESERVELIGHT_PARTICLE_RED = 128;									//�ԐF�l(0�`255)
	constexpr auto RESERVELIGHT_PARTICLE_GREEN = 128;									//�ΐF�l(0�`255)
	constexpr auto RESERVELIGHT_PARTICLE_BLUE = 128;									//�F�l(0�`255)
	constexpr auto RESERVELIGHT_PARTICLE_SCALE = 1.0;									//�g�k�l(1.0���f�t�H���g)
	constexpr auto RESERVELIGHT_PARTICLE_ANGLE = 0.0;									//�`��p�x(3.14=180��)
	constexpr auto RESERVELIGHT_PARTICLE_CNT = 20;										//�p�[�e�B�N��1������̐�������
	constexpr auto RESERVELIGHT_PARTICLE_QTY = 10;										//1�t���[��������̃p�[�e�B�N����
	//�p�[�e�B�N��1������̈ړ������̃����_���l����
	constexpr auto RESERVELIGHT_PARTICLE_RANDOMX1 = 20;								//�p�[�e�B�N����X�����_���l
	constexpr auto RESERVELIGHT_PARTICLE_RANDOMX2 = 10.0;								//		�V
	constexpr auto RESERVELIGHT_PARTICLE_RANDOMX3 = 8.0;								//		�V
	constexpr auto RESERVELIGHT_PARTICLE_RANDOMY1 = 20;								//�p�[�e�B�N����Y�����_���l
	constexpr auto RESERVELIGHT_PARTICLE_RANDOMY2 = 10.0;								//		�V
	constexpr auto RESERVELIGHT_PARTICLE_RANDOMY3 = 8.0;								//		�V

}