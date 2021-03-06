/*****************************************************************//**
 * \file   Boss.cpp
 * \brief  ボスクラス（オブジェクトベースクラスのサブクラス）
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "ResourceServer.h"
#include "ModeEpilogue.h"
#include "OverlayBlack.h"
#include "Boss.h"
#include "BossBlood.h"
#include "Game.h"

using namespace BossInifo;

Boss::Boss(int x,int y,bool flip) {
   _x = x;
   _y = y;
   _isflip = flip;
   Init();
   LoadPicture();
   LoadSE();
   VolumeInit();
}
Boss::~Boss() {
}

void Boss::Init() {
   _sort = 12;
   _w = GRAPH_WIDTH;
   _h = GRAPH_HEIGHT;
   _gx = GRAPHPOINT_X;
   _gy = GRAPHPOINT_Y;
   _hit_x = POSITION_HITX;
   _hit_y = POSITION_HITY;
   _hit_w = COLLISION_WIDTH;
   _hit_h = COLLISION_HEIGHT;
   _alpha = 255;
   _state = BOSSSTATE::IDLE;
}

void Boss::Process(Game& g) {
   ObjectBase::Process(g);
   EventChange(g);
   VolumeChange();
   /*---状態毎の処理---*/
   switch (_state) {
   case BOSSSTATE::IDLE:
      Idle(g);
      break;
   case BOSSSTATE::EVENTA:
      BossEventA(g);
      break;
   case BOSSSTATE::EVENTB:
      BossEventB(g);
      break;
   case BOSSSTATE::DAMAGE:
      Damage(g);
      break;
   case BOSSSTATE::DEAD:
      Dead(g);
      break;
   }

}
void Boss::Draw(Game& g) {
   SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
   ObjectBase::Draw(g);
}

/*---------待機----------*/

void Boss::Idle(Game& g) {
   _grhandle = _grall["Idle"][_anime["Idle"]];
   _anime["Idle"] = 0;
}
/*---------ボスイベントA----------*/

void Boss::BossEventA(Game& g) {
   auto frame = _cnt - _action_cnt;
   if (frame >= 0 && 120 >= frame) {
      _grhandle = _grall["Idle"][_anime["Idle"]];
      _anime["Idle"] = 0;
   }
   if (frame == 60) {
      _isflip = false;
   }
   if (frame == 120) {
      _isflip = true;
   }
   if (frame > 120&&360>frame){
      _grhandle = _grall["Move"][_anime["Move"]];
      _anime["Move"] = (_cnt / ANIMESPEED_WALK) % MOVE_ANIMEMAX;
      _x -= 4;
   }
   if (frame ==360) {
      g.GetOS()->Del(this);
   }
}
/*---------ボスイベントB----------*/

void Boss::BossEventB(Game& g) {
   auto frame = _cnt - _action_cnt;
   _spd = 3;
   _grhandle = _grall["Idle"][_anime["Idle"]];
   _anime["Idle"] = 0;
   if (frame == 30) {
      _isflip = true;
   }
   if (frame >= 90 && 250 > frame) {
      _grhandle = _grall["Back"][_anime["Back"]];
      _anime["Back"] = (_cnt / ANIMESPEED_BACK) % BACK_ANIMEMAX;
      _x += _spd;
   }
   if (frame >= 250) {
      _grhandle = _grall["Idle"][_anime["Idle"]];
      _anime["Idle"] = 0;
   }
   if (frame == 270) {
      _isflip = false;
   }
   if (frame == 290) {
      _isflip = true;
   }
   if (frame == 320) {
      PlaySoundMem(_se["Dead01V"], DX_PLAYTYPE_BACK, true);
   }
   if (frame > 320) {
      for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
      {
         // iteはプレイヤーの特殊攻撃オブジェクトか？
         if ((*ite)->GetObjType() == OBJECTTYPE::SPECIAL)
         {
            // 敵とプレイヤーの特殊攻撃オブジェクトの当たり判定を行う
            if (IsHit(*(*ite)) == true) {
               (*ite)->Delete(g);
               _action_cnt = _cnt;
               PlaySoundMem(_se["Dead03V"], DX_PLAYTYPE_BACK, true);
               _state = BOSSSTATE::DAMAGE;
            }
         }
      }
   }
}
/*--------被ダメ----------*/

