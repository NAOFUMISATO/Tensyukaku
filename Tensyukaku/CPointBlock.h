#pragma once
#include "ObjectBase.h"

class CPointBlock :public ObjectBase {
public:
	CPointBlock(std::string  cpointtype);
	~CPointBlock();
	virtual OBJECTTYPE	GetObjType() { return OBJECTTYPE::CPOINTBLOCK; }
	void Init()override;
	void Process(Game& g)override;
	void Draw(Game& g)override;
	void Delete(Game& g)override;
private:
	void CPointPosition();
	std::string  _cpoint_type;
};
//チェックポイント
namespace CPInfo {
	constexpr auto CPOINT_2A_X = 3600;
	constexpr auto CPOINT_2A_Y = 8600;
	constexpr auto CPOINT_3A_X = 250;
	constexpr auto CPOINT_3A_Y = 7840;
	constexpr auto CPOINT_4A_X = 5600;
	constexpr auto CPOINT_4A_Y = 7080;
	constexpr auto CPOINT_5A_X = 250;
	constexpr auto CPOINT_5A_Y =	6320;
	constexpr auto CPOINT_5B_X = 5500;
	constexpr auto CPOINT_5B_Y = 6320;
	constexpr auto CPOINT_8A_X = 5000;
	constexpr auto CPOINT_8A_Y = 4040;
	constexpr auto CPOINT_11A_X = 5600;
	constexpr auto CPOINT_11A_Y = 1760;
}