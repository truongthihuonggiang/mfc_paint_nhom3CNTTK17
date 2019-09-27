
// public1View.cpp : implementation of the Cpublic1View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "public1.h"
#endif

#include "public1Doc.h"
#include "public1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cpublic1View

IMPLEMENT_DYNCREATE(Cpublic1View, CView)

BEGIN_MESSAGE_MAP(Cpublic1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Cpublic1View construction/destruction

Cpublic1View::Cpublic1View() noexcept
{
	// TODO: add construction code here

	//thietlapnut
	hinhcn.thietlap(0, 0, 80, 50);
	hinhcn.chu = CString("HCN");
	hinhtron.thietlap(81, 0, 161, 50);
	hinhtron.chu = CString("HTron");
	hinhtg.thietlap(162, 0, 242, 50);
	hinhtg.chu = CString("TamGiac");
	hxemlai.thietlap(243, 0, 323, 50);
	hxemlai.chu = CString("XemLai");
	xoa.thietlap(314, 0, 394, 50);
	xoa.chu = CString("Xoa");
	//mau
	maudo.thietlap(550, 10, 580, 40);
	trang.thietlap(600, 10, 630, 40);
	den.thietlap(650, 10, 680, 40);
	menu.thietlap(0, 0, 750, 50);


	n = 0;
	control = 0;
}

Cpublic1View::~Cpublic1View()
{
}

BOOL Cpublic1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cpublic1View drawing

void Cpublic1View::OnDraw(CDC* /*pDC*/)
{
	Cpublic1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC pDC(this);
	CPen *pen;
	CBrush *mau;
	//
	CPen *pen1;
	pen1 = new CPen(PS_SOLID, 0, RGB(0, 225, 225));
	pen = pDC.SelectObject(pen1);
	menu.ve(&pDC);
	hinhcn.ve(&pDC);
	hinhtron.ve(&pDC);
	hinhtg.ve(&pDC);
	hxemlai.ve(&pDC);
	xoa.ve(&pDC);
	maudo.maudo(&pDC);
	maudo.ve(&pDC);
	trang.trang(&pDC);
	trang.ve(&pDC);
	den.den(&pDC);
	den.ve(&pDC);
	// TODO: add draw code for native data here
}


// Cpublic1View printing

BOOL Cpublic1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cpublic1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cpublic1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// Cpublic1View diagnostics

#ifdef _DEBUG
void Cpublic1View::AssertValid() const
{
	CView::AssertValid();
}

void Cpublic1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cpublic1Doc* Cpublic1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cpublic1Doc)));
	return (Cpublic1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cpublic1View message handlers


void Cpublic1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	p1.x = point.x;
	p1.y = point.y;
	p2.x = point.x;
	p2.y = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void Cpublic1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC pDC(this);
	CPen *pen;
	CBrush *mau;
	p2.x = point.x;
	p2.y = point.y;

	if (hinhcn.tronghinh(point) == 1)
	{
		control = 1;
		//mauchuadoi
		hinhcn.maucu(&pDC);
		hinhcn.ve(&pDC);
		//maudoi
		hinhtg.maumoi(&pDC);
		hinhtg.ve(&pDC);
		hinhtron.ve(&pDC);
		hxemlai.ve(&pDC);
		xoa.ve(&pDC);
	}
	else
		if (hinhtron.tronghinh(point) == 1)
		{
			control = 2;
	
			hinhtron.maucu(&pDC);
			hinhtron.ve(&pDC);
			hinhtg.maumoi(&pDC);
			hinhtg.ve(&pDC);
			hinhcn.ve(&pDC);
			hxemlai.ve(&pDC);
			xoa.ve(&pDC);

		}
		else
			if (hinhtg.tronghinh(point) == 1)
			{
				control = 3;
				hinhtg.maucu(&pDC);
				hinhtg.ve(&pDC);
				hinhcn.maumoi(&pDC);
				hinhcn.ve(&pDC);
				hxemlai.ve(&pDC);
				hinhtron.ve(&pDC);
			}
			else
				if (hxemlai.tronghinh(point) == 1)
				{
					control = 4;
					hxemlai.maucu(&pDC);

					hxemlai.ve(&pDC);
					hinhcn.maumoi(&pDC);
					hinhcn.ve(&pDC);
					hinhtron.ve(&pDC);
					hinhtg.ve(&pDC);
					xoa.ve(&pDC);
				}
				else
				if (xoa.tronghinh(point) == 1)
				{
					control = 5;
					xoa.maucu(&pDC);
					xoa.ve(&pDC);
					hinhcn.maumoi(&pDC);
					hinhcn.ve(&pDC);
					hinhtron.ve(&pDC);
					hinhtg.ve(&pDC);
					hxemlai.ve(&pDC);
				 }
				else//maudo.thietlap(500, 20, 530, 50);
					
					if (maudo.tronghinh(point) == 1)
					{
						control = 6;
						

						hinhcn.maumoi(&pDC);
						xoa.ve(&pDC);
						hinhcn.ve(&pDC);
						hinhtron.ve(&pDC);
						hinhtg.ve(&pDC);
						hxemlai.ve(&pDC);
					}
					else
						//trang.thietlap(550, 20, 580, 50);
						if (trang.tronghinh(point) == 1)
						{
							control = 7;
							
							hinhcn.maumoi(&pDC);
							xoa.ve(&pDC);
							hinhcn.ve(&pDC);
							hinhtron.ve(&pDC);
							hinhtg.ve(&pDC);
							hxemlai.ve(&pDC);
						}
						else
							//den.thietlap(600, 20, 630, 50);
							if (den.tronghinh(point) == 1)
							{
								control = 8;
								
								hinhcn.maumoi(&pDC);
								xoa.ve(&pDC);
								hinhcn.ve(&pDC);
								hinhtron.ve(&pDC);
								hinhtg.ve(&pDC);
								hxemlai.ve(&pDC);
							}
						
				else
					if (control == 1 && p1.y > 50 && p2.y > 50)
					{
						//hcn
						ph[n] = new HCN(p1, p2);
						ph[n]->ve(&pDC);
						n++;
						
					}
					else
						if (control == 2 && p1.y > 50 && p2.y > 50)
						{
							//tron
							ph[n] = new Htron(p1, p2);
							ph[n]->ve(&pDC);
							n++;
						}
						else
							if (control == 3 && p1.y > 50 && p2.y > 50)
							{
								//tamgiac
								ph[n] = new Tamgiac(p1,p2);
								ph[n]->ve(&pDC);
								n++;
							}
							else
							if(control==4)
							{
								int i;
								for (i = 0; i < n; i++)
								{
									if (ph[i]->tronghinh(p1) == 1)
									{
										ph[i]->xemlai(&pDC);
									}
								}
							}
							else
							
								if (control == 5)
								{
									int i;
									for (i = 0; i < n; i++)
									{
										if (ph[i]->tronghinh(p1) == 1)
										{
											ph[i]->xoa(&pDC);
											
										}
									}
								}
							
							else
								if (control == 6)
								{
									int i;
									for (i = 0; i < n; i++)
									{
										if (ph[i]->tronghinh(p1) == 1)
										{
											ph[i]->maudo(&pDC);
											ph[i]->ve(&pDC);
										}
									}
								}
								else
								
									if (control == 7)
									{
										int i;
										for (i = 0; i < n; i++)
										{
											if (ph[i]->tronghinh(p1) == 1)
											{
												ph[i]->trang(&pDC);
												ph[i]->ve(&pDC);
											}
										}
									}
									else
									{
										
											for (int i = 0; i < n; i++)
											{
												if (ph[i]->tronghinh(p1) == 1)
												{
													ph[i]->den(&pDC);
													ph[i]->ve(&pDC);
													
												}
											}
										
									}
	CView::OnLButtonUp(nFlags, point);
}
