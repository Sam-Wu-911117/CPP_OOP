//Exercise 11.9 Solution: Overnight Package.h
// Definition of derived class OvernightPackage.
#ifndef _OVERNIGHT_H
#define _OVERNIGHT_H
#include "Package.h"// Package class definition
using namespace std;

class OvernightPackage : public Package
{
public:
	OvernightPackage(const std::string&, const std::string&, const std::string&,
		const std::string&, int, const std::string&, const std::string&,
		const std::string&, const std::string&, int, double, double, double);
	void setOvernightFee(double);// set overnight fee
	double getOvernightFee() const;// return overnight fee
	virtual double calculateCost() const override; // calculate shipping cost for package
    //�����禡�A���h�����\��A�]�t���ݹ�{���P���\��(��.cpp�ɤ��s��@��)�A��override
	void print() const;//print package's information and cost

private:
	double overnightFeePerOunce; // per ounce for overnight delivery
};// end class OvernightPackage

#endif // !_OVERNIGHT_H


