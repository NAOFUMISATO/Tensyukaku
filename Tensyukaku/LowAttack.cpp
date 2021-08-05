#include <DxLib.h>
#include "Player.h"
#include "Game.h"
#include "LowAttackCollision.h"
using namespace Tsk;
using namespace PInfo;
void Player::LowAttack(Game& g) {
	//下段攻撃判定オブジェクトの生成
	if (_Cnt - _Action_Cnt == LABegin_Frame) {
		LowAttackCollision* LAC = new LowAttackCollision();
		if (_isFlip == false) {
			// 中段攻撃判定オブジェクトの開始位置をプレイヤー位置から算出
			LAC->SetPosition(_x + _hit_x - LAC->GetW(), _y - LAC->GetH());
			// オブジェクトサーバ-に中段攻撃判定オブジェクトを追加
			g.GetOS()->Add(LAC);
		};
		if (_isFlip == true) {
			// 中段攻撃判定オブジェクトの開始位置をプレイヤー位置から算出
			LAC->SetPosition(_x - _hit_x, _y - LAC->GetH());
			// オブジェクトサーバ-に中段攻撃判定オブジェクトを追加
			g.GetOS()->Add(LAC);
		}
	}
	if (_Cnt - _Action_Cnt == MiddleAttack_Frame) {
		_Action = PLAYERACTION::IDLE;
	}
}