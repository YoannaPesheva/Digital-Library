#pragma once
class Book {
private:
	char* author;
	char* title;
	char* nameOfATextFile;
	char* summary; //a short text 
	double rating; // for ex. 9.40
	int ISBN;
	void copyTxt(char*& destination, const char* source);
	void copyAll(const Book& other);
	void deleteAll();


public:
	//Dynamically allocated memory =>
	Book(); //default constructor
	Book(const Book& other); //copy constructor
	Book& operator=(const Book& other); //=
	~Book(); //destructor

	//setters
	void setTitle(const char* title);
	void setAuthor(const char* author);
	void setTextFile(const char* textFile);
	void setSummary(const char* summary);
	void setRating(double rating);
	void setISBN(int ISBN);

	//getters
	const char* getTitle() const { return this->title; }
	const char* getAuthor() const { return this->author; }
	const char* getTextFile() const { return this->nameOfATextFile; }
	const char* getSummary() const { return this->summary; }
	const double  getRating() const { return this->rating; }
	const int getISBN() const { return this->ISBN; }

	//print function
	void print();

};