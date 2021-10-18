#include <DxLib.h>
#include "ResourceServer.h"
#include "Cursor.h"
#include "OutGameParticle.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ModePrologue.h"
#include "ModeTitle.h"
#include "ModeCredit.h"
#include "Math.h"
#include "ModeExPlain.h"
#include "OverlayBlack.h"
using namespace CParInfo;
using namespace CuInfo;
Cursor::Cursor():_state(CURSOLSTATE::NOHIT){
   Init();
   LoadSE();
   VolumeInit();
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
   _spd = 6;
   _cnt = 0;
   _position = { 960,540 };
   _velocity_dir = { 0,0 };
   _hit_type = "NOHIT";
   _par_qty = 7;
   _input_flag=false;
   _startpush_flag = false;
   _endpush_flag = false;
}

void Cursor::Process(Game& g) {
   ObjectBase::Process(g);
   VolumeChange();
   auto frame = _cnt - _action_cnt;
   switch (_state) {
   case CURSOLSTATE::NOHIT:
      _hit_type = "NOHIT";
      _par_qty = NOHIT_PARQTY;
      break;
   case CURSOLSTATE::STARTHIT:
      _hit_type = "STARTHIT";
      _par_qty = HIT_PARQTY;
      if (g.GetTrg() & PAD_INPUT_3 && _input_flag == false)
      {
         _action_cnt = _cnt;
         _input_flag = true;
         _startpush_flag = true;
         PlaySoundMem(_se["GameStart"], DX_PLAYTYPE_BACK, true);
         StopSoundMem(g.GetBgm()["Title"]);
         auto ol = new OverlayBlack();
         ol->SetFade(120, 120, 120, 3);
         g.GetMS()->Add(ol, 1, "OverlayBlack");
      }
      if (frame == 120 && _startpush_flag == true) {
         _input_flag = false;
         // タイトルモードを削除
         g.GetMS()->Del(g.GetMS()->Get("Title"));
         // プロローグモードを追加
         auto mp = new ModePrologue();
         g.GetMS()->Add(mp, 0, "Prologue");
      }
      break;
   case CURSOLSTATE::EXHIT:
      _hit_type = "EXHIT";
      _par_qty = HIT_PARQTY;
      if (g.GetTrg() & PAD_INPUT_3)
      {
         PlaySoundMem(_se["OtherSelect"], DX_PLAYTYPE_BACK, true);
         auto ex = new ModeExPlain();
         g.GetMS()->Add(ex, 1, "ExPlain");
         auto mt = (ModeTitle*)g.GetMS()->Get("Title");
         mt->SetStopObjProcess(true);
      }
      break;
   case CURSOLSTATE::ENDHIT:
      _hit_type = "ENDHIT";
      _par_qty = HIT_PARQTY;
      if (g.GetTrg() & PAD_INPUT_3 && _input_flag == false) {
         _action_cnt = _cnt;
         _input_flag = true;
         _endpush_flag = true;
         PlaySoundMem(_se["OtherSelect"], DX_PLAYTYPE_BACK, true);
         auto ol = new OverlayBlack();
         ol->SetFade(120, 120, 120, 3);
         g.GetMS()->Add(ol, 1, "OverlayBlack");
      }
      if (frame == 120 && _endpush_flag == true) {
         DxLib_End();      // ＤＸライブラリ使用の終了処理
         return;
      }
      break;
   case CURSOLSTATE::CREDITHIT:
      _hit_type = "CREDITHIT";
      _par_qty = HIT_PARQTY;
      if (g.GetTrg() & PAD_INPUT_3 && _input_flag == false) {
         _action_cnt = _cnt;
         _input_flag = true;
         _creditpush_flag = true;
         PlaySoundMem(_se["OtherSelect"], DX_PLAYTYPE_BACK, true);
         StopSoundMem(g.GetBgm()["Title"]);
         auto ol = new OverlayBlack();
         ol->SetFade(120, 120, 120, 3);
         g.GetMS()->Add(ol, 1, "OverlayBlack");
      }
      if (frame == 120 && _creditpush_flag == true) {
         _input_flag = false;
         g.GetMS()->Del(g.GetMS()->Get("Title"));
         auto mc = new ModeCredit();
         g.GetMS()->Add(mc, 1, "Credit");
      }
      break;
   }
   //カーソルの座標から炎パーティクル発生
   for (int i = 0; i <_par_qty; i++)
   {
      std::pair<int, int> xy = std::make_pair(_x, _y);
      std::pair<double, double> dxy = std::make_pair(((rand() % CURSOR_PARTICLE1_RANDOMX1) - CURSOR_PARTICLE1_RANDOMX2) / CURSOR_PARTICLE1_RANDOMX3, ((rand() % CURSOR_PARTICLE1_RANDOMY1) - CURSOR_PARTICLE1_RANDOMY2) / CURSOR_PARTICLE1_RANDOMY3);
      auto c1 = new CursorParticle1(xy, dxy, _hit_type);
      g.GetOS()->Add(c1);
   }
   auto xbuf = g.GetXBuf();
   auto ybuf = g.GetYBuf();
   if (_input_flag == false) {
      if (g.GetKey() & PAD_INPUT_RIGHT) {
         _velocity_dir.x =1;   // (3-3)右入力あり
      }
      else if (g.GetKey() & PAD_INPUT_LEFT) {
         _velocity_dir.x = -1;  // (3-4)左入力あり
      }
      else if (g.GetKey() & PAD_INPUT_UP) {
         _velocity_dir.y = -1;  // (3-4)上入力あり
      }
      else if (g.GetKey() & PAD_INPUT_DOWN) {
         _velocity_dir.y = 1;  // (3-4)下入力あり
      }
      else {
         _velocity_dir.x = 0;   // (3-5.)左右入力なし
         _velocity_dir.y = 0;   // (3-5.)上下入力なし
      }
      if (_velocity_dir.x != 0 && _velocity_dir.y != 0) {
         // (4-5)入力あれば正規化して単位ベクトルにする
         _velocity_dir.Normalize();
      }
      if (xbuf == 0 && ybuf == 0) {
         _velocity_dir = { 0, 0 };  // 入力なし
      }
      else {
         // レバーの倒し度合いをベクトルにする
         _velocity_dir = { static_cast<float>(xbuf), static_cast<float>(ybuf) };
         // レバーの倒し度合いで速度を変える
         auto len = _velocity_dir.Length();
         auto spd = static_cast<double>(_spd);
         spd = 3 * len / 1000;
         // 正規化して単位ベクトルにする
         _velocity_dir.Normalize();
      }
      auto vd = _velocity_dir * _spd;
      auto positionX = static_cast<int>(_position.x);
      auto positionY = static_cast<int>(_position.y);
      _position += vd;
      _x = positionX;
      _y = positionY;
   }
   if (_x<= 0||_x>=SCREEN_W) {
      _x =_before_x;
   }
   if (_y <= 0 || _y >= SCREEN_H) {
      _y = _before_y;
   }
   HitJudge(g);
}

