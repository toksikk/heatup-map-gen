#include "gametile.h"
#ifndef GAMEMAP
#define GAMEMAP
class gamemap {
	private:
		gametile the_map[24][32];
		gametile dummy;
	public:
		gamemap();
		gametile* getTile(int x, int y);
		void printMap(void);
};
#endif
