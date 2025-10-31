// BalloonsView.cpp : implementation of the CBalloonsView class
//

#include "stdafx.h"
#include "Balloons.h"

#include "BalloonsDoc.h"
#include "BalloonsView.h"
#include "ExitGame.h"
#include "MainFrm.h"
#include "Inst.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBalloonsView

IMPLEMENT_DYNCREATE(CBalloonsView, CView)

BEGIN_MESSAGE_MAP(CBalloonsView, CView)
	//{{AFX_MSG_MAP(CBalloonsView)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_WM_TIMER()
	ON_COMMAND(ID_APP_EXIT, OnAppExit)
	ON_WM_DESTROY()
	ON_UPDATE_COMMAND_UI(ID_FILE_NEW, OnUpdateFileNew)
	ON_COMMAND(ID_HELP, OnHelp)
	ON_WM_PAINT()
	ON_WM_KILLFOCUS()
	ON_WM_SETFOCUS()
	ON_COMMAND(ID_CLOSE, OnClose)
	ON_UPDATE_COMMAND_UI(ID_CLOSE, OnUpdateClose)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CBalloonsView construction/destruction

CBalloonsView::CBalloonsView()
{
	m_points=m_arrownumber=ANO=0;
	m_personlocation=MPL=37;
	m_count=CNT=60;
	Bonus=FALSE;
	UDcount=UDC=0;
	IsLoaded=TRUE;
	IsFired=FALSE;
	IsFirePressed=FALSE;
	ArrowYpos=AYP=89;
	AroEnd=FALSE;
}

CBalloonsView::~CBalloonsView()
{
}


BOOL CBalloonsView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

// CBalloonsView diagnostics

#ifdef _DEBUG
void CBalloonsView::AssertValid() const
{
	CView::AssertValid();
}

void CBalloonsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBalloonsDoc* CBalloonsView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBalloonsDoc)));
	return (CBalloonsDoc*)m_pDocument;
}
#endif //_DEBUG


// CBalloonsView message handlers

void CBalloonsView::OnFileNew() 
{
//	CString str;
	AroEnd=FALSE;
	IsGameStarted=TRUE;
	IsFired=FALSE;
	IsFirePressed=FALSE;
	IsLoaded=TRUE;
	Bonus=FALSE;
	m_personlocation=MPL=37;
	ArrowYpos=AYP=89;
	m_count=CNT=60;
	UDcount=UDC=0;
	m_points=0;
	m_arrownumber=ANO=0;

	for(int j=0; j<=9; j++)
	{
		m_b[j].balloonstatus=UP;

		m_b[j].x1 = 290+(j*BW);
		m_b[j].y1 = 350;
		m_b[j].x2 = (m_b[j].x1+BW);
		m_b[j].y2 = (m_b[j].y1+BH);
	}

	SetTimer(1,52,NULL);
	SetTimer(2,150,NULL);
	SetTimer(3,82,NULL);
	SetTimer(4,30,NULL);
	SetTimer(5,12,NULL);
	SetTimer(6,130,NULL);
	SetTimer(7,25,NULL);
	SetTimer(8,65,NULL);
	SetTimer(9,100,NULL);
	SetTimer(10,5,NULL);

	for (j=0; j<=14; j++)
	{
		m_a[j].x1 = 99;
		m_a[j].y1 = 89;
		m_a[j].x2 = m_a[j].x1+AW;
		m_a[j].y2 = m_a[j].y1+AH;
		m_a[j].arrowstatus = NOTUSED;
	}

	// Setting statusbar information
	((CMainFrame*)GetParentFrame())->PaneInfo();

	GameSession();
//	docNo++;

//	str.Format(" L E V E L -- %d",docNo);
	((CMainFrame*)GetParentFrame())->PaneText(0,"   ARTIRONS");
}

