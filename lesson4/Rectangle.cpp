#include "Rectangle.h"

Rectangle::setCoordX(int x1, int x2, int x3, int x4) {
	coordX.push_back(x1);
	coordX.push_back(x2);
	coordX.push_back(x3);
	coordX.push_back(x4);
}

Rectangle::setCoordY(int y1, int y2, int y3, int y4) {
	coordY.push_back(y1);
	coordY.push_back(y2);
	coordY.push_back(y3);
	coordY.push_back(y4);
}

Rectangle::getSquare() {
	int a = abs(coordX[0] - coordX[1]);
	int b = abs(coordY[0] - coordY[1]);
	return a * b;
}

Rectangle::shiftXY(int offsetValueX, int offsetValueY) {
	for (int i = 0; i < coordX.size(); ++i) {
		coordX[i] += offsetValueX;
	}

	for (int i = 0; i < coordY.size(); ++i) {
		coordY[i] += offsetValueY;
	}
}

Rectangle::scaleX(int scaleValueX) {
	for (int i = 0; i < coordX.size(); ++i) {
		coordX[i] *= scaleValueX;
	}
}

Rectangle::scaleY(int scaleValueY) {
	for (int i = 0; i < coordY.size(); ++i) {
		coordY[i] *= scaleValueY;
	}
}

Rectangle::scale(int scaleValue) {
	for (int i = 0; i < coordX.size(); ++i) {
		coordX[i] /= scaleValue;
		coordY[i] /= scaleValue;
	}
}