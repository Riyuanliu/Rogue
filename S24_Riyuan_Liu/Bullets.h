#pragma once
#include "Rogue.h"
#include "Player.h"
#include "Enemy.h"
class Bullets {
public:
	Bullets();
	Bullets(int x, int y, Direction direction, std::string filepath, int speed, int damage);
	void render();
	Direction getdirection();

	void movingX(int x);
	void movingY(int y);

	int getX();
	int getY();

	void bulletMove();
	bool collidesWith(const Enemy& enemy) const;

	bool operator==(const Bullets& other) const {
		return x == other.x && y == other.y && direction == other.direction;
	}
	int getDamage();
private:
	int x;
	int y;
	int damage;
	int speed;
	Rogue::Image currentImage{ "../Assets/Textures/Bullet/Bullet1.png" };
	Direction direction;

};