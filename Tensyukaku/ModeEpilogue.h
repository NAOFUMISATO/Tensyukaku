#pragma once
#include "ModeBase.h"
class  ModeEpilogue :public ModeBase {
	typedef ModeBase base;
public:
	virtual bool Initialize(Game& g);
	virtual bool Terminate(Game& g);
	virtual bool Process(Game& g);
	virtual bool Draw(Game& g);

};

namespace EpiInfo {
	constexpr auto BG_FADEIN_FRAME			= 120;
	constexpr auto BG_FADEIN_SPEED			= 2;
	constexpr auto TEXT1_FADEIN_FRAME		= 120;
	constexpr auto TEXT_FADE_SPEED			= 3;
	constexpr auto TEXT_FIRST_XPOSITION		= 500;
	constexpr auto TEXT_MOVE_SPEED			 = 2;
	constexpr auto TEXT1_FADEOUT_BEGINFRAME = 180 + TEXT1_FADEIN_FRAME;
	constexpr auto TEXT1_FADEOUT_ENDFRAME	= 120 + TEXT1_FADEOUT_BEGINFRAME;
	constexpr auto TEXT2_FADEIN_BEGINFRAME	= 60 + TEXT1_FADEOUT_ENDFRAME;
	constexpr auto TEXT2_FADEIN_ENDFRAME	= 120 + TEXT2_FADEIN_BEGINFRAME;
	constexpr auto TEXT2_FADEOUT_BEGINFRAME = 450 + TEXT2_FADEIN_ENDFRAME;
	constexpr auto TEXT2_FADEOUT_ENDFRAME	= 120 + TEXT2_FADEOUT_BEGINFRAME;
	constexpr auto TEXT3_FADEIN_BEGINFRAME	= 60 + TEXT2_FADEOUT_ENDFRAME;
	constexpr auto TEXT3_FADEIN_ENDFRAME	= 120 + TEXT3_FADEIN_BEGINFRAME;
	constexpr auto TEXT3_FADEOUT_BEGINFRAME = 240 + TEXT3_FADEIN_ENDFRAME;
	constexpr auto TEXT3_FADEOUT_ENDFRAME	= 120 + TEXT3_FADEOUT_BEGINFRAME;
	constexpr auto TEXT4_FADEIN_BEGINFRAME	= 60 + TEXT3_FADEOUT_ENDFRAME;
	constexpr auto TEXT4_FADEIN_ENDFRAME	= 120 + TEXT4_FADEIN_BEGINFRAME;
	constexpr auto TEXT4_FADEOUT_BEGINFRAME = 330 + TEXT4_FADEIN_ENDFRAME;
	constexpr auto TEXT4_FADEOUT_ENDFRAME	= 120 + TEXT4_FADEOUT_BEGINFRAME;
	constexpr auto BG_FADEOUT_BEGINFRAME	= 60 + TEXT4_FADEOUT_ENDFRAME + BG_FADEIN_FRAME;
	constexpr auto BG_FADEOUT_ENDFRAME		= 60 + BG_FADEOUT_BEGINFRAME;
	constexpr auto BG_FADEOUT_SPEED		= 4;

	/*---------�e�L�X�g�̉摜�`��֌W----------*/
	constexpr auto TEXT_GRAPH_WIDTH = 300;			//1��������̉摜�T�C�Y�i���j
	constexpr auto TEXT_GRAPH_HEIGHT = 700;			//1��������̉摜�T�C�Y�i�c�j
	constexpr auto TEXT_GRAPHNAME = "res/Mode/AllEText.png";	//�摜�t�@�C����
	constexpr auto TEXT_ANIMEMAX = 4;			//�S�Ẳ摜����
	constexpr auto TEXT_WIDTHCOUNT = 4;			//���̉摜����
	constexpr auto TEXT_HEIGHTCOUNT = 1;		//�c�̉摜����
}