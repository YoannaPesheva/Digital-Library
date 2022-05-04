#pragma once
class Books {
private:
	char* author;
	char* title;
	char* nameOfATextFile;
	char* summary; //a short text 
	double rating; //9.5
	int ISBN; //long int?
	void copyTxt(char*& destination, const char* source);
public:
	//Dynamically allocated memory =>
	Books(); //default constructor
	Books(const Books& other); //copy constructor
	Books& operator=(const Books& other); //=
	~Books(); //destructor
};