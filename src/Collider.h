#pragma once
#include <SFML\Graphics.hpp>

class Collider
{
public:
	Collider(sf::RectangleShape& body);
	~Collider();

	void Move(float dx, float dy) { body.move(dx, dy); }

	// sf::IntRect CheckCollision(Collider& other, float push);
	bool BoundingBoxTest(const sf::Sprite & Object1, const sf::Sprite & Object2);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f;  }

private:
	sf::RectangleShape& body;
};

