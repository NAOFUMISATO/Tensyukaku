/*****************************************************************//**
 * \file   PlayerMotion.cpp
 * \brief  プレイヤーの状態関数
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#include <DxLib.h>
#include "Player.h"
#include "Game.h"
#include "MiddleAttackCollision.h"
#include "LowAttackCollision.h"
#include "KickCollision.h"
#include "IaiCollision.h"
#include "SpecialCollision.h"
#include "OverlayBlack.h"
#include "ModeGameover.h"
#include "ModeGame.h"
#include "ModeBossBefore.h"
#include "Stair.h"
#include "MiddleAttackParticle1.h"
#include "MiddleAttackParticle2.h"
#include "LowAttackParticle1.h"
#include "LowAttackParticle2.h"
#include "IaiParticle1.h"
#include "IaiParticle2.h"
#include "IaiParticle3.h"
#include "SwayParticle.h"

using namespace PInfo;
using namespace MP1Info;
using namespace MP2Info;
using namespace LP1Info;
using namespace LP2Info;
using namespace IP1Info;
using namespace IP2Info;
using namespace IP3Info;
using namespace SPInfo;
using namespace StInfo;
/*----------出現----------*/

void Player::Appear(Game& g) {
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["Appear"][_anime["Appear"]];
   _anime["Appear"] = 0;
   //オーバーレイブラックモードの透明度が一定以下なら抜刀状態へ移行
   auto ob = (OverlayBlack*)g.GetMS()->Get("OverlayBlack");
   auto Pal = ob->GetPal();
   if (Pal <= 100) {
      _action_cnt = _cnt;
      _state = PLAYERSTATE::SWORDOUT;
   }
}

/*----------抜刀----------*/

void Player::Swordout(Game& g) {
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["Swordout"][_anime["Swordout"]];
   _anime["Swordout"] = ((frame) / ANIMESPEED_SWORDOUT) % SWORDOUT_ANIMEMAX;
   //BGM再生（ボスステージのチェックポイントを踏んでいるならボスのBGM、そうでないならメインステージのBGM再生）
   auto vpal = g.GetVpal();
   if (frame == 1) {
      vpal["Main"] = 0;
      if (g.GetCPointFlag()["11A"] == true) {
         PlaySoundMem(g.GetBgm()["Boss"], DX_PLAYTYPE_LOOP, true);
      }
      else {
         PlaySoundMem(g.GetBgm()["Main"], DX_PLAYTYPE_LOOP, true);
      }
   }
   //音源のフェードイン（メインステージのみ）
   if (frame < SWORDOUT_ANIMEFRAME && vpal["Main"] < 120) {
      vpal["Main"] += 2;
      g.SetVpal(vpal);
   }
   //アニメフレーム経ったなら待機状態へ移行
   if (frame >= SWORDOUT_ANIMEFRAME) {
      _action_cnt = _cnt;
      _state = PLAYERSTATE::IDLE;
   }
}
/*----------待機----------*/

void Player::Idle(Game& g) {
   _grhandle = _grall["Idle"][_anime["Idle"]];
   _anime["Idle"] = (_cnt / ANIMESPEED_IDLE) % IDLE_ANIMEMAX;
   //6ボタン押下で居合状態へ移行
   if (g.GetTrg() & PAD_INPUT_6 && _iai_gauge == IAI_MAX) {
      _state = PLAYERSTATE::IAI;
      _action_cnt = _cnt;
      //SE
      PlaySoundMem(_se["Iai"], DX_PLAYTYPE_BACK, true);
   }
   //5ボタン押下でスウェイ状態へ移行
   if (g.GetTrg() & PAD_INPUT_5) {
      _state = PLAYERSTATE::SWAY;
      //SE
      PlaySoundMem(_se["Sway"], DX_PLAYTYPE_BACK, true);
      _action_cnt = _cnt;
   }
   //4ボタン押下で中段攻撃状態へ移行
   if (g.GetTrg() & PAD_INPUT_4) {
      _state = PLAYERSTATE::MIDDLEATTACK;
      _action_cnt = _cnt;
   }
   //3ボタン押下で下段攻撃状態へ移行
   if (g.GetTrg() & PAD_INPUT_3) {
      _state = PLAYERSTATE::LOWATTACK;
      _action_cnt = _cnt;
   }
   //1ボタン押下で蹴り状態へ移行
   if (g.GetTrg() & PAD_INPUT_1) {
      _state = PLAYERSTATE::KICK;
      _action_cnt = _cnt;
   }
   //左スティック左右入力で移動状態へ移行
   if (g.GetKey() & PAD_INPUT_LEFT || g.GetKey() & PAD_INPUT_RIGHT) {
      _state = PLAYERSTATE::MOVE;
      _action_cnt = _cnt;
   }
   //左スティック上下入力で移動状態へ移行（デバッグ用）
#ifdef _DEBUG
   if (g.GetKey() & PAD_INPUT_UP && g.GetKey() & PAD_INPUT_7 || g.GetKey() & PAD_INPUT_DOWN && g.GetKey() & PAD_INPUT_7)
   {
      _state = PLAYERSTATE::MOVE;
      _action_cnt = _cnt;
   }
#endif
}
/*----------移動----------*/

