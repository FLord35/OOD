#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "CustomShapeMathDecorator.h"
#include "CustomTriangleShape.h"

class TriangleShapeMathDecorator : public CustomShapeMathDecorator
{
	public:
		TriangleShapeMathDecorator(CustomTriangleShape* triangleShapePtr);

		virtual double GetPerimeter();

		virtual double GetArea();
	
	private:
		double getLength(sf::Vector2f firstPoint, sf::Vector2f secondPoint);
};

