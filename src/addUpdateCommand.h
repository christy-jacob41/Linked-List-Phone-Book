/*
  this class allows the user to add an entry or update one depending on if the name is in the phone  book
 */

#ifndef ADDUPDATECOMMAND_H_
#define ADDUPDATECOMMAND_H_

#include "bookCommand.h"
#include "phoneBook.h"

// addUpdateCommand is a derived class of bookCommand
class addUpdateCommand : public bookCommand
{
	// private phone book object declared
private:
	phoneBook& book;

	// public constructor and execute function which overrides the execute function in command.h
public:
	addUpdateCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream);
	virtual void execute() override;

};



#endif /* ADDUPDATECOMMAND_H_ */
