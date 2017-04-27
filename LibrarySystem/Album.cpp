/***************************
Author: Sana Tauqir
Date: 6/2/16
Description: Class definition for the Album class
***************************/

#include "Album.hpp"

/************
Description: constructor, uses call to super for every non-unique parameter
*************/
Album::Album(string identify, string t, string singer): LibraryItem(identify, t) {
	artist = singer;
}

/************
Description: Get function / returns the artist of the album
*************/
string Album::getArtist() {
	return artist;
}

/************
Description: Get function / returns the checkoutlength for the item
*************/
int Album::getCheckOutLength() {
	return CHECK_OUT_LENGTH;
}