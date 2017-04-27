/***************************
Author: Sana Tauqir
Date: 6/2/16
Description: Class declaration for the Movie class
***************************/

#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <string>
#include "LibraryItem.hpp"
using namespace std;

class Movie : public LibraryItem {

private:
	string director;

public:
	
	static const int CHECK_OUT_LENGTH = 7;
	
	Movie(string identify, string t, string direct);
	string getDirector();
	int getCheckOutLength();

};

#endif