//Exercise 11.9 Solution: Overnight Package.h
// Definition of derived class OvernightPackage.
#ifndef OVERNIGHT_H
#define OVERNIGKT_H

#include "Package.h"// Package class definition

class OverNightPackage : public Package
{
public:
    OverNightPackage(const std::string& sName, const std::string& sAddress,
        const std::string& sCity, const std::string& sState, int sZIP,
        const std::string& rName, const std::string& rAddress, const std::string& rCity,
        const std::string& rState, int rZIP, double w, double cost, double fee);
    

    void setFeePerOunce(double);// set overnight fee
    double getFeePerOunce() const;// return overnight fee

    virtual double calculateCost() const override;        // calculate shipping cost for package
    //虛擬函式，有多載的功能，因含式需實現不同的功能(於.cpp檔中新實作的)，需override
    void print() const;                //print package's information and cost


private:
    double overnightFeePerOunce;    // per ounce for overnight delivery

}; // end class OvernightPackage

#endif
