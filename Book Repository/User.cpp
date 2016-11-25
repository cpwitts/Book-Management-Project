#include "User.h"
#include "Encrypter.h"
#include <iostream>

User::User()
{
	name = "";
	password = "";
	setNext(NULL);
	setPrev(NULL);
}

User::User(std::string nameParam, std::string passwordParam)
{
	name = Encrypter::encryptString(nameParam);
	password = Encrypter::encryptString(passwordParam);
	setNext(NULL);
	setPrev(NULL);
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
	//Encrypt the entered text before testing, so that it should match the encrypted password saved
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
