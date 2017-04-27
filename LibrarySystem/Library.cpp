/***************************
Author: Sana Tauqir
Date: 6/2/2016
Description: Class definition for the Library Class
***************************/

#include "Library.hpp"
#include <iostream>

/********************
Description: Constructor, sets the currentDate of the library to 0
*********************/
Library::Library() {
	currentDate = 0;
}

/********************
Description: Adds a Library Item of type Book/Album/Movie to the holdings vector
*********************/
void Library::addLibraryItem(LibraryItem* libItem) {
	holdings.push_back(libItem);
}

/********************
Description: Adds a Patron to the Members vector
*********************/
void Library::addPatron(Patron* pat) {
	members.push_back(pat);
}

/********************
Description: Finds the Patron in the members vector and returns a pointer to it
*********************/
std::string Library::checkOutLibraryItem(std::string patronID, std::string ItemID) {

	LibraryItem* libItem = getLibraryItem(ItemID);
	Patron* pat = getPatron(patronID);

	if (libItem == NULL)
		return "item not found";
	if (pat == NULL)
		return "patron not found";
	if (libItem->getLocation() == CHECKED_OUT)
		return "item already checked out";
	if (libItem->getLocation() == ON_HOLD_SHELF && libItem->getRequestedBy() != pat)
		return "item on hold by other patron";
	else {
		libItem->setCheckedOutBy(pat);
		libItem->setDateCheckedOut(currentDate);
		libItem->setLocation(CHECKED_OUT);
		pat->addLibraryItem(libItem);
		return "check out successful";
	}
}


/*
Description: 
if the specified LibraryItem is not in the Library, return "item not found"
if the LibraryItem is not checked out, return "item already in library"
update the Patron's checkedOutItems; update the LibraryItem's location depending on whether another Patron has requested it; update the LibraryItem's checkedOutBy; return "return successful"*/
std::string Library::returnLibraryItem(std::string ItemID) {
	LibraryItem* libItem = getLibraryItem(ItemID);
	Patron* pat = libItem->getCheckedOutBy();

	if (libItem == NULL)
		return "item not found";
	if (libItem->getLocation() == ON_SHELF)
		return "item already in library";
	else
	{
		//if the item has not been requested by anyone, put it back on the shelf
		if (libItem->getRequestedBy() == NULL) {
			libItem->setRequestedBy(NULL);
			libItem->setLocation(ON_SHELF);
		}
		else
			libItem->setLocation(ON_HOLD_SHELF);

		libItem->setCheckedOutBy(NULL);
		
		pat->removeLibraryItem(libItem);
		return "return successful";
	}


}

/*
Description:
if the specified LibraryItem is not in the Library, return "item not found"
if the specified Patron is not in the Library, return "patron not found"
if the specified LibraryItem is already requested, return "item already on hold"
update the LibraryItem's requestedBy; if the LibraryItem is on the shelf, update its location to on hold; return "request successful"
*/
std::string Library::requestLibraryItem(std::string patronID, std::string ItemID) {
	LibraryItem* libItem = getLibraryItem(ItemID);
	Patron* pat = getPatron(patronID);

	if (libItem == NULL)
		return "item not found";
	if (pat == NULL)
		return "patron not found";
	if (libItem->getLocation() == ON_HOLD_SHELF)
		return "item already on hold";
	else {
		libItem->setLocation(ON_HOLD_SHELF);
		libItem->setRequestedBy(pat);
		return "request successful";
	}


}

/*******************
Description: If the Patron is in the library, subtract the payment from their fineAmount using amendFine function
********************/
std::string Library::payFine(std::string patronID, double payment) {
	Patron* pat = getPatron(patronID);
	double neg = payment * -1;

	if (pat == NULL)
		return "patron not found";
	else if (payment <= pat->getFineAmount()) {
		pat->amendFine(neg);
		return "Your fine has been paid. Thank you!";
	}
	else
		return "You are paying in excess of your fine amount";

}

/********************
Description: Increments the current date
Increases Patron's fines depending on whether they have had items checked out longer than the Item's Check_out_length
*********************/
void Library::incrementCurrentDate() {
	currentDate+=1;
	vector <LibraryItem*> x;

	//loop through every member's checked out items
	for (size_t i = 0; i < members.size(); i++){
		x = members[i]->getCheckedOutItems();
		int y = 0, z=0;
		for (size_t j = 0; j < x.size(); j++) {
			//if the item has been checked out for longer than 7/14/21 days, amend a fine of 10cents
			y = currentDate - x[j]->getDateCheckedOut();
			z = x[j]->getCheckOutLength();
			if (y > z) {
				members[i]->amendFine(.10);
			}
		}
	}
		
}

/********************
Description: Finds the Patron in the members vector and returns a pointer to it
*********************/
Patron* Library::getPatron(std::string patronID) {
	for (size_t i = 0; i < members.size(); i++)
	{
		if (members[i]->getIdNum() == patronID)
			return members[i];
	}
	return NULL;
}

/********************
Description: Finds the LibraryItem in the holdings vector and returns a pointer to it
*********************/
LibraryItem* Library::getLibraryItem(std::string ItemID) {
	for (size_t i = 0; i < holdings.size(); i++)
	{
		if (holdings[i]->getIdCode() == ItemID)
			return holdings[i];
	}
	return NULL;
}


int main() {
	Book b1("123", "War and Peace", "Tolstoy");
	std::cout << "b1 has an ID of " << b1.getIdCode() << " a title of " << b1.getTitle() << " and is by " << b1.getAuthor() << endl;
	Book b2("234", "Moby Dick", "Melville");
	Book b3("345", "Phantom Tollbooth", "Juster");
	Patron p1("abc", "Felicity");
	Patron p2("bcd", "Waldo");
	Patron p3("efg", "Sana");
	
	Library lib;
	lib.addLibraryItem(&b1);
	lib.addLibraryItem(&b2);
	lib.addLibraryItem(&b3);
	lib.addPatron(&p1);
	lib.addPatron(&p2);
	lib.addPatron(&p3);
	string s = lib.checkOutLibraryItem("bcd", "234");
	cout << s << endl;
	string e = lib.requestLibraryItem("efg", "123" );
	cout << e << endl;

	for (int i = 0; i < 7; i++)
		lib.incrementCurrentDate();
	string r = lib.checkOutLibraryItem("bcd", "123");
	cout << "this is where Felicity tries to check out the book Sana has on hold " << r << endl;
	
	string y = lib.checkOutLibraryItem("abc", "345");
	cout << y << endl;

	for (int i = 0; i < 24; i++)
		lib.incrementCurrentDate();

	std::cout << p2.getFineAmount() << endl;
	std::cout << p1.getFineAmount() << endl;
	string t = lib.payFine("bcd", 0.4);
	cout << t << endl;
	double p1Fine = p1.getFineAmount();
	cout << p1Fine << endl;
	double p2Fine = p2.getFineAmount();
	cout << p2Fine << endl;
}
