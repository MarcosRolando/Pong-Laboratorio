#pragma once
class Player {
private:
	int score;
protected:
	int yPosition, ogyPosition;
	char up, down;
public:
	Player(int yPosition, char up, char down);
	int getyPosition();
	void reset();
	void move();
	int getScore();
	void scores();
	~Player();
};

