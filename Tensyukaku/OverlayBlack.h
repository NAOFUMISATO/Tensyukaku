#pragma once
#include "ModeBase.h"

class OverlayBlack : public ModeBase
{
	typedef ModeBase base;
public:
	virtual bool Initialize(Game& g);
	virtual bool Terminate(Game& g);
	virtual bool Process(Game& g);
	virtual bool Draw(Game& g);
	void	SetFade(int fadeoutframe,int fadeinbeginframe,int fadeinendframe, int fadespeed);
	int	GetPal() { return _Pal; }
private:
	int	_Fadeoutframe;
	int	_FadeinBeginframe;
	int	_FadeinEndframe;
};