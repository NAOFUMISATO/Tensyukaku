/*
      武士のモーション関数
*/
#include <DxLib.h>
#include "Bushi.h"
#include "Game.h"
#include "BushiMotionCollision.h"
#include "PrivateCollision.h"

using namespace BInfo;
/*----------出現----------*/
void Bushi::Appear(Game& g) {
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["Appear"][_anime["Appear"]];
   _anime["Appear"] = (_cnt / ANIMESPEED_APPEAR) % APPEAR_ANIMEMAX;
   if (frame < APPEAR_ALLFRAME) {
      _alpha += FADEIN_SPEED;
   }
   //全フレーム経ったなら透明度をMAXにして、索敵状態へ移行
   if (frame == APPEAR_ALLFRAME) {
      _alpha = 255;
      _action_cnt = _cnt;
      _state=ENEMYSTATE::PATROL;
   }
}

/*----------巡回----------*/
void Bushi::Patrol(Game& g) {
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["Patrol"][_anime["Patrol"]];
   _anime["Patrol"] = (_cnt / ANIMESPEED_PATROL) % PATROL_ANIMEMAX;
   //一定時間ごとに振り返る処理
   if (frame == PATROL_TURNFRAME) {
      if (_isflip == false) {
         _isflip = true;
      }
      else {_isflip = false;}
   }
   if (frame == PATROL_TURNFRAME *2) {
      if (_isflip == false) {
         _isflip = true;
      }
      else { _isflip = false; }
      _action_cnt = _cnt;
   }
   if (_isflip == false) {
      //前方索敵範囲判定オブジェクトの生成
      PrivateCollision pc(_x + _hit_x - PATROL_WIDTH, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);
      //後方索敵範囲判定オブジェクトの生成
      PrivateCollision bpc(_x - _hit_x, _y - _hit_h, PATROL_BACKWIDTH, PATROL_HEIGHT);
      //索敵範囲オブジェクトはプレイヤーに当たったか？
      for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++){
         // iteはプレイヤーか？
         if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER){
            //前方索敵範囲オブジェクトとプレイヤーが当たったなら追跡状態へ移行
            if ((*ite)->IsHit(pc) == true){
               _state = ENEMYSTATE::COMING;
            }
            //後方索敵範囲オブジェクトに当たっている且つ、プレイヤーの速さが一定以上なら振り返り追跡状態へ移行
            if ((*ite)->IsHit(bpc) == true) {
               auto ps = (*ite)->GetSpd();
               if (ps > 5) {
                  if (_isflip == false) {
                     _isflip = true;
                  }
                  else { _isflip = false; }
                  _action_cnt = _cnt;
                  _state = ENEMYSTATE::COMING;
               }
            }
         }
      }
   }
   if (_isflip == true) {
      //前方索敵範囲判定オブジェクトの生成
      PrivateCollision pc(_x - _hit_x, _y - _hit_h, PATROL_WIDTH, PATROL_HEIGHT);
      //後方索敵範囲判定オブジェクトの生成
      PrivateCollision bpc(_x + _hit_x - PATROL_BACKWIDTH, _y - _hit_h, PATROL_BACKWIDTH, PATROL_HEIGHT);
      //索敵範囲オブジェクトはプレイヤーに当たったか？
      for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++){
         if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER){
            //前方索敵範囲オブジェクトとプレイヤーが当たったなら追跡状態へ移行
            if ((*ite)->IsHit(pc) == true){
               _state = ENEMYSTATE::COMING;
            }
            //後方索敵範囲オブジェクトに当たっている且つ、プレイヤーの速さが一定以上なら振り返り追跡状態へ移行
            if ((*ite)->IsHit(bpc) == true){
               auto ps = (*ite)->GetSpd();
               if (ps > 5) {
                  if (_isflip == false) {
                     _isflip = true;
                  }
                  else { _isflip = false; }
                  _state = ENEMYSTATE::COMING;
               }
            }
         }
      }
   }
}
/*----------追跡----------*/
void Bushi::Coming(Game& g) {
   _grhandle = _grall["Coming"][_anime["Coming"]];
   _anime["Coming"] = (_cnt / ANIMESPEED_COMING) % COMING_ANIMEMAX;
   if (_isflip == false) {
      _x -= _spd;
      g.GetChip()->IsHit(*this, -1, 0);
      //攻撃発生範囲判定オブジェクトの生成
      PrivateCollision ac(_x + _hit_x - COMING_WIDTH, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
      //攻撃発生範囲オブジェクトはプレイヤーに当たったか？
      for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++){
         // iteはプレイヤーか？
         if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER){
            // 攻撃発生範囲判定オブジェクトにプレイヤーが当たったなら攻撃状態へ移行
            if ((*ite)->IsHit(ac) == true){
               _action_cnt = _cnt;
               _state = ENEMYSTATE::ATTACK;
               _anime["Coming"] = 0;
            }
         }
      }
      //追跡中止範囲判定オブジェクトの生成
      PrivateCollision cc(_x + _hit_x - COMINGCANCEL_WIDTH, _y - _hit_h, COMINGCANCEL_WIDTH, COMINGCANCEL_HEIGHT);
      //追跡中止範囲オブジェクトはプレイヤーに当たったか？
      for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++){
         // iteはプレイヤーか？
         if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER){
            // 追跡中止範囲オブジェクトとプレイヤーが当たらなくなったら索敵状態へ移行
            if ((*ite)->IsHit(cc) == false){
               _action_cnt = _cnt;
               _state = ENEMYSTATE::PATROL;
               _anime["Coming"] = 0;
            }
         }
      }   
   }
   if (_isflip == true) {
      _x += _spd;
      g.GetChip()->IsHit(*this, 1, 0);
      //攻撃発生範囲判定オブジェクトの生成
      PrivateCollision cc(_x - _hit_x, _y - _hit_h, COMING_WIDTH, COMING_HEIGHT);
      //攻撃発生範囲判定オブジェクトはプレイヤーに当たったか？
      for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++){
         // iteはプレイヤーか？
         if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER){
            // 攻撃発生範囲判定オブジェクトにプレイヤーが当たったなら攻撃状態へ移行
            if ((*ite)->IsHit(cc) == true){
               _action_cnt = _cnt;
               _state = ENEMYSTATE::ATTACK;
               _anime["Coming"] = 0;
            }
         }
      }
      //追跡中止範囲判定オブジェクトの生成
      PrivateCollision ccc(_x - _hit_x, _y - _hit_h, COMINGCANCEL_WIDTH, COMINGCANCEL_HEIGHT);
      //追跡中止範囲オブジェクトはプレイヤーに当たったか？
      for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++){
         // iteはプレイヤーか？
         if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER){
            // 追跡中止範囲オブジェクトとプレイヤーが当たらなくなったら索敵状態へ移行
            if ((*ite)->IsHit(ccc) == false){
               _action_cnt = _cnt;
               _state = ENEMYSTATE::PATROL;
               _anime["Coming"] = 0;
            }
         }
      }
   }
}
/*----------攻撃----------*/
void Bushi::Attack(Game& g) {
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["Attack"][_anime["Attack"]];
   //アニメフレーム以下ならアニメーションする
   if (frame<ATTACK_ANIMEFRAME) {
      _anime["Attack"] = ((frame) / ANIMESPEED_ATTACK) % ATTACK_ANIMEMAX;
   }
   if (_isflip == false) {
      //攻撃中止範囲オブジェクトの生成
      PrivateCollision acc(_x + _hit_x - ATTACKCANCEL_WIDTH, _y - _hit_h, ATTACKCANCEL_WIDTH, ATTACKCANCEL_HEIGHT);
      if (frame == ATTACK_ANIMEFRAME|| frame == ATTACK_ALLFRAME) {
         //攻撃中止範囲オブジェクトはプレイヤーに当たったか？
         for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++){
            // iteはプレイヤーか？
            if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER){
               // 攻撃中止範囲オブジェクトとプレイヤーが当たらなくなったら追跡状態へ移行
               if ((*ite)->IsHit(acc) == false){
                  _anime["Attack"] = 0;
                  _state = ENEMYSTATE::COMING;
               }
            }
         }
      }
   }
   if (_isflip == true) {
      //攻撃中止範囲オブジェクトの生成
      PrivateCollision acc(_x - _hit_x, _y - _hit_h, ATTACKCANCEL_WIDTH, ATTACKCANCEL_HEIGHT);
      if (frame == ATTACK_ANIMEFRAME || frame==ATTACK_ALLFRAME) {
         //攻撃中止範囲オブジェクトはプレイヤーに当たったか？
         for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++){
            // iteはプレイヤーか？
            if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER){
               // 攻撃中止範囲オブジェクトとプレイヤーが当たらなくなったら追跡状態へ移行
               if ((*ite)->IsHit(acc) == false){
                  _anime["Attack"] = 0;
                  _state = ENEMYSTATE::COMING;
               }
            }
         }
      }
   }
   if (frame == ATTACK_BEGINFRAME) {
      //SE
      PlaySoundMem(_se["Attack"],DX_PLAYTYPE_BACK,true);
      if (_isflip == false) {
         _x -= ATTACK_STEP;
         //武士の攻撃判定オブジェクトの生成
         auto bac = new BushiAttackCollision(_x + _hit_x - ATTACK_WIDTH, _y - _hit_h);
         // オブジェクトサーバ-に武士の攻撃判定オブジェクトを追加
         g.GetOS()->Add(bac);
      };
      if (_isflip == true) {
         _x += ATTACK_STEP;
         //武士の攻撃判定オブジェクトの生成
         auto bac = new BushiAttackCollision(_x - _hit_x, _y - _hit_h);
         // オブジェクトサーバ-に武士の攻撃判定オブジェクトを追加
         g.GetOS()->Add(bac);
      }
   }
   if (frame == ATTACK_ALLFRAME) {
      _action_cnt=_cnt;
   }
}
/*----------被ダメ----------*/
void Bushi::Damage(Game& g) {
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["Damage"][_anime["Damage"]];
   if (frame < DAMAGE_ANIMEFRAME) {
      _anime["Damage"] = ((frame) / ANIMESPEED_DAMAGE) % DAMAGE_ANIMEMAX;
   }
   //全フレーム経ったら追跡状態へ移行
   if (frame == DAMAGE_ALLFRAME) {
         _state = ENEMYSTATE::COMING;
         _anime["Damage"] = 0;
   }
}
/*----------死亡----------*/
void Bushi::Dead(Game& g) {
   auto frame = _cnt - _action_cnt;
   _grhandle = _grall["Dead"][_anime["Dead"]];   
   //当たり判定を削除する
   _hit_x = 10000;
   //アニメフレーム以下ならアニメーションする
   if (frame < DEAD_ANIMEFRAME) {
      _anime["Dead"] = ((frame) / ANIMESPEED_DEAD) % DEAD_ANIMEMAX;
   }
   //アニメフレーム以上かつ全フレーム以下ならフェードアウトしていく
   if (frame >= DEAD_ANIMEFRAME && DEAD_ALLFRAME > frame) {
      _alpha -= FADEOUT_SPEED;
   }
   //全フレーム経ったならこのオブジェクトを削除する
   if (frame == DEAD_ALLFRAME) {   
      Delete(g);
   }
}

