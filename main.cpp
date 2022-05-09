#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstring>
#include "Commands.h"
#include "Library.h"
#include "Book.h"


int main()
{
	Library library;
	char command[16]="0";
	int commandCode;
	char password[] = "pass";
	char passInput[20]="";
	int wrongTries;
	Commands::printCommands();
	do
	{
		std::cout << "What would you like to do: ";
		std::cin.getline(command, 16);
		commandCode = Commands::getCommand(command);
		if (commandCode == 0) 
		{ 
			std::cout << "Invalid command, please try again!" << std::endl;
		}
		else if (commandCode == 1) 
		{
			std::cout << "Welcome to the sort command :D" << std::endl;
			std::cout << "By what category do you want to sort the books: " << std::endl;
			std::cout << "Please press 1 if you want them sorted by title, 2 for author and 3 for rating: ";
			int categoryType = 0; 
			do {
				std::cin >> categoryType;
				if (categoryType < 1 || categoryType>3) std::cout << "Make sure you press a number between 1 and 3. Try again: " << std::endl;
			} while (categoryType<1 || categoryType>3);
		
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
				if (categoryType == 1) {}
				else if (categoryType == 2) {}
				else if (categoryType == 3) {}
			}
		}
		else if (commandCode == 2) 
		{

		}
		else if (commandCode == 3) 
		{

		}
		else if (commandCode == 4) 
		{
			//the administrator's password is "pass" :D
			wrongTries = 3;
			std::cout << "This is a command that needs authorization. Please enter the administrator's password: ";
			std::cin.getline(passInput, 19); //????????????????????????
			while (strcmp(passInput, "pass")!=0)
			{
				wrongTries--;
				if (wrongTries == 0) {
					std::cout <<"Sorry, you have entered a wrong password 3 consecutive times and access to the command \"add\" was denied. Try again later!"<< std::endl;
					break;
				}
				std::cout << "Wrong password. You have " << wrongTries << " tries left. Please enter the administator's password: ";
				std::cin.getline(passInput, 19);
			}
			if (wrongTries != 0) {
				Book newBook;
				char* temp= new char[512];
				double rating = 0;
				int ISBN = 0;
				std::cout << "Please enter the name of the book: ";
				std::cin.getline(temp,100);
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
					if(rating<0 || rating>10) std::cout << "Be careful, the rating can be a number between 1 and 10!" << std::endl;
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
		else if (commandCode == 5) 
		{
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
				std::cout << "Please enter the title of the book you want removed: ";
				char* title = new char[101];
				std::cin.getline(title,100);
				library.remove(title);
				delete[] title;
				title = nullptr;
			}
		}
	} while (commandCode != -1);
		if (commandCode == -1)
		{
			std::cout << "Thank you for using the library. Looking forward to seeing you again!" << std::endl;
			return 0;
		}
		return 0;


	/*ofstream out("trying.txt");
	if (out.is_open())
		out << "Is it working?" << endl;
	else out << "Apparently not" << endl;
	out.close();

	ifstream in;
	string text = "";
	in.open("trying.txt");
	if (in.is_open())
	{
		while (getline(in, text))
		{
			cout << text;
		}
	}
	in.close();*/

}