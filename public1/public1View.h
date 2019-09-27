
// public1View.h : interface of the Cpublic1View class
//

#pragma once
#include"HCN.h"
#include"NutBam.h"
#include"Htron.h"
#include"Tamgiac.h"

class Cpublic1View : public CView
{
protected: // create from serialization only
	Cpublic1View() noexcept;
	DECLARE_DYNCREATE(Cpublic1View)

// Attributes
public:
	Cpublic1Doc* GetDocument() const;

// Operations
public:
	NutBam hinhcn, menu, hinhtron, hinhtg, hxemlai, maudo, trang, den, xoa;
	PublicHinh *ph[20];
	int n;
	int control;
	CPoint p1, p2, p3, p4;
	int xn, yn;
	int x1, y1, x2, y2;
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~Cpublic1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in public1View.cpp
inline Cpublic1Doc* Cpublic1View::GetDocument() const
   { return reinterpret_cast<Cpublic1Doc*>(m_pDocument); }
#endif

