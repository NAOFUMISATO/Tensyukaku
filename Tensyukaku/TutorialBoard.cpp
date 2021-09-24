#include <DxLib.h>
#include "ResourceServer.h"
#include  "TutorialBoard.h"
#include "ModeTutorial.h"
#include "ModeGame.h"
#include  "Game.h"
namespace {
	constexpr auto GRAPHPOINT_X = 0;		//X位置から描画点までの差分
	constexpr auto GRAPHPOINT_Y = -180;		//Y位置から描画点までの差分
	constexpr auto POSITION_HITX = -72;		//描画点から当たり判定左上座標までの差分
	constexpr auto POSITION_HITY = -180;		//描画点から当たり判定左上座標までの差分
	constexpr auto COLLISION_WIDTH = 144;	//当たり判定横幅
	constexpr auto COLLISION_HEIGHT = 360;	//当たり判定縦幅
}
TutorialBoard::TutorialBoard(int x, int y,int num) {
	Init();
	_x = x;
	_y = y;
	_TutorialNum = num;
	_GrHandle = ResourceServer::LoadGraph("res/Gimik/TutorialBoard.png");
}
TutorialBoard::~TutorialBoard() {
};

void TutorialBoard::Init() {
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
	_Appear_Flag = false;
	_Touch_Flag = false;
#ifdef _DEBUG
	_Color = std::make_tuple(255, 100, 5);
	_Dalpha = 128;
	_Fill = true;
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
			if (IsHit(*(*ite)) == true && g.GetTrg() & PAD_INPUT_2)
			{
				auto mg = (ModeGame*)g.GetMS()->Get("Game");
				auto stopflag = mg->GetStopObjFlag();
				if (stopflag == false) {
					if (_TutorialNum == 1) {
						auto mb1 = new ModeTutorial();
						mb1->SetNum(_TutorialNum);
						g.GetMS()->Add(mb1, 3, "Tutorial1");
					}
					else if (_TutorialNum == 2) {
						auto mb2 = new ModeTutorial();
						mb2->SetNum(_TutorialNum);
						g.GetMS()->Add(mb2, 3, "Tutorial2");
					}
					else if (_TutorialNum == 3) {
						auto mb3 = new ModeTutorial();
						mb3->SetNum(_TutorialNum);
						g.GetMS()->Add(mb3, 3, "Tutorial3");
					}
					else if (_TutorialNum == 4) {
						auto mb4 = new ModeTutorial();
						mb4->SetNum(_TutorialNum);
						g.GetMS()->Add(mb4, 3, "Tutorial4");
					}
					else if (_TutorialNum == 5) {
						auto mb5 = new ModeTutorial();
						mb5->SetNum(_TutorialNum);
						g.GetMS()->Add(mb5, 3, "Tutorial5");
					}
					mg->SetStopObjProcess(true);
					mg->SetStopObjFlag(true);
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