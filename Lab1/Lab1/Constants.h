#pragma once
#include <iostream>
namespace cconsts
{
	//Input alphabet
	const std::string INPUT_TRIANGLE_SHAPE_NAME = "TRIANGLE";
	const std::string INPUT_RECTANGLE_SHAPE_NAME = "RECTANGLE";
	const std::string INPUT_CIRCLE_SHAPE_NAME = "CIRCLE";

	const std::string INPUT_TRIANGLE_FIRST_POINT_PREFACE = "P1=";
	const std::string INPUT_TRIANGLE_SECOND_POINT_PREFACE = "P2=";
	const std::string INPUT_TRIANGLE_THIRD_POINT_PREFACE = "P3=";

	const std::string INPUT_RECTANGLE_FIRST_POINT_PREFACE = "P1=";
	const std::string INPUT_RECTANGLE_SECOND_POINT_PREFACE = "P2=";

	const std::string INPUT_CIRCLE_CENTER_POINT_PREFACE = "C=";
	const std::string INPUT_CIRCLE_RADIUS_PREFACE = "R=";

	const std::string INPUT_MAJOR_SEPARATOR = ";";
	const std::string INPUT_MINOR_SEPARATOR = ",";
	const std::string INPUT_DATA_SEPARATOR = ":";

	//Output alphabet
	const std::string OUTPUT_TRIANGLE_SHAPE_NAME = "TRIANGLE";
	const std::string OUTPUT_RECTANGLE_SHAPE_NAME = "RECTANGLE";
	const std::string OUTPUT_CIRCLE_SHAPE_NAME = "CIRCLE";

	const std::string OUTPUT_PERIMETER_PREFACE = "P=";
	const std::string OUTPUT_AREA_PREFACE = "S=";

	const std::string OUTPUT_MAJOR_SEPARATOR = ";";
	const std::string OUTPUT_DATA_SEPARATOR = ":";

	//Window properties
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	
	const std::string WINDOW_TITLE = "title";

	//Structs and enums
	struct Coordinates
	{
		int x = 0;
		int y = 0;
	};

	struct CircleAsPoints
	{
		Coordinates centerPointCoordinates = { 0, 0 };
		int radius = 0;
	};

	struct RectangleAsPoints
	{
		Coordinates firstPointCoordinates = { 0, 0 };
		Coordinates secondPointCoordinates = { 0, 0 };
	};

	struct TriangleAsPoints
	{
		Coordinates firstPointCoordinates = { 0, 0 };
		Coordinates secondPointCoordinates = { 0, 0 };
		Coordinates thirdPointCoordinates = { 0, 0 };
	};

	enum ShapeType
	{
		NO_SHAPE,
		CIRCLE,
		TRIANGLE,
		RECTANGLE
	};
}