#include "FileInputHandler.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Constants.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "CustomCircleShape.h"

FileInputHandler::FileInputHandler()
{
}

int FileInputHandler::ParseCoordinates(const std::string& preface, const std::string& separator, int& startingPosition, const std::string& line)
{
	int firstSymbol = startingPosition + preface.length();
	int lastSymbol;

	if (separator == "")
	{
		lastSymbol = line.length();
	}
	else
	{
		lastSymbol = line.find(separator, firstSymbol);
	}

	std::string substring = line.substr(firstSymbol, lastSymbol - firstSymbol);

	startingPosition = lastSymbol;

	return std::stoi(substring);
}

void FileInputHandler::ParseCommand(const std::string& line)
{
	int position = line.find(cconsts::INPUT_DATA_SEPARATOR);

	std::string shapeName = line.substr(0, position);

	position = position + 2;

	if (shapeName == cconsts::INPUT_TRIANGLE_SHAPE_NAME)
	{
		shapeType = cconsts::TRIANGLE;

		int firstFirstPointCoordinate = ParseCoordinates(cconsts::INPUT_TRIANGLE_FIRST_POINT_PREFACE, cconsts::INPUT_MINOR_SEPARATOR, position, line);
		int secondFirstPointCoordinate = ParseCoordinates("", cconsts::INPUT_MAJOR_SEPARATOR, position += 1, line);

		int firstSecondPointCoordinate = ParseCoordinates(cconsts::INPUT_TRIANGLE_SECOND_POINT_PREFACE, cconsts::INPUT_MINOR_SEPARATOR, position += 2, line);
		int secondSecondPointCoordinate = ParseCoordinates("", cconsts::INPUT_MAJOR_SEPARATOR, position += 1, line);

		int firstThirdPointCoordinate = ParseCoordinates(cconsts::INPUT_TRIANGLE_THIRD_POINT_PREFACE, cconsts::INPUT_MINOR_SEPARATOR, position += 2, line);
		int secondThirdPointCoordinate = ParseCoordinates("", "", position += 1, line);

		trianglePoints = { 
			{firstFirstPointCoordinate, secondFirstPointCoordinate},
			{firstSecondPointCoordinate, secondSecondPointCoordinate},
			{firstThirdPointCoordinate, secondThirdPointCoordinate} 
		};
	}
	else if (shapeName == cconsts::INPUT_RECTANGLE_SHAPE_NAME)
	{
		shapeType = cconsts::RECTANGLE;

		int firstFirstPointCoordinate = ParseCoordinates(cconsts::INPUT_RECTANGLE_FIRST_POINT_PREFACE, cconsts::INPUT_MINOR_SEPARATOR, position, line);
		int secondFirstPointCoordinate = ParseCoordinates("", cconsts::INPUT_MAJOR_SEPARATOR, position += 1, line);

		int firstSecondPointCoordinate = ParseCoordinates(cconsts::INPUT_RECTANGLE_SECOND_POINT_PREFACE, cconsts::INPUT_MINOR_SEPARATOR, position += 2, line);
		int secondSecondPointCoordinate = ParseCoordinates("", "", position += 1, line);

		rectanglePoints = {
			{firstFirstPointCoordinate, secondFirstPointCoordinate},
			{firstSecondPointCoordinate, secondSecondPointCoordinate}
		};
	}
	else if (shapeName == cconsts::INPUT_CIRCLE_SHAPE_NAME)
	{
		shapeType = cconsts::CIRCLE;

		int firstCenterCoordinate = ParseCoordinates(cconsts::INPUT_CIRCLE_CENTER_POINT_PREFACE, cconsts::INPUT_MINOR_SEPARATOR, position, line);
		int secondCenterCoordinate = ParseCoordinates("", cconsts::INPUT_MAJOR_SEPARATOR, position += 1, line);

		int firstSymbol = position + 2 + cconsts::INPUT_CIRCLE_RADIUS_PREFACE.length();
		int radius = std::stoi(line.substr(firstSymbol, line.length() - firstSymbol));

		circlePoints = {
			{firstCenterCoordinate, secondCenterCoordinate},
			radius
		};
	}
}

cconsts::ShapeType FileInputHandler::GetShapeType()
{
	switch (shapeType)
	{
		case cconsts::CIRCLE:
			return cconsts::CIRCLE;
		case cconsts::TRIANGLE:
			return cconsts::TRIANGLE;
		case cconsts::RECTANGLE:
			return cconsts::RECTANGLE;
		default:
			return cconsts::NO_SHAPE;
	}
}

cconsts::CircleAsPoints FileInputHandler::GetCircleData()
{
	return circlePoints;
}

cconsts::TriangleAsPoints FileInputHandler::GetTriangleData()
{
	return trianglePoints;
}

cconsts::RectangleAsPoints FileInputHandler::GetRectangleData()
{
	return rectanglePoints;
}


