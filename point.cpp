#include <cstdlib>
#include <ctime>
#include <set>

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

void Point::randomize(int height, int width, std::deque<Point> occupied){

	std::set<Point> set;
	for(int i = 0; i < width; i++)
		for(int j = 0; j < height; j++)
			set.insert(Point(i, j));

	for(Point p: occupied)
		set.erase(p);

	std::set<Point>::iterator element = set.begin();
	std::advance(element, std::rand() % set.size());
	*this = *element;
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

bool Point::operator<(const Point that) const{
	return (Y!=that.Y) ? (Y<that.Y) : (X<that.X);
}
