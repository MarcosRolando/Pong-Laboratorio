#pragma once
#include "Ball.h"
#include "Player.h"

class Board {
private:
	int height, width;
public:
	Board(int height, int width);
	void print(Ball& ball, Player& player1, Player& player2);
	~Board();
private:
	void showScores(int scoreP1, int scoreP2);
};

