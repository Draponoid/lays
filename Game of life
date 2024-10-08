#include <iostream>
#include <Windows.h>

bool gameover;
const int width = 11;
const int height = 11;


void render(bool field[width][height]) {
	system("cls");
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) std::cout << field[i][j];
			std::cout << std::endl;
	}
	std::cout << std::endl;
}

void bact(bool field[width][height]) {
	field[width / 2][height / 2] = 1; field[width / 2 - 1][height / 2] = 1;
	field[width / 2 - 2][height / 2 - 1] = 1; field[width / 2][height / 2 - 1] = 1; field[width / 2 - 1][height / 2 + 1] = 1;
}

int parity(int a, int b) {
	if (a > 0) {
		return a % b;
	}
	if (a < 0) {
		a = abs(a);
		return a % b;
	}
	if (a == 0) {
		return 0;
	}
}



void movecells(bool field[width][height]) {
	int c = 0;
	bool** buffer = new bool* [width];
	for (int i = 0; i < width; i++) {
		buffer[i] = new bool[height];
	}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			c = 0;
				if (field[parity (i - 1, width)][j % height] == 1) {
					c++;
				}
				if (field[parity(i + 1, width)][j % height] == 1) {
					c++;
				}
				if (field[i % width][parity(j - 1, height)] == 1) {
					c++;
				}
				if (field[i % width][parity(j + 1, height)] == 1) {
					c++;
				}
				if (field[parity(i - 1, width)][parity(j - 1, height)] == 1) {
					c++;
				}
				if (field[parity(i + 1, width)][parity(j + 1, height)] == 1) {
					c++;
				}
				if (field[parity(i - 1, width)][parity(j + 1, height)] == 1) {
					c++;
				}
				if (field[parity(i + 1, width)][parity(j - 1, height)] == 1) {
					c++;
				}
			if (c < 2 || c > 3) {
				buffer[i][j] = false;
			}
			else if (c == 3) {
				buffer[i][j] = true;
			}
			else if (c == 2) {
				buffer[i][j] = field[i][j];
			}

		}
	}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			field[i][j] = buffer[i][j];
		}
	}
}
