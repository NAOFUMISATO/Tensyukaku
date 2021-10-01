#include "CPointBlock.h"
#include "Game.h"
using namespace CPInfo;
namespace {
	constexpr auto GRAPHPOINT_X = 0;		//X�ʒu����`��_�܂ł̍���
	constexpr auto GRAPHPOINT_Y = -50;		//Y�ʒu����`��_�܂ł̍���
	constexpr auto POSITION_HITX = -50;		//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto POSITION_HITY = -50;		//�`��_���瓖���蔻�荶����W�܂ł̍���
	constexpr auto COLLISION_WIDTH = 100;	//�K�i�̓����蔻�艡��
	constexpr auto COLLISION_HEIGHT = 100;	//�K�i�̓����蔻��c��
}
CPointBlock::CPointBlock(std::string  cpointtype) {	
	_cpoint_type = cpointtype;
	Init();
}
CPointBlock::~CPointBlock() {
};

void CPointBlock::Init() {
	CPointPosition();
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
#ifdef _DEBUG
	_debug_color = std::make_tuple(255, 255, 5);
	_debug_alpha = 128;
	_debug_fill = true;
#endif
}

void CPointBlock::Process(Game& g) {
	ObjectBase::Process(g);
	//�`�F�b�N�|�C���g�ƃv���C���[�̓����蔻��
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// ite�̓v���C���[���H
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
		{
			if (IsHit(*(*ite)) == true)
			{
				auto flag = g.GetCPointFlag();
				if (_cpoint_type == "2A") {
					flag["2A"] = true;
				}
				else if (_cpoint_type == "3A"){
					flag["3A"] = true;
				}
				else if (_cpoint_type == "4A") {
					flag["4A"] = true;
				}
				else if (_cpoint_type == "5A") {
					flag["5A"] = true;
				}
				else if (_cpoint_type == "5B") {
					flag["5B"] = true;
				}
				else if (_cpoint_type == "8A") {
					flag["8A"] = true;
				}
				else if(_cpoint_type == "11A"){
					flag["11A"] = true;
				}
				g.SetCPointFlag(flag);
				Delete(g);
			}
		}
	}
}

void  CPointBlock::Draw(Game& g) {
	ObjectBase::Draw(g);
}

void CPointBlock::Delete(Game& g) {
	g.GetOS()->Del(this);
}

void CPointBlock::CPointPosition() {
	if (_cpoint_type == "2A") {
		_x = CPOINT_2A_X;
		_y= CPOINT_2A_Y;
	}
	else if (_cpoint_type == "3A") {
		_x = CPOINT_3A_X;
		_y = CPOINT_3A_Y;
	}
	else if (_cpoint_type == "4A") {
		_x = CPOINT_4A_X;
		_y = CPOINT_4A_Y;
	}
	else if (_cpoint_type == "5A") {
		_x = CPOINT_5A_X;
		_y = CPOINT_5A_Y;
	}
	else if (_cpoint_type == "5B") {
		_x = CPOINT_5B_X;
		_y = CPOINT_5B_Y;
	}
	else if (_cpoint_type == "8A") {
		_x = CPOINT_8A_X;
		_y = CPOINT_8A_Y;
	}
	else if (_cpoint_type == "11A") {
		_x = CPOINT_11A_X;
		_y = CPOINT_11A_Y;
	}
}