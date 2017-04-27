/*
Sana Tauqir							PIC 10A: Intro to Programming
Assignment 4						Spring 2014

*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main ()
{
// naming constants
	const char QUIT = 'q';
	const int MAX_NUMBER = 37;
	const int DOUBLE_ZERO = MAX_NUMBER;
	const int DEFAULT_PLAYER_NUMBER = MAX_NUMBER+1;
	const int EVEN_ODD_PAYOUT = 1;
	const int STRAIGHT_UP_PAYOUT = 35;

	// variables for bet amounts
	double evenBet = 0;
	double oddBet = 0;
	double straightBet = 0;
	double evenWinning = 0;
	double oddWinning = 0;
	double straightWinning = 0;

	// variables for whether the bet type has been made before
	bool straightMade = 0;
	bool betA = 0;
	bool betB = 0;

	// other variables
	string user_name;
	double remaining_amount = 1000.00;
	int straightup_number = 0;
	int rouletteSpin = 0;
	double winningPurse=0;
	char user_choice;
	int isValid=0;
	
	// asking for the name
	cout << "What is your name? ";
	getline (cin, user_name);
	

	//start of the loop
	do {

	cout << endl << "Roulette 1.0" << endl << endl;
	cout << user_name << ", you have $" << remaining_amount << " left." << endl << endl;

	// print out the menu
	cout << "Select from the following options:" << endl << endl;
	cout << "<a> Even Bet " << endl;
	cout << "<b> Odd Bet " << endl;
	cout << "<c> Straight Up Bet" << endl;
	cout << "<d> Spin the Wheel" << endl;
	cout << "<q> Quit" << endl << endl;
	cout << "Enter the letter of your choice: ";
	cin>> user_choice;
	cout<< endl;
	
	//set the seed
	int seed = static_cast<int>(time(NULL));
	srand (seed);

		switch (user_choice) 
		{
		case 'a':
			// check if this bet has already been made this session
			if (betA == true)
			{
				cout << "Already bet! Try another option. " << endl << endl;
				break;
			}
			// ask for bet amount which is nonnegative and valid
			cout << "Enter an even bet: ";
			cin >> evenBet;
			cout << endl;

			if (evenBet < 0)
				{ 
					cout << "Invalid bet! Try again" << endl;
					break;
				}
			if (evenBet > remaining_amount)
				{
					cout << "Cannot bet that much! Try again. " <<endl;
					break;
				}

			remaining_amount -= evenBet; 
			betA = true;
			break;

		// odd bet amount
		case 'b':
			if (betB == true)
			{
				cout << "Already bet! Try another option. " << endl << endl;
				break;
			}

			cout << "Enter an odd bet: ";
			cin >> oddBet;

			if (oddBet <0)
				{
					cout << "Invalid bet! Try again" << endl;
					break;
				}
			if (oddBet > remaining_amount)
				{
					cout << "Cannot bet that much! Try again. " <<endl;
					break;
				}
			
			remaining_amount -= oddBet;
			betB = true;
			break;

		//straight up bet
		case 'c':
			if (straightMade == true)
			{
				cout << "Already bet! Try another option. " << endl << endl;
				break;
			}

			cout<< "Enter a straight up bet: ";
			cin >> straightBet;

			if (straightBet <0)
				{
					cout << "Invalid bet! Try again" << endl;
					break;
				}
			if (straightBet > remaining_amount)
				{
					cout << "Cannot bet that much! Try again. " <<endl;
					break;
				}
			
			//ask for a number to bet on from 00 to 36
			cout << "Enter a number to bet on <Enter \"37\" for \"00\">: ";
			cin >> straightup_number;
			if (straightup_number < MAX_NUMBER && straightup_number >0)
				isValid = straightup_number;
			else
				cout << "You entered an invalid number! Enter another number: ";

			remaining_amount -= straightBet;
			straightMade = true;
			break;

		//spin the wheel
		case 'd':
			rouletteSpin = (rand() % 38);
			cout << "The number is " << rouletteSpin << endl;

		// if they made even bet and even number, then they keep bet and earn additional amount
			if (betA == true && rouletteSpin %2 == 0)
				{
					evenWinning = (evenBet*(EVEN_ODD_PAYOUT+1));
					cout << "Winnings from Even: " << evenWinning << endl;
				}

			if (betB == true && rouletteSpin%2 == 1)
				{
					oddWinning = (oddBet*(EVEN_ODD_PAYOUT+1));
					cout << "Winnings from Odd: " << oddWinning << endl;
				}

			if (straightBet == true && rouletteSpin == straightup_number)
				{
					straightWinning = (straightBet*STRAIGHT_UP_PAYOUT);
					cout << "Winnings from StraightUp: " << straightWinning << endl; 
				}

		// calculate total winnings and update players purse
			winningPurse = evenWinning+oddWinning+straightWinning;
			remaining_amount+= winningPurse;

			//reset bet values to 0 and player number to default
			evenBet = 0;
			oddBet = 0;
			straightBet = 0;
			rouletteSpin = DEFAULT_PLAYER_NUMBER;
			break;

		case 'q':
			user_choice = QUIT;
			break;
		}

	} while (user_choice != QUIT);

	cout << "Thanks for playing, " << user_name << "!" << endl << endl;

}