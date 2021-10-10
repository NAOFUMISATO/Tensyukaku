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

	int		_grhandle;									//�摜�n���h��
	int		_x;											//�`��_X���W
	int		_y;											//�`��_Y���W
	int		_cnt;										//����J�E���^
	int		_mode_cnt;									//�o�ߎ��ԋL�^�ϐ�
	int		_pal;										//BlendMode�p�ϐ�
	int		_fade_speed;									//�t�F�[�h�X�s�[�h
	bool	_trans_flag;								//DrawRotaGraph�̓����x�t���O
	std::pair<double, double> _drg;						//DrawRotaGraph�p�y�A�ϐ��ifirst�g�k���Asecond�p�x�j
	std::tuple<int, int, int> _rgb;						//Color�p�^�v���^�ϐ�
	std::unordered_map<std::string, std::vector<int>> _grall;		//�S�Ẳ摜�n���h���}�b�v
	std::unordered_map<std::string, int> _anime;							//�A�j���[�V�����}�b�v
	std::unordered_map<std::string, int> _se;									//SE�}�b�v
	std::unordered_map<std::string, int> _vpal;								//�{�����[���}�b�v
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
};



