#include "gamemap.h"
#include "random_number.h"
#include "position_checker.h"
#include <iostream>
using namespace std;
int main(void) {
	gamemap* gm = new gamemap();
	int hw = -1;
	int tries = 0;
	int hwtotaltiles = 0;
	
	// the following algorithm sets hardware blocks but no ways.
	// for the purpose if somebody wants to implement an algorithm to generate ways along existing hardware.
/*	for (int i = 0; i < 9; i++) {
		hw++;

		int minimumsize = 2;	
		int maximumsize = 5;
	
		int width = (get_random_number(maximumsize) + minimumsize);
		int height = (get_random_number(maximumsize) + minimumsize);
	
		int posx = get_random_number(32);
		int posy = get_random_number(24); 

	
		while (check_surroundings_for_hw_to_e_s(gm, posx, posy, maximumsize)) {
			tries++;
			width = (get_random_number(maximumsize) + minimumsize);
			height = (get_random_number(maximumsize) + minimumsize);

//			cout << "old posx " << posx << " old posy " << posy << endl;
//			cout << "new posx " ;
			posx = get_random_number(32);
//			cout <<posx<<endl;
//			cout << "new posy ";
			posy = get_random_number(24);
//			cout <<posy<<endl;
			
			if (tries > 100000) break;
		}
			
		if (tries > 100000) break;
		for (int x = posx; x < posx+width; x++) {
			for (int y = posy; y < posy+height; y++) {
				hwtotaltiles++;
				gm->getTile(x,y)->setHardware(hw);
			}
		}
	}
*/
	// algorithm generates a way-pattern and afterwards sets 9 1 block sized manipulable gametiles.
	int waymapcoveringgoal = 100;

	for (int i=0; i< (32*24/100.0)*waymapcoveringgoal; i++) {
		int posx = get_random_number(32);
		int posy = get_random_number(24);
		if (i==0) gm->getTile(posx,posy)->setWay();
		while (check_bordering_way_amount(gm, posx, posy) != 1) {
			tries++;
			posx = get_random_number(32);
			posy = get_random_number(24);
			while (gm->getTile(posx,posy)->getChar() == '#') {
				posx = get_random_number(32);
				posy = get_random_number(24);
				if (tries > 100000) break;
			}
			if (tries > 100000) break;
		}
		if (tries > 100000) break;
		gm->getTile(posx,posy)->setWay();
	}

	for (int i=0; i<9; i++) {
		hw++;
		int posx = get_random_number(32);
		int posy = get_random_number(24);

		while (gm->getTile(posx, posy)->getChar() != '-') {
			posx = get_random_number(32);
			posy = get_random_number(24);
		}
		gm->getTile(posx, posy)->setHardware(i);
	}

	gm->printMap();
	delete gm;
}
