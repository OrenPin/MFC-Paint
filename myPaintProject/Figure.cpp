#include "pch.h"
#include "stdafx.h"  //!!! 1st include
#include "Figure.h"

IMPLEMENT_SERIAL(Figure, CObject, 1)

Figure::Figure(void)
{
}

Figure::~Figure(void)
{
}

void Figure::Serialize(CArchive& ar) {
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << x1;
		ar << x2;
		ar << y1;
		ar << y2;
		ar << penColor;
		ar << brushColor;

	}
	else
	{
		ar >> x1;
		ar >> x2;
		ar >> y1;
		ar >> y2;
		ar >> penColor;
		ar >> brushColor;

	}
}