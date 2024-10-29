#include "TriangleShapeMathDecorator.h"
#include "CustomShapeMathDecorator.h"
#include "CustomTriangleShape.h"
#define _USE_MATH_DEFINES
#include <math.h>

TriangleShapeMathDecorator::TriangleShapeMathDecorator(CustomTriangleShape* triangleShapePtr) :
	CustomShapeMathDecorator(triangleShapePtr)
{
	shapeType = cconsts::TRIANGLE;
}

double TriangleShapeMathDecorator::GetPerimeter()
{
	sf::ConvexShape* localShape = dynamic_cast<sf::ConvexShape*>(shape);

	double firstSideLength = getLength(localShape->getPoint(0), localShape->getPoint(1));
	double secondSideLength = getLength(localShape->getPoint(1), localShape->getPoint(2));
	double thirdSideLength = getLength(localShape->getPoint(2), localShape->getPoint(0));

	return firstSideLength + secondSideLength + thirdSideLength;
}

double TriangleShapeMathDecorator::GetArea()
{
	sf::ConvexShape* localShape = dynamic_cast<sf::ConvexShape*>(shape);

	double halfPerimeter = GetPerimeter()/2;

	double firstSideLength = getLength(localShape->getPoint(0), localShape->getPoint(1));
	double secondSideLength = getLength(localShape->getPoint(1), localShape->getPoint(2));
	double thirdSideLength = getLength(localShape->getPoint(2), localShape->getPoint(0));

	double area = std::sqrt(halfPerimeter * (halfPerimeter - firstSideLength) * (halfPerimeter - secondSideLength) * (halfPerimeter - thirdSideLength));

	return area;
}

double TriangleShapeMathDecorator::getLength(sf::Vector2f firstPoint, sf::Vector2f secondPoint)
{
	return std::sqrt(std::pow(firstPoint.x - secondPoint.x, 2) + std::pow(firstPoint.y - secondPoint.y, 2));
}
