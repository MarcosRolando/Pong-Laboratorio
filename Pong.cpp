#include <iostream>
#include "Ball.h"
#include "Board.h"
#include "Player.h"
#include "Pong.h"
#include <Windows.h>
#include <conio.h>
#include "pch.h"
#include "IA.h"
#include "Constants.h"

#pragma comment(lib, "winmm.lib") //es para que anden los sonidos 

void Pong::verifyBallWallCollision() {
	int position = ball.getyPosition();
	ball_direction dir = ball.getDirection();
	if ( (position == TOP_ROW || position == BOTTOM_ROW) && (dir != RIGHT && dir != LEFT) ) {
		ball.changeDirection();
		WALL_SOUND;
	}
}

void Pong::verifyPlayerCollision() {
	int ball_x = ball.getxPosition(), ball_y = ball.getyPosition();
	int p1_y = player1.getyPosition(), p2_y = player2.getyPosition();

	if (ball_x == LEFT_COLUMN + 1) {
		if (ball_y == p1_y || ball_y == (p1_y + 1) || ball_y == (p1_y - 1)) {
			ball.newRightDirection();
			PLAYER_SOUND;
			player2.calculateDestiny(ball);
		} else {
			pointFinished = true;
			player2.scores();
			SCORE_SOUND;
		}
	}

	if (ball_x == RIGHT_COLUMN - 1) {
		if (ball_y == p2_y || ball_y == (p2_y + 1) || ball_y == (p2_y - 1)) {
			ball.newLeftDirection();
			PLAYER_SOUND;
			player1.calculateDestiny(ball);
		} else {
			pointFinished = true;
			player1.scores();
			SCORE_SOUND;
		}
	}
}

void Pong::verifyGame() {
	verifyBallWallCollision();
	verifyPlayerCollision();
}

void Pong::newPoint() {
	board.print(ball, player1, player2);
	_getch();
	while (!pointFinished) {
		Sleep(GAME_SPEED); 
		verifyGame();
		player1.move();
		player2.move();
		ball.move();
		board.print(ball, player1, player2);
	}
	ball.reset();
	player1.reset();
	player2.reset();
	pointFinished = false;
	while (_kbhit()) _getch(); //esto permite que la pelota quede quieta hasta que alguien se mueva en el comienzo de cada punto
}

void Pong::run() {
	while (true) {
		newPoint();
	}
}

Pong::Pong() : player1(P1_ROW), player2(P2_ROW), ball(BALL_ROW, BALL_COLUMN), board(BOARD_HEIGHT, BOARD_WIDTH) {
	pointFinished = false;
}


Pong::~Pong() {
}
