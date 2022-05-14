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


	//friend std::istream& operator >>(std::istream& in, Book& book)
	//{
	//	in >> book.title;
	//	in >> book.author;
	//	in >> book.nameOfATextFile;
	//	in >> book.summary;
	//	in >> book.rating;
	//	in >> book.ISBN;
	//	return in;
	//}
	//friend std::ostream& operator<<(std::ostream& out, const Book& book)
	//{
	//	out << book.getTitle();
	//	out << book.getAuthor();
	//	out << book.getTextFile();
	//	out << book.getSummary();
	//	out << book.getRating();
	//	out << book.getISBN();
	//	return out;
	//	
	//}

};