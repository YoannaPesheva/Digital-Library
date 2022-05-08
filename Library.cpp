#include<iostream>
#include "Library.h"

bool Library::reallocate()
{
	capacity *= 2;
	Book* temporary = new Book[capacity];
	if (temporary == nullptr)
	{
		std::cout << "There was a problem allocating the needed memory!" << std::endl;
		return false;
	}
	for (int i = 0; i < currSize; i++) temporary[i] = library[i];
	delete[] library;
	library = temporary;
	return true;
}

void Library::copyAll(const Library& other)
{
	capacity = other.capacity;
	currSize = other.currSize;
	library = new Book[capacity];
	for (int i = 0; i < currSize; i++)
	{
		library[i] = other.library[i];
	}

}

Library::Library()
{
	capacity = 16;
	currSize = 0;
	library = new Book[capacity];
}

Library::Library(const Library& other)
{
	copyAll(other);
}

Library& Library::operator=(const Library& other)
{
	if (this != &other)
	{
		copyAll(other);
	}
	return *this;
}


Library& Library::add(const Book& book)
{
	if (currSize == capacity) reallocate();
	library[currSize++] = book;
	return *this;
}

Library::~Library()
{
	delete[] library;
}
