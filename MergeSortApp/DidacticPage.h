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
        TRadioGroup *rgTableTypes;
        TShape *sRed;
        TShape *sYellow;
        TShape *sBlue;
        TLabel *lComparisonsName;
        TLabel *lComparisonsAmount;
        TTimer *Timer1;
        void __fastcall bGenerateClick(TObject *Sender);
        void __fastcall bStartClick(TObject *Sender);
        void __fastcall sbAmountChange(TObject *Sender);
        void __fastcall sbDelayChange(TObject *Sender);
        void __fastcall iPauseClick(TObject *Sender);
        void __fastcall iPlayClick(TObject *Sender);
        void __fastcall Start1Click(TObject *Sender);
        void __fastcall rgTableTypesClick(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);

private:	// User declarations

        TShape *tab[30];
        void merge(TShape *arr[], int l, int m, int r);
        void mergeSort(TShape *arr[], int l, int r);

        void randomTable();
        void reversedTable();
        void constantTable();
        void arrowDownTable();
        void arrowUpTable();
        void almostSortedTable();
        void sortedTable();
        void fewUniqueTable();

        void deleteTable();
public:		// User declarations
        __fastcall TfDidacticPage(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfDidacticPage *fDidacticPage;
//---------------------------------------------------------------------------
#endif
