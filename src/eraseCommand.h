/*
  the eraseCommand class allows the user to erase an entry with a specific name
 */

#ifndef ERASECOMMAND_H_
#define ERASECOMMAND_H_

#include "bookCommand.h"
#include "phoneBook.h"

// eraseCommand is a derived class of bookCommand
class eraseCommand : public bookCommand
{
	// private phone book object declared
private:
	phoneBook& book;

	// public constructor and execute function which overrides the execute function in command.h
public:
	eraseCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream);
	virtual void execute() override;

};


#endif /* ERASECOMMAND_H_ */
