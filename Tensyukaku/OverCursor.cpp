#include <DxLib.h>
#include "ResourceServer.h"
#include "OverCursor.h"
#include "OutGameParticle.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ModeGame.h"
#include "ModeTitle.h"
#include "Math.h"
#include "OverlayBlack.h"
namespace {
	constexpr auto RED = 0;
	constexpr auto GREEN = 1;
	constexpr auto Blue = 2;
}
using namespace CParInfo;
OverCursor::OverCursor() :_State(CURSOLSTATE::NOHIT) {
	Init();
}
OverCursor::~OverCursor() {
};

void OverCursor::Init() {
	_x = 960;
	_y = 540;
	_gx = 0;
	_gy = -10;
	_hit_x = -10;
	_hit_y = -10;
	_hit_w = 20;
	_hit_h = 20;
	_Spd = 3;
	_Position = { 960,540 };
	_velocityDir = { 0,0 };
	_colortype = 2;
	_Cnt = 121;
	_Input_Flag = false;
}

void OverCursor::Process(Game& g) {
	ObjectBase::Process(g);
	switch (_State) {
	case CURSOLSTATE::NOHIT:
		_colortype = 5;
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite��OverRetry�I�u�W�F�N�g���H
			if ((*ite)->GetObjType() == OBJECTTYPE::OVERRETRY)
			{
				// �J�[�\���Ƃ��̃I�u�W�F�N�g�̓����蔻����s��
				if (IsHit(*(*ite)) == true) {
					_State = CURSOLSTATE::RETRYHIT;
					_colortype = GetRand(4);
				}
			}
		}
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite��OverGotitle�I�u�W�F�N�g���H
			if ((*ite)->GetObjType() == OBJECTTYPE::OVERGOTITLE)
			{
				// �J�[�\���Ƃ��̃I�u�W�F�N�g�̓����蔻����s��
				if (IsHit(*(*ite)) == true) {
					_State = CURSOLSTATE::GOTITLEHIT;
					_colortype = GetRand(4);
				}
			}
		}
		break;
	case CURSOLSTATE::RETRYHIT:
		if (g.GetTrg() & PAD_INPUT_1 && _Input_Flag == false)
		{
			_Input_Flag = true;
			_Action_Cnt = _Cnt;
			auto ol = new OverlayBlack();
			ol->FadeSetting(120, 180, 240,3 );
			g.GetMS()->Add(ol, 1, "OverlayBlack");
		}
		if (_Cnt - _Action_Cnt == 120) {
			_Input_Flag = false;
			// �Q�[���I�[�o�[���[�h���폜
			g.GetMS()->Del(g.GetMS()->Get("Gameover"));
			g.GetMS()->Del(g.GetMS()->Get("Game"));
			// �Q�[�����[�h��ǉ�
			auto mg = new ModeGame();
			g.GetMS()->Add(mg, 0, "Game");
		}
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite��Retry�I�u�W�F�N�g���H
			if ((*ite)->GetObjType() == OBJECTTYPE::OVERRETRY)
			{
				// �J�[�\���Ƃ��̃I�u�W�F�N�g�̓����蔻����s��
				if (IsHit(*(*ite)) == false) {
					_State = CURSOLSTATE::NOHIT;
				}
			}
		}
		break;
	case CURSOLSTATE::GOTITLEHIT:
		if (g.GetTrg() & PAD_INPUT_1 && _Input_Flag == false)
		{
			_Input_Flag = true;
			_Action_Cnt = _Cnt;
			auto ol = new OverlayBlack();
			ol->FadeSetting(120, 240, 360, 2);
			g.GetMS()->Add(ol, 99999, "OverlayBlack");
		}
		if (_Cnt - _Action_Cnt == 120) {
			_Input_Flag = false;
			// �Q�[���I�[�o�[���[�h���폜
			g.GetMS()->Del(g.GetMS()->Get("Gameover"));
			// �Q�[�����[�h��ǉ�
			auto mt = new ModeTitle();
			g.GetMS()->Add(mt, 0, "Title");
		}
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite��Gotitle�I�u�W�F�N�g���H
			if ((*ite)->GetObjType() == OBJECTTYPE::OVERGOTITLE)
			{
				// �J�[�\���Ƃ��̃I�u�W�F�N�g�̓����蔻����s��
				if (IsHit(*(*ite)) == false) {
					_State = CURSOLSTATE::NOHIT;
				}
			}
		}
		break;
	}
	//�J�[�\���̍��W���牊�p�[�e�B�N������
	for (int i = 0; i < CURSOR_PARTICLE1_QTY; i++)
	{
		std::pair<int, int> xy = std::make_pair(_x, _y);
		std::pair<double, double> dxy = std::make_pair(((rand() % CURSOR_PARTICLE1_RANDOMX1) - CURSOR_PARTICLE1_RANDOMX2) / CURSOR_PARTICLE1_RANDOMX3, ((rand() % CURSOR_PARTICLE1_RANDOMY1) - CURSOR_PARTICLE1_RANDOMY2) / CURSOR_PARTICLE1_RANDOMY3);
		auto c1 = new CursorParticle1(xy, dxy, _colortype);
		g.GetOS()->Add(c1);
	}
	auto xbuf = g.GetXBuf();
	auto ybuf = g.GetYBuf();
	if (_Input_Flag == false) {
		if (g.GetKey() & PAD_INPUT_RIGHT) {
			_velocityDir.x = 1;   // (3-3)�E���͂���
		}
		else if (g.GetKey() & PAD_INPUT_LEFT) {
			_velocityDir.x = -1;  // (3-4)�����͂���
		}
		else if (g.GetKey() & PAD_INPUT_UP) {
			_velocityDir.y = -1;  // (3-4)����͂���
		}
		else if (g.GetKey() & PAD_INPUT_DOWN) {
			_velocityDir.y = 1;  // (3-4)�����͂���
		}
		else {
			_velocityDir.x = 0;   // (3-5.)���E���͂Ȃ�
			_velocityDir.y = 0;   // (3-5.)�㉺���͂Ȃ�
		}
		if (_velocityDir.x != 0 && _velocityDir.y != 0) {
			// (4-5)���͂���ΐ��K�����ĒP�ʃx�N�g���ɂ���
			_velocityDir.Normalize();
		}
		if (xbuf == 0 && ybuf == 0) {
			_velocityDir = { 0, 0 };  // ���͂Ȃ�
		}
		else {
			// ���o�[�̓|���x�������x�N�g���ɂ���
			_velocityDir = { static_cast<float>(xbuf), static_cast<float>(ybuf) };
			// ���o�[�̓|���x�����ő��x��ς���
			auto len = _velocityDir.Length();
			auto spd = static_cast<double>(_Spd);
			spd = 3 * len / 1000;
			// ���K�����ĒP�ʃx�N�g���ɂ���
			_velocityDir.Normalize();
		}
		auto vd = _velocityDir * _Spd;
		auto positionX = static_cast<int>(_Position.x);
		auto positionY = static_cast<int>(_Position.y);
		_Position += vd;
		_x = positionX;
		_y = positionY;
	}
}
void OverCursor::Draw(Game& g) {
	DrawRotaGraph(_x, _y, 1.0, 0.0, _GrHandle, true, _isFlip);
	int& re = std::get<RED>(_Color);
	int& gr = std::get<GREEN>(_Color);
	int& bl = std::get<Blue>(_Color);
#ifdef _DEBUG
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Dalpha);		// �������`��w��
	DrawBox(_x + _hit_x, _y + _hit_y, _x + _hit_x + _hit_w, _y + _hit_y + _hit_h, GetColor(re, gr, bl), _Fill);	// �������̐Ԃœ����蔻��`��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// �s�����`��w��
#endif
}