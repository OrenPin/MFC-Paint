#pragma once
#include "Figure.h"

class TriangleF :public Figure {

	DECLARE_SERIAL(TriangleF)

public:
	TriangleF();
	TriangleF(int xx1, int yy1, int xx2, int yy2, COLORREF C1, COLORREF C2)
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
		//int x3 = x1, y3 = y2;
		// the notes here make it a Right-angled triangle
		/*CPoint p[3];
		p[0].x = x1;
		p[0].y = y1;
		p[1].x = x2;
		p[1].y = y2;
		p[2].x = x3;
		p[2].y = y3;*/
		CPoint p[3];
		p[0].x = x1 + (x2 - x1) / 2;
		p[0].y = y1;
		p[1].x = x2;
		p[1].y = y2;
		p[2].x = x1;
		p[2].y = y2;
		dc->Polygon(p, 3);
		dc->SelectObject(oldPen);
		dc->SetROP2(R2_COPYPEN);
		dc->SelectObject(oldBrush);
	}
};