void CBalloonsView::GameSession()
{
	CClientDC dc(this);
	
	m_str.Format(" Remaining:%d secs",m_count);
	((CMainFrame*)GetParentFrame())->PaneText(1,m_str);

	m_str.Format(" Arrows Left:%d",(15-m_arrownumber));
	((CMainFrame*)GetParentFrame())->PaneText(2,m_str);

	m_str.Format(" Points: %d",m_points);
	((CMainFrame*)GetParentFrame())->PaneText(3,m_str);

	((CMainFrame*)GetParentFrame())->PaneText(4," Move with Arrow keys and shoot with Ctrl");
	
	// Drawing Game Board
	dc.BitBlt(0,0,ClientRect.right,ClientRect.bottom,&m_BitmapMemdc,0,0,SRCCOPY );

	// Drawing boy bitmap
	dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobin1mask,0,0,SRCAND);
	dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobin1,0,0,SRCINVERT);

	SetTimer(25,1000,NULL);
}


void CBalloonsView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CClientDC dc(this);

	if (IsGameStarted)
	{
		UINT KeyState=(nFlags<<256)>>256; // Shifting solves repeated message problem

		switch(KeyState)	// Checking virtual scan codes for key press
		{
			case 328:	//Drawing the draging bitmap
				if (UDcount>0)
				{
					if(IsFired) 
					{					
						UDcount--;
						ArrowYpos-=23;
						dc.BitBlt(0,0,MW,380,&m_BitmapMemdc,0,0,SRCCOPY );
						dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobinshooteddragmask,0,0,SRCAND);
						dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobinshooteddrag,0,0,SRCINVERT);
					}
					else
					{
						if(IsFirePressed)
						{
							UDcount--;
							ArrowYpos-=23;
							dc.BitBlt(0,0,MW,380,&m_BitmapMemdc,0,0,SRCCOPY );
							dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobindragshootmask,0,0,SRCAND);
							dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobindragshoot,0,0,SRCINVERT);
						}
						else
						{
							UDcount--;
							ArrowYpos-=23;
							dc.BitBlt(0,0,MW,380,&m_BitmapMemdc,0,0,SRCCOPY );
							dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobindragmask,0,0,SRCAND);
							dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobindrag,0,0,SRCINVERT);
						}
					}

					m_personlocation-=23;
				}
				break;

			case 336:	// Drawing Draging bitmap at new location with key press
				if (UDcount<10)
				{
					m_personlocation+=23;
					if(IsFired) 
					{
						dc.BitBlt(0,0,MW,380,&m_BitmapMemdc,0,0,SRCCOPY );
						dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobinshooteddragmask,0,0,SRCAND);
						dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobinshooteddrag,0,0,SRCINVERT);
						UDcount++;
						ArrowYpos+=23;
					}
					else
					{
						if(IsFirePressed)
						{
							dc.BitBlt(0,0,MW,380,&m_BitmapMemdc,0,0,SRCCOPY );
							dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobindragshootmask,0,0,SRCAND);
							dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobindragshoot,0,0,SRCINVERT);
							UDcount++;
							ArrowYpos+=23;
						}
						else
						{
							dc.BitBlt(0,0,MW,380,&m_BitmapMemdc,0,0,SRCCOPY );
							dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobindragmask,0,0,SRCAND);
							dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobindrag,0,0,SRCINVERT);
							UDcount++;
							ArrowYpos+=23;
						}
					}
				}
				break;

			 case 42:
					if(m_arrownumber<16 && IsFired && !IsLoaded)
					{
						IsFired=FALSE;
						IsLoaded=TRUE;
						dc.BitBlt(0,0,MW,380,&m_BitmapMemdc,0,0,SRCCOPY );
						dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobin1mask,0,0,SRCAND);
						dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobin1,0,0,SRCINVERT);
					}
				 break;

			 case 29:	//Loading & Shooting the arrow
				 if(m_arrownumber<16 && !IsFired && !IsFirePressed && IsLoaded)
				 {
			 		m_bonusCnt=1;
					IsFirePressed=TRUE;
					dc.BitBlt(0,0,MW,380,&m_BitmapMemdc,0,0,SRCCOPY );
					dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobin2mask,0,0,SRCAND);
					dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobin2,0,0,SRCINVERT);
				 }
				 break;
		}
	}
	else
		MessageBox("c'on  man,  start  a  game  first","C'on Man",MB_OK);	
}


