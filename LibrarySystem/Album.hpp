/***************************
Author: Sana Tauqir
Date: 6/2/16
Description: Class declaration for the Album class
***************************/

#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <string>
#include "LibraryItem.hpp"
using namespace std;

class Album : public LibraryItem {

private:
	string artist;

public: 

	static const int CHECK_OUT_LENGTH = 14;
	
	Album(string identify, string t, string singer);
	string getArtist();
	int getCheckOutLength();

};

#endif