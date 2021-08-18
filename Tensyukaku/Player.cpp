/*
** プレイヤー
*/

#include <DxLib.h>
#include "ResourceServer.h"
#include "Player.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ModeGame.h"
#include "PlayerHp.h"
#include <vector>
#include <sstream>

using namespace PInfo;
Player::Player() :
	_Idle_AnimeNo(0),
	_Move_AnimeNo(0),
	_MiddleAttack_AnimeNo(0),
	_LowAttack_AnimeNo(0),
	_Kick_AnimeNo(0),
	_Iai_AnimeNo(0),
	/*_Sway_GrHandle(-1),
	_Sway_AnimeNo(0),*/
	_Damage_AnimeNo(0),
	_Dead_AnimeNo(0),
	_Walk_SEHandle(-1),
	_MiddleAttack_SEHandle(-1),
	_LowAttack_SEHandle(-1),
	_Kick_SEHandle(-1),
	_Damage_SEHandle(-1),
	_SwordIn_SEHandle(-1),
	_Iai_SEHandle(-1),
	_State(PLAYERSTATE::IDLE),
	_Star_Flag(false)
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
	_GrHandle = -1;
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
	
	AnimeUpdate(g);

	/*---状態毎の処理---*/
		//無敵状態
	if (_Star_Flag == true) {
		if (_Cnt - _Star_Cnt == Star_Frame) {
			_Star_Flag = false;
		}
	}
	switch (_State) {
		//待機状態
	case PLAYERSTATE::IDLE:
		Idle(g);
		break;
		//移動状態
	case PLAYERSTATE::MOVE:
		Move(g);
		break;
		//中段攻撃状態
	case PLAYERSTATE::MIDDLEATTACK:
		MidAttack(g);
		break;
		//下段攻撃状態
	case PLAYERSTATE::LOWATTACK:
		LowAttack(g);
		break;
		//蹴り状態
	case PLAYERSTATE::KICK:
		Kick(g);
		break;
		//居合状態
	case PLAYERSTATE::IAI:
		Iai(g);
		break;
	//	//スウェイ状態
	//case PLAYERSTATE::SWAY:
	//	Sway(g);
	//	break;
		//被ダメ状態
	case PLAYERSTATE::DAMAGE:
		Damage(g);
		break;
		//死亡状態
	case PLAYERSTATE::DEAD:
		Dead(g);
		break;
	}
	// 主人公位置からカメラ座標決定
	g.SetcvX(_x - (SCREEN_W * BackCameraX / 100));
	g.SetcvY(_y - (SCREEN_H * BackCameraY / 100));
	if (g.GetcvX() < 0) { g.SetcvX(0); }
	if (g.GetcvX() > g.GetmapW()-SCREEN_W) { g.SetcvX(g.GetmapW() - SCREEN_W); }
	if (g.GetcvY() < 0) { g.SetcvY(0); }
	if (g.GetcvY() > g.GetmapH() - SCREEN_H) { g.SetcvY(g.GetmapH() - SCREEN_H); }
	auto GC = g.GetChip();
	GC->SetscrX(_x - (SCREEN_W * ChipCameraX / 100));		// 画面の横中央にキャラを置く
	GC->SetscrY(_y - (SCREEN_H * ChipCameraY / 100));	// 画面の縦92.55%にキャラを置く
	if (GC->GetscrX() < 0) { GC->SetscrX(0); }
	if (GC->GetscrX() > GC->GetMSW() * GC->GetCSW() - SCREEN_W) { GC->SetscrX(GC->GetMSW() * GC->GetCSW() - SCREEN_W); }
	if (GC->GetscrY() < 0) { GC->SetscrY(0); }
	if (GC->GetscrY() > GC->GetMSH() * GC->GetCSH() - SCREEN_H) { GC->SetscrY(GC->GetMSH() * GC->GetCSH() - SCREEN_H); }
}

void Player::Draw(Game& g) {
	UIDraw(g);
	//無敵状態の描画処理
	if (_Star_Flag == true && (_Cnt / AnimeSpeed_Star % 2) == 0) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	}
	ObjectBase::Draw(g);
#ifdef _DEBUG
	std::stringstream ss;
	ss << "_Cnt=" << _Cnt << "\n";
	ss << "_scrX=" << g.GetChip()->GetscrX() << "\n";
	ss << "_scrY=" << g.GetChip()->GetscrY() << "\n";
	ss << "PlayerX=" << _x << "\n";
	ss << "PlayerY=" << _y << "\n";
	ss << "MidNo=" <<_MiddleAttack_AnimeNo<< "\n";
	ss << "LowNo=" << _LowAttack_AnimeNo << "\n";
	DrawString(10, 10, ss.str().c_str(), GetColor(255, 50, 255));
