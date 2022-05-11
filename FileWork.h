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
	ifstream in;
	in.open("Library.txt");
	if (!in.is_open())
	{
		cout << "Something went wrong while opening the file. Please try later!" << endl;
		return;
	}
	Book tempBook;
	while (!in.eof())
	{
		char* buffer = new char[512];
		in.getline(buffer, 100);
		tempBook.setTitle(buffer);
		in.getline(buffer, 100);
		tempBook.setAuthor(buffer);
		in.getline(buffer, 100);
		tempBook.setTextFile(buffer);
		in.getline(buffer, 500);
		tempBook.setSummary(buffer);
		library.add(tempBook);
		delete[] buffer;
	}
	cout << library;
	in.close();

}

void FileWork::saveChanges()
{

}