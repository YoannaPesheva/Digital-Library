#include<iostream>
#include "Commands.h"

//const we will work with
const int END_SESSION = -1;
const int INVALID_COMMAND = 0;
const int SORT_BOOKS = 1;
const int FIND_A_BOOK = 2;
const int OUTPUT_A_BOOK = 3;
const int ADD_A_BOOK = 4;
const int REMOVE_A_BOOK = 5;
const int GET_HELP = 6;


//printing
void Commands::printCommands() {
	std::cout << "List of Commands: " << std::endl;
	std::cout << "1. Unauthorised access:" << std::endl;
	std::cout << "  1.1 Sort (the books by a criteria).\n  1.2. Find (a book by a criteria).\n  1.3. Output (a book)." << std::endl;
	std::cout << "2. Authorised access:" << std::endl;
	std::cout << "  2.1. Add (a book).\n  2.2. Remove (a book)." << std::endl;
	std::cout << "3. End (the session)" << std::endl;
	std::cout << "4. Help (prints the commands again)." << std::endl;
}


//get the command the user wants
int Commands::getCommand(const char* command)
{
	if (strcmp(command, "Sort") == 0 || strcmp(command, "sort") == 0)
	{
		return SORT_BOOKS;
	}
	else if (strcmp(command, "Find") == 0 || strcmp(command, "find") == 0)
	{
		return FIND_A_BOOK;
	}
	else if (strcmp(command, "Output") == 0 || strcmp(command, "output") == 0)
	{
		return OUTPUT_A_BOOK;
	}
	else if (strcmp(command, "Add") == 0 || strcmp(command, "add") == 0)
	{
		return ADD_A_BOOK;
	}
	else if (strcmp(command, "Remove") == 0 || strcmp(command, "remove") == 0)
	{
		return REMOVE_A_BOOK;
	}
	else if (strcmp(command, "End") == 0 || strcmp(command, "end") == 0)
	{
		return END_SESSION;
	}
	else if (strcmp(command, "Help") == 0 || strcmp(command, "help") == 0)
	{
		return GET_HELP;
	}
	else
	{
		return INVALID_COMMAND;
	}

}