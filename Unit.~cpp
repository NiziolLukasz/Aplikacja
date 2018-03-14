//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
         tab[0] = new TShape((TComponent*)(NULL));
         tab[0]->Parent = this;
         tab[0]->Width = 3.5;
         tab[0]->Height = -2.5;
         tab[0]->Left = 300;
         tab[0]->Top = 400;
         tab[0]->Brush->Color = clWhite;

        for(int i=1; i<100; i++)
        {
                tab[i] = new TShape((TComponent*)(NULL));
                tab[i]->Parent = this;
                tab[i]->Width = tab[0]->Width;
                tab[i]->Height = tab[i-1]->Height + tab[0]->Height;
                tab[i]->Left = tab[0]->Width + tab[i-1]->Left;
                tab[i]->Top = tab[0]->Top;
                tab[i]->Brush->Color = clWhite;
        }
}
//---------------------------------------------------------------------------
