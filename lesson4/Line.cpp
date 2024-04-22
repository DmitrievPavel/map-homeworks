#include "Line.h"

Line::setCoordX(int x1, int x2) {
	coordX.push_back(x1);
	coordX.push_back(x2);
}

Line::setCoordY(int y1, int y2) {
	coordY.push_back(y1);
	coordY.push_back(y2);
}

Line::shiftXY(int offsetValueX, int offsetValueY) {
	for (int i = 0; i < coordX.size(); ++i) {
		coordX[i] += offsetValueX;
	}

	for (int i = 0; i < coordY.size(); ++i) {
		coordY[i] += offsetValueY;
	}
}

Line::scaleX(int scaleValueX) {
	for (int i = 0; i < coordX.size(); ++i) {
		coordX[i] *= scaleValueX;
	}
}

Line::scaleY(int scaleValueY) {
	for (int i = 0; i < coordY.size(); ++i) {
		coordY[i] *= scaleValueY;
	}
}

Line::scale(int scaleValue) {
	for (int i = 0; i < coordX.size(); ++i) {
		coordX[i] /= scaleValue;
		coordY[i] /= scaleValue;
	}
}