void Boss::Damage(Game& g) {
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["Damage"][_anime["Damage"]];
   _anime["Damage"] = 0;
   if (frame == 1) {
      auto bloodtype = 0;
      auto bb = new BossBlood(_x + _gx+100, _y + _gy, bloodtype);
      g.GetOS()->Add(bb);
   }
   if (frame == DAMAGE_ALLFRAME) {
      _action_cnt = _cnt;
      PlaySoundMem(_se["Dead02V"], DX_PLAYTYPE_BACK, true);
      _state = BOSSSTATE::DEAD;
      auto bloodtype = 1;
      auto bb = new BossBlood(_x + _gx, _y + _gy, bloodtype);
      g.GetOS()->Add(bb);
   }
}
/*----------死亡--------*/

void Boss::Dead(Game& g) {
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["Dead"][_anime["Dead"]];
   if (frame < DEAD_ANIMEFRAME) {
      _anime["Dead"] = ((frame) / ANIMESPEED_DEAD) % DEAD_ANIMEMAX;
   }
   auto modechangeframe = 120;
   if (frame == DEAD_ALLFRAME) {
      StopSoundMem(g.GetBgm()["Main"]);
      auto ol = new OverlayBlack();
      ol->SetFade(modechangeframe, 240, 300, 4);
      g.GetMS()->Add(ol, 2, "OverlayBlack");
   }
   
   if (frame == DEAD_ALLFRAME + modechangeframe) {
      g.GetMS()->Del(g.GetMS()->Get("Game"));
      auto me = new ModeEpilogue();
      g.GetMS()->Add(me, 0, "Epilogue");
   }
}

void Boss::EventChange(Game& g) {
   if (_bossevent_a_flag == true) {
      _state = BOSSSTATE::EVENTA;
      _action_cnt = _cnt;
      _bossevent_a_flag = false;
   }
   if (_bossevent_b_flag == true) {
      _state = BOSSSTATE::EVENTB;
      _action_cnt = _cnt;
      _bossevent_b_flag = false;
   }
}

void Boss::LoadPicture() {
   _grall["Idle"].resize(IDLE_ANIMEMAX);
   ResourceServer::LoadDivGraph(IDLE_GRAPHNAME, IDLE_ANIMEMAX, IDLE_WIDTHCOUNT, IDLE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Idle"].data());
   _grall["Move"].resize(MOVE_ANIMEMAX);
   ResourceServer::LoadDivGraph(MOVE_GRAPHNAME, MOVE_ANIMEMAX, MOVE_WIDTHCOUNT, MOVE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Move"].data());
   _grall["Back"].resize(BACK_ANIMEMAX);
   ResourceServer::LoadDivGraph(BACK_GRAPHNAME, BACK_ANIMEMAX, BACK_WIDTHCOUNT, BACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Back"].data());
   _grall["Damage"].resize(DAMAGE_ANIMEMAX);
   ResourceServer::LoadDivGraph(DAMAGE_GRAPHNAME, DAMAGE_ANIMEMAX, DAMAGE_WIDTHCOUNT, DAMAGE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Damage"].data());
   _grall["Dead"].resize(DEAD_ANIMEMAX);
   ResourceServer::LoadDivGraph(DEAD_GRAPHNAME, DEAD_ANIMEMAX, DEAD_WIDTHCOUNT, DEAD_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Dead"].data());
}

void Boss::LoadSE() {
   _se["Dead01V"] = ResourceServer::LoadSoundMem("se/Voice/BossDead01.wav");
   _se["Dead02V"] = ResourceServer::LoadSoundMem("se/Voice/BossDead02.wav");
   _se["Dead03V"] = ResourceServer::LoadSoundMem("se/Voice/Dead03.wav");
}

void Boss::VolumeInit() {
   _vpal["Dead01V"] = 255;
   _vpal["Dead02V"] = 255;
   _vpal["Dead03V"] = 255;
}

void Boss::VolumeChange() {
   ChangeVolumeSoundMem(_vpal["Dead01V"], _se["Dead01V"]);
   ChangeVolumeSoundMem(_vpal["Dead02V"], _se["Dead02V"]);
   ChangeVolumeSoundMem(_vpal["Dead03V"], _se["Dead03V"]);
}