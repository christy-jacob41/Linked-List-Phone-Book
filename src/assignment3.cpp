// this is the main function that creates the menu, phone book, menu items, and starts up the menu

#include <iostream>

#include "command.h"
#include "menuList.h"
#include "phoneBookEntry.h"
#include "addUpdateCommand.h"
#include "eraseCommand.h"
#include "phoneBook.h"
#include "printCommand.h"
#include "bookCommand.h"


int main()
{
	// declaring phone book and menu list objects while passing menu list header
	phoneBook book;
	menuList menu("Phone book menu:");

	// declaring addUpdateCommand, eraseCommand, and printCommand objects while passing the phone book, cin, and cout
	addUpdateCommand addUpdate(book, std::cin, std::cout);
	eraseCommand erase(book, std::cin, std::cout);
	printCommand print(book, std::cin, std::cout);

	// creating addUpdateCommand, eraseCommand, and printCommand menu items while passing the appropriate character, description, and object
	menuItem addUpdateItem('a', "add/update", addUpdate);
	menuItem eraseItem('e', "erase", erase);
	menuItem printItem('p', "print", print);

	// adding the addUpdateCommand, eraseCommand, and printCommand menu items to the menu list
	menu.add(addUpdateItem);
	menu.add(eraseItem);
	menu.add(printItem);

	// print out message stating that we're starting the phone book and actually starting the phone book
	std::cout << "Starting the Phone Book" << std::endl << std::endl;
	menu.start();

	return 0;
}
