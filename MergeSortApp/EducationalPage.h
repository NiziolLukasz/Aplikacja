//---------------------------------------------------------------------------

#ifndef EducationalPageH
#define EducationalPageH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TfEducationalPage : public TForm
{
__published:	// IDE-managed Components
   TMainMenu *MainMenu;
   TMenuItem *mFile;
   TMenuItem *mStart;
   TMenuItem *mGoTo;
   TMenuItem *mAdv;
   TMenuItem *mExit;
   TMenuItem *mHelp;
   TMenuItem *mAbout;
   TMenuItem *mDyd;
   TPanel *PanelLeft;
   TScrollBar *sbAmount;
   TButton *bGenerate;
   TRadioGroup *rgTableTypes;
   TButton *bStart;
   TLabel *lSign;
   TTimer *tFormatAnim;
   TLabel *lCompMS2;
   TLabel *lComparisons;
   TLabel *lArrAccess;
   TLabel *lArrMS2;
   TOpenDialog *OpenDialog;
   TLabel *lSaveUnsorted;
   TLabel *lSaveSorted;
   TLabel *lSign2;
   TButton *bSaveUnsorted;
   TButton *bSaveSorted;
   TSaveDialog *SaveDialog;
   TEdit *eAmount;
   TLabel *lRepeat;
   TEdit *eRepeat;
   TLabel *lAmountName;
   TLabel *lAlgoritmName;
   TLabel *lMS2;
   TLabel *lMS1;
   TLabel *lMShalf;
   TLabel *lCompMS1;
   TLabel *lCompMShalf;
   TLabel *lArrMS1;
   TLabel *lArrMShalf;
   TLabel *lQS;
   TLabel *lArrQS;
   TLabel *lCompQS;
   TButton *bSaveResults;
   void __fastcall mDydClick(TObject *Sender);
   void __fastcall mAdvClick(TObject *Sender);
   void __fastcall mExitClick(TObject *Sender);
   void __fastcall mStartClick(TObject *Sender);
   void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
   void __fastcall rgTableTypesClick(TObject *Sender);
   void __fastcall bGenerateClick(TObject *Sender);
   void __fastcall sbAmountChange(TObject *Sender);
   void __fastcall bStartClick(TObject *Sender);
   void __fastcall tFormatAnimTimer(TObject *Sender);
   void __fastcall bLoadFileClick(TObject *Sender);
   void __fastcall bSaveUnsortedClick(TObject *Sender);
   void __fastcall bSaveSortedClick(TObject *Sender);
   void __fastcall bSaveResultsClick(TObject *Sender);
private:	// User declarations
   int n, if_count, arr_access, option;
   AnsiString unsorted_arr, sorted_arr;
   bool first_run, sorted;

   // n - aktualna wielko�� tablicy
   // if_count - ilo�� zliczonych por�wna�
   // arr_access - ilo�� zliczonych dost�p�w do tablicy
   // first_run -


   int *tab; // Tablica warto�ci

   void merge(int *&arr, int l, int m, int r); // Algorytm ��czenia
   void mergeSort(int *&arr, int l, int r); // Algorytm sortowania

   // Funkcje generuj�ce tablice:
   void randomTable(); // Tablica losowa
   void reversedTable(); // Tablica odwr�cona
   void constantTable(); // Tablica sta�a
   void arrowDownTable(); // Tablica "strza�ka w d�"
   void arrowUpTable(); // Tablica "strza�ka w g�r�"
   void almostSortedTable(); // Tablica prawie posortowana
   void sortedTable(); // Tablica posortowana
   void fewUniqueTable(); // Tablica "kilka unikalnych"
   void fromFile(); // Tablica wczytana z pliku
   void deleteTable(int *&arr); // Usuni�cie tablicy
   void end();
   void saveToFile(AnsiString str);
   void showElements();
   void showResults(TLabel *algName, TLabel *comp, TLabel *arr);
   void clearResults(TLabel *algName, TLabel *comp, TLabel *arr);

   bool isSorted();
   bool checkAmount();
   bool checkRepeat();

   String getTable(int *&arr); // Zwraca Stringa z warto�ciami tabeli np. "26; 54; 23; "

   
   
   // W�tki:
   int W_ID; // Indentyfikator w�tku
   unsigned int W_PD; // Pseudo-identyfikator w�tku

public:		// User declarations
   void AlgorithmStart(); // Funkcja dzia�aj�ca na innym w�tku
        __fastcall TfEducationalPage(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfEducationalPage *fEducationalPage;
//---------------------------------------------------------------------------
#endif
