//---------------------------------------------------------------------------

#ifndef ShapeH
#define ShapeH
//---------------------------------------------------------------------------
#endif

#pragma once

#include "Point.h"

class Shape
{
public:

	mPoint * center;
	double angle;
    double scale;

	Shape(double x, double y)
	{
		angle = 0;
        scale = 1;
        center = new mPoint(x, y);
    }

	virtual void Draw(TImage * screen)
	{
		center->Draw(0, 0, screen);
	}

	virtual void Rotate(double d_angle)
	{
		angle += d_angle;
	}

	virtual void Scale(double mult)
	{
		scale *= mult;
	}

	virtual void Move(double dx, double dy)
	{
		center->x += dx;
        center->y += dy;
    }

};

