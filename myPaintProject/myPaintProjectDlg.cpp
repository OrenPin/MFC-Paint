
// myPaintProjectDlg.cpp : implementation file

#include "pch.h"
#include "framework.h"
#include "myPaintProject.h"
#include "myPaintProjectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmyPaintProjectDlg dialog



CmyPaintProjectDlg::CmyPaintProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYPAINTPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmyPaintProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmyPaintProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_RADIO2, &CmyPaintProjectDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO1, &CmyPaintProjectDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO3, &CmyPaintProjectDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CmyPaintProjectDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_BUTTON3, &CmyPaintProjectDlg::resetFigures)
	ON_BN_CLICKED(IDC_BUTTON4, &CmyPaintProjectDlg::restoreFigures)
	ON_BN_CLICKED(IDC_BUTTON6, &CmyPaintProjectDlg::randomFigure)
	ON_BN_CLICKED(IDCANCEL, &CmyPaintProjectDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON5, &CmyPaintProjectDlg::PieF)
	ON_BN_CLICKED(IDC_BUTTON7, &CmyPaintProjectDlg::ArcF)
	ON_BN_CLICKED(IDC_BUTTON12, &CmyPaintProjectDlg::selectColor)
	ON_COMMAND(ID_FILE_MENU_LOAD, &CmyPaintProjectDlg::OnFileMenuLoad)
	ON_COMMAND(ID_FILE_MENU_SAVE, &CmyPaintProjectDlg::OnFileMenuSave)
	ON_BN_CLICKED(IDC_BUTTON1, &CmyPaintProjectDlg::selectPen)
	ON_BN_CLICKED(IDC_RADIO5, &CmyPaintProjectDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &CmyPaintProjectDlg::OnBnClickedRadio6)
END_MESSAGE_MAP()


// CmyPaintProjectDlg message handlers

