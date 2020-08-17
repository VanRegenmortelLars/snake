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

	std::deque<Point> const * get_body(){ return &body; };
	std::deque<Point> const * get_food(){ return &food; };

private:
	std::deque<Point> body;
	std::deque<Point> food;

	void move(Point p);
};
