#include "User.h"
#include "UserList.h"
#include "Book.h"
#include "BookList.h"
#include "UserMenu.h"
#include <string>
#include <iostream>

BookList bookList = BookList::getInstance();//An instance of bookList, which has a linked list of books and functions to manage books
UserList userList = UserList::getInstance();//An instance of userList, which has a linked list of users and functions to manage users
bool quit = false; //determines when the program should end
char choice; //Takes in the users choice of option in menu loops

void UserMenu::displayUserSelectMenu()
{	
	bookList.readBooks();
	userList.readUsers();
	
	//Allows the user to make a choice. Will not proceed until a valid choice is made
	while (quit == false)
	{
		choice = 0;//Choice must be reset

		std::cout << "\nPress the number shown to navigate the menu:\nAre you... \n1. Admin \n2. Registerd User \n3. Guest \n4. Quit Program \n\n";
		std::cin >> choice;

		//Clears the cin buffer
		std::cin.clear();
		std::cin.ignore(1);

		switch (choice)
		{
		case '1':
			displayAdminMenu();
			break;
		case '2':
			displayUserLoginMenu();
			break;
		case '3':
			displayGuestMenu();
			break;
		case '4':
			quit = true;
			break;
		default:
			std::cout << "\nPlease try again\n\n";
		}
	}
}

void UserMenu::displayUserLoginMenu()
{
	//variables to store information entered
	std::string username = "";
	std::string password = "";

	std::cout << "\nPlease enter your username\n";
	getline(std::cin, username);

	//Checks for account with username first
	User* tempUser = userList.findUser(username);
	if (tempUser != NULL)
	{
		std::cout << "\nPlease enter your password\n";
		getline(std::cin, password);

		//Checks password second.
		if (tempUser->checkPassword(password))
		{
			displayUserMenu();
		}
		else
		{
			std::cout << "\nIncorrect password\n";
		}
	}
	else
	{
		std::cout << "\nNo such user exists\n";	
	}
}


void UserMenu::displayGuestMenu()
{
	//Allows the user to make a choice. Will not proceed until a valid choice is made
	while (quit == false)
	{
		choice = 0;//Choice must be reset

		std::cout << "\nPress the number shown to navigate the menu: \n1. Search by Title \n2. Search by Author \n3. Search by ISBN \n4. Check availability \n5. Quit \n\n";
		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore(1);
		std::string search; //Used to take in use input
		switch (choice)
		{
		case '1':
			//Prompts the user for a title to search for
			std::cout << "Please enter a title to search for:\n";
			getline(std::cin, search);

			bookList.searchTitle(search);
			break;

		case '2':
			//Prompts the user for an author to search for
			std::cout << "Please enter an Author to search for:\n";
			getline(std::cin, search);

			bookList.searchAuthor(search);
			break;

		case '3':
			//Prompts the user for an ISBN to search for
			std::cout << "Please enter an ISBN to search for:\n";
			getline(std::cin, search);

			bookList.searchIsbn(search);
			break;

		case '4':
			//Calls relevant function from bookList
			if (bookList.checkAvailable())
			{
				std::cout << "\nThis book is available\n";
			}
			else
			{
				std::cout << "\nThat book is unavailable\n";
			}
			break;

		case '5':
			//Quits
			quit = true;
			break;

		default:
			std::cout << "\nPlease try again\n\n";
		}
	}
}


void UserMenu::displayUserMenu()
{
	//Allows the user to make a choice. Will not proceed until a valid choice is made
	while (quit == false)
	{
		choice = 0;//Choice must be reset

		std::cout << "\nPress the number shown to navigate the menu: \n1. Search by Title \n2. Search by Author \n3. Search by ISBN \n4. Check availability \n5. Checkout book \n6. Return book\n7. Quit \n\n";
		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore(1);
		std::string search; //Used to take in use input
		switch (choice)
		{
		case '1':
			//Prompts the user for a title to search for
			std::cout << "Please enter a title to search for:\n";
			getline(std::cin, search);

			bookList.searchTitle(search);
			break;

		case '2':
			//Prompts the user for an author to search for
			std::cout << "Please enter an Author to search for:\n";
			getline(std::cin, search);

			bookList.searchAuthor(search);
			break;

		case '3':
			//Prompts the user for an ISBN to search for
			std::cout << "Please enter an ISBN to search for:\n";
			getline(std::cin, search);

			bookList.searchIsbn(search);
			break;

		case '4':
			//Calls relevant function from bookList
			if (bookList.checkAvailable())
			{
				std::cout << "\nThis book is available\n";
			}
			else
			{
				std::cout << "\nThat book is unavailable\n";
			}
			break;

		case '5':
			//Calls relevant function from bookList
			bookList.checkOutBook();
			break;

		case '6':
			//Calls relevant function from bookList
			bookList.returnBook();
			break;

		case '7':
			//Quits
			quit = true;
			break;

		default:
			std::cout << "\nPlease try again\n\n";
		}
	}
}


void UserMenu::displayAdminMenu()
{
	//Allows the user to make a choice. Will not proceed until a valid choice is made
	while (quit == false)
	{
		choice = 0;//Choice must be reset

		//Variables to store input.
		//Switch statements cannot skip declarations, so they are declared here
		std::string newTitle = "";
		std::string newAuthor = "";
		std::string newIsbn = "";
		std::string username = "";
		std::string newUsername = "";
		std::string newPassword = "";
		Book* bookToRemove = NULL;
		User* userToRemove = NULL;

		std::cout << "\nPress the number shown to navigate the menu: \n1. Add book \n2. Remove book \n3. Make book available \n4. Make book unavailable \n5. Add user \n6. Remove user \n7. Quit \n\n";
		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore(1);
		std::string search; //Used to take in use input
		switch (choice)
		{
		case '1':
			//Prompts the user for books information, then creates it
			std::cout << "\nPlease enter the books title:\n";
			getline(std::cin, newTitle);
			std::cout << "\nPlease enter the books author:\n";
			getline(std::cin, newAuthor);
			std::cout << "\nPlease enter the books isbn:\n";
			getline(std::cin, newIsbn);
			bookList.addBook(new Book(newTitle, newAuthor, newIsbn, true));
			break;

		case '2':
			//Gets the user to find a book. If one is found, it is removed
			bookToRemove = bookList.findBook();
			if (bookToRemove != NULL)
			{
				bookList.removeBook(bookToRemove);
			}
			break;

		case '3':
			//Returning a book makes it available, so the same function
			//can be used here
			bookList.returnBook();
			break;

		case '4':
			//Checking out a book makes it unavailable, so the same function
			//can be used here
			bookList.checkOutBook();
			break;

		case '5':
			//Prompts the user for a new users information, then creates it
			std::cout << "\nPlease enter the username:\n";
			getline(std::cin, newUsername);
			std::cout << "\nPlease enter the password:\n";
			getline(std::cin, newPassword);
			userList.addUser(new User(newUsername, newPassword));
			break;

		case '6':
			//Gets the user to find a book. If one is found, it is removed
			std::cout << "\nPlease enter the username of the user to be removed:\n";
			getline(std::cin, username);
			userToRemove = userList.findUser(username);
			if (userToRemove != NULL)
			{
				userList.removeUser(userToRemove);
			}
			break;

		case '7':
			//Quits
			quit = true;
			break;

		default:
			std::cout << "\nPlease try again\n\n";
		}
	}
}