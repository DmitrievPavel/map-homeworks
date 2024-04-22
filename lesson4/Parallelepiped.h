#pragma once
#include<cmath>
#include <vector>

class Parallelepiped {
private:
	std::vector<int> coordX;
	std::vector<int> coordY;
	std::vector<int> coordZ;
public:
	Parallelepiped() = default;
	~Parallelepiped() = default;
	void setCoordX(int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8);
	void setCoordY(int y1, int y2, int y3, int y4, int y5, int y6, int y7, int y8);
	void setCoordZ(int z1, int z2, int z3, int z4, int z5, int z6, int z7, int z8);
	double getSquare();
	double getVolume();
	void shiftXYZ(int offsetValueX, int offsetValueY, int offsetValueZ);
	void scaleX(int scaleValueX);
	void scaleY(int scaleValueY);
	void scaleZ(int scaleValueZ);
	void scale(int scaleValue);
};