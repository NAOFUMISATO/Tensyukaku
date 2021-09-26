/*
** プレイヤー
*/

#include <DxLib.h>
#include "ResourceServer.h"
#include "Player.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ModeGame.h"
#include "OverlayFlame.h"
#include "PlayerHp.h"
#include "IaiGauge.h"
#include "Button.h"
#include <vector>
#include <sstream>

using namespace PInfo;
Player::Player(int x,int y) :
	_move_animespeed(0),
	_star_flag(false),
	_ui_flag(false),
	_nohit_flag(false),
	_restartcheck_flag(false),
	_tutorialhit_flag(false),
	_stairup_flag(false),
	_gaugeup_flag(false)
{
	_x = x;
	_y = y;
	Init();
	LoadPicture();
	LoadSE();
	VolumeInit();
}

Player::~Player()
{	
}

void Player::Init()
{
	// プレイヤー情報の初期化
	_sort = 13;
	_State = PLAYERSTATE::APPEAR;
	_GrHandle = -1;
	_w = GRAPH_WIDTH;
	_h = GRAPH_HEIGHT;
	_gx = GRAPHPOINT_X;
	_gy = GRAPHPOINT_Y;
	_hit_x = POSITION_HITX;
	_hit_y = POSITION_HITY;
	_hit_w = COLLISION_WIDTH;
	_hit_h = COLLISION_HEIGHT;
	_life = LIFE_MAX;
	_action_cnt = _cnt;
	_spd = 0;
	_iai_gauge = 0;
	_isflip = FIRST_FLIP;
	_alpha = FIRST_ALPHA;
	_position = { 0,0 };
	_CameraX = 500;
}


void Player::Process(Game& g)
{
	ObjectBase::Process(g);
	VolumeChange();
	//UIのインスタンス生成
	UIAppear(g);
	//左スティックの入力量によるステータス設定
	BufSetting(g);
	if (g.GetRestartFlag() == true) {
		PLAYERSTATE::SWORDOUT;
	}
	//居合ゲージMAX時のSE発生
	if (_iai_gauge == 5 && _gaugeup_flag == false) {
		PlaySoundMem(_Se["Gage"], DX_PLAYTYPE_BACK, true);
		_gaugeup_flag = true;
	}
	/*---状態毎の処理---*/
	//再起からのスタートなら、状態を抜刀状態にする
	RestartCheck(g);
		//無敵状態
		Star(g);
	switch (_State) {
		//出現状態
	case	PLAYERSTATE::APPEAR:
		Appear(g);
		break;
		//抜刀状態
	case PLAYERSTATE::SWORDOUT:
		Swordout(g);
		break;
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
	DebugDraw(g);
#endif
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
	ObjectBase::Draw(g);
	ButtonDraw(g);
}

void Player::Delete(Game& g) {
		g.GetOS()->Del(this);
}

//画像読み込み関数
void Player::LoadPicture() {
	_GrAll["Appear"].resize(APPEAR_ANIMEMAX);
	ResourceServer::LoadDivGraph(APPEAR_GRAPHNAME, APPEAR_ANIMEMAX, APPEAR_WIDTHCOUNT, APPEAR_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Appear"].data());
	_GrAll["Swordout"].resize(SWORDOUT_ANIMEMAX);
	ResourceServer::LoadDivGraph(SWORDOUT_GRAPHNAME, SWORDOUT_ANIMEMAX, SWORDOUT_WIDTHCOUNT, SWORDOUT_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _GrAll["Swordout"].data());
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

//効果音読み込み関数
void Player::LoadSE() {
	_Se["BStartGame"] = ResourceServer::LoadSoundMem("se/Player/BStartGame.wav");
	_Se["Walk"] = ResourceServer::LoadSoundMem("se/Player/Footstep.wav");
	_Se["MiddleAttack"] = ResourceServer::LoadSoundMem("se/Player/MiddleAttack1.wav");
	_Se["LowAttack"] = ResourceServer::LoadSoundMem("se/Player/LowAttack.wav");
	_Se["Kick"] = ResourceServer::LoadSoundMem("se/Player/Kick.wav");
	_Se["Sway"] = ResourceServer::LoadSoundMem("se/Player/Sway.wav");
	_Se["Damage"] = ResourceServer::LoadSoundMem("se/Player/Damage.wav");
	_Se["Dead"] = ResourceServer::LoadSoundMem("se/Player/Dead.wav");
	_Se["Iai"] = ResourceServer::LoadSoundMem("se/Player/Iai.wav");
	_Se["Gage"] = ResourceServer::LoadSoundMem("se/Player/Gage.wav");
}

//効果音ボリューム初期値設定関数
void	Player::VolumeInit() {
	_Vpal["BStartGame"] = 255;
	_Vpal["Walk"] = 255;
	_Vpal["MiddleAttack"] = 255;
	_Vpal["LowAttack"] = 255;
	_Vpal["Kick"] = 255;
	_Vpal["Sway"] = 255;
	_Vpal["Damage"] = 255;
	_Vpal["Dead"] = 255;
	_Vpal["Iai"] = 255;
	_Vpal["Gage"] = 255;

}

//ボリューム変更関数
void	Player::VolumeChange() {
	ChangeVolumeSoundMem(_Vpal["BStartGame"],_Se["BStartGame"]);
	ChangeVolumeSoundMem(_Vpal["Walk"], _Se["Walk"]);
	ChangeVolumeSoundMem(_Vpal["MiddleAttack"], _Se["MiddleAttack"]);
	ChangeVolumeSoundMem(_Vpal["LowAttack"], _Se["LowAttack"]);
	ChangeVolumeSoundMem(_Vpal["Kick"], _Se["Kick"]);
	ChangeVolumeSoundMem(_Vpal["Sway"], _Se["Sway"]);
	ChangeVolumeSoundMem(_Vpal["Damage"], _Se["Damage"]);
	ChangeVolumeSoundMem(_Vpal["Dead"], _Se["Dead"]);
	ChangeVolumeSoundMem(_Vpal["Iai"], _Se["Iai"]);
	ChangeVolumeSoundMem(_Vpal["Gage"], _Se["Gage"]);
}
//プレイヤーの被ダメ&押し出し&各イベントブロック判定の処理
void	Player::HitJudge(Game& g) {
	//ボスステージのイベント処理状態遷移用処理
	if (_BEventA_Flag == true) {
		_action_cnt = _cnt;
		_State = PLAYERSTATE::EVENTA;
		_BEventA_Flag = false;
	}
	if (_BEventB_Flag == true) {
		_action_cnt = _cnt;
		_State = PLAYERSTATE::EVENTB;
		_BEventB_Flag = false;
	}
	//待機と移動時のみ階段判定を受け付ける処理
	if (_State == PLAYERSTATE::IDLE || _State == PLAYERSTATE::MOVE) {
		_stairup_flag = true;
	}
	else { _stairup_flag = false; }
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
			if (IsHit(*(*ite)) == true && _star_flag == false&&_nohit_flag==false)
			{
				// プレイヤーの状態遷移と攻撃オブジェクトのダメージ処理
				(*ite)->Delete(g);		// (*ite) は攻撃オブジェクト
				_life--;
				_action_cnt = _cnt;
				_State = PLAYERSTATE::DAMAGE;
				PlaySoundMem(_Se["Damage"], DX_PLAYTYPE_BACK, true);
			}
			break;
		//階段との当たり判定
		case ObjectBase::OBJECTTYPE::STAIR:
			// プレイヤーとその階段の当たり判定を行う
			if (IsHit(*(*ite)) == true&&_stairup_flag==true)
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
			if (IsHit(*(*ite)) == true && _stairup_flag == true)
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
					_life = 3;
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
				(*ite)->Delete(g);
				auto of = new OverlayFlame();
				g.GetMS()->Add(of, 1, "Flame");
				PlaySoundMem(g.GetBgm()["Flame"], DX_PLAYTYPE_LOOP, true);
			}
		case ObjectBase::OBJECTTYPE::TUTORIALBOARD:
			// プレイヤーとそのチュートリアルボードの当たり判定を行う
			if (IsHit(*(*ite)) == true) {
				_tutorialhit_flag = true;
			}
			break;
		default:
			break;
		}
	}
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
	ss << "体力=" << _life << "\n";
	ss << "速さ=" << _spd << "\n";
	ss << "カメラ割合=" << _CameraX << "\n";
	ss << "フレーム=" << _cnt-_action_cnt << "\n";
	DrawString(10, 10, ss.str().c_str(), GetColor(255, 0, 0));
}