void CBalloonsView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CClientDC dc(this);

	UINT KeyState=(nFlags<<256)>>256;

	if (IsGameStarted)
	{
		if(KeyState==49181) // Left Ctrl Fire Key
		{
			if(m_arrownumber<16 && !IsFired && IsLoaded)
			{
				IsLoaded=FALSE;
				IsFired=TRUE;
				IsFirePressed=FALSE;
				IsKeyPressed=TRUE;
				dc.BitBlt(0,0,MW,380,&m_BitmapMemdc,0,0,SRCCOPY );
				dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobin3mask,0,0,SRCAND);
				dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobin3,0,0,SRCINVERT);

				// Getting fired arrow bitmap
				m_a[m_arrownumber].arrowstatus=ALIVE;
				m_arrownumber++;
				m_str.Format(" Arrows Left:%d",(15-m_arrownumber));
				((CMainFrame*)GetParentFrame())->PaneText(2,m_str);

				SetTimer(11,1,NULL);
			}
		}
		else
		if((UDcount>0) | (UDcount<9))
		{		// Drawing boys first bitmap at every keyup
			if(IsFired)
			{
				dc.BitBlt(0,0,MW,380,&m_BitmapMemdc,0,0,SRCCOPY );
				dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobin3mask,0,0,SRCAND);
				dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobin3,0,0,SRCINVERT);
			}
			else
			{
				if(IsFirePressed)
				{
					dc.BitBlt(0,0,MW,380,&m_BitmapMemdc,0,0,SRCCOPY );
					dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobin2mask,0,0,SRCAND);
					dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobin2,0,0,SRCINVERT);
				}
				else
				{
					dc.BitBlt(0,0,MW,380,&m_BitmapMemdc,0,0,SRCCOPY );
					dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobin1mask,0,0,SRCAND);
					dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobin1,0,0,SRCINVERT);
				}
			}
		}
	}
}


