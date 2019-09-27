#include "stdafx.h"
#include "HCN.h"

HCN::HCN(CPoint p1, CPoint p2)
{
	point1.x = p1.x;
	point1.y = p1.y;
	point2.x = p1.x;
	point2.y = p1.y;
	x1 = p1.x;
	x2 = p2.x;
	y1 = p1.y;
	y2 = p2.y;
}
HCN::HCN(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}
void HCN::thietlap(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}

CPoint HCN::getA()
{
	return CPoint(x1, y1);
}
CPoint HCN::getC()
{
	return CPoint(x2, y2);
}
int HCN::tronghinh(CPoint p)
{
	int kq = 0;
	if (p.x >= x1 && p.x <= x2 && p.y >= y1 && p.y <= y2)
		kq = 1;
	return kq;
}
float HCN::dientich()
{
	float kq = 0;

	kq = (x2 - x1)*(y2 - y1);

	return kq;

}
float HCN::chuvi()
{
	float kq = 0;
	if (x2 > x1&&y2 > y1)
	{
		kq = ((x2 - x1) + (y2 - y1)) * 2;
	}
	if (x2 > x1&&y2 < y1)
	{
		kq = ((x2 - x1) + (y1 - y2)) * 2;
	}
	if (x2 < x1&&y2 < y1)
	{
		kq = ((x1 - x2) + (y1 - y2)) * 2;
	}
	if (x2<x1&&y2>y1)
	{
		kq = ((x1 - x2) + (y2 - y1)) * 2;
	}
	return kq;

}
void HCN::ve(CClientDC *pDC)
{
	pDC->Rectangle(x1, y1, x2, y2);
	CString str, cv;
	str.Format(_T("%f"), dientich());
	pDC->TextOutW(430, 10, str);
	cv.Format(_T("%f"), chuvi());
	pDC->TextOutW(430, 25, cv);
}
void HCN::xemlai(CClientDC *pDC)
{
	CString str, cv;
	str.Format(_T("%f"), dientich());
	pDC->TextOutW(430, 10, str);
	cv.Format(_T("%f"), chuvi());
	pDC->TextOutW(430, 25, cv);
}
void HCN::maucu(CClientDC *pDC)
{
	CPen *pen;
	CBrush *mau;
	CPen *pen1;
	pen1 = new CPen(PS_SOLID, 0, RGB(225, 225, 225));
	pen = pDC->SelectObject(pen1);
	CBrush *mau1;
	mau1 = new CBrush(RGB(180, 121, 12));
	mau = pDC->SelectObject(mau1);
}
void HCN::maumoi(CClientDC *pDC)
{
	CPen *pen;
	CBrush *mau;
	CPen *pen1b;
	pen1b = new CPen(PS_SOLID, 0, RGB(0, 255, 255));
	pen = pDC->SelectObject(pen1b);
	CBrush *mau1b;
	mau1b = new CBrush(RGB(255, 255, 255));
	mau = pDC->SelectObject(mau1b);
}
void HCN::maudo(CClientDC *pDC)
{
	int control = 5;
	CBrush *mau;
	CPen *pen;
	CPen *pen1;
	pen1 = new CPen(PS_SOLID, 0, RGB(0, 0, 0));
	pen = pDC->SelectObject(pen1);
	CBrush *mau1;
	mau1 = new CBrush(RGB(220, 20, 60));
	mau = pDC->SelectObject(mau1);
}
void HCN::den(CClientDC *pDC)
{
	int control = 7;
	CBrush *mau;
	CPen *pen;
	CPen *pen1;
	pen1 = new CPen(PS_SOLID, 0, RGB(0, 0, 0));
	pen = pDC->SelectObject(pen1);
	CBrush *mau1;
	mau1 = new CBrush(RGB(0, 0, 0));
	mau = pDC->SelectObject(mau1);
}
void HCN::trang(CClientDC *pDC)
{
	int control = 6;
	CBrush *mau;
	CPen *pen;
	CPen *pen1;
	pen1 = new CPen(PS_SOLID, 0, RGB(0, 0, 0));
	pen = pDC->SelectObject(pen1);
	CBrush *mau1;
	mau1 = new CBrush(RGB(255, 255, 255));
	mau = pDC->SelectObject(mau1);
}
void HCN::xoa(CClientDC *pDC)
{

}
HCN::HCN()
{
}


HCN::~HCN()
{
}
