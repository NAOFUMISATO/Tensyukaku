#include "CPointBlock.h"
#include "Game.h"
using namespace CPInfo;
namespace {
	constexpr auto GRAPHPOINT_X = 0;		//X位置から描画点までの差分
	constexpr auto GRAPHPOINT_Y = -50;		//Y位置から描画点までの差分
	constexpr auto POSITION_HITX = -50;		//描画点から当たり判定左上座標までの差分
	constexpr auto POSITION_HITY = -50;		//描画点から当たり判定左上座標までの差分
	constexpr auto COLLISION_WIDTH = 100;	//階段の当たり判定横幅
	constexpr auto COLLISION_HEIGHT = 100;	//階段の当たり判定縦幅
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
	//チェックポイントとプレイヤーの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
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