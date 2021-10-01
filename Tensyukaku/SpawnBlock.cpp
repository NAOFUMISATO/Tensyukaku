#include "SpawnBlock.h"
#include "Game.h"
#include "Bushi.h"
#include "Busyo.h"
#include "Ninja.h"
#include "Zyounin.h"
#include "Shielder.h"
#include "Lancer.h"
#include "PoisonNinja.h"
#include "PoisonZyounin.h"
#include "Boss.h"

using namespace SpaInfo;
/*
	スポーンブロック
*/
Spawn::Spawn(std::string spawntype) {
	_spawn_type = spawntype;
	Init();
}
Spawn::~Spawn() {
}
void Spawn::Init() {
	_gx = 0;
	_gy = -50;
	_hit_x = -50;
	_hit_y = -50;
	_hit_w = 100;
	_hit_h = 100;
#ifdef _DEBUG
	_debug_color = std::make_tuple(255, 0, 255);
	_debug_alpha = 128;
	_debug_fill = true;
#endif
	SpawnPositon();
}
void Spawn::Process(Game& g) {
	ObjectBase::Process(g);
	//プレイヤーとの当たり判定
	for (auto ite = g.GetOS()->List()->begin(); ite != g.GetOS()->List()->end(); ite++)
	{
		// iteはプレイヤーか？
		if ((*ite)->GetObjType() == OBJECTTYPE::PLAYER)
		{
			if (IsHit(*(*ite)) == true) {
				Delete(g);
				if (_spawn_type == "1A") {
					auto bu2 = new Bushi(SPAWN1A_BUSHI2_X, SPAWN1A_BUSHI2_Y, SPAWN1A_BUSHI2_FLIP);
					g.GetOS()->Add(bu2);
					auto bu3 = new Bushi(SPAWN1A_BUSHI3_X, SPAWN1A_BUSHI3_Y, SPAWN1A_BUSHI3_FLIP);
					g.GetOS()->Add(bu3);
				}
				else if (_spawn_type == "1B") {
					auto bu1 = new Bushi(SPAWN1B_BUSHI1_X, SPAWN1B_BUSHI1_Y, SPAWN1B_BUSHI1_FLIP);
					g.GetOS()->Add(bu1);
					auto bu2 = new Bushi(SPAWN1B_BUSHI2_X, SPAWN1B_BUSHI2_Y, SPAWN1B_BUSHI2_FLIP);
					g.GetOS()->Add(bu2);
					auto bu3 = new Bushi(SPAWN1B_BUSHI3_X, SPAWN1B_BUSHI3_Y, SPAWN1B_BUSHI3_FLIP);
					g.GetOS()->Add(bu3);
					auto bu4 = new Bushi(SPAWN1B_BUSHI4_X, SPAWN1B_BUSHI4_Y, SPAWN1B_BUSHI4_FLIP);
					g.GetOS()->Add(bu4);
				}
				else if (_spawn_type == "2A") {
					auto ni1 = new Ninja(SPAWN2A_NINJA1_X, SPAWN2A_NINJA1_Y, SPAWN2A_NINJA1_FLIP, SPAWN2A_NINJA1_KUNAI);
					g.GetOS()->Add(ni1);
					auto ni2 = new Ninja(SPAWN2A_NINJA2_X, SPAWN2A_NINJA2_Y, SPAWN2A_NINJA2_FLIP, SPAWN2A_NINJA2_KUNAI);
					g.GetOS()->Add(ni2);
				}
				else if (_spawn_type == "2B") {
					auto ni1 = new Ninja(SPAWN2B_NINJA1_X, SPAWN2B_NINJA1_Y, SPAWN2B_NINJA1_FLIP, SPAWN2B_NINJA1_KUNAI);
					g.GetOS()->Add(ni1);
					auto ni2 = new Ninja(SPAWN2B_NINJA2_X, SPAWN2B_NINJA2_Y, SPAWN2B_NINJA2_FLIP, SPAWN2B_NINJA2_KUNAI);
					g.GetOS()->Add(ni2);
					auto ni3 = new Ninja(SPAWN2B_NINJA3_X, SPAWN2B_NINJA3_Y, SPAWN2B_NINJA3_FLIP, SPAWN2B_NINJA3_KUNAI);
					g.GetOS()->Add(ni3);
					auto ni4 = new Ninja(SPAWN2B_NINJA4_X, SPAWN2B_NINJA4_Y, SPAWN2B_NINJA4_FLIP, SPAWN2B_NINJA4_KUNAI);
					g.GetOS()->Add(ni4);
				}
				else if (_spawn_type == "3A") {
					auto la1 = new Lancer(SPAWN3A_LANCE1_X, SPAWN3A_LANCE1_Y, SPAWN3A_LANCE1_FLIP);
					g.GetOS()->Add(la1);
				}
				else if (_spawn_type == "3B") {
					auto la1 = new Lancer(SPAWN3B_LANCE1_X, SPAWN3B_LANCE1_Y, SPAWN3B_LANCE1_FLIP);
					g.GetOS()->Add(la1);
					auto la2 = new Lancer(SPAWN3B_LANCE2_X, SPAWN3B_LANCE2_Y, SPAWN3B_LANCE2_FLIP);
					g.GetOS()->Add(la2);
				}
				else if (_spawn_type == "3C") {
					auto sh1 = new Shielder(SPAWN3C_SHIEL1_X, SPAWN3C_SHIEL1_Y, SPAWN3C_SHIEL1_FLIP);
					g.GetOS()->Add(sh1);
					auto sh2 = new Shielder(SPAWN3C_SHIEL2_X, SPAWN3C_SHIEL2_Y, SPAWN3C_SHIEL2_FLIP);
					g.GetOS()->Add(sh2);
				}
				else if (_spawn_type == "3D") {
					auto sh1 = new Shielder(SPAWN3D_SHIEL1_X, SPAWN3D_SHIEL1_Y, SPAWN3D_SHIEL1_FLIP);
					g.GetOS()->Add(sh1);
					auto la1 = new Lancer(SPAWN3D_LANCE1_X, SPAWN3D_LANCE1_Y, SPAWN3D_LANCE1_FLIP);
					g.GetOS()->Add(la1);
				}
				else if (_spawn_type == "3E") {
					auto la1 = new Lancer(SPAWN3E_LANCE1_X, SPAWN3E_LANCE1_Y, SPAWN3E_LANCE1_FLIP);
					g.GetOS()->Add(la1);
				}
				else if (_spawn_type == "4A") {
					auto sh1 = new Shielder(SPAWN4A_SHIEL1_X, SPAWN4A_SHIEL1_Y, SPAWN4A_SHIEL1_FLIP);
					g.GetOS()->Add(sh1);
				}
				else if (_spawn_type == "4B") {
					auto bu1 = new Bushi(SPAWN4B_BUSHI1_X, SPAWN4B_BUSHI1_Y, SPAWN4B_BUSHI1_FLIP);
					g.GetOS()->Add(bu1);
					auto ni1 = new Ninja(SPAWN4B_NINJA1_X, SPAWN4B_NINJA1_Y, SPAWN4B_NINJA1_FLIP, SPAWN4B_NINJA1_KUNAI);
					g.GetOS()->Add(ni1);
				}
				else if (_spawn_type == "4C") {
					auto bu1 = new Bushi(SPAWN4C_BUSHI1_X, SPAWN4C_BUSHI1_Y, SPAWN4C_BUSHI1_FLIP);
					g.GetOS()->Add(bu1);
					auto la1 = new Lancer(SPAWN4C_LANCE1_X, SPAWN4C_LANCE1_Y, SPAWN4C_LANCE1_FLIP);
					g.GetOS()->Add(la1);
					auto ni1 = new Ninja(SPAWN4C_NINJA1_X, SPAWN4C_NINJA1_Y, SPAWN4C_NINJA1_FLIP, SPAWN4C_NINJA1_KUNAI);
					g.GetOS()->Add(ni1);
				}
				else if (_spawn_type == "4D") {
					auto sh1 = new Shielder(SPAWN4D_SHIEL1_X, SPAWN4D_SHIEL1_Y, SPAWN4D_SHIEL1_FLIP);
					g.GetOS()->Add(sh1);
					auto sh2 = new Shielder(900, 7080, true);
					g.GetOS()->Add(sh2);
				}
				else if (_spawn_type == "5A") {
					auto ni1 = new Ninja(SPAWN5A_NINJA1_X, SPAWN5A_NINJA1_Y, SPAWN5A_NINJA1_FLIP, SPAWN5A_NINJA1_KUNAI);
					g.GetOS()->Add(ni1);
					auto ni2 = new Ninja(SPAWN5A_NINJA2_X, SPAWN5A_NINJA2_Y, SPAWN5A_NINJA2_FLIP, SPAWN5A_NINJA2_KUNAI);
					g.GetOS()->Add(ni2);
					auto pn1 = new PoisonNinja(SPAWN5A_POIJA1_X, SPAWN5A_POIJA1_Y, SPAWN5A_POIJA1_FLIP);
					g.GetOS()->Add(pn1);
					auto pn2 = new PoisonNinja(SPAWN5A_POIJA2_X, SPAWN5A_POIJA2_Y, SPAWN5A_POIJA2_FLIP);
					g.GetOS()->Add(pn2);
					auto pn3 = new PoisonNinja(SPAWN5A_POIJA3_X, SPAWN5A_POIJA3_Y, SPAWN5A_POIJA3_FLIP);
					g.GetOS()->Add(pn3);
					auto pn4 = new PoisonNinja(SPAWN5A_POIJA4_X, SPAWN5A_POIJA4_Y, SPAWN5A_POIJA4_FLIP);
					g.GetOS()->Add(pn4);
					auto pn5 = new PoisonNinja(SPAWN5A_POIJA5_X, SPAWN5A_POIJA5_Y, SPAWN5A_POIJA5_FLIP);
					g.GetOS()->Add(pn5);
					auto pn6 = new PoisonNinja(SPAWN5A_POIJA6_X, SPAWN5A_POIJA6_Y, SPAWN5A_POIJA6_FLIP);
					g.GetOS()->Add(pn6);
					auto pn7 = new PoisonNinja(SPAWN5A_POIJA7_X, SPAWN5A_POIJA7_Y, SPAWN5A_POIJA7_FLIP);
					g.GetOS()->Add(pn7);
					auto pn8 = new PoisonNinja(SPAWN5A_POIJA8_X, SPAWN5A_POIJA8_Y, SPAWN5A_POIJA8_FLIP);
					g.GetOS()->Add(pn8);
				}
				else if (_spawn_type == "5B") {
					auto sh1 = new Shielder(SPAWN5B_SHIEL1_X, SPAWN5B_SHIEL1_Y, SPAWN5B_SHIEL1_FLIP);
					g.GetOS()->Add(sh1);
					auto sh2 = new Shielder(SPAWN5B_SHIEL2_X, SPAWN5B_SHIEL2_Y, SPAWN5B_SHIEL2_FLIP);
					g.GetOS()->Add(sh2);
				}
				else if (_spawn_type == "5C") {
					auto bu1 = new Bushi(SPAWN5C_BUSHI1_X, SPAWN5C_BUSHI1_Y, SPAWN5C_BUSHI1_FLIP);
					g.GetOS()->Add(bu1);
					auto bu2 = new Bushi(SPAWN5C_BUSHI2_X, SPAWN5C_BUSHI2_Y, SPAWN5C_BUSHI2_FLIP);
					g.GetOS()->Add(bu2);
					auto bu3 = new Bushi(SPAWN5C_BUSHI3_X, SPAWN5C_BUSHI3_Y, SPAWN5C_BUSHI3_FLIP);
					g.GetOS()->Add(bu3);
					auto bs1 = new Busyo(SPAWN5C_BUSYO1_X, SPAWN5C_BUSYO1_Y, SPAWN5C_BUSYO1_FLIP);
					g.GetOS()->Add(bs1);
					auto la1 = new Lancer(SPAWN5C_LANCE1_X, SPAWN5C_LANCE1_Y, SPAWN5C_LANCE1_FLIP);
					g.GetOS()->Add(la1);
					auto ni1 = new Ninja(SPAWN5C_NINJA1_X, SPAWN5C_NINJA1_Y, SPAWN5C_NINJA1_FLIP, SPAWN5C_NINJA1_KUNAI);
					g.GetOS()->Add(ni1);
					auto ni2 = new Ninja(SPAWN5C_NINJA2_X, SPAWN5C_NINJA2_Y, SPAWN5C_NINJA2_FLIP, SPAWN5C_NINJA2_KUNAI);
					g.GetOS()->Add(ni2);
					auto ni3 = new Ninja(SPAWN5C_NINJA3_X, SPAWN5C_NINJA3_Y, SPAWN5C_NINJA3_FLIP, SPAWN5C_NINJA3_KUNAI);
					g.GetOS()->Add(ni3);
					auto zy1 = new Zyounin(SPAWN5C_ZYONI1_X, SPAWN5C_ZYONI1_Y, SPAWN5C_ZYONI1_FLIP, SPAWN5C_ZYONI1_KUNAI);
					g.GetOS()->Add(zy1);
				}
				else if (_spawn_type == "6A") {
					auto sh1 = new Shielder(SPAWN6A_SHIEL1_X, SPAWN6A_SHIEL1_Y, SPAWN6A_SHIEL1_FLIP);
					g.GetOS()->Add(sh1);
					auto sh2 = new Shielder(SPAWN6A_SHIEL2_X, SPAWN6A_SHIEL2_Y, SPAWN6A_SHIEL2_FLIP);
					g.GetOS()->Add(sh2);
				}
				else if (_spawn_type == "8A") {
					auto bu1 = new Bushi(SPAWN8A_BUSHI1_X, SPAWN8A_BUSHI1_Y, SPAWN8A_BUSHI1_FLIP);
					g.GetOS()->Add(bu1);
					auto sh1 = new Shielder(SPAWN8A_SHIEL1_X, SPAWN8A_SHIEL1_Y, SPAWN8A_SHIEL1_FLIP);
					g.GetOS()->Add(sh1);
					auto bs1 = new Busyo(SPAWN8A_BUSYO1_X, SPAWN8A_BUSYO1_Y, SPAWN8A_BUSYO1_FLIP);
					g.GetOS()->Add(bs1);
					auto boss = new Boss(SPAWN8A_BOSS1_X, SPAWN8A_BOSS1_Y, SPAWN8A_BOSS1_FLIP);
					g.GetOS()->Add(boss);
				}
				else if (_spawn_type == "9A") {
					auto bu1 = new Bushi(SPAWN9A_BUSHI1_X, SPAWN9A_BUSHI1_Y, SPAWN9A_BUSHI1_FLIP);
					g.GetOS()->Add(bu1);
					auto la1 = new Lancer(SPAWN9A_LANCE1_X, SPAWN9A_LANCE1_Y, SPAWN9A_LANCE1_FLIP);
					g.GetOS()->Add(la1);
					auto ni1 = new Ninja(SPAWN9A_NINJA1_X, SPAWN9A_NINJA1_Y, SPAWN9A_NINJA1_FLIP, SPAWN9A_NINJA1_KUNAI);
					g.GetOS()->Add(ni1);
				}
				else if (_spawn_type == "9B") {
					auto bs1 = new Busyo(SPAWN9B_BUSYO1_X, SPAWN9B_BUSYO1_Y, SPAWN9B_BUSYO1_FLIP);
					g.GetOS()->Add(bs1);
					auto la1 = new Lancer(SPAWN9B_LANCE1_X, SPAWN9B_LANCE1_Y, SPAWN9B_LANCE1_FLIP);
					g.GetOS()->Add(la1);
					auto sh1 = new Shielder(SPAWN9B_SHIEL1_X, SPAWN9B_SHIEL1_Y, SPAWN9B_SHIEL1_FLIP);
					g.GetOS()->Add(sh1);
					auto zy1 = new Zyounin(SPAWN9B_ZYONI1_X, SPAWN9B_ZYONI1_Y, SPAWN9B_ZYONI1_FLIP, SPAWN9B_ZYONI1_KUNAI);
					g.GetOS()->Add(zy1);
				}
				else if (_spawn_type == "10A") {
					auto bu1 = new Bushi(SPAWN10A_BUSHI1_X, SPAWN10A_BUSHI1_Y, SPAWN10A_BUSHI1_FLIP);
					g.GetOS()->Add(bu1);
					auto bu2 = new Bushi(SPAWN10A_BUSHI2_X, SPAWN10A_BUSHI2_Y, SPAWN10A_BUSHI2_FLIP);
					g.GetOS()->Add(bu2);
					auto bu3 = new Bushi(SPAWN10A_BUSHI3_X, SPAWN10A_BUSHI3_Y, SPAWN10A_BUSHI3_FLIP);
					g.GetOS()->Add(bu3);
					auto la1 = new Lancer(SPAWN10A_LANCE1_X, SPAWN10A_LANCE1_Y, SPAWN10A_LANCE1_FLIP);
					g.GetOS()->Add(la1);
					auto ni1 = new Ninja(SPAWN10A_NINJA1_X, SPAWN10A_NINJA1_Y, SPAWN10A_NINJA1_FLIP, SPAWN10A_NINJA1_KUNAI);
					g.GetOS()->Add(ni1);
				}
				else if (_spawn_type == "10B") {
					auto bu1 = new Bushi(SPAWN10B_BUSHI1_X, SPAWN10B_BUSHI1_Y, SPAWN10B_BUSHI1_FLIP);
					g.GetOS()->Add(bu1);
					auto bu2 = new Bushi(SPAWN10B_BUSHI2_X, SPAWN10B_BUSHI2_Y, SPAWN10B_BUSHI2_FLIP);
					g.GetOS()->Add(bu2);
					auto bu3 = new Bushi(SPAWN10B_BUSHI3_X, SPAWN10B_BUSHI3_Y, SPAWN10B_BUSHI3_FLIP);
					g.GetOS()->Add(bu3);
					auto sh1 = new Shielder(SPAWN10B_SHIEL1_X, SPAWN10B_SHIEL1_Y, SPAWN10B_SHIEL1_FLIP);
					g.GetOS()->Add(sh1);
					auto ni1 = new Ninja(SPAWN10B_NINJA1_X, SPAWN10B_NINJA1_Y, SPAWN10B_NINJA1_FLIP, SPAWN10B_NINJA1_KUNAI);
					g.GetOS()->Add(ni1);
					auto zy1 = new Zyounin(SPAWN10B_ZYONI1_X, SPAWN10B_ZYONI1_Y, SPAWN10B_ZYONI1_FLIP, SPAWN10B_ZYONI1_KUNAI);
					g.GetOS()->Add(zy1);
				}
				else if (_spawn_type == "11A") {
					auto bu1 = new Bushi(SPAWN11A_BUSHI1_X, SPAWN11A_BUSHI1_Y, SPAWN11A_BUSHI1_FLIP);
					g.GetOS()->Add(bu1);
					auto ni1 = new Ninja(SPAWN11A_NINJA1_X, SPAWN11A_NINJA1_Y, SPAWN11A_NINJA1_FLIP, SPAWN11A_NINJA1_KUNAI);
					g.GetOS()->Add(ni1);
					auto pn1 = new PoisonNinja(SPAWN11A_POIJA1_X, SPAWN11A_POIJA1_Y, SPAWN11A_POIJA1_FLIP);
					g.GetOS()->Add(pn1);
					auto pn2 = new PoisonNinja(SPAWN11A_POIJA2_X, SPAWN11A_POIJA2_Y, SPAWN11A_POIJA2_FLIP);
					g.GetOS()->Add(pn2);
					auto pn3 = new PoisonNinja(SPAWN11A_POIJA3_X, SPAWN11A_POIJA3_Y, SPAWN11A_POIJA3_FLIP);
					g.GetOS()->Add(pn3);
					auto pn4 = new PoisonNinja(SPAWN11A_POIJA4_X, SPAWN11A_POIJA4_Y, SPAWN11A_POIJA4_FLIP);
					g.GetOS()->Add(pn4);
				}
				else if (_spawn_type == "11B") {
					auto bu1 = new Bushi(SPAWN11B_BUSHI1_X, SPAWN11B_BUSHI1_Y, SPAWN11B_BUSHI1_FLIP);
					g.GetOS()->Add(bu1);
					auto sh1 = new Shielder(SPAWN11B_SHIEL1_X, SPAWN11B_SHIEL1_Y, SPAWN11B_SHIEL1_FLIP);
					g.GetOS()->Add(sh1);
				}
				else if (_spawn_type == "11C") {
					auto zy1 = new Zyounin(SPAWN11C_ZYONI1_X, SPAWN11C_ZYONI1_Y, SPAWN11C_ZYONI1_FLIP, SPAWN11C_ZYONI1_KUNAI);
					g.GetOS()->Add(zy1);
				}
				else if (_spawn_type == "11D") {
					auto la1 = new Lancer(SPAWN11D_LANCE1_X, SPAWN11D_LANCE1_Y, SPAWN11D_LANCE1_FLIP);
					g.GetOS()->Add(la1);
					auto sh1 = new Shielder(SPAWN11D_SHIEL1_X, SPAWN11D_SHIEL1_Y, SPAWN11D_SHIEL1_FLIP);
					g.GetOS()->Add(sh1);
					auto ni1 = new Ninja(SPAWN11D_NINJA1_X, SPAWN11D_NINJA1_Y, SPAWN11D_NINJA1_FLIP, SPAWN11D_NINJA1_KUNAI);
					g.GetOS()->Add(ni1);
				}
				else if (_spawn_type == "11E") {
					auto bs1 = new Busyo(SPAWN11E_BUSYO1_X, SPAWN11E_BUSYO1_Y, SPAWN11E_BUSYO1_FLIP);
					g.GetOS()->Add(bs1);
					auto bs2 = new Busyo(SPAWN11E_BUSYO2_X, SPAWN11E_BUSYO2_Y, SPAWN11E_BUSYO2_FLIP);
					g.GetOS()->Add(bs2);
				}
				else if (_spawn_type == "11F") {
					auto bu1 = new Bushi(SPAWN11F_BUSHI1_X, SPAWN11F_BUSHI1_Y, SPAWN11F_BUSHI1_FLIP);
					g.GetOS()->Add(bu1);
					auto ni1 = new Ninja(SPAWN11F_NINJA1_X, SPAWN11F_NINJA1_Y, SPAWN11F_NINJA1_FLIP, SPAWN11F_NINJA1_KUNAI);
					g.GetOS()->Add(ni1);
				}
				else if (_spawn_type == "12A") {
					auto bu1 = new Bushi(SPAWN12A_BUSHI1_X, SPAWN12A_BUSHI1_Y, SPAWN12A_BUSHI1_FLIP);
					g.GetOS()->Add(bu1);
					auto bu2 = new Bushi(SPAWN12A_BUSHI2_X, SPAWN12A_BUSHI2_Y, SPAWN12A_BUSHI2_FLIP);
					g.GetOS()->Add(bu2);
					auto ni1 = new Ninja(SPAWN12A_NINJA1_X, SPAWN12A_NINJA1_Y, SPAWN12A_NINJA1_FLIP, SPAWN12A_NINJA1_KUNAI);
					g.GetOS()->Add(ni1);
					auto zy1 = new Zyounin(SPAWN12A_ZYONI1_X, SPAWN12A_ZYONI1_Y, SPAWN12A_ZYONI1_FLIP, SPAWN12A_ZYONI1_KUNAI);
					g.GetOS()->Add(zy1);
					auto sh1 = new Shielder(SPAWN12A_SHIEL1_X, SPAWN12A_SHIEL1_Y, SPAWN12A_SHIEL1_FLIP);
					g.GetOS()->Add(sh1);
					auto sh2 = new Shielder(SPAWN12A_SHIEL2_X, SPAWN12A_SHIEL2_Y, SPAWN12A_SHIEL2_FLIP);
					g.GetOS()->Add(sh2);
					auto boss = new Boss(SPAWN12A_BOSS2_X, SPAWN12A_BOSS2_Y, SPAWN12A_BOSS2_FLIP);
					g.GetOS()->Add(boss);
				}
				else if (_spawn_type == "12B") {
					auto bu1 = new Bushi(SPAWN12B_BUSHI1_X, SPAWN12B_BUSHI1_Y, SPAWN12B_BUSHI1_FLIP);
					g.GetOS()->Add(bu1);
					auto la1 = new Lancer(SPAWN12B_LANCE1_X, SPAWN12B_LANCE1_Y, SPAWN12B_LANCE1_FLIP);
					g.GetOS()->Add(la1);
				}
				else if (_spawn_type == "12C") {
					auto bs1 = new Busyo(SPAWN12C_BUSYO1_X, SPAWN12C_BUSYO1_Y, SPAWN12C_BUSYO1_FLIP);
					g.GetOS()->Add(bs1);
				}
			}
		}
	}
}
void Spawn::Draw(Game& g) {
	ObjectBase::Draw(g);
}
void Spawn::Delete(Game& g) {
	g.GetOS()->Del(this);
}

