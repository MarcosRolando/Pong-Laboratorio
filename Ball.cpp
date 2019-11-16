#include "Ball.h"
#include <stdlib.h>
#include <time.h>
#include "pch.h"
#include <vector>
#include "Constants.h"


Ball::Ball(int yPosition, int xPosition) {
	srand(time(NULL));
	this->ogxPosition = xPosition;
	this->ogyPosition = yPosition;
	this->xPosition = xPosition;
	this->yPosition = yPosition;
	std::vector<ball_direction> list{ RIGHT, LEFT };
	int index = rand() % list.size();
	direction = list[index];
}

int Ball::getxPosition() {
	return xPosition;
}

ball_direction Ball::getDirection() {
	return direction;
}

int Ball::getyPosition() {
	return yPosition;
}

void Ball::reset() {
	xPosition = ogxPosition;
	yPosition = ogyPosition;
	std::vector<ball_direction> list{ RIGHT, LEFT };
	int index = rand() % list.size();
	direction = list[index];
}

void Ball::newRightDirection() {
	if (yPosition == BOTTOM_ROW) {
		std::vector<ball_direction> list{RIGHT, UPRIGHT};
		int index = rand() % list.size();
		direction = list[index];
	} else if (yPosition == TOP_ROW) {
		std::vector<ball_direction> list{ RIGHT, DOWNRIGHT};
		int index = rand() % list.size();
		direction = list[index];
	} else {
		std::vector<ball_direction> list{ RIGHT, UPRIGHT, DOWNRIGHT };
		int index = rand() % list.size();
		direction = list[index];
	}
}

void Ball::newLeftDirection() {
	if (yPosition == BOTTOM_ROW) {
		std::vector<ball_direction> list{ LEFT, UPLEFT };
		int index = rand() % list.size();
		direction = list[index];
	}
	else if (yPosition == TOP_ROW) {
		std::vector<ball_direction> list{ LEFT, DOWNLEFT };
		int index = rand() % list.size();
		direction = list[index];
	}
	else {
		std::vector<ball_direction> list{ LEFT, UPLEFT, DOWNLEFT };
		int index = rand() % list.size();
		direction = list[index];
	}
}

void Ball::move() {
	switch (direction) {
	case RIGHT:
		xPosition++;
		break;
	case LEFT:
		xPosition--;
		break;
	case UPRIGHT:
		xPosition++;
		yPosition--;
		break;
	case UPLEFT:
		xPosition--;
		yPosition--;
		break;
	case DOWNRIGHT:
		xPosition++;
		yPosition++;
		break;
	case DOWNLEFT:
		xPosition--;
		yPosition++;
		break;
	}
}

void Ball::changeDirection() {
	switch (direction) {
	case UPLEFT:
		direction = DOWNLEFT;
		break;
	case DOWNLEFT:
		direction = UPLEFT;
		break;
	case UPRIGHT:
		direction = DOWNRIGHT;
		break;
	case DOWNRIGHT:
		direction = UPRIGHT;
		break;
	}
}

Ball::~Ball() {
}
