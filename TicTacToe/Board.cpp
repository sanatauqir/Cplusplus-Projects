/*************************************
Author: Sana Tauqir
Date: 6/2/2016
Description: Class definition for the Board class
*************************************/

#include "Board.hpp"
#include <iostream>
using namespace std;

/***********
Description: Constructor 
**********/
Board::Board() {
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			moves[i][j] = '.';
		}

	}
}

/***********
Description: print out the x or o according to the position provided and the players turn
**********/
bool Board::makeMove(int x, int y, char player) {
	if (moves[x][y] != 'x' && moves[x][y] != 'o') {
		moves[x][y] = player;
		return true;
	}
	else {
		cout << "That square is already taken." << endl;
		return false;
	}
}

/***********
Description: Checks whether a player has won or if the game is a draw or still in progress
**********/
int Board::gameState() {
	//There should be a method called gameState that takes no parameters and returns a value indicating one of four possibilities : 'x' has won, 'o' has won, the game is a draw, or the game is still in progress - use an enum for this (the enum definition should go in Board.hpp)

	if ((moves[0][0] == 'x' && moves[0][1] == 'x' && moves[0][2] == 'x') || (moves[1][0] == 'x' && moves[1][1] == 'x' && moves[1][2] == 'x') || (moves[2][0] == 'x' && moves[2][1] == 'x' && moves[2][2] == 'x') || (moves[0][0] == 'x' && moves[1][0] == 'x' && moves[2][0] == 'x') || (moves[0][2] == 'x' && moves[1][2] == 'x' && moves[2][2] == 'x') || (moves[0][1] == 'x' && moves[1][1] == 'x' && moves[2][1] == 'x') || (moves[0][0] == 'x' && moves[1][1] == 'x' && moves[2][2] == 'x') || (moves[0][2] == 'x' && moves[1][1] == 'x' && moves[2][0] == 'x'))
		return XWON;
	else if ((moves[0][0] == 'o' && moves[0][1] == 'o' && moves[0][2] == 'o') || (moves[1][0] == 'o' && moves[1][1] == 'o' && moves[1][2] == 'o') || (moves[2][0] == 'o' && moves[2][1] == 'o' && moves[2][2] == 'o') || (moves[0][0] == 'o' && moves[1][0] == 'o' && moves[2][0] == 'o') || (moves[0][2] == 'o' && moves[1][2] == 'o' && moves[2][2] == 'o') || (moves[0][1] == 'o' && moves[1][1] == 'o' && moves[2][1] == 'o') || (moves[0][0] == 'o' && moves[1][1] == 'o' && moves[2][2] == 'o') || (moves[0][2] == 'o' && moves[1][1] == 'o' && moves[2][0] == 'o'))
		return OWON;

	bool flag = false;  //assume the board is full

	for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (moves[i][j] == '.')
					flag = true; //jk the board has an empty spot
			}

		}

	if (flag == true)
		return IP;
	else
		return DRAW;

}

/***********
Description: prints out the board to the window
**********/
void Board::print() {
	for (int i = 0; i < 3; i++)  //rows
	{
		for (int j = 0; j < 3; j++)   //columns
		{
			cout << moves[i][j];
		}
		cout << endl;
	}

}
