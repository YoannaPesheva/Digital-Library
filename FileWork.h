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
	int propertyCounter = 0;
	char* buffer = new char[512];
	double rating = 0;
	int isbn = 0;
	std::ifstream in("Library.txt", std::ios::in);
	if (!in.is_open())
	{
		std::cout << "Error occured while trying to open the file!" << std::endl;
	}
	Book* tempBook = new Book();
	while (!in.eof())
	{
		switch (propertyCounter)
		{
		case 0:
			in.getline(buffer, 100);
			tempBook->setTitle(buffer);
			propertyCounter++;
			break;
		case 1:
			in.getline(buffer, 100);
			tempBook->setAuthor(buffer);
			propertyCounter++;
			break;
		case 2:
			in.getline(buffer, 100);
			tempBook->setTextFile(buffer);
			propertyCounter++;
			break;
		case 3:
			in.getline(buffer, 500);
			tempBook->setSummary(buffer);
			propertyCounter++;
			break;
		case 4:
			in >> rating;
			tempBook->setRating(rating);
			propertyCounter++;
			break;
		case 5:
			in >> isbn;
			tempBook->setISBN(isbn);
			propertyCounter++;
			break;
		default:
			in.getline(buffer,100);
			propertyCounter = 0;
			library.add(*tempBook);
			std::ofstream newFile(tempBook->getTextFile());
			newFile.close();
			break;
		}
	}
	delete tempBook;
	tempBook = nullptr;
	delete[] buffer;
	buffer = nullptr;
	in.close();
}


void FileWork::saveChanges(Library& library)
{
	std::ofstream out;
	out.open("Library.txt", std::ios::out);
	out << library;
	out.close();
}