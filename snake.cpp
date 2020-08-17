#include "snake.h"

Snake::Snake(Point p){
	body = {p};
};

std::deque<Point>::iterator Snake::begin(){
	return body.begin();
}

std::deque<Point>::iterator Snake::end(){
	return body.end();
}

void Snake::up(){
	move(head().up());
}

void Snake::down(){
	move(head().down());
}

void Snake::left(){
	move(head().left());
}

void Snake::right(){
	move(head().right());
}

void Snake::move(Point p){
	body.push_front(p);
	if(!food.empty() && body.back()==food.back())
		food.pop_back();
	else
		body.pop_back();
}

Point Snake::head() const{
	return body.front();
}

void Snake::feed(){
	food.push_front(head());
}
