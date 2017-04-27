/***************************
Author:
Date:
Description:
***************************/

#include "LibraryItem.hpp"
/*************
Description: Constructor for a Library
**************/
LibraryItem::LibraryItem(std::string idc, std::string t) {
	idCode = idc;
	title = t;
	checkedOutBy = NULL;
	requestedBy = NULL;
	location = ON_SHELF;
}

/*************
Description: Get function / returns ID of an Item
**************/
std::string LibraryItem::getIdCode() {
	return idCode;
}

/*************
Description: Get function / returns title of an Item
**************/
std::string LibraryItem::getTitle() {
	return title;
}

/*************
Description: Get function / returns location of an item
**************/
Locale LibraryItem::getLocation() {
	return location;
}

/*************
Description: Set functions / sets the lcoation of an item
**************/
void LibraryItem::setLocation(Locale loc) {
	location = loc;
}

/*************
Description: Get function / returns pointer to Patron that has this item checked out
**************/
Patron* LibraryItem::getCheckedOutBy() {
	return checkedOutBy;
}

/*************
Description: Set functions / sets the Patron for an item that is checked out
**************/
void LibraryItem::setCheckedOutBy(Patron* patCheck) {
	checkedOutBy = patCheck;
}

/*************
Description: Get function / returns pointer to patron who has requested the item
**************/
Patron* LibraryItem::getRequestedBy() {
	return requestedBy;
}

/*************
Description: Set function / sets an Item to the patron who it is requested by
**************/
void LibraryItem::setRequestedBy(Patron* patRequest) {
	requestedBy = patRequest;
}

/*************
Description: Get function / returns the date an item was first checked out;
**************/
int LibraryItem::getDateCheckedOut() {
	return dateCheckedOut;
}

/*************
Description: Set function / sets the date an item was checked out
**************/
void LibraryItem::setDateCheckedOut(int x) {
	dateCheckedOut = x;
}