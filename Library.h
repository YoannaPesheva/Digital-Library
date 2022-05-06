#pragma once
#include "Book.h";

class Library {
private:
	Book* library;
	size_t capacity;
	size_t currSize;
	bool reallocate();

public:
	Library();
	Library(const Library& other);
	Library& operator =(const Library& other);
	~Library();
};
