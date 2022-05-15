#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "CommandExecuter.h"
#include "Commands.h"


int main()
{
	CommandExecuter c;
	c.start();

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
			c.InvalidCommandMessage();
		}
		else if (commandCode == 1)
		{
			c.executeSort();
		}
		else if (commandCode == 2)
		{
			c.executeFind();
		}
		else if (commandCode == 3)
		{
			c.readContent();
		}
		else if (commandCode == 4)
		{
			c.addBook();
		}
		else if (commandCode == 5)
		{
			c.removeBook();
		}
		else if (commandCode == 6)
		{
			Commands::printCommands();
		}
		if (commandCode == -1)
		{
			c.EndProgram();
			break;
		}
		std::cout << "What would you like to do: ";
		std::cin.getline(command, 16);

	} while (commandCode != -1);

	return 0;
}
