#include "gamemap.h"
#include <iostream>
int main(void) {
	gamemap* gm = new gamemap();
	gm->getTile(0,0)->setHardware(1);
	gm->printMap();
	delete gm;
}
