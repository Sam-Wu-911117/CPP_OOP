#include<iostream> 
#include<stdexcept> 
#include"Sphere.h" 
using namespace std;
#define MY_PI 3.14159265358979323846
Sphere::Sphere(double r, double  x, double y)
	:ThreeDimensionalShape(x, y)
{
	if (r >= 0.0)
		radius = r;
	else
		throw invalid_argument("Radius must be >=0.0");
}
double Sphere::getRadius()const
{
	return radius;
}

double Sphere::getArea()const
{
	return radius * radius * MY_PI * 4;
}
double Sphere::getVolume()const
{
	return radius * radius * radius * MY_PI * 4 / 3;
}
void Sphere::print()const
{
	cout << "Sphere with radius" << radius << "; center at (" << xCenter << "," << yCenter << ")";
}