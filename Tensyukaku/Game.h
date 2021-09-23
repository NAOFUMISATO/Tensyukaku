#pragma once
#include	"BackGround.h"
#include	"MapChip.h"
#include	"Player.h"
#include	"ObjectServer.h"
#include	"ModeServer.h"
#include	<unordered_map>

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
	int		GetXBuf() { return _Xbuf; }
	int		GetYBuf() { return _Ybuf; }
	int		GetmapH() { return _mapH; }
	int		GetmapW() { return _mapW; }
	int		GetcvX() { return _cvX; }
	int		GetcvY() { return _cvY; }
	int		GetCPointFlag() { return _CPoint_Flag; }
	MapChip* GetChip() { return _mapChip; }
	ModeServer* GetMS() { return _serverMode; }
	ObjectServer* GetOS() { return &_objServer; }
	std::unordered_map<std::string, int> GetBgm() { return _Bgm; }
	std::unordered_map<std::string, int> GetVpal() { return _Vpal; }
	//セッター関数
	void	SetcvX(int cvX) { _cvX = cvX; }
	void	SetcvY(int cvY) { _cvY = cvY; }
	void	SetmapW(int mapW) { _mapW = mapW; }
	void	SetmapH(int mapH) { _mapH = mapH; }
	void	SetChip(MapChip* map) { _mapChip = map; }
	void	SetCPointFlag(bool cpointflag) { _CPoint_Flag = cpointflag; }
	void   SetVpal(std::unordered_map<std::string, int> vpal) { _Vpal = vpal; }
private:
	void		LoadBgm();	//BGM読み込み
	void		VolumeInit();//BGMのボリューム初期値
	void		VolumeChange();//BGMのボリューム変更関数

	int _gKey;			// キー入力の情報
	int _gTrg;			// キー入力のトリガ情報
	int	_Xbuf;			//左ステッィクX入力量
	int	_Ybuf;			//左ステッィクY入力量
	int _gCnt;			// 毎フレーム+1するカウント
	int	_cvX, _cvY;		// カメラ
	int _mapW, _mapH;	// マップ
	bool _CPoint_Flag;	//チェックポイントフラグ
	std::unordered_map<std::string, int> _Bgm; //BGMマップ
	std::unordered_map<std::string, int> _Vpal; //ボリュームマップ

	MapChip* _mapChip;			//マップチップ
	ModeServer* _serverMode;	//モードサーバー
	ObjectServer _objServer;	//プレイヤーや敵などを登録する
};
