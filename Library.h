#pragma once
#include "Book.h";

class Library {
private:
	Book* library;
	int capacity;
	int currSize;
	bool reallocate();
	void copyAll(const Library& other);
	int getBookIndex(const char* title);

public:
	Library(); //default constructor
	Library(const Library& other); //copy constructor
	Library& operator =(const Library& other); //=
	~Library();//destructor

	Book& operator [](int index) { return library[index]; }
	const Book operator[](int ind) const { return library[ind]; }

	const int getCurrSize() const {
		return currSize;
	}

	void add(const Book& book);
	void remove(char* title);
	int getIndexOfBook(char* title)
	{
		return getBookIndex(title);
	}

	void sortByTitleAscending();
	void sortByAuthorAscending();
	void sortByRatingAscending();
	void sortByTitleDescending();
	void sortByAuthorDescending();
	void sortByRatingDescending();

	friend std::ostream& operator<<(std::ostream& out, const Library& library);
	friend std::ostream& operator>>(std::istream& in, Library& library);
	
	

};