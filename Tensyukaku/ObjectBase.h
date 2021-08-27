#pragma once
#include "HitBox.h"
#include <vector>
#include "Math.h"
#include <utility>
#include <tuple>
#include <unordered_map>

class Game;
// �I�u�W�F�N�g�N���X
class ObjectBase {
public:
	ObjectBase();
	~ObjectBase();
	//�I�u�W�F�N�g�̎�ޗ�
	enum class OBJECTTYPE {
		PLAYER, ENEMY,UI,PARTICLE,STAIR,
		MIDDLEATTACK, LOWATTACK, KICK, IAI,
		BUSHIPATROL, BUSHICOMING, BUSHIATTACK,
		NINJAPATROL, NINJACOMING, NINJAATTACK,
		SHIELDERPATROL,SHIELDERCOMING,SHIELDERATTACK,SHIELD,
		SCENARIO,ENEMYSPAWN
	};
	virtual OBJECTTYPE	GetObjType() = 0;

	virtual	void	Init();
	virtual	void	Process(Game& g);
	virtual	void	Draw(Game& g);
	virtual	bool	IsHit(ObjectBase& o);
	virtual	void	Delete(Game& g) {};

	
	int		GetX() { return _x; }
	int		GetY() { return _y; }
	int		GetGX() { return _gx; }
	int		GetGY() { return _gy; }
	int		GetW() { return _w; }
	int		GetH() { return _h; }
	int		GetHitW() { return _hit_w; }
	int		GetHitH() { return _hit_h; }
	int		GetHitX() { return _hit_x; }
	int		GetHitY() { return _hit_y; }
	bool	GetFlip() { return _isFlip; }
	HitBox	GetHB() { return { _x,_y,_gx,_gy,_hit_x,_hit_y,_hit_w,_hit_h }; }
	Vector2 GetPosition() { return _Position; }		//���W�̎擾

	void	SetPosition(int x, int y) { _x = x; _y = y; }
	void	SetX(int x) { _x = x; }
	void	SetY(int y) { _y = y; }
	void	SetFlip(bool isflip) { _isFlip = isflip; }
	
protected:
	Vector2 _Position;	// �ʒu�x�N�g��
	int		_GrHandle;	// �摜�n���h��
	std::unordered_map<std::string, std::vector<int>> _GrAll;	//�S�Ẳ摜�n���h���}�b�v
	std::unordered_map<std::string, int> _Anime;				//�A�j���[�V�����}�b�v
	std::unordered_map<std::string, int> _Se;					//SE�}�b�v
	int		_x, _y;		// ���W�i��ʒu�j
	int		_gx, _gy;	// ��ʒu����`�掞�̍���
	int		_w, _h;		// �傫��
	int		_Life;		// �̗�
	int		_Spd;		// �ړ����x
	bool	_isFlip;	//���]����
	int		_hit_x, _hit_y;				//�`��_���獶����W�܂ł̍���
	int		_hit_w, _hit_h;				//�����蔻��̕�
	std::pair <int, int>_hit_judge;		//�����蔻��p�ϐ�
	std::pair <double, double>_Drg;		//DrawRotaGraph�p�ϐ�
	int		_Dalpha;					//�f�o�b�N�p��`�����x
	bool	_Fill;						//�f�o�b�O�p��`�h��Ԃ��t���O
	std::tuple<int, int,int>_Color;		//�f�o�b�N�p��`�J���[
	int		_Cnt;						//����J�E���^
	int		_Action_Cnt;				//�A�N�V�����o�ߎ��ԕۑ��ϐ�
	
};
