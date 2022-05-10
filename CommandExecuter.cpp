#include "CommandExecuter.h"

void CommandExecuter::start()
{
	char command[16] = "0";
	int commandCode;
	Commands::printCommands();
	std::cout << "What would you like to do: ";
	std::cin.getline(command, 16);
	do
	{
		commandCode = Commands::getCommand(command);
		if (commandCode == 0)
		{
			InvalidCommandMessage();
		}
		else if (commandCode == 1)
		{
			executeSort();
		}
		else if (commandCode == 2)
		{
			executeFind();
		}
		else if (commandCode == 3)
		{
			std::cout << "Function not done yet :D" << std::endl;
		}
		else if (commandCode == 4)
		{
			addBook();
		}
		else if (commandCode == 5)
		{
			removeBook();
		}
		if (commandCode == -1) break;
		std::cout << "What would you like to do: ";
		std::cin.ignore(10, '\n');
		std::cin.getline(command, 16);

	} while (commandCode != -1);
	if (commandCode == -1)
	{
		EndProgram();
	}
}

void CommandExecuter::InvalidCommandMessage()
{
	std::cout << "Invalid command, please try again!" << std::endl;
}

void CommandExecuter::executeSort()
{
	std::cout << "Welcome to the sort command :D" << std::endl;
	std::cout << "By what category do you want to sort the books: " << std::endl;
	std::cout << "Please press 1 if you want them sorted by title, 2 for author and 3 for rating: ";
	int categoryType = 0;
	do {
		std::cin >> categoryType;
		if (categoryType < 1 || categoryType>3) std::cout << "Make sure you press a number between 1 and 3. Try again: " << std::endl;
	} while (categoryType < 1 || categoryType>3);

	std::cout << "Do you want the books to be sorted in ascending order(please press 1 for that) or descending one(please press 2): ";
	int orderType = 0;
	do {
		std::cin >> orderType;
		if (orderType < 1 || orderType >2) std::cout << "Make sure you press a number between 1 and 2. Try again: " << std::endl;
	} while (orderType < 1 || orderType>2);

	if (orderType == 1)
	{
		if (categoryType == 1)
		{
			library.sortByTitleAscending();
		}
		else if (categoryType == 2)
		{
			library.sortByAuthorAscending();
		}
		else if (categoryType == 3)
		{
			library.sortByRatingAscending();
		}
	}
	else
	{
		if (categoryType == 1)
		{
			library.sortByTitleDescending();
		}
		else if (categoryType == 2)
		{
			library.sortByAuthorDescending();
		}
		else if (categoryType == 3)
		{
			library.sortByRatingDescending();
		}
	}
	std::cout << library;
}

void CommandExecuter::executeFind()
{
	std::cout << "Welcome to the find function :D" << std::endl;
	std::cout << "What category do you want to search for a book by: ";
	std::cout << "Press 1 if you want it to be the title, 2 if you want to search by author, 3 for part of the summary and 4 if you want to search by ISBN: ";
	int commandType = 0;
	do {
		std::cin >> commandType;
		if (commandType < 1 || commandType>4) std::cout << "Make sure you press a number between 1 and 4. Try again: " << std::endl;
	} while (commandType < 1 || commandType>4);
	if (commandType == 1)
	{
		findBookByTitle();
	}
	else if (commandType == 2)
	{
		findBookByAuthor();
	}
	else if (commandType == 3)
	{
		findBookBySummary();
	}
	else
	{
		findBookByISBN();
	}
}

void CommandExecuter::findBookByTitle()
{
	char* title = new char[101];
	std::cout << "Please enter the title of the book you want to find: ";
	std::cin.ignore(1, '/n');
	std::cin.getline(title, 100);
	for (int i = 0; i < library.getCurrSize(); i++)
	{
		if (strcmp(title, library[i].getTitle()) == 0)
		{
			library[i].print();
		}
	}
	delete[] title;
	title = nullptr;
}

void CommandExecuter::findBookByAuthor()
{
	char* author = new char[101];
	std::cout << "Please enter the author of the book you want to find: ";
	std::cin.ignore(1, '/n');
	std::cin.getline(author, 100);
	for (int i = 0; i < library.getCurrSize(); i++)
	{
		if (strcmp(author, library[i].getAuthor()) == 0)
		{
			library[i].print();
			break;
		}
	}
	delete[] author;
	author = nullptr;
}

void CommandExecuter::findBookBySummary()
{
	char* summary = new char[512];
	std::cout << "Please enter part of the summary of the book you want to find: ";
	std::cin.ignore(1, '/n');
	std::cin.getline(summary, 511);
	char* str = nullptr;
	for (int i = 0; i < library.getCurrSize(); i++)
	{
		str = std::strstr(summary, library[i].getSummary());
		if (str != nullptr)
		{
			library[i].print();
		}
	}
	delete str;
	delete[] summary;
	summary = nullptr;
}

void CommandExecuter::findBookByISBN()
{
	int ISBN = 0;
	std::cout << "Please enter the ISBN of the book you want to find: ";
	std::cin >> ISBN;
	for (int i = 0; i < library.getCurrSize(); i++)
	{
		if (library[i].getISBN() == ISBN)
		{
			library[i].print();
		}
	}
}

void CommandExecuter::addBook()
{
	char password[] = "pass";
	char passInput[20] = "";
	int wrongTries;
	//the administrator's password is "pass" :D
	wrongTries = 3;
	std::cout << "This is a command that needs authorization. Please enter the administrator's password: ";
	std::cin.getline(passInput, 19); //????????????????????????
	while (strcmp(passInput, "pass") != 0)
	{
		wrongTries--;
		if (wrongTries == 0) {
			std::cout << "Sorry, you have entered a wrong password 3 consecutive times and access to the command \"add\" was denied. Try again later!" << std::endl;
			break;
		}
		std::cout << "Wrong password. You have " << wrongTries << " tries left. Please enter the administator's password: ";
		std::cin.getline(passInput, 19);
	}

	if (wrongTries != 0) {
		Book newBook;
		char* temp = new char[512];
		double rating = 0;
		int ISBN = 0;
		std::cout << "Please enter the name of the book: ";
		std::cin.getline(temp, 100);
		newBook.setTitle(temp);
		std::cout << "Please enter the author of the book: ";
		std::cin.getline(temp, 100);
		newBook.setAuthor(temp);
		std::cout << "Please enter the name of the text file of the book: ";
		std::cin.getline(temp, 100);
		newBook.setTextFile(temp);
		std::cout << "Please enter the summary of the book: ";
		std::cin.getline(temp, 511);
		newBook.setSummary(temp);
		do
		{
			std::cout << "Now, please enter the rating of the book: ";
			std::cin >> rating;
			if (rating < 0 || rating>10) std::cout << "Be careful, the rating can be a number between 1 and 10!" << std::endl;
		} while (rating <= 0 || rating > 10);
		newBook.setRating(rating);
		do {
			std::cout << "Please enter the ISBN of the book: ";
			std::cin >> ISBN;
		} while (ISBN <= 0);
		newBook.setISBN(ISBN);
		library.add(newBook);
		delete[] temp;
		temp = nullptr;
	}
}

void CommandExecuter::removeBook()
{
	char password[] = "pass";
	char passInput[20] = "";
	int wrongTries;
	wrongTries = 3;
	std::cout << "This is a command that needs authorization. Please enter the administrator's password: ";
	std::cin.getline(passInput, 19);
	while (strcmp(passInput, "pass") != 0)
	{
		wrongTries--;
		if (wrongTries == 0) {
			std::cout << "Sorry, you have entered a wrong password 3 consecutive times and access to the command \"add\" was denied. Try again later!" << std::endl;
			break;
		}
		std::cout << "Wrong password. You have " << wrongTries << " tries left. Please enter the administator's password: ";
		std::cin.getline(passInput, 19);
	}
	if (wrongTries != 0) {
		std::cout << "Please enter the title of the book you want removed: ";
		char* title = new char[101];
		std::cin.getline(title, 100);
		library.remove(title);
		delete[] title;
		title = nullptr;
	}
}

void CommandExecuter::EndProgram()
{
	std::cout << "Thank you for using the library. Looking forward to seeing you again!" << std::endl;
	return;
}


