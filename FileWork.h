#pragma once
#include<iostream>
#include<fstream>
#include "Library.h"

class FileWork
{
public:
	static void readBooksFromFile(Library& library);
	static void saveChanges(Library& library);

};

void FileWork::readBooksFromFile(Library& library)
{
	std::ifstream myFile("Library.txt", std::ios::in);
	if (!myFile.is_open())
	{
		std::cout << ";-;" << std::endl;
	}
	int propertyCount = 0;
	char* buffer = new char[100];
	Book* tempBook=new Book();
	bool isEmpty = myFile.peek() == EOF; //!!!!!!!!!!!
	if (!isEmpty)
	{
		while (!myFile.eof())
		{

			if (propertyCount == 0)
			{
				myFile.getline(buffer, 100);
				tempBook->setTitle(buffer);
				propertyCount++;
			}
			if (propertyCount == 1)
			{
				myFile.getline(buffer, 100);
				tempBook->setAuthor(buffer);
				propertyCount++;
			}
			if (propertyCount == 2)
			{
				myFile.getline(buffer, 100);
				tempBook->setTextFile(buffer);
				propertyCount++;
			}
			if (propertyCount == 3)
			{
				myFile.getline(buffer, 100);
				tempBook->setSummary(buffer);
				propertyCount++;
			}
			if (propertyCount == 4)
			{
				myFile.getline(buffer, 100);
				double rating = std::atof(buffer); //turns char arr into double
				tempBook->setRating(rating);
				propertyCount++;
			}
			if (propertyCount == 5)
			{
				myFile.getline(buffer, 100);
				int isbn = std::strtol(buffer, nullptr, 10); //turns char arr into int
				tempBook->setISBN(isbn);

				std::ofstream newFile(tempBook->getTextFile());
				newFile.close();

				propertyCount = 0;
				library.add(*tempBook);
				tempBook = new Book();
			}
		}
	}
}



void FileWork::saveChanges(Library& library)
{
	std::ofstream out("Library.txt", std::ios::out);
	out << library;
	out.close();
}