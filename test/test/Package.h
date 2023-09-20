// Exercise 11.9 Solution: Package.h

// Definition of base class Package.
#ifndef _PACKAGE_H
#define _PACKAGE_H
#include <string>

class Package
{
public:
	// constructor initializes data members
	Package(const std::string&, const std::string&, const std::string&,
		const std::string&, int, const std::string&, const std::string&,
		const std::string&, const std::string&, int, double, double);
	void setSenderName(const std::string&);			// set sender's name
	virtual std::string getSenderName() const;				// set sender's name
	void setSenderAddress(const std::string&);		// set sender's address
	virtual std::string getSenderAddress() const;			// return sender's address
	void setSenderCity(const std::string&);			//set sender's city
	virtual std::string getSenderCity() const;				// return sender*s city
	void setSenderState(const std::string&);		// set sender's state
	virtual std::string getSenderState() const;				// return sender's state
	void setSenderZIP(int);							// set sender's ZIP code
	int getSenderZIP() const;						// return sender's ZIP code
	void setRecipientName(const std::string&);		// set recipient's name
	virtual std::string getRecipientName() const;			// return recipient's name
	void setRecipientAddress(const std::string&);	// set recipient's address
	virtual std::string getRecipientAddress() const;		// return recipient's address
	void setRecipientCity(const std::string&);		// set recipient's city
	virtual std::string getRecipientCity() const;			// return recipient's city
	void setRecipientState(const std::string&);		// set recipient's state
	virtual std::string getRecipientState() const;			// return recipient's state
	void setRecipientZIP(int);						// set recipient's ZIP code
	int getRecipientZIP() const;					// return recipient's ZIP code
	void setWeight(double);							// validate and store weight
	double getWeight() const;						// return weight of package
	void setCostPerOunce(double);					// validate and store cost perounce


	double getCostPerOunce() const;					//return cost peronuce
	virtual double calculateCost() const;					// calculate shipping cost for package

	void print() const;								// print package's information  and cost

private:
	// data members to store sender and recipient's address information
	std::string senderName;
	std::string senderAddress;
	std::string senderCity;
	std::string senderState;
	int senderZIP;
	std::string recipientName;
	std::string recipientAddress;
	std::string recipientCity;
	std::string recipientState;
	int recipientZIP;
	double weight;// weight of the package
	double costPerOunce;// cost per ounce to ship the package
};

#endif // !_PACKAGE_H