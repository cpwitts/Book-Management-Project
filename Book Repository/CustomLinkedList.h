#ifndef CUSTOMLINKEDLIST_H
#define CUSTOMLINKEDLIST_H
#include "CustomListItem.h"

class CustomLinkedList
{
	CustomListItem firstItem;//Pointer to the first item in the list

public:

	/**
	Reads in seat data from a specified text file
	@return bool True if a file was found and read, otherwise false
	*/
	virtual bool readData() = 0;

	/**
	Writes out all the changes made to the text file
	*/
	virtual void saveChanges() = 0;

	/**
	Adds a new User to the list of Users
	@param CustomListItem* the item to add
	*/
	virtual void addItem(CustomListItem* itemParam) = 0;

	/**
	Removes a User from the list of Users
	@param CustomListItem* the item to remove
	*/
	virtual void removeItem(CustomListItem* itemParam) = 0;
};

#endif
