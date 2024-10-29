#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Constants.h"
#include "WindowWrapper.h"

class CustomShape
{
	//TODO: определить указатель через shared_ptr и заменить некоторые взаимодействия

	protected:
		sf::Shape* shape;

		cconsts::ShapeType shapeType = cconsts::NO_SHAPE;

	public:
		CustomShape(sf::Shape* shapePtr);

		virtual ~CustomShape();

		CustomShape(const CustomShape& other);

		void DrawShape(WindowWrapper& window);

		cconsts::ShapeType GetShapeType();
};

