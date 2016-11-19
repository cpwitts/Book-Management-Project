#include "User.h"
#include "UserList.h"
#include "Encrypter.h"
#include <iostream>
#include <fstream>
#include <string>


bool UserList::readUsers()
{
	firstUser = NULL;
	std::ifstream userFile("users.txt"); //Opens input stream
	std::string line; //Used for a single line of input
	std::string input; //Used for multiple lines of input
	int count = 0; //Used to determine if name or password is currently being read

	if (userFile.is_open())
	{
		std::string newName;
		std::string newPassword;
		User* prevUser = NULL;
		User* tempUser = NULL;

		while (getline(userFile, line))
		{
			//If the line is an empty line, reset count. A new User is about to be read.
			if (line == "")
			{
				count = 0;
			}
			//First count is name, second is password
			else if (count == 0)
			{
				newName = line;
				count++;
			}
			else if (count == 1)
			{
				newPassword = line;
				count++;

				/**
				All the data for a User has been read in, so a User is created
				Note: Since the name and password get encrypted when they are set, 
				and we are reading in already encrypted data, and they must be 
				decrytped before being passed into the constructor.
				*/
				tempUser = new User(Encrypter::decryptString(newName), Encrypter::decryptString(newPassword));
				//If there is no first User, this User becomes the first. Otherwise, it is added to the end of the list
				if (firstUser == NULL)
				{
					firstUser = tempUser;
					prevUser = firstUser;
				}
				else
				{
					prevUser->setNext(tempUser);
					tempUser->setPrev(prevUser);
					prevUser = tempUser;
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

void UserList::saveChanges()
{
	std::ofstream userFile("users.txt"); //Opens output stream
	User* currentUser = firstUser;

	//Iterates through list, writing details to text file
	while (currentUser != NULL)
	{
		userFile << currentUser->getName() << std::endl << currentUser->getPassword() << std::endl << std::endl;
		currentUser = currentUser->getNext();
	}
	userFile.close();
}

void UserList::addUser(User* userParam)
{
	if (firstUser == NULL)
	{
		firstUser = userParam;
	}
	else
	{
		User* currentUser = firstUser;
		while (currentUser->getNext() != NULL)
		{
			currentUser = currentUser->getNext();
		}
		currentUser->setNext(userParam);
		userParam->setPrev(currentUser);
	}
	saveChanges();
	std::cout << std::endl << Encrypter::decryptString(userParam->getName()) << " was added";
}

void UserList::removeUser(User* userParam)
{
	if (userParam->getPrev() != NULL)
	{
		userParam->getPrev()->setNext(userParam->getNext());
	}
	//If the User has no prev, it is the first User, so firstUser must be changed to place the next User at the start
	else
	{
		firstUser = userParam->getNext();
	}
	if (userParam->getNext() != NULL)
	{
		userParam->getNext()->setPrev(userParam->getPrev());
	}
	std::cout << std::endl << Encrypter::decryptString(userParam->getName()) << " was successfully removed.\n";
	delete userParam;
	saveChanges();
}


User* UserList::findUser(std::string nameParam) const
{
	User* currentUser = firstUser;
	std::string searchName = Encrypter::encryptString(nameParam); //Encrypts name to search for, so it can eb compared with other encrypted names.
	std::string userName = ""; //stores name of user being comapared
	std::cout << std::endl;

	//Changes the search term to upper case
	for (char & c : searchName)
	{
		c = toupper(c);
	}
	while (currentUser != NULL)
	{
		userName = currentUser->getName();

		//Changes the User title to upper case
		for (char & c : userName)
		{
			c = toupper(c);
		}

		if (userName.compare(searchName) == 0)
		{
			return currentUser;
		}
		currentUser = currentUser->getNext();
	}
	std::cout << "\nNo user with that username was found\n";
	return NULL;
}