void CBalloonsView::OnTimer(UINT n) 
{
	CClientDC dc(this);

	if(IsGameStarted==TRUE)
	{
		switch(n)
		{
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
				n=n-1;

				if(m_b[n].balloonstatus==UP)
				{
					if(m_b[n].y1<-BH)
					{
						m_b[n].balloonstatus=NOWHERE;
					}
					else
					{
						dc.BitBlt(m_b[n].x1,m_b[n].y1,BW,(BH),&m_BitmapMemdc,m_b[n].x1,m_b[n].y1,SRCCOPY );
						dc.BitBlt(m_b[n].x1,m_b[n].y1,BW,(BH),&m_memdcballoonmask,0,0,SRCAND);
						dc.BitBlt(m_b[n].x1,m_b[n].y1,BW,(BH),&m_b[n].balloonmemdc,0,0,SRCINVERT);
				
						if((m_count%15)==0 && m_bonusCnt==1)
						{
							Bonus=TRUE;
							dc.BitBlt((m_b[n].x1),m_b[n].y1,BW,(BH),&m_BitmapMemdc,(m_b[n].x1),m_b[n].y1,SRCCOPY);
							dc.BitBlt((m_b[n].x1),m_b[n].y1,BW,(BH),&m_memdcballoonmask,0,0,SRCAND);
							dc.BitBlt((m_b[n].x1),m_b[n].y1,BW,(BH),&m_bonus_1_memdc,0,0,SRCINVERT);				
						}			
						m_b[n].y1=m_b[n].y1-BS;
						m_b[n].y2=m_b[n].y2-BS;
					}	
				}

				if(m_b[n].balloonstatus==DOWN)
				{
					if(m_b[n].y1>(350+BH))
					{
						m_b[n].balloonstatus=NOWHERE;
					}
					else
					{
						dc.BitBlt((m_b[n].x1),(m_b[n].y1-5),BW,(BH),&m_BitmapMemdc,(m_b[n].x1),(m_b[n].y1-5),SRCCOPY);
						dc.BitBlt((m_b[n].x1),(m_b[n].y1),BW,(BH),&m_deflatememdc,0,0,SRCAND);
						dc.BitBlt((m_b[n].x1),(m_b[n].y1),BW,(BH),&m_b[n].burstballoonmemdc,0,0,SRCINVERT);			
						m_b[n].y1=m_b[n].y1+BS;
						m_b[n].y2=m_b[n].y2+BS;
					}
				}
				if(m_b[n].balloonstatus==NOWHERE)
				{
					m_b[n].x1 = 290+(n*BW);
					m_b[n].y1 = 350;
					m_b[n].x2 = (m_b[n].x1+BW);
					m_b[n].y2 = (m_b[n].y1+BH);
					m_b[n].balloonstatus=UP;
				}
				break;

			case 25:
				m_count--;
				m_str.Format(" Remaining:%d secs",m_count);
				((CMainFrame*)GetParentFrame())->PaneText(1,m_str);

				if(m_count==0)
				{
					MessageBox("G a m e   O v e r (time's up)","C'on man",MB_OK);					
					OnClose();
				}
				break;

		//	default:
			case 11:

				if(AroEnd)
				{
					for(;m_a[m_arrownumber-1].x1<1000;)
					{					
						dc.BitBlt((m_a[m_arrownumber-1].x1),ArrowYpos,(AW),AH,&m_a[m_arrownumber-1].arrowbgmemdc,0,0,SRCAND);
						dc.BitBlt((m_a[m_arrownumber-1].x1),ArrowYpos,(AW),AH,&m_a[m_arrownumber-1].arrowmemdc,0,0,SRCINVERT);
						Sleep(18);
						dc.BitBlt(m_a[m_arrownumber-1].x1,ArrowYpos,(AW),AH,&m_BitmapMemdc,m_a[m_arrownumber-1].x1,ArrowYpos,SRCCOPY);

						m_a[m_arrownumber-1].x1=m_a[m_arrownumber-1].x1+AS;
						m_a[m_arrownumber-1].x2=m_a[m_arrownumber-1].x2+AS;
			
						if(m_a[m_arrownumber-1].x1>600)
						{
							KillTimer(11);
							IsKeyPressed=FALSE;
							m_a[m_arrownumber-1].arrowstatus=DEAD;
						}
					}
					MessageBox("G a m e   O v e r (arrows finished)","C'on man",MB_OK);
					OnClose();
				}
				else
				if(m_a[m_arrownumber-1].arrowstatus==ALIVE)
				{
					dc.BitBlt((m_a[m_arrownumber-1].x1),ArrowYpos,(AW),AH,&m_a[m_arrownumber-1].arrowbgmemdc,0,0,SRCAND);
					dc.BitBlt((m_a[m_arrownumber-1].x1),ArrowYpos,(AW),AH,&m_a[m_arrownumber-1].arrowmemdc,0,0,SRCINVERT);
					Sleep(18);
					dc.BitBlt(m_a[m_arrownumber-1].x1,ArrowYpos,(AW),AH,&m_BitmapMemdc,m_a[m_arrownumber-1].x1,ArrowYpos,SRCCOPY);

					m_a[m_arrownumber-1].x1=m_a[m_arrownumber-1].x1+AS;
					m_a[m_arrownumber-1].x2=m_a[m_arrownumber-1].x2+AS;

					if(m_a[m_arrownumber-1].x1>600)
					{
						KillTimer(11);
						IsKeyPressed=FALSE;
						m_a[m_arrownumber-1].arrowstatus=DEAD;
					}

					for(int j=0; j<9; j++)
					{
						if((m_a[m_arrownumber-1].x2)>=(m_b[j].x1) && (m_a[m_arrownumber-1].x2)<=(m_b[j].x2) && (ArrowYpos)>=(m_b[j].y1) && (ArrowYpos)<=(m_b[j].y2))
						{
							::MessageBeep(MB_ICONEXCLAMATION);
							m_b[j].balloonstatus=DOWN;
							if(m_b[j].x1>289 && m_b[j].x1<291)
								m_points+=3;
							if(m_b[j].x1>320 && m_b[j].x1<322)
								m_points+=5;
							if(m_b[j].x1>351 && m_b[j].x1<353)
								m_points+=7;
							if(m_b[j].x1>382 && m_b[j].x1<384)
								m_points+=9;
							if(m_b[j].x1>413 && m_b[j].x1<415)
								m_points+=11;
							if(m_b[j].x1>444 && m_b[j].x1<446)
								m_points+=13;
							if(m_b[j].x1>475 && m_b[j].x1<477)
								m_points+=15;
							if(m_b[j].x1>506 && m_b[j].x1<508)
								m_points+=17;
							if(m_b[j].x1>537 && m_b[j].x1<539)
								m_points+=19;
							if(m_b[j].x1>568 && m_b[j].x1<570)
								m_points+=21;
							if(Bonus==TRUE && m_b[j].x1>289 && m_b[j].x1<415)
								m_points+=25;
							if(Bonus==TRUE && m_b[j].x1>413 && m_b[j].x1<570)
								m_points+=50;
							m_str.Format(" Points: %d",m_points);
							((CMainFrame*)GetParentFrame())->PaneText(3,m_str);

							if((m_arrownumber)>14)
								AroEnd=TRUE;
						}
					}
				}
				break;
			}
	  }
}


