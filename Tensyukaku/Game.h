#pragma once
#include	"BackGround.h"
#include	"MapChip.h"
#include	"Player.h"
#include	"ObjectServer.h"
#include	"ModeServer.h"
namespace Tsk {
	// 画面設定
	constexpr auto SCREEN_W = 1920;		///< 画面の横解像度
	constexpr auto SCREEN_H = 1080;		///< 画面の縦解像度
	constexpr auto SCREEN_DEPTH = 32;   ///< １ドットあたりのビット数


	// ゲームクラス
	class Game
	{
	public:
		Game();				// アプリの初期化
		~Game();			// アプリの解放

		void	Input();		// フレーム処理：入力
		void	Process();		// フレーム処理：計算
		void	Draw();		// フレーム処理：描画

		//ゲッター関数
		int		GetKey() { return _gKey; }
		int		GetTrg() { return _gTrg; }
		int		GetmapH() { return _mapH; }
		int		GetcvX() { return _cvX; }
		int		GetcvY() { return _cvY; }
		BackGround	GetBg() { return _bg; }
		ModeServer* GetMS() { return _serverMode; }
		ObjectServer* GetOS() { return &_objServer; }
	/*	MapChips GetChips() { return _mapChips; }*/
		//セッター関数
		void	SetcvX(int cvX) { cvX = _cvX; }
		void	SetcvY(int cvY) { cvY = _cvY; }
		void	SetmapW(int mapW) { mapW = _mapW; }
		void	SetmapH(int mapH) { mapH = _mapH; }

	private:
		int _gKey;			// キー入力の情報
		int _gTrg;			// キー入力のトリガ情報
		int _gCnt;			// 毎フレーム+1するカウント
		int	_cvX, _cvY;		// カメラ
		int _mapW, _mapH;	// マップ

		BackGround	_bg;	// 背景
		ModeServer* _serverMode; //モードサーバー
		ObjectServer _objServer; // プレイヤーや敵などを登録する
		//MapChips	_mapChips; // マップチップ
	};
}