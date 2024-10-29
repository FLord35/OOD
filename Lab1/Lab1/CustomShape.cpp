#include "CustomShape.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


CustomShape::CustomShape(sf::Shape* shapePtr):
	shape(shapePtr)
{
}

CustomShape::~CustomShape()
{
	delete shape;
}

CustomShape::CustomShape(const CustomShape& other)
{
	switch (other.shapeType)
	{
		case cconsts::CIRCLE:
			shape = new sf::CircleShape(*dynamic_cast<sf::CircleShape*>(other.shape));
			break;
		case cconsts::TRIANGLE:
			shape = new sf::ConvexShape(*dynamic_cast<sf::ConvexShape*>(other.shape));
			break;
		case cconsts::RECTANGLE:
			shape = new sf::RectangleShape(*dynamic_cast<sf::RectangleShape*>(other.shape));
			break;
		default:
			shape = nullptr;
			shapeType = cconsts::NO_SHAPE;
			break;
	}
}

void CustomShape::DrawShape(WindowWrapper& window)
{
	window.Draw(shape);
}


cconsts::ShapeType CustomShape::GetShapeType()
{
	return shapeType;
}
