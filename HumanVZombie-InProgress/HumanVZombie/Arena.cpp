#include "Arena.h"
#include <string>
#include <iostream>

using namespace std;

const int MAXROWS = 20;
const int MAXCOLS = 20;
const int EMPTY = 0;
const int HAS_BRAIN = 1;

Arena::Arena(int nRows, int nCols) {
	if (nRows <= 0 || nCols <= 0 || nRows > MAXROWS || nCols > MAXCOLS) {
		cout << "***Area created with invalid size " << nRows << " by " << nCols << "!" << endl;
			exit(1);
	}
	m_rows = nRows;
	m_cols = nCols;
	m_player = nullptr;
	m_nZombies = 0;
	m_turns = 0;
	for (int r = 1; r <= m_rows; r++) {
		for (int c = 1; c <= m_cols; c++) {
			setCellStatus(r, c, EMPTY);
		}
	}
}

Arena::~Arena() {
	//TODO: release the player and all remaining dynamically allocated robots
}

int Arena::rows() const {
	//return the number of rows in the arena
	return m_rows;
}

int Arena::cols() const {
	//return the number of cols in the arena
	return m_cols;
}

Player* Arena::player() const {
	return m_player;
}

int Arena::zombieCount() const {
	//return the number of zombies in the arena
	return m_nZombies;
}

int Arena::getCellStatus(int r, int c) const {
	checkPos(r, c);
	return m_grid[r - 1][c - 1];
}

int Arena::numberOfZombiesAt(int r, int c) const {
	//TODO: return the number of zombies at r, c
	return numberOfZombiesAt(r, c);
}

void Arena::display(string msg) const {
	char displayGrid[MAXROWS][MAXROWS];
	int r, c;
	for (r = 1; r <= rows(); r++) {
		for (c = 1; c <= cols(); c++) {
			displayGrid[r - 1][c - 1] = (getCellStatus(r, c) == EMPTY ? '.' : '*');
		}
		//indicate each zombie's position
		//if one zombie is at some grid point, set the displayGrid char
		//to 'Z' if it's 2 through 8, set it to '2' through '8'
		//For 9 or more set it to 9

	}
		//Indicate the players position
		if (m_player != nullptr) {
			displayGrid[m_player->row() - 1][m_player->col() - 1] = (m_player->isDead() ? 'X' : '@');
		}
		//draw the grid

		//builtin??
	clearScreen();
	
	for (r = 1; r <= rows(); r++) {
		for (c = 1; c <= cols(); c++) {
			cout << displayGrid[r - 1][c - 1];
		cout << endl;
		}
	}
	cout << endl;

	//Write message, zombie and player info
	if (msg != "")
		cout << msg << endl;
	cout << "There are " << zombieCount() << " zombies remaining." << endl;
	if (m_player == nullptr)
		cout << "There is no player!" << endl;
	else if (m_player->isDead())
		cout << "The player is dead." << endl;
	cout << m_turns << " turns have been taken." << endl;
}

void Arena::setCellStatus(int r, int c, int status) {
	checkPos(r, c);
	m_grid[r-1][c-1] = status;
}

bool Arena::addZombie(int r, int c) {
	if (m_nZombies == MAXZOMBIES)
		return false;
	m_zombies[m_nZombies] = new Zombie(this, r, c);
	m_nZombies++;
	return true;
}

bool Arena::addPlayer(int r, int c) {
	if (m_player != nullptr)
		return false;

	//dynamically allocate new player and add to arena
	m_player = new Player(this, r, c);
	return true;
}

void Arena::moveZombies() {
	//move all zombies, mark the player as dead if necessary.
	//release any dead dynamically allocated zombie
	//another turn taken
	m_turns++;

}

void Arena::checkPos(int r, int c) const {
	if (r < 1 || r > m_rows || c < 1 || c > m_cols) {
		cout << "***Invalid arena position (" << r << "," << c << ")" << endl;
		exit(1);
	}


}