void Cursor::Draw(Game& g) {
   ObjectBase::Draw(g);
}
//効果音読み込み関数
void Cursor::LoadSE() {
   _se["GameStart"] = ResourceServer::LoadSoundMem("se/OutGame/GameStartPush.wav");
   _se["OtherSelect"] = ResourceServer::LoadSoundMem("se/OutGame/OtherSelectPush.wav");
   _se["SelectHit"] = ResourceServer::LoadSoundMem("se/OutGame/SelectHit.wav");
}

//効果音ボリューム初期値設定関数
void   Cursor::VolumeInit() {
   _vpal["GameStart"] = 255;
   _vpal["OtherSelect"] = 255;
   _vpal["SelectHit"] = 150;
}

//ボリューム変更関数
void   Cursor::VolumeChange() {
   ChangeVolumeSoundMem(_vpal["GameStart"], _se["GameStart"]);
   ChangeVolumeSoundMem(_vpal["OtherSelect"], _se["OtherSelect"]);
   ChangeVolumeSoundMem(_vpal["SelectHit"], _se["SelectHit"]);
}

void Cursor::HitJudge(Game& g) {
   //カーソルとセレクトの当たり判定
   for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
   {
      OBJECTTYPE objType = (*ite)->GetObjType();
      switch (objType) {
      case ObjectBase::OBJECTTYPE::GAMESTART:
         if (_state == CURSOLSTATE::NOHIT) {
            if (IsHit(*(*ite)) == true) {
               PlaySoundMem(_se["SelectHit"], DX_PLAYTYPE_BACK, true);
               _state = CURSOLSTATE::STARTHIT;

            }
         }
         if (_state == CURSOLSTATE::STARTHIT) {
            if (IsHit(*(*ite)) == false) {
               _state = CURSOLSTATE::NOHIT;
            }
         }
         break;
      case ObjectBase::OBJECTTYPE::EXPLAIN:
         if (_state == CURSOLSTATE::NOHIT) {
            if (IsHit(*(*ite)) == true) {
               PlaySoundMem(_se["SelectHit"], DX_PLAYTYPE_BACK, true);
               _state = CURSOLSTATE::EXHIT;
            }
         }
         if (_state == CURSOLSTATE::EXHIT) {
            if (IsHit(*(*ite)) == false) {
               _state = CURSOLSTATE::NOHIT;
            }
         }
         break;
      case ObjectBase::OBJECTTYPE::GAMEEND:
         if (_state == CURSOLSTATE::NOHIT) {
            if (IsHit(*(*ite)) == true) {
               PlaySoundMem(_se["SelectHit"], DX_PLAYTYPE_BACK, true);
               _state = CURSOLSTATE::ENDHIT;
            }
         }
         if (_state == CURSOLSTATE::ENDHIT) {
            if (IsHit(*(*ite)) == false) {
               _state = CURSOLSTATE::NOHIT;
            }
         }
         break;
      case ObjectBase::OBJECTTYPE::CREDIT:
         if (_state == CURSOLSTATE::NOHIT) {
            if (IsHit(*(*ite)) == true) {
               PlaySoundMem(_se["SelectHit"], DX_PLAYTYPE_BACK, true);
               _state = CURSOLSTATE::CREDITHIT;
            }
         }
         if (_state == CURSOLSTATE::CREDITHIT) {
            if (IsHit(*(*ite)) == false) {
               _state = CURSOLSTATE::NOHIT;
            }
         }
         break;
      }
   }
}