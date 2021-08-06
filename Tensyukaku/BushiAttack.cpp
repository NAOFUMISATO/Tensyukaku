#include <DxLib.h>
#include "EnemyBase.h"
#include "Bushi.h"
#include "Game.h"
#include "BushiAttackCollision.h"
#include "ObjectBase.h"
using namespace Tsk;
using namespace BInfo;
void Bushi::Attack(Game& g) {
	if (_Cnt - _Action_Cnt == ABegin_Frame) {
		//中段攻撃判定オブジェクトの生成
		BushiAttackCollision* BAC = new BushiAttackCollision();
		if (_isFlip == false) {
			// 攻撃判定オブジェクトの開始位置を武士位置から算出
			BAC->SetPosition(_x + _hit_x - BAC->GetW(), _y - _hit_h);
			// オブジェクトサーバ-に中段攻撃判定オブジェクトを追加
			g.GetOS()->Add(BAC);
		};
		if (_isFlip == true) {
			// 攻撃判定オブジェクトの開始位置を武士位置から算出
			BAC->SetPosition(_x - _hit_x, _y - _hit_h);
			// オブジェクトサーバ-に中段攻撃判定オブジェクトを追加
			g.GetOS()->Add(BAC);
		}
	}
	if (_Cnt - _Action_Cnt == Attack_Frame)
	{
		_State = Bushi::ENEMYSTATE::PATROL;
	}
}