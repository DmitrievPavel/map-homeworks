#include "Cylinder.h"

Cylinder::setParam(int coordX, int coordY, double _radius, double _height) {
	x = coordX;
	y = coordY;
	radius = _radius;
	height = _height;
}

Cylinder::getSquare() {
	return (M_PI * (radius * radius)) + (2 * radius * height);
}

Cylinder::getVolume() {
	return M_PI * radius * radius * height;
}
