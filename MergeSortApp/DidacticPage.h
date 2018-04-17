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
   // max_n - maxymalna ilo�c s�upk�w
   // n - aktualna ilo�c s��pk�w
   // center - �rodek formatki dla wy�wietlanych s�upk�w
   // delay - warto�� op�nienia sortowania
   // if_count - ilo�� zliczonych por�wna�
   // arr_access - ilo�� zliczonych dost�p�w do tablicy

   bool running, right_click;
   int step, how_much, last;
   // running - true: dzia�anie algorytmu trwa; false: algorytm nieuruchomiony
   // right_click - true: wci�ni�ty przycisk "Step by step"; false: nic si� nie dzieje

   // Animacja:
   // step - o ile ma si� przesun�� obiekt
   // how_much - jak daleko ma si� przesun�� obiekt
   // last - pocz�tkowa/ostatnia pozycja obiektu


   // W�tki:
   int W_ID; // Indentyfikator w�tku
   unsigned int W_PD; // Pseudo-identyfikator w�tku

   TShape *tab[30]; // Tablica Shape
   void merge(TShape *arr[], int l, int m, int r); // Algorytm ��czenia
   void mergeSort(TShape *arr[], int l, int r); // Algorytm sortowania

   void unlock(); // Funkcja odblokowuj�ca przyciski, po zatrzymaniu dzia�ania algorytmu

   // Funkcje generuj�ce tablice:
   void randomTable(); // Tablica losowa
   void reversedTable(); // Tablica odwr�cona
   void constantTable(); // Tablica sta�a
   void arrowDownTable(); // Tablica "strza�ka w d�"
   void arrowUpTable(); // Tablica "strza�ka w g�r�"
   void almostSortedTable(); // Tablica prawie posortowana
   void sortedTable(); // Tablica posortowana
   void fewUniqueTable(); // Tablica "kilka unikalnych"

   void deleteTable(); // "Usuni�cie" tablicy


public:		// User declarations
   void mergeSortStart(); // Funkcja dzia�aj�ca na innym w�tku

        __fastcall TfDidacticPage(TComponent* Owner);
        __fastcall TfDidacticPage();
};
//---------------------------------------------------------------------------
extern PACKAGE TfDidacticPage *fDidacticPage;
//---------------------------------------------------------------------------
#endif
