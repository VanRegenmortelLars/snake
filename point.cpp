#include <cstdlib>
#include <ctime>

#include "point.h"

Point::Point(int x, int y){
		X = x;
		Y = y;
};

int Point::x(){
	return X;
}

int Point::y(){
	return Y;
}

void Point::randomize(int height, int width){
	X = std::rand() % width;
	Y = std::rand() % height;
}

Point Point::up() const{
	return {X, Y-1};
}

Point Point::down() const{
	return {X, Y+1};
}

Point Point::left() const{
	return {X-1, Y};
}

Point Point::right() const{
	return {X+1, Y};
}

bool Point::operator==(const Point that) const{
	return (this->X==that.X) && (this->Y==that.Y);
}

bool Point::operator!=(const Point that) const{
	return !(*this==that);
}
