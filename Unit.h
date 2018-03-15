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
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TFDidactic : public TForm
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
        TScrollBar *SBAmount;
        TEdit *EAmount;
        TButton *BGenerate;
        TLabel *Label2;
        TImage *Image3;
        TButton *BStart;
        TButton *Button4;
        TPanel *Panel3;
        TImage *Image1;
        TImage *Image2;
        TLabel *Label3;
        TTimer *Timer1;
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *Exit1;
        TMenuItem *Help1;
        TMenuItem *About1;
        TMenuItem *Didactic1;
        TMenuItem *Tryby1;
        TMenuItem *Dydaktyczny1;
        TMenuItem *Naukwy1;
        TMenuItem *Zaawansowany1;
        TScrollBar *SBDelay;
        TLabel *LDelayName;
        TLabel *LDelayNumber;
        void __fastcall BGenerateClick(TObject *Sender);
        void __fastcall BStartClick(TObject *Sender);
        void __fastcall SBAmountChange(TObject *Sender);
        void __fastcall EAmountChange(TObject *Sender);
        void __fastcall SBDelayChange(TObject *Sender);
private:	// User declarations
        TShape *tab[100];
        void mergeShape(TShape *arr[], int l, int m, int r);
        void mergeShapeSort(TShape *arr[], int l, int r);
public:		// User declarations
        __fastcall TFDidactic(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDidactic *FDidactic;
//---------------------------------------------------------------------------
#endif
