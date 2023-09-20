#ifndef CUBE_H 
#define CUBE_H 
#include"ThreeDimensionalShape.h" 
class Cube :public ThreeDimensionalShape
{
public:
	Cube(double = 0.0, double = 0.0, double = 0.0);
	virtual double getSidelength()const;
	virtual double getArea()const;
	virtual double getVolume()const;
	void print()const;
private:
	double sidelength;
};
#endif