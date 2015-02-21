#include "gamemap.h"
#include "gametile.h"
#include <iostream>
gamemap::gamemap() {
	dummy.setHardware(9); // damit hardware_checker weiss, wann es der dummy/hardware ist.
}
gametile* gamemap::getTile(int x, int y) {
	gametile* gtp;
	if ((x <= 31 && y <= 23) && (x >= 0 && y >= 0)) { 
		gtp = &the_map[y][x];
	} else {
		gtp = &dummy;
	}
	return gtp;
}
void gamemap::printMap(void) {
	for (int y = 0; y < 24; y++) {
		for (int x = 0; x < 32; x++) {
			std::cout << the_map[y][x].getChar();
		}
		std::cout << std::endl;
	}
}
