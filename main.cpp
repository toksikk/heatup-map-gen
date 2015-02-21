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
	
	// folgende for-schleife setzt hardware-gametiles
	for (int i = 0; i < 10; i++) {
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

	for (int i=0; i< (int)((32*24-hwtotaltiles)*0.5); i++) {
		
	}

	//std::cout << check_surroundings_for_hw_to_e_s(gm, 4, 2, 1) << std::endl; // "1" == speicherzugriffsfehler


	gm->printMap();
	delete gm;
}
