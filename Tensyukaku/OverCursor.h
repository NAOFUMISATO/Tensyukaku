#pragma once
#include "ObjectBase.h"

class OverCursor : public ObjectBase {
public:
	OverCursor();
	~OverCursor();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::OVERCURSOR; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
private:
	enum class CURSOLSTATE { NOHIT, RETRYHIT, GOTITLEHIT};
	CURSOLSTATE _State;		//カーソルの状態変数
	Vector2 _velocityDir;	//速度方向
	int		_colortype;		//パーティクルの色指定
	bool	_Input_Flag;	//入力管理フラグ
};