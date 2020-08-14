#pragma once

#include <deque>

#include "point.h"

class Snake{
public:
	Snake(Point p);

	std::deque<Point>::iterator begin();
	std::deque<Point>::iterator end();

	void move(Point p);
	void grow(Point p);

	Point up() const;
	Point down() const;
	Point left() const;
	Point right() const;
private:
	std::deque<Point> snake;
};
