#pragma once
#include "ModeBase.h"
class  ModePrologue :public ModeBase {
	typedef ModeBase base;
public:
	virtual bool Initialize(Game& g);
	virtual bool Terminate(Game& g);
	virtual bool Process(Game& g);
	virtual bool Draw(Game& g);
private:
	int		_GraphNo;
};

namespace ProInfo {
	/*----------各フェードフレーム関係----------*/
	constexpr auto BG1_FADEIN_FRAME = 120;
	constexpr auto BG1_FADEIN_SPEED = 2;
	constexpr auto TEXT1_FADEIN_FRAME = 60;
	constexpr auto TEXT_FADE_SPEED = 4;
	constexpr auto TEXT1_FADEOUT_BEGINFRAME = 300 + TEXT1_FADEIN_FRAME;
	constexpr auto TEXT1_FADEOUT_ENDFRAME	= 60 + TEXT1_FADEOUT_BEGINFRAME;
	constexpr auto TEXT2_FADEIN_BEGINFRAME	= 60 + TEXT1_FADEOUT_ENDFRAME;
	constexpr auto TEXT2_FADEIN_ENDFRAME	= 60 + TEXT2_FADEIN_BEGINFRAME;
	constexpr auto TEXT2_FADEOUT_BEGINFRAME = 300+ TEXT2_FADEIN_ENDFRAME;
	constexpr auto TEXT2_FADEOUT_ENDFRAME	= 60 + TEXT2_FADEOUT_BEGINFRAME;
	constexpr auto TEXT3_FADEIN_BEGINFRAME	= 60 + TEXT2_FADEOUT_ENDFRAME;
	constexpr auto TEXT3_FADEIN_ENDFRAME	= 60 + TEXT3_FADEIN_BEGINFRAME;
	constexpr auto TEXT3_FADEOUT_BEGINFRAME = 300 + TEXT3_FADEIN_ENDFRAME;
	constexpr auto TEXT3_FADEOUT_ENDFRAME	= 60 + TEXT3_FADEOUT_BEGINFRAME;
	constexpr auto TEXT4_FADEIN_BEGINFRAME	= 60 + TEXT3_FADEOUT_ENDFRAME;
	constexpr auto TEXT4_FADEIN_ENDFRAME	= 60 + TEXT4_FADEIN_BEGINFRAME;
	constexpr auto TEXT4_FADEOUT_BEGINFRAME = 300 + TEXT4_FADEIN_ENDFRAME;
	constexpr auto TEXT4_FADEOUT_ENDFRAME	= 60 + TEXT4_FADEOUT_BEGINFRAME;
	constexpr auto BG1_FADEOUT_BEGINFRAME	= 60 + TEXT4_FADEOUT_ENDFRAME + BG1_FADEIN_FRAME;
	constexpr auto BG1_FADEOUT_ENDFRAME		= 60 + BG1_FADEOUT_BEGINFRAME;
	constexpr auto BG1_FADEOUT_SPEED = 4;
	constexpr auto BG2_FADEIN_BEGINFRAME	= 60 + BG1_FADEOUT_ENDFRAME;
	constexpr auto BG2_FADEIN_ENDFRAME		= 60 + BG2_FADEIN_BEGINFRAME;
	constexpr auto BG2_FADEIN_SPEED = 4;
	constexpr auto TEXT5_FADEIN_BEGINFRAME	= 60 + BG2_FADEIN_ENDFRAME- BG1_FADEIN_FRAME;
	constexpr auto TEXT5_FADEIN_ENDFRAME	= 60 + TEXT5_FADEIN_BEGINFRAME;
	constexpr auto TEXT5_FADEOUT_BEGINFRAME = 300 + TEXT5_FADEIN_ENDFRAME;
	constexpr auto TEXT5_FADEOUT_ENDFRAME	= 60 + TEXT5_FADEOUT_BEGINFRAME;
	constexpr auto PROLOGUE_FADEOUT_FRAME = 120 + TEXT5_FADEOUT_ENDFRAME;
	/*-----------背景移動フレーム関係----------*/
	constexpr auto BG_XMOVE_FRAME = 400+BG1_FADEIN_FRAME;
	constexpr auto BG_YMOVE_FRAME = 1120+ BG1_FADEIN_FRAME;
	constexpr auto BG_XMOVE_SPEED = 6;
	constexpr auto BG_YMOVE_SPEED = 4;
	/*---------背景&テキストの画像描画関係----------*/
	constexpr auto BG_GRAPH_WIDTH = 3840;			//1枚当たりの画像サイズ（横）
	constexpr auto BG_GRAPH_HEIGHT = 2160;			//1枚当たりの画像サイズ（縦）
	constexpr auto BG_GRAPHNAME = "res/Mode/PrologueAll.png";	//画像ファイル名
	constexpr auto BG_ANIMEMAX = 2;					//全ての画像枚数
	constexpr auto BG_WIDTHCOUNT = 2;				//横の画像枚数
	constexpr auto BG_HEIGHTCOUNT = 1;				//縦の画像枚数

	constexpr auto TEXT_GRAPH_WIDTH = 300;			//1枚当たりの画像サイズ（横）
	constexpr auto TEXT_GRAPH_HEIGHT = 700;			//1枚当たりの画像サイズ（縦）
	constexpr auto TEXT_GRAPHNAME = "res/Mode/AllPText.png";	//画像ファイル名
	constexpr auto TEXT_ANIMEMAX = 5;			//全ての画像枚数
	constexpr auto TEXT_WIDTHCOUNT = 5;			//横の画像枚数
	constexpr auto TEXT_HEIGHTCOUNT = 1;		//縦の画像枚数
}