void Player::Move(Game& g) {
   _grhandle = _grall["Move"][_anime["Move"]];
   _anime["Move"] = (_cnt / _move_animespeed) % MOVE_ANIMEMAX;
   //6ボタン押下で居合状態へ移行
   if (g.GetTrg() & PAD_INPUT_6 && _iai_gauge == IAI_MAX) {
      _state = PLAYERSTATE::IAI;
      _action_cnt = _cnt;
      //SE
      PlaySoundMem(_se["Iai"], DX_PLAYTYPE_BACK, true);
   }
   //5ボタン押下でスウェイ状態へ移行
   else if (g.GetTrg() & PAD_INPUT_5) {
      _state = PLAYERSTATE::SWAY;
      //SE
      PlaySoundMem(_se["Sway"], DX_PLAYTYPE_BACK, true);
      _action_cnt = _cnt;
   }
   //4ボタン押下で中段攻撃状態へ移行
   else if (g.GetTrg() & PAD_INPUT_4) {
      _state = PLAYERSTATE::MIDDLEATTACK;
      _action_cnt = _cnt;
   }
   //3ボタン押下で下段攻撃状態へ移行
   else if (g.GetTrg() & PAD_INPUT_3) {
      _state = PLAYERSTATE::LOWATTACK;
      _action_cnt = _cnt;
   }
   //1ボタン押下で蹴り状態へ移行
   else if (g.GetTrg() & PAD_INPUT_1) {
      _state = PLAYERSTATE::KICK;
      _action_cnt = _cnt;
   }
   //左スティック左右入力で移動
   else if (g.GetKey() & PAD_INPUT_LEFT)
   {
      _x -= _spd;
      g.GetChip()->IsHit(*this, -1, 0);
      _isflip = false;

   }
   else if (g.GetKey() & PAD_INPUT_RIGHT)
   {
      _x += _spd;
      g.GetChip()->IsHit(*this, 1, 0);
      _isflip = true;

   }
   //左スティック上下入力で移動（デバッグ用）
#ifdef _DEBUG
   else if (g.GetKey() & PAD_INPUT_UP && g.GetKey() & PAD_INPUT_7)
   {
      _y -= _spd+20;
      _isflip = true;
   }
   else if (g.GetKey() & PAD_INPUT_DOWN && g.GetKey() & PAD_INPUT_7)
   {
      _y += _spd + 20;
      _isflip = true;
   }
#endif
   //入力がないなら待機状態へ移行
   else {
      _state = PLAYERSTATE::IDLE;
   }
}
/*----------中段攻撃----------*/

