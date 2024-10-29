#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "CustomShapeMathDecorator.h"
#include "CustomCircleShape.h"

class CircleShapeMathDecorator : public CustomShapeMathDecorator
{
	public:
		CircleShapeMathDecorator(CustomCircleShape* circleShapePtr);

		virtual double GetPerimeter();

		virtual double GetArea();
};

