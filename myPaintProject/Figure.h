#pragma once
#include "stdafx.h"
#include <cmath>

class Figure : public CObject {

	DECLARE_SERIAL(Figure)   //!!! NO ";"
public:
	void Serialize(CArchive& ar);
	
public:
	int x1, y1, x2, y2;
	COLORREF penColor;
	COLORREF brushColor;
	Figure();
	Figure(int xx1, int yy1, int xx2, int yy2, COLORREF C1, COLORREF C2)
	{
		x1 = xx1;
		x2 = xx2;
		y1 = yy1;
		y2 = yy2;
		penColor = C1;
		brushColor = C2;
	}

	virtual void Draw(CDC* dc) {}
	virtual ~Figure(void);
};

