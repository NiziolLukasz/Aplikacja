//---------------------------------------------------------------------------

#ifndef DidacticPageH
#define DidacticPageH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Menus.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TfDidacticPage : public TForm
{
__published:	// IDE-managed Components
        TPanel *PanelLeft;
        TPanel *PanelRight;
        TScrollBar *sbAmount;
        TButton *bGenerate;
        TLabel *lStep;
        TImage *iRight;
        TButton *bStart;
        TButton *bStop;
        TPanel *PanelBottom;
        TImage *iPause;
        TImage *iLeft;
        TLabel *lAmount;
        TMainMenu *MainMenu;
        TMenuItem *File1;
        TMenuItem *Exit1;
        TMenuItem *Help1;
        TMenuItem *About1;
        TMenuItem *Tryby1;
        TMenuItem *Dydaktyczny1;
        TMenuItem *Naukwy1;
        TMenuItem *Zaawansowany1;
        TScrollBar *sbDelay;
        TLabel *lDelayName;
        TLabel *lDelayNumber;
        TImage *iPlay;
        TMenuItem *Start1;
        TLabel *lControlPanel;
        TTimer *Timer1;
        TRadioGroup *rgTableTypes;
        void __fastcall bGenerateClick(TObject *Sender);
        void __fastcall bStartClick(TObject *Sender);
        void __fastcall sbAmountChange(TObject *Sender);
        void __fastcall sbDelayChange(TObject *Sender);
        void __fastcall iPauseClick(TObject *Sender);
        void __fastcall iPlayClick(TObject *Sender);
        void __fastcall Start1Click(TObject *Sender);
        void __fastcall rgTableTypesClick(TObject *Sender);

private:	// User declarations
        TShape *tab[100];
        void merge(TShape *arr[], int l, int m, int r);
        void mergeSort(TShape *arr[], int l, int r);
        int min(int x, int y);

        void randomTable(int n);
        void reversedTable(int n);
        void constantTable(int n);
        void arrowDownTable(int n);
        void arrowUpTable(int n);
        void almostSortedTable(int n);
        void sortedTable(int n);
        void fewUniqueTable(int n);

        void deleteTable();
public:		// User declarations
        __fastcall TfDidacticPage(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfDidacticPage *fDidacticPage;
//---------------------------------------------------------------------------
#endif
