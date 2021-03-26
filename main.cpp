#include "header1.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;


int main() {
	Brock bro;
	Wall wal;
	Mino min;

	wal.setWall();
	min.resetMino();

	time_t t = time(NULL);

	while (1) {
		min.changeAngle();

		if (t != time(NULL)) {
			t = time(NULL);

			min.crash();
		}
	}
}

