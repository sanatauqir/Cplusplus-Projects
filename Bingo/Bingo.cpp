/*
Sana Tauqir							PIC 10A: Intro to Programming
						Spring 2014
*/

#include "Bingo.h"
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

Bingo::Bingo ()
{
	int card[NUM_ROWS][NUM_COLS];
	bool marked[NUM_ROWS][NUM_COLS];
	for (int row = 0; row< NUM_ROWS; row++) // in the marked array, set all locations to false except the center
		for (int col = 0; col <NUM_COLS; col++)
		{
			if (row == 2 && col == 2)
				marked[row][col] = true;
			else
				marked[row][col] = false;
		}
}

void Bingo::generateCard()
{
	int seed = static_cast<int>(time(NULL));
	srand(seed);
	int newRand;
	bool notFound;

	for (int row = 0; row< NUM_ROWS; row++)
		for (int col = 0; col <NUM_COLS; col++)
		{
			card[row][col] = 0;	// set all the positions in the card array to 0
		}

	for (int row =0; row < NUM_ROWS ; row++)
		{
			do 
			{
				notFound = true;
				newRand = (rand()%15) + 1;
				for (int checkRow = 0; checkRow < row; checkRow++)	 //check through the rows in col 0 if the # exists
					if (newRand == card [checkRow][0])
						notFound = false;		// if it exists, set notFound to false, meaning it was found
			} while (notFound == false);
				card [row][0] = newRand;
		}

	for (int row = 0; row <NUM_ROWS ; row++)
		{
			do 
			{
				notFound = true;
				newRand = (rand()%15) + 16;	// generate random number 1-15 and set to newRand
				for (int checkRow = 0; checkRow < row; checkRow++)	 //check through the rows in col 1 if the # exists
					if (newRand == card [checkRow][1])
						notFound = false;		// if it exists, set notFound to false, meaning it was found
			} while (notFound == false);
				card [row][1] = newRand;	// if notFound is true then set random number in col 1
		}

	for (int row = 0; row < NUM_ROWS ; row++)
		{
			do 
			{
				notFound = true;
				newRand = (rand()%15) + 31;	// generate random number 16-30
				for (int checkRow = 0; checkRow < row; checkRow++)	 //check through the rows in col 2 if the # exists
					if (newRand == card [checkRow][2])
						notFound = false;		// if it exists, set notFound to false, meaning it was found
			} while (notFound == false);
				card [row][2] = newRand;	// if notFound is true then set random number in col 2
		}

	for (int row = 0; row <NUM_ROWS ; row++)
		{
			do 
			{
				notFound = true;
				newRand = (rand()%15) + 46;
				for (int checkRow = 0; checkRow < row; checkRow++)	 //check through the rows in col 3 if the # exists
					if (newRand == card [checkRow][3])
						notFound = false;		// if it exists, set notFound to false, meaning it was found
			} while (notFound == false);
				card [row][3] = newRand;	// if notFound is true, set random number in col 3
		}

	for (int row = 0; row <NUM_ROWS ; row++)
	{
			do 
			{
				notFound = true;
				newRand = (rand()%15) + 61;
				for (int checkRow = 0; checkRow < row; checkRow++)	 //check through the rows in col 4 if the # exists
					if (newRand == card [checkRow][4])
						notFound = false;		// if it exists, set notFound to false, meaning it was found
			} while (notFound == false);
				card [row][4] = newRand;	// if notFound is true set random number in col 4
		}
		card [2][2] = 0;
}

// sets all of them back to true
void Bingo::resetGame()
{
	for (int row = 0; row< NUM_ROWS; row++)
		for (int col = 0; col <NUM_COLS; col++)
		{
			if (row == 2 && col == 2)
				marked[row][col] = true;
			else
				marked[row][col] = false;
		}
}

bool Bingo::cardContainsNumber(int number)
{
	for (int row = 0; row< NUM_ROWS; row++)
	{
		for (int col = 0; col <NUM_COLS; col++)
		{
			if (card[row][col] == number)	// check whether the number exists in the card array
				return true;
		}
	}
	return false;
}

