#pragma once
#include <iostream>
#include "Constants.h"
class FileInputHandler
{
	public:
		FileInputHandler();

		void ParseCommand(const std::string& line);

		cconsts::ShapeType GetShapeType();

		cconsts::CircleAsPoints GetCircleData();
		cconsts::TriangleAsPoints GetTriangleData();
		cconsts::RectangleAsPoints GetRectangleData();

	private:
		int ParseCoordinates(const std::string& preface,const std::string& separator, int& startingPosition, const std::string& line);

		cconsts::ShapeType shapeType = cconsts::NO_SHAPE;

		cconsts::CircleAsPoints circlePoints;
		cconsts::TriangleAsPoints trianglePoints;
		cconsts::RectangleAsPoints rectanglePoints;
};

