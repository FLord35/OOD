#pragma once
#include <iostream>
#include "CustomShape.h"
#include "CustomShapeMathDecorator.h"
#include "CustomCircleShape.h"
#include "CircleShapeMathDecorator.h"
#include "CustomTriangleShape.h"
#include "TriangleShapeMathDecorator.h"
#include "CustomRectangleShape.h"
#include "RectangleShapeMathDecorator.h"
#include "FileInputHandler.h"
#include "FileOutputHandler.h"
#include "ShapeBuilder.h"
#include "WindowWrapper.h"
#include <vector>
#include <iostream>
#include <fstream>

class LogicCoordinator
{
	public:
		LogicCoordinator();

		~LogicCoordinator();

		void InitializeFiles(const std::string& inputFileName, const std::string& outputFileName);

		void ParseData();

		void OutputData();

		void DrawData();

		void CloseFiles();

	private:
		std::ifstream inputFile;
		std::ofstream outputFile;

		std::vector<CustomShapeMathDecorator*> vectorOfShapes;
};