#endif

}

void Player::Delete(Game& g) {
		g.GetOS()->Del(this);
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
	ResourceServer::LoadDivGraph(LowdAttack_GraphName, LowAttack_AnimeMax, LowAttack_WidthCount, LowAttack_HeightCount, GraphWidth, GraphHeight, _LowAttack_GrAll.data());
	_Kick_GrAll.resize(Kick_AnimeMax);
	ResourceServer::LoadDivGraph(Kick_GraphName, Kick_AnimeMax, Kick_WidthCount, Kick_HeightCount, GraphWidth, GraphHeight, _Kick_GrAll.data());
	_Iai_GrAll.resize(Iai_AnimeMax);
	ResourceServer::LoadDivGraph(Iai_GraphName, Iai_AnimeMax, Iai_WidthCount, Iai_HeightCount, GraphWidth, GraphHeight, _Iai_GrAll.data());
	/*_Sway_GrAll.resize(Sway_AnimeMax);
	ResourceServer::LoadDivGraph(Sway_GraphName, Sway_AnimeMax, Sway_WidthCount, Sway_HeightCount, GraphWidth, GraphHeight, _Sway_GrAll.data());*/
	_Damage_GrAll.resize(Damage_AnimeMax);
	ResourceServer::LoadDivGraph(Damage_GraphName, Damage_AnimeMax, Damage_WidthCount, Damage_HeightCount, GraphWidth, GraphHeight, _Damage_GrAll.data());
	_Dead_GrAll.resize(Dead_AnimeMax);
	ResourceServer::LoadDivGraph(Dead_GraphName, Dead_AnimeMax, Dead_WidthCount, Dead_HeightCount, GraphWidth, GraphHeight, _Dead_GrAll.data());
}

//プレイヤーの効果音読み込み関数
void Player::LoadActionSE() {
	_Walk_SEHandle = ResourceServer::LoadSoundMem(Walk_SE);
	_MiddleAttack_SEHandle = ResourceServer::LoadSoundMem(MiddleAttack_SE);
	_LowAttack_SEHandle = ResourceServer::LoadSoundMem(LowAttack_SE);
	_Kick_SEHandle= ResourceServer::LoadSoundMem(Kick_SE);
	_Damage_SEHandle= ResourceServer::LoadSoundMem(Damage_SE);
	_SwordIn_SEHandle = ResourceServer::LoadSoundMem(SwordIn_SE);
	_Iai_SEHandle = ResourceServer::LoadSoundMem(Iai_SE);
}

//プレイヤーのアニメーション関数
void Player::AnimeUpdate(Game& g) {
	_Idle_AnimeNo = (_Cnt / AnimeSpeed_Idle) % Idle_AnimeMax;
	_Move_AnimeNo = (_Cnt / AnimeSpeed_Move) % Move_AnimeMax;
	_MiddleAttack_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_MiddleAttack) % MiddleAttack_AnimeMax;
	_LowAttack_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_LowAttack) % LowAttack_AnimeMax;
	_Kick_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Kick) % Kick_AnimeMax;
	_Iai_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Iai) % Iai_AnimeMax;
	_Damage_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Damage) % Damage_AnimeMax;
	_Dead_AnimeNo = ((_Cnt - _Action_Cnt) / AnimeSpeed_Dead) % Dead_AnimeMax;
}

//プレイヤーのUI描画関数

void Player::UIDraw(Game& g) {
		PlayerHp* HP = new PlayerHp();
		HP->SetPosition(SCREEN_W - SCREEN_W+300 , SCREEN_H - 40);
		g.GetOS()->Add(HP);
	if (_Life >= 3) {
		DrawRotaGraph(HP->GetX(), HP->GetY(), GraphScale, GraphAngle, HP->GetHp3(), true, false);
		g.GetOS()->Del(HP);
	}
	else if (_Life == 2) {
		DrawRotaGraph(HP->GetX(), HP->GetY(), GraphScale, GraphAngle, HP->GetHp2(), true, false);
		g.GetOS()->Del(HP);
	}
	else if (_Life == 1) {
		DrawRotaGraph(HP->GetX(), HP->GetY(), GraphScale, GraphAngle, HP->GetHp1(), true, false);
		g.GetOS()->Del(HP);
	}
	else if(_Life <= 0) { g.GetOS()->Del(HP); }
}