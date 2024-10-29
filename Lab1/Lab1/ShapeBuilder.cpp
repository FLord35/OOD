#include "ShapeBuilder.h"
#include "CustomShape.h"
#include "CustomCircleShape.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

ShapeBuilder::ShapeBuilder()
{
}

CustomCircleShape ShapeBuilder::BuildShape(cconsts::CircleAsPoints circlePoints)
{
	//TODO: погуглить фабричный метод, сделать как там

	sf::CircleShape* circle = new sf::CircleShape(circlePoints.radius);
	circle->setPosition(circlePoints.centerPointCoordinates.x, circlePoints.centerPointCoordinates.y);
	circle->setFillColor(sf::Color(0xFF, 0xFF, 0xFF)); //TODO: цвета в константы или тупо того

	CustomCircleShape customCircle(circle);

	return customCircle;
}

CustomTriangleShape ShapeBuilder::BuildShape(cconsts::TriangleAsPoints trianglePoints)
{
	sf::ConvexShape* triangle = new sf::ConvexShape;
	triangle->setPointCount(3);
	triangle->setPoint(0, sf::Vector2f(static_cast<float>(trianglePoints.firstPointCoordinates.x), static_cast<float>(trianglePoints.firstPointCoordinates.y)));
	triangle->setPoint(1, sf::Vector2f(static_cast<float>(trianglePoints.secondPointCoordinates.x), static_cast<float>(trianglePoints.secondPointCoordinates.y)));
	triangle->setPoint(2, sf::Vector2f(static_cast<float>(trianglePoints.thirdPointCoordinates.x), static_cast<float>(trianglePoints.thirdPointCoordinates.y)));
	triangle->setFillColor(sf::Color(0xFF, 0xFF, 0xFF)); //TODO: цвета в константы или тупо того

	CustomTriangleShape customTriangle(triangle);

	return customTriangle;
}

CustomRectangleShape ShapeBuilder::BuildShape(cconsts::RectangleAsPoints rectanglePoints)
{
	sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(
		static_cast<float>(rectanglePoints.secondPointCoordinates.x - rectanglePoints.firstPointCoordinates.x),
		static_cast<float>(rectanglePoints.secondPointCoordinates.y - rectanglePoints.firstPointCoordinates.y)
		));
	rectangle->setPosition(rectanglePoints.firstPointCoordinates.x, rectanglePoints.firstPointCoordinates.y);
	rectangle->setFillColor(sf::Color(0xFF, 0xFF, 0xFF)); //TODO: цвета в константы или тупо того

	CustomRectangleShape customRectangle(rectangle);

	return customRectangle;
}
