
//this class allows the user to add an entry or update one depending on if the name is in the phone  book

#include <iostream>

#include "addUpdateCommand.h"

// constructor for addUpdateCommand with initializer list
addUpdateCommand::addUpdateCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream)
  :  bookCommand(inStream, outStream), book(bookIn)
{
}

// overriding the execute function
void addUpdateCommand::execute()
{
	// declaring string variables to hold the name, phone number, and email to be taken in
	std::string name;
	std::string phoneNumber;
	std::string email;

	// taking in the name, phone number, and email
	name = promptInput("Enter name to add/update");
	phoneNumber = promptInput("Enter phone number");
	email = promptInput("Enter e-mail address");

	// if name is in the phone book, update, otherwise, add
	if(book.find(name))
	{
		// calling insert function to update and displayString to tell what happened
		book.insert(name, phoneNumber, email);
		displayString("Updating phone book entry for " + name);
	}
	else
	{
		// calling insert function to update and displayString to tell what happened
		book.insert(name, phoneNumber, email);
		displayString("Adding phone book entry for " + name);
	}
}
