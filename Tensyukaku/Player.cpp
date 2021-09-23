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
#include "IaiGauge.h"
#include <vector>
#include <sstream>

using namespace PInfo;
Player::Player(int x,int y) :
	_State(PLAYERSTATE::IDLE),
	_Move_AnimeSpeed(0),
	_Star_Flag(false),
	_UI_Flag(false),
	_noHit_Flag(false),
	_StairUp_Flag(false)
{
	_x = x;
	_y = y;
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
	_Sort = 13;
	_GrHandle = -1;
	_w = GRAPH_WIDTH;
	_h = GRAPH_HEIGHT;
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
	_Life = LIFE_MAX;
	_Spd = 0;
	_Iai_Gauge = 0;
	_isFlip = FIRST_FLIP;
	_Alpha = FIRST_ALPHA;
	_Position = { 0,0 };
	_CameraX = 500;
}


void Player::Process(Game& g)
{
	ObjectBase::Process(g);
	//UIのインスタンス生成
	UIAppear(g);
	//左スティックの入力量によるステータス設定
	BufSetting(g);
	/*---状態毎の処理---*/
		//無敵状態
		Star(g);
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
	case PLAYERSTATE::SWAY:
		Sway(g);
		break;
		//被ダメ状態
	case PLAYERSTATE::DAMAGE:
		Damage(g);
		break;
		//死亡状態
	case PLAYERSTATE::DEAD:
		Dead(g);
		break;
		//階段位置調整状態
	case PLAYERSTATE::STAIRMOVE:
		StairMove(g);
		break;
		//階段上昇状態
	case PLAYERSTATE::STAIRUP:
		StairUp(g);
		break;
		//ボス階段位置調整状態
	case PLAYERSTATE::BOSSSTAIRMOVE:
		BossStairMove(g);
		break;
		//ボス階段上昇状態
	case PLAYERSTATE::BOSSSTAIRUP:
		BossStairUp(g);
		break;
		//イベントA状態
	case PLAYERSTATE::EVENTA:
		BossEventA(g);
		break;
		//イベントB状態
	case PLAYERSTATE::EVENTB:
		BossEventB(g);
		break;
		//特殊攻撃状態
	case PLAYERSTATE::SPECIALATTACK:
		SpecialAttack(g);
		break;
	}
	//当たり判定の処理
	HitJudge(g);
	//プレイヤー位置からのカメラ位置設定
	CameraSetting(g);
}

void Player::Draw(Game& g) {
#ifdef _DEBUG
	/*DebugDraw(g);*/
#endif
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _Alpha);
	ObjectBase::Draw(g);
}

void Player::Delete(Game& g) {
		g.GetOS()->Del(this);
}

