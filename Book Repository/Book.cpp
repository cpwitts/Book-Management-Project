#include "Book.h"
#include <iostream>

Book::Book()
{
	title = "";
	author = "";
	isbn = "";
	available = true;
	setNext(NULL);
	setPrev(NULL);
}

Book::Book(std::string titleParam, std::string authorParam, std::string isbnParam, bool availableParam)
{
	title = titleParam;
	author = authorParam;
	isbn = isbnParam;
	available = availableParam;
	setNext(NULL);
	setPrev(NULL);
}

std::string Book::getTitle() const
{
	return title;
}

void Book::setTitle(std::string titleParam)
{
	title = titleParam;
}

std::string Book::getAuthor() const
{
	return author;
}

void Book::setAuthor(std::string authorParam)
{
	author = authorParam;
}

std::string Book::getIsbn() const
{
	return isbn;
}

void Book::setIsbn(std::string isbnParam)
{
	isbn = isbnParam;
}

bool Book::isAvailable() const
{
	return available;
}

void Book::setAvailable(bool availableParam)
{
	available = availableParam;
}

void Book::printDetails() const
{
	std::cout << title << std::endl << "by " << author << std::endl << isbn << std::endl;
	if (available)
	{
		std::cout << "Available" << std::endl << std::endl;
	}
	else
	{
		std::cout << "This book is currently unavailable" << std::endl << std::endl;
	}
}




