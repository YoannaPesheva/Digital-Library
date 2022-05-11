#pragma once
#include<iostream>
#include<fstream>
#include "Library.h"
using namespace std;

class FileWork
{
public:
	static void readBooksFromFile(Library& library);
	static void saveChanges();

};

void FileWork::readBooksFromFile(Library& library)
{
	ifstream in("Library.txt");
	if (!in.is_open())
	{
		std::cout << "Error occured while trying to open the file!" << std::endl;
	}
	in.close();
}


void FileWork::saveChanges()
{

}