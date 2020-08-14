#pragma once

class Point{
public:
	Point(int x = 0, int y = 0);
	int x();
	int y();

	void randomize(int height, int width);

	Point up() const;
	Point down() const;
	Point left() const;
	Point right() const;

	bool operator==(const Point that) const;
	bool operator!=(const Point that) const;
private:
	int X,Y;
};
