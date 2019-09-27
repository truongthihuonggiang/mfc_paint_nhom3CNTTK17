#pragma once
#include "PublicHinh.h"
class HCN :
	public PublicHinh
{
private:
	int x1, y1, x2, y2;
public:
	HCN(CPoint p1, CPoint p2);
	HCN(int x1, int y1, int x2, int y2);
	void thietlap(int x1, int y1, int x2, int y2);
	CPoint getA();
	CPoint getC();
	int  tronghinh(CPoint p);
	void ve(CClientDC *pDC);
	float dientich();
	float chuvi();
	void xoa(CClientDC *pDC);
	void xemlai(CClientDC *pDC);
	void maucu(CClientDC *pDC);
	void maumoi(CClientDC *pDC);
	void maudo(CClientDC *pDC);
	void trang(CClientDC *pDC);
	void den(CClientDC *pDC);
	HCN();
	~HCN();
};

