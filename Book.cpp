#define _CRT_SECURE_NO_WARNINGS //because of the strcpy() warning

#include "Book.h"
#include<iostream>

//helper functions
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



//big 4
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



//Setters
void Book::setTitle(const char* title)
{
	delete[] this->title;
	this->copyTxt(this->title, title);
}
void Book::setAuthor(const char* author)
{
	delete[] this->author;
	this->copyTxt(this->author, author);
}
void Book::setTextFile(const char* textFile)
{
	delete[] this->nameOfATextFile;
	this->copyTxt(this->nameOfATextFile, textFile);
}
void Book::setSummary(const char* summary)
{
	delete[] this->summary;
	this->copyTxt(this->summary, summary);
}
void Book::setRating(double rating) { this->rating = rating; }
void Book::setISBN(int ISBN) { this->ISBN = ISBN; }



//print function
void Book::print()
{
		std::cout << this->title << std::endl;
		std::cout << this->author << std::endl;
		std::cout << this->nameOfATextFile << std::endl;
		std::cout << this->summary << std::endl;
		std::cout << this->rating << std::endl;
		std::cout << this->ISBN << std::endl;
}
