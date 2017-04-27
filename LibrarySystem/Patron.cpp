/***************************
Author: Sana Tauqir
Date: 6/2/16
Description: Class definition for the Patron class
***************************/

#include "Patron.hpp"

/*************
Description: Constructor
**************/
Patron::Patron(std::string idn, std::string n) {
	idNum = idn;
	name = n;
}

/*************
Description: Get function / returns Patron id
**************/
std::string Patron::getIdNum() {
	return idNum;
}

/*************
Description: Get function / returns Patron name
**************/
std::string Patron::getName() {
	return name;
}

/*************
Description: Get function / returns vector of items checked out by a Patron
**************/
std::vector<LibraryItem*> Patron::getCheckedOutItems() {
	return checkedOutItems;
}

/*************
Description: Adds an item to the checkedoutitems vector
**************/
void Patron::addLibraryItem(LibraryItem* b) {
	checkedOutItems.push_back(b);
}

/************* 
Description: removes an item from the checkedoutitems vector
**************/
void Patron::removeLibraryItem(LibraryItem* b) {
	for (size_t i = 0; i < checkedOutItems.size(); i++)
	{
		if (b == checkedOutItems[i])
			checkedOutItems.erase(checkedOutItems.begin()+i);
	}
}

/*************
Description: Get function / returns the fineAmount of a Patron
**************/
double Patron::getFineAmount() {
	return fineAmount;
}

/*************
Description: Adds the amount to their existing fine
**************/
void Patron::amendFine(double amount){	
	fineAmount += amount;

}