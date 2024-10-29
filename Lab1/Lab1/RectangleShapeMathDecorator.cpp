#include "RectangleShapeMathDecorator.h"
#include "CustomShapeMathDecorator.h"
#include "CustomRectangleShape.h"
#define _USE_MATH_DEFINES
#include <math.h>

RectangleShapeMathDecorator::RectangleShapeMathDecorator(CustomRectangleShape* rectangleShapePtr) :
	CustomShapeMathDecorator(rectangleShapePtr)
{
	shapeType = cconsts::RECTANGLE;
}

double RectangleShapeMathDecorator::GetPerimeter()
{
	int height = dynamic_cast<sf::RectangleShape*>(shape)->getLocalBounds().height;
	int width = dynamic_cast<sf::RectangleShape*>(shape)->getLocalBounds().width;

	return width * 2 + height * 2;
}

double RectangleShapeMathDecorator::GetArea()
{
	int height = dynamic_cast<sf::RectangleShape*>(shape)->getLocalBounds().height;
	int width = dynamic_cast<sf::RectangleShape*>(shape)->getLocalBounds().width;

	return width * height;
}
