#pragma once
#ifndef BOOK_H
#define BOOK_H
#include <string>
#include "CustomListItem.h"

class Book : public CustomListItem
{
	std::string title; //Title of the book
	std::string author; //Author of the book
	std::string isbn; // ISBN of the book
	bool available; //Is the book currently available

public:
	/**
	@return string the title of the book
	*/
	std::string getTitle() const;
	/**
	Sets the title of the book
	@param string The title of the book
	*/
	void setTitle(std::string titleParam);
	/**
	@return string the author of the book
	*/
	std::string getAuthor() const;
	/**
	Sets the author of the book
	@param string The author of the book
	*/
	void setAuthor(std::string authorParam);
	/**
	@return string the ISBN of the book
	*/
	std::string getIsbn() const;
	/**
	Sets the ISBN of the book
	@param string The ISBN of the book
	*/
	void setIsbn(std::string isbnParam);
	/**
	@return bool true if book is available, otherwise false
	*/
	bool isAvailable() const;
	/**
	Sets the book to available or not
	@param bool true if avaible, otherwise false
	*/
	void setAvailable(bool availableParam);
	/**
	Prints the relevant details of the book
	*/
	void printDetails() const;

	/**
	Creates a new book with:
	title, ISBN and author set to empty strings
	prev and next set to NULL#
	available set to true
	*/
	Book();

	/**
	Creates a new book with given parameters. Prev and next set to NULL
	@param string the title of the book
	@param string the author of the book
	@param string the ISBN of the book
	@param bool is the book available or not
	*/
	Book(std::string titleParam, std::string authorParam, std::string isbnParam, bool availableParam);
};

#endif

