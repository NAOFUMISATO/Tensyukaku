/*****************************************************************//**
 * \file   ModeBase.cpp
 * \brief  モード用ベースクラス
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ModeBase.h"

namespace{
	constexpr auto RED = 0;
	constexpr auto GREEN = 1;
	constexpr auto BLUE = 2;
}
//コンストラクタ
ModeBase::ModeBase() {
	//初期化（モードーサーバー用）
	_sz_name = "";
	_uid = 1;
	_layer = 0;

	_cnt_mode = 0;
	_tm_mode = 0;
	_tm_step = 0;
	_tm_mode_base = 0;
	_tm_pause_base = 0;
	_tm_pause_step = 0;
	_tm_old_frame = 0;
}
//デストラクタ
ModeBase::~ModeBase() {
}

/*-----初期化-----*/
bool	ModeBase::Initialize(Game& g) {
	_grhandle = -1;					//画像ハンドル初期化
	_cnt = 0;								//動作カウンタ0で初期化
	_pal = 255;							//透明度の初期化
	_trans_flag = false;			//背景透過フラグを偽で初期化
	_drg = std::make_pair(1.0, 0.0);						//DrawRotaGraph用、拡大率及び角度の初期化
	_rgb = std::make_tuple(255,255,255);			//SetDrawBright用、RGBの初期化
	return true;
}
/*-----終了------*/
bool	ModeBase::Terminate(Game& g) {
	return true;
}
/*-----更新-----*/
bool	ModeBase::Process(Game& g){
	_cnt++;						//毎フレーム１ずつ増加
	return	true;
}
/*-----描画-----*/
bool	ModeBase::Draw(Game& g)
{
	auto scale = _drg.first;
	auto angle = _drg.second;
	int& re = std::get<RED>(_rgb);
	int& gr = std::get<GREEN>(_rgb);
	int& bl = std::get<BLUE>(_rgb);
	SetDrawBright(re,gr,bl);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _pal);
	DrawRotaGraph(_x, _y, scale, angle,_grhandle, _trans_flag,FALSE);
	SetDrawBright(255, 255, 255);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	return	true;
}


// 時間経過をさせる
void ModeBase::StepTime(unsigned long tmNow) {
	// 時間経過処理
	if (_cnt_mode == 0) {
		_tm_mode = 0;
		_tm_step = 0;
		_tm_mode_base = tmNow;
		_tm_pause_base = 0;
		_tm_pause_step = 0;
	}
	else {
		_tm_mode = tmNow - _tm_mode_base + _tm_pause_step;
		_tm_step = tmNow - _tm_old_frame;
	}
	_tm_old_frame = tmNow;
}

// カウントを進める
void ModeBase::StepCount() {
	_cnt_mode++;
}
