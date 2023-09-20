//TwoDayPackage.h
#ifndef _TWODAY_H
#define _TWODAY_H
#include "Package.h"

class TwoDayPackage : public Package
{
public:
	TwoDayPackage(const std::string&, const std::string&, const std::string&,
		const std::string&, int, const std::string&, const std::string&,
		const std::string&, const std::string&, int, double, double, double);
	void setFlatFee(double);  // set flat fee for two-day-delivery service
	double getFlatFee() const; // return flat fee
	virtual double calculateCost() const override; // calculate shipping cost for package
	//虛擬函式，有多載的功能，因含式需實現不同的功能(於.cpp檔中新實作的)，需override
	void print() const;  // print package's information and cost
private:
	double flatFee; // flat fee for two-day-delivery service
};
// end class TwoDayPackage

#endif // !_TWODAY_H