void Player::MidAttack(Game& g) {
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["MiddleAttack"][_anime["MiddleAttack"]];
   _anime["MiddleAttack"] = ((frame) / ANIMESPEED_MIDDLEATTACK) % MIDDLEATTACK_ANIMEMAX;
   //踏み込み処理（一定フレーム以下なら向いている方向にX座標移動）
   if (frame < MIDDLEATTACK_BEGINFRAME) {
      if (_isflip == false) {
         _x -= 10;
         g.GetChip()->IsHit(*this, -1, 0);
      }
      if (_isflip == true) {
         _x += 10;
         g.GetChip()->IsHit(*this, 1, 0);
      }
   }
   if (frame == MIDDLEATTACK_BEGINFRAME) {
      //SE
      PlaySoundMem(_se["MiddleAttack"], DX_PLAYTYPE_BACK, true);
      if (_isflip == false) {
         //中段攻撃判定オブジェクトの生成
         auto mac = new MiddleAttackCollision(_x + _hit_x - MIDDLEATTACK_WIDTH, _y - _hit_h);
         // オブジェクトサーバ-に中段攻撃判定オブジェクトを追加
         g.GetOS()->Add(mac);
         //パーティクル1
         for (int i = 0; i < MIDDLEATTACK_PARTICLE1_QTY; i++)
         {
            std::pair<int, int> xy = std::make_pair(_x, _y);
            std::pair<double, double> dxy = std::make_pair(((rand() % MIDDLEATTACK_PARTICLE1_RANDOMX1) - MIDDLEATTACK_PARTICLE1_RANDOMX2) / MIDDLEATTACK_PARTICLE1_RANDOMX3, ((rand() % MIDDLEATTACK_PARTICLE1_RANDOMY1) - MIDDLEATTACK_PARTICLE1_RANDOMY2) / MIDDLEATTACK_PARTICLE1_RANDOMY3);
            auto m1 = new MiddleAttackParticle1(xy, dxy, false);
            g.GetOS()->Add(m1);
         }
         //パーティクル2
         for (int i = 0; i < MIDDLEATTACK_PARTICLE2_QTY; i++)
         {
            std::pair<int, int> xy = std::make_pair(_x, _y);
            std::pair<double, double> dxy = std::make_pair(((rand() % MIDDLEATTACK_PARTICLE2_RANDOMX1) - MIDDLEATTACK_PARTICLE2_RANDOMX2) / MIDDLEATTACK_PARTICLE2_RANDOMX3, ((rand() % MIDDLEATTACK_PARTICLE2_RANDOMY1) - MIDDLEATTACK_PARTICLE2_RANDOMY2) / MIDDLEATTACK_PARTICLE2_RANDOMY3);
            auto m2 = new MiddleAttackParticle2(xy, dxy, false);
            g.GetOS()->Add(m2);
         }
      };
      if (_isflip == true) {
         //中段攻撃判定オブジェクトの生成
         auto mac = new MiddleAttackCollision(_x - _hit_x, _y - _hit_h);
         // オブジェクトサーバ-に中段攻撃判定オブジェクトを追加
         g.GetOS()->Add(mac);
         //パーティクル1
         for (int i = 0; i < MIDDLEATTACK_PARTICLE1_QTY; i++)
         {
            std::pair<int, int> xy = std::make_pair(_x, _y);
            std::pair<double, double> dxy = std::make_pair(((rand() % MIDDLEATTACK_PARTICLE1_RANDOMX1) - MIDDLEATTACK_PARTICLE1_RANDOMX2) / MIDDLEATTACK_PARTICLE1_RANDOMX3, ((rand() % MIDDLEATTACK_PARTICLE1_RANDOMY1) - MIDDLEATTACK_PARTICLE1_RANDOMY2) / MIDDLEATTACK_PARTICLE1_RANDOMY3);
            auto m1 = new MiddleAttackParticle1(xy, dxy, true);
            g.GetOS()->Add(m1);
         }
         //パーティクル2
         for (int i = 0; i < MIDDLEATTACK_PARTICLE2_QTY; i++)
         {
            std::pair<int, int> xy = std::make_pair(_x, _y);
            std::pair<double, double> dxy = std::make_pair(((rand() % MIDDLEATTACK_PARTICLE2_RANDOMX1) - MIDDLEATTACK_PARTICLE2_RANDOMX2) / MIDDLEATTACK_PARTICLE2_RANDOMX3, ((rand() % MIDDLEATTACK_PARTICLE2_RANDOMY1) - MIDDLEATTACK_PARTICLE2_RANDOMY2) / MIDDLEATTACK_PARTICLE2_RANDOMY3);
            auto m2 = new MiddleAttackParticle2(xy, dxy, true);
            g.GetOS()->Add(m2);
         }
      }
   }
   //全フレーム経ったなら待機状態へ移行
   if (frame == MIDDLEATTACK_ALLFRAME) {
      _state = PLAYERSTATE::IDLE;
   }
   
}
/*----------下段攻撃----------*/

