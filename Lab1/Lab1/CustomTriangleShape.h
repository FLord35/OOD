#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "CustomShape.h"
#include "Constants.h"
class CustomTriangleShape : public CustomShape
{
	public:
		CustomTriangleShape(sf::ConvexShape* shapePtr);
};

