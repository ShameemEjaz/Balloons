#if !defined(AFX_INST_H__9576173B_31E1_4E3D_8058_F873AC21E943__INCLUDED_)
#define AFX_INST_H__9576173B_31E1_4E3D_8058_F873AC21E943__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Inst.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Inst dialog

class Inst : public CDialog
{
// Construction
public:
	Inst(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Inst)
	enum { IDD = IDD_DIALOG2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Inst)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Inst)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INST_H__9576173B_31E1_4E3D_8058_F873AC21E943__INCLUDED_)
