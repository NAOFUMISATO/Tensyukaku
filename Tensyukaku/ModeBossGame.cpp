//#include "DxLib.h"
//#include "ModeBossGame.h"
//#include "Game.h"
//#include "Player.h"
//#include "PlayerHp.h"
//#include "IaiGauge.h"
//
//bool ModeBossGame::Initialize(Game& g) {
//	if (!base::Initialize(g)) { return false; }
//	g.GetOS()->Add(new Player);
//	_Apeear_Flag = false;
//	_stopObjProcess = false;
//
//	// �J�������}�b�v������
//	g.SetmapW(5760);
//	g.SetmapH(7920);
//	g.SetcvX(0);
//	g.SetcvY(g.GetmapH() - SCREEN_H);
//	// BGM���t�J�n	
//	_bgm = PlaySoundFile("bgm/InGame70dB.mp3", DX_PLAYTYPE_LOOP);
//	return true;
//}
//
//bool ModeBossGame::Terminate(Game& g) {
//	base::Terminate(g);
//	delete g.GetChip();
//	g.GetOS()->Clear();
//	return true;
//}
//
//bool ModeBossGame::Process(Game& g) {
//	base::Process(g);
//	if (_stopObjProcess == false)
//	{
//		g.GetChip()->Process(g);
//		g.GetOS()->Process(g);
//		if (_Apeear_Flag == false) {
//			_Apeear_Flag = true;
//			
//		}
//
//	}
//
//	return true;
//}
//
//bool ModeBossGame::Draw(Game& g) {
//	base::Draw(g);
//
//	_bg.Draw(g);				// �w�i�摜�`��
//	g.GetChip()->Draw();			//�}�b�v�`�b�v�`��
//	g.GetOS()->Draw(g);				// �I�u�W�F�N�g�̕`��
//	return true;
//}
