
#include "phoneBookEntry.h"
#include <iostream>
#include <iomanip>

// implementing constructors
// default constructor
phoneBookEntry::phoneBookEntry()
{
	entryName = "";
	entryPhoneNumber = "";
	entryEmail = "";
}
// constructor with name and number
phoneBookEntry::phoneBookEntry(const std::string &name, const std::string &number)
{
	entryName = name;
	entryPhoneNumber = number;
	entryEmail = "";
}
// constructor with name, number, and email
phoneBookEntry::phoneBookEntry(const std::string &name, const std::string &number,  const std::string &email)
{
	entryName = name;
	entryPhoneNumber = number;
	entryEmail = email;
}
phoneBookEntry::phoneBookEntry(const phoneBookEntry &from) // copy constructor
{
	entryName = from.name();
	entryPhoneNumber = from.phoneNumber();
	entryEmail = from.email();
}

// implementing accessors
std::string phoneBookEntry::name() const
{
	return entryName;
}
std::string phoneBookEntry::phoneNumber() const
{
	return entryPhoneNumber;
}
std::string phoneBookEntry::email() const
{
	return entryEmail;
}

// implementing mutators
void phoneBookEntry::phoneNumber(const std::string &newNumber)
{
	entryPhoneNumber = newNumber;
}
void phoneBookEntry::email(const std::string &newEmail)
{
	entryEmail = newEmail;
}
bool phoneBookEntry::operator==(const phoneBookEntry &entry) const
{
	return this->name()==entry.name();
}
bool phoneBookEntry::operator!=(const phoneBookEntry &entry) const
{
	return this->name()!=entry.name();
}
bool phoneBookEntry::operator<(const phoneBookEntry &entry) const
{
	return this->name()<entry.name();;
}
bool phoneBookEntry::operator<=(const phoneBookEntry &entry) const
{
	return this->name()<=entry.name();;
}
bool phoneBookEntry::operator>(const phoneBookEntry &entry) const
{
	return this->name()>entry.name();;
}
bool phoneBookEntry::operator>=(const phoneBookEntry &entry) const
{
	return this->name()>=entry.name();;
}

std::ostream& operator<<(std::ostream &out, const phoneBookEntry &entry)
{
	out << std::left;
	if(entry.name()=="")
	{
	}
	else if(entry.email()!="")
	{
		out << std::setw(31) << entry.name() <<  std::setw(16) << entry.phoneNumber() << entry.email();
	}
	else
	{
		out <<  std::setw(31) << entry.name() <<  std::setw(16) << entry.phoneNumber();
	}
	return out;
}
