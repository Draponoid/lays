#include<iostream>
#include<Windows.h>
#include<conio.h>

bool gameover = false;
bool Flag = true;
int direction = 1;

const int MAX_SIZE = 100;
int snakeX[MAX_SIZE];
int snakeY[MAX_SIZE]; 
int snakeLength = 1; 

void fields(int** field, int width, int length) {
	system("cls");

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < length; j++) {
			std::cout << field[i][j];
		}
		std::cout << std::endl;
	}
}

void fruit(int** field, int width, int length) {
	int i = rand() % width;
	int j = rand() % length;
	while (field[i][j] != 0) {
		i = rand() % width;
		j = rand() % length;
	}
	field[i][j] = 3;
	Flag = false;
}


void movel(int** field, int width, int length) {
	int prevx = snakeX[0];
	int prevy = snakeY[0];
	int prev2x, prev2y;
	if (direction == 1) {
		snakeX[0] -= 1; 
	}
	else if (direction == 2) {
		snakeX[0] += 1; 
	}
	else if (direction == 3) {
		snakeY[0] -= 1; 
	}
	else if (direction == 4) {
		snakeY[0] += 1; 
	}
	if (snakeX[0] <= 0 || snakeX[0] >= width - 1 || snakeY[0] <= 0 || snakeY[0] >= length - 1) {
		gameover = true;
		return;
	}

	if (field[snakeX[0]][snakeY[0]] == 3) {
		snakeLength++;
		snakeX[snakeLength - 1] = snakeX[snakeLength - 2];
		snakeY[snakeLength - 1] = snakeY[snakeLength - 2];
		Flag = true;
	}
	else if (field[snakeX[0]][snakeY[0]] == 2) {
		gameover = true;
	}

	for (int i = 1; i < snakeLength; i++) {
		prev2x = snakeX[i];
		prev2y = snakeY[i];
		snakeX[i] = prevx;
		snakeY[i] = prevy;
		prevx = prev2x;
		prevy = prev2y;
	}

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < length; j++) {
			if (field[i][j] != 1 && field[i][j] != 3) {
				field[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < snakeLength; i++) {
		field[snakeX[i]][snakeY[i]] = 2;
	}
}


	void move(int** field, int width, int length) {
		if (_kbhit()) {
			char ch = _getch();
			if (ch == 72) direction = 1;
			if (ch == 80) direction = 2;
			if (ch == 75) direction = 3;
			if (ch == 77) direction = 4;
		}
	}


	int main() {
		const int width = 10;
		const int length = 15;
		int** field = new int* [width];
		for (int i = 0; i < width; i++) field[i] = new int[length];
		for (int i = 0; i < width; i++) {
			field[i] = new int[length];
			for (int j = 0; j < length; j++) {
				field[i][j] = 0;
			}
		}

		for (int j = 0; j < length; j++) {
			field[0][j] = 1;
			field[width - 1][j] = 1;
		}
		for (int i = 0; i < width; i++) {
			field[i][0] = 1;
			field[i][length - 1] = 1;
		}
				field[5][7] = 2;
				snakeX[0] = 5;
				snakeY[0] = 7;

		while (!gameover) {
			fields(field, width, length);
			move(field, width, length);
			movel(field, width, length);
			std::cout << direction;
			if (Flag) {
				fruit(field, width, length);
			}
			Sleep(500);
		}
	}
