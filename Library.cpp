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

int Library::getBookIndex(const char* title)
{
	for (int i = 0; i < this->currSize; i++)
	{
		if (strcmp(title, this->library[i].getTitle()) == 0)
		{
			return i;
		}
	}
	return -1;
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


void Library::add(const Book& book)
{
	if (currSize == capacity) reallocate();
	library[currSize++] = book;
	
}


void Library::remove(char* title)
{
	int index = getBookIndex(title);
	if (index == -1)
	{
		std::cout << "The book you wanted to remove cannot be found!" << std::endl;
	}
	else {
		for (int i = 0; i < currSize-1; i++)
		{
			std::swap(library[i], library[i + 1]);
		}
		currSize--;
	}


}

void Library::sortByTitleAscending()
{

}

void Library::sortByAuthorAscending()
{

}

void Library::sortByRatingAscending()
{
	for (int i = 0; i < currSize; i++)
	{
		for (int j = 0; j < currSize - i - 1; j++)
			if (library[j].getRating() > library[j + 1].getRating())
				std::swap(library[j], library[j + 1]);
	}
}


Library::~Library()
{
	delete[] library;
}
