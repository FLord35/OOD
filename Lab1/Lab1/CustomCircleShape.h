#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "CustomShape.h"
#include "Constants.h"
class CustomCircleShape : public CustomShape
{
	public:
		CustomCircleShape(sf::CircleShape* shapePtr);
};

