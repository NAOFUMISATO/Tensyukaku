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
	CURSOLSTATE _State;		//�J�[�\���̏�ԕϐ�
	Vector2 _velocityDir;	//���x����
	int		_colortype;		//�p�[�e�B�N���̐F�w��
};
