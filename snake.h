#pragma once

#include <deque>

#include "point.h"

class Snake{
public:
	Snake(Point p);

	void up();
	void down();
	void left();
	void right();

	void feed();
	Point head() const;

	std::deque<Point> const * get_body(){ return &body; };
	std::deque<Point> const * get_food(){ return &food; };

	bool hit_itself_or_wall(int height, int width) const;

private:
	std::deque<Point> body;
	std::deque<Point> food;

	void move(Point p);
};
