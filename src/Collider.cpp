#include "Collider.h"
#include <iostream>

class OrientedBoundingBox // Used in the BoundingBoxTest
{
public:
	OrientedBoundingBox(const sf::Sprite& Object) // Calculate the four points of the OBB from a transformed (scaled, rotated...) sprite
	{
		sf::Transform trans = Object.getTransform();
		sf::IntRect local = Object.getTextureRect();
		Points[0] = trans.transformPoint(0.f, 0.f);
		Points[1] = trans.transformPoint(local.width, 0.f);
		Points[2] = trans.transformPoint(local.width, local.height);
		Points[3] = trans.transformPoint(0.f, local.height);
	}

	sf::Vector2f Points[4];

	void ProjectOntoAxis(const sf::Vector2f& Axis, float& Min, float& Max) // Project all four points of the OBB onto the given axis and return the dotproducts of the two outermost points
	{
		Min = (Points[0].x*Axis.x + Points[0].y*Axis.y);
		Max = Min;
		for (int j = 1; j<4; j++)
		{
			float Projection = (Points[j].x*Axis.x + Points[j].y*Axis.y);

			if (Projection<Min)
				Min = Projection;
			if (Projection>Max)
				Max = Projection;
		}
	}
};


Collider::Collider(sf::RectangleShape& body) :
	body(body)
{

}

Collider::~Collider()
{
}

/*
bool Collider::CheckCollision(Collider & other, float push)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (intersectX > intersectY) {
			if (deltaX > 0.0f) {
				Move(intersectX * (1.0f - push), 0.0f);
				std::cout << "move" << std::endl;
				other.Move(-intersectX * push, 0.0f);
			} else {
				std::cout << "move" << std::endl;
				Move(-intersectX * (1.0f - push), 0.0f);
				other.Move(intersectX * push, 0.0f);
			}
		} else {
			if (deltaY > 0.0f) {
				std::cout << "move" << std::endl;
				Move(0.0f, intersectY * (1.0f - push));
				other.Move(0.0f, -intersectY * push);
			} else {
				std::cout << "move" << std::endl;
				Move(0.0f, -intersectY * (1.0f - push));
				other.Move(0.0f, intersectY * push);
			}
		}
		return true;
	}

	return false;
}
*/

bool Collider::BoundingBoxTest(const sf::Sprite& Object1, const sf::Sprite& Object2) {
	OrientedBoundingBox OBB1(Object1);
	OrientedBoundingBox OBB2(Object2);

	// Create the four distinct axes that are perpendicular to the edges of the two rectangles
	sf::Vector2f Axes[4] = {
		sf::Vector2f(OBB1.Points[1].x - OBB1.Points[0].x,
		OBB1.Points[1].y - OBB1.Points[0].y),
		sf::Vector2f(OBB1.Points[1].x - OBB1.Points[2].x,
		OBB1.Points[1].y - OBB1.Points[2].y),
		sf::Vector2f(OBB2.Points[0].x - OBB2.Points[3].x,
		OBB2.Points[0].y - OBB2.Points[3].y),
		sf::Vector2f(OBB2.Points[0].x - OBB2.Points[1].x,
		OBB2.Points[0].y - OBB2.Points[1].y)
	};

	for (int i = 0; i<4; i++) // For each axis...
	{
		float MinOBB1, MaxOBB1, MinOBB2, MaxOBB2;

		// ... project the points of both OBBs onto the axis ...
		OBB1.ProjectOntoAxis(Axes[i], MinOBB1, MaxOBB1);
		OBB2.ProjectOntoAxis(Axes[i], MinOBB2, MaxOBB2);

		// ... and check whether the outermost projected points of both OBBs overlap.
		// If this is not the case, the Separating Axis Theorem states that there can be no collision between the rectangles
		if (!((MinOBB2 <= MaxOBB1) && (MaxOBB2 >= MinOBB1)))
			return false;
	}
	return true;
}