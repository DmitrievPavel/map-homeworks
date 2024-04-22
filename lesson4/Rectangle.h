#pragma once
#include<cmath>
#include <vector>

class Rectangle {
private:
	std::vector<int> coordX;
	std::vector<int> coordY;
public:
	Rectangle() = default;
	~Rectangle() = default;
	void setCoordX(int x1, int x2, int x3, int x4);
	void setCoordY(int y1, int y2, int y3, int y4);
	double getSquare();
	void shiftXY(int offsetValueX, int offsetValueY);
	void scaleX(int scaleValueX);
	void scaleY(int scaleValueY);
	void scale(int scaleValue);
};