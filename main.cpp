// Snake
// Author: Van Regenmortel Lars
// Date: August 2020

#include <iostream>
#include <string>
#include <termios.h>

#include "point.h"
#include "snake.h"

#define LINE_TOP "\u2554\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2557\n"
#define LINE_MID "\u255F\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2562\n"
#define LINE_BOTTOM "\u255A\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u255D\n"
#define LINE_EMPTY "\u2551                     \u2551\n"

#define CURSOR_MOVE(p) "\e[" + std::to_string(p.y()+4) +  ";" + std::to_string(3*p.x()+3) + "H"

#define HEIGHT 7
#define WIDTH 7

void display(Snake snake, Point candy){

	// Clear board
	std::cout << "\e[u";
	for(int i = 0; i < HEIGHT; i++)
		std::cout << LINE_EMPTY;

	// Display snake (body)
	for(Point p: *snake.get_body()){
		std::cout << CURSOR_MOVE(p);
		std::cout << "\u25A1";
	}

	// Display snake (food)
	for(Point p: *snake.get_food()){
		std::cout << CURSOR_MOVE(p);
		std::cout << "\u25A3";
	}

	// Display candy
	std::cout << CURSOR_MOVE(candy);
	std::cout << "\u25A0";
}

bool move(Snake * snake, Point * candy){


	// Read user input
	char input;
	std::cin >> input;

	// Move snake according to user input
	switch(input){
		case 27:
			return false;
			break;
		case 'w':
			snake->up();
			break;
		case 's':
			snake->down();
			break;
		case 'a':
			snake->left();
			break;
		case 'd':
			snake->right();
			break;
		default:
			return true;
	}

	// Feed snake if snake eats candy
	if(snake->head()==*candy){
		snake->feed();
		candy->randomize(HEIGHT, WIDTH, *snake->get_body());
	}

	return true;
}

void game(){

	Snake snake = Snake({3, 3});

	Point candy;
	candy.randomize(HEIGHT, WIDTH, *snake.get_body());

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
	termios_new.c_lflag &= ~ICANON & ~ECHO;
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