BOOL CmyPaintProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// Add "About..." menu item to system menu.

	
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	//!! 16 b
	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1);
	//!! 16 e

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CmyPaintProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CmyPaintProjectDlg::OnPaint()
{

	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//our painting should be before the call to base class OnPaint()
		CPaintDC dc(this); // device context for painting

		//change order: segment 1st, rectangle 2nd ...

		/*CPoint P1(20, 10);
		CPoint P2(700, 600);
		CPoint P3(40, 20);
		CPoint P4(1400, 1200);*/

		// drawing rectangles on the screen app
		//
		for (int i = 0; i < figs.GetSize(); i++)
			figs[i]->Draw(&dc);
		CDialogEx::OnPaint();

		//printing rectangle, line and ellipse all together
		//
		/*dc.Rectangle(P1.x, P1.y, P2.x, P2.y);
		dc.MoveTo(P1);
		dc.LineTo(P2);
		dc.Ellipse(P1.x, P1.y, P2.x, P2.y);*/

		// comment these drawings and uncomment the following lines

		//printing rectangle with green edges
		// 
		//CPen pen1, * oldPen;
		//pen1.CreatePen(PS_SOLID, 3/* width */, RGB(0, 255, 0));
		//oldPen = dc.SelectObject(&pen1);
		//dc.Rectangle(P1.x, P1.y, P2.x, P2.y);
		//dc.SelectObject(oldPen);

		//printing circle filled in yellow
		// 
		//CBrush myBrush, * oldBrush;
		////Yellow   
		//myBrush.CreateSolidBrush(RGB(255, 255, 0));
		//oldBrush = dc.SelectObject(&myBrush);
		//dc.Ellipse(P1.x, P1.y, P2.x, P2.y);
		//dc.SelectObject(oldBrush);

		//printing red line
		// 
		//CPen pen2, * oldPen2;
		//pen2.CreatePen(PS_SOLID, 3/* width */, RGB(255, 100, 100));
		//oldPen2 = dc.SelectObject(&pen2);
		//dc.MoveTo(P1);
		//dc.LineTo(P2);
		//dc.SelectObject(oldPen2);

		// printing half circle
		// 
		//CPen pen3, * oldPen3;
		//pen3.CreatePen(PS_SOLID, 3/* width */, RGB(255, 100, 100));
		//oldPen3 = dc.SelectObject(&pen3);
		//dc.MoveTo(P1);
		//dc.Pie(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, P4.x, P4.y);
		//dc.SelectObject(oldPen3);

		//////!! 0 e
		//CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CmyPaintProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CmyPaintProjectDlg::OnLButtonDown(UINT nFlags, CPoint point)
{

	endP = startP = point;
	isPressed = true;

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CmyPaintProjectDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (isPressed)
	{

		endP = point;
		isPressed = false;

		switch (futureFigKIND)
		{
		case RECTANGLE:
			figs.Add(new RectangleF(startP.x, startP.y, endP.x, endP.y, Pen1, Brush1));
			ur.addNew(figs[figs.GetSize() - 1]);
			break;
		case ELLIPSE:
			figs.Add(new EllipseF(startP.x, startP.y, endP.x, endP.y, Pen1, Brush1));
			ur.addNew(figs[figs.GetSize() - 1]);
			break;
		case PARALLELOGRAM:
			figs.Add(new ParallelogramF(startP.x, startP.y, endP.x, endP.y, Pen1, Brush1));
			ur.addNew(figs[figs.GetSize() - 1]);
			break;
		case TRIANGLE:
			figs.Add(new TriangleF(startP.x, startP.y, endP.x, endP.y, Pen1, Brush1));
			ur.addNew(figs[figs.GetSize() - 1]);
			break;
		case HourGlass:
			figs.Add(new HourGlassF(startP.x, startP.y, endP.x, endP.y, Pen1, Brush1));
			ur.addNew(figs[figs.GetSize() - 1]);
			break;
		case Trapezoid:
			figs.Add(new TrapezoidF(startP.x, startP.y, endP.x, endP.y, Pen1, Brush1));
			ur.addNew(figs[figs.GetSize() - 1]);
			break;
		}
		Invalidate();
	}

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CmyPaintProjectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (isPressed)
	{
		CClientDC dc(this);
		CBrush* oldBrush;
		CPen* oldPen;
		CBrush myBrush;
		CPoint p[4];
		CPoint pts[3];
		myBrush.CreateSolidBrush(Brush1);
		oldBrush = dc.SelectObject(&myBrush);

		CPen myPen1(PS_SOLID, 3, Pen1);
		oldPen = dc.SelectObject(&myPen1);
		dc.SetROP2(R2_NOTXORPEN);

		switch (futureFigKIND)
		{
		case RECTANGLE:
			dc.Rectangle(startP.x, startP.y, endP.x, endP.y);
			endP = point;
			dc.Rectangle(startP.x, startP.y, endP.x, endP.y);
			break;
		case ELLIPSE:
			dc.Ellipse(startP.x, startP.y, endP.x, endP.y);
			endP = point;
			dc.Ellipse(startP.x, startP.y, endP.x, endP.y);
			break;
		case PARALLELOGRAM:
			int x3, x4, y3, y4;
			if (startP.x > endP.x)
			{
				p[0].x = startP.x;
				p[0].y = startP.y;
				p[2].x = endP.x;
				p[2].y = endP.y;
				p[1].x = startP.x - abs(startP.x - endP.x) / 3;
				p[1].y = endP.y;
				p[3].x = endP.x + abs(startP.x - endP.x) / 3;
				p[3].y = startP.y;

			}
			else
			{
				p[0].x = startP.x;
				p[0].y = startP.y;
				p[1].x = endP.x - abs(endP.x - startP.x) / 3;
				p[1].y = startP.y;
				p[2].x = endP.x;
				p[2].y = endP.y;
				p[3].x = endP.x - 2 * abs(endP.x - startP.x) / 3;
				p[3].y = endP.y;
			}

			dc.Polygon(p, 4);
			endP = point;
			if (startP.x > endP.x)
			{
				p[0].x = startP.x;
				p[0].y = startP.y;
				p[2].x = endP.x;
				p[2].y = endP.y;
				p[1].x = startP.x - abs(startP.x - endP.x) / 3;
				p[1].y = endP.y;
				p[3].x = endP.x + abs(startP.x - endP.x) / 3;
				p[3].y = startP.y;

			}
			else
			{
				p[0].x = startP.x;
				p[0].y = startP.y;
				p[1].x = endP.x - abs(endP.x - startP.x) / 3;
				p[1].y = startP.y;
				p[2].x = endP.x;
				p[2].y = endP.y;
				p[3].x = endP.x - 2 * abs(endP.x - startP.x) / 3;
				p[3].y = endP.y;
			}
			dc.Polygon(p, 4);
			break;
		case TRIANGLE: // the notes here make it a Right-angled triangle
			//int xx3 = startP.x, yy3 = endP.y;
			//pts[0].x = startP.x;
			pts[0].x = startP.x + (endP.x - startP.x) / 2;
			pts[0].y = startP.y;
			pts[1].x = endP.x;
			pts[1].y = endP.y;
			pts[2].x = startP.x;
			//pts[2].x = xx3;
			pts[2].y = endP.y;
			//pts[2].y = yy3;
			dc.Polygon(pts, 3);
			endP = point;
			//xx3 = startP.x;
			//yy3 = endP.y;
			/*pts[0].x = startP.x;
			pts[0].y = startP.y;
			pts[1].x = endP.x;
			pts[1].y = endP.y;
			pts[2].x = xx3;
			pts[2].y = yy3;*/
			pts[0].x = startP.x + (endP.x - startP.x) / 2;
			pts[0].y = startP.y;
			pts[1].x = endP.x;
			pts[1].y = endP.y;
			pts[2].x = startP.x;
			pts[2].y = endP.y;
			dc.Polygon(pts, 3);
			break;
		case HourGlass:
			p[0].x = startP.x;
			p[0].y = startP.y;
			p[2].x = endP.x;
			p[2].y = endP.y;
			p[1].x = startP.x - abs(startP.x - endP.x) / 3;
			p[1].y = endP.y;
			p[3].x = endP.x + abs(startP.x - endP.x) / 3;
			p[3].y = startP.y;
			dc.Polygon(p, 4);
			break;
		case Trapezoid:
			p[0].x = startP.x;
			p[0].y = startP.y;
			p[2].x = endP.x;
			p[2].y = endP.y;
			p[1].x = startP.x - abs(startP.x - endP.x) / 3;
			p[1].y = endP.y;
			p[3].x = endP.x + abs(startP.x - endP.x) / 3;
			p[3].y = startP.y;
			dc.Polygon(p, 4);
			break;
		}

		dc.SelectObject(oldPen);
		dc.SetROP2(R2_COPYPEN);
		dc.SelectObject(oldBrush);

	}
	CDialogEx::OnMouseMove(nFlags, point);
}


void CmyPaintProjectDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	futureFigKIND = ELLIPSE;
}


void CmyPaintProjectDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	futureFigKIND = RECTANGLE;
}


//void CmyPaintProjectDlg::OnBnClickedButton1()
//{
//	// TODO: Add your control notification handler code here
//	//!! 23 b
//				 // FALSE to SAVE
//	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
//	CString filename;
//	if (dlg.DoModal() == IDOK)
//	{
//		filename = dlg.GetPathName(); // return full path and filename
//		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
//		CArchive ar(&file, CArchive::store);
//		figs.Serialize(ar);
//		ar.Close();
//		file.Close();
//	}
//	//!! 23 e
//}


//void CmyPaintProjectDlg::OnBnClickedButton2()
//{
//	// TODO: Add your control notification handler code here
//	//!! 24 b
//				 // TRUE to LOAD
//	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
//	CString filename;
//	if (dlg.DoModal() == IDOK)
//	{
//		filename = dlg.GetPathName(); // return full path and filename
//		CFile file(filename, CFile::modeRead);
//		CArchive ar(&file, CArchive::load);
//		figs.Serialize(ar);
//		ar.Close();
//		file.Close();
//		Invalidate();
//	}
//	//!! 24 e
//}


void CmyPaintProjectDlg::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	futureFigKIND = PARALLELOGRAM;
}


void CmyPaintProjectDlg::OnBnClickedRadio4()
{
	// TODO: Add your control notification handler code here
	futureFigKIND = TRIANGLE;
}

