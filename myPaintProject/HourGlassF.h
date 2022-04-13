#pragma once
#include "Figure.h"
#include "RectangleF.h"

class HourGlassF :public RectangleF {

	DECLARE_SERIAL(HourGlassF)
public:
	HourGlassF();
	HourGlassF(int xx1, int yy1, int xx2, int yy2, COLORREF C1, COLORREF C2)
		:RectangleF(xx1, yy1, xx2, yy2, C1, C2)
	{

	}
	void hourglass(CDC* dc) {
		CPoint p[6];
		p[0].x = x1 + (x2 - x1) / 2;
		p[0].y = y1 + (y2 - y1) / 2;
		p[1].x = x2;
		p[1].y = y2;
		p[2].x = x1;
		p[2].y = y2;
		p[3].x = x1 + (x2 - x1) / 2;
		p[3].y = y1 + (y2 - y1) / 2;
		p[4].x = x1;
		p[4].y = y1;
		p[5].x = x2;
		p[5].y = y1;
		dc->Polygon(p, 6);
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

		hourglass(dc);

		dc->SelectObject(oldPen);
		dc->SetROP2(R2_COPYPEN);
		dc->SelectObject(oldBrush);
	}
};