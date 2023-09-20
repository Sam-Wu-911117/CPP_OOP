// Exercise 11.9 Solution: TwoDayPackage.h
// Definition of derived class TwoDayPackage.
#ifndef TW0DAY_H
#define TWODAY_H
#include "Package.h" // Package class definition

class TwoDayPackage : public Package
{
public:
	TwoDayPackage(const std::string &sName, const std::string &sAddress,
		const std::string &sCity, const std::string &sState, int sZIP,
		const std::string &rName, const std::string &rAddress, const std::string &rCity,
		const std::string &rState, int rZIP, double w, double cost, double fee);

	void setFlatFee(double);    // set flat fee for two-day-delivery service
	double getFlatFee() const;    // return flat fee

	double calculateCost() const; // calculate shipping cost for package
	void print() const;           // print package's information and cost
private:
	double flatFee;               // flat fee for two-day-delivery service
}; // end class TwoDayPackage

#endif