//---------------------------------------------------------------------------
#pragma once
#ifndef UnitH
#define UnitH

#define DEF_SPEED 5
#define DEF_ASPEED 10
#define DEF_CART_LEN 40
#define DEF_CART_WID 20
#define PI 3.14159265
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>

#include <tchar.h>
#include <string>

#include "MCart.h"

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Canv;
	TButton *CAdd;
	TLabel *DebugConsole;
	TTimer *Process;
	TButton *CCAdd;
	TButton *CCRem;
	TButton *CRem;
	void __fastcall CAddClick(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, Word &Key, TShiftState Shift);
	void __fastcall FormKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall CanvClick(TObject *Sender);
	void __fastcall ProcessTimer(TObject *Sender);
	void __fastcall CCAddClick(TObject *Sender);
	void __fastcall CCRemClick(TObject *Sender);
	void __fastcall CRemClick(TObject *Sender);
	//void __fastcall TForm1::FormKeyDown(TObject *Sender, Word &Key, TShiftState Shift);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------

TForm1 *Form1;

void Clear()
{
    Form1->Canv->Canvas->Rectangle(0,0, Form1->Canv->Width, Form1->Canv->Height);
}

std::vector<MCart> carts;

// called every 40 millisec
void DrawAll()
{
	Clear();

	for (int i = 0; i < carts.size(); i++) {
		if (carts[i].directions[0]) {
			carts[i].MoveFwd();
		} else if (carts[i].directions[1]) {
			carts[i].MoveBack();
		}
		if (carts[i].directions[2]) {
			carts[i].TurnLeft();
		} else if (carts[i].directions[3]) {
			carts[i].TurnRight();
		}
		carts[i].Draw(Form1->Canv);
	}
}


#endif