void CBalloonsView::OnAppExit() 
{
	if(IsGameStarted)
	{
		ANO=m_arrownumber;
		CNT=m_count;
		AYP=ArrowYpos;
		UDC=UDcount;
		MPL=m_personlocation;

		for (int g=1; g<=10; g++)
		{
			KillTimer(g);
			for(int aro=0; aro<=14; aro++)
			{
				if(m_a[aro].arrowstatus==ALIVE)
				{
					KillTimer(11);
					m_a[aro].arrowstatus=DEAD;
				}
			}
		}
		KillTimer(25);
		
		ExitGame egame;
		if(egame.DoModal()==IDOK)
			PostQuitMessage(0);				
		else
		{
			m_arrownumber=ANO;
			m_count=CNT;
			ArrowYpos=ANO;
			UDcount=UDC;
			m_personlocation=MPL;
			SetTimer(1,52,NULL);
			SetTimer(2,150,NULL);
			SetTimer(3,82,NULL);
			SetTimer(4,30,NULL);
			SetTimer(5,12,NULL);
			SetTimer(6,130,NULL);
			SetTimer(7,25,NULL);
			SetTimer(8,65,NULL);
			SetTimer(9,100,NULL);
			SetTimer(10,5,NULL);
			SetTimer(25,1000,NULL);
		}
	}
	else
		PostQuitMessage(0);		
}


void CBalloonsView::OnDestroy() 
{
	if(IsGameStarted)
	{
		for (int g=1; g<=10; g++)
		{
			KillTimer(g);
			for(int aro=0; aro<=14; aro++)
			{
				if(m_a[aro].arrowstatus==ALIVE)
				{
					KillTimer(11);
					m_a[aro].arrowstatus=DEAD;
				}
			}
		}
		KillTimer(25);
		PostQuitMessage(0);
	}
	else
		PostQuitMessage(0);	
}


void CBalloonsView::GameEnd()
{
	CClientDC dc(this);

	if(IsGameStarted)
	{
		for (int g=1; g<=10; g++)
		{
			KillTimer(g);
			for(int aro=0; aro<=14; aro++)
			{
				if(m_a[aro].arrowstatus==ALIVE)
				{
					KillTimer(11);
					m_a[aro].arrowstatus=DEAD;
				}
			}
		}
		IsGameStarted=FALSE;
		KillTimer(25);
	}
}


void CBalloonsView::OnUpdateFileNew(CCmdUI* pCmdUI) 
{
	if(IsGameStarted)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);	
}


void CBalloonsView::OnHelp() 
{
	Inst inst;
	inst.DoModal();
}


void CBalloonsView::OnDraw(CDC* pDC) 
{
}


void CBalloonsView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	if(IsGameStarted)
	{
		dc.BitBlt(0,0,ClientRect.right,ClientRect.bottom,&m_BitmapMemdc,0,0,SRCCOPY );

		if(IsFired)
		{
			dc.BitBlt(0,0,MW,380,&m_BitmapMemdc,0,0,SRCCOPY );
			dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobin3mask,0,0,SRCAND);
			dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobin3,0,0,SRCINVERT);
		}
		else
		{
			dc.BitBlt(0,0,MW,380,&m_BitmapMemdc,0,0,SRCCOPY );
			dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobin1mask,0,0,SRCAND);
			dc.BitBlt(10,m_personlocation,MW,MH,&m_memdcrobin1,0,0,SRCINVERT);
		}
	}

	if(!IsGameStarted)		
	{
		dc.BitBlt(0,0,600,450,&m_ArtironsMemdc,0,0,SRCCOPY);
	}
}

