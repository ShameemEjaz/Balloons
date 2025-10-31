// BalloonsView.h : interface of the CBalloonsView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BALLOONSVIEW_H__CF66C5D0_65AC_4A90_8A10_3217FBD9F287__INCLUDED_)
#define AFX_BALLOONSVIEW_H__CF66C5D0_65AC_4A90_8A10_3217FBD9F287__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBalloonsView : public CView
{
protected: // create from serialization only
	CBalloonsView();
	DECLARE_DYNCREATE(CBalloonsView)

// Attributes
public:
	CBalloonsDoc* GetDocument();
	void GameSession();
	void GameEnd();

// Operations
public:

	BOOL Bonus,AroEnd;
	BOOL IsGameStarted,IsKeyPressed,IsFired,IsFirePressed,IsLoaded,IsFinished;
	int docNo,ANO,CNT,AYP,UDC,MPL;
	CBitmap m_Bitmap,m_ArtironsBM,m_balloonmask,m_deflatebitmap;
	int m_BitmapHeight,m_BitmapWidth;
	int UDcount,t,ArrowYpos, m_count, m_bonusCnt;
	BITMAP BM,Person;
	CDC m_BitmapMemdc,m_ArtironsMemdc,m_memdcballoonmask,m_deflatememdc;
	RECT ClientRect,ArrowRect;
	CBitmap m_bonus_1_bitmap; 
	CDC m_bonus_1_memdc; 

	CBitmap m_robindragshootmask,m_robindragshoot,m_robinshooteddragmask,m_robinshooteddrag;
	CDC m_memdcrobindragshootmask,m_memdcrobindragshoot,m_memdcrobinshooteddragmask,m_memdcrobinshooteddrag;
	CBitmap m_robin1,m_robin1mask,m_robin2,m_robin2mask,m_robin3,m_robin3mask,m_robindrag, m_robindragmask,m_spray,m_spraymask;
	CDC m_memdcrobin1,m_memdcrobin1mask,m_memdcrobin2,m_memdcrobin2mask,m_memdcrobin3,m_memdcrobin3mask,m_memdcrobindrag,m_memdcrobindragmask,m_memdcspray,m_memdcspraymask;
	int m_personlocation, m_arrownumber, m_points;
	CString m_str;

	struct balloon
	{
		int x1, y1, x2, y2;
		int balloonstatus;
		CBitmap balloonbitmap;
		CDC balloonmemdc;
		CBitmap balloonbgbitmap;
		CDC balloonbkmemdc;
		CBitmap burstballoonbitmap;
		CDC burstballoonmemdc;
	}m_b[10];

	struct arrow
	{
		int x1, y1, x2, y2;
		int arrowstatus;
		CBitmap arrowbitmap;
		CDC arrowmemdc;
		CBitmap arrowbgbitmap;
		CDC arrowbgmemdc;
	}m_a[15];

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBalloonsView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBalloonsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBalloonsView)
	afx_msg void OnFileNew();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnAppExit();
	afx_msg void OnDestroy();
	afx_msg void OnUpdateFileNew(CCmdUI* pCmdUI);
	afx_msg void OnHelp();
	afx_msg void OnPaint();
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnClose();
	afx_msg void OnUpdateClose(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BalloonsView.cpp
inline CBalloonsDoc* CBalloonsView::GetDocument()
   { return (CBalloonsDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BALLOONSVIEW_H__CF66C5D0_65AC_4A90_8A10_3217FBD9F287__INCLUDED_)
