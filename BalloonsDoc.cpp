// BalloonsDoc.cpp : implementation of the CBalloonsDoc class
//

#include "stdafx.h"
#include "Balloons.h"

#include "BalloonsDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBalloonsDoc

IMPLEMENT_DYNCREATE(CBalloonsDoc, CDocument)

BEGIN_MESSAGE_MAP(CBalloonsDoc, CDocument)
	//{{AFX_MSG_MAP(CBalloonsDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBalloonsDoc construction/destruction

CBalloonsDoc::CBalloonsDoc()
{
}

CBalloonsDoc::~CBalloonsDoc()
{
}

BOOL CBalloonsDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBalloonsDoc serialization

void CBalloonsDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CBalloonsDoc diagnostics

#ifdef _DEBUG
void CBalloonsDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBalloonsDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBalloonsDoc commands