void CBalloonsView::OnInitialUpdate() 
{
	CClientDC dc(this);

	m_robin1mask.LoadBitmap(IDB_BITMAP31);
	m_memdcrobin1mask.CreateCompatibleDC(&dc);
	m_memdcrobin1mask.SelectObject(m_robin1mask);

	m_robin2mask.LoadBitmap(IDB_BITMAP35);
	m_memdcrobin2mask.CreateCompatibleDC(&dc);
	m_memdcrobin2mask.SelectObject(m_robin2mask);

	m_robin3mask.LoadBitmap(IDB_BITMAP33);
	m_memdcrobin3mask.CreateCompatibleDC(&dc);
	m_memdcrobin3mask.SelectObject(m_robin3mask);

	m_robindragmask.LoadBitmap(IDB_BITMAP30);
	m_memdcrobindragmask.CreateCompatibleDC(&dc);
	m_memdcrobindragmask.SelectObject(m_robindragmask);

	m_robindragshootmask.LoadBitmap(IDB_BITMAP34);
	m_memdcrobindragshootmask.CreateCompatibleDC(&dc);
	m_memdcrobindragshootmask.SelectObject(m_robindragshootmask);

	m_robinshooteddragmask.LoadBitmap(IDB_BITMAP32);
	m_memdcrobinshooteddragmask.CreateCompatibleDC(&dc);
	m_memdcrobinshooteddragmask.SelectObject(m_robinshooteddragmask);

	m_balloonmask.LoadBitmap(IDB_BITMAP37);
	m_memdcballoonmask.CreateCompatibleDC(&dc);
	m_memdcballoonmask.SelectObject(m_balloonmask);
	

	m_deflatebitmap.LoadBitmap(IDB_BITMAP38);
	m_deflatememdc.CreateCompatibleDC(&dc);
	m_deflatememdc.SelectObject(m_deflatebitmap);

	// Getting colored bitmap(s) of boy  /////////////////////////
	m_robin1.LoadBitmap(IDB_BITMAP2);
	m_memdcrobin1.CreateCompatibleDC(&dc);
	m_memdcrobin1.SelectObject(m_robin1);

	m_robin2.LoadBitmap(IDB_BITMAP6);
	m_memdcrobin2.CreateCompatibleDC(&dc);
	m_memdcrobin2.SelectObject(m_robin2);

	m_robin3.LoadBitmap(IDB_BITMAP4);
	m_memdcrobin3.CreateCompatibleDC(&dc);
	m_memdcrobin3.SelectObject(m_robin3);

	m_robindrag.LoadBitmap(IDB_BITMAP1);
	m_memdcrobindrag.CreateCompatibleDC(&dc);
	m_memdcrobindrag.SelectObject(m_robindrag);

	m_robindragshoot.LoadBitmap(IDB_BITMAP5);
	m_memdcrobindragshoot.CreateCompatibleDC(&dc);
	m_memdcrobindragshoot.SelectObject(m_robindragshoot);

	m_robinshooteddrag.LoadBitmap(IDB_BITMAP3);
	m_memdcrobinshooteddrag.CreateCompatibleDC(&dc);
	m_memdcrobinshooteddrag.SelectObject(m_robinshooteddrag);

	m_bonus_1_bitmap.LoadBitmap(IDB_BITMAP39);
	m_bonus_1_memdc.CreateCompatibleDC(&dc);
	m_bonus_1_memdc.SelectObject(m_bonus_1_bitmap);

	for (int g=0; g<=9; g++)
	{
		// Getting 10 inflated balloons bitmap
		m_b[g].balloonbitmap.LoadBitmap(IDB_BITMAP8+g);
		m_b[g].balloonmemdc.CreateCompatibleDC(&dc);
		m_b[g].balloonmemdc.SelectObject(m_b[g].balloonbitmap);

		// Getting 10 deflated balloons bitmap
		m_b[g].burstballoonbitmap.LoadBitmap(IDB_BITMAP18+g);
		m_b[g].burstballoonmemdc.CreateCompatibleDC(&dc);
		m_b[g].burstballoonmemdc.SelectObject(m_b[g].burstballoonbitmap);
	}

	for(g=0; g<=14; g++)
	{
		// Getting arrow bitmap
		m_a[g].arrowbitmap.LoadBitmap(IDB_BITMAP7);
		m_a[g].arrowmemdc.CreateCompatibleDC(&dc);
		m_a[g].arrowmemdc.SelectObject(m_a[g].arrowbitmap);

		m_a[g].arrowbgbitmap.LoadBitmap(IDB_BITMAP36);
		m_a[g].arrowbgmemdc.CreateCompatibleDC(&dc);
		m_a[g].arrowbgmemdc.SelectObject(m_a[g].arrowbgbitmap);
	}

	m_ArtironsBM.LoadBitmap (IDB_BITMAP41);
	m_ArtironsMemdc.CreateCompatibleDC(&dc);
	m_ArtironsMemdc.SelectObject(&m_ArtironsBM);
	
	// Drawing Artirons first screen
//	dc.SetStretchBltMode(COLORONCOLOR);
//	dc.StretchBlt(0,0,ClientRect.right,ClientRect.bottom,&m_ArtironsMemdc,0,0,m_BitmapWidth,m_BitmapHeight,SRCCOPY ); 

	((CMainFrame*)GetParentFrame())->PaneInfo();
	((CMainFrame*)GetParentFrame())->ErasePaneInfo();
	// Setting game start to FALSE
	IsGameStarted=FALSE;

	// Getting Game Board
	m_Bitmap.LoadBitmap (IDB_BITMAP29);
	m_Bitmap.GetObject (sizeof (BM), &BM);
	m_BitmapMemdc.CreateCompatibleDC(&dc);
	m_BitmapMemdc.SelectObject(&m_Bitmap);
	m_BitmapWidth = BM.bmWidth;
	m_BitmapHeight = BM.bmHeight;
	GetClientRect(&ClientRect);	
}


