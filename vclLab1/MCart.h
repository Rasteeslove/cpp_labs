#include "MRect.h"

class MCart : public MRect
{
private:
	char cargo;

public:

	void AddCargo()
	{
		if (cargo < 4)
			cargo++;
	}

	void RemCargo()
	{
		if (cargo > 0)
			cargo--;
	}

	bool isSelected;
	bool directions[4];

	MCart(
		double x,
		double y,
		double w,
		double l,
		double a
	) : MRect(
		x, y, w, l, a
		)
	{
		isSelected = 0;
        cargo = 0;
		for (int i = 0; i < 4; i++)
            directions[i] = 0;
	}

	void Select()
	{
        isSelected = !isSelected;
	}

	void DrawCargo(TImage * screen)
	{
		for (int i = 0; i < cargo; i++) {
			MRect box(getX(), getY(), 17 - 4 * i, 17 - 4 * i, getAngle());
            box.Draw(screen);
		}
    }

	virtual void Draw(TImage * screen)
	{
		if (isSelected)
			screen->Canvas->Pen->Color = clRed;

		MRect::Draw(screen);

		screen->Canvas->Pen->Color = clBlack;

        DrawCargo(screen);
    }

    void MoveFwd()
	{
		Move(getAngle(), DEF_SPEED / (cargo + 1));
	}

	void MoveBack()
	{
		Move(getAngle() + 180, DEF_SPEED / (cargo + 1));
	}

	void TurnRight()
	{
		Rotate(DEF_ASPEED / (cargo + 1));
	}

	void TurnLeft()
	{
		Rotate(-DEF_ASPEED / (cargo + 1));
	}

};

