#pragma once
#include "ObjectBase.h"

class TitleCursor :public ObjectBase {
public:
	TitleCursor();
	~TitleCursor();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::TITLECURSOR; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
private:
	enum class CURSOLSTATE { NOHIT, STARTHIT, EXHIT, ENDHIT };
	CURSOLSTATE _State;		//カーソルの状態変数
	Vector2 _velocityDir;	//速度方向
	int		_colortype;		//パーティクルの色指定
	bool	_Input_Flag;	//入力管理フラグ
};
