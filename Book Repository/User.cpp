#include "User.h"
#include "Encrypter.h"
#include <iostream>

User::User()
{
	name = "";
	password = "";
	next = NULL;
	prev = NULL;
}

User::User(std::string nameParam, std::string passwordParam)
{
	name = Encrypter::encryptString(nameParam);
	password = Encrypter::encryptString(passwordParam);
	next = NULL;
	prev = NULL;
}

std::string User::getName() const
{
	return name;
}

void User::setName(std::string nameParam)
{
	name = Encrypter::encryptString(nameParam);
}

std::string User::getPassword() const
{
	return password;
}

void User::setPassword(std::string passwordParam)
{
	password = Encrypter::encryptString(passwordParam);
}

bool User::checkPassword(std::string enteredPassword) const
{
	std::string testString = Encrypter::encryptString(enteredPassword);
	if (password.compare(testString) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

User* User::getNext() const
{
	return next;
}

void User::setNext(User* nextParam)
{
	next = nextParam;
}

User* User::getPrev() const
{
	return prev;
}

void User::setPrev(User* prevParam)
{
	prev = prevParam;
}

