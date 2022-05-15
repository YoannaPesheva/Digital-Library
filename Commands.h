#pragma once

//the class does not have any fields, so the functions in it need to be static
class Commands {

public:
	static void printCommands();
	static int getCommand(const char* command);
};




