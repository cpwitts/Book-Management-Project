#include "CustomListItem.h"

CustomListItem* CustomListItem::getNext() const
{
	return next;
}

void CustomListItem::setNext(CustomListItem* nextParam)
{
	next = nextParam;
}

CustomListItem* CustomListItem::getPrev() const
{
	return prev;
}

void CustomListItem::setPrev(CustomListItem* prevParam)
{
	prev = prevParam;
}




