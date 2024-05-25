#include "Bullets.h"

Bullets::Bullets()
{
	direction = Direction::Left;
	x = 0;
	y = 0;
	damage = 20;
}

Bullets::Bullets(int x, int y, Direction direction,std::string filepath, int speed, int damage)
{
	this->x = x;
	this->y = y;
	this->direction = direction;
	this->speed = speed;
	this->damage = damage;
	currentImage = Rogue::Image{ filepath };
}

void Bullets::render()
{
	Rogue::Renderer::Draw(currentImage, x, y);
}

Direction Bullets::getdirection()
{
	return direction;
}

void Bullets::movingX(int x)
{
	this->x += x;
}
void Bullets::movingY(int y)
{
	this->y += y;
}

int Bullets::getX()
{
	return x;
}

int Bullets::getY()
{
	return y;
}

void Bullets::bulletMove()
{
	if (direction == Direction::Left) {
		this->x += -speed;
	}
	else if (direction == Direction::right) {
		this->x += speed;
	}
	else if (direction == Direction::up) {
		this->y += speed;
	}
	else if (direction == Direction::down) {
		this->y += -speed;
	}
}

bool Bullets::collidesWith(const Enemy& enemy) const
{
	int bulletX = x;
	int bulletY = y;

	
	int bulletWidth = currentImage.GetWidth();
	int bulletHeight = currentImage.GetHeight();
	

	// Get enemy position and size
	int enemyX = enemy.getX();
	int enemyY = enemy.getY();
	int enemyWidth = enemy.getWidth();
	int enemyHeight = enemy.getHeight();

	// Check if bounding boxes overlap
	bool collisionX = bulletX < enemyX + enemyWidth && bulletX + bulletWidth > enemyX;
	bool collisionY = bulletY < enemyY + enemyHeight && bulletY + bulletHeight > enemyY;

	return collisionX && collisionY;
}

int Bullets::getDamage()
{
	return damage;
}
