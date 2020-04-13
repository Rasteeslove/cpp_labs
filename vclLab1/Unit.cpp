//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

char wsad[] = {'W','S','A','D'};

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::CAddClick(TObject *Sender)
{
    srand (time(NULL));
	MCart one(rand() % Canv->Width, rand() % Canv->Height, DEF_CART_WID, DEF_CART_LEN, rand() % 360);
	carts.push_back(one);
}

int getIndexOfWSAD(char key)
{
	for (int i = 0; i < 4; i++)
		if (key == wsad[i])
			return i;

    // not wsad
	return 4;
}

void doWSADto(Word &Key, bool mode)
{
	int index = getIndexOfWSAD(Char(Key));

	if (index != 4)
		for (int i = 0; i < carts.size(); i++)
			if (carts[i].isSelected)
				carts[i].directions[index] = mode;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, Word &Key, TShiftState Shift)
{
	std::string symbol(1, Char(Key));
	std::string output_message = "Key " + symbol + " is pressed.";
	Form1->DebugConsole->Caption = &output_message[0];

	doWSADto(Key, 1);
}

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
	Form1->DebugConsole->Caption = "";

	doWSADto(Key, 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CanvClick(TObject *Sender)
{

	// select cart

	TPoint mouse;
	mouse = Mouse->CursorPos;
	mouse = ScreenToClient(mouse);

	for (int i = 0; i < carts.size(); i++)
		if (carts[i].isWithin(mouse.x - Canv->Left, mouse.y - Canv->Top))
			carts[i].Select();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ProcessTimer(TObject *Sender)
{
    DrawAll();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CCAddClick(TObject *Sender)
{
	for (int i = 0; i < carts.size(); i++)
		if (carts[i].isSelected)
			carts[i].AddCargo();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CCRemClick(TObject *Sender)
{
	for (int i = 0; i < carts.size(); i++)
		if (carts[i].isSelected)
			carts[i].RemCargo();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CRemClick(TObject *Sender)
{
	for (int i = 0; i < carts.size(); i++)
		if (carts[i].isSelected)
			carts.erase(carts.begin() + i);
}
//---------------------------------------------------------------------------




