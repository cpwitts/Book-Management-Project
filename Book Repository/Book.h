#pragma once
#ifndef BOOK_H
#define BOOK_H
#include <string>

class Book
{
	std::string title;
	std::string author;
	std::string isbn;
	bool available;
	Book* next;
	Book* prev;

public:
	std::string getTitle() const;
	void setTitle(std::string titleParam);
	std::string getAuthor() const;
	void setAuthor(std::string authorParam);
	std::string getIsbn() const;
	void setIsbn(std::string isbnParam);
	bool isAvailable() const;
	void setAvailable(bool availableParam);
	Book* getNext() const;
	void setNext(Book* nextParam);
	Book* getPrev() const;
	void setPrev(Book* prevParam);
	void printDetails() const;

	Book();
	Book(std::string titleParam, std::string authorParam, std::string isbnParam, bool availableParam);
};

#endif

