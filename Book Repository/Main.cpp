#include <iostream>
#include "BookList.h"

char choice = 0; //Stores the choice user made in main menu
int menu = 1; //Represents the current menu
bool quit = false; //Used to in main loop
BookList bookList = BookList::getInstance();//An instance of bookLisy, which has a linked list of books and functions to manage books

void printMainMenu();

int main()
{
	bookList.readBooks();
	while (!quit)
	{
		//Displays main menu
		if (menu == 1)
		{
			printMainMenu();
		}

		//Search for books by title
		else if (menu == 2)
		{
			std::string search;
			std::cout << "Please enter a title to search for:\n";
			getline(std::cin, search);
			
			bookList.searchTitle(search);
			menu = 1;
		}

		//Search for books by author
		else if (menu == 3)
		{
			std::string search;
			std::cout << "Please enter an Author to search for:\n";
			getline(std::cin, search);

			bookList.searchAuthor(search);
			menu = 1;
		}
		
		//Search for books by ISBN
		else if (menu == 4)
		{
			std::string search;
			std::cout << "Please enter an ISBN to search for:\n";
			getline(std::cin, search);
			
			bookList.searchIsbn(search);
			menu = 1;
		}
		
		//Resets all data
		else if (menu == 5)
		{
			bookList.checkAvailable();
			menu = 1;
		}

		//Resets the information of a single seat
		else if (menu == 6)
		{
			bookList.checkOutBook();
			menu = 1;
		}

		//Saves all changes to a text file
		else if (menu == 7)
		{
			bookList.returnBook();
			menu = 1;
		}
		
		//Allows the user to add a new book
		else if (menu == 8)
		{
			std::string newTitle;
			std::string newAuthor;
			std::string newIsbn;
			std::cout << "\nPlease enter the book title:\n";
			getline(std::cin, newTitle);
			std::cout << "\nPlease enter the books author:\n";
			getline(std::cin, newAuthor);
			std::cout << "\nPlease enter the books isbn:\n";
			getline(std::cin, newIsbn);
			bookList.addBook(new Book(newTitle, newAuthor, newIsbn, true));
			menu = 1;
		}
		
		//Allows the user to remove a book
		else if (menu == 9)
		{
			Book* bookToRemove = NULL;
			bookToRemove = bookList.findBook();
			if (bookToRemove != NULL)
			{
				bookList.removeBook(bookToRemove);
			}
			menu = 1;
		}
	}
	return 0;
}

//Displays the main menu
void printMainMenu()
{
	//Allows the user to make a choice. Will not proceed until a valid choice is made
	while (menu == 1 && quit == false)
	{
		std::cout << "\nPress the number shown to navigate the menu: \n1. Search by Title \n2. Search by Author \n3. Search by ISBN \n4. Check availability \n5. Checkout book \n6. Return Book \n7. Add book \n8. Remove Book \n9. Quit \n\n";
		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore(1);
		switch (choice)
		{
		case '1':
			menu = 2;
			break;
		case '2':
			menu = 3;
			break;
		case '3':
			menu = 4;
			break;
		case '4':
			menu = 5;
			break;
		case '5':
			menu = 6;
			break;
		case '6':
			menu = 7;
			break;
		case '7':
			menu = 8;
			break;
		case '8':
			menu = 9;
			break;
		case '9':
			quit = true;
			break;
		default:
			std::cout << "\nPlease try again\n\n";
		}
	}
}
