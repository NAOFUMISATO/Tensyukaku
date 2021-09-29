#include "SpawnBlockBase.h"
#include "Game.h"
namespace {
	constexpr auto GRAPHPOINT_X = 0;		//X�ʒu����`��_�܂ł̍���
	constexpr auto GRAPHPOINT_Y = -50;		//Y�ʒu����`��_�܂ł̍���
	constexpr auto POSITION_HITX = -50;		//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto POSITION_HITY = -50;		//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto COLLISION_WIDTH = 100;	//�K�i�̓����蔻�艡��
	constexpr auto COLLISION_HEIGHT = 100;	//�K�i�̓����蔻��c��
}
SpawnBlockBase::SpawnBlockBase() {
	Init();
}
SpawnBlockBase::~SpawnBlockBase() {
}

void SpawnBlockBase::Init() {
	
}
void SpawnBlockBase::Draw(Game& g) {
	ObjectBase::Draw(g);
}
void SpawnBlockBase::Delete(Game& g) {
	g.GetOS()->Del(this);
}