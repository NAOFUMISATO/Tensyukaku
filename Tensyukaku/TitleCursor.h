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
	CURSOLSTATE _State;		//�J�[�\���̏�ԕϐ�
	Vector2 _velocityDir;	//���x����
	int		_colortype;		//�p�[�e�B�N���̐F�w��
	bool	_Input_Flag;	//���͊Ǘ��t���O
};