//UIインスタンス生成関数
void Player::UIAppear(Game& g){
	if (_ui_flag == false) {
		auto hp1 = new PlayerHp(0);
		g.GetOS()->Add(hp1);
		auto hp2 = new PlayerHp(1);
		g.GetOS()->Add(hp2);
		auto hp3 = new PlayerHp(2);
		g.GetOS()->Add(hp3);
		auto ig = new IaiGauge();
		g.GetOS()->Add(ig);
		_ui_flag = true;
	}
}
//チュートリアルボタン描画関数
void Player::ButtonDraw(Game& g) {
	if (_tutorialhit_flag == true) {
		Button bt(_x, _y - 500, 2);
		bt.Process(g);
		bt.Draw(g);
		_tutorialhit_flag = false;
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

//再起からの開始かどうか確認する関数
void Player::RestartCheck(Game& g) {
	if (_restartcheck_flag == false) {
		if (g.GetRestartFlag() == true) {
			_State = PLAYERSTATE::SWORDOUT;
		}
		_restartcheck_flag = true;
	}
}
//無敵状態時の処理
void Player::Star(Game& g) {
	if (_star_flag == true) {
		_alpha = FIRST_ALPHA;
		if ((_cnt / ANIMESPEED_STAR % 2) == 0) {
			_alpha = STAR_ALPHA;
		}
		if (_cnt - _Star_Cnt == STAR_ALLFRAME) {
			_alpha = FIRST_ALPHA;
			_star_flag = false;
		}
	}
}
//左スティックの入力量によるステータス設定
void Player::BufSetting(Game& g) {
	auto xbuf = g.GetXBuf();
	if (xbuf < MAX_BUF - RUN_XBUF && -(MAX_BUF - RUN_XBUF) < xbuf) {
		_spd = WALKSPEED;
		_move_animespeed = ANIMESPEED_WALK;
	}
	if (xbuf >= RUN_XBUF || -RUN_XBUF >= xbuf) {
		_spd = RUNSPEED;
		_move_animespeed = ANIMESPEED_RUN;
	}
}