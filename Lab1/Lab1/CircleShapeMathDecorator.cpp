#include "CircleShapeMathDecorator.h"
#include "CustomShapeMathDecorator.h"
#include "CustomCircleShape.h"
#define _USE_MATH_DEFINES
#include <math.h>

CircleShapeMathDecorator::CircleShapeMathDecorator(CustomCircleShape* circleShapePtr):
	CustomShapeMathDecorator(circleShapePtr)
{
	shapeType = cconsts::CIRCLE;
}

double CircleShapeMathDecorator::GetPerimeter()
{
	return 2 * M_PI * dynamic_cast<sf::CircleShape*>(shape)->getRadius();
}

double CircleShapeMathDecorator::GetArea()
{
	return M_PI * pow(dynamic_cast<sf::CircleShape*>(shape)->getRadius(), 2);
}
