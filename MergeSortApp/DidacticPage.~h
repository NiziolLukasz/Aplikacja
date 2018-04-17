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
        TPanel *PanelBottom;
        TImage *iPause;
        TImage *iLeft;
        TLabel *lAmount;
        TMainMenu *MainMenu;
   TMenuItem *mFile;
   TMenuItem *mExit;
   TMenuItem *mHelp;
   TMenuItem *mAbout;
   TMenuItem *mGoTo;
   TMenuItem *mEdu;
   TMenuItem *mAdv;
        TScrollBar *sbDelay;
        TLabel *lDelayName;
        TLabel *lDelayNumber;
        TImage *iPlay;
   TMenuItem *mStart;
        TLabel *lControlPanel;
        TRadioGroup *rgTableTypes;
        TShape *sRed;
        TShape *sYellow;
        TShape *sBlue;
        TLabel *lComparisonsName;
        TLabel *lComparisonsAmount;
   TTimer *tAnim;
   TTimer *tFormatAnim;
   TButton *bSkip;
   TLabel *lArrAccessName;
   TLabel *lArrAccessAmount;
        void __fastcall bGenerateClick(TObject *Sender);
        void __fastcall bStartClick(TObject *Sender);
        void __fastcall sbAmountChange(TObject *Sender);
        void __fastcall sbDelayChange(TObject *Sender);
        void __fastcall iPauseClick(TObject *Sender);
        void __fastcall iPlayClick(TObject *Sender);
        void __fastcall mStartClick(TObject *Sender);
        void __fastcall rgTableTypesClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
   void __fastcall iRightClick(TObject *Sender);
   void __fastcall tAnimTimer(TObject *Sender);
   void __fastcall tFormatAnimTimer(TObject *Sender);
   void __fastcall mEduClick(TObject *Sender);
   void __fastcall mAdvClick(TObject *Sender);
   void __fastcall mExitClick(TObject *Sender);
   void __fastcall bSkipClick(TObject *Sender);

private:	// User declarations
   int max_n, n, center, delay, if_count, arr_access;
   // max_n - maxymalna iloœc s³upków
   // n - aktualna iloœc s³ópków
   // center - œrodek formatki dla wyœwietlanych s³upków
   // delay - wartoœæ opóŸnienia sortowania
   // if_count - iloœæ zliczonych porównañ
   // arr_access - iloœæ zliczonych dostêpów do tablicy

   bool running, right_click;
   int step, how_much, last;
   // running - true: dzia³anie algorytmu trwa; false: algorytm nieuruchomiony
   // right_click - true: wciœniêty przycisk "Step by step"; false: nic siê nie dzieje

   // Animacja:
   // step - o ile ma siê przesun¹æ obiekt
   // how_much - jak daleko ma siê przesun¹æ obiekt
   // last - pocz¹tkowa/ostatnia pozycja obiektu


   // W¹tki:
   int W_ID; // Indentyfikator w¹tku
   unsigned int W_PD; // Pseudo-identyfikator w¹tku

   TShape *tab[30]; // Tablica Shape
   void merge(TShape *arr[], int l, int m, int r); // Algorytm ³¹czenia
   void mergeSort(TShape *arr[], int l, int r); // Algorytm sortowania

   void unlock(); // Funkcja odblokowuj¹ca przyciski, po zatrzymaniu dzia³ania algorytmu

   // Funkcje generuj¹ce tablice:
   void randomTable(); // Tablica losowa
   void reversedTable(); // Tablica odwrócona
   void constantTable(); // Tablica sta³a
   void arrowDownTable(); // Tablica "strza³ka w dó³"
   void arrowUpTable(); // Tablica "strza³ka w górê"
   void almostSortedTable(); // Tablica prawie posortowana
   void sortedTable(); // Tablica posortowana
   void fewUniqueTable(); // Tablica "kilka unikalnych"

   void deleteTable(); // "Usuniêcie" tablicy


public:		// User declarations
   void mergeSortStart(); // Funkcja dzia³aj¹ca na innym w¹tku

        __fastcall TfDidacticPage(TComponent* Owner);
        __fastcall TfDidacticPage();
};
//---------------------------------------------------------------------------
extern PACKAGE TfDidacticPage *fDidacticPage;
//---------------------------------------------------------------------------
#endif
