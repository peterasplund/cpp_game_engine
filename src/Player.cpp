#include "Player.h"
#include "Display.h"
#include "Resource_Managers/Resource_Holder.h"

#include <iostream>

void Player::init()
{
	groupID = GroupIDS::NORMAL;

	int tw = 32;
	int th = 50;

	walkSpeed = 2.2;

	texture.setTexture(&Resource_Holder::get().getTexture(Texture_Name::Player));
	texture.setSize({ (float)tw * 2, (float)th * 2 });


	walkLeftAnimation.addFrame({ 0,      th * 3, tw, th }, 0.1);
	walkLeftAnimation.addFrame({ tw,     th * 3, tw, th }, 0.1);
	walkLeftAnimation.addFrame({ tw * 2, th * 3, tw, th }, 0.1);
	walkLeftAnimation.addFrame({ tw * 3, th * 3, tw, th }, 0.1);

	walkRightAnimation.addFrame({ 0,      th * 5, tw, th }, 0.1);
	walkRightAnimation.addFrame({ tw,     th * 5, tw, th }, 0.1);
	walkRightAnimation.addFrame({ tw * 2, th * 5, tw, th }, 0.1);
	walkRightAnimation.addFrame({ tw * 3, th * 5, tw, th }, 0.1);

	walkUpAnimation.addFrame({ 0,      th * 7, tw, th }, 0.1);
	walkUpAnimation.addFrame({ tw,     th * 7, tw, th }, 0.1);
	walkUpAnimation.addFrame({ tw * 2, th * 7, tw, th }, 0.1);
	walkUpAnimation.addFrame({ tw * 3, th * 7, tw, th }, 0.1);

	walkDownAnimation.addFrame({ 0,      th * 1, tw, th }, 0.1);
	walkDownAnimation.addFrame({ tw,     th * 1, tw, th }, 0.1);
	walkDownAnimation.addFrame({ tw * 2, th * 1, tw, th }, 0.1);
	walkDownAnimation.addFrame({ tw * 3, th * 1, tw, th }, 0.1);

	currentAnimation = &walkDownAnimation;
}

void Player::draw()
{
	Display::draw(texture);
}

bool Player::update(float dt)
{
	if (velocity.x != 0) {
		velocity.x = 0;
	}
	if (velocity.y != 0) {
		velocity.y = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		currentAnimation = &walkLeftAnimation;
		velocity.x -= walkSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		currentAnimation = &walkRightAnimation;
		velocity.x = walkSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		currentAnimation = &walkUpAnimation;
		velocity.y -= walkSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		currentAnimation = &walkDownAnimation;
		velocity.y += walkSpeed;
	}

	if (velocity.x != 0 || velocity.y != 0) {
		currentAnimation->play();
	}
	else {
		currentAnimation->stop();
	}


	texture.setTextureRect(currentAnimation->getFrame());

	texture.move(velocity);
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
	}
}
