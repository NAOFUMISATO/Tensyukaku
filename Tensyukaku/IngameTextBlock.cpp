#include "IngameTextBlock.h"
#include "ModeIngameText.h"
#include "Game.h"
using namespace ITInfo;
IngameTextBlock::IngameTextBlock(std::string texttype) {
	_text_type = texttype;
	Init();
}
IngameTextBlock::~IngameTextBlock() {
};

void IngameTextBlock::Init() {
	TextPosition();
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
#ifdef _DEBUG
	_debug_color = std::make_tuple(15, 15, 15);
	_debug_alpha = 128;
	_debug_fill = true;
#endif
}
void IngameTextBlock::Process(Game& g) {
	ObjectBase::Process(g);
	//チュートリアルブロックとプレイヤーの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
		{
			// //チュートリアルブロックとプレイヤーの当たり判定を行う
			if (IsHit(*(*ite)) == true)
			{
				Delete(g);
				if (_text_type == "TOP") {
					auto ittop = new ModeIngameText();
					ittop->SetType("TOP");
					g.GetMS()->Add(ittop, 3, "TOP");
				}
				else if (_text_type == "UPPER") {
					auto itupper = new ModeIngameText();
					itupper->SetType("UPPER");
					g.GetMS()->Add(itupper, 3, "UPPER");
				}
				else if (_text_type == "MIDDLE") {
					auto itmiddle = new ModeIngameText();
					itmiddle->SetType("MIDDLE");
					g.GetMS()->Add(itmiddle, 3, "MIDDLE");
				}
				else if (_text_type == "UNDER") {
					auto itunder = new ModeIngameText();
					itunder->SetType("UNDER");
					g.GetMS()->Add(itunder, 10, "UNDER");
				}
			}
		}
	}
}

void  IngameTextBlock::Draw(Game& g) {
	ObjectBase::Draw(g);
}

void IngameTextBlock::Delete(Game& g) {
	g.GetOS()->Del(this);
}

void IngameTextBlock::TextPosition() {
	if (_text_type == "TOP") {
		_x = TOP_TEXT_X;
		_y = TOP_TEXT_Y;
	}
	else if (_text_type == "UPPER") {
		_x = UPPER_TEXT_X;
		_y = UPPER_TEXT_Y;
	}
	else if (_text_type == "MIDDLE") {
		_x = MIDDLE_TEXT_X;
		_y = MIDDLE_TEXT_Y;
	}
	else if (_text_type == "UNDER") {
		_x = UNDER_TEXT_X;
		_y = UNDER_TEXT_Y;
	}
}