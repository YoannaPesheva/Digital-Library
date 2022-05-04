#define _CRT_SECURE_NO_WARNINGS //because of the strcpy() warning
#include<iostream>
#include "Book.h"

void Book::copyTxt(char*& destination, const char* source)
{
	destination = new(std::nothrow) char[strlen(source) + 1];
	strcpy(destination, source);
}

void Book::copyAll(const Book& other)
{
	ISBN = other.ISBN;
	rating = other.rating;
	copyTxt(author, other.author);
	copyTxt(title, other.title);
	copyTxt(nameOfATextFile, other.nameOfATextFile);
	copyTxt(summary, other.summary);
}

void Book::deleteAll()
{
	delete[] author;
	delete[] title;
	delete[] nameOfATextFile;
	delete[] summary;
}

Book::Book()
{
	author = nullptr;
	title = nullptr;
	nameOfATextFile = nullptr;
	summary = nullptr;
	ISBN = -1;
	rating = -1; //needs to be between 0 and 10 !!!
}

Book::Book(const Book& other)
{
	copyAll(other);
}

Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		deleteAll();
		copyAll(other);

	}
	return *this;
}

Book::~Book()
{
	deleteAll();
}