void Player::LowAttack(Game& g) {
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["LowAttack"][_anime["LowAttack"]];
   _anime["LowAttack"] = ((frame) / ANIMESPEED_LOWATTACK) % LOWATTACK_ANIMEMAX;
   if (frame == LOWATTACK_BEGINFRAME) {
      //SE
      PlaySoundMem(_se["LowAttack"], DX_PLAYTYPE_BACK, true);
      if (_isflip == false) {
         //下段攻撃判定オブジェクトの生成
         auto lac = new LowAttackCollision(_x + _hit_x - LOWATTACK_WIDTH, _y - LOWATTACK_HEIGHT);
         // オブジェクトサーバ-に下段攻撃判定オブジェクトを追加
         g.GetOS()->Add(lac);
         //パーティクル1
         for (int i = 0; i < LOWATTACK_PARTICLE1_QTY; i++)
         {
            std::pair<int, int> xy = std::make_pair(_x, _y);
            std::pair<double, double> dxy = std::make_pair(((rand() % LOWATTACK_PARTICLE1_RANDOMX1) - LOWATTACK_PARTICLE1_RANDOMX2) / LOWATTACK_PARTICLE1_RANDOMX3, ((rand() % -LOWATTACK_PARTICLE1_RANDOMY1) - LOWATTACK_PARTICLE1_RANDOMY2) / LOWATTACK_PARTICLE1_RANDOMY3);
            auto l1 = new LowAttackParticle1(xy, dxy,false);
            g.GetOS()->Add(l1);
         }
         //パーティクル2
         for (int i = 0; i < LOWATTACK_PARTICLE2_QTY; i++)
         {
            std::pair<int, int> xy = std::make_pair(_x, _y);
            std::pair<double, double> dxy = std::make_pair(((rand() % LOWATTACK_PARTICLE2_RANDOMX1) - LOWATTACK_PARTICLE2_RANDOMX2) / LOWATTACK_PARTICLE2_RANDOMX3, ((rand() % LOWATTACK_PARTICLE2_RANDOMY1) - LOWATTACK_PARTICLE2_RANDOMY2) / LOWATTACK_PARTICLE2_RANDOMY3);
            auto l2 = new LowAttackParticle2(xy, dxy,false);
            g.GetOS()->Add(l2);
         }
      };
      if (_isflip == true) {
         //下段攻撃判定オブジェクトの生成
         auto lac = new LowAttackCollision(_x - _hit_x, _y - LOWATTACK_HEIGHT);
         // オブジェクトサーバ-に下段攻撃判定オブジェクトを追加
         g.GetOS()->Add(lac);
         //パーティクル1
         for (int i = 0; i < LOWATTACK_PARTICLE1_QTY; i++)
         {
            std::pair<int, int> xy = std::make_pair(_x, _y);
            std::pair<double, double> dxy = std::make_pair(((rand() % LOWATTACK_PARTICLE1_RANDOMX1) - LOWATTACK_PARTICLE1_RANDOMX2) / LOWATTACK_PARTICLE1_RANDOMX3, ((rand() % -LOWATTACK_PARTICLE1_RANDOMY1) - LOWATTACK_PARTICLE1_RANDOMY2) / LOWATTACK_PARTICLE1_RANDOMY3);
            auto l1 = new LowAttackParticle1(xy, dxy,true);
            g.GetOS()->Add(l1);
         }
         //パーティクル2
         for (int i = 0; i < LOWATTACK_PARTICLE2_QTY; i++)
         {
            std::pair<int, int> xy = std::make_pair(_x, _y);
            std::pair<double, double> dxy = std::make_pair(((rand() % LOWATTACK_PARTICLE2_RANDOMX1) - LOWATTACK_PARTICLE2_RANDOMX2) / LOWATTACK_PARTICLE2_RANDOMX3, ((rand() % LOWATTACK_PARTICLE2_RANDOMY1) - LOWATTACK_PARTICLE2_RANDOMY2) / LOWATTACK_PARTICLE2_RANDOMY3);
            auto l2 = new LowAttackParticle2(xy, dxy,true);
            g.GetOS()->Add(l2);
         }
      }
   }
   //全フレーム経ったなら待機状態へ移行
   if (frame == LOWATTACK_ALLFRAME) {
      _state = PLAYERSTATE::IDLE;
   }
}

/*----------蹴り----------*/

void Player::Kick(Game& g) {
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["Kick"][_anime["Kick"]];
   _anime["Kick"] = ((frame) / ANIMESPEED_KICK) % KICK_ANIMEMAX;
   if (frame == KICK_BEGINFRAME) {      
      //SE
      PlaySoundMem(_se["Kick"], DX_PLAYTYPE_BACK, true);
      if (_isflip == false) {
         //蹴り判定オブジェクトの生成
         auto kic = new KickCollision(_x + _hit_x - KICK_WIDTH, _y - _hit_h / 2);
         // オブジェクトサーバ-に蹴り判定オブジェクトを追加
         g.GetOS()->Add(kic);
      };
      if (_isflip == true) {
         //蹴り判定オブジェクトの生成
         auto kic = new KickCollision(_x - _hit_x, _y - _hit_h / 2);
         // オブジェクトサーバ-に蹴り判定オブジェクトを追加
         g.GetOS()->Add(kic);
      }
   }
   //全フレーム経ったなら待機状態へ移行
   if (frame == KICK_ALLFRAME) {
      _state = PLAYERSTATE::IDLE;
   }
}

/*----------居合----------*/

