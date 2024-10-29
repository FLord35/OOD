#pragma once
#include <iostream>
#include "Constants.h"
#include "CustomShapeMathDecorator.h"
#include <string>
class FileOutputHandler
{
	public:
		FileOutputHandler();

		std::string ParseShapeData(CustomShapeMathDecorator& decoratedShape);
};

