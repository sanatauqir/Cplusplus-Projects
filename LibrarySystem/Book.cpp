/***************************
Author: Sana Tauqir
Date: 6/2/16
Description: Class definition for the Book class
***************************/

#include "Book.hpp"

/************
Description: constructor, uses call to super for every non-unique parameter
*************/
Book::Book(string identify, string t, string writer) : LibraryItem(identify, t) {
	
	author = writer;
}

/************
Description: Get function / returns the author of the book
*************/
string Book::getAuthor() {

	return author;
}

/************
Description: Get function / returns the checkoutlength for the item
*************/
int Book::getCheckOutLength() {
	return CHECK_OUT_LENGTH;
}