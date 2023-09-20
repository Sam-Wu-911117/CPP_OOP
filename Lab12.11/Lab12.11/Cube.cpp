#include<iostream> 
#include<stdexcept> 
#include"Cube.h" 
using namespace std;

Cube::Cube(double s, double  x, double y)
	:ThreeDimensionalShape(x, y)
{
	if (s >= 0.0)
		sidelength = s;
	else
		throw invalid_argument("Sidelength must be >=0.0");
}
double Cube::getSidelength()const
{
	return sidelength;
}

double Cube::getArea()const
{
	return sidelength * sidelength * 6;
}
double Cube::getVolume()const
{
	return sidelength * sidelength * sidelength;
}
void Cube::print()const
{
	cout << "Cube with sidelength" << sidelength << "; center at (" << xCenter << "," << yCenter << ")";
}