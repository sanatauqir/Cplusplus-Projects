#pragma once
#include "Arena.h"
#include <string>

using namespace std;

class Game {
public:
	Game(int rows, int cols, int nZombies);
	~Game();

	void play();

private:
	Arena* m_arena; //array of pointers to arena we are in
	string takePlayerTurn();  //if player chooses nothing then computer will pick turn

};