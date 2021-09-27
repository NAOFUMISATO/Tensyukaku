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
	int		GetKey() { return _gkey; }
	int		GetTrg() { return _gtrg; }
	int		GetXBuf() { return _xbuf; }
	int		GetYBuf() { return _ybuf; }
	int		GetmapH() { return _map_h; }
	int		GetmapW() { return _map_w; }
	int		GetcvX() { return _cv_x; }
	int		GetcvY() { return _cv_y; }
	bool		GetCPointFlag() { return _cpoint_flag; }
	bool		GetRestartFlag() { return _restart_flag; }
	bool		GetTutorial1Flag() { return _tutorial1_flag; }
	bool		GetTutorial2Flag() { return _tutorial2_flag; }
	bool		GetTutorial3Flag() { return _tutorial3_flag; }
	bool		GetTutorial4Flag() { return _tutorial4_flag; }
	bool		GetTutorial5Flag() { return _tutorial5_flag; }

	MapChip* GetChip() { return _mapchip; }
	ModeServer* GetMS() { return _servermode; }
	ObjectServer* GetOS() { return &_objserver; }
	std::unordered_map<std::string, int> GetBgm() { return _bgm; }
	std::unordered_map<std::string, int> GetVpal() { return _vpal; }
	//セッター関数
	void	SetcvX(int cvX) { _cv_x = cvX; }
	void	SetcvY(int cvY) { _cv_y = cvY; }
	void	SetmapW(int mapW) { _map_w = mapW; }
	void	SetmapH(int mapH) { _map_h = mapH; }
	void	SetChip(MapChip* map) { _mapchip = map; }
	void	SetCPointFlag(bool cpointflag) { _cpoint_flag = cpointflag; }
	void	SetRestartFlag(bool restartflag) { _restart_flag = restartflag; }
	void	SetTutorial1Flag(bool tutorial1flag) { _tutorial1_flag=tutorial1flag; }
	void	SetTutorial2Flag(bool tutorial2flag) { _tutorial2_flag=tutorial2flag; }
	void	SetTutorial3Flag(bool tutorial3flag) { _tutorial3_flag=tutorial3flag; }
	void	SetTutorial4Flag(bool tutorial4flag) { _tutorial4_flag=tutorial4flag; }
	void	SetTutorial5Flag(bool tutorial5flag) { _tutorial5_flag=tutorial5flag; }
	void   SetVpal(std::unordered_map<std::string, int> vpal) { _vpal = vpal; }
private:
	void		LoadBgm();	//BGM読み込み
	void		VolumeInit();//BGMのボリューム初期値
	void		VolumeChange();//BGMのボリューム変更関数

	int _gkey;			// キー入力の情報
	int _gtrg;			// キー入力のトリガ情報
	int	_xbuf;			//左ステッィクX入力量
	int	_ybuf;			//左ステッィクY入力量
	int _gcnt;			// 毎フレーム+1するカウント
	int	_cv_x, _cv_y;		// カメラ
	int _map_w, _map_h;	// マップ
	bool _cpoint_flag;	//チェックポイントフラグ
	bool _restart_flag;//再起からの開始かどうかのフラグ
	bool _tutorial1_flag;//チュートリアル1の出現フラグ
	bool _tutorial2_flag;//チュートリアル2の出現フラグ
	bool _tutorial3_flag;//チュートリアル3の出現フラグ
	bool _tutorial4_flag;//チュートリアル4の出現フラグ
	bool _tutorial5_flag;//チュートリアル5の出現フラグ
	std::unordered_map<std::string, int> _bgm; //BGMマップ
	std::unordered_map<std::string, int> _vpal; //ボリュームマップ

	MapChip* _mapchip;			//マップチップ
	ModeServer* _servermode;	//モードサーバー
	ObjectServer _objserver;	//プレイヤーや敵などを登録する
};
