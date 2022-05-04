#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Books.h"

void Books::copyTxt(char*& destination, const char* source)
{
	destination = new(std::nothrow) char[strlen(source) + 1];
	strcpy(destination, source);
}

void Books::copyAll(const Books& other)
{
	ISBN = other.ISBN;
	rating = other.rating;
	copyTxt(author, other.author);
	copyTxt(title, other.title);
	copyTxt(nameOfATextFile, other.nameOfATextFile);
	copyTxt(summary, other.summary);
}

void Books::deleteAll()
{
	delete[] author;
	delete[] title;
	delete[] nameOfATextFile;
	delete[] summary;
}

Books::Books()
{
	author = nullptr;
	title = nullptr;
	nameOfATextFile = nullptr;
	summary = nullptr;
	ISBN = -1;
	rating = -1; //needs to be between 0 and 10 !!!
}

Books::Books(const Books& other)
{
	copyAll(other);
}

Books& Books::operator=(const Books& other)
{
	if (this != &other)
	{
		deleteAll();
		copyAll(other);

	}
	return *this;
}

Books::~Books()
{
	deleteAll();
}
