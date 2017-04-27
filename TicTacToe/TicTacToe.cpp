/*************************************
Author: Sana Tauqir
Date: 6/2/2016
Description: Class definition for the TicTacToe class
*************************************/

#include "TicTacToe.hpp"
#include <iostream>

using namespace std;

/***********
Description: Constructor
***********/
TicTacToe::TicTacToe(char firstMove) {

	myTurn = firstMove;

}

/***********
Description: Function that runs the game, asks for input and keeps going while the game is IP
**********/
void TicTacToe::play() {

 	int numTurns = 0, row = 0, column = 0;
	int game = b.gameState();

	do {
	 
		bool valid = false;
		while (valid == false) {
			cout << "Player " << myTurn << ": please enter your move" << endl;
			cin >> row;
			cin >> column;
			if (row > 2 || column > 2) {
				valid = false;
				cout << "That is not a valid entry" << endl;
			}
			else
				valid = true;
		}

		bool moveDone = b.makeMove(row, column, myTurn);
		b.print();

		if (myTurn == 'x' && moveDone == true)
			myTurn = 'o';
		else if (myTurn == 'o' && moveDone == true)
			myTurn = 'x';

		game = b.gameState();

	} while (game == b.IP);
	cout << "Game Over! " << endl;

}

int main() {

	char meFirst = 'o';
	TicTacToe fortheAges(meFirst);
	fortheAges.play();

}