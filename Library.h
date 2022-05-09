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
	Library();
	Library(const Library& other);
	Library& operator =(const Library& other);
	Book& operator [](int index) { return library[index]; }
	const Book operator[](int ind) const { return library[ind]; }
	void add(const Book& book);
	void remove(char* title);
	void sortByTitleAscending();
	void sortByAuthorAscending();
	void sortByRatingAscending();
	~Library();

	
	

};
