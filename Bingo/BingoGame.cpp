/*
Sana Tauqir							PIC 10A: Intro to Programming
Spring 2014
*/
#include "Bingo.h"
#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int main(){

   srand(static_cast<int>(time(NULL)));
   
   Bingo game;
   char again;
   do {
     cout << "_____________Bingo 1.0______________" << endl << endl;
     game.play();
     cout << "Play again? Enter 'y' or 'n': ";
     cin >> again;
	 game.resetGame();
   }
   while(again == 'y');

  cout << "Thanks for playing!" << endl;
  system("PAUSE");
  return 0;
}