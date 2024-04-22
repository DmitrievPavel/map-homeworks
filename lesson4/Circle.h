#pragma once
#define _USE_MATH_DEFINES
#include<cmath>
#include <vector>

class Circle {
private:
	int x;
	int y;
	double radius;
public:
	Circle() = default;
	~Circle() = default;
	void setParam(int coordX, int coordY, double _radius);
	double getSquare();
};