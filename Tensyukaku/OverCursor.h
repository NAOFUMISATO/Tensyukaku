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
	CURSOLSTATE _State;		//�J�[�\���̏�ԕϐ�
	Vector2 _velocityDir;	//���x����
	int		_colortype;		//�p�[�e�B�N���̐F�w��
	bool	_Input_Flag;	//���͊Ǘ��t���O
};