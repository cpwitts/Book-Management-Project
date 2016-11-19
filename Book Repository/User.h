#pragma once
#ifndef USER_H
#define USER_H
#include <string>

class User
{
	std::string name; //Name of user
	std::string password; //Password of user
	User* next; //Pointer to next user
	User* prev; //Pointer to previous user

public:
	/**
	@return string The name of the user
	*/
	std::string getName() const;
	/**
	Sets the name of the user
	@param string The name of the user
	*/
	void setName(std::string nameParam);
	/**
	@return string The password of the user
	*/
	std::string getPassword() const;
	/**
	Sets the password of the user
	@param string The password of the user
	*/
	void setPassword(std::string passwordParam);
	/**
	Compares a stored password to an entered password
	@param string The string to test
	@return bool True is the password is correct, otherwise false
	*/
	bool checkPassword(std::string enteredPassword) const;

	/**
	@return User* Pointer to the next user
	*/
	User* getNext() const;
	/**
	Sets the next user in the list
	@param User* Pointer to the next user in the list
	*/
	void setNext(User* nextParam);
	/**
	@return User* Pointer to the previous user
	*/
	User* getPrev() const;
	/**
	Sets the next user in the list
	@param User* Pointer to the previous user in the list
	*/
	void setPrev(User* prevParam);

	/**
	Creates a user with name and password set to an empty string
	*/
	User();
	/**
	Creates a user with a name and password
	@param string the name of the user
	@param string the password of the user
	*/
	User(std::string nameParam, std::string passwordParam);
};

#endif