#pragma once
#include<SFML\Graphics.hpp>
class Brick {

public:
	Brick() {
		brick.setSize({90,40});
	}
	~Brick()=default;
	void drawTo(sf::RenderWindow &window) { window.draw(brick); }
	void setPos(sf::Vector2f newpos) { brick.setPosition(newpos); }
	sf::Vector2f getPos() { return brick.getPosition(); }
	sf::Vector2f getSize() { return brick.getSize(); }
	float getY() { return brick.getPosition().y; }
	float getX() { return brick.getPosition().x; }
	sf::FloatRect getBounds() { return brick.getGlobalBounds(); }

private:
	sf::RectangleShape brick;

};
