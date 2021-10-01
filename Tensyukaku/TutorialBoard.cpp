#include <DxLib.h>
#include "ResourceServer.h"
#include  "TutorialBoard.h"
#include "ModeTutorial.h"
#include "ModeGame.h"
#include  "Game.h"

using namespace TBInfo;
namespace {
	constexpr auto GRAPHPOINT_X = 0;		//X位置から描画点までの差分
	constexpr auto GRAPHPOINT_Y = -180;		//Y位置から描画点までの差分
	constexpr auto POSITION_HITX = -100;		//描画点から当たり判定左上座標までの差分
	constexpr auto POSITION_HITY = -180;		//描画点から当たり判定左上座標までの差分
	constexpr auto COLLISION_WIDTH = 200;	//当たり判定横幅
	constexpr auto COLLISION_HEIGHT = 360;	//当たり判定縦幅
}
TutorialBoard::TutorialBoard(std::string tutorialtype):_tutorialhit_flag(false) {
	_tutorial_type = tutorialtype;
	_grhandle = ResourceServer::LoadGraph("res/Gimik/TutorialBoard.png");
	Init();
}
TutorialBoard::~TutorialBoard() {
};

void TutorialBoard::Init() {
	TutorialPosition();
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
#ifdef _DEBUG
	_debug_color = std::make_tuple(255, 100, 5);
	_debug_alpha = 128;
	_debug_fill = true;
#endif
}
void  TutorialBoard::Process(Game& g) {
	ObjectBase::Process(g);
	//チュートリアルブロックとプレイヤーの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
		{
			// //チュートリアルブロックとプレイヤーの当たり判定を行う
			if (IsHit(*(*ite)) == true&&_tutorialhit_flag==false)
			{
				_tutorialhit_flag = true;
				if (_tutorial_type == "1A") {
					auto mb1 = new ModeTutorial();
					mb1->SetType("1A");
					g.GetMS()->Add(mb1, 3, "1A");
				}
				else if (_tutorial_type == "1B") {
					auto mb2 = new ModeTutorial();
					mb2->SetType("1B");
					g.GetMS()->Add(mb2, 3, "1B");
				}
				else if (_tutorial_type == "2A") {
					auto mb3 = new ModeTutorial();
					mb3->SetType("2A");
					g.GetMS()->Add(mb3, 3, "2A");
				}
				else if (_tutorial_type == "3A") {
					auto mb4 = new ModeTutorial();
					mb4->SetType("3A");
					g.GetMS()->Add(mb4, 3, "3A");
				}
				else if (_tutorial_type == "3B") {
					auto mb5 = new ModeTutorial();
					mb5->SetType("3B");
					g.GetMS()->Add(mb5, 3, "3B");
				}
				else if (_tutorial_type == "4A") {
					auto mb6= new ModeTutorial();
					mb6->SetType("4A");
					g.GetMS()->Add(mb6, 3, "4A");
				}
				else if (_tutorial_type == "5A") {
					auto mb7 = new ModeTutorial();
					mb7->SetType("5A");
					g.GetMS()->Add(mb7, 3, "5A");
				}
			}
			if (IsHit(*(*ite)) == false&&_tutorialhit_flag == true)
			{
				_tutorialhit_flag = false;
				if (_tutorial_type == "1A") {
					g.GetMS()->Del(g.GetMS()->Get("1A"));
				}
				else if (_tutorial_type == "1B") {
					g.GetMS()->Del(g.GetMS()->Get("1B"));
				}
				else if (_tutorial_type == "2A") {
					g.GetMS()->Del(g.GetMS()->Get("2A"));
				}
				else if (_tutorial_type == "3A") {
					g.GetMS()->Del(g.GetMS()->Get("3A"));
				}
				else if (_tutorial_type == "3B") {
					g.GetMS()->Del(g.GetMS()->Get("3B"));
				}
				else if (_tutorial_type == "4A") {
					g.GetMS()->Del(g.GetMS()->Get("4A"));
				}
				else if (_tutorial_type == "5A") {
					g.GetMS()->Del(g.GetMS()->Get("5A"));
				}
			}
		}
	}
}
void  TutorialBoard::Draw(Game& g) {
	ObjectBase::Draw(g);
}

void TutorialBoard::Delete(Game& g) {
	g.GetOS()->Del(this);
}

void TutorialBoard::TutorialPosition() {
	if (_tutorial_type == "1A") {
		_x = TUTORIAL1A_X;
		_y = TUTORIAL1A_Y;
	}
	else if (_tutorial_type == "1B") {
		_x = TUTORIAL1B_X;
		_y = TUTORIAL1B_Y;
	}
	else if (_tutorial_type == "2A") {
		_x = TUTORIAL2A_X;
		_y = TUTORIAL2A_Y;
	}
	else if (_tutorial_type == "3A") {
		_x = TUTORIAL3A_X;
		_y = TUTORIAL3A_Y;
	}
	else if (_tutorial_type == "3B") {
		_x = TUTORIAL3B_X;
		_y = TUTORIAL3B_Y;
	}
	else if (_tutorial_type == "4A") {
		_x = TUTORIAL4A_X;
		_y = TUTORIAL4A_Y;
	}
	else if (_tutorial_type == "5A") {
		_x = TUTORIAL5A_X;
		_y = TUTORIAL5A_Y;
	}
}