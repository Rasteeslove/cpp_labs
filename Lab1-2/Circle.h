//---------------------------------------------------------------------------

#ifndef CircleH
#define CircleH
//---------------------------------------------------------------------------
#endif

#include "Shape.h"

class Circle : public Shape
{
public:

	double radius;

	Circle(double x, double y, double rad) : Shape(x, y)
	{
        radius = rad;
	}

    void Scale(double mult) override
	{
		Shape::Scale(mult);

        radius *= mult;
	}

	void Move(double dx, double dy) override
	{
		Shape::Move(dx, dy);
	}

	void Draw(TImage * screen) override
	{
        System::Uitypes::TColor tmp = screen->Canvas->Brush->Color;
		screen->Canvas->Brush->Color = clWhite;

		screen->Canvas->Ellipse(center->x - radius, center->y - radius,
								center->x + radius, center->y + radius);

        screen->Canvas->Brush->Color = tmp;

		Shape::Draw(screen);
	}

	double Perimeter()
	{
		return 2 * PI * radius;
	}

	double Square()
	{
        return PI * radius * radius;
    }

};
