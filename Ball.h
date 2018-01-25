#pragma once
#include<SFML\Graphics.hpp>
#include"Pad.h"
#include"Brick.h"
class Ball {

public:
	Ball(sf::Vector2f size) {
		ball.setSize(size);
	}
	void drawTo(sf::RenderWindow &window) { window.draw(ball); }
	void setPos(sf::Vector2f newpos) { ball.setPosition(newpos); }
	sf::Vector2f getPos() { return ball.getPosition(); }
	sf::Vector2f getSize() { return ball.getSize(); }
	float getY() { return ball.getPosition().y; }
	float getX() { return ball.getPosition().x; }
	sf::FloatRect getBounds() { return ball.getGlobalBounds(); }
	bool isColliding(Pad x)
	{
		if (ball.getGlobalBounds().intersects(x.getBounds()))
		{
			return true;
		}
		else return false;
	}
	bool isColliding(Brick x)
	{
		if (ball.getGlobalBounds().intersects(x.getBounds()))
		{
			return true;
		}
		else return false;
	}
private:
	sf::RectangleShape ball;

};
