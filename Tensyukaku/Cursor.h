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
	enum class CURSOLSTATE { NOHIT, STARTHIT, EXHIT, ENDHIT };
	CURSOLSTATE _State;		//カーソルの状態変数
	Vector2 _velocityDir;	//速度方向
	int		_colortype;		//パーティクルの色指定
};
