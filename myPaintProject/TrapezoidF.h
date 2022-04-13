#pragma once
#include "Figure.h"
#include "RectangleF.h"

class TrapezoidF :public RectangleF {

	DECLARE_SERIAL(TrapezoidF)
public:
	TrapezoidF();
	TrapezoidF(int xx1, int yy1, int xx2, int yy2, COLORREF C1, COLORREF C2)
		:RectangleF(xx1, yy1, xx2, yy2, C1, C2)
	{

	}
	void trapezoid(CDC* dc) {
		CPoint p[4];
		
		p[0].x = x1 + abs(y1 - y2) / 3;
		p[0].y = y1;
		p[2].x = x2;
		p[2].y = y2;
		p[1].x = x1;
		p[1].y = y2;
		p[3].x = x2 - abs(y1 - y2) / 3;
		p[3].y = y1;
		
		dc->Polygon(p, 4);
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

		trapezoid(dc);

		dc->SelectObject(oldPen);
		dc->SetROP2(R2_COPYPEN);
		dc->SelectObject(oldBrush);
	}
};