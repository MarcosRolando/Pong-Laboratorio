#pragma once

enum ball_direction {
	DOWNRIGHT, 
	UPRIGHT, 
	RIGHT, 
	LEFT, 
	UPLEFT, 
	DOWNLEFT 
};

class Ball
{
private:
	int ogxPosition, ogyPosition;
	int xPosition, yPosition;
	ball_direction direction;
public:
	Ball(int xPosition, int yPosition);
	void reset();
	void move();
	ball_direction getDirection();
	void changeDirection();
	void newRightDirection();
	void newLeftDirection();
	int getxPosition();
	int getyPosition();
	~Ball();
};

