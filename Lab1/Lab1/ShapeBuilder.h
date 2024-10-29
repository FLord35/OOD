#pragma once
#include "constants.h"
#include "CustomCircleShape.h"
#include "CustomTriangleShape.h"
#include "CustomRectangleShape.h"
class ShapeBuilder
{
	public:
		ShapeBuilder();

		CustomCircleShape BuildShape(cconsts::CircleAsPoints);
		CustomTriangleShape BuildShape(cconsts::TriangleAsPoints);
		CustomRectangleShape BuildShape(cconsts::RectangleAsPoints);


};

