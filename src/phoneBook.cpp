//the phone book class keeps track of a phone book and allows you to insert, erase, and find an entry and allows you to get the size of the phone book and allows you to print the contents of the phone book

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

#include "phoneBook.h"

// defining default constructor
phoneBook::phoneBook()
: entryIterator(phoneBookEntries.begin())
{

}

// 3 Insert Functions which either update the entry if the name exists or add the entry if the name doesen't exist
// defining insert function with a phone book entry as the passed parameter
void phoneBook::insert(const phoneBookEntry &entry)
{
	// if the name is in the book, update, or else, add
	if(find(entry.name()))
	{
		phoneBookEntries.erase(entry);
	}
	phoneBookEntries.insert(entry);
}

// defining insert function with name, number, and email as parameters
void phoneBook::insert(const std::string &name, const std::string &number, const std::string &email)
{
	// if the name is in the book, update, or else, add
	phoneBookEntry entry(name, number, email);
	if(find(name))
	{
		phoneBookEntries.erase(entry);
	}
	phoneBookEntries.insert(entry);
}

// defining insert function with name and number as parameters
void phoneBook::insert(const std::string &name, const std::string &number)
{
	// if the name is in the book, update, or else, add
	phoneBookEntry entry(name, number);
	if(find(name))
	{
		phoneBookEntries.erase(entry);
	}
	phoneBookEntries.insert(entry);
}

// function which erases the entry with the passed name if there is one and returns true only if an entry is erased
bool phoneBook::erase(std::string name)
{
	// declaring bool variable for whether entry was erased or not
	phoneBookEntry entry(name, "", "");
	return phoneBookEntries.erase(entry);

}

// function that looks for a name in the phone book and returns true if found
bool phoneBook::find(std::string name)
{
	// declaring bool variable for whether name was found or not
	bool found =false;
	phoneBookEntry entry(name, "", "");
	if(phoneBookEntries.find(entry)!= phoneBookEntries.end())
	{
		entryIterator = phoneBookEntries.find(entry);
		found = true;
	}
	return found;
}

// 2 print functions that print out the contents of the phone book using a for loop, formatted
// one prints to cout and the other to the passed by reference ostream object
void phoneBook::print() const
{
	std::cout << std::left << std::setw(31) << "Name:" << std::setw(16) << "Phone Number:" << "E-Mail:" << std::endl;
	phoneBookEntries.print();
}
void phoneBook::print(std::ostream &out) const
{
	out << std::left << std::setw(31) << "Name:" << std::setw(16) << "Phone Number:" << "E-Mail:" << std::endl;
	phoneBookEntries.print(out);
}

// debug function to help with debugging that prints the contents of the phone book vector to the passed by reference ostream object
void phoneBook::debug(std::ostream &out) const
{
	phoneBookEntries.print(out);
}

// function returning the vector size
std::size_t phoneBook::size() const
{
	return phoneBookEntries.size();
}

// implementing begin and end functions
phoneBook::iterator phoneBook::begin()
{
	return phoneBookEntries.begin();
}
phoneBook::iterator phoneBook::end()
{
	return phoneBookEntries.end();
}
