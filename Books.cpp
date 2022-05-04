#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
#include "Books.h"

void Books::copyTxt(char*& destination, const char* source)
{
	destination = new(std::nothrow) char[strlen(source) + 1];
	strcpy(destination, source);
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
	ISBN = other.ISBN;
	rating = other.rating;
	strcpy(author, other.author);
	strcpy(title, other.title);
	strcpy(nameOfATextFile, other.nameOfATextFile);
	strcpy(summary, other.summary);
}

Books& Books::operator=(const Books& other)
{

	return *this;
}

Books::~Books()
{
	delete[] author;
	delete[] title;
	delete[] nameOfATextFile;
	delete[] summary;
}
