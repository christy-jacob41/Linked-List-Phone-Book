/*
	the phone book class keeps track of a phone book and allows you to insert, erase, and find an entry and allows you to get the size of the phone book and allows you to print the contents of the phone book
 */

#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_

#include <vector>
#include <string>
#include <iostream>

#include "phoneBookEntry.h"
#include "orderedLinkedList.h"

class phoneBook
{

public:
	//default constructor
	phoneBook();
	//member functions
	void insert(const phoneBookEntry &entry);
	void insert(const std::string &name, const std::string &number, const std::string &email);
	void insert(const std::string &name, const std::string &number);
	bool erase(std::string name);
	bool find(std::string name);
	void print() const;
	void print(std::ostream &out) const;
	void debug(std::ostream &out) const;
	std::size_t size() const;
	// typedef to make declarations and definitions easier to type
	typedef orderedLinkedList<phoneBookEntry> phoneBookEntryList;
	typedef phoneBookEntryList::iterator iterator;
	typedef phoneBookEntryList::const_iterator const_iterator;
	// functions to return the beginning and end positions of the phone book vector as a iterator
	iterator begin();
	iterator end();
private:
	// vector holding phone book entries
	phoneBookEntryList phoneBookEntries;
	// iterator holding the position of the current entry in the phone book vector
	iterator entryIterator;

};


#endif /* PHONEBOOK_H_ */
