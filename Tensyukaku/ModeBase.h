#pragma once
#include	<string>
#include	<tuple>
#include	<utility>
#include	<unordered_map>
class ModeServer;
class Game;


class		ModeBase
{
public:
	ModeBase();
	virtual ~ModeBase();

	virtual bool	Initialize(Game& g);
	virtual bool	Terminate(Game& g);
	virtual bool	Process(Game& g);
	virtual bool	Draw(Game& g);
protected:

	int		_GrHandle;									//�摜�n���h��
	int		_x;											//�`��_X���W
	int		_y;											//�`��_Y���W
	int		_Cnt;										//����J�E���^
	int		_Mode_Cnt;									//�o�ߎ��ԋL�^�ϐ�
	int		_Pal;										//BlendMode�p�ϐ�
	int		_FadeSpeed;									//�t�F�[�h�X�s�[�h
	int		_bgm;										//BGM�n���h��
	bool	_Trans_Flag;								//DrawRotaGraph�̓����x�t���O
	std::pair<double, double> _drg;						//DrawRotaGraph�p�y�A�ϐ��ifirst�g�k���Asecond�p�x�j
	std::tuple<int, int, int> _rgb;						//Color�p�^�v���^�ϐ�
	std::unordered_map<std::string, std::vector<int>> _GrAll;		//�S�Ẳ摜�n���h���}�b�v
	std::unordered_map<std::string, int> _Anime;					//�A�j���[�V�����}�b�v
	std::unordered_map<std::string, int> _Se;						//SE�}�b�v

public:
	int	GetModeCount() { return _cntMode; }			// ���̃��[�h���n�܂��Ă���̃J�E���^
	unsigned long GetModeTm() { return _tmMode; }	// ���̃��[�h���n�܂��Ă���̎���ms
	unsigned long GetStepTm() { return _tmStep; }	// �O�t���[������̌o�ߎ���ms

	void SetCallPerFrame(int frame) { _callPerFrame = _callPerFrame_cnt = frame; }	// ���t���[����1��Process()���ĂԂ�(def:1)
	void SetCallOfCount(int count) { _callOfCount = count; }		// 1��̌Ăяo���ɉ���Process()���ĂԂ�(def:1)
	int GetCallPerFrame() { return _callPerFrame; }
	int GetCallOfCount() { return _callOfCount; }
private:
	friend	ModeServer;
	/*-----ModeServer�p-----*/
	std::string		_szName;
	int				_uid;
	int				_layer;

	void StepTime(unsigned long tmNow);
	void StepCount();

	// ���[�h�������p
	int		_cntMode;	// �{���[�h�ɓ����Ă���̃J�E���^, 0�X�^�[�g
	unsigned long	_tmMode;	// �{���[�h�ɓ����Ă���̎��ԁBms
	unsigned long	_tmStep;	// �O�t���[������̌o�ߎ��ԁBms
	unsigned long	_tmModeBase;	// ���̃��[�h���n�܂������ԁBms
	unsigned long	_tmPauseBase;	// �|�[�Y���̃x�[�X���ԁBms
	unsigned long	_tmPauseStep;	// �|�[�Y���̐ώZ���ԁBms ���쒆�A���̒l�� _tmMode �ɗp����
	unsigned long	_tmOldFrame;	// �O�t���[���̎��ԁBms

	// CallPerFrame / CallOfCount�p
	int		_callPerFrame, _callPerFrame_cnt;
	int		_callOfCount;

};



