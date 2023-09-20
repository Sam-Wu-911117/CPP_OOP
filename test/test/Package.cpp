//Package.cpp
#include <stdexcept>
#include "Package.h"
#include <iostream>
using namespace std;

Package::Package(const std::string& sName, const std::string& sAddress, const std::string& sCity,
	const std::string& sState, int sZIP, const std::string& rName, const std::string& rAddress,
	const std::string& rCity, const std::string& rState, int rZIP, double w, double cost)
	: senderName(sName), senderAddress(sAddress), senderCity(sCity), senderState(sState), senderZIP(sZIP),
	recipientName(rName), recipientAddress(rAddress), recipientCity(rCity), recipientState(rState), recipientZIP(rZIP)
{
	setWeight(w);
	setCostPerOunce(cost);
}

void Package::setSenderName(const std::string& sName)
{
	senderName = sName;
}

std::string Package::getSenderName() const
{
	return senderName;
}

void Package::setSenderAddress(const std::string& sAddress)
{
	senderAddress = sAddress;
}

std::string Package::getSenderAddress() const
{
	return senderAddress;
}

void Package::setSenderCity(const std::string& sCity)
{
	senderCity = sCity;
}

std::string Package::getSenderCity() const
{
	return senderCity;
}

void Package::setSenderState(const std::string& sState)
{
	senderState = sState;
}

std::string Package::getSenderState() const
{
	return senderState;
}

void Package::setSenderZIP(int sZIP)
{
	senderZIP = sZIP;
}

int Package::getSenderZIP() const
{
	return senderZIP;
}

void Package::setRecipientName(const std::string& rName)
{
	recipientName = rName;
}

std::string Package::getRecipientName() const
{
	return recipientName;
}

void Package::setRecipientAddress(const std::string& rAddress)
{
	recipientAddress = rAddress;
}

std::string Package::getRecipientAddress() const
{
	return recipientAddress;
}

void Package::setRecipientCity(const std::string& rCity)
{
	recipientCity = rCity;
}

std::string Package::getRecipientCity() const
{
	return recipientCity;
}

void Package::setRecipientState(const std::string& rState)
{
	recipientState = rState;
}

std::string Package::getRecipientState() const
{
	return recipientState;
}

void Package::setRecipientZIP(int rZIP)
{
	recipientZIP = rZIP;
}

int Package::getRecipientZIP() const
{
	return recipientZIP;
}

void Package::setWeight(double w)
{
	if (w >= 0.0)
		weight = w;
	else
		throw invalid_argument("Weight must be >= 0.0");
}

double Package::getWeight() const
{
	return weight;
}

void Package::setCostPerOunce(double cost)
{
	costPerOunce = cost;
}

double Package::getCostPerOunce() const
{
	return costPerOunce;
}

double Package::calculateCost() const
{
	return getWeight() * getCostPerOunce();
}

void Package::print() const
{
	cout << ">> Package:\n\nSender:\n" << getSenderName() << '\n' << getSenderAddress() << '\n'
		<< getSenderCity() << ", " << getSenderState() << ' ' << getSenderZIP();
	cout << "\n\nRecipient:\n" << getRecipientName() << '\n' << getRecipientAddress() << '\n'
		<< getRecipientCity() << ", " << getRecipientState() << ' ' << getRecipientZIP();
	cout << "\n\nCost: $" << calculateCost() << endl << "=================================================================================================" << endl;
}