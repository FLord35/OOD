#pragma once
#include "Constants.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class WindowWrapper
{
	public:
		WindowWrapper(cconsts::Coordinates size, const std::string& title);

		void Draw(sf::Shape* shape);

		void Display();

	private:
		sf::RenderWindow window;

};

