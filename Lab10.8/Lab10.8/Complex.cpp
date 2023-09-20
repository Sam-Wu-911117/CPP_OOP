//Complex.cpp
#include "Complex.h"
#include <iostream>

using namespace std;

Complex::Complex(double realPart, double imaginaryPart)
	:real(realPart), imaginary(imaginaryPart)
{
}

Complex Complex::operator+(const Complex &operand2) const
{
	return Complex(real + operand2.real, imaginary + operand2.imaginary);

}

Complex Complex::operator-(const Complex &operand2) const
{
	return Complex(real - operand2.real, imaginary - operand2.imaginary);
}

Complex Complex::operator*(const Complex &operand2) const
{
	return Complex(real * operand2.real - imaginary * operand2.imaginary, real* operand2.imaginary + imaginary * operand2.real);
}

bool Complex::operator==(const Complex &right) const
{
	if (real == right.real && imaginary == right.imaginary)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Complex::operator!=(const Complex &right) const
{
	if (real != right.real || imaginary != right.imaginary)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Complex::print() const
{
	cout << " [ " << real << " + " << imaginary << " j " << " ] ";
}
//==========================================================================================

std::ostream &operator<<(std::ostream &output, const Complex &complexNum)
{
	output << " [ " << complexNum.real << " + " << complexNum.imaginary << " j " << " ] ";
	return output;
}

std::istream &operator>>(std::istream &input, Complex &complexNum)
{
	input >> complexNum.real;
	input >> complexNum.imaginary;
	return input;
}

