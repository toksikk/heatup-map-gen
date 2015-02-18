#include "gamemap.h"
#include "gametile.h"
#include <iostream>
gamemap::gamemap() {
	
}
gametile* gamemap::getTile(int x, int y) {
    gametile* gtp = &the_map[y][x];
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
