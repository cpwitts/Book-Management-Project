#ifndef BOOKLIST_H
#define BOOKLIST_H

#include <string>
#include "Book.h"
#include "CustomLinkedList.h"

/**
A doubly linked list of books, with all necessary functionality.
This class is implemented as a singleton class, the application
is single terminal, and has only one library to manage.
*/
class BookList : CustomLinkedList
{
	Book* firstItem;//Pointer to the first book in the list

public:
	/**
	Reads in seat data from a specified text file
	@return bool True if a file was found and read, otherwise false
	*/
	bool readData();

	/**
	Writes out all the changes made to the text file
	*/
	void saveChanges();

	/**
	Adds a new book to the list of books
	@param Book the book to add
	*/
	void addItem(CustomListItem* bookParam);

	/**
	Removes a book from the list of books
	@param Book* the book to remove
	*/
	void removeItem(CustomListItem* bookParam);

	/**
	Searches and prints out all books with a title that matches, or contains, the search string
	@param string The string to compare book titles to
	*/
	void searchTitle(std::string searchParam) const;

	/**
	Searches and prints out all books whose author matches, or contains, the search string
	@param string The string to compare book authors to
	*/
	void searchAuthor(std::string searchParam) const;

	/**
	Searches and prints out all books with an ISBN that matches, or contains, the search string
	@param string The string to compare book ISBN to
	*/
	void searchIsbn(std::string searchParam) const;

	/**
	Asks user for method of finding a book (isbn or title) the prompts for input.
	Calls either findIsbn of findTitle
	@return Book* the book found (NULL if no book is found)
	*/
	Book* findBook() const;

	/**
	Finds and returns a pointer to a single book with a title that EXACTLY matches the search string
	@param string The string to compare book titles to
	@return Book* The matching book
	*/
	Book* findTitle(std::string searchParam) const;

	/**
	Finds and returns a pointer to a single book with an ISBN that EXACTLY matches the search string
	@param string The string to compare book ISBN to
	@return Book* The matching book
	*/
	Book* findIsbn(std::string searchParam) const;
	
	/**
	Sets a book to be unavailable
	@param Book* The book to set unavailable
	*/
	void checkOutBook();

	/**
	Checks if a book is available or not
	@return bool ture if available, otherwise false
	*/
	bool checkAvailable() const;

	/**
	Sets a book to be available
	@param Book* The book to set available
	*/
	void returnBook();

	/**
	Returns an instance of BookList
	*/
	static BookList& getInstance()
	{
		static BookList instance;
		return instance;
	}

private:
	BookList() {} //Private to prevent creation of new instances
	void operator=(BookList const&); // Overwritten, but not implemented to prevent copying
};
#endif