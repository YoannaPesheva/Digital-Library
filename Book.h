#pragma once
class Book {
private:
	char* author;
	char* title;
	char* nameOfATextFile;
	char* summary; //a short text 
	double rating; //9.5
	int ISBN; //long int?
	void copyTxt(char*& destination, const char* source);
	void copyAll(const Book& other);
	void deleteAll();


public:
	//Dynamically allocated memory =>
	Book(); //default constructor
	Book(const Book& other); //copy constructor
	Book& operator=(const Book& other); //=
	~Book(); //destructor
};