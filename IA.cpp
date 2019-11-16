#include "IA.h"
#include "Ball.h"
#include <cstdlib>
#include <iostream>
#include "Constants.h"

#define MAX_Y_POSITION 15 //esta en base a la posicion media del jugador
#define MIN_Y_POSITION 2

IA::IA(int yPosition) : Player(yPosition, 0, 1) {
	positionDiff = 0;
	moveDirection = 0;
}

void IA::calculateDestiny(Ball& ball) {
	int xPos = ball.getxPosition(), yPos = ball.getyPosition();
	int finalBallPos = 0;
	ball_direction dir = ball.getDirection();
	bool finished = false;

	while (!finished) {
		switch (dir) {
		case DOWNRIGHT:
			while (yPos != BOTTOM_ROW && xPos != RIGHT_COLUMN) {
				yPos++;
				xPos++;
			}
			if (xPos == RIGHT_COLUMN) {
				finalBallPos = yPos;
				finished = true;
			} else {
				dir = UPRIGHT;
			}
			break;
		case UPRIGHT:
			while (yPos != TOP_ROW && xPos != RIGHT_COLUMN) {
				yPos--;
				xPos++;
			}
			if (xPos == RIGHT_COLUMN) {
				finalBallPos = yPos;
				finished = true;
			} else {
				dir = DOWNRIGHT;
			}
			break;
		case RIGHT:
			finalBallPos = yPos;
			finished = true;
			break;
		case LEFT:
			finalBallPos = yPos;
			finished = true;
			break;
		case UPLEFT:
			while (yPos != TOP_ROW && xPos != LEFT_COLUMN) {
				yPos--;
				xPos--;
			}
			if (xPos == LEFT_COLUMN) {
				finalBallPos = yPos;
				finished = true;
			} else {
				dir = DOWNLEFT;
			}
			break;
		case DOWNLEFT:
			while (yPos != BOTTOM_ROW && xPos != LEFT_COLUMN) {
				yPos++;
				xPos--;
			}
			if (xPos == LEFT_COLUMN) {
				finalBallPos = yPos;
				finished = true;
			} else {
				dir = UPLEFT;
			}
			break;
		}
	}
	positionDiff = finalBallPos - yPosition;
	if (positionDiff < 0) moveDirection = up;
	else if (positionDiff > 0) moveDirection = down;
	positionDiff = abs(positionDiff);
}

void IA::move() {
	if ((moveDirection == up) && (yPosition > MIN_Y_POSITION)) { 
		if (positionDiff != 0) {
			yPosition--;
			positionDiff--;
		}
	} else if ((moveDirection == down) && (yPosition < MAX_Y_POSITION)) {
		if (positionDiff != 0) {
			yPosition++;
			positionDiff--;
		}
	}
}

IA::~IA() {
}
