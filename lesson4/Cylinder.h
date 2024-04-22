#pragma once
#define _USE_MATH_DEFINES
#include<cmath>
#include <vector>

class Cylinder {
private:
	int x;
	int y;
	double radius;
	double height;
public:
	Cylinder() = default;
	~Cylinder() = default;
	void setParam(int coordX, int coordY, double _radius, double _height);
	double getSquare();
	double getVolume();
};