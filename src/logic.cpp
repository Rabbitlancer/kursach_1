//in-game logic
//by Rabbitlancer
#include <ctime>
#include "headers/logic.h"


int is_complete() {

}

int loop() {
	t = clock();
}

int wait() {
	while (clock() - t < TIME_THRESHOLD) {
		; //waiting...
	}
}
