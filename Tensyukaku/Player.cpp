/*
**	プレイヤー
*/

#include <DxLib.h>
#include "ResourceServer.h"
#include "Player.h"
#include "Game.h"
#include "ObjectBase.h"
#include "ModeGame.h"
#include "ModePause.h"
#include "OverlayFlame.h"
#include "PlayerHp.h"
#include "IaiGauge.h"
#include "PlayerParticle.h"
#include <vector>
#include <sstream>
using namespace PParInfo;
using namespace PInfo;
Player::Player(int x,int y,bool flip) :
	_move_animespeed(0),
	_star_flag(false),
	_ui_flag(false),
	_nohit_flag(false),
	_restartcheck_flag(false),
	_tutorialhit_flag(false),
	_stairup_flag(false),
	_gaugemax_flag(false),
	_pauseinput_flag(false)
{
	_x = x;
	_y = y;
	_isflip = flip;
	Init();						// 情報の初期化
	LoadPicture();		//画像読み込み
	LoadSE();				//効果音読み込み
	VolumeInit();			//効果音音量初期化
}

Player::~Player(){	
}
//初期化
void Player::Init()
{
	_sort = 13;
	_state = PLAYERSTATE::APPEAR;
	_grhandle = -1;
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
	_alpha = FIRST_ALPHA;
	_position = { 0,0 };
	_camera_x = 500;
}

