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

#include <vector>
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
    TLabel *lMSHalf;
   TLabel *lCompMS1;
    TLabel *lCompMSHalf;
   TLabel *lArrMS1;
    TLabel *lArrMSHalf;
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
   void __fastcall eRepeatExit(TObject *Sender);
   void __fastcall eAmountExit(TObject *Sender);
private:	// User declarations
   int n; // aktualna wielko�� tablicy
   float comparision_sum;
   float access_sum;
   int option;
   bool first_run;

   int *tab; // Tablica warto�ci
   int *tab_MS1; // Tablica pomocznicza
   int *tab_MS2; // Tablica pomocznicza
   int *tab_MSHalf; // Tablica pomocznicza
   int *tab_QS; // Tablica pomocznicza

   //  void mergeTwoTables(int *arr, int l, int m, int r); // Algorytm ��czenia dw�ch tablic
   //  void mergeSortTwoTables(int *arr, int l, int r); // Algorytm sortowania dw�ch tablic

   //  void mergeOneTable(int *arr, int l, int  s, int p); // Algorytm ��czenia jednej tablicy
   //  void mergeSortOneTable(int *arr, int l, int r); // Algorytm sortowania jednej tablicy

    //  void mergeHalfTable(int *arr, int left, int mid, int right);
    //  void mergeSortHalfTable(int *arr, int left, int right);

   //  int Rand(int p, int q);
   //  void Swap(int &a, int &b);
   //  int Partition(int arr[], int lo, int hi);
   //  void QuickSort(int arr[], int lo, int hi);

   void sort(void (*algorithm)(int*, int, int), int* array, int length,
                    int repeat, TLabel* lName, TLabel* lComp, TLabel* lAccess);

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
   void deleteTable(int *arr); // Usuni�cie tablicy
   void end();
   void saveToFile(AnsiString str);
   void showElements();
   void showResults(int *table, TLabel *algName, TLabel *comparisions, TLabel *access);
   void clearResults(TLabel *algName, TLabel *comp, TLabel *arr);
   void clearAllResults();

   bool isSorted(int *table);
   void checkAmount();
   void checkRepeat();
   void compAccessSum();
   void changeSign(String text, TColor color);
   void PageChangeEdu();
   void copyTable(int *original, int *&tempTable);
   void copyTables();
   float round(float var);

   String getTable(int *arr); // Zwraca Stringa z warto�ciami tabeli np. "26;54;23;"

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
