#include <stdlib.h> /* srand, rand */
#include <sys/time.h> /* time */
int get_random_number(int n) {
	struct timeval time;
	gettimeofday(&time, NULL);
	srand((time.tv_sec)+(time.tv_usec));
	return rand() % n; // random number out of n
}
