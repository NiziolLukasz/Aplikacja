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
    TLabel *lCompHS;
   TLabel *lComparisons;
   TLabel *lArrAccess;
    TLabel *lArrAccessHS;
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
    TLabel *lHS;
   TLabel *lMS1;
    TLabel *lMSHalf;
   TLabel *lCompMS1;
    TLabel *lCompMSHalf;
    TLabel *lArrAccessMS1;
    TLabel *lArrAccessMSHalf;
   TLabel *lQS;
    TLabel *lArrAccessQS;
   TLabel *lCompQS;
   TButton *bSaveResults;
    TLabel *lArrChanged;
    TLabel *lArrChangedHS;
    TLabel *lArrChangedMS1;
    TLabel *lArrChangedMSHalf;
    TLabel *lArrChangedQS;
    TLabel *lSortTime;
    TLabel *lSortTimeHS;
    TLabel *lSortTimeMS1;
    TLabel *lSortTimeMSHalf;
    TLabel *lSortTimeQS;
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
   int n; // aktualna wielkoœæ tablicy
   float comparision_sum;
   float access_sum;
   float changed_sum;
   float time_sum;
   int option;
   bool first_run;

   int *tab; // Tablica wartoœci
   int *tab_MS1; // Tablica pomocznicza
   int *tab_HS; // Tablica pomocznicza
   int *tab_MSHalf; // Tablica pomocznicza
   int *tab_QS; // Tablica pomocznicza

   void sort(void (*algorithm)(int*, int), int* array, int length,
            int repeat, TLabel* lName, TLabel* lComp, TLabel* lAccess, TLabel *lChanged, TLabel* lTime);

   // Funkcje generuj¹ce tablice:
   void randomTable(); // Tablica losowa
   void reversedTable(); // Tablica odwrócona
   void constantTable(); // Tablica sta³a
   void arrowDownTable(); // Tablica "strza³ka w dó³"
   void arrowUpTable(); // Tablica "strza³ka w górê"
   void almostSortedTable(); // Tablica prawie posortowana
   void sortedTable(); // Tablica posortowana
   void fewUniqueTable(); // Tablica "kilka unikalnych"
   void fromFile(); // Tablica wczytana z pliku
   void deleteTable(int *arr); // Usuniêcie tablicy
   void end();
   void saveToFile(AnsiString str);
   void showElements();
   void showResults(int *table, TLabel *algName, TLabel *comparisions, TLabel *access, TLabel *changed, TLabel *time);
   void clearResults(TLabel *algName, TLabel *comp, TLabel *access, TLabel *changed, TLabel *time);
   void clearAllResults();

   bool isSorted(int *table);
   void checkAmount();
   void checkRepeat();
   void sumResults(float time);
   void changeSign(String text, TColor color);
   void PageChangeEdu();
   void copyTable(const int *original, int *&tempTable);
   void copyTables();
   float round(float var);

   String getTable(int *arr); // Zwraca Stringa z wartoœciami tabeli np. "26;54;23;"

   // W¹tki:
   int W_ID; // Indentyfikator w¹tku
   unsigned int W_PD; // Pseudo-identyfikator w¹tku

public:		// User declarations
   void AlgorithmStart(); // Funkcja dzia³aj¹ca na innym w¹tku
        __fastcall TfEducationalPage(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfEducationalPage *fEducationalPage;
//---------------------------------------------------------------------------
#endif
