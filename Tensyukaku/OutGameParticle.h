#pragma once
#include "ParticleBase.h"
#include <tuple>
#include <utility>
//�J�[�\��
class CursorParticle1: public ParticleBase {
public:
	CursorParticle1(std::pair<double, double> xy, std::pair<double, double> vxy,int colortype);
	~CursorParticle1();

	virtual PARTICLETYPE GetParType() { return PARTICLETYPE::CURSOR1; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
private:
	int _ColorType;
};

namespace CParInfo {
	/*----------�J�[�\��----------*/
	constexpr auto CURSOR_PARTICLE1_GRAPH = "res/Particle/Cursor.png";				//�摜�t�@�C����
	constexpr auto CURSOR_PARTICLE1_POSITIONX = 0.0;								//��_(����)����`��_�ւ�X���W����
	constexpr auto CURSOR_PARTICLE1_POSITIONY = -10.0;								//��_(����)����`��_�ւ�Y���W����
	constexpr auto CURSOR_PARTICLE1_BLENDMODE = DX_BLENDMODE_PMA_ADD;				//�u�����h���[�h�ݒ�
	constexpr auto CURSOR_PARTICLE1_PAL = 50;										//�u�����h�l
	constexpr auto CURSOR_PARTICLE1_SCALE = 1.0;									//�g�k�l
	constexpr auto CURSOR_PARTICLE1_ANGLE = 0.0;									//�`��p�x(3.14=180��)
	constexpr auto CURSOR_PARTICLE1_CNT = 30;										//�p�[�e�B�N��1������̐�������
	constexpr auto CURSOR_PARTICLE1_QTY = 7;										//1�t���[��������̃p�[�e�B�N����
	//�p�[�e�B�N��1������̈ړ������̃����_���l����
	constexpr auto CURSOR_PARTICLE1_RANDOMX1 = 30;									//�p�[�e�B�N����X�����_���l
	constexpr auto CURSOR_PARTICLE1_RANDOMX2 = 10.5;								//		�V
	constexpr auto CURSOR_PARTICLE1_RANDOMX3 = 10.5;								//		�V
	constexpr auto CURSOR_PARTICLE1_RANDOMY1 = 17;									//�p�[�e�B�N����Y�����_���l
	constexpr auto CURSOR_PARTICLE1_RANDOMY2 = 19.5;								//		�V
	constexpr auto CURSOR_PARTICLE1_RANDOMY3 = 8.5;									//		�V
	
}