#pragma once

#include "TES3Object.h"
#include "TES3Item.h"

namespace TES3 {
	namespace WeaponType {
		enum WeaponType {
			ShortBlade1H = 0x0,
			LongBlade1H = 0x1,
			LongBlade2H = 0x2,
			Blunt1H = 0x3,
			Blunt2close = 0x4,
			Blunt2wide = 0x5,
			Spear2H = 0x6,
			Axe1H = 0x7,
			Axe2H = 0x8,
			Bow = 0x9,
			Crossbow = 0xA,
			Thrown = 0xB,
			Arrow = 0xC,
			Bolt = 0xD
		};
	}

	struct Weapon : Item {
		float weight; // 0x54
		int value; // 0x58
		char weaponType; // 0x5C
		short maxCondition; // 0x5E
		float speed; // 0x60
		float reach; // 0x64
		short enchantCapacity; // 0x68
		unsigned char chopMin; // 0x6A
		unsigned char chopMax; // 0x6B
		unsigned char slashMin; // 0x6C
		unsigned char slashMax; // 0x6D
		unsigned char thrustMin; // 0x6E
		unsigned char thrustMax; // 0x6F
		int materialFlags; // 0x70
		Enchantment * enchantment; // 0x74
	};
}