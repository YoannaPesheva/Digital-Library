#pragma once
#include<iostream>
#include "Library.h"
#include "Commands.h"

class CommandExecuter 
{
private:
	Library library;

public:
	//start the program
	void  start();

	// commands
	void InvalidCommandMessage();

	void executeSort();

	void executeFind();
	void findBookByTitle();
	void findBookByAuthor();
	void findBookBySummary();
	void findBookByISBN();

	void addBook();

	void removeBook();

	void EndProgram();

};
