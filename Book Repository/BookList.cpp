
#include "Book.h"
#include "BookList.h"
#include <iostream>
#include <fstream>
#include <string>


bool BookList::readBooks()
{
	firstBook = NULL;
	std::ifstream bookFile("books.txt"); //Opens input stream
	std::string line; //Used for a single line of input
	std::string input; //Used for multiple lines of input
	int count = 0; //Used to determine if title, author or ISBN is currently being read

	if (bookFile.is_open())
	{
		std::string newTitle;
		std::string newAuthor;
		std::string newISBN;
		bool newAvailability;
		Book* prevBook = NULL;
		Book* tempBook = NULL;

		while (getline(bookFile, line))
		{
			//If the line is an empty line, reset count. A new book is about to be read.
			if (line == "")
			{
				count = 0;
			}
			//First count is title, second is author, third is ISBN, foruth is availability
			else if (count == 0)
			{
				newTitle = line;
				count++;
			}
			else if (count == 1)
			{
				newAuthor = line;
				count++;
			}
			else if (count == 2)
			{
				newISBN = line;
				count++;
			}
			else if (count == 3)
			{
				if (line.compare("Available") == 0)
				{
					newAvailability = true;
				}
				else
				{
					newAvailability = false;
				}

				//All the data for a book has been read in, so a book is created
				tempBook = new Book(newTitle, newAuthor, newISBN, newAvailability);
				//If there is no first book, this book becomes the first. Otherwise, it ias added to the end of the list
				if (firstBook == NULL)
				{
					firstBook = tempBook;
					prevBook = firstBook;
				}
				else
				{
					prevBook->setNext(tempBook);
					tempBook->setPrev(prevBook);
					prevBook = tempBook;
				}
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

void BookList::saveChanges()
{
	std::ofstream bookFile("books.txt"); //Opens output stream
	Book* currentBook = firstBook;

	//Iterates through list, writing details to text file
	while (currentBook != NULL)
	{
		bookFile << currentBook->getTitle() << std::endl << currentBook->getAuthor() << std::endl << currentBook->getIsbn() << std::endl;
		if (currentBook->isAvailable())
		{
			bookFile << "Available";
		}
		else
		{
			bookFile << "Unavailable";
		}
		bookFile << std::endl << std::endl;
		currentBook = currentBook->getNext();
	}
	bookFile.close();
}

void BookList::addBook(Book* bookParam)
{
	if (firstBook == NULL)
	{
		firstBook = bookParam;
	}
	else
	{
		Book* currentBook = firstBook;
		while (currentBook->getNext() != NULL)
		{
			currentBook = currentBook->getNext();
		}
		currentBook->setNext(bookParam);
		bookParam->setPrev(currentBook);
		saveChanges();
	}
}

void BookList::removeBook(Book* bookParam)
{
	if (bookParam->getPrev() != NULL)
	{
		bookParam->getPrev()->setNext(bookParam->getNext());
	}
	//If the book has no prev, it is the first book, so firstBook must be changed to place the next book at the start
	else
	{
		firstBook = bookParam->getNext();
	}
	if (bookParam->getNext() != NULL)
	{
		bookParam->getNext()->setPrev(bookParam->getPrev());
	}
	std::cout << std::endl << bookParam->getTitle() << " Was removed.\n";
	delete bookParam;
	saveChanges();
}

void BookList::searchTitle(std::string searchParam) const
{
	Book* currentBook = firstBook;
	std::string bookTitle = "";
	std::cout << std::endl;

	//Changes the search term to upper case
	for (char & c : searchParam)
	{
		c = toupper(c);
	}
	while (currentBook != NULL)
	{
		bookTitle = currentBook->getTitle();
		
		//Changes the book title to upper case
		for (char & c : bookTitle)
		{
			c = toupper(c);
		}

		if (bookTitle.find(searchParam) != std::string::npos)
		{
			currentBook->printDetails();
		}
		currentBook = currentBook->getNext();
	}
}

void BookList::searchAuthor(std::string searchParam) const
{
	Book* currentBook = firstBook;
	std::string bookAuthor = "";
	std::cout << std::endl;

	//Changes the search term to upper case
	for (char & c : searchParam)
	{
		c = toupper(c);
	}
	while (currentBook != NULL)
	{
		bookAuthor = currentBook->getAuthor();

		//Changes the book title to upper case
		for (char & c : bookAuthor)
		{
			c = toupper(c);
		}

		if (bookAuthor.find(searchParam) != std::string::npos)
		{
			currentBook->printDetails();
		}
		currentBook = currentBook->getNext();
	}
};

void BookList::searchIsbn(std::string searchParam) const
{
	Book* currentBook = firstBook;
	std::string bookIsbn = "";
	std::cout << std::endl;

	while (currentBook != NULL)
	{
		bookIsbn = currentBook->getIsbn();
		if (bookIsbn.find(searchParam) != std::string::npos)
		{
			currentBook->printDetails();
		}
		currentBook = currentBook->getNext();
	}
}

Book* BookList::findBook() const
{
	std::string search;
	char choice;
	Book* foundBook = NULL;
	std::cout << "Find book by:\n1: Title\n2: ISBN\n\n";
	std::cin >> choice;
	std::cin.clear();
	std::cin.ignore(1);
	switch (choice)
	{
	case '1':
		std::cout << "Please enter the title of the book:\n";
		getline(std::cin, search);
		foundBook = findTitle(search);
		if (foundBook != NULL)
		{
			return foundBook;
		}
		else
		{
			std::cout << "\nNo book with that title was found\n\n";
			return NULL;
		}
		break;
	case '2':
		std::cout << "Please enter the ISBN of the book:\n";
		getline(std::cin, search);
		foundBook = findIsbn(search);
		if (foundBook != NULL)
		{
			return foundBook;
		}
		else
		{
			std::cout << "\nNo book with that ISBN was found\n\n";
			return NULL;
		}
		break;
	default:
		return NULL;
		break;
	}
}

Book* BookList::findTitle(std::string searchParam) const
{
	Book* currentBook = firstBook;
	std::string bookTitle = "";
	std::cout << std::endl;

	//Changes the search term to upper case
	for (char & c : searchParam)
	{
		c = toupper(c);
	}
	while (currentBook != NULL)
	{
		bookTitle = currentBook->getTitle();

		//Changes the book title to upper case
		for (char & c : bookTitle)
		{
			c = toupper(c);
		}

		if (bookTitle.compare(searchParam) == 0)
		{
			return currentBook;
		}
		currentBook = currentBook->getNext();
	}
	return NULL;
}

Book* BookList::findIsbn(std::string searchParam) const
{
	Book* currentBook = firstBook;
	std::string bookIsbn = "";
	std::cout << std::endl;

	while (currentBook != NULL)
	{
		bookIsbn = currentBook->getIsbn();

		//Changes the book title to upper case
		for (char & c : bookIsbn)
		{
			c = toupper(c);
		}

		if (bookIsbn.compare(searchParam) == 0)
		{
			return currentBook;
		}
		currentBook = currentBook->getNext();
	}
	return NULL;
}

void BookList::checkOutBook()
{
	Book* bookToCheckOut = NULL;
	bookToCheckOut = findBook();
	if (bookToCheckOut != NULL && bookToCheckOut->isAvailable())
	{
		bookToCheckOut->setAvailable(false);
		saveChanges();
	}
	else
	{
		std::cout << "Book cannot be checked out\n\n";
	}
}

bool BookList::checkAvailable() const
{
	Book* bookToCheck = NULL;
	bookToCheck = findBook();
	if (bookToCheck != NULL)
	{
		return bookToCheck->isAvailable();
	}
	else
	{
		return false;
	}
}

void BookList::returnBook()
{
	Book* bookToCheckOut = NULL;
	bookToCheckOut = findBook();
	if (bookToCheckOut != NULL && !bookToCheckOut->isAvailable())
	{
		bookToCheckOut->setAvailable(true);
		saveChanges();
	}
	else
	{
		std::cout << "Book cannot be returned\n\n";
	}
}

