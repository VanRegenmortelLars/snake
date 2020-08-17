#pragma once

#include <deque>

#include "point.h"

class Snake{
public:
	Snake(Point p);

	std::deque<Point>::iterator begin();
	std::deque<Point>::iterator end();

	void up();
	void down();
	void left();
	void right();

	void feed();
	Point head() const;

private:
	std::deque<Point> snake;
	std::deque<Point> food;

	void move(Point p);
};
