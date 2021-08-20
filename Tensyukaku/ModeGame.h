#pragma once
#include	"ModeBase.h"
#include	"BackGround.h"
#include	"Player.h"



class ModeGame : public ModeBase
{
	typedef ModeBase base;
public:
	virtual bool Initialize(Game& g);
	virtual bool Terminate(Game& g);
	virtual bool Process(Game& g);
	virtual bool Draw(Game& g);


private:
	BackGround	_bg;
	// �I�u�W�F�N�g�������X�g�b�v����
	bool	_stopObjProcess;

	// BGM�p
	int		_bgm;

};