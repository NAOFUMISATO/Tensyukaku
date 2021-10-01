#pragma once
#include "ObjectBase.h"
class TitleLogo :public ObjectBase {
public:
	TitleLogo();
	~TitleLogo();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::TITLELOGO; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};
class GameStart :public ObjectBase {
public:
	GameStart();
	~GameStart();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::GAMESTART; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};

class Explain :public ObjectBase {
public:
	Explain();
	~Explain();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::EXPLAIN; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};

class GameEnd :public ObjectBase {
public:
	GameEnd();
	~GameEnd();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::GAMEEND; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};

class Credit :public ObjectBase {
public:
	Credit();
	~Credit();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::CREDIT; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
};