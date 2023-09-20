// Exercise 11.9 Solution: Package.cpp
   // Member-function definitions of class Package.
#include <stdexcept>
#include<iostream>
#include "Package.h" // Package class definition
using namespace std;

// constructor initializes data members
Package::Package(const string& sName, const string& sAddress,
	const string& sCity, const string& sState, int sZIP,
	const string& rName, const string& rAddress, const string& rCity,
	const string& rState, int rZIP, double w, double cost)
	:senderName(sName), senderAddress(sAddress), senderCity(sCity),
	senderState(sState), senderZIP(sZIP), recipientName(rName),
	recipientAddress(rAddress), recipientCity(rCity),
	recipientState(rState), recipientZIP(rZIP)
{
	setWeight(w); // validate and store weight
	setCostPerOunce(cost); // validale and store cost per ounce
} // end Package constructor




void Package::setWeight(double w)
{
	if (w >= 0.0)
		weight = w;
	else
		throw invalid_argument("Weight must be >= 0.0");
} // end function setWeight

// return weight of package
double Package::getWeight() const
{
	return weight;
} // end function getWeight

void Package::setCostPerOunce(double cost) {
	if (cost >= 0.0)
		costPerOunce = cost;
	else
		throw invalid_argument("Weight must be >= 0.0");
}						 // validate and store cost perounce

double Package::getCostPerOunce() const {
	return costPerOunce;
}					//return cost peronuce

// calculate shipping cost for package
double Package::calculateCost() const
{
	return getWeight() * getCostPerOunce();
} // end function calculateCost

// print package's information and cost
void Package::print() const
{
	cout << "Package 1:\n\nSender:\n" << getSenderName()
		<< "\n" << getSenderAddress() << "\n"
		<< getSenderCity() << ", " << getSenderState()
		<< " " << getSenderZIP();

	cout << "\n\nRecipient:\n" << getRecipientName()
		<< "\n" << getRecipientAddress() << "\n"
		<< getRecipientCity() << ","
		<< getRecipientState() << "  "
		<< getRecipientZIP();

	cout << "\n\nCost: $" << calculateCost() << endl;


} // end function print

void Package::setSenderName(const string& sName) {

	senderName = sName;
}		// set sender's name

string Package::getSenderName() const {
	return  senderName;
}						 // set sender's name

void Package::setSenderAddress(const string& sAddress) {
	senderAddress = sAddress;
}		 // set sender's address

string Package::getSenderAddress() const {
	return senderAddress;
}					 // return sender's address

void Package::setSenderCity(const string& sCity) {
	senderCity = sCity;
}				//set sender's city

string Package::getSenderCity() const {
	return senderCity;
}					// return sender*s city

void Package::setSenderState(const string& sState) {
	senderState = sState;
}		// set sender's state

string Package::getSenderState() const {
	return senderState;
}					// return sender's state

void Package::setSenderZIP(int sZIP) {
	senderZIP = sZIP;
}										// set sender's ZIP code

int Package::getSenderZIP() const {
	return senderZIP;
}								// return sender's ZIP code

void Package::setRecipientName(const string& rName) {
	recipientName = rName;
}		// set recipient's name

string Package::getRecipientName() const {
	return recipientName;
}				// return recipient's name

void Package::setRecipientAddress(const string& rAddress) {
	recipientAddress = rAddress;
}	// set recipient's address

string Package::getRecipientAddress() const {
	return recipientAddress;
}				// return recipient's address

void Package::setRecipientCity(const string& rCity) {
	recipientCity = rCity;
}		// set recipient's city

string Package::getRecipientCity() const {
	return recipientCity;
}					// return recipient's city

void Package::setRecipientState(const string& rState) {
	recipientState = rState;
}		// set recipient's state

string Package::getRecipientState() const {
	return recipientState;
}					// return recipient's state

void Package::setRecipientZIP(int rZIP) {
	recipientZIP = rZIP;
}									// set recipient's ZIP code

int Package::getRecipientZIP() const {
	return recipientZIP;
}

