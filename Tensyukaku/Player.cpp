/*
** プレイヤー
*/

#include <DxLib.h>
#include "ResourceServer.h"
#include "Player.h"
#include "MiddleAttackCollision.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ModeGame.h"
#include <vector>
#include <sstream>
using namespace Tsk;
using namespace PInfo;
Player::Player() :
	_Idle_GrHandle(-1),
	_Idle_AnimeNo(0),
	_Move_GrHandle(-1),
	_Move_AnimeNo(0),
	_MiddleAttack_GrHandle(-1),
	_MiddleAttack_AnimeNo(0),
	_LowAttack_GrHandle(-1),
	_LowAttack_AnimeNo(0),
	_Walk_SEHandle(-1),
	_MiddleAttack_SEHandle(-1),
	_LowAttack_SEHandle(-1),
	_Action(PLAYERACTION::IDLE)

{
	Init();
	LoadActionGraph();
	LoadActionSE();
}

Player::~Player()
{
}

void Player::Init()
{
	// プレイヤー情報の初期化
	_w = GraphWidth;
	_h = GraphHeight;
	_x = PositionX;
	_y = PositionY;
	_gx = GraphPointX;
	_gy = GraphPointY;
	_hit_x = PositionHitX;
	_hit_y = PositionHitY;
	_hit_w = CollisionWidth;
	_hit_h = CollisionHeight;
	_Life = LifeMax;
	_Spd = Speed;
	_isFlip = false;
}


void Player::Process(Game& g)
{
	ObjectBase::Process(g);
	/*---状態毎の処理---*/
	switch (_Action) {
		//待機状態
	case PLAYERACTION::IDLE:
		Idle(g);
		break;
		//移動状態
	case PLAYERACTION::MOVE:
		Move(g);
		break;
		//中段攻撃状態
	case PLAYERACTION::MIDDLEATTACK:
		MidAttack(g);
		break;
		//下段攻撃状態
	case PLAYERACTION::LOWATTACK:
		LowAttack(g);
		break;
	}
}
void Player::Draw(Game& g) {
	// カメラから見た座標に変更（ワールド座標→ビュー座標）

	auto x = _x + _gx/* - g.GetChips().GetScrX()*/;
	auto y = _y + _gy/*- g.GetChips().GetScrY()*/;

	//プレイヤーの状態によるアニメーション遷移
	switch (_Action) {
		//待機状態
	case PLAYERACTION::IDLE:
		_Idle_AnimeNo = (_Cnt / AnimeSpeed_Idle) % Idle_AnimeMax;
		_Idle_GrHandle = _Idle_GrAll[_Idle_AnimeNo];
		DrawRotaGraph(x, y, GraphScale, GraphAngle, _Idle_GrHandle, true, _isFlip);
		break;
		//移動状態
	case PLAYERACTION::MOVE:
		_Move_AnimeNo = (_Cnt / AnimeSpeed_Move) % Move_AnimeMax;
		_Move_GrHandle = _Move_GrAll[_Move_AnimeNo];
		if (g.GetKey() & PAD_INPUT_LEFT) {
			DrawRotaGraph(x, y, GraphScale, GraphAngle, _Move_GrHandle, true, _isFlip);
		}
		else if (g.GetKey() & PAD_INPUT_RIGHT) {
			DrawRotaGraph(x, y, GraphScale, GraphAngle, _Move_GrHandle, true, _isFlip);
		}
		break;
		//中段攻撃状態
	case PLAYERACTION::MIDDLEATTACK:
		_MiddleAttack_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_MiddleAttack) % MiddleAttack_AnimeMax;
		_MiddleAttack_GrHandle = _MiddleAttack_GrAll[_MiddleAttack_AnimeNo];
		DrawRotaGraph(x, y, GraphScale, GraphAngle, _MiddleAttack_GrHandle, true, _isFlip);
		break;
		//下段攻撃状態
	case PLAYERACTION::LOWATTACK:
		_LowAttack_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_LowAttack) % LowAttack_AnimeMax;
		_LowAttack_GrHandle = _LowAttack_GrAll[_LowAttack_AnimeNo];
		DrawRotaGraph(x, y, GraphScale, GraphAngle, _LowAttack_GrHandle, true, _isFlip);
		break;
	}
	// 主人公位置からカメラ座標決定
	//g.GetChips().SetScr(_x - (SCREEN_W / 2), _y - (SCREEN_H * 7 / 10));		// 画面の横中央にキャラ配置,画面の縦70%にキャラ配置
	/*-----デバッグ描画-----*/
#ifdef _DEBUG
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		// 半透明描画指定
	DrawBox(x + _hit_x, y + _hit_y, x + _hit_x + _hit_w, y + _hit_y + _hit_h, GetColor(255, 0, 0), FALSE);	// 半透明の赤で当たり判定描画
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// 不透明描画指定
	std::stringstream ss;
	ss << "_Cnt=" << _Cnt << "\n";
	ss << "MidNo=" << _MiddleAttack_AnimeNo << "\n";
	ss << "LowNo=" << _LowAttack_AnimeNo << "\n";
	DrawString(x - 100, y + 100, ss.str().c_str(), GetColor(255, 50, 255));
#endif
}
//プレイヤーの画像読み込み関数
void Player::LoadActionGraph() {
	_Idle_GrAll.resize(Idle_AnimeMax);
	ResourceServer::LoadDivGraph(Idle_GraphName, Idle_AnimeMax, Idle_WidthCount, Idle_HeightCount, GraphWidth, GraphHeight, _Idle_GrAll.data());
	_Move_GrAll.resize(Move_AnimeMax);
	ResourceServer::LoadDivGraph(Move_GraphName, Move_AnimeMax, Move_WidthCount, Move_HeightCount, GraphWidth, GraphHeight, _Move_GrAll.data());
	_MiddleAttack_GrAll.resize(MiddleAttack_AnimeMax);
	ResourceServer::LoadDivGraph(MiddleAttack_GraphName, MiddleAttack_AnimeMax, MiddleAttack_WidthCount, MiddleAttack_HeightCount, GraphWidth, GraphHeight, _MiddleAttack_GrAll.data());
	_LowAttack_GrAll.resize(LowAttack_AnimeMax);
	ResourceServer::LoadDivGraph(LowdleAttack_GraphName, LowAttack_AnimeMax, LowAttack_WidthCount, LowAttack_HeightCount, GraphWidth, GraphHeight, _LowAttack_GrAll.data());
}

//プレイヤーの効果音読み込み関数
void Player::LoadActionSE() {
	_Walk_SEHandle = ResourceServer::LoadSoundMem(Walk_SE);
	_MiddleAttack_SEHandle = ResourceServer::LoadSoundMem(MiddleAttack_SE);
	_LowAttack_SEHandle = ResourceServer::LoadSoundMem(LowAttack_SE);
}