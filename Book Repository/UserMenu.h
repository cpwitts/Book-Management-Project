#ifndef USERMENU_H
#define USERMENU_H

#include <string>
#include "Book.h"

/**
This class displays menus and takes in input.
It is implemented as a Singleton, as there should only
be a single menu.
*/
class UserMenu
{

public:
	/**
	Prints a menu asking the user to select between admin, registered and guest
	*/
	void displayUserSelectMenu();

	/**
	Prints a menu allowing the user to login.
	Prompts user for a username. If that username is found,
	promtps user for a password. If login is successful, the
	user will be brought to the userMenu. If not,they will be
	brought back to userSelectMenu
	*/
	void displayUserLoginMenu();

	/**
	Prints a menu for guests to use
	*/
	void displayGuestMenu();

	/**
	Prints a menu for registered users to use
	*/
	void displayUserMenu();

	/**
	Prints a menu for admins to use
	*/
	void displayAdminMenu();

	/**
	Returns an instance of UserMenu
	*/
	static UserMenu& getInstance()
	{
		static UserMenu instance;
		return instance;
	}

private:
	UserMenu() {} //Private to prevent creation of new instances
	void operator=(UserMenu const&); // Overwritten, but not implemented to prevent copying
};
#endif