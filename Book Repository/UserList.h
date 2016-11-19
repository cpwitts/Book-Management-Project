#ifndef USERLIST_H
#define USERLIST_H

#include <string>
#include "User.h"

/**
A doubly linked list of Users, with all necessary functionality.
This class is implemented as a singleton class, the application
is single terminal, and has only one set of users to manage.
*/
class UserList
{
	User* firstUser;//Pointer to the first User in the list

public:
	/**
	Reads in seat data from a specified text file
	@return bool True if a file was found and read, otherwise false
	*/
	bool readUsers();

	/**
	Writes out all the changes made to the text file
	*/
	void saveChanges();

	/**
	Adds a new User to the list of Users
	@param User the User to add
	*/
	void addUser(User* UserParam);

	/**
	Removes a User from the list of Users
	@param User* the User to remove
	*/
	void removeUser(User* UserParam);

	/**
	Finds a user by name. The name must match the search string EXACTLY
	@param string The name to search for
	@return User* the User found (NULL if no User is found)
	*/
	User* findUser(std::string nameParam) const;

	/**
	Returns an instance of UserList
	*/
	static UserList& getInstance()
	{
		static UserList instance;
		return instance;
	}

private:
	UserList() {} //Private to prevent creation of new instances
	void operator=(UserList const&); // Overwritten, but not implemented to prevent copying
};
#endif