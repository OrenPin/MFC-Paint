#pragma once
#include "Figure.h"
class EllipseF :public Figure {
	DECLARE_SERIAL(EllipseF)   //!!! NO ";"  

public:
	EllipseF();
	EllipseF(int xx1, int yy1, int xx2, int yy2, COLORREF C1, COLORREF C2)
		:Figure(xx1, yy1, xx2, yy2, C1, C2)
	{
	}
	void Draw(CDC* dc);
};