#include "CustomRectangleShape.h"

CustomRectangleShape::CustomRectangleShape(sf::RectangleShape* shapePtr):
	CustomShape(shapePtr)
{
	shapeType = cconsts::RECTANGLE;
}
