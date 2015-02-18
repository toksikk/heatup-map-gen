#include "gametile.h"
#include <iostream>
gametile::gametile() {
	wall = true;
	way = false;
	hardware = false;
	hardware_number = 10;
}
gametile::~gametile() {
    
}
void gametile::setWay(void) {
	wall = false;
	way = true;
}
void gametile::setHardware(int number){
	hardware = true;
	hardware_number = number;
}
char gametile::getChar(void) {
	if (hardware) {
		return hardware_number + '0';
	} else if (way && !wall) {
		return '#';
	} else {
	    return '-';
	}
}
