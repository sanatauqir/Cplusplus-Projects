/***************************
Author: Sana Tauqir
Date: 6/2/16
Description: Class declaration for the Book class
***************************/

#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include "LibraryItem.hpp"
using namespace std;

class Book: public LibraryItem {

private:
	string author;

public:

	static const int CHECK_OUT_LENGTH = 21;

	string getAuthor();
	Book(string identify, string t, string writer);
	int getCheckOutLength();
};

#endif