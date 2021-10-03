#pragma once
#include "ObjectBase.h"

class Cursor :public ObjectBase {
public:
	Cursor();
	~Cursor();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::CURSOR; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
private:
	void	HitJudge(Game& g);//各当たり判定の処理
	void LoadSE();//効果音読み込み関数
	void	VolumeInit();	//効果音ボリューム初期値設定関数
	void	VolumeChange();	//ボリューム変更関数
	
	enum class CURSOLSTATE { NOHIT, STARTHIT, EXHIT, ENDHIT,CREDITHIT};
	CURSOLSTATE _state;		//カーソルの状態変数
	Vector2 _velocityDir;	//速度方向
	std::string	_hit_type;		//パーティクルのタイプ指定
	int		_par_qty;
	bool	_input_flag;	//入力管理フラグ
	bool	_startpush_flag;
	bool	_endpush_flag;
	bool	_creditpush_flag;
};

namespace CuInfo{
	constexpr auto NOHIT_PARQTY = 7;
	constexpr auto HIT_PARQTY =10;
}