#include <iostream>
#include "Board.h"
#include "Ball.h"
#include "pch.h"

#define BALL "o "
#define BLANK "  "
#define PLAYER_PIECE char(186) << " "
#define BOARD_LIMIT char(205)
#define PLAYER1_COLUMN 0
#define PLAYER2_COLUMN (width - 1)

Board::Board(int height, int width) {
	this->height = height;
	this->width = width;
}

void Board::showScores(int scoreP1, int scoreP2) {
	std::cout << "Player 1: " << scoreP1 << "         Player 2: " << scoreP2 << std::endl;
}

//agrego para la parte visual barras extra en los laterales QUE NO VAN EN EL JUEGO CON MATRICES
void Board::print(Ball& ball, Player& player1, Player& player2) {
	int p1y = player1.getyPosition(), p2y = player2.getyPosition();
	system("CLS");
	for (int i = 0; i < height + 2; i++) {
		for (int j = 0; j < width; j++) {

			if (i == 0 || i == height + 1) {
				std::cout << BOARD_LIMIT;
				if (j < width - 1) std::cout << BOARD_LIMIT; //sweet spot para que las barras queden bien, NO TOCAR
			} else if ( (i == p1y || i == (p1y + 1) || i == (p1y - 1)) && j == PLAYER1_COLUMN) {
				std::cout << PLAYER_PIECE;
			} else if ( (i == p2y || i == (p2y + 1) || i == (p2y - 1)) && j == PLAYER2_COLUMN) {
				std::cout << PLAYER_PIECE;
			} else if (i == ball.getyPosition() && j == ball.getxPosition()) {
				std::cout << BALL;
			} else {
				std::cout << BLANK;
			}

		}
		std::cout << std::endl;
	}
	showScores(player1.getScore(), player2.getScore());
}

Board::~Board() {
}
