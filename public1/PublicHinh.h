#pragma once
class PublicHinh
{
public:
	CPoint point1, point2;
	virtual void ve(CClientDC *pDC);
	virtual float dientich();
	virtual float chuvi();
	virtual int tronghinh(CPoint p1);
	virtual void xemlai(CClientDC *pDC);
	virtual void xoa(CClientDC *pDC);
	virtual void maucu(CClientDC *pDC);
	virtual void maumoi(CClientDC *pDC);
	virtual void maudo(CClientDC *pDC);
	virtual void trang(CClientDC *pDC);
	virtual void den(CClientDC *pDC);
	PublicHinh();
	~PublicHinh();
};

