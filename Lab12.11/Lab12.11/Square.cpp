// Exercise 12.13 Solution: Square.cpp
// Member-fundion definitions for class Square
#include<iostream> 
#include<stdexcept> 
#include"Square.h" 
using namespace std;

Square::Square(double s, double  x, double y)
	:TwoDimensionalShape(x, y)
{
	if (s >= 0.0)
		sideLength = s;
	else
		throw invalid_argument("Side must be >=0.0");
}
double Square::getSideLength()const
{
	return sideLength;
}

double Square::getArea()const
{
	return sideLength * sideLength;
}
void Square::print()const
{
	cout << "Square with side length" << sideLength << ": center at (" << xCenter << "," << yCenter << ")";
}