void Spawn::SpawnPositon() {
	if (_spawn_type == "1A") {
		_x = SPAWN1A_XPOSITION;
		_y = SPAWN1A_YPOSITION;
	}
	else if (_spawn_type == "1B") {
		_x = SPAWN1B_XPOSITION;
		_y = SPAWN1B_YPOSITION;
	}
	else if (_spawn_type == "2A") {
		_x = SPAWN2A_XPOSITION;
		_y = SPAWN2A_YPOSITION;
	}
	else if (_spawn_type == "2B") {
		_x = SPAWN2B_XPOSITION;
		_y = SPAWN2B_YPOSITION;
	}
	else if (_spawn_type == "3A") {
		_x = SPAWN3A_XPOSITION;
		_y = SPAWN3A_YPOSITION;
	}
	else if (_spawn_type == "3B") {
		_x = SPAWN3B_XPOSITION;
		_y = SPAWN3B_YPOSITION;
	}
	else if (_spawn_type == "3C") {
		_x = SPAWN3C_XPOSITION;
		_y = SPAWN3C_YPOSITION;
	}
	else if (_spawn_type == "3D") {
		_x = SPAWN3D_XPOSITION;
		_y = SPAWN3D_YPOSITION;
	}
	else if (_spawn_type == "3E") {
		_x = SPAWN3E_XPOSITION;
		_y = SPAWN3E_YPOSITION;
	}
	else if (_spawn_type == "4A") {
		_x = SPAWN4A_XPOSITION;
		_y = SPAWN4A_YPOSITION;
	}
	else if (_spawn_type == "4B") {
		_x = SPAWN4B_XPOSITION;
		_y = SPAWN4B_YPOSITION;
	}
	else if (_spawn_type == "4C") {
		_x = SPAWN4C_XPOSITION;
		_y = SPAWN4C_YPOSITION;
	}
	else if (_spawn_type == "4D") {
		_x = SPAWN4D_XPOSITION;
		_y = SPAWN4D_YPOSITION;
	}
	else if (_spawn_type == "5A") {
		_x = SPAWN5A_XPOSITION;
		_y = SPAWN5A_YPOSITION;
	}
	else if (_spawn_type == "5B") {
		_x = SPAWN5B_XPOSITION;
		_y = SPAWN5B_YPOSITION;
	}
	else if (_spawn_type == "5C") {
		_x = SPAWN5C_XPOSITION;
		_y = SPAWN5C_YPOSITION;
	}
	else if (_spawn_type == "6A") {
		_x = SPAWN6A_XPOSITION;
		_y = SPAWN6A_YPOSITION;
	}
	else if (_spawn_type == "8A") {
		_x = SPAWN8A_XPOSITION;
		_y = SPAWN8A_YPOSITION;
	}
	else if (_spawn_type == "9A") {
		_x = SPAWN9A_XPOSITION;
		_y = SPAWN9A_YPOSITION;
	}
	else if (_spawn_type == "9B") {
		_x = SPAWN9B_XPOSITION;
		_y = SPAWN9B_YPOSITION;
	}
	else if (_spawn_type == "10A") {
		_x = SPAWN10A_XPOSITION;
		_y = SPAWN10A_YPOSITION;
	}
	else if (_spawn_type == "10B") {
		_x = SPAWN10B_XPOSITION;
		_y = SPAWN10B_YPOSITION;
	}
	else if (_spawn_type == "11A") {
		_x = SPAWN11A_XPOSITION;
		_y = SPAWN11A_YPOSITION;
	}
	else if (_spawn_type == "11B") {
		_x = SPAWN11B_XPOSITION;
		_y = SPAWN11B_YPOSITION;
	}
	else if (_spawn_type == "11C") {
		_x = SPAWN11C_XPOSITION;
		_y = SPAWN11C_YPOSITION;
	}
	else if (_spawn_type == "11D") {
		_x = SPAWN11D_XPOSITION;
		_y = SPAWN11D_YPOSITION;
	}
	else if (_spawn_type == "11E") {
		_x = SPAWN11E_XPOSITION;
		_y = SPAWN11E_YPOSITION;
	}
	else if (_spawn_type == "11F") {
		_x = SPAWN11F_XPOSITION;
		_y = SPAWN11F_YPOSITION;
	}
	else if (_spawn_type == "12A") {
		_x = SPAWN12A_XPOSITION;
		_y = SPAWN12A_YPOSITION;
	}
	else if (_spawn_type == "12B") {
		_x = SPAWN12B_XPOSITION;
		_y = SPAWN12B_YPOSITION;
	}
	else if (_spawn_type == "12C") {
		_x = SPAWN12C_XPOSITION;
		_y = SPAWN12C_YPOSITION;
	}
}