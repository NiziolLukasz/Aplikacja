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
        TLabel *lAmount;
        TMainMenu *MainMenu;
   TMenuItem *mFile;
   TMenuItem *mExit;
   TMenuItem *mHelp;
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
   TMenuItem *About1;
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
   int max_n; // Maxymalna ilo�c s�upk�w
   int n; // Aktualna ilo�c s��pk�w
   int center; // �rodek formatki dla wy�wietlanych s�upk�w
   int delay; // Warto�� op�nienia sortowania
   int if_count; // Ilo�� zliczonych por�wna�
   int arr_access; // Ilo�� zliczonych dost�p�w do tablicy
   int arr_changed;

   bool running; // True: dzia�anie algorytmu trwa; false: algorytm nieuruchomiony
   bool right_click; // True: wci�ni�ty przycisk "Step by step"; false: nic si� nie dzieje

   //Animacja:
   int step; // O ile ma si� przesun�� obiekt
   int how_much; // Jak daleko ma si� przesun�� obiekt
   int last; // Pocz�tkowa/ostatnia pozycja obiektu

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

   void PageChangeDid();

public:		// User declarations
   void mergeSortStart(); // Funkcja dzia�aj�ca na innym w�tku

        __fastcall TfDidacticPage(TComponent* Owner);
        __fastcall TfDidacticPage();
};
//---------------------------------------------------------------------------
extern PACKAGE TfDidacticPage *fDidacticPage;
//---------------------------------------------------------------------------
#endif
