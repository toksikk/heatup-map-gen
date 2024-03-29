#include "gamemap.h"
#include "random_number.h"
#include "position_checker.h"
#include <iostream>
using namespace std;
void fill_map_alg1(gamemap* gm) {
	int hw = -1;
	int tries = 0;
	int maxtries = 5000; // rather primitive way, but <5000 happens to generate maps with almost no ways

	// algorithm generates a way-pattern and afterwards sets 9 1 block sized manipulable gametiles.
	int waymapcoveringgoal = 100;
	int maxborderinginit = 1; // this has to be 1 - was trying to figure out a way to use this for something I can't remember

	for (int i=0; i< (32*24/100.0)*waymapcoveringgoal; i++) {
		int posx = get_random_number(32);
		int posy = get_random_number(24);
		int maxbordering = maxborderinginit;
		if (i==0) {
			for (int i=0; i<maxbordering; i++) {
				gm->getTile(posx,posy)->setWay();
				posx = get_random_number(32);
				posy = get_random_number(24);
			}
		}
		while (check_bordering_way_amount(gm, posx, posy) != maxbordering) {
			tries++;
			posx = get_random_number(32);
			posy = get_random_number(24);
			while (gm->getTile(posx,posy)->getChar() == '#') {
				posx = get_random_number(32);
				posy = get_random_number(24);
				if (tries == maxtries/2) maxbordering--;
				if (tries > maxtries) break;
			}
			if (tries == maxtries/2) maxbordering--;
			if (tries > maxtries) break;
		}
		if (tries > maxtries) break;
		gm->getTile(posx,posy)->setWay();
		tries = 0;
	}

	for (int i=0; i<9; i++) {
		hw++;
		int posx = get_random_number(32);
		int posy = get_random_number(24);

		while ((gm->getTile(posx, posy)->getChar() != '-') || (check_bordering_way_amount(gm, posx, posy) < 1)) {
			posx = get_random_number(32);
			posy = get_random_number(24);
		}
		gm->getTile(posx, posy)->setHardware(i);
	}

}
void fill_map_alg2(gamemap* gm) {
	int hw = -1;
	int tries = 0;
	int hwtotaltiles = 0;

	// the following algorithm sets hardware blocks but no ways.
	// for the purpose if somebody wants to implement an algorithm to generate ways along existing hardware.
	for (int i = 0; i < 9; i++) {
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
}
void fill_map_with_ways(gamemap* gm) {
	int tries = 0;
	int maxtries = 10000; // rather primitive way, but <5000 happens to generate maps with almost no ways

	// algorithm generates a way-pattern and afterwards sets 9 1 block sized manipulable gametiles.
	int waymapcoveringgoal = 100;
	int maxborderinginit = 1; // this has to be 1 - was trying to figure out a way to use this for something I can't remember

	for (int i=0; i< (gm->get_percentage_of_ways_of_possible_ways()/100.0)*waymapcoveringgoal; i++) {
		int posx = get_random_number(32);
		int posy = get_random_number(24);
		int maxbordering = maxborderinginit;
		if (i==0) {
			for (int i=0; i<maxbordering; i++) {
				gm->getTile(posx,posy)->setWay();
				posx = get_random_number(32);
				posy = get_random_number(24);
			}
		}
		while (check_bordering_way_amount(gm, posx, posy) != maxbordering) {
			tries++;
			posx = get_random_number(32);
			posy = get_random_number(24);
			while (gm->getTile(posx,posy)->getChar() == '#' || check_char_for_hw(gm->getTile(posx,posy)->getChar())) {
				posx = get_random_number(32);
				posy = get_random_number(24);
				if (tries == maxtries/10) maxbordering++;
				if (tries > maxtries) break;
			}
			if (tries == maxtries/3) maxbordering++;
			if (tries > maxtries) break;
		}
		if (tries > maxtries) break;
		gm->getTile(posx,posy)->setWay();
		tries = 0;
	}
}
int main(void) {
	gamemap* gm2 = new gamemap();
	fill_map_alg2(gm2);
	fill_map_with_ways(gm2);
	gm2->printMap();
	delete gm2;
}
