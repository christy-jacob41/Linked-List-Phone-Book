/*
	the phoneBookEntry class keeps track of one entry and can return name, number, and email and change number and email
 */

#ifndef PHONEBOOKENTRY_H_
#define PHONEBOOKENTRY_H_

#include <string>

class phoneBookEntry
{
private:
	//creating three private strings holding name, phone number, and email address
	std::string entryName;
	std::string entryPhoneNumber;
	std::string entryEmail;
public:
	// constructors for phoneBookEntry class
	phoneBookEntry();
	phoneBookEntry(const std::string &name, const std::string &number);
	phoneBookEntry(const std::string &name, const std::string &number,  const std::string &email);
	phoneBookEntry(const phoneBookEntry &from); // copy constructor
	// accessor methods for name, phone number, and email
	std::string name() const;
	std::string phoneNumber() const;
	std::string email() const;
	// mutator methods for phone number and email(you can't change name)
	void phoneNumber(const std::string &newNumber);
	void email(const std::string &newEmail);
	// functions for comparison operations
	bool operator==(const phoneBookEntry &entry) const;
	bool operator!=(const phoneBookEntry &entry) const;
	bool operator<(const phoneBookEntry &entry) const;
	bool operator<=(const phoneBookEntry &entry) const;
	bool operator>(const phoneBookEntry &entry) const;
	bool operator>=(const phoneBookEntry &entry) const;
};

std::ostream& operator<<(std::ostream &out, const phoneBookEntry &entry);

#endif /* PHONEBOOKENTRY_H_ */
