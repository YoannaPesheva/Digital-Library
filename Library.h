#pragma once

#include "Book.h"

class Library {
private:
	Book* library;
	int capacity;
	int currSize;
	//help functions
	bool reallocate(); //reallocates more memory when the current size of the array reaches the overall capacity
	void copyAll(const Library& other);
	int getBookIndex(const char* title); //compares a title with all the books in the arr and if it finds it - returns the index of the book

public:
	Library(); //default constructor
	Library(const Library& other); //copy constructor
	Library& operator =(const Library& other); //=
	~Library();//destructor

	//redefining the operator[]
	Book& operator [](int index) { return library[index]; }
	const Book operator[](int index) const { return library[index]; }

	//get function for the current size
	const int getCurrSize() const {
		return currSize;
	}

	//get function for the index of the book that has the same title as the input title
	int getIndexOfBook(char* title)
	{
		return getBookIndex(title);
	}

	//find and remove a book
	void add(const Book& book);
	void remove(char* title);

	//sort functions
	void sortByTitleAscending();
	void sortByAuthorAscending();
	void sortByRatingAscending();
	void sortByTitleDescending();
	void sortByAuthorDescending();
	void sortByRatingDescending();
	void printSorted();

	//<<
	friend std::ostream& operator<<(std::ostream& out, const Library& library);
	
	

};