#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "CustomShape.h"

class CustomShapeMathDecorator : public CustomShape
{
	protected:
		CustomShape* customShape;

	public:

		CustomShapeMathDecorator(CustomShape* shapePtr);

		virtual double GetPerimeter() = 0;

		virtual double GetArea() = 0;

};