void CBalloonsView::OnKillFocus(CWnd* pNewWnd) 
{
	if(IsGameStarted)
	{
		ANO=m_arrownumber+1;
		CNT=m_count;
		AYP=ArrowYpos;
		UDC=UDcount;
		MPL=m_personlocation;
		for (int g=1; g<=10; g++)
		{
			KillTimer(g);
			for(int aro=0; aro<=14; aro++)
			{
				if(m_a[aro].arrowstatus==ALIVE)
				{
					KillTimer(11);
					m_a[aro].arrowstatus=DEAD;
				}
			}
		}
		KillTimer(25);
	}
}

void CBalloonsView::OnSetFocus(CWnd* pOldWnd) 
{
	if(IsGameStarted)
	{
		m_arrownumber=ANO;
		m_count=CNT;
		ArrowYpos=AYP;
		UDcount=UDC;
		m_personlocation=MPL;
		SetTimer(1,52,NULL);
		SetTimer(2,150,NULL);
		SetTimer(3,82,NULL);
		SetTimer(4,30,NULL);
		SetTimer(5,12,NULL);
		SetTimer(6,130,NULL);
		SetTimer(7,25,NULL);
		SetTimer(8,65,NULL);
		SetTimer(9,100,NULL);
		SetTimer(10,5,NULL);
		SetTimer(25,1000,NULL);	
	}
}

void CBalloonsView::OnClose() 
{
	CClientDC dc(this);

	IsGameStarted=FALSE;
	GameEnd();
	((CMainFrame*)GetParentFrame())->ErasePaneInfo();
	dc.BitBlt(0,0,600,450,&m_ArtironsMemdc,0,0,SRCCOPY);
}

void CBalloonsView::OnUpdateClose(CCmdUI* pCmdUI) 
{
	if(IsGameStarted)	
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

