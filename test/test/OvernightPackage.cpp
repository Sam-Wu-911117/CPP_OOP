//OvernightPackage.cpp
#include <stdexcept>
#include <iostream>
#include "OvernightPackage.h"

OvernightPackage::OvernightPackage(const std::string& sName, const std::string& sAddress, const std::string& sCity,
	const std::string& sState, int sZIP, const std::string& rName, const std::string& rAddress,
	const std::string& rCity, const std::string& rState, int rZIP, double w, double cost, double fee)
	: Package(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, w, cost)
{
	setOvernightFee(fee);
}

void OvernightPackage::setOvernightFee(double fee)
{
	if (fee >= 0.0)
		overnightFeePerOunce = fee;
	else
		throw invalid_argument("Overnightfee must be >= 0.0");
}

double OvernightPackage::getOvernightFee() const
{
	return overnightFeePerOunce;
}

double OvernightPackage::calculateCost() const
{
	return getWeight() * (getCostPerOunce() + getOvernightFee());
}

void OvernightPackage::print() const
{
	cout << ">> OvernightPackage:\n\nSender:\n" << getSenderName() << '\n' << getSenderAddress() << '\n'
		<< getSenderCity() << ", " << getSenderState() << ' ' << getSenderZIP();
	cout << "\n\nRecipient:\n" << getRecipientName() << '\n' << getRecipientAddress() << '\n'
		<< getRecipientCity() << ", " << getRecipientState() << ' ' << getRecipientZIP();
	cout << "\n\nCost: $" << calculateCost() << endl << "=================================================================================================" << endl;
}