void Bingo::displayCard() const
{
	cout << endl;
	cout << "    B    I    N    G    O" << endl;

	for (int row = 0; row< NUM_ROWS; row++)
	{
		for (int col = 0; col <NUM_COLS; col++)
			{
				cout << right << setw(5);
				if (row==2 && col ==2)
					cout << "X";				// print X in the center
				else
					cout << card[row][col];		// print whatever the card array has
			}
			cout << endl; 
	}

}

void Bingo::displayMarked() const
{
	cout << endl;
	cout << "    B    I    N    G    O" << endl;

	for (int row = 0; row< NUM_ROWS; row++)
	{
		for (int col = 0; col <NUM_COLS; col++)
			{
				cout << right << setw(5);
				if (row==2 && col ==2)
					cout << "1";			// print out 1 for the center piece
				else if (marked [row][col] == true)
					cout << true;				// if the position is marked true in marked array, print out 1
				else
					cout << false;
			}
			cout << endl; 
	}
	cout << endl;
}

void Bingo::mark(int number)
{
	for (int row = 0; row< NUM_ROWS; row++)
	{
		for (int col = 0; col <NUM_COLS; col++)
		{
			if (card[row][col] == number)			// if the number exists in the card array
				marked [row][col] = true;			// mark is as true in the marked array
		}
	}
}

bool Bingo::wonGame() const
{
	// if you find five consecutive trues in a row in the marked array, return true
	for (int row = 0; row< NUM_ROWS; row++)
	{
		int counter =0;
		for (int col = 0; col <NUM_COLS; col++)
		{
			if (marked[row][col] == true)
				counter++;
		}
			if (counter == 5)
				return true;
	}

	// if you find five consecutive trues in a column in the marked array, return true
	for (int col =0; col < NUM_COLS; col++)
	{
		int counter =0;
		for (int row = 0; row <NUM_COLS; row++)
		{
			if (marked[row][col] == true)
				counter++;
		}
			if (counter == 5)
				return true;
	}

	// if you find five consecutive trues in the negative diagonal, return true
	for (int row = 0; row <NUM_ROWS ; row++)
	{
		int counter= 0;
		for (int col = 0; col <NUM_COLS ; col++)
		{	
			if (row == col && marked[row][col] == true)
				counter++;
		}
		if (counter == 5)
			return true;
	}

	// if you find five consecutive trues in the positive diagonal, return true
	for (int row = 0 ; row <NUM_ROWS; row++)
	{
		int counter = 0;
		for (int col = 5; col = 0; col--)
		{
			if (marked[row][col] == true)
				counter++;
		}
		if (counter == 5)
			return true;
	}
	return false;
}

void Bingo::play()
{
	int generated =0;
	bool alreadyUsed = true;
	int size = 0;
	int usedNum [1000]; //vector of int elements
	int counter =0;
	int i=0;
	bool notFound = false;
	int here = 0;

	generateCard();	
	displayCard();
	displayMarked();
	do
	{	
		do
		{
			// generate random number and compare it to every position in vector of ints
			system ("PAUSE");
			generated = (rand() % 75) +1;
			notFound = true;	// assuming not found initially
			for (i=0; i < size; i++)
				if (usedNum [i] == generated)	
					notFound = false;		// is found in the usedNum, generate new number
		} while (notFound == false);	 // keep generating while number is found in the list 
		
		usedNum[i] = generated; // adds the number called to the vector
		size++;

		// print out the card and marked arrays when the number generated exists on the card, and mark it in marked array
		if (cardContainsNumber (generated) == true)
		{
			mark (generated);
			cout << "Next number called: " << generated;
			cout << endl;
			displayCard();
			displayMarked();
		}

		// print out the card and marked arrays even if the number generated does not exist on the Card
		if (cardContainsNumber (generated) == false)
		{ 
		cout << "Next number called: " << generated;
		cout << endl;
		displayCard();
		displayMarked();
		}

	}while (wonGame() == false);			// keep going while someone has not won the game yet

		cout << "Bingo!!!!";
		displayCard();
		displayMarked();
}