void CmyPaintProjectDlg::resetFigures()
{
	// TODO: Add your control notification handler code here
	for (int i = 0;i < figs.GetSize();i++)
	{
		ur.addNew(figs[i]);
		ur.Delete();
	}
	figs.RemoveAll();
	Invalidate();
}


void CmyPaintProjectDlg::restoreFigures()
{
	// TODO: Add your control notification handler code here

	while (!(ur.rIsEmpty()))
	{
		figs.Add(ur.top());
		ur.DeleteR();
		Invalidate();
	}

}

void CmyPaintProjectDlg::randomFigure()
{
	// TODO: Add your control notification handler code here
	srand(time(NULL));
	futureFigKIND = static_cast<FIGURES>(rand() % 6);
}

void CmyPaintProjectDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CmyPaintProjectDlg::PieF()
{
	// TODO: Add your control notification handler code here
	srand(time(NULL));
	CClientDC dc(this);
	CPen pen2(PS_SOLID, 5, RGB(rand() % 255, rand() % 255, rand() % 255));
	CPen* oldBp2 = dc.SelectObject(&pen2);
	CBrush Brush2, * oldB2;
	Brush2.CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
	oldB2 = dc.SelectObject(&Brush2);
	CRect rect(rand() % 1000, rand() % 1000, rand() % 1000, rand() % 1000);
	dc.Pie(rect, CPoint(rand() % 1000, (rand() % 1000)+ 600), CPoint(rand() % 20, rand() % 20));
}


void CmyPaintProjectDlg::ArcF()
{
	// TODO: Add your control notification handler code here
	srand(time(NULL));
	CClientDC dc(this);
	CPen pen2(PS_SOLID, 5, RGB(rand() % 255, rand() % 255, rand() % 255));
	CPen* oldP2 = dc.SelectObject(&pen2);
	dc.Arc(rand() % 1000, rand() % 1000, rand() % 1000, rand() % 1000, rand() % 1000, rand() % 1000, rand() % 1000, rand() % 1000);
}



void CmyPaintProjectDlg::selectColor()
{
	// TODO: Add your control notification handler code here
	CColorDialog Brush;
	if (Brush.DoModal() == IDOK)
		Brush1 = Brush.GetColor();
}

//void CmyPaintProjectDlg::OnBnClickedMfccolorbutton2()
//{
//	// TODO: Add your control notification handler code here
//	Brush = cBrush.GetColor();
//}
//
//
//void CmyPaintProjectDlg::OnBnClickedMfccolorbutton1()
//{
//	// TODO: Add your control notification handler code here
//	Pen = cPen.GetColor();
//}

void CmyPaintProjectDlg::OnFileMenuLoad()
{
	// TODO: Add your control notification handler code here
	//!! 24 b
				 // TRUE to LOAD
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
	//!! 24 e
}


void CmyPaintProjectDlg::OnFileMenuSave()
{
	// TODO: Add your control notification handler code here
	//!! 23 b
				 // FALSE to SAVE
	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
	}
	//!! 23 e
}


void CmyPaintProjectDlg::selectPen()
{
	// TODO: Add your control notification handler code here
	CColorDialog Brush;
	if (Brush.DoModal() == IDOK)
		Pen1 = Brush.GetColor();
}

void CmyPaintProjectDlg::OnBnClickedRadio5()
{
	// TODO: Add your control notification handler code here
	futureFigKIND = HourGlass;
}


void CmyPaintProjectDlg::OnBnClickedRadio6()
{
	// TODO: Add your control notification handler code here
	futureFigKIND = Trapezoid;
}