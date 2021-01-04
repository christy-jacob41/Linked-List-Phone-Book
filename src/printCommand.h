/*
   the printCommand class allows the user to print out the current contents of the phone book vector
 */

#ifndef PRINTCOMMAND_H_
#define PRINTCOMMAND_H_

#include "bookCommand.h"
#include "phoneBook.h"

// printCommand is a derived class of bookCommand
class printCommand : public bookCommand
{
	// private phone book object declared
private:
	phoneBook& book;

	// public constructor and execute function which overrides the execute function in command.h
public:
	printCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream);
	virtual void execute() override;

};



#endif /* PRINTCOMMAND_H_ */