/*---処理---*/
void Player::Process(Game& g)
{
	ObjectBase::Process(g);
	VolumeChange();
	//UIのインスタンス生成
	UIAppear(g);
	//左スティックの入力量によるステータス設定
	BufSetting(g);
	//ゲージMAX時の自機発光&SE発生
	GaugeMax(g);
	//ポーズの入力管理関数
	PauseInput(g);
	/*---状態毎の処理---*/
	//再起からのスタートなら、状態を抜刀状態にする
	RestartCheck(g);
		//無敵状態
		Star(g);
	switch (_state) {
		//出現状態
	case PLAYERSTATE::APPEAR:
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
/*---描画---*/
void Player::Draw(Game& g) {
#ifdef _DEBUG
	DebugDraw(g);
#endif
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
	ObjectBase::Draw(g);
}

//画像読み込み関数
void Player::LoadPicture() {
	_grall["Appear"].resize(APPEAR_ANIMEMAX);
	ResourceServer::LoadDivGraph(APPEAR_GRAPHNAME, APPEAR_ANIMEMAX, APPEAR_WIDTHCOUNT, APPEAR_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Appear"].data());
	_grall["Swordout"].resize(SWORDOUT_ANIMEMAX);
	ResourceServer::LoadDivGraph(SWORDOUT_GRAPHNAME, SWORDOUT_ANIMEMAX, SWORDOUT_WIDTHCOUNT, SWORDOUT_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Swordout"].data());
	_grall["Idle"].resize(IDLE_ANIMEMAX);
	ResourceServer::LoadDivGraph(IDLE_GRAPHNAME, IDLE_ANIMEMAX, IDLE_WIDTHCOUNT, IDLE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Idle"].data());
	_grall["Move"].resize(MOVE_ANIMEMAX);
	ResourceServer::LoadDivGraph(MOVE_GRAPHNAME, MOVE_ANIMEMAX, MOVE_WIDTHCOUNT, MOVE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Move"].data());
	_grall["MiddleAttack"].resize(MIDDLEATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(MIDDLEATTACK_GRAPHNAME, MIDDLEATTACK_ANIMEMAX, MIDDLEATTACK_WIDTHCOUNT, MIDDLEATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["MiddleAttack"].data());
	_grall["LowAttack"].resize(LOWATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(LOWATTACK_GRAPHNAME, LOWATTACK_ANIMEMAX, LOWATTACK_WIDTHCOUNT, LOWATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["LowAttack"].data());
	_grall["Kick"].resize(KICK_ANIMEMAX);
	ResourceServer::LoadDivGraph(KICK_GRAPHNAME, KICK_ANIMEMAX, KICK_WIDTHCOUNT, KICK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Kick"].data());
	_grall["Iai"].resize(IAI_ANIMEMAX);
	ResourceServer::LoadDivGraph(IAI_GRAPHNAME, IAI_ANIMEMAX, IAI_WIDTHCOUNT, IAI_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Iai"].data());
	_grall["Sway"].resize(SWAY_ANIMEMAX);
	ResourceServer::LoadDivGraph(SWAY_GRAPHNAME, SWAY_ANIMEMAX, SWAY_WIDTHCOUNT, SWAY_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Sway"].data());
	_grall["Damage"].resize(DAMAGE_ANIMEMAX);
	ResourceServer::LoadDivGraph(DAMAGE_GRAPHNAME, DAMAGE_ANIMEMAX, DAMAGE_WIDTHCOUNT, DAMAGE_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Damage"].data());
	_grall["Dead"].resize(DEAD_ANIMEMAX);
	ResourceServer::LoadDivGraph(DEAD_GRAPHNAME, DEAD_ANIMEMAX, DEAD_WIDTHCOUNT, DEAD_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Dead"].data());
	_grall["Special"].resize(SPECIALATTACK_ANIMEMAX);
	ResourceServer::LoadDivGraph(SPECIALATTACK_GRAPHNAME, SPECIALATTACK_ANIMEMAX, SPECIALATTACK_WIDTHCOUNT, SPECIALATTACK_HEIGHTCOUNT, GRAPH_WIDTH, GRAPH_HEIGHT, _grall["Special"].data());
}

//効果音読み込み関数
void Player::LoadSE() {
	_se["BStartGame"] = ResourceServer::LoadSoundMem("se/Player/BStartGame.wav");
	_se["Walk"] = ResourceServer::LoadSoundMem("se/Player/Footstep.wav");
	_se["MiddleAttack"] = ResourceServer::LoadSoundMem("se/Player/MiddleAttack.wav");
	_se["LowAttack"] = ResourceServer::LoadSoundMem("se/Player/LowAttack.wav");
	_se["Kick"] = ResourceServer::LoadSoundMem("se/Player/Kick.wav");
	_se["Sway"] = ResourceServer::LoadSoundMem("se/Player/Sway.wav");
	_se["Stair"] = ResourceServer::LoadSoundMem("se/Player/Stair.wav");
	_se["Damage"] = ResourceServer::LoadSoundMem("se/Player/Damage.wav");
	_se["Dead"] = ResourceServer::LoadSoundMem("se/Player/Dead.wav");
	_se["Iai"] = ResourceServer::LoadSoundMem("se/Player/Iai.wav");
	_se["Gage"] = ResourceServer::LoadSoundMem("se/Player/Gage.wav");
	_se["Special"] = ResourceServer::LoadSoundMem("se/Player/SpecialAttack.wav");
}

//効果音ボリューム初期値設定関数
void	Player::VolumeInit() {
	_vpal["BStartGame"] = 200;
	_vpal["Walk"] = 255;
	_vpal["MiddleAttack"] = 255;
	_vpal["LowAttack"] = 255;
	_vpal["Kick"] = 255;
	_vpal["Sway"] = 255;
	_vpal["Stair"] = 255;
	_vpal["Damage"] = 255;
	_vpal["Dead"] = 255;
	_vpal["Iai"] = 255;
	_vpal["Gage"] = 255;
	_vpal["Special"] = 255;
}

//ボリューム変更関数
void	Player::VolumeChange() {
	ChangeVolumeSoundMem(_vpal["BStartGame"],_se["BStartGame"]);
	ChangeVolumeSoundMem(_vpal["Walk"], _se["Walk"]);
	ChangeVolumeSoundMem(_vpal["MiddleAttack"], _se["MiddleAttack"]);
	ChangeVolumeSoundMem(_vpal["LowAttack"], _se["LowAttack"]);
	ChangeVolumeSoundMem(_vpal["Kick"], _se["Kick"]);
	ChangeVolumeSoundMem(_vpal["Sway"], _se["Sway"]);
	ChangeVolumeSoundMem(_vpal["Stair"], _se["Stair"]);
	ChangeVolumeSoundMem(_vpal["Damage"], _se["Damage"]);
	ChangeVolumeSoundMem(_vpal["Dead"], _se["Dead"]);
	ChangeVolumeSoundMem(_vpal["Iai"], _se["Iai"]);
	ChangeVolumeSoundMem(_vpal["Gage"], _se["Gage"]);
	ChangeVolumeSoundMem(_vpal["Special"], _se["Special"]);
}
//プレイヤーの被ダメ&押し出し&各イベントブロック判定の処理
void	Player::HitJudge(Game& g) {
	//ボスステージのイベント処理状態遷移用処理
	if (_bosseventA_flag == true) {
		_action_cnt = _cnt;
		_state = PLAYERSTATE::EVENTA;
		_bosseventA_flag = false;
	}
	if (_bosseventB_flag == true) {
		_action_cnt = _cnt;
		_state = PLAYERSTATE::EVENTB;
		_bosseventB_flag = false;
	}
	//待機と移動時のみ階段判定を受け付ける処理
	if (_state == PLAYERSTATE::IDLE || _state == PLAYERSTATE::MOVE) {
		_stairup_flag = true;
	}
	else { _stairup_flag = false; }
/*----------各当たり判定の処理----------*/
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		OBJECTTYPE objType = (*ite)->GetObjType();
		switch (objType) {
			//各敵の攻撃
		case ObjectBase::OBJECTTYPE::BUSHIATTACK:
		case ObjectBase::OBJECTTYPE::BUSYOATTACK:
		case ObjectBase::OBJECTTYPE::NINJAATTACK:
		case ObjectBase::OBJECTTYPE::ZYOUNINATTACK:
		case ObjectBase::OBJECTTYPE::SHIELDERATTACK:
		case ObjectBase::OBJECTTYPE::LANCERATTACK:
		case ObjectBase::OBJECTTYPE::POISON:
		case ObjectBase::OBJECTTYPE::KUNAI:
			//敵の攻撃に当たったならダメージ状態へ移行
			if (IsHit(*(*ite)) == true && _star_flag == false&&_nohit_flag==false)
			{
				(*ite)->Delete(g);
				_life--;	
				_action_cnt = _cnt;
				_state = PLAYERSTATE::DAMAGE;
				//SE
				PlaySoundMem(_se["Damage"], DX_PLAYTYPE_BACK, true);
			}
			break;
		//階段
		case ObjectBase::OBJECTTYPE::STAIR:
			if (IsHit(*(*ite)) == true&&_stairup_flag==true)
			{
				//階段に当たっている状態で上入力したなら階段位置調整状態へ移行
				if (g.GetKey() & PAD_INPUT_UP && g.GetYBuf() < -UP_YBUF) {
					_player_y = _y;
					_stair_x = (*ite)->GetX();
					_stairflip_flag = (*ite)->GetFlip();
					_state = PLAYERSTATE::STAIRMOVE;
				}
			}
			break;
			//ボス階段
		case ObjectBase::OBJECTTYPE::BOSSSTAIR:
			if (IsHit(*(*ite)) == true && _stairup_flag == true)
			{
				//階段に当たっている状態で上入力したならボス階段位置調整状態へ移行
				if (g.GetKey() & PAD_INPUT_UP && g.GetYBuf() < -UP_YBUF) {
					_player_y = _y;
					_stair_x = (*ite)->GetX();
					_stairflip_flag = (*ite)->GetFlip();
					_state = PLAYERSTATE::BOSSSTAIRMOVE;
				}
			}
			break;
			//敵
		case ObjectBase::OBJECTTYPE::ENEMY:
			//敵に当たっているなら前のX座標にする
			if ((*ite)->GetObjType() == OBJECTTYPE::ENEMY)
			{
				if (IsHit(*(*ite)) == true) {
					_x = _before_x;

				}
			}
			break;
			//回復ブロック
		case ObjectBase::OBJECTTYPE::RECOVERYBLOCK:
			//当たったならプレイヤーの体力を全回復させる
				if (IsHit(*(*ite)) == true) {
					(*ite)->Delete(g);
					_life = 3;
				}
				break;
			//炎演出ブロック
		case ObjectBase::OBJECTTYPE::FLAMEBLOCK:
			//当たったなら炎演出モード生成
			if (IsHit(*(*ite)) == true) {
				(*ite)->Delete(g);
				auto of = new OverlayFlame();
				g.GetMS()->Add(of, 1, "Flame");
				//炎上SEがなっていないなら炎上SE発生
				if (CheckSoundMem(g.GetBgm()["Flame"]) == 0) {
					PlaySoundMem(g.GetBgm()["Flame"], DX_PLAYTYPE_LOOP, true);
				}
			}
			break;
			//チュートリアルボード
		case ObjectBase::OBJECTTYPE::TUTORIALBOARD:
			//当たっているときのみチュートリアルヒットフラグをTRUEにする
			if (IsHit(*(*ite)) == true) {
				_tutorialhit_flag = true;
			}
			if (IsHit(*(*ite)) == false) {
				_tutorialhit_flag = false;
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
	ss << "カメラ割合=" << _camera_x << "\n";
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
//プレイヤー位置からのカメラ位置設定
void Player::CameraSetting(Game& g) {
	g.SetcvX(_x - (SCREEN_W * _camera_x / 1000));				// 背景の横中央にキャラを置く
	g.SetcvY(_y - (SCREEN_H * BACK_CAMERA_Y / 100));		// 背景の縦93%にキャラを置く
	if (g.GetcvX() < 0) { g.SetcvX(0); }
	if (g.GetcvX() > g.GetmapW() - SCREEN_W) { g.SetcvX(g.GetmapW() - SCREEN_W); }
	if (g.GetcvY() < 0) { g.SetcvY(0); }
	if (g.GetcvY() > g.GetmapH() - SCREEN_H) { g.SetcvY(g.GetmapH() - SCREEN_H); }

	auto GC = g.GetChip();
	GC->SetscrX(_x - (SCREEN_W * _camera_x / 1000));			// マップチップの横中央にキャラを置く
	GC->SetscrY(_y - (SCREEN_H * CHIP_CAMERA_Y / 100));		// マップチップの縦93%にキャラを置く
	if (GC->GetscrX() < 0) { GC->SetscrX(0); }
	if (GC->GetscrX() > GC->GetMSW() * GC->GetCSW() - SCREEN_W) { GC->SetscrX(GC->GetMSW() * GC->GetCSW() - SCREEN_W); }
	if (GC->GetscrY() < 0) { GC->SetscrY(0); }
	if (GC->GetscrY() > GC->GetMSH() * GC->GetCSH() - SCREEN_H) { GC->SetscrY(GC->GetMSH() * GC->GetCSH() - SCREEN_H); }
}

//再起からの開始かどうか確認する関数
void Player::RestartCheck(Game& g) {
	if (_restartcheck_flag == false) {
		//再起からの開始ならば抜刀状態から開始
		if (g.GetRestartFlag() == true) {
			_state = PLAYERSTATE::SWORDOUT;
		}
		else {
			//SE発生
			PlaySoundMem(_se["BStartGame"],DX_PLAYTYPE_BACK,true); }
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
		if (_cnt - _star_cnt == STAR_ALLFRAME) {
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
	//左スティック入力値が一定以上なら移動速度&アニメーション速度アップ
	if (xbuf >= RUN_XBUF || -RUN_XBUF >= xbuf) {
		_spd = RUNSPEED;
		_move_animespeed = ANIMESPEED_RUN;
	}
}
//ポーズの入力管理関数
void Player::PauseInput(Game& g) {
	//プレイヤーが待機状態または移動状態時のみ入力受付
	if (_state == PLAYERSTATE::IDLE || _state == PLAYERSTATE::MOVE) {
		_pauseinput_flag = true;
	}
	else { _pauseinput_flag = false; }
	//12ボタン押下でポーズ画面生成&ゲームの処理ストップ
	if (g.GetTrg() & PAD_INPUT_12 && _pauseinput_flag == true) {
		auto mp = new ModePause();
		g.GetMS()->Add(mp, 20, "Pause");
		auto mg = (ModeGame*)g.GetMS()->Get("Game");
		mg->SetStopObjProcess(true);
	}
}

//ゲージMAX時の自機発光&SE発生
void Player::GaugeMax(Game& g) {
	if (_iai_gauge == 5&& _gaugemax_flag ==false) {
		//自機発光パーティクル
		for (int i = 0; i < GAGEMAX_PARTICLE_QTY; i++)
		{
			std::pair<int, int> xy = std::make_pair(_x, _y);
			std::pair<double, double> dxy = std::make_pair(((rand() % GAGEMAX_PARTICLE_RANDOMX1) - GAGEMAX_PARTICLE_RANDOMX2) / GAGEMAX_PARTICLE_RANDOMX3, ((rand() % GAGEMAX_PARTICLE_RANDOMY1) - GAGEMAX_PARTICLE_RANDOMY2) / GAGEMAX_PARTICLE_RANDOMY3);
			auto gm = new GageMax(xy, dxy);
			g.GetOS()->Add(gm);
		}
		//SE
		PlaySoundMem(_se["Gage"], DX_PLAYTYPE_BACK, true);
		_gaugemax_flag = true;
	}
}