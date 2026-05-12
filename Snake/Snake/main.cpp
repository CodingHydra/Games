#include <iostream>
#include <conio.h>
#include <windows.h>;

using namespace std;
bool gameover;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup() {
	gameover = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;

}
void Draw() {
	system("cls");
	for (int i = 0; i < width+2; i++) {
		cout << "#";
	}
	cout << endl;

	for (int i = 0; i < height; i++) {

		for (int j = 0; j < width; j++) {

			if (j == 0) {
				cout << "#";
			}
			if (i == y && j == x) {
				cout << "O";
			}
			if (i == fruitY && j == fruitX){
				cout << "F";
			}
			else {
				bool print = false;
				for (int k = 0; k < nTail; k++) {
					if (tailX[k] == j && tailY[k] == i) {
						cout << "0";
						print = true;
					}
					
				}
				if (!print) {
					cout << " ";
				}
			}

			if (j == width - 1) {
				cout << "#";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < width+2; i++) {
		cout << "#";
	}
	cout << endl;
	cout << "Score:" << score << endl;
	Sleep(60);
	

}
void Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
				gameover = true;
				break;

		}
	}
}
void Logic() {
	int pevX = tailX[0];
	int pevY = tailX[0];
	int pev2X, pev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++) {
		pev2X = tailX[i];
		pev2Y = tailY[i];
		tailX[i] = pevX;
		tailY[i] = pevY;

		pevX = pev2X;
		pevY = pev2Y;


	}

	switch (dir) {
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}

	if (x > width || x < 0 || y > height || y < 0) {
		gameover = true;
	}
	if (x == fruitX && y == fruitY) {
		
		fruitX = rand() % width;
		fruitY = rand() % height;
		score += 10;
		nTail++;
	}

}



int main() {
	Setup();
	while (!gameover) {
		Draw();
		Input();
		Logic();
		
	}

	return 0; //
}