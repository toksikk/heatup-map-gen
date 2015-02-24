#include "gametile.h"
#include "gamemap.h"
#include "position_checker.h"
#include <iostream>
bool check_char_for_hw(char c) {
	return (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9');
	// shorter and should work too:
	// return (c != '#' && c != '-');
}
bool check_surroundings_for_hw(gamemap* gm, int x, int y, int range) {
	if (check_char_for_hw(gm->getTile(x,y)->getChar())) return true;
	for (int i = 1; i <= range; i++) {
		bool c1 = check_char_for_hw(gm->getTile(x+i,y)->getChar());
		bool c2 = check_char_for_hw(gm->getTile(x,y+i)->getChar());
		bool c3 = check_char_for_hw(gm->getTile(x-i,y)->getChar());
		bool c4 = check_char_for_hw(gm->getTile(x,y-i)->getChar());
		if (c1 || c2 || c3 || c4) {
			return true;
		}
	}
	return false;
}
bool check_surroundings_for_hw_to_e_s(gamemap* gm, int x, int y, int range) {
	for (int i = -1; i <= range+1; i++) {
		for (int j = -1; j <= range+1; j++) {
			if (check_char_for_hw(gm->getTile(x+i,y+j)->getChar())) return true;
		}
	}
	return false;
}
int check_bordering_way_amount(gamemap* gm, int x, int y) {
	int amount = 0;
	if (gm->getTile(x+1, y)->getChar() == '#') amount++;
	if (gm->getTile(x-1, y)->getChar() == '#') amount++;
	if (gm->getTile(x, y+1)->getChar() == '#') amount++;
	if (gm->getTile(x, y-1)->getChar() == '#') amount++;
	return amount;
}
