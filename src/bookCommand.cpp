// book command allows you to display a passed string and allows you to prompt user input, take it in, and return it

#include <iostream>
#include <string>

#include "bookCommand.h"

// bookCommand constructor using an initializer list
bookCommand::bookCommand(std::istream &inStream, std::ostream &outStream)
   :  in(inStream), out(outStream)
{
}

// function to display a passed message to the ostream object
void bookCommand::displayString(std::string message)
{
	out << message << std::endl;
}

// function to prompt user input using the ostream object, taking in a string using the istream object, and returning the string
std::string bookCommand::promptInput(std::string prompt)
{
	// declaring string variable to hold input
	std::string response;

	// prompting user and taking in result using get line
	out << prompt << std::endl;
	std::getline(in, response);

	// returning the string we took in
	return response;
}
