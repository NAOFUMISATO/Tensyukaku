#pragma once
#include "Stair.h"
#include <unordered_map>
class Game;
class GimikPlacement {
public:
	GimikPlacement(Game& g);
	~GimikPlacement();
	void Init(Game& g);
private:
	void StairAppear(Game& g);		//階段設定関数
	void AndonAppear(Game& g);		//行燈設定関数
	void RestObjAppear(Game& g);	//休息ポイント用掛け軸設定関数
};

namespace GInfo {
	/*----------各ギミックの位置&向き----------*/
	//階段
	constexpr auto  STAIR1A_X = 3665;	 constexpr auto STAIR1A_Y = 9360;	 constexpr auto STAIR1A_FLIP = false;
	constexpr auto  STAIR2A_X = 175;	 constexpr auto STAIR2A_Y = 8600;	 constexpr auto STAIR2A_FLIP = true;
	constexpr auto  STAIR3A_X = 5585;	 constexpr auto STAIR3A_Y = 7840;	 constexpr auto STAIR3A_FLIP = false;
	constexpr auto  STAIR4A_X = 175;	 constexpr auto STAIR4A_Y = 7080;	 constexpr auto STAIR4A_FLIP = true;
	constexpr auto  STAIR5A_X = 5585;	 constexpr auto STAIR5A_Y = 6320;	 constexpr auto STAIR5A_FLIP = false;
	constexpr auto  STAIR6A_X = 4015;	 constexpr auto STAIR6A_Y = 5560;	 constexpr auto STAIR6A_FLIP = true; 
	constexpr auto  STAIR6B_X = 3665;	 constexpr auto STAIR6B_Y = 5560;	 constexpr auto STAIR6B_FLIP = false;
	constexpr auto STAIR7A_X = 5585;	constexpr auto STAIR7A_Y = 4800;	constexpr auto STAIR7A_FLIP = false;
	constexpr auto STAIR7B_X = 2055;	constexpr auto STAIR7B_Y = 4800;	constexpr auto STAIR7B_FLIP = true;
	constexpr auto STAIR8A_X = 4900;	constexpr auto STAIR8A_Y = 4040;	constexpr auto STAIR8A_FLIP = true;
	constexpr auto STAIR9A_X = 175;		constexpr auto STAIR9A_Y = 3280;	constexpr auto STAIR9A_FLIP = true;
	constexpr auto STAIR10A_X = 5585;constexpr auto STAIR10A_Y = 2520;constexpr auto STAIR10A_FLIP = false;
	constexpr auto STAIR11A_X = 175;	constexpr auto STAIR11A_Y = 1760;	constexpr auto STAIR11A_FLIP = true;

	//行燈
	constexpr auto  ANDON5A_X = 3800;	 constexpr auto ANDON5A_Y = 6320;
	constexpr auto  ANDON5B_X = 4900;	 constexpr auto ANDON5B_Y = 6320;
	constexpr auto ANDON6A_X = 2800;	constexpr auto ANDON6A_Y = 5560;
	constexpr auto ANDON8A_X = 4900;	constexpr auto ANDON8A_Y = 4040;
	constexpr auto ANDON8B_X = 4000;	constexpr auto ANDON8B_Y = 4040;
	constexpr auto ANDON8C_X = 3700;	constexpr auto ANDON8C_Y = 4040;
	constexpr auto ANDON8D_X = 3400;	constexpr auto ANDON8D_Y = 4040;
	constexpr auto ANDON8E_X = 3000;	constexpr auto ANDON8E_Y = 4040;
	constexpr auto ANDON11A_X = 4900;	constexpr auto ANDON11A_Y = 1760;
	constexpr auto ANDON11B_X = 3800;constexpr auto ANDON11B_Y = 1760;
	constexpr auto ANDON11C_X = 2700;	constexpr auto ANDON11C_Y = 1760;
	constexpr auto ANDON11D_X = 1900;constexpr auto ANDON11D_Y =1760;
	constexpr auto ANDON11E_X = 1000;	constexpr auto ANDON11E_Y = 1760;
	//休息用ポイント
	constexpr auto  REST_POINT6A_X = 2100;	 constexpr auto REST_POINT6A_Y = 4800+370;
	constexpr auto  REST_POINT7A_X = 5500;	 constexpr auto REST_POINT7A_Y = 4040+370;
}