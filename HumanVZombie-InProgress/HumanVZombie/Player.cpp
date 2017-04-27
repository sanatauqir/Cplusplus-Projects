#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

const int EMPTY = 0;
const int HAS_BRAIN = 1;

Player::Player(Arena* ap, int r, int c) {
	if (ap == nullptr) {
		cout << "***The player must be created in some Arena!***" << endl;
		exit(1);
	}
	if (r < 1 || r > ap->rows() || c < 1 || c > ap->cols()) {
		cout << "***Zombie created with invalid coordinates(" << r << "," << c << ")!" << endl;
		exit(1);
	}
	m_arena = ap;
	m_row = r;
	m_col = c;
	m_dead = false;
}

int Player::row() const {
	//return what row the player is at
	return m_row;
}

int Player::col() const {
	//return what col the player is at
	return m_col;
}

string Player::dropBrain() {
	if (m_arena->getCellStatus(m_row, m_col) == HAS_BRAIN)
		return "There's already a brain at this spot.";
	m_arena->setCellStatus(m_row, m_col, HAS_BRAIN);
	return "A brain has been dropped.";
}

string Player::move(int dir) {
	//TODO: attempt to move the player one step in the indicated direction. if this fails,
	//return "Player couldn't move, player stands."
	//A player who moves onto a zombie dies, and this retuns
	//"PLayer walked into a zombie and died"
	//Otherwise, return one of "Player moved north." east, south, west
}

bool Player::isDead() const {
	//return whether the player is dead
	return false;
}

void Player::setDead() {
	m_dead = true;
}