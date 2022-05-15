#include<iostream>
#include "Library.h"

//the helping functions
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

//get the index
int Library::getBookIndex(const char* title)
{
	for (int  i = 0; i < this->currSize; i++)
	{
		if (strcmp(title, this->library[i].getTitle()) == 0)
		{
			return i;
		}
	}
	return -1;
}


//big 4
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

Library::~Library()
{
	delete[] library;
}
//end of big 4

//add a book
void Library::add(const Book& book)
{
	if (currSize == capacity) reallocate();
	library[currSize++] = book;
	
}

//remove a book
void Library::remove(char* title)
{
	int index = getBookIndex(title);
	if (index == -1)
	{
		std::cout << "The book you wanted to remove cannot be found!" << std::endl;
	}
	else 
	{
		for (int i = index; i<currSize-1; i++)
		{
			std::swap(library[i], library[i+1]);
		}
		currSize--;
		std::cout << "Book removed successfully!" << std::endl;
	}


}

//sorting functions
void Library::sortByTitleAscending()
{
	for (int i = 0; i < currSize; i++)
	{
		for (int j = 0; j < currSize - i - 1; j++)
		{
			if (strcmp(library[j].getTitle(), library[j + 1].getTitle())>0)
			{
				std::swap(library[j], library[j + 1]);
			}
		}
	}
}

void Library::sortByAuthorAscending()
{
	for (int i = 0; i < currSize; i++)
	{
		for (int j = 0; j < currSize - i - 1; j++)
		{
			if (strcmp(library[j].getAuthor(), library[j + 1].getAuthor()) > 0)
			{
				std::swap(library[j], library[j + 1]);
			}
		}
	}
}

void Library::sortByRatingAscending()
{
	for (int i = 0; i < currSize; i++)
	{
		for (int j = 0; j < currSize - i - 1; j++)
		{
			if (library[j].getRating() > library[j + 1].getRating())
			{
				std::swap(library[j], library[j + 1]);
			}
		}
	}
}

void Library::sortByTitleDescending()
{
	for (int i = 0; i < currSize; i++)
	{
		for (int j = 0; j < currSize - i - 1; j++)
		{
			if (strcmp(library[j].getTitle(), library[j + 1].getTitle()) < 0)
			{
				std::swap(library[j], library[j + 1]);
			}
		}
	}
}

void Library::sortByAuthorDescending()
{
	for (int i = 0; i < currSize; i++)
	{
		for (int j = 0; j < currSize - i - 1; j++)
		{
			if (strcmp(library[j].getAuthor(), library[j + 1].getAuthor()) < 0)
			{
				std::swap(library[j], library[j + 1]);
			}
		}
	}
}


void Library::sortByRatingDescending()
{
	for (int i = 0; i < currSize; i++)
	{
		for (int j = 0; j < currSize - i - 1; j++)
			if (library[j].getRating() < library[j + 1].getRating())
				std::swap(library[j], library[j + 1]);
	}
}
//end of sorting functions

//printing the info after the sorting functions, because its specific
void Library::printSorted()
{
	int size = currSize;
	for (int i = 0; i < size-1; i++)
	{
		std::cout << library[i].getTitle() << std::endl;
		std::cout << library[i].getAuthor() << std::endl;
		std::cout << library[i].getISBN() << std::endl;
		std::cout << std::endl;
	}
		std::cout << library[size-1].getTitle() << std::endl;
		std::cout << library[size-1].getAuthor() << std::endl;
		std::cout << library[size-1].getISBN() << std::endl;
}

//<<
std::ostream& operator<<(std::ostream& out, const Library& library)
{
	int end = library.getCurrSize();
	for (int i = 0; i < end-1; i++)
	{
		out << library[i].getTitle() << std::endl;
		out << library[i].getAuthor() << std::endl;
		out << library[i].getTextFile() << std::endl;
		out << library[i].getSummary() << std::endl;
		out << library[i].getRating() << std::endl;
		out << library[i].getISBN() << std::endl;
	}
	out << library[end-1].getTitle() << std::endl;
	out << library[end-1].getAuthor() << std::endl;
	out << library[end-1].getTextFile() << std::endl;
	out << library[end-1].getSummary() << std::endl;
	out << library[end-1].getRating() << std::endl;
	out << library[end-1].getISBN();

	return out;
}

