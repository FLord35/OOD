#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "CustomShape.h"
#include "Constants.h"
class CustomRectangleShape : public CustomShape
{
	public:
		CustomRectangleShape(sf::RectangleShape* shapePtr);
};

