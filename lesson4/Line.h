#pragma once
#include<cmath>
#include <vector>

class Line {
private:
	std::vector<int> coordX;
	std::vector<int> coordY;
public:
	Line() = default;
	~Line() = default;
	void setCoordX(int x1, int x2);
	void setCoordY(int y1, int y2);
	void shiftXY(int offsetValueX, int offsetValueY);
	void scaleX(int scaleValueX);
	void scaleY(int scaleValueY);
	void scale(int scaleValue);
};