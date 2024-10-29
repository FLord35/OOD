#include "WindowWrapper.h"

WindowWrapper::WindowWrapper(cconsts::Coordinates size, const std::string& title):
	window(sf::VideoMode(size.x, size.y), title)
{
	window.clear();
}

void WindowWrapper::Draw(sf::Shape* shape)
{
	window.draw(*shape);
}

void WindowWrapper::Display()
{
	window.display();
}
