/***************************
Author: Sana Tauqir
Date: 6/2/16
Description: Class definition for the Movie class
***************************/

#include "Movie.hpp"

/************
Description: constructor, uses call to super for every non-unique parameter
*************/
Movie::Movie(string identify, string t, string direct) : LibraryItem(identify, t){
	director = direct;
}

/************
Description: Get function / returns the director of the movie
*************/
string Movie::getDirector() {
	return director;
}

/************
Description: Get function / returns the checkoutlength for the item
*************/
int Movie::getCheckOutLength() {
	return CHECK_OUT_LENGTH;
}