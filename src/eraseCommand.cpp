
//the eraseCommand class allows the user to erase an entry with a specific name

#include <iostream>

#include "eraseCommand.h"

eraseCommand::eraseCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream)
  :  bookCommand(inStream, outStream), book(bookIn)
{
   // any other code you may need
}

void eraseCommand::execute()
{
	// decalring name variable and taking it in
	std::string name;
	name = promptInput("Enter name to erase");

	// if the name is found, erase, otherwise print error message
	if(book.find(name))
	{
		// calling erase function to erase and displayString to tell what happened
		book.erase(name);
		displayString("Phone book entry " + name + " was erased");
	}
	else
	{
		// calling displayString to print error message
		displayString("Phone book entry " + name + " was not erased");
	}
}
