#include "LogicCoordinator.h"

int main(int argc, char* argv[])
{
    LogicCoordinator logicCoordinator;

    logicCoordinator.InitializeFiles(argv[1], argv[2]);

    logicCoordinator.ParseData();
    logicCoordinator.OutputData();
    logicCoordinator.DrawData();

    logicCoordinator.CloseFiles();
}
