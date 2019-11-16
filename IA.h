#pragma once
#include "Player.h"
#include "Ball.h"

class IA : public Player {
private:
	int positionDiff;
	char moveDirection;
public:
	IA(int yPosition);
	void calculateDestiny(Ball& ball);
	void move();
	~IA();
};

