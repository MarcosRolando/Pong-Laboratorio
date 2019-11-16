#include "Player.h"
#include <Windows.h>
#include "pch.h"

#define MAX_Y_POSITION 15 //esta en base a la posicion media de la barra del jugador
#define MIN_Y_POSITION 2

Player::Player(int yPosition, char up, char down) {
	this->ogyPosition = yPosition;
	this->yPosition = yPosition;
	this->up = up;
	this->down = down;
	score = 0;
}

int Player::getyPosition() {
	return yPosition;
}

void Player::reset() {
	yPosition = ogyPosition;
}

void Player::scores() {
	score++;
}

int Player::getScore() {
	return score;
}

void Player::move() {
	if ( (GetKeyState(up) & 0x8000) && (yPosition > MIN_Y_POSITION)) { //la comparacion con 0x8000 hace que si tocas una vez se mueve una sola vez
		yPosition--;
	}
	else if ( (GetKeyState(down) & 0x8000) && (yPosition < MAX_Y_POSITION) ) {
		yPosition++;
	}
}

Player::~Player() {
}