void Player::Iai(Game& g) {
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["Iai"][_anime["Iai"]];
   if (frame < IAI_ANIMEFRAME) {
      _anime["Iai"] = ((frame) / ANIMESPEED_IAI) % IAI_ANIMEMAX;
   }
   if (frame >= IAI_BEGINFRAME && IAI_ALLFRAME - 15 >= frame) {
      //特定のモーション中に当たり判定を行わないフラグをTRUEにする
      _nohit_flag = true;
      //居合時に向いている方向に前進する処理
      if (_isflip == false) {
         _x -= IAI_MOVEMENT;
         g.GetChip()->IsHit(*this, -1, 0);
      }
      if (_isflip == true) {
         _x += IAI_MOVEMENT;
         g.GetChip()->IsHit(*this, 1, 0);
      }
   }
   //特定のモーション中でないなら当たり判定を行わないフラグをFALSEにする
   else { _nohit_flag = false; }
   //居合時の納刀パーティクル
   if (frame == IAI_BEGINFRAME - 10) {
      if (_isflip == false) {
         //パーティクル1
         for (int i = 0; i < IAI_PARTICLE1_QTY; i++)
         {
            std::pair<int, int> xy = std::make_pair(_x, _y);
            std::pair<double, double> dxy = std::make_pair(((rand() % IAI_PARTICLE1_RANDOMX1) - IAI_PARTICLE1_RANDOMX2) / IAI_PARTICLE1_RANDOMX3, ((rand() % -IAI_PARTICLE1_RANDOMY1) - IAI_PARTICLE1_RANDOMY2) / IAI_PARTICLE1_RANDOMY3);
            auto i1 = new IaiParticle1(xy, dxy, false);
            g.GetOS()->Add(i1);
         }
      }
      if (_isflip == true) {
         //パーティクル1
         for (int i = 0; i < IAI_PARTICLE1_QTY; i++)
         {
            std::pair<int, int> xy = std::make_pair(_x, _y);
            std::pair<double, double> dxy = std::make_pair(((rand() % IAI_PARTICLE1_RANDOMX1) - IAI_PARTICLE1_RANDOMX2) / IAI_PARTICLE1_RANDOMX3, ((rand() % -IAI_PARTICLE1_RANDOMY1) - IAI_PARTICLE1_RANDOMY2) / IAI_PARTICLE1_RANDOMY3);
            auto i1 = new IaiParticle1(xy, dxy, true);
            g.GetOS()->Add(i1);
         }
      }
   }
   //居合の当たり判定及びパーティクル発生
   if (frame == IAI_BEGINFRAME) {
      //居合ゲージリセット
      _iai_gauge = 0;
      //居合ゲージのMAXフラグリセット
      _gaugemax_flag = false;
      if (_isflip == false) {
         //居合オブジェクトの生成
         auto iac = new IaiCollision(_x + _hit_x - IAI_WIDTH, _y - _hit_h / 2);
         // オブジェクトサーバ-に蹴り判定オブジェクトを追加
         g.GetOS()->Add(iac);
         //パーティクル2
         for (int i = 0; i < IAI_PARTICLE2_QTY; i++)
         {
            std::pair<int, int> xy = std::make_pair(_x, _y);
            std::pair<double, double> dxy = std::make_pair(((rand() % IAI_PARTICLE2_RANDOMX1) - IAI_PARTICLE2_RANDOMX2) / IAI_PARTICLE2_RANDOMX3, ((rand() % -IAI_PARTICLE2_RANDOMY1) - IAI_PARTICLE2_RANDOMY2) / IAI_PARTICLE2_RANDOMY3);
            auto i2 = new IaiParticle2(xy, dxy, false);
            g.GetOS()->Add(i2);
         }
         //パーティクル3
         for (int i = 0; i < IAI_PARTICLE3_QTY; i++)
         {
            std::pair<int, int> xy = std::make_pair(_x, _y);
            std::pair<double, double> dxy = std::make_pair(((rand() % IAI_PARTICLE3_RANDOMX1) - IAI_PARTICLE3_RANDOMX2) / IAI_PARTICLE3_RANDOMX3, ((rand() % -IAI_PARTICLE3_RANDOMY1) - IAI_PARTICLE3_RANDOMY2) / IAI_PARTICLE3_RANDOMY3);
            auto i3 = new IaiParticle3(xy, dxy, false);
            g.GetOS()->Add(i3);
         }
      }
      if (_isflip == true) {
         //居合オブジェクトの生成
         auto iac = new IaiCollision(_x - _hit_x, _y - _hit_h / 2);
         // オブジェクトサーバ-に居合判定オブジェクトを追加
         g.GetOS()->Add(iac);
         //パーティクル2
         for (int i = 0; i < IAI_PARTICLE2_QTY; i++)
         {
            std::pair<int, int> xy = std::make_pair(_x, _y);
            std::pair<double, double> dxy = std::make_pair(((rand() % IAI_PARTICLE2_RANDOMX1) - IAI_PARTICLE2_RANDOMX2) / IAI_PARTICLE2_RANDOMX3, ((rand() % -IAI_PARTICLE2_RANDOMY1) - IAI_PARTICLE2_RANDOMY2) / IAI_PARTICLE2_RANDOMY3);
            auto i2 = new IaiParticle2(xy, dxy, true);
            g.GetOS()->Add(i2);
         }
         //パーティクル3
         for (int i = 0; i < IAI_PARTICLE3_QTY; i++)
         {
            std::pair<int, int> xy = std::make_pair(_x, _y);
            std::pair<double, double> dxy = std::make_pair(((rand() % IAI_PARTICLE3_RANDOMX1) - IAI_PARTICLE3_RANDOMX2) / IAI_PARTICLE3_RANDOMX3, ((rand() % -IAI_PARTICLE3_RANDOMY1) - IAI_PARTICLE3_RANDOMY2) / IAI_PARTICLE3_RANDOMY3);
            auto i3 = new IaiParticle3(xy, dxy, true);
            g.GetOS()->Add(i3);
         }
      }
   }
   //全フレーム経ったなら待機状態へ移行
   if (frame == IAI_ALLFRAME) {
      _state = PLAYERSTATE::IDLE;
   }
}
/*----------スウェイ----------*/

