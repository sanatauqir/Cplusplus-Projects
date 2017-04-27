/*************************************
Author: Sana Tauqir
Date: 6/2/2016
Description: Class declaration for the TicTacToe class
*************************************/

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "TicTacToe.hpp"
#include "Board.hpp"

class TicTacToe {

private:
	Board b;
	char myTurn;

public:

	TicTacToe(char firstMove);
	void play();

};


#endif