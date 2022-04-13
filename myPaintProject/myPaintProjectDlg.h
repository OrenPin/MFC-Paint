
// myPaintProjectDlg.h : header file
//
#if !defined(AFX_DLGDLG_H__D02F91E6_1066_4AA4_AE0B_1D16C986AE2C__INCLUDED_)
#define AFX_DLGDLG_H__D02F91E6_1066_4AA4_AE0B_1D16C986AE2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Figure.h"
#include "RectangleF.h"
#include "EllipseF.h"
#include "Parallelogram.h"
#include "TriangleF.h"
#include "HourGlassF.h"
#include "TrapezoidF.h"
#include <vector>
#include "afxcolorbutton.h"
#include "UndoRedo.cpp"


using namespace std;
// CmyPaintProjectDlg dialog
class CmyPaintProjectDlg : public CDialogEx
{
	enum FIGURES { RECTANGLE, ELLIPSE, PARALLELOGRAM, TRIANGLE, HourGlass, Trapezoid };
	int index;
	bool isPressed;
	CPoint lastPoint;
	CPoint startP;
	CPoint endP;
	FIGURES futureFigKIND;
	Figure* f;
	COLORREF Pen1, Brush1;
	UndoRedo<Figure*> ur;
	CTypedPtrArray< CObArray, Figure*> figs;


// Construction
public:
	CmyPaintProjectDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYPAINTPROJECT_DIALOG };
#endif
	//making new types of variables!!!
	//CPoint start, end;
	//bool isPressed = false;
	//CTypedPtrArray< CObArray, Figure*> figs;
	//int futureFigureKind = 1; //Rectangle (2 - Ellipse)
	

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void resetFigures();
	afx_msg void restoreFigures();
	afx_msg void randomFigure();
	CMFCColorButton cBrush;
	CMFCColorButton cPen;
	afx_msg void OnBnClickedCancel();
	afx_msg void PieF();
	afx_msg void ArcF();
	afx_msg void selectColor();
	afx_msg void OnFileMenuLoad();
	afx_msg void OnFileMenuSave();
	afx_msg void selectPen();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGDLG_H__D02F91E6_1066_4AA4_AE0B_1D16C986AE2C__INCLUDED_)
