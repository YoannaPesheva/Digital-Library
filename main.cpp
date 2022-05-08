#include<iostream>
#include<fstream>
#include<cstring>
#include "Commands.h"
#include "Library.h"
#include "Book.h"


int main()
{
	Library library;
	char command[16];
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
				std::cout << "Please enter the name of the book: ";
				
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
				std::cout << "Success!";
				//addCommand;
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