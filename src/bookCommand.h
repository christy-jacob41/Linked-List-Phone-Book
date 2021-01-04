/*
	book command allows you to display a passed string and allows you to prompt user input, take it in, and return it
 */

#ifndef BOOKCOMMAND_H_
#define BOOKCOMMAND_H_

#include <iostream>
#include <string>

#include "command.h"

// bookCommand is a derived class of command
class bookCommand : public command
{
// declaring variables for istream and ostream and declaring a function to display a string as well as one to prompt user input, take it in, and return it
protected:
      std::istream &in;
      std::ostream &out;
      void displayString(std::string message);
      std::string promptInput(std::string prompt);
public:
      bookCommand(std::istream &in, std::ostream &out);

};



#endif /* BOOKCOMMAND_H_ */
