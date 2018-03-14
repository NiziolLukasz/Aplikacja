//---------------------------------------------------------------------------

#ifndef UnitH
#define UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TGroupBox *GroupBox1;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TRadioButton *RadioButton3;
        TRadioButton *RadioButton4;
        TRadioButton *RadioButton5;
        TRadioButton *RadioButton6;
        TRadioButton *RadioButton7;
        TRadioButton *RadioButton8;
        TRadioButton *RadioButton9;
        TButton *Button1;
        TLabel *Label1;
        TScrollBar *ScrollBar1;
        TEdit *Edit1;
        TButton *Button2;
        TLabel *Label2;
        TImage *Image3;
        TButton *Button3;
        TButton *Button4;
        TPanel *Panel3;
        TImage *Image1;
        TImage *Image2;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
        TShape *tab[100];
        void mergeShape(TShape *arr[], int l, int m, int r);
        void mergeShapeSort(TShape *arr[], int l, int r);
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
