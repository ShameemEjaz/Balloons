// Inst.cpp : implementation file
//

#include "stdafx.h"
#include "Balloons.h"
#include "Inst.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Inst dialog


Inst::Inst(CWnd* pParent /*=NULL*/)
	: CDialog(Inst::IDD, pParent)
{
	//{{AFX_DATA_INIT(Inst)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Inst::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Inst)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Inst, CDialog)
	//{{AFX_MSG_MAP(Inst)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Inst message handlers
