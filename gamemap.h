#include "gametile.h"
#ifndef GAMEMAP
#define GAMEMAP
class gamemap {
	private:
		gametile the_map[24][32];
	public:
		gamemap();
		gametile* getTile(int x, int y);
		void printMap(void);
};
#endif
