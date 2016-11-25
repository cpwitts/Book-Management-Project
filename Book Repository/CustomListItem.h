#ifndef CUSTOMLISTITEM_H
#define CUSTOMLISTITEM_H

class CustomListItem
{
	CustomListItem* next; //Pointer to next item in list
	CustomListItem* prev; //Pointer to previous item in list

public:
	/**
	@return CustomListItem* pointer to the next Item
	*/
	CustomListItem* getNext() const;
	/**
	Sets the next Item in the list
	@param CustomListItem* The next Item in the list
	*/
	void setNext(CustomListItem* nextParam);
	/**
	@return CustomListItem* pointer to the previous Item
	*/
	CustomListItem* getPrev() const;
	/**
	Sets the previous Item in the list
	@param CustomListItem* pointer to the previous Item
	*/
	void setPrev(CustomListItem* prevParam);

};

#endif
