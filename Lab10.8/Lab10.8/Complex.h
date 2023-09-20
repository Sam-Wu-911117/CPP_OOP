//Complex.h
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{
	//friend std::ostream&operator<<(std::ostream& output, const Complex& complexNum);

	friend std::ostream &operator<<(std::ostream &output, const Complex &complexNum);
	friend std::istream &operator>>(std::istream &input,  Complex &complexNum);

public:
	explicit Complex(double realPart, double imaginaryPart);
	Complex operator+(const Complex &operand2) const;
	Complex operator-(const Complex &operand2) const;
	Complex operator*(const Complex &operand2) const; //mutioication
	bool operator==(const Complex &right) const; //equal
	bool operator!=(const Complex &right) const; //not equal
	void print() const;

private:
	double real;
	double imaginary;
};



#endif