#include<iostream>
#include "Commands.h";

const int END_SESSION = -1;
const int INVALID_COMMAND = 0;
const int SORT_BOOKS = 1;
const int FIND_A_BOOK = 2;
const int OUTPUT_A_BOOK = 3;
const int ADD_A_BOOK = 4;
const int REMOVE_A_BOOK = 5;


/*commands
*	1.sort
*		1.1 by title
*		1.2 by author
*		1.3 by rating
*			1.1.1-increasing
*			1.1.2-decreasing
* !!the output is only every book's title, author and ISBN
*	2. find a book by criteria
*		2.1 by title
*		2.2 author
*		2.3. ISBN 
*		2.4 a part of the summary - only that is partial
*		!ignore small and big letters
*	3. Output the book (?)
*	NEED PASSWORD
*	4. add a book
*	5. remove a book 
*/	


void Commands::printCommands() {
	std::cout << "List of Commands: " << std::endl;
	std::cout << "1. Unauthorised access:" << std::endl;
	std::cout << "  1.1 Sort (the books by a criteria).\n  1.2. Find (a book by a criteria).\n  1.3. Output (a book)." << std::endl;
	std::cout << "2. Authorised access:" << std::endl;
	std::cout << "  2.1. Add (a book).\n  2.2. Remove (a book)." << std::endl;
	std::cout << "3. End (the session)" << std::endl;
}

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
	else if (strcmp(command, "Add") == 0|| strcmp(command, "add") == 0)
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
	else
	{
		return INVALID_COMMAND;
	}

}
