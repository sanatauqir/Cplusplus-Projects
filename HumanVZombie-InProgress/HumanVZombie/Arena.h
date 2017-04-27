#pragma once
#include "Player.h"
#include "Zombie.h"

const int MAXROWS = 20;
const int MAXCOLS = 20;
const int MAXZOMBIES = 10;

class Arena {
public:
	Arena(int nRows, int nCols);
	~Arena();

	int rows() const;
	int cols() const;
	Player* player() const;	//array of pointers to each player

	int zombieCount() const;
	int getCellStatus(int r, int c) const;
	int numberOfZombiesAt(int r, int c) const;
	void display(string msg) const;

	//Mutators
	void setCellStatus(int r, int c, int status);
	bool addZombie(int r, int c);
	bool addPlayer(int r, int c);
	void moveZombies(); //move a zombie randomly but not off grid, slower if brain eaten
	void checkPos(int r, int c) const;

private:
	int m_grid[MAXROWS][MAXCOLS];
	int m_rows;
	int m_cols;
	Player* m_player;	//array of pointers to players in game
	Zombie* m_zombies[MAXZOMBIES]; //array of pointers to zombies in game
	int m_nZombies;
	int m_turns;

};