void Player::Sway(Game& g){
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["Sway"][_anime["Sway"]];
   _anime["Sway"] = ((frame) / ANIMESPEED_SWAY) % SWAY_ANIMEMAX;
   if (frame >= SWAY_NOHITBEGINFRAME && SWAY_NOHITENDFRAME > frame) {
      //特定のモーション中に当たり判定を行わないフラグをTRUEにする
      _nohit_flag = true;
   }
   //特定のモーション中に当たり判定を行わないフラグをFALSEにする
   else { _nohit_flag = false; }
   if (frame == 1) {
      //パーティクル
      for (int i = 0; i < SWAY_PARTICLE_QTY; i++)
      {
         std::pair<int, int> xy = std::make_pair(_x, _y);
         std::pair<double, double> dxy = std::make_pair(((rand() % SWAY_PARTICLE_RANDOMX1) - SWAY_PARTICLE_RANDOMX2) / SWAY_PARTICLE_RANDOMX3, ((rand() % -SWAY_PARTICLE_RANDOMY1) - SWAY_PARTICLE_RANDOMY2) / SWAY_PARTICLE_RANDOMY3);
         auto sw = new SwayParticle(xy, dxy, true);
         g.GetOS()->Add(sw);
      }
   }
   //スウェイ時の移動フレーム
   if (frame < SWAY_MOVEFRAME) {
      if (_isflip == false) {
         _x += SWAY_MOVEMENT;
         g.GetChip()->IsHit(*this, 1, 0);
      }
      if (_isflip == true) {
         _x -= SWAY_MOVEMENT;
         g.GetChip()->IsHit(*this, -1, 0);   
      }
   }
   //全フレーム経ったなら待機状態へ移行
   if (frame == SWAY_ALLFRAME) {
      _state = PLAYERSTATE::IDLE;
   }
}

/*----------被ダメ----------*/

void Player::Damage(Game& g) {
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["Damage"][_anime["Damage"]];
   _anime["Damage"] = ((frame) / ANIMESPEED_DAMAGE) % DAMAGE_ANIMEMAX;
   //居合のSEが発生途中なら止める処理
   StopSoundMem(_se["Iai"]);
   //特定のモーション中に当たり判定を行わないフラグをTRUEにする
   _nohit_flag = true; 
   if (frame == DAMAGE_ALLFRAME) {
      if (_life > 0) {
         //体力がゼロでないなら無敵状態へ移行&待機状態へ移行
         _star_cnt = _cnt;
         _star_flag = true;
         _state = PLAYERSTATE::IDLE;
      }
      else {
         //体力がゼロなら死亡状態へ移行
         _action_cnt = _cnt;
         _state = PLAYERSTATE::DEAD;
         PlaySoundMem(_se["Dead"], DX_PLAYTYPE_BACK, true);
      }
   }
}

/*----------死亡----------*/

void Player::Dead(Game& g) {
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["Dead"][_anime["Dead"]];
   //当たり判定を削除する
   _hit_x = 10000;
   //アニメフレーム以内ならアニメーションさせる
   if (frame < DEAD_ANIMEFRAME){
   _anime["Dead"] = ((frame) / ANIMESPEED_DEAD) % DEAD_ANIMEMAX; 
   }
   //死亡全フレーム終了した際の処理
   if (frame == DEAD_ALLFRAME) {
      g.SetRestartFlag(true);                     //ゲームのリスタートフラグをTRUEにする
      auto mg = (ModeGame*)g.GetMS()->Get("Game");
      mg->SetStopObjProcess(true);                //ゲームの処理を止める
      g.GetMS()->Del(g.GetMS()->Get("Flame"));    //炎演出モードが発生していたなら削除する
      StopSoundMem(g.GetBgm()["Main"]);           //メインステージのBGMが鳴っていたなら止める
      StopSoundMem(g.GetBgm()["Boss"]);           //ボスステージのBGMが鳴っていたなら止める
      StopSoundMem(g.GetBgm()["Flame"]);          //炎演出モードのBGMが鳴っていたなら止める
      auto mgo = new ModeGameover();
      g.GetMS()->Add(mgo,1, "Gameover");          //ゲームオーバーモード生成
      
   }
}

/*---------階段位置調整---------*/

