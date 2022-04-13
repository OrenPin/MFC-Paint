#include "pch.h"
#include "stdafx.h"
#include "EllipseF.h"


IMPLEMENT_SERIAL(EllipseF, CObject, 1)


EllipseF::EllipseF() {}

void EllipseF::Draw(CDC* dc) {
	CBrush myBrush, * oldBrush;
	myBrush.CreateSolidBrush(brushColor);
	oldBrush = dc->SelectObject(&myBrush);

	CPen myPen1(PS_SOLID, 3, penColor);
	CPen* oldPen;
	oldPen = dc->SelectObject(&myPen1);
	dc->SetROP2(R2_COPYPEN);


	dc->Ellipse(x1, y1, x2, y2);


	dc->SelectObject(oldPen);
	dc->SetROP2(R2_COPYPEN);
	dc->SelectObject(oldBrush);
}