#include "Zombie.h"
#include <iostream>

using namespace std;

Zombie::Zombie(Arena *ap, int r, int c) {
	if (ap == nullptr)
	{
		cout << "***A zombie must be created in some Arena!***" << endl;
	}
	if (r < 1 || r > ap->rows() || c < 1 || c > ap->cols()) {
		cout << "***Zombie created with invalid coordinates(" << r << "," << c << ")!" << endl;
		exit(1);
	}
	m_arena = ap;
	m_row = r;
	m_col = c;
}

int Zombie::row() const {
	return m_row;
}

int Zombie::col() const {
	return m_col;
}

//return whether the zombie is dead
bool Zombie::isDead() const {
	return false;
}

void Zombie::move(){
	//TODO: Return without moving i the zombie has eaten one brain (so is supposed to move only every other turn)
	//and this is a turn it does not move
	//Otherwise, attempt to move in a random direction; if it can't move, don't move
	//If it lands on a poisoned brain, eat the brain, so it is no longer on that grid point.
}



