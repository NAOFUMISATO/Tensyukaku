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
	void	HitJudge(Game& g);//�e�����蔻��̏���
	void LoadSE();//���ʉ��ǂݍ��݊֐�
	void	VolumeInit();	//���ʉ��{�����[�������l�ݒ�֐�
	void	VolumeChange();	//�{�����[���ύX�֐�
	
	enum class CURSOLSTATE { NOHIT, STARTHIT, EXHIT, ENDHIT,CREDITHIT};
	CURSOLSTATE _state;		//�J�[�\���̏�ԕϐ�
	Vector2 _velocityDir;	//���x����
	std::string	_hit_type;		//�p�[�e�B�N���̃^�C�v�w��
	int		_par_qty;
	bool	_input_flag;	//���͊Ǘ��t���O
	bool	_startpush_flag;
	bool	_endpush_flag;
	bool	_creditpush_flag;
};

namespace CuInfo{
	constexpr auto NOHIT_PARQTY = 7;
	constexpr auto HIT_PARQTY =10;
}