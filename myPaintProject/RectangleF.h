#pragma once
#include "Figure.h"
class RectangleF : public Figure {
	DECLARE_SERIAL(RectangleF)   //!!! NO ";"  

public:
	RectangleF();
	RectangleF(int xx1, int yy1, int xx2, int yy2, COLORREF C1, COLORREF C2)
		:Figure(xx1, yy1, xx2, yy2, C1, C2)
	{

	}
	void Draw(CDC* dc)
	{
		CBrush myBrush, * oldBrush;
		myBrush.CreateSolidBrush(brushColor);
		oldBrush = dc->SelectObject(&myBrush);

		CPen myPen1(PS_SOLID, 3, penColor);
		CPen* oldPen;
		oldPen = dc->SelectObject(&myPen1);
		dc->SetROP2(R2_COPYPEN);

		dc->Rectangle(x1, y1, x2, y2);

		dc->SelectObject(oldPen);
		dc->SetROP2(R2_COPYPEN);
		dc->SelectObject(oldBrush);
	}
};