//プレイヤーの被ダメ&押し出し&各イベントブロック判定の処理
void	Player::HitJudge(Game& g) {
	//ボスステージのイベント処理状態遷移用処理
	if (_BEventA_Flag == true) {
		_Action_Cnt = _Cnt;
		_State = PLAYERSTATE::EVENTA;
		_BEventA_Flag = false;
	}
	if (_BEventB_Flag == true) {
		_Action_Cnt = _Cnt;
		_State = PLAYERSTATE::EVENTB;
		_BEventB_Flag = false;
	}
	//待機と移動時のみ階段判定を受け付ける処理
	if (_State == PLAYERSTATE::IDLE || _State == PLAYERSTATE::MOVE) {
		_StairUp_Flag = true;
	}
	else { _StairUp_Flag = false; }
	//敵の攻撃の当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		OBJECTTYPE objType = (*ite)->GetObjType();
		switch (objType) {
		case ObjectBase::OBJECTTYPE::BUSHIATTACK:
		case ObjectBase::OBJECTTYPE::BUSYOATTACK:
		case ObjectBase::OBJECTTYPE::NINJAATTACK:
		case ObjectBase::OBJECTTYPE::ZYOUNINATTACK:
		case ObjectBase::OBJECTTYPE::SHIELDERATTACK:
		case ObjectBase::OBJECTTYPE::LANCERATTACK:
		case ObjectBase::OBJECTTYPE::POISON:
		case ObjectBase::OBJECTTYPE::STRPOISON:
		case ObjectBase::OBJECTTYPE::KUNAI:
			// プレイヤーとその攻撃の当たり判定を行う
			if (IsHit(*(*ite)) == true && _Star_Flag == false&&_noHit_Flag==false)
			{
				// プレイヤーの状態遷移と攻撃オブジェクトのダメージ処理
				(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
				_Life--;
				_Action_Cnt = _Cnt;
				_State = PLAYERSTATE::DAMAGE;
				PlaySoundMem(_Se["Damage"], DX_PLAYTYPE_BACK, true);
			}
			break;
		//階段との当たり判定
		case ObjectBase::OBJECTTYPE::STAIR:
			// プレイヤーとその階段の当たり判定を行う
			if (IsHit(*(*ite)) == true&&_StairUp_Flag==true)
			{
				if (g.GetKey() & PAD_INPUT_UP && g.GetYBuf() < -UP_YBUF) {
					_Player_y = _y;
					_Stair_x = (*ite)->GetX();
					_StairFlip_Flag = (*ite)->GetFlip();
					_State = PLAYERSTATE::STAIRMOVE;
				}
			}
			break;
		case ObjectBase::OBJECTTYPE::BOSSSTAIR:
			// プレイヤーとその階段の当たり判定を行う
			if (IsHit(*(*ite)) == true && _StairUp_Flag == true)
			{
				if (g.GetKey() & PAD_INPUT_UP && g.GetYBuf() < -UP_YBUF) {
					_Player_y = _y;
					_Stair_x = (*ite)->GetX();
					_StairFlip_Flag = (*ite)->GetFlip();
					_State = PLAYERSTATE::BOSSSTAIRMOVE;
				}
			}
			break;
		case ObjectBase::OBJECTTYPE::ENEMY:
			// iteは敵か？
			if ((*ite)->GetObjType() == OBJECTTYPE::ENEMY)
			{
				// プレイヤーとその敵の当たり判定を行う
				if (IsHit(*(*ite)) == true) {
					_x = _Before_x;

				}
			}
			break;
		case ObjectBase::OBJECTTYPE::RECOVERYBLOCK:
				// プレイヤーとその回復判定の当たり判定を行う
				if (IsHit(*(*ite)) == true) {
					(*ite)->Delete(g);
					_Life = 3;
				}
				break;
		case ObjectBase::OBJECTTYPE::CPOINTBLOCK:
			// プレイヤーとそのチェックポイントの当たり判定を行う
			if (IsHit(*(*ite)) == true) {
				(*ite)->Delete(g);
				PlaySoundMem(g.GetBgm()["Boss"], DX_PLAYTYPE_LOOP, true);
				g.SetCPointFlag(true);
			}
			break;
		case ObjectBase::OBJECTTYPE::FLAMEBLOCK:
			// プレイヤーとその炎演出の当たり判定を行う
			if (IsHit(*(*ite)) == true) {
				PlaySoundMem(g.GetBgm()["Flame"], DX_PLAYTYPE_LOOP, true);
			}
			break;
		default:
			break;
		}
	}
}
//プレイヤーの画像読み込み関数
void Player::LoadActionGraph() {
	_GrAll["Idle"].resize(IDLE_ANIMEMAX);
	ResourceServer::LoadDivGraph(IDLE_GRAPHNAME, IDLE_ANIMEMAX, IDLE_WIDTHCOUNT, IDLE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Idle"].data());
	_GrAll["Move"].resize(MOVE_ANIMEMAX);
	ResourceServer::LoadDivGraph(MOVE_GRAPHNAME, MOVE_ANIMEMAX, MOVE_WIDTHCOUNT, MOVE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Move"].data());
	_GrAll["MiddleAttack"].resize(MIDDLEATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(MIDDLEATTACK_GRAPHNAME, MIDDLEATTACK_ANIMEMAX, MIDDLEATTACK_WIDTHCOUNT, MIDDLEATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["MiddleAttack"].data());
	_GrAll["LowAttack"].resize(LOWATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(LOWATTACK_GRAPHNAME, LOWATTACK_ANIMEMAX, LOWATTACK_WIDTHCOUNT, LOWATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["LowAttack"].data());
	_GrAll["Kick"].resize(KICK_ANIMEMAX);
	ResourceServer::LoadDivGraph(KICK_GRAPHNAME, KICK_ANIMEMAX, KICK_WIDTHCOUNT, KICK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Kick"].data());
	_GrAll["Iai"].resize(IAI_ANIMEMAX);
	ResourceServer::LoadDivGraph(IAI_GRAPHNAME, IAI_ANIMEMAX, IAI_WIDTHCOUNT, IAI_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Iai"].data());
	_GrAll["Sway"].resize(SWAY_ANIMEMAX);
	ResourceServer::LoadDivGraph(SWAY_GRAPHNAME, SWAY_ANIMEMAX, SWAY_WIDTHCOUNT, SWAY_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Sway"].data());
	_GrAll["Damage"].resize(DAMAGE_ANIMEMAX);
	ResourceServer::LoadDivGraph(DAMAGE_GRAPHNAME, DAMAGE_ANIMEMAX, DAMAGE_WIDTHCOUNT, DAMAGE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Damage"].data());
	_GrAll["Dead"].resize(DEAD_ANIMEMAX);
	ResourceServer::LoadDivGraph(DEAD_GRAPHNAME, DEAD_ANIMEMAX, DEAD_WIDTHCOUNT, DEAD_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Dead"].data());
	_GrAll["Special"].resize(SPECIALATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(SPECIALATTACK_GRAPHNAME, SPECIALATTACK_ANIMEMAX, SPECIALATTACK_WIDTHCOUNT, SPECIALATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Special"].data());
}

//プレイヤーの効果音読み込み関数
void Player::LoadActionSE() {
	_Se["Walk"] =		ResourceServer::LoadSoundMem("se/Player/Footstep.wav");
	_Se["MiddleAttack"]=ResourceServer::LoadSoundMem("se/Player/MiddleAttack1.wav");
	_Se["LowAttack"] =	ResourceServer::LoadSoundMem("se/Player/LowAttack1.wav");
	_Se["Kick"] =		ResourceServer::LoadSoundMem("se/Player/Kick.wav");
	_Se["Sway"] = ResourceServer::LoadSoundMem("se/Player/Sway.wav");
	_Se["Damage"] =		ResourceServer::LoadSoundMem("se/Player/Damage.wav");
	_Se["Dead"] = ResourceServer::LoadSoundMem("se/Player/Dead.wav");
	_Se["Iai"] =		ResourceServer::LoadSoundMem("se/Player/Iai.wav");
}

//デバック用関数
void Player::DebugDraw(Game& g) {
	std::stringstream ss;
	ss << "Xスクロール値=" << g.GetChip()->GetscrX() << "\n";
	ss << "Yスクロール値=" << g.GetChip()->GetscrY() << "\n";
	ss << "プレイヤーX座標=" << _x << "\n";
	ss << "プレイヤーY座標=" << _y << "\n";
	ss<<"左スティック入力量X="<<g.GetXBuf()<< "\n";
	ss <<"左スティック入力量Y="<<g.GetYBuf()<< "\n";
	ss << "体力=" << _Life << "\n";
	ss << "速さ=" << _Spd << "\n";
	ss << "カメラ割合=" << _CameraX << "\n";
	ss << "フレーム=" << _Cnt-_Action_Cnt << "\n";
	DrawString(10, 10, ss.str().c_str(), GetColor(255, 0, 0));
}

//UIインスタンス生成関数
void Player::UIAppear(Game& g){
	if (_UI_Flag == false) {
		auto hp1 = new PlayerHp(0);
		g.GetOS()->Add(hp1);
		auto hp2 = new PlayerHp(1);
		g.GetOS()->Add(hp2);
		auto hp3 = new PlayerHp(2);
		g.GetOS()->Add(hp3);
		auto ig = new IaiGauge();
		g.GetOS()->Add(ig);
		_UI_Flag = true;
	}
}
//プレイヤー位置からのカメラ位置設定
void Player::CameraSetting(Game& g) {

	g.SetcvX(_x - (SCREEN_W * _CameraX / 1000));				// 背景の横中央にキャラを置く
	g.SetcvY(_y - (SCREEN_H * BACK_CAMERA_Y / 100));		// 背景の縦93%にキャラを置く
	if (g.GetcvX() < 0) { g.SetcvX(0); }
	if (g.GetcvX() > g.GetmapW() - SCREEN_W) { g.SetcvX(g.GetmapW() - SCREEN_W); }
	if (g.GetcvY() < 0) { g.SetcvY(0); }
	if (g.GetcvY() > g.GetmapH() - SCREEN_H) { g.SetcvY(g.GetmapH() - SCREEN_H); }

	auto GC = g.GetChip();
	GC->SetscrX(_x - (SCREEN_W * _CameraX / 1000));			// マップチップの横中央にキャラを置く
	GC->SetscrY(_y - (SCREEN_H * CHIP_CAMERA_Y / 100));		// マップチップの縦93%にキャラを置く
	if (GC->GetscrX() < 0) { GC->SetscrX(0); }
	if (GC->GetscrX() > GC->GetMSW() * GC->GetCSW() - SCREEN_W) { GC->SetscrX(GC->GetMSW() * GC->GetCSW() - SCREEN_W); }
	if (GC->GetscrY() < 0) { GC->SetscrY(0); }
	if (GC->GetscrY() > GC->GetMSH() * GC->GetCSH() - SCREEN_H) { GC->SetscrY(GC->GetMSH() * GC->GetCSH() - SCREEN_H); }
}
//無敵状態時の処理
void Player::Star(Game& g) {
	if (_Star_Flag == true) {
		_Alpha = FIRST_ALPHA;
		if ((_Cnt / ANIMESPEED_STAR % 2) == 0) {
			_Alpha = STAR_ALPHA;
		}
		if (_Cnt - _Star_Cnt == STAR_ALLFRAME) {
			_Alpha = FIRST_ALPHA;
			_Star_Flag = false;
		}
	}
}
//左スティックの入力量によるステータス設定
void Player::BufSetting(Game& g) {
	auto xbuf = g.GetXBuf();
	if (xbuf < MAX_BUF - RUN_XBUF && -(MAX_BUF - RUN_XBUF) < xbuf) {
		_Spd = WALKSPEED;
		_Move_AnimeSpeed = ANIMESPEED_WALK;
	}
	if (xbuf >= RUN_XBUF || -RUN_XBUF >= xbuf) {
		_Spd = RUNSPEED;
		_Move_AnimeSpeed = ANIMESPEED_RUN;
	}
}