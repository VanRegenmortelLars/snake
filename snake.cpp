#include <algorithm>

#include "snake.h"

Snake::Snake(Point p){
	body = {p};
};

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

bool Snake::hit_itself_or_wall(int height, int width) const{

	// Verify whether snake hits itself
	if(std::count(body.begin(), body.end(), head()) > 1)
		return true;

	// Verify whether snake hits the wall
	if( (head().x()<0) || (head().x()>width-1) \
		|| (head().y()<0) || (head().y()>height-1) )
		return true;

	return false;
}
