#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;
const int NUMDIRS = 4;

const int EMPTY = 0;
const int HAS_BRAIN = 1;


Game::Game(int rows, int cols, int nZombies) {
	if (nZombies < 0 || nZombies > MAXZOMBIES) {
		cout << "***Game created with invalid number of zombies: " << nZombies << endl;
		exit(1);
	}
	int nEmpty = rows*cols - nZombies - 1;
	if (nEmpty < 0) {
		cout << "**Game created with a " << rows << " by " << cols << " arena, which is too small to hold a player and "
			<< nZombies << " zombies!" << endl;
		exit(1);	
	}
	m_arena = new Arena(rows, cols);

	int rPlayer;
	int cPlayer;
	do {
		rPlayer = randInt(1, rows);
		cPlayer = randInt(1, cols);
	} while (m_arena->getCellStatus(rPlayer, cPlayer) != EMPTY);
		m_arena->addPlayer(rPlayer, cPlayer);

	//populate with zombies
	while (nZombies > 0) {
		int r = randInt(1, rows);
		int c = randInt(1, cols);
		if (r == rPlayer && c == cPlayer) {
			continue;
		}
		m_arena->addZombie(r, c);
		nZombies--;
	}
}

Game::~Game() {
	delete m_arena;
}

string Game::takePlayerTurn() {
	for (;;) {
		cout << "your move (n/e/s/w/x or nothing): ";
		string playerMove;
		getline(cin, playerMove);
		
		Player* player = m_arena->player();
		int dir;

		if (playerMove.size() == 0)
		{
			if (recommendMove(*m_arena, player->row(), player->col(), dir))
				return player->move(dir);
			else
				return player->dropBrain();
		}
		else if (playerMove.size() == 1) {
			if (tolower(playerMove[0]) == 'x')
				return player->dropBrain();
			else if (charToDir(playerMove[0], dir))
				return player->move(dir);
		}
		cout << "Player move must be nothing, or 1 character n/e/s/w/x." << endl;
	}
}

void Game::play() {
	m_arena->display("");
	while (!m_arena->player()->isDead() && m_arena->zombieCount() > 0) {
		string msg = takePlayerTurn();
		Player* player = m_arena->player();
		if (player->isDead())
			break;
		m_arena->moveZombies();
		m_arena->display(msg);
	}
	if (m_arena->player()->isDead())
		cout << "You lose." << endl;
	else
		cout << "You win." << endl;
}


int randInt(int lowest, int highest) {
	if (highest < lowest)
		swap(highest, lowest);
	return lowest + (rand() % (highest - lowest + 1));
}

bool charToDir(char ch, int& dir) {
	switch (tolower(ch)) {
	case 'n':
		dir = NORTH;
		break;
	case 'e':
		dir = EAST;
		break;
	case 's':
		dir = SOUTH;
		break;
	case 'w':
		dir = WEST;
		break;
	default:
		return false;

	}
	return true;
}

bool attemptMove(const Arena& a, int dir, int& r, int& c) {
	//return false without changing anything if moving one step from (r, c)
	//in the indicated direction would run off the edge of the arena.
	//otherwise, update r and c to the position resulting from the move
	//and return true
}

bool recommendMove(const Arena& a, int r, int c, int& bestDir) {
//your replacement implement should do something intelligent
	//if staying put runs the risk of a zombie possibly moving only the other player's location when the zombies
	//move, yet moving in a particular direction pts the player in a position that is safe when the zombies move, then the
	//chosen action is to move to a safer location
	//similarly, if staying put is safe, but moving in certain directions puts the player in danger, then the chosen action
	//should not be to move in one of the dangerous direcitions; instead, the player should stay put or move to another
	//safe position. in general, a position that may be moved to by many zombies is more dangerous than one
	//that may be moved to by few.
	//unless you want to , you do not have to take into account that a zombie might be poisoned and thus sometimes
	//less dangerous than one that is not. that requires a more sophisticated analysis that we're not asking you to do.



}
