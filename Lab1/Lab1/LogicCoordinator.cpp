#include "LogicCoordinator.h"

LogicCoordinator::LogicCoordinator()
{
}

LogicCoordinator::~LogicCoordinator()
{
    for (int i = 0; i < vectorOfShapes.size(); i++)
    {
        delete vectorOfShapes[i];
    }
}

void LogicCoordinator::InitializeFiles(const std::string& inputFileName, const std::string& outputFileName)
{
    inputFile.open(inputFileName);
    if (!inputFile.is_open())
    {
        std::cerr << "Input file opening error" << std::endl; //TODO: Сделать handler ошибок, передавать туда, строки в константы
    }

    outputFile.open(outputFileName);
    if (!outputFile.is_open())
    {
        std::cerr << "Output file opening error" << std::endl; //TODO: Сделать handler ошибок, передавать туда, строки в константы
    }
}

void LogicCoordinator::ParseData()
{
    std::string commandLine;
    FileInputHandler fileInputHandler;
    ShapeBuilder shapeBuilder;
    CustomShapeMathDecorator* decoratedShape = nullptr;
    CustomShape* shape = nullptr;

    while (!inputFile.eof())
    {
        std::getline(inputFile, commandLine);
        fileInputHandler.ParseCommand(commandLine);

        switch (fileInputHandler.GetShapeType())
        {
        case cconsts::CIRCLE:
        {
            CustomCircleShape circle = shapeBuilder.BuildShape(fileInputHandler.GetCircleData());

            decoratedShape = new CircleShapeMathDecorator(&circle);
            break;
        }
        case cconsts::TRIANGLE:
        {
            CustomTriangleShape triangle = shapeBuilder.BuildShape(fileInputHandler.GetTriangleData());

            decoratedShape = new TriangleShapeMathDecorator(&triangle);
            break;
        }
        case cconsts::RECTANGLE:
        {
            CustomRectangleShape rectangle = shapeBuilder.BuildShape(fileInputHandler.GetRectangleData());

            decoratedShape = new RectangleShapeMathDecorator(&rectangle);
            break;
        }
        default:
            break;
        }

        vectorOfShapes.push_back(decoratedShape);
    }
}

void LogicCoordinator::OutputData()
{
    FileOutputHandler fileOutputHandler;

    for (auto & shape : vectorOfShapes)
    {
        std::string line = fileOutputHandler.ParseShapeData(*shape);
        outputFile << line << std::endl;
    }
}

void LogicCoordinator::DrawData()
{
    WindowWrapper window({ cconsts::WINDOW_WIDTH, cconsts::WINDOW_HEIGHT }, cconsts::WINDOW_TITLE);

    for (auto& shape : vectorOfShapes)
    {
        shape->DrawShape(window);
    }

    window.Display();
    sf::sleep(sf::seconds(3));
}

void LogicCoordinator::CloseFiles()
{
    inputFile.close();
    outputFile.close();
}
