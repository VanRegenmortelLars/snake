// Snake
// Author: Van Regenmortel Lars
// Date: August 2020

#include <iostream>
#include <termios.h>

#include "point.h"
#include "snake.h"

#define LINE_TOP "\u2554\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2557\n"
#define LINE_MID "\u255F\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2562\n"
#define LINE_BOTTOM "\u255A\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u255D\n"
#define LINE_LEFT "\u2551"
#define LINE_RIGHT "\u2551\n"
#define LINE_CLEAR "\r\u255F\u2500\u2500\u2500\r"

#define HEIGHT 7
#define WIDTH 7

void display(Snake snake, Point candy){

	int board[HEIGHT*WIDTH] = {0};

	board[WIDTH*candy.y()+candy.x()] = 2;

	for(Point p: snake)
		board[WIDTH*p.y()+p.x()] = 1;

	std::cout << "\e[u";
	for(int i = 0; i < HEIGHT; i++){
		std::cout << LINE_LEFT;
		for(int j = 0; j < WIDTH; j++){
			switch(board[WIDTH*i+j]){
				case 1:
					std::cout << " \u25A1 ";
					break;
				case 2:
					std::cout << " \u25A0 ";
					break;
				default:
					std::cout << "   ";
			}
		}
		std::cout << LINE_RIGHT;
	}
}

bool move(Snake * snake, Point * candy){

	char input;
	Point head;

	// Read user input
	std::cin >> input;
	std::cout << LINE_CLEAR;

	// Identify user input
	switch(input){
		case 27:
			return false;
			break;
		case 'w':
			head = snake->up();
			break;
		case 's':
			head = snake->down();
			break;
		case 'a':
			head = snake->left();
			break;
		case 'd':
			head = snake->right();
			break;
		default:
			return true;
	}

	// Move snake according to user input
	// Generate new candy is eaten
	if(head!=*candy){
		snake->move(head);
	}
	else{
		snake->grow(head);
		candy->randomize(HEIGHT, WIDTH);
	}

	return true;
}

void game(){

	Snake snake = Snake({3, 3});

	Point candy;
	candy.randomize(HEIGHT, WIDTH);

	display(snake, candy);

	bool alive = true;
	while(alive){
		alive = move(&snake, &candy);
		display(snake, candy);
	}
}

int main(){
	struct termios termios_new, termios_old;
	tcgetattr(0, &termios_old);
	termios_new = termios_old;
	termios_new.c_lflag &= ~ICANON;
	tcsetattr(0, TCSANOW, &termios_new);

	std::cout << "\e[?25l";

	std::cout << "\e[2J";
	std::cout << "\e[H";

	std::cout << LINE_TOP;
	std::cout << "\u2551      SNAKE v0.3     \u2551\n";
	std::cout << LINE_MID;
	std::cout << "\e[s";
	std::cout << "\n\n\n\n\n\n\n";
	std::cout << LINE_MID;
	std::cout << "\u2551      Controls:      \u2551\n";
	std::cout << "\u2551        \u2191 w \u2191        \u2551\n";
	std::cout << "\u2551   \u2190 a \u2190     \u2192 d \u2192   \u2551\n";
	std::cout << "\u2551        \u2193 s \u2193        \u2551\n";
	std::cout << LINE_BOTTOM;

	game();

	std::cout << "\e[2J";
	std::cout << "\e[H";

	std::cout << "\e[?25h";

	tcsetattr(0, TCSANOW, &termios_old);

	return 0;
}
