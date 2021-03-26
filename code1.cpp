#include "header1.h"
#include <string.h>
#include <algorithm>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

char Brock::field[FIELD_HEIGHT][FIELD_WIDTH];
char Brock::displayBuffer[FIELD_HEIGHT][FIELD_WIDTH];
int Mino::minoType;
int Mino::minoAngle;
int Mino::minoX;
int Mino::minoY;

void Wall::setWall() {
	for (int i = 0; i < FIELD_HEIGHT; i++)
		bro.field[i][0] = bro.field[i][FIELD_WIDTH - 1] = 1;

	for (int i = 0; i < FIELD_WIDTH; i++)
		bro.field[FIELD_HEIGHT - 1][i] = 1;
}

Mino::Mino() {

	minoType = 0;
	minoAngle = 0;
	minoX = 5;
	minoY = 0;
}

void Mino::resetMino() {
	minoX = 5;
	minoY = 0;
	minoType = rand() % MINO_TYPE_MAX;
	minoAngle = rand() % MINO_ANGLE_MAX;
}

bool Mino::isHit(int _minoX, int _minoY, int _minoType, int _minoAngle) {
	for (int i = 0; i < MINO_HEIGHT; i++)
		for (int j = 0; j < MINO_WIDTH; j++)
			if (bro.minoShapes[_minoType][_minoAngle][i][j]
				&& bro.field[_minoY + i][_minoX + j])
				return true;
	return false;
}


void Mino::display() {
	memcpy(bro.displayBuffer, bro.field, sizeof(bro.field));

	for (int i = 0; i < MINO_HEIGHT; i++) {
		for (int j = 0; j < MINO_WIDTH; j++)
			bro.displayBuffer[minoY + i][minoX + j] |= bro.minoShapes[minoType][minoAngle][i][j];
	}
	system("cls");

	for (int i = 0; i < FIELD_HEIGHT; i++) {
		for (int j = 0; j < FIELD_WIDTH; j++)
			printf(bro.displayBuffer[i][j] ? "¡" : "@");
		printf("\n");
	}
}

void Mino::changeAngle() {
	if (_kbhit()) {
		switch (_getch()) {
			//case 'w':
		case 's':
			if (!isHit(
				minoX,
				minoY + 1,
				minoType,
				minoAngle))
				minoY++;
			break;
		case 'a':
			if (!isHit(
				minoX - 1,
				minoY,
				minoType,
				minoAngle))
				minoX--;
			break;
		case 'd':
			if (!isHit(
				minoX + 1,
				minoY,
				minoType,
				minoAngle))
				minoX++;
			break;
		case 0x20:
			if (!isHit(
				minoX,
				minoY,
				minoType,
				(minoAngle + 1) % MINO_ANGLE_MAX))
				minoAngle = (minoAngle + 1) % MINO_ANGLE_MAX;
			break;
		}
		display();

	}
}

void Mino::mbreak() {
	for (int i = 0; i < MINO_HEIGHT; i++)
		for (int j = 0; j < MINO_WIDTH; j++)
			bro.field[minoY + i][minoX + j] |= bro.minoShapes[minoType][minoAngle][i][j];
	{
		for (int i = 0; i < FIELD_HEIGHT - 1; i++) {
			bool lineFill = true;
			for (int j = 1; j < FIELD_WIDTH - 1; j++) {
				if (!bro.field[i][j])
					lineFill = false;
			}
			if (lineFill) {
				for (int j = i; 0 < j; j--)
					memcpy(bro.field[j], bro.field[j - 1], FIELD_WIDTH);
			}
		}
	}
}

void Mino::crash() {
	if (isHit(
		minoX,
		minoY + 1,
		minoType,
		minoAngle)) {
		mbreak();
		resetMino();
	}
	else
		minoY++;
	    display();
}
