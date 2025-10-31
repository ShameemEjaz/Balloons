// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Balloons.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[5];

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
}

CMainFrame::~CMainFrame()
{
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	cs.lpszName=" Balloons"; // Setting windows title
	cs.cx=600;
	cs.cy=450;
	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX; //| FWS_ADDTOTITLE
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS,
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1),AfxGetApp()->LoadIcon(IDR_MAINFRAME));
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
//	m_sb.CreateEx(this,SBARS_SIZEGRIP|SBT_TOOLTIPS ,WS_CHILD | WS_VISIBLE | CBRS_BOTTOM,AFX_IDW_STATUS_BAR);
	m_sb.Create(this,WS_CHILD | WS_VISIBLE | CBRS_BOTTOM,NULL);
	
	return 0;
}


void CMainFrame::PaneInfo()
{

	m_sb.SetIndicators(indicators,5); 

	// Setting spaces for info bits on statusbar
	m_sb.SetPaneInfo(0,ID_SEPARATOR,SBPS_NORMAL,80);//  SBPS_NOBORDERS
	m_sb.SetPaneInfo(1,ID_SEPARATOR,SBPS_NORMAL,110);
	m_sb.SetPaneInfo(2,ID_SEPARATOR,SBPS_NORMAL,90);
	m_sb.SetPaneInfo(3,ID_SEPARATOR,SBPS_NORMAL,70);
	m_sb.SetPaneInfo(4,ID_SEPARATOR,SBPS_NORMAL|SBPS_STRETCH,0); 
}

void CMainFrame::PaneText(int no, CString lpt)
{
	m_sb.SetPaneText(no,lpt,TRUE);
}


void CMainFrame::ErasePaneInfo()
{
	CClientDC dc(this);

	m_sb.SetPaneInfo(0,ID_SEPARATOR,SBPS_NORMAL|SBPS_STRETCH,GetDeviceCaps(dc, HORZRES));
	PaneText(0,"  K A R A C H I    P A K I S T A N");
}