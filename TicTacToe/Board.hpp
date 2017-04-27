/*************************************
Author: Sana Tauqir
Date: 6/2/2016
Description: Class declaration for the Board class
*************************************/

#ifndef BOARD_HPP
#define BOARD_HPP


class Board {

private:

	char moves[3][3];

public:

	enum stateOfGame { XWON, OWON, DRAW, IP};

	Board(); // default constructor

	bool makeMove(int x, int y, char player);

	int gameState();    //return value indicating one of four possibilities

	void print();




};


#endif