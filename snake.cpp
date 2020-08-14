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

void Snake::move(Point p){
	snake.insert(snake.begin(), p);
	snake.pop_back();
}

void Snake::grow(Point p){
	snake.insert(snake.begin(), p);
}

Point Snake::up() const{
	return snake.front().up();
}

Point Snake::down() const{
	return snake.front().down();
}

Point Snake::left() const{
	return snake.front().left();
}

Point Snake::right() const{
	return snake.front().right();
}
