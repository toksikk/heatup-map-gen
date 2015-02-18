#include <stdlib.h> /* srand, rand */
#include <time.h> /* time */
int get_random_number(int n) {
	srand(time(NULL));
	return rand() % n + 1; // random number between 1 and n
}
