/*
Sana Tauqir							PIC 10A: Intro to Programming
Spring 2014
*/

#ifndef BINGO_H
#define BINGO_H

const int NUM_ROWS = 5;
const int NUM_COLS = 5;

class Bingo {

  public: 
	Bingo();

	void resetGame();
	void displayCard() const;
	void displayMarked() const;
	void play();

  private:
	int card[NUM_ROWS][NUM_COLS];
	bool marked[NUM_ROWS][NUM_COLS];

	void generateCard();
	bool cardContainsNumber(int number);
	bool wonGame()const;
	void mark(int number);
};

#endif