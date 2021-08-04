#include <DxLib.h>
#include "Player.h"
#include "Game.h"
#include "MiddleAttackCollision.h"
using namespace Tsk;
using namespace PInfo;
void Player::MidAttack(Game& g) {
	//中段攻撃判定オブジェクトの生成
	MiddleAttackCollision* MAC = new MiddleAttackCollision();
	if (_isFlip == false) {
		// 中段攻撃判定オブジェクトの開始位置をプレイヤー位置から算出
		MAC->SetPosition(_x + _hit_x - MAC->GetW(), _y - _hit_h);
		// オブジェクトサーバ-に中段攻撃判定オブジェクトを追加
		g.GetOS()->Add(MAC);
	};
	if (_isFlip == true) {
		// 中段攻撃判定オブジェクトの開始位置をプレイヤー位置から算出
		MAC->SetPosition(_x - _hit_x, _y - _hit_h);
		// オブジェクトサーバ-に中段攻撃判定オブジェクトを追加
		g.GetOS()->Add(MAC);
	}
	if (_Cnt - _Action_Cnt == MiddleAttack_Frame) {
		MAC->Damage(g);
		_Action = PLAYERACTION::IDLE;
	}
}