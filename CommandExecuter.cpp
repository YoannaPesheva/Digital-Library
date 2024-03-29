#include "CommandExecuter.h"
#include "FileWork.h"
#include "Library.h"

#include<conio.h>
#include<iostream>
#include<fstream>

const char PASSWORD[] = "pass";

//helping functions
bool isPassCorrect(const char* password)
{
	char passInput[100] = "";
	int wrongTries;
	wrongTries = 3;
	std::cout << "This is a command that needs authorization. Please enter the administrator's password: ";
	int i = 0;
	char ch = _getch();
	while (ch != 13)
	{
		passInput[i++] = ch;
		std::cout << "*";
		ch = _getch();
	}
	while (strcmp(passInput, password) != 0)
	{
		wrongTries--;
		if (wrongTries == 0) {
			std::cout << std::endl << "Sorry, you have entered a wrong password 3 consecutive times. ";
			return false;
		}
		std::cout << std::endl << "Wrong password. You have " << wrongTries << " tries left. Please enter the administator's password: ";
		i = 0;
		ch = _getch();
		while (ch != 13)
		{
			passInput[i++] = ch;
			std::cout << "*";
			ch = _getch();
		}
	}
	return true;
}

int isSameArr(char* firstArr, const char* secondArr)
{
	int sizeFirst = strlen(firstArr);
	int sizeSecond = strlen(secondArr);
	if (sizeFirst == sizeSecond)
	{
		int j = 0;
		while (j < sizeFirst)
		{
			if ((firstArr[j] > 'A' && firstArr[j] < 'Z') && (firstArr[j] != secondArr[j]))
			{
				if (firstArr[j] + 32 != secondArr[j])
				{
					break;
				}
			}
			else if ((firstArr[j] > 'a' && firstArr[j] < 'z') && (firstArr[j] != secondArr[j]))
			{
				if (firstArr[j] - 32 != secondArr[j])
				{
					break;
				}
			}
			j++;
		}
		if (j == sizeFirst)
		{
			return true;
		}
	}
	return false;
}



//CommandExecuter functions

//start the program
void CommandExecuter::start()
{
	FileWork::readBooksFromFile(library);
}

//invalid input
void CommandExecuter::InvalidCommandMessage()
{
	std::cout << "Invalid command, please try again!" << std::endl;
}

