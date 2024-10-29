#include "CustomCircleShape.h"
#include "CustomShape.h"

CustomCircleShape::CustomCircleShape(sf::CircleShape* shapePtr):
	CustomShape(shapePtr)
{
	shapeType = cconsts::CIRCLE;
}
