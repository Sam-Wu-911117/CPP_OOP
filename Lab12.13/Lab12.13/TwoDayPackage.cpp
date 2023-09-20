//TwoDayPackage.cpp
#include "TwoDayPackage.h"
#include <stdexcept>
#include <iostream>
using namespace std;


TwoDayPackage::TwoDayPackage(const string& sName, const string& sAddress,
	const string& sCity, const string& sState, int sZIP,
	const string& rName, const string& rAddress, const string& rCity,
	const string& rState, int rZIP, double w, double cost, double fee)
	: Package(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, w, cost)
{
	setFlatFee(fee);
	//end TwoDayPackage constructor
}

//set flat fee
void TwoDayPackage::setFlatFee(double fee)
{
	flatFee = fee;
}//end function getFlatFee

//return flat fee
double TwoDayPackage::getFlatFee() const
{
	return flatFee;
}//end function getFlatFee

//calculate shipping cost for package
double TwoDayPackage::calculateCost() const
{
	return getFlatFee() + Package::calculateCost();
}//end function calculateCost

void TwoDayPackage::print() const
{
	cout << "TwoDayPackage:\n\nSender:\n" << getSenderName() << '\n' << getSenderAddress() << '\n'
		<< getSenderCity() << ", " << getSenderState() << ' ' << getSenderZIP();
	cout << "\n\nRecipient:\n" << getRecipientName() << '\n' << getRecipientAddress() << '\n'
		<< getRecipientCity() << ", " << getRecipientState() << ' ' << getRecipientZIP();
	cout << "\n\nCost: $" << calculateCost() << endl; 
	cout << "=================================================================================================" << endl;
}//end function print