#pragma once
#include "PublicHinh.h"
class Htron :
	public PublicHinh
{
private:
	int x, y;
	int r;
public:
	Htron(CPoint p1, CPoint p2);
	void ve(CClientDC *pDC);
	float dientich();
	float chuvi();
	int tronghinh(CPoint p);
	void xemlai(CClientDC *pDC);
	void maudo(CClientDC *pDC);
	void trang(CClientDC *pDC);
	void den(CClientDC *pDC);
	Htron();
	~Htron();
};

