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
	//int propertyCounter = 0;
	//char* title = new char[100];
	//char* author = new char[100];
	//char* textFile = new char[100];
	//char* summary= new char[512];
	//double rating = 0;
	//int isbn = 0;
	//std::ifstream in("Library.txt", std::ios::in);
	//if (!in.is_open())
	//{
	//	std::cout << "Error occured while trying to open the file!" << std::endl;
	//}
	//Book* tempBook = new Book();
	//while (!in.eof())
	//{
	//	switch (propertyCounter)
	//	{
	//	case 0:
	//		in.getline(title, 100);
	//		tempBook->setTitle(title);
	//		propertyCounter++;
	//		break;
	//	case 1:
	//		in.getline(author, 100);
	//		tempBook->setAuthor(author);
	//		propertyCounter++;
	//		break;
	//	case 2:
	//		in.getline(textFile, 100);
	//		tempBook->setTextFile(textFile);
	//		propertyCounter++;
	//		break;
	//	case 3:
	//		in.getline(summary, 500);
	//		tempBook->setSummary(summary);
	//		propertyCounter++;
	//		break;
	//	case 4:
	//		in >> rating;
	//		tempBook->setRating(rating);
	//		propertyCounter++;
	//		break;
	//	case 5:
	//		in >> isbn;
	//		tempBook->setISBN(isbn);
	//		propertyCounter++;
	//		break;
	//	default:
	//		propertyCounter = 0;
	//		library.add(*tempBook);
	//		std::ofstream newFile(tempBook->getTextFile());
	//		newFile.close();
	//		break;
	//	}
	//}

	//delete[] title;
	//title = nullptr;
	//in.close();










	std::ifstream myFile("Library.txt", std::ios::in);
	if (!myFile.is_open())
	{
		std::cout << ";-;" << std::endl;
	}
	int propertyCount = 0;
	char* buffer = new char[100];
	Book* tempBook=new Book();
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
			int isbn = std::strtol(buffer, nullptr, 10);
			tempBook->setISBN(isbn);

			std::ofstream newFile(tempBook->getTextFile());
			newFile.close();

			propertyCount = 0;
			library.add(*tempBook);
			tempBook = new Book();
		}
	}
}



void FileWork::saveChanges(Library& library)
{
	std::ofstream out("Library.txt", std::ios::out);
	out << library;
	out.close();
}