void Player::StairMove(Game& g) {
   _grhandle = _grall["Move"][_anime["Move"]];
   _anime["Move"] = (_cnt / ANIMESPEED_RUN) % MOVE_ANIMEMAX;
   //特定のモーション中に当たり判定を行わないフラグをTRUEにする
   _nohit_flag = true;
   //当たった階段の向きに応じて階段上昇位置へ自動的に移動する
   if (_stairflip_flag == false) {
      if (_x >= _stair_x + StInfo::POSITION_HITX) {
         _isflip = false;
         _x -= STAIRMOVE_SPEED;
      }
      if (_x <= _stair_x + StInfo::POSITION_HITX) {
         _isflip = true;
         _position = { static_cast<double>(_x),static_cast<double>(_y) };
         //SE
         PlaySoundMem(_se["Stair"], DX_PLAYTYPE_BACK, true);
         //階段上昇状態へ移行
         _state = PLAYERSTATE::STAIRUP;
      }
   }
   if (_stairflip_flag == true) {
      if (_x <= _stair_x + StInfo::POSITION_HITX + StInfo::COLLISION_WIDTH) {
         _isflip = true;
         _x += STAIRMOVE_SPEED;
      }
      if (_x >= _stair_x + StInfo::POSITION_HITX + StInfo::COLLISION_WIDTH) {
         _isflip = false;
         //階段上昇の為に一時的にプレイヤー座標をdouble型にキャストする
         _position = { static_cast<double>(_x),static_cast<double>(_y) };
         //SE
         PlaySoundMem(_se["Stair"], DX_PLAYTYPE_BACK, true);
         //階段上昇状態へ移行
         _state = PLAYERSTATE::STAIRUP;
      }
   }
}

/*---------階段上昇------------*/

void Player::StairUp(Game& g) {
   _grhandle = _grall["Move"][_anime["Move"]];
   _anime["Move"] = (_cnt / ANIMESPEED_WALK) % MOVE_ANIMEMAX;
   //上昇速度の設定
   _stairup_spd = STAIRUP_SPEED;
   //階段の向きに応じて上昇する角度を変える
   if (_stairflip_flag == false) {
      _angle = 4.886921905584122f;//280度
   }
   if (_stairflip_flag == true) {
      _angle = 4.53756055185257f;//260度
   }
   _velocity_dir = { std::cos(_angle), std::sin(_angle) };
   auto vd = _velocity_dir * _stairup_spd;
   //プレイヤー座標をint型にキャストする
   auto positionX = static_cast<int>(_position.x);
   auto positionY = static_cast<int>(_position.y);
   _position += vd;
   _x = positionX;
   _y = positionY;
   //プレイヤーY座標が階段の高さ分上昇したなら待機状態へ移行
   auto upheight = _y - _player_y;
   if (upheight == -StInfo::COLLISION_HEIGHT) {
      _nohit_flag = false;
      _state = PLAYERSTATE::IDLE;
      StopSoundMem(_se["Stair"]);
   }
}

/*---------ボス階段位置調整---------*/

void Player::BossStairMove(Game& g) {
   _grhandle = _grall["Move"][_anime["Move"]];
   _anime["Move"] = (_cnt / ANIMESPEED_RUN) % MOVE_ANIMEMAX;
   //特定のモーション中に当たり判定を行わないフラグをTRUEにする
   _nohit_flag = true;
   //当たった階段の向きに応じて階段上昇位置へ自動的に移動する
   if (_stairflip_flag == false) {
      if (_x >= _stair_x + StInfo::POSITION_HITX) {
         _isflip = false;
         _x -= STAIRMOVE_SPEED;
      }
      if (_x <= _stair_x + StInfo::POSITION_HITX) {
         _isflip = true;
         //階段上昇の為に一時的にプレイヤー座標をdouble型にキャストする
         _position = { static_cast<double>(_x),static_cast<double>(_y) };
         auto ol = new OverlayBlack();
         ol->SetFade(90, 270, 360, 3);
         g.GetMS()->Add(ol, 20, "OverlayBlack");      //イベントの為のオーバレイブラックモード生成
         //SE
         PlaySoundMem(_se["Stair"], DX_PLAYTYPE_BACK, true);
         //ボス階段上昇状態へ移行
         _state = PLAYERSTATE::BOSSSTAIRUP;
         _action_cnt = _cnt;
      }
   }
   if (_stairflip_flag == true) {
      if (_x <= _stair_x + StInfo::POSITION_HITX + StInfo::COLLISION_WIDTH) {
         _isflip = true;
         _x += STAIRMOVE_SPEED;
      }
      if (_x >= _stair_x + StInfo::POSITION_HITX + StInfo::COLLISION_WIDTH) {
         _isflip = false;
         //階段上昇の為に一時的にプレイヤー座標をdouble型にキャストする
         _position = { static_cast<double>(_x),static_cast<double>(_y) };
         auto ol = new OverlayBlack();
         ol->SetFade(90, 270, 360, 3);
         g.GetMS()->Add(ol, 20, "OverlayBlack");      //イベントの為のオーバレイブラックモード生成
         //SE
         PlaySoundMem(_se["Stair"], DX_PLAYTYPE_BACK, true);
         //ボス階段上昇状態へ移行
         _state = PLAYERSTATE::BOSSSTAIRUP;
         _action_cnt = _cnt;
      }
   }
}

/*---------ボス階段上昇------------*/

void Player::BossStairUp(Game& g) {
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["Move"][_anime["Move"]];
   _anime["Move"] = (_cnt / ANIMESPEED_WALK) % MOVE_ANIMEMAX;
   //メインステージのBGMをフェードアウトさせる
   auto vpal = g.GetVpal();
   vpal["Main"] -= 1;
   g.SetVpal(vpal);
   //上昇速度の設定
   _stairup_spd = BOSSSTAIRUP_SPEED;
   //階段の向きに応じて上昇する角度を変える
   if (_stairflip_flag == false) {
      _angle = 4.886921905584122f;//280度
   }
   if (_stairflip_flag == true) {
      _angle = 4.53756055185257f;//260度
   }
   _velocity_dir = { std::cos(_angle), std::sin(_angle) };
   auto vd = _velocity_dir * _stairup_spd;
   //プレイヤー座標をint型にキャストする
   auto positionX = static_cast<int>(_position.x);
   auto positionY = static_cast<int>(_position.y);
   _position += vd;
   _x = positionX;
   _y = positionY;
   //プレイヤーY座標が階段の高さ分上昇したなら待機状態へ移行
   auto upheight = _y - _player_y;
   if (upheight == -StInfo::COLLISION_HEIGHT) {
      StopSoundMem(_se["Stair"]);
      auto bb = new ModeBossBefore();
      g.GetMS()->Add(bb, 5, "BossBefore");         //イベントモード生成
      auto mg = (ModeGame*)g.GetMS()->Get("Game");
      mg->SetStopObjProcess(true);                  //ゲームの処理を止める
      StopSoundMem(g.GetBgm()["Main"]);         //メインステージのBGMを止める
      _nohit_flag = false;
      _state = PLAYERSTATE::IDLE;
   }
}
/*-----ボスイベントA-----*/

void Player::BossEventA(Game& g) {
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["Idle"][_anime["Idle"]];
   _anime["Idle"] = (_cnt / ANIMESPEED_IDLE) % IDLE_ANIMEMAX;
   //イベント時のカメラ移動の処理
   if (frame == 1) {
      _camera_x = 800;
   }
   if (frame <=120) {
      _camera_x +=1;
   }
   if (frame >= 240) {
      _camera_x -=1;
   }
   //カメラ位置が元の位置に戻ったなら待機状態へ移行
   if (frame == 360) {
      _camera_x = 500;
      _state = PLAYERSTATE::IDLE;
   }
}
/*-----ボスイベントB-----*/

void Player::BossEventB(Game& g) {
   auto frame = _cnt - _action_cnt;
   _spd = 4;
   //フレームが一定値以下なら待機のアニメーション
   if (frame <= 120) {
      _grhandle = _grall["Idle"][_anime["Idle"]];
      _anime["Idle"] = (_cnt / ANIMESPEED_IDLE) % IDLE_ANIMEMAX;
      auto vpal = g.GetVpal();
      vpal["Boss"] -= 1;         //ボスステージBGMのフェードアウト
      vpal["Flame"] -= 1;      //炎演出BGMのフェードアウト
      g.SetVpal(vpal);
   }
   if (frame == 120) {
      StopSoundMem(g.GetBgm()["Boss"]);      //ボスステージのBGMを止める
      StopSoundMem(g.GetBgm()["Flame"]);   //炎演出BGMを止める
   }
   //フレームが一定値以内なら移動アニメーション
   if (frame > 120 && 310 >= frame) {
      _x += _spd;
      _grhandle = _grall["Move"][_anime["Move"]];
      _anime["Move"] = (_cnt / 10) % MOVE_ANIMEMAX;
   }
   //フレームが一定値以上なら待機のアニメーション
   if (frame > 310) {
      _grhandle = _grall["Idle"][_anime["Idle"]];
      _anime["Idle"] = (_cnt / ANIMESPEED_IDLE) % IDLE_ANIMEMAX;
   }
   //フレームが一定値以上かつ、1～4ボタンのいずれかを押下したなら特殊攻撃状態へ移行
   if (frame > 470) {
      if (g.GetTrg() & PAD_INPUT_1|| g.GetTrg() & PAD_INPUT_2|| g.GetTrg() & PAD_INPUT_3|| g.GetTrg() & PAD_INPUT_4) {
         _state = PLAYERSTATE::SPECIALATTACK;
         _action_cnt = _cnt;
      }
   }
}
/*-----特殊攻撃-----*/

void Player::SpecialAttack(Game& g) {
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["Special"][_anime["Special"]];
   //アニメフレーム以下ならアニメーションさせる
   if (frame < SPECIALATTACK_ANIMEFRAME) {
      _anime["Special"] = ((frame) / ANIMESPEED_SPECIALATTACK) % SPECIALATTACK_ANIMEMAX;
   }
   if (frame == SPECIALATTACK_BEGINFRAME) {
      //SE
      PlaySoundMem(_se["Special"], DX_PLAYTYPE_BACK, true);
      //特殊攻撃判定オブジェクトの生成
      auto sc = new SpecialCollision(_x - _hit_x, _y - _hit_h);
      // オブジェクトサーバ-に特殊攻撃判定オブジェクトを追加
      g.GetOS()->Add(sc);
   }
}
