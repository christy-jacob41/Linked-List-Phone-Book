
//the printCommand class allows the user to print out the current contents of the phone book vector

#include <iostream>

#include "printCommand.h"

printCommand::printCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream)
  :  bookCommand(inStream, outStream), book(bookIn)
{
   // any other code you may need
}

void printCommand::execute()
{
	// calling print function to print out contents of phone book
	book.print(out);
}
