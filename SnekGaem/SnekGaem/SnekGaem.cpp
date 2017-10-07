// SnekGaem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;


bool gameOver;
const int WIDTH = 30;
const int HEIGHT = 30;
int x, y, foodX, foodY, score;
enum uDirect { STOP = 0, LEFT, RIGHT, UP, DOWN};
uDirect dir;


void setup();

void draw();

void input();

void logic();




int main()
{
	setup();
	while (!gameOver)
	{
		draw();
		input();
		logic();
		
		
	}
	
	return 0;
}




void setup()
{
	gameOver = false;
	dir = STOP;
	x = (WIDTH / 2);
	y = (HEIGHT / 2);
	foodX = rand() % WIDTH;
	foodY = rand() % HEIGHT;
	score = 0;
}

void draw()
{
	system("cls");
	for (int j = 0; j < HEIGHT; ++j)
	{
		for (int i = 0; i < WIDTH; ++i)
		{
			if (i == 0 || i == (WIDTH - 1) || j == 0 || j == (HEIGHT - 1))
				cout << "# ";
			else
				cout << "  ";
			if (i == y && j == x)
				cout << "O";
			else if (i == foodY && j == foodX)
				cout << "*";
			else
				cout << " ";

		}
		cout << endl;

	}
}



	void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
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
			gameOver = true;
			break;
		}
	}
}

void logic()
{
	switch (dir)
	{
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	default:
		break;
	}
	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
		gameOver = true;
}
