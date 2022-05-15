#pragma once
#include "Library.h"

#include<iostream>
#include<fstream>

class FileWork
{
public:
	static void readBooksFromFile(Library& library);
	static void saveChanges(Library& library);

};


//read books from the file
void FileWork::readBooksFromFile(Library& library)
{
	std::ifstream myFile("Library.txt", std::ios::in);
	if (!myFile.is_open())
	{
		std::cout << "There was an error while trying to open the file!" << std::endl;
	}
	int propertyCount = 0;
	char* buffer = new char[100];
	Book* tempBook = new Book();
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

				if (!std::ifstream(tempBook->getTextFile()))
				{
					std::ofstream newFile(tempBook->getTextFile());
					newFile.close();
				}

				propertyCount = 0;
				library.add(*tempBook);
				tempBook = new Book();
			}
		}
	}
}


//save the changes
void FileWork::saveChanges(Library& library)
{
	std::ofstream out("Library.txt", std::ios::out);
	out << library;
	out.close();
}