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

	void setTitle(const char* title)
	{
		delete[] this->title;
		this->copyTxt(this->title, title);
	}
	void setAuthor(const char* author)
	{
		delete[] this->author;
		this->copyTxt(this->author, author);
	}
	void setTextFile(const char* textFile)
	{
		delete[] this->nameOfATextFile;
		this->copyTxt(this->nameOfATextFile, textFile);
	}
	void setSummary(const char* summary)
	{
		delete[] this->summary;
		this->copyTxt(this->summary, summary);
	}
	void setRating(double rating)
	{
		this->rating = rating;
	}
	void setISBN(int ISBN)
	{
		this->ISBN = ISBN;
	}


	const char* getTitle() const { return this->title; }
	const char* getAuthor() const { return this->author; }
	const char* getTextFile() const { return this->nameOfATextFile; }
	const char* getSummary() const { return this->summary; }
	const double  getRating() const { return this->rating; }
	const int getISBN() const { return this->ISBN; }


	void print()
	{
		std::cout << this->title << std::endl;
		std::cout << this->author<<std::endl;
		std::cout << this->nameOfATextFile << std::endl;
		std::cout << this->summary << std::endl;
		std::cout << this->rating << std::endl;
		std::cout << this->ISBN << std::endl;
	}


	friend std::istream& operator >> (std::istream& in, Book& book)
	{
		char buffer[1025] = { '\0', };
		in >> buffer;
		in >> book.title;
		in >> book.author;
		in >> book.nameOfATextFile;
		in >> book.summary;
		in >> book.rating;
		in >> book.ISBN;

		return in;
	}
};