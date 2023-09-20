// Exercise 12.13 Solution: Shape.cpp
	// Member and friend definitions for class Shape

#include"Shape.h" 
Shape::Shape(double x, double y)
{
	xCenter = x;
	yCenter = y;
}
double Shape::getCenterX()const
{
	return xCenter;
}
double Shape::getCenterY()const
{
	return yCenter;
}
ostream& operator<<(ostream& out, Shape& s)
{
	s.print();
	return out;
}