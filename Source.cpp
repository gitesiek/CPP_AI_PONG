#include<SFML/Graphics.hpp>
#include"Ball.h"
#include<cstdlib>
#include<iostream>
int main()
{

	int a = 1;

	float px = 90;
	float pd = 20;
	srand(time(NULL));
	float s = 0.05;
	float x = 450, y = 300;
	bool p, g;
	int l, d;
	l = std::rand() % 2;
	d = std::rand() % 2;
	if (l == 0) p = false;
	else p = true;
	if (d == 0) g = false;
	else g = true;
	const int manyBricks = 18;
	float bx, by = 10;
	float spc = 10;

	///////////////vars	

		bool plrs = false;
		sf::RenderWindow window(sf::VideoMode(1400, 700), "Pong");
		Ball ball({ 20, 20 });
		ball.setPos({ 1400 /2,700 /2 });
		Pad pad1({ 30 ,px });
		Pad pad2({ 30 ,px });
		pad1.setPos({ 0, 700/2 });
		pad2.setPos({ (1400 -pad2.getSize().x), 700 /2 });
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					pad1.move({ 0 ,-pd });
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					pad1.move({ 0 ,pd });
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					if (plrs) {
						pad2.move({ 0 ,-pd });
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					if (plrs) {
						pad2.move({ 0 ,pd });
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					window.close();
				}
			}
			if (ball.isColliding(pad1)) {
				p = !p;
				s += 0.01;
			}
			if (ball.isColliding(pad2)) {
				p = !p;
				s += 0.01;
			}
			//////////////Basic ai that plays the game itself
			if (!plrs) {
				if (ball.getX() > 1100) {

					if (pad2.getPos().y + pad2.getSize().y / 2 > ball.getPos().y)
					{
						pad2.move({ 0 , -0.05F });
					}
					if (pad2.getPos().y + pad2.getSize().y / 2 < ball.getPos().y)
					{
						pad2.move({ 0 , 0.05F });
					}
				}
			}
			if (!plrs) {
				if (ball.getX() < 300) {
					if (pad1.getPos().y + pad1.getSize().y / 2 > ball.getPos().y)
					{
						pad1.move({ 0 ,-pd });
					}
					if (pad1.getPos().y + pad1.getSize().y / 2 < ball.getPos().y)
					{
						pad1.move({ 0 ,pd });
					}
				}
			}
			if (x + ball.getSize().x >= 1400) { x = 1400 / 2; y = 700 / 2; pad1.score++; std::cout << "Score: pad1= " << pad1.score << " pad2= " << pad2.score << std::endl; s = 0.05; p = rand() % 2; g = rand() % 2; }
			if (x <= 0) { x = 1400 / 2; y = 700 / 2; pad2.score++; std::cout << "Score: pad1= " << pad1.score << " pad2= " << pad2.score << std::endl; s = 0.05; p = rand() % 2; g = rand() % 2;	}
			if (y <= 0) { g = false; s -= 0.001; }
			if (y + ball.getSize().y >= 700) {g = true; s -= 0.001;}

			if (p) x = x - s;
			else x = x + s;
			if (g) y = y - s;
			else y = y + s;

			if(pad1.getY() <= 0) pad1.setPos({ 0 ,0 });
			if (pad1.getY()+pad1.getSize().y >= 700) pad1.setPos({ 0 ,700-pad1.getSize().y });
			if (pad2.getY() <= 0) pad2.setPos({ (1400 - pad2.getSize().x) ,0 });
			if (pad2.getY() + pad2.getSize().y >= 700) pad2.setPos({ (1400 - pad2.getSize().x) ,700 - pad2.getSize().y });

			window.clear();
			ball.drawTo(window);
			pad1.drawTo(window);
			pad2.drawTo(window);

			ball.setPos({ x,y });
			window.display();
		}
	}
