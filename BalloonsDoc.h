// BalloonsDoc.h : interface of the CBalloonsDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BALLOONSDOC_H__01AF963D_B949_47EF_B650_61E630777E1B__INCLUDED_)
#define AFX_BALLOONSDOC_H__01AF963D_B949_47EF_B650_61E630777E1B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBalloonsDoc : public CDocument
{
protected: // create from serialization only
	CBalloonsDoc();
	DECLARE_DYNCREATE(CBalloonsDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBalloonsDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBalloonsDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBalloonsDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BALLOONSDOC_H__01AF963D_B949_47EF_B650_61E630777E1B__INCLUDED_)
