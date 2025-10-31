#if !defined(AFX_EXITGAME_H__771D3278_21A6_4F0C_8526_E2230A24207A__INCLUDED_)
#define AFX_EXITGAME_H__771D3278_21A6_4F0C_8526_E2230A24207A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExitGame.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ExitGame dialog

class ExitGame : public CDialog
{
// Construction
public:
	ExitGame(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ExitGame)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ExitGame)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ExitGame)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXITGAME_H__771D3278_21A6_4F0C_8526_E2230A24207A__INCLUDED_)
