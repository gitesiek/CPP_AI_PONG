#pragma once
#include<SFML\Graphics.hpp>
class Pad {

public:
	Pad(sf::Vector2f size) {
		pad.setSize(size);
	}
	void drawTo(sf::RenderWindow &window) { window.draw(pad); }
	void move(sf::Vector2f distance) { pad.move(distance); }
	void setPos(sf::Vector2f newpos) { pad.setPosition(newpos); }
	sf::Vector2f getPos() { return pad.getPosition(); }
	sf::Vector2f getSize() { return pad.getSize(); }
	float getY() { return pad.getPosition().y; }
	float getX() { return pad.getPosition().x; }
	sf::FloatRect getBounds() { return pad.getGlobalBounds(); }
	int score = 0;

private:
	sf::RectangleShape pad;

};
