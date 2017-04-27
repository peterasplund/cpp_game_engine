#include "Player.h"

Player::Player(Texture_Name sprite, sf::Vector2f position)
	: Entity(sprite, position) {
	groupID = GroupIDS::NORMAL;

	int tw = 39;
	int th = 63;

	body.setSize({ (float)tw, (float)th });
	this->sprite.setScale({ 2, 2 });
	this->sprite.setTextureRect(body.getTextureRect());
	
	walkSpeed = 4;

	walkAnimation.addFrame({ 0,      0, tw, th }, 0.1);
	walkAnimation.addFrame({ tw,     0, tw, th }, 0.1);
	walkAnimation.addFrame({ tw * 2, 0, tw, th }, 0.1);
	walkAnimation.addFrame({ tw * 3, 0, tw, th }, 0.1);
	walkAnimation.addFrame({ tw * 4, 0, tw, th }, 0.1);
	walkAnimation.addFrame({ tw * 5, 0, tw, th }, 0.1);
	walkAnimation.addFrame({ tw * 6, 0, tw, th }, 0.1);
	walkAnimation.addFrame({ tw * 7, 0, tw, th }, 0.1);
	walkAnimation.addFrame({ tw * 8, 0, tw, th }, 0.1);
	walkAnimation.addFrame({ tw * 9, 0, tw, th }, 0.1);

	jumpAnimation.addFrame({ tw * 10, 0, tw, th }, 0.1);

	currentAnimation = &walkAnimation;
}


bool Player::update(float dt)
{
	if (velocity.x != 0) {
		velocity.x = 0;
	}
	if (velocity.y != 0) {
		velocity.y = 0;
	}
	if (velocity.y > maxVelocityY) {
		velocity.y = maxVelocityY;
	}

	// velocity.y += gravity;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		direction = Direction::LEFT;
		velocity.x =- walkSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		direction = Direction::RIGHT;
		velocity.x = walkSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		velocity.y =- walkSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		velocity.y = walkSpeed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		// jump
	}

	if (velocity.x != 0) {
		currentAnimation->play();
	}
	else {
		currentAnimation->stop();
	}

	sf::IntRect rect = currentAnimation->getFrame();

	if (direction == Direction::LEFT) {
		rect = sf::IntRect(rect.left + rect.width, rect.top, -rect.width, rect.height);
	}
	else {
		rect = sf::IntRect(rect.left, rect.top, rect.width, rect.height);
	}

	Entity::update(dt);

	sprite.setTextureRect(rect);
	return true;
}

void Player::collision(Entity* entity)
{
	std::cout << entity->getGroupID()<< std::endl;
	switch (entity->getGroupID())
	{
	case GroupIDS::COLLECTIBLE:
		entity->destroy();
		break;
	case GroupIDS::COLLISION:
		getCollider().BoundingBoxTest(sprite, entity->sprite);
		// texture.setPosition(body.getPosition());
		break;
	}
}
