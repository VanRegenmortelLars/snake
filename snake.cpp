#include "snake.h"

Snake::Snake(Point p){
	snake = {p};
};

std::deque<Point>::iterator Snake::begin(){
	return snake.begin();
}

std::deque<Point>::iterator Snake::end(){
	return snake.end();
}

void Snake::up(){
	move(snake.front().up());
}

void Snake::down(){
	move(snake.front().down());
}

void Snake::left(){
	move(snake.front().left());
}

void Snake::right(){
	move(snake.front().right());
}

void Snake::move(Point p){
	snake.insert(snake.begin(), p);
	if(!food.empty() && snake.back()==food.back())
		food.pop_back();
	else
		snake.pop_back();
}

Point Snake::head() const{
	return snake.front();
}

void Snake::feed(){
	food.push_front(head());
}
