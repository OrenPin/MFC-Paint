#pragma once
#include "Figure.h"
#include "RectangleF.h"

class ParallelogramF :public RectangleF {

	DECLARE_SERIAL(ParallelogramF)
public:
	ParallelogramF();
	ParallelogramF(int xx1, int yy1, int xx2, int yy2, COLORREF C1, COLORREF C2)
		:RectangleF(xx1, yy1, xx2, yy2, C1, C2)
	{

	}
	void paralel(CDC* dc) {
		CPoint p[4];
		if (x1 > x2)
		{
			p[0].x = x1;
			p[0].y = y1;
			p[2].x = x2;
			p[2].y = y2;
			p[1].x = x1 - abs(x1 - x2) / 3;
			p[1].y = y2;
			p[3].x = x2 + abs(x1 - x2) / 3;
			p[3].y = y1;

		}
		else
		{
			p[0].x = x1;
			p[0].y = y1;
			p[1].x = x2 - abs(x2 - x1) / 3;
			p[1].y = y1;
			p[2].x = x2;
			p[2].y = y2;
			p[3].x = x2 - 2 * abs(x2 - x1) / 3;
			p[3].y = y2;
		}
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

		paralel(dc);


		//CPoint p[4];

		/*if (x1 > x2)
		{
			p[0].x = x1;
			p[0].y = y1;
			p[2].x = x2;
			p[2].y = y2;
			p[1].x = x1 - abs(x1 - x2) / 3;
			p[1].y = y2;
			p[3].x = x2 + abs(x1 - x2) / 3;
			p[3].y = y1;

		}
		else
		{
			p[0].x = x1;
			p[0].y = y1;
			p[1].x = x2 - abs(x2 - x1) / 3;
			p[1].y = y1;
			p[2].x = x2;
			p[2].y = y2;
			p[3].x = x2 - 2 * abs(x2 - x1) / 3;
			p[3].y = y2;
		}*/
		//dc->Polygon(p, 4);
		dc->SelectObject(oldPen);
		dc->SetROP2(R2_COPYPEN);
		dc->SelectObject(oldBrush);
	}
};