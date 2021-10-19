/*****************************************************************//**
 * \file   Game.h
 * \brief  ゲームクラス
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "BackGround.h"
#include "MapChip.h"
#include "Player.h"
#include "ObjectServer.h"
#include "ModeServer.h"
#include <unordered_map>

constexpr auto SCREEN_W = 1920;  //!< 画面の横解像度
constexpr auto SCREEN_H = 1080;  //!< 画面の縦解像度
constexpr auto SCREEN_DEPTH = 32;//!< １ドットあたりのビット数

/** ゲーム本体 */
class Game{
public:
   /**
    * \brief コンストラクタ
    */
   Game();
   /**
    * \brief デストラクタ
    */
   ~Game();
   /**
    * \brief フレーム処理:入力
    */
   void Input();
   /**
    * \brief フレーム処理:計算
    */
   void Process();
   /**
    * \brief フレーム処理:描画
    */
   void Draw();

   /**
    * \brief        キー入力の情報を返す関数
    * \return _gkey キー入力の情報
    */
   int GetKey() { return _gkey; }
   /**
    * \brief        キー入力のトリガ情報を返す関数
    * \return _gtrg キー入力のトリガ情報
    */
   int GetTrg() { return _gtrg; }
   /**
    * \brief        左ステッィクX入力量の情報を返す関数
    * \return _xbuf 左ステッィクX入力量の情報
    */
   int GetXBuf() { return _xbuf; }
   /**
    * \brief        左ステッィクY入力量の情報を返す関数
    * \return _ybuf 左ステッィクY入力量の情報
    */
   int GetYBuf() { return _ybuf; }
   /**
    * \brief         マップの縦幅を返す関数
    * \return _map_h マップの縦幅
    */
   int GetmapH() { return _map_h; }
   /**
    * \brief         マップの横幅を返す関数
    * \return _map_w マップの横幅
    */
   int GetmapW() { return _map_w; }
   /**
    * \brief        マップX座標を返す関数
    * \return _cv_x マップX座標
    */
   int GetcvX() { return _cv_x; }
   /**
    * \brief        カメラY座標を返す関数
    * \return _cv_y カメラY座標
    */
   int GetcvY() { return _cv_y; }
   /**
    * \brief                再起からの開始かどうかのフラグを返す関数
    * \return _restart_flag 再起からの開始かどうかのフラグ
    */
   bool GetRestartFlag() { return _restart_flag; }
   /**
    * \brief           マップチップクラスを返す関数
    * \return _mapchip マップチップクラス
    */
   MapChip* GetChip() { return _mapchip; }
   /**
    * \brief              モードサーバークラスを返す関数
    * \return _servermode モードサーバークラス
    */
   ModeServer* GetMS() { return _servermode; }
   /**
    * \brief              オブジェクトサーバークラスの参照を返す関数
    * \return &_objserver オブジェクトサーバークラス
    */
   ObjectServer* GetOS() { return &_objserver; }
   /**
    * \brief       BGMマップを返す関数
    * \return _bgm BGMマップ
    */
   std::unordered_map<std::string, int> GetBgm() { return _bgm; }
   /**
    * \brief        ボリュームマップを返す関数
    * \return _vpal ボリュームマップ
    */
   std::unordered_map<std::string, int> GetVpal() { return _vpal; }
   /**
    * \brief               チェックポイントフラグマップを返す関数
    * \return _cpoint_flag チェックポイントフラグマップ
    */
   std::unordered_map<std::string, bool> GetCPointFlag() { return  _cpoint_flag; }
   /**
    * \brief     カメラX座標を設定する関数
    * \param cvx カメラX座標
    */
   void SetcvX(int cvx) { _cv_x = cvx; }
   /**
    * \brief     カメラY座標を設定する関数
    * \param cvy カメラY座標
    */
   void SetcvY(int cvy) { _cv_y = cvy; }
   /**
    * \brief      マップ横幅を設定する関数
    * \param mapw マップ横幅
    */
   void SetmapW(int mapw) { _map_w = mapw; }
   /**
    * \brief      マップ縦幅を設定する関数
    * \param maph マップ縦幅
    */
   void SetmapH(int maph) { _map_h = maph; }
   /**
    * \brief             再起からの開始かどうかのフラグを設定する関数
    * \param restartflag 再起からの開始かどうかのフラグ
    */
   void SetRestartFlag(bool restartflag) { _restart_flag = restartflag; }
   /**
    * \brief            チェックポイントフラグマップを設定する関数
    * \param cpointflag チェックポイントフラグマップ
    */
   void SetCPointFlag(std::unordered_map<std::string, bool> cpointflag) { _cpoint_flag = cpointflag; }
   /**
    * \brief      ボリュームマップを設定する関数
    * \param vpal ボリュームマップ
    */
   void SetVpal(std::unordered_map<std::string, int> vpal) { _vpal = vpal; }
   /**
    * \brief BGMのボリューム初期化関数
    */
   void VolumeInit();

private:
   /**
    * \brief BGM読み込み関数
    */
   void LoadBgm();
   /**
    * \brief BGMボリューム変更関数
    */
   void VolumeChange();

   int _gkey;         //!< キー入力の情報
   int _gtrg;         //!< キー入力のトリガ情報
   int _xbuf;         //!< 左ステッィクX入力量
   int _ybuf;         //!< 左ステッィクY入力量
   int _gcnt;         //!< 毎フレーム+1するカウント
   int _cv_x;         //!< カメラX座標
   int _cv_y;         //!< カメラY座標
   int _map_w;        //!< マップ横幅
   int _map_h;        //!< マップ縦幅
   bool _restart_flag;//!< 再起からの開始かどうかのフラグ
   std::unordered_map<std::string, int> _bgm;          //!< BGMマップ
   std::unordered_map<std::string, int> _vpal;         //!< ボリュームマップ
   std::unordered_map<std::string, bool> _cpoint_flag; //!< チェックポイントフラグマップ

   MapChip* _mapchip;         //!< マップチップ
   ModeServer* _servermode;   //!< モードサーバー
   ObjectServer _objserver;   //!< オブジェクトを登録する
};
