#pragma once
#include "ModeBase.h"

class  ModeIngameText :public ModeBase {
	typedef ModeBase base;
public:
	virtual bool Initialize(Game& g);
	virtual bool Terminate(Game& g);
	virtual bool Process(Game& g);
	virtual bool Draw(Game& g);
	int	GetPal() { return _pal; }
	void SetType(std::string texttype) { _text_type = texttype; }
private:
	void LoadTextGraph();

	std::string	_text_type;
	int		_fadein_frame;
	int		_fadeout_frame;
	int		_fade_speed;
};

namespace ITInfo {
	constexpr auto GRAPH_WIDTH = 1120;			//1枚当たりの画像サイズ（横）
	constexpr auto GRAPH_HEIGHT = 265;			//1枚当たりの画像サイズ（縦)
	constexpr auto FADEIN_FRAME = 60;				//フェードインフレーム
	constexpr auto FADEOUT_FRAME = 180;			// フェードアウトフレーム
	constexpr auto FADE_SPEED = 4;			// フェードアウトフレーム

}