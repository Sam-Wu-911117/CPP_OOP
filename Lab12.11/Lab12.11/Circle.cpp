#include<iostream> 
#include<stdexcept> 
#include"Circle.h" 
using namespace std;
#define MY_PI 3.14159265358979323846
Circle::Circle(double r, double  x, double y)
	:TwoDimensionalShape(x, y)
{
	if (r >= 0.0)
		radius = r;
	else
		throw invalid_argument("Radius must be >=0.0");
}
double Circle::getRadius()const
{
	return radius;
}

double Circle::getArea()const
{
	return radius * radius * MY_PI;
}
void Circle::print()const
{
	cout << "Circle with radius" << radius << "; center at (" << xCenter << "," << yCenter << ")";
}