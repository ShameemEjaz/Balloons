// ExitGame.cpp : implementation file
//

#include "stdafx.h"
#include "Balloons.h"
#include "ExitGame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ExitGame dialog


ExitGame::ExitGame(CWnd* pParent /*=NULL*/)
	: CDialog(ExitGame::IDD, pParent)
{
	//{{AFX_DATA_INIT(ExitGame)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ExitGame::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ExitGame)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ExitGame, CDialog)
	//{{AFX_MSG_MAP(ExitGame)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ExitGame message handlers
