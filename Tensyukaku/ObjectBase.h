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
	//�I�u�W�F�N�g�̏�ԗ�
	enum class OBJECTSTATE {
		ALLIBE,DEAD
	};
	//�I�u�W�F�N�g�̎�ޗ�
	enum class OBJECTTYPE {
		TITLELOGO,GAMESTART, EXPLAIN,GAMEEND, CURSOR,
		OVERLOGO,OVERRETRY,OVERGOTITLE,OVERBLACK,OVERCURSOR,
		PLAYER, ENEMY,BOSS, UI, PARTICLE,
		MIDDLEATTACK, LOWATTACK, KICK, IAI,SPECIAL,
		PRIVATECOLLISION,BUSHIATTACK,NINJAATTACK,KUNAI,SHIELDERATTACK,SHIELD, LANCERATTACK,BUSYOATTACK,ZYOUNINATTACK,
		STAIR,BOSSSTAIR, RESTPOINT,POISONNINJA,POISONZYOUNIN, POISON,STRPOISON,ANDON,FLAME, MUGENANDON,MUGENFLAME,SPAWNBLOCK, EVENTBLOCK, RECOVERYBLOCK,CPOINTBLOCK,BOSSEVENTBLOCK,FLAMEBLOCK, TUTORIALBOARD,BOSSSPAWN
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
	int		GetHp() { return _life; }
	int		GetGauge() { return _iai_gauge; }
	int		GetSpd() { return _spd; }
	int		GetSort() { return _sort; }
	bool	GetFlip() { return _isflip; }
	HitBox	GetHB() { return { _x,_y,_gx,_gy,_hit_x,_hit_y,_hit_w,_hit_h }; }
	Vector2 GetPosition() { return _position; }		//���W�̎擾
	bool isDead() const { return _ostate == OBJECTSTATE::DEAD; }

	void	SetGauge(int ig) {_iai_gauge=ig; }
	void	SetPosition(int x, int y) { _x = x; _y = y; }
	void	SetX(int x) { _x = x; }
	void	SetY(int y) { _y = y; }
	void	SetFlip(bool isflip) { _isflip = isflip; }
	void	SetBEventA(bool beventAflag) { _bosseventA_flag =beventAflag; }
	void	SetBEventB(bool beventBflag) { _bosseventB_flag =beventBflag; }
	
	
protected:
	Vector2 _position;	// �ʒu�x�N�g��
	OBJECTSTATE _ostate;// �I�u�W�F�N�g�̏�ԗ񋓕ϐ�
	int		_grhandle;	// �摜�n���h��
	std::unordered_map<std::string, std::vector<int>> _grall;	//�S�Ẳ摜�n���h���}�b�v
	std::unordered_map<std::string, int> _anime;				//�A�j���[�V�����}�b�v
	std::unordered_map<std::string, int> _se;					//SE�}�b�v
	std::unordered_map<std::string, int> _vpal;					//�{�����[���}�b�v
	int		_x, _y;		// ���W�i��ʒu�j
	int		_gx, _gy;	// ��ʒu����`�掞�̍���
	int		_w, _h;		// �傫��
	int		_life;		// �̗�
	int		_spd;		// �ړ����x
	bool	_isflip;	//�@���]����
	int		_alpha;		//�@�����x
	int		_iai_gauge;	// �����Q�[�W
	int		_hit_x, _hit_y;				//�`��_���獶����W�܂ł̍���
	int		_hit_w, _hit_h;				//�����蔻��̕�
	bool	_draw_flag;					//XY���W����ʓ��Ȃ�Ε`�悷��t���O
	int		_dx;						//�`�攻��p�ϐ�
	int		_dy;						//�`�攻��p�ϐ�
	std::pair <int, int>_hit_judge;		//�����蔻��p�ϐ�
	std::pair <double, double>_drg;		//DrawRotaGraph�p�ϐ�
	int		_debug_alpha;					//�f�o�b�N�p��`�����x
	bool	_debug_fill;						//�f�o�b�O�p��`�h��Ԃ��t���O
	std::tuple<int, int,int>_debug_color;		//�f�o�b�N�p��`�J���[
	int		_cnt;						//����J�E���^
	int		_action_cnt;				//�A�N�V�����o�ߎ��ԕۑ��ϐ�
	int		_before_x;					//�O���X���W�ۑ��ϐ�
	int		_before_y;					//�O���Y���W�ۑ��ϐ�
	bool	_bosseventA_flag;				//�{�X�C�x���gA�t���O
	bool	_bosseventB_flag;				//�{�X�C�x���gB�t���O
	int		_sort;
};
