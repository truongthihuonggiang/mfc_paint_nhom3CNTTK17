#include "stdafx.h"
#include "Htron.h"

Htron::Htron(CPoint p1, CPoint p2)
{
	point1.x = p1.x;
	point1.y = p1.y;
	point2.x = p2.x;
	point2.y = p2.y;
	x = (p1.x + p2.x) / 2;
	y = (p1.y + p2.y) / 2;
	r = (sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y))) / 2;
}
float Htron::dientich()
{
	int kq = 0;
	kq = 3.14*r*r;
	return kq;
}
float Htron::chuvi()
{
	int kq = 0;
	kq = 3.14 * 2 * r;
	return kq;
}
void Htron::ve(CClientDC *pDC)
{
	pDC->Ellipse(point1.x, point1.y, point2.x, point2.y);
	CString dt, cv;
	dt.Format(_T("%f"), dientich());
	pDC->TextOutW(430, 10, dt);
	cv.Format(_T("%f"), chuvi());
	pDC->TextOutW(430, 25, cv);
}
int Htron::tronghinh(CPoint p)
{
	int kq = 0;
	if (p.x >= point1.x && p.x <= point2.x && p.y >= point1.y && p.y <= point2.y)
		kq = 1;
	return kq;
}
void Htron::xemlai(CClientDC *pDC)
{
	CString dt, cv;
	dt.Format(_T("%f"), dientich());
	pDC->TextOutW(430, 10, dt);
	cv.Format(_T("%f"), chuvi());
	pDC->TextOutW(430, 25, cv);
}
void Htron::maudo(CClientDC *pDC)
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
void Htron::den(CClientDC *pDC)
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
void Htron::trang(CClientDC *pDC)
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
Htron::Htron()
{
}


Htron::~Htron()
{
}
