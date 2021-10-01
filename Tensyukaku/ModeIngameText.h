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
	constexpr auto GRAPH_WIDTH = 1120;			//1��������̉摜�T�C�Y�i���j
	constexpr auto GRAPH_HEIGHT = 265;			//1��������̉摜�T�C�Y�i�c)
	constexpr auto FADEIN_FRAME = 60;				//�t�F�[�h�C���t���[��
	constexpr auto FADEOUT_FRAME = 180;			// �t�F�[�h�A�E�g�t���[��
	constexpr auto FADE_SPEED = 4;			// �t�F�[�h�A�E�g�t���[��

}