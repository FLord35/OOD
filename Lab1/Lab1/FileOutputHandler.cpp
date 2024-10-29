#include "FileOutputHandler.h"

FileOutputHandler::FileOutputHandler()
{
}

std::string FileOutputHandler::ParseShapeData(CustomShapeMathDecorator& decoratedShape)
{
	std::string line;

	double shapeArea = decoratedShape.GetArea();
	double shapePerimeter = decoratedShape.GetPerimeter();

	switch (decoratedShape.GetShapeType())
	{
		case cconsts::CIRCLE:
			line = cconsts::OUTPUT_CIRCLE_SHAPE_NAME;
			break;
		case cconsts::TRIANGLE:
			line = cconsts::OUTPUT_TRIANGLE_SHAPE_NAME;
			break;
		case cconsts::RECTANGLE:
			line = cconsts::OUTPUT_RECTANGLE_SHAPE_NAME;
			break;
		default:
			break;
	}

	line += cconsts::OUTPUT_DATA_SEPARATOR;
	line += " ";
	line += cconsts::OUTPUT_PERIMETER_PREFACE;
	line += std::to_string(shapePerimeter);
	line += cconsts::OUTPUT_MAJOR_SEPARATOR;
	line += " ";
	line += cconsts::OUTPUT_AREA_PREFACE;
	line += std::to_string(shapeArea);

	return line;
}
