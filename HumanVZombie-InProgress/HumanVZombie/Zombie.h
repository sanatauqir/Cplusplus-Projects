#pragma once
#include "Arena.h"

class Arena;

class Zombie {
public:
	//Constructor
	Zombie(Arena *ap, int r, int c);

	//Accessors
	int row() const;
	int col() const;

	//Functions
	bool isDead() const;
	void move();

private:
	//array of pointers to the arena
	Arena* m_arena;
	int m_row;
	int m_col;
};