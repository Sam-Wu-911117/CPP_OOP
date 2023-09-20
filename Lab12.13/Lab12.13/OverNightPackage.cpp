// Exercise 11.9 Solution: OvemightPackage.cpp
// Member-function definitions of class OvernightPackage.
#include <stdexcept>
#include <iostream>
#include "OverNightPackage.h" //OvernightPackage class definition
using namespace std;

OverNightPackage::OverNightPackage(const string& sName, const string& sAddress,
    const string& sCity, const string& sState, int sZIP,
    const string& rName, const string& rAddress, const string& rCity,
    const string& rState, int rZIP, double w, double cost, double fee)
    : Package(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, w, cost)// constructor
{
    setFeePerOunce(fee);
}


void OverNightPackage::setFeePerOunce(double fee)
{
    overnightFeePerOunce = fee;
}// set overnight fee

double OverNightPackage::getFeePerOunce() const
{
    return overnightFeePerOunce;
}// return overnight fee

double OverNightPackage::calculateCost() const
{
    return Package::getWeight() * getFeePerOunce();
}// calculate shipping cost for package

void OverNightPackage::print() const
{
    cout << "OvernightPackage:\n\nSender:\n" << getSenderName() << '\n' << getSenderAddress() << '\n'
        << getSenderCity() << ", " << getSenderState() << ' ' << getSenderZIP();
    cout << "\n\nRecipient:\n" << getRecipientName() << '\n' << getRecipientAddress() << '\n'
        << getRecipientCity() << ", " << getRecipientState() << ' ' << getRecipientZIP();
    cout << "\n\nCost: $" << calculateCost() << endl;
    cout << "=================================================================================================" << endl;
}// print package's information and cost


