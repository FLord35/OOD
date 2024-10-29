#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "CustomShapeMathDecorator.h"
#include "CustomRectangleShape.h"

class RectangleShapeMathDecorator : public CustomShapeMathDecorator
{
	public:
		RectangleShapeMathDecorator(CustomRectangleShape* rectangleShapePtr);

		virtual double GetPerimeter();

		virtual double GetArea();
};

