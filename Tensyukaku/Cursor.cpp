#include <DxLib.h>
#include "ResourceServer.h"
#include "Cursor.h"
#include "OutGameParticle.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ModePrologue.h"
#include "ModeTitle.h"
#include "Math.h"
#include "ExPlain.h"
#include "OverlayBlack.h"
using namespace CParInfo;
Cursor::Cursor():_State(CURSOLSTATE::NOHIT){
	Init();
	LoadSound();
};
Cursor::~Cursor() {
}

void Cursor::Init() {
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
	_Input_Flag=false;
}

void Cursor::Process(Game& g) {
	ObjectBase::Process(g);
	auto frame = _Cnt - _Action_Cnt;
	switch (_State) {
	case CURSOLSTATE::NOHIT:
		_colortype = 0;
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite��GameStart�I�u�W�F�N�g���H
			if ((*ite)->GetObjType() == OBJECTTYPE::GAMESTART)
			{
				// �J�[�\���Ƃ��̃I�u�W�F�N�g�̓����蔻����s��
				if (IsHit(*(*ite)) == true) {
					_State = CURSOLSTATE::STARTHIT;
					_colortype =3;
				}
			}
		}
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite��Explain�I�u�W�F�N�g���H
			if ((*ite)->GetObjType() == OBJECTTYPE::EXPLAIN)
			{
				// �J�[�\���Ƃ��̃I�u�W�F�N�g�̓����蔻����s��
				if (IsHit(*(*ite)) == true) {
					_State = CURSOLSTATE::EXHIT;
					_colortype = 4;
				}
			}
		}
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite��GameEnd�I�u�W�F�N�g���H
			if ((*ite)->GetObjType() == OBJECTTYPE::GAMEEND)
			{
				// �J�[�\���Ƃ��̃I�u�W�F�N�g�̓����蔻����s��
				if (IsHit(*(*ite)) == true) {
					_State = CURSOLSTATE::ENDHIT;
					_colortype =2;
				}
			}
		}
		break;
	case CURSOLSTATE::STARTHIT:
		if (g.GetTrg() & PAD_INPUT_1&&_Input_Flag ==false)
		{
			_Input_Flag =true;
			_Action_Cnt = _Cnt;
			PlaySoundMem(_Se["GameStart"],DX_PLAYTYPE_BACK, true);
			StopSoundMem(g.GetBgm()["Title"]);
			auto ol = new OverlayBlack();
			ol->SetFade(120, 120, 120, 3);
			g.GetMS()->Add(ol,1, "OverlayBlack");
		}
		if (frame == 120) {
			_Input_Flag =false;
			// �^�C�g�����[�h���폜
			g.GetMS()->Del(g.GetMS()->Get("Title"));
			// �v�����[�O���[�h��ǉ�
			auto mp = new ModePrologue();
			g.GetMS()->Add(mp, 0, "Prologue");
		}
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite��GameStart�I�u�W�F�N�g���H
			if ((*ite)->GetObjType() == OBJECTTYPE::GAMESTART)
			{
				// �J�[�\���Ƃ��̃I�u�W�F�N�g�̓����蔻����s��
				if (IsHit(*(*ite)) == false) {
					_State = CURSOLSTATE::NOHIT;
				}
			}
		}
		break;
	case CURSOLSTATE::EXHIT:
		if (g.GetTrg() & PAD_INPUT_1)
		{
			_Action_Cnt = _Cnt;
			PlaySoundMem(_Se["OtherSelect"], DX_PLAYTYPE_BACK, true);
			StopSoundMem(g.GetBgm()["Title"]);
		}
		if (frame == 5) {
			auto ex = new ExPlain();
			g.GetMS()->Add(ex, 1, "ExPlain");
			auto mt = (ModeTitle*)g.GetMS()->Get("Title");
			mt->SetStopObjProcess(true);
		}
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite��Explain�I�u�W�F�N�g���H
			if ((*ite)->GetObjType() == OBJECTTYPE::EXPLAIN)
			{
				// �J�[�\���Ƃ��̃I�u�W�F�N�g�̓����蔻����s��
				if (IsHit(*(*ite)) == false) {
					_State = CURSOLSTATE::NOHIT;
				}
			}
		}
		break;
	case CURSOLSTATE::ENDHIT:
		if (g.GetTrg() & PAD_INPUT_1) {
			PlaySoundMem(_Se["OtherSelect"], DX_PLAYTYPE_BACK, true);
			StopSoundMem(g.GetBgm()["Title"]);
			DxLib_End();		// �c�w���C�u�����g�p�̏I������
			return;
		}
		for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
		{
			// ite��GameEnd�I�u�W�F�N�g���H
			if ((*ite)->GetObjType() == OBJECTTYPE::GAMEEND)
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

void Cursor::Draw(Game& g) {
	ObjectBase::Draw(g);
}

void Cursor::LoadSound() {
	_Se["GameStart"] = ResourceServer::LoadSoundMem("se/OutGame/GameStartPush.wav");
	_Se["OtherSelect"] = ResourceServer::LoadSoundMem("se/OutGame/OtherSelectPush.wav");
}