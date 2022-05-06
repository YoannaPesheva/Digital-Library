#pragma once
#include "Book.h";

class Library {
private:
	Book* library;
	int capacity;
	int currSize;
	bool reallocate();
	void copyAll(const Library& other);

public:
	Library();
	Library(const Library& other);
	Library& operator =(const Library& other);
	~Library();
};
