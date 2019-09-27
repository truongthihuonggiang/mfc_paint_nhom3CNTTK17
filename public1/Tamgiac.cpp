#include "stdafx.h"
#include "Tamgiac.h"

Tamgiac::Tamgiac(CPoint p1, CPoint p2)
{
	point1.x = p1.x;
	point1.y = p1.y;
	point2.x = p2.x;
	point2.y = p2.y;
	x1 = (p1.x + p2.x) / 2;
	y1 = p1.y;
	x2 = p1.x;
	y2 = p2.y;
	x3 = p2.x;
	y3 = p2.y;
}
Tamgiac::Tamgiac(int mx1, int my1, int mx2, int my2, int mx3, int my3)
{
	x1 = mx1; y1 = my1; x2 = mx2; y2 = my2; x3 = mx3; y3 = my3;
}
void Tamgiac::thietlap(int mx1, int my1, int mx2, int my2, int mx3, int my3)
{
	x1 = mx1; y1 = my1; x2 = mx2; y2 = my2; x3 = mx3; y3 = my3;
}
int Tamgiac::tronghinh(CPoint p)
{
	Tamgiac hinhtg1, hinhtg2, hinhtg3;
	int kq = 0;
	hinhtg1.thietlap(x1, y1, x2, y2, p.x, p.y);
	hinhtg2.thietlap(x2, y2, x3, y3, p.x, p.y);
	hinhtg3.thietlap(x3, y3, x1, y1, p.x, p.y);
	if (hinhtg1.dientich() + hinhtg2.dientich() + hinhtg3.dientich() == dientich())
		kq = 1;
	return kq;
}
CPoint Tamgiac::getA()
{
	return CPoint(x1, y1);
}
CPoint Tamgiac::getB()
{
	return CPoint(x2, y2);
}
CPoint Tamgiac::getC()
{
	return CPoint(x3, y3);
}
void Tamgiac::ve(CClientDC *pDC)
{
	pDC->MoveTo(x1, y1);
	pDC->LineTo(x2, y2);
	pDC->LineTo(x3, y3);
	pDC->LineTo(x1, y1);
	CString str, cv;
	str.Format(_T("%f"), dientich());
	pDC->TextOutW(430, 10, str);
	cv.Format(_T("%f"), chuvi());
	pDC->TextOutW(430, 25, cv);
}
float Tamgiac::dientich()
{
	float kq = 0;
	kq = (float)(0.5)*(abs)((x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1));
	return kq;
}
float Tamgiac::chuvi()
{
	float kq;
	kq = (sqrt((x2 - x1)*(x2 - x1)) + sqrt((y2 - y1)*(y2 - y1))) + (sqrt((x3 - x2)*(x3 - x2)) + sqrt((y3 - y2)*(y3 - y2))) + (sqrt((x3 - x1)*(x3 - x1)) + sqrt((y3 - y1)*(y3 - y1)));
	return kq;
}
void Tamgiac::xemlai(CClientDC *pDC)
{
	CString str, cv;
	str.Format(_T("%f"), dientich());
	pDC->TextOutW(430, 10, str);
	cv.Format(_T("%f"), chuvi());
	pDC->TextOutW(430, 25, cv);
}
Tamgiac::Tamgiac()
{
}


Tamgiac::~Tamgiac()
{
}
