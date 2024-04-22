#include "Parallelepiped.h"

Parallelepiped::setCoordX(int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8) {
	coordX.push_back(x1);
	coordX.push_back(x2);
	coordX.push_back(x3);
	coordX.push_back(x4);
	coordX.push_back(x5);
	coordX.push_back(x6);
	coordX.push_back(x7);
	coordX.push_back(x8);
}

Parallelepiped::setCoordY(int y1, int y2, int y3, int y4, int y5, int y6, int y7, int y8) {
	coordY.push_back(y1);
	coordY.push_back(y2);
	coordY.push_back(y3);
	coordY.push_back(y4);
	coordY.push_back(y5);
	coordY.push_back(y6);
	coordY.push_back(y7);
	coordY.push_back(y8);
}

Parallelepiped::setCoordZ(int z1, int z2, int z3, int z4, int z5, int z6, int z7, int z8) {
	coordZ.push_back(z1);
	coordZ.push_back(z2);
	coordZ.push_back(z3);
	coordZ.push_back(z4);
	coordZ.push_back(z5);
	coordZ.push_back(z6);
	coordZ.push_back(z7);
	coordZ.push_back(z8);
}

Parallelepiped::getSquare() {
	int a = abs(coordX[0] - coordX[1]);
	int b = abs(coordY[0] - coordY[1]);
	int c = abs(coordZ[0] - coordZ[1]);
	return 2 * ((a * b) + (b * c) + (a * c));
}

Parallelepiped::getVolume() {
	int a = abs(coordX[0] - coordX[1]);
	int b = abs(coordY[0] - coordY[1]);
	int c = abs(coordZ[0] - coordZ[1]);
	return a * b * c;
}

Parallelepiped::shiftXYZ(int offsetValueX, int offsetValueY, int offsetValueZ) {
	for (int i = 0; i < coordX.size(); ++i) {
		coordX[i] += offsetValueX;
	}
	for (int i = 0; i < coordY.size(); ++i) {
		coordY[i] += offsetValueY;
	}
	for (int i = 0; i < coordZ.size(); ++i) {
		coordZ[i] += offsetValueZ;
	}

}

Parallelepiped::scaleX(int scaleValueX) {
	for (int i = 0; i < coordX.size(); ++i) {
		coordX[i] *= scaleValueX;
	}
}

Parallelepiped::scaleY(int scaleValueY) {
	for (int i = 0; i < coordY.size(); ++i) {
		coordY[i] *= scaleValueY;
	}
}

Parallelepiped::scaleZ(int scaleValueZ) {
	for (int i = 0; i < coordZ.size(); ++i) {
		coordZ[i] *= scaleValueZ;
	}
}

Parallelepiped::scale(int scaleValue) {
	for (int i = 0; i < coordX.size(); ++i) {
		coordX[i] /= scaleValue;
		coordY[i] /= scaleValue;
		coordZ[i] /= scaleValue;
	}
}

