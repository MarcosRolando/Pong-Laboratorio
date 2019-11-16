#pragma once
#include "Board.h"
#include "Ball.h"
#include "Player.h"
#include "IA.h"

class Pong {
private:
	Board board;
	Ball ball;
	IA player1, player2;
	bool pointFinished;
public:
	Pong();
	void run();
	~Pong();
private:
	void verifyBallWallCollision();
	void newPoint();
	void verifyPlayerCollision();
	void verifyGame();
};

