#include "CustomTriangleShape.h"
#include "CustomShape.h"

CustomTriangleShape::CustomTriangleShape(sf::ConvexShape* shapePtr):
	CustomShape(shapePtr)
{
	shapeType = cconsts::TRIANGLE;
}
