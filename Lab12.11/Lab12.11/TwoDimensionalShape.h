// Exercise 12.13 Solution: TwoDimensionaIShape.h
 // Definition of class TwoDimensiona1Shape
#ifndef TWODIM_H
#define TWODIM_H

#include "Shape.h"

class TwoDimensionalShape : public Shape
{
public:
	//default constructor
	TwoDimensionalShape(double x, double y) : Shape(x, y) {}
	virtual double getArea() const = 0; // area of TwoDimensionalShape
};//end class TwoDimensionalShape
#endif