//sort function
void CommandExecuter::executeSort()
{
	std::cout << "Welcome to the sort command :D" << std::endl;
	std::cout << "By what category do you want to sort the books: " << std::endl;
	std::cout << "Please press 1 if you want them sorted by title, 2 for author and 3 for rating: ";
	int categoryType = 0;
	do {
		std::cin >> categoryType;
		if (categoryType < 1 || categoryType>3) std::cout << "Make sure you enter a number between 1 and 3. Try again: ";
	} while (categoryType < 1 || categoryType>3);

	std::cout << "Do you want the books to be sorted in ascending order(please press 1 for that) or descending one(please press 2): ";
	int orderType = 0;
	do {
		std::cin >> orderType;
		if (orderType < 1 || orderType >2) std::cout << "Make sure you enter a number between 1 and 2. Try again: ";
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
	library.printSorted();
	std::cin.ignore(10, '\n');
}
//end of sort functions


//find functions
void CommandExecuter::executeFind()
{
	std::cout << "Welcome to the find function :D" << std::endl;
	std::cout << "What category do you want to search for a book by: ";
	std::cout << "Press 1 if you want it to be the title, 2 if you want to search by author, 3 for part of the summary and 4 if you want to search by ISBN: ";
	int commandType = 0;
	do {
		std::cin >> commandType;
		if (commandType < 1 || commandType>4) std::cout << "Make sure you enter a number between 1 and 4. Try again: " << std::endl;
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
	char title[101] = "";
	std::cout << "Please enter the title of the book you want to find: ";
	std::cin.ignore(1, '/n');
	std::cin.getline(title, 100);
	bool isBookFound = false;
	for (int i = 0; i < library.getCurrSize(); i++)
	{
		if (isSameArr(title, library[i].getTitle()))
		{
			std::cout << "We found your book!" << std::endl;
			library[i].print();
			isBookFound = true;
			break;
		}
	}
	if (!isBookFound)
	{
		std::cout << "Sorry, we couldn\'t find your book!" << std::endl;
	}
}

void CommandExecuter::findBookByAuthor()
{
	char author[101]="";
	std::cout << "Please enter the author of the book you want to find: ";
	std::cin.ignore(1, '/n');
	std::cin.getline(author, 100);
	bool isBookFound = false;
	for (int i = 0; i < library.getCurrSize(); i++)
	{
		if (isSameArr(author, library[i].getAuthor()))
		{
			std::cout << "We found your book!" << std::endl;
			library[i].print();
			isBookFound = true;
			break;
		}
	}
	if (!isBookFound)
	{
		std::cout << "Sorry, we couldn\'t find your book!" << std::endl;
	}
}

void CommandExecuter::findBookBySummary()
{
	char summary[512]="";
	bool isFound = false;
	std::cout << "Please enter part of the summary of the book you want to find: ";
	std::cin.ignore(1, '/n');
	std::cin.getline(summary, 511);
	for (int i = 0; i < library.getCurrSize(); i++)
	{
		if ((strstr(library[i].getSummary(), summary)) != nullptr)
		{
			isFound = true;
			library[i].print();
			break;
		}
	}
	if (isFound == false)
	{
		std::cout << "Sorry, we couldn\'t find your book!" << std::endl;
	}
}

void CommandExecuter::findBookByISBN()
{
	int ISBN = 0;
	bool isFound = false;
	std::cout << "Please enter the ISBN of the book you want to find: ";
	std::cin >> ISBN;
	for (int i = 0; i < library.getCurrSize(); i++)
	{
		if (library[i].getISBN() == ISBN)
		{
			isFound = true;
			library[i].print();
			break;
		}
	}
	if (isFound == false)
		{
			std::cout << "Sorry, we couldn\'t find your book!" << std::endl;
		}
		std::cin.ignore(10, '\n');
}
//end of find functions


//read lines/sentences
void CommandExecuter::readContent()
{
	char title[101]="";
	char buffer[512]="";

	std::cout << "Please enter the title of the book which content you would like to see: ";
	std::cin.getline(title, 100);

	int i = library.getIndexOfBook(title);
	if (i == -1)
	{
		std::cout << "Sorry, we couldn\'t find your book!" << std::endl;
		return;
	}

	std::ifstream in;
	in.open(library[i].getTextFile(), std::ios::in);
	if (!in.is_open())
	{
		std::cout << "The file couldn't be loaded!" << std::endl;
		return;
	}

	std::cout << "Please press 1 if you want to read the content in mode \"read pages\" or press 2 for the \"read sentences\" mode: ";
	do {
		std::cin >> i;
		if (i < 1 || i>2) std::cout << "Make sure you enter a number between 1 and 2. Try again: " << std::endl;
	} while (i < 1 || i>2);


	if (i == 1)
	{
		std::cout << "How many pages (lines) would you like to read: " << std::endl;
		int lines = 0;
		do {
			std::cin >> lines;
			if(lines<0) std::cout<< "Make sure you enter a positive number!" << std::endl;
		} while (lines < 0);
		std::cout << "This is the extract:" << std::endl;
		for (int j = 0; j < lines && !in.eof(); j++)
		{
			in.getline(buffer, 511);
			std::cout << buffer << std::endl;
		}
	}
	// i am not sure i understood this correctly, but the function shows on the screen
	//a sentence and stops when it find the end of it.
	else
	{
		char j = '\0';
		std::cout << "This is the extract:" << std::endl;
		while (j != '.' && j != '!' && j != '?')
		{
			in.get(j);
			std::cout << j;
		}
		std::cout<<std::endl;
	}

	in.close();
	std::cin.ignore(10, '\n');
}

//add a book
void CommandExecuter::addBook()
{

	if (isPassCorrect(PASSWORD)) {
		Book newBook;
		char temp[512]="";
		double rating = 0;
		int ISBN = 0;

		std::cout << std::endl << "Please enter the name of the book : ";
		std::cin.getline(temp, 100);
		newBook.setTitle(temp);
		for (int i = 0; i < library.getCurrSize(); i++)
		{
			if (strcmp(library[i].getTitle(), temp) == 0)
			{
				std::cout << "This book is already in the system!" << std::endl;
				return;
			}
		}

		std::cout << "Please enter the author of the book: ";
		std::cin.getline(temp, 100);
		newBook.setAuthor(temp);

		std::cout << "Please enter the name of the text file of the book: ";
		std::cin.getline(temp, 100);
		for (int i = 0; i < library.getCurrSize(); i++)
		{
			if (strcmp(library[i].getTextFile(), temp) == 0)
			{
				std::cout << "This file already exists! Please enter another name for the file: ";
				std::cin.getline(temp, 100);
				i = -1;
			}
		}
		newBook.setTextFile(temp);

		std::ofstream newFile(newBook.getTextFile());
		if (!newFile.is_open())
		{
			std::cout << "Something went wrong with the file!" << std::endl;
			return;
		}
		newFile.close();

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
		std::cout << "The book was added successfully!" << std::endl;

		std::cin.ignore(10, '\n');
	}
	else
	{
		std::cout << "Access to the command \"add\" was denied. Try again later!" << std::endl;
	}
}

//remove a book
void CommandExecuter::removeBook()
{
	if (isPassCorrect(PASSWORD))
	{
		std::cout << std::endl << "Please enter the title of the book you want removed: ";
		char title[101] = "";
		std::cin.getline(title, 100);
		int j = library.getIndexOfBook(title);
		if (j != -1)
		{
			std::cout << "Do you want the file where the content of the book is stored to be deleted as well? (please press 1 if you do and 2 if you do not want such thing to be done: ";
			int removeFile = 0;
			std::cin >> removeFile;
			if (removeFile == 1)
			{
				int result = remove(library[j].getTextFile());
				if (result == 0)
				{
					std::cout << "File deleted successfully!" << std::endl;
				}
				else
				{
					std::cout << "An error occured while deleting the file!" << std::endl;
					return;
				}
				library.remove(title);
				std::cin.ignore(10, '\n');
			}
			else {
				library.remove(title);
				std::cin.ignore(10, '\n');
			}
		}
		else
		{
			std::cout << "Sorry, we couldn\'t find your book!" << std::endl;
		}
	}
	else
	{
		std::cout << "Access to the command \"remove\" was denied. Try again later!" << std::endl;
	}
}

//end the program and save the changes
void CommandExecuter::EndProgram()
{
	FileWork::saveChanges(library);
	std::cout << "Thank you for using the library. Looking forward to seeing you again!" << std::endl;
	return;
}

