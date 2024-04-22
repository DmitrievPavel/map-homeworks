#include "Circle.h"

Circle::setParam(int coordX, int coordY, double _radius) {
	x = coordX;
	y = coordY;
	radius = _radius;
}

Circle::getSquare() {
	return M_PI * radius * radius;
}