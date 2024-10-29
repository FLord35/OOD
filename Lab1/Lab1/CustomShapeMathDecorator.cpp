#include "CustomShapeMathDecorator.h"
#include "CustomShape.h"

CustomShapeMathDecorator::CustomShapeMathDecorator(CustomShape* shapePtr):
	CustomShape(*shapePtr),
	customShape(shapePtr)
{
}
