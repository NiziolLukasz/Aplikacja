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
   TMenuItem *mHelp;
   TMenuItem *About1;
   TPanel *PanelBottom;
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
   void __fastcall bSaveUnsortedClick(TObject *Sender);
   void __fastcall bSaveSortedClick(TObject *Sender);
   void __fastcall bSaveResultsClick(TObject *Sender);
   void __fastcall eRepeatExit(TObject *Sender);
   void __fastcall eAmountExit(TObject *Sender);
   void __fastcall About1Click(TObject *Sender);
private:	// User declarations
   int n; // aktualna wielkoœæ tablicy
   float comparision_sum;
   float access_sum;
   float changed_sum;
   float time_sum;
   int option;
   bool first_run;
   bool opened;
   int stime;

   int *tab; // Tablica wartoœci
   int *tab_MS1; // Tablica pomocznicza
   int *tab_HS; // Tablica pomocznicza
   int *tab_MSHalf; // Tablica pomocznicza
   int *tab_QS; // Tablica pomocznicza

   void sort(void (*algorithm1)(int*, int), void (*algorithm2)(int*, int),
            int* array, int length,
            int repeat, TLabel* lName, TLabel* lComp, TLabel* lAccess, TLabel *lChanged, TLabel* lTime);

   // Funkcje generuj¹ce tablice:
   template<class T>
   void randomTable(T*& arr, int length); // Tablica losowa
   template<class T>
   void reversedTable(T*& arr, int length); // Tablica odwrócona
   template<class T>
   void constantTable(T*& arr, int length); // Tablica sta³a
   template<class T>
   void arrowDownTable(T*& arr, int length); // Tablica "strza³ka w dó³"
   template<class T>
   void arrowUpTable(T*& arr, int length); // Tablica "strza³ka w górê"
   template<class T>
   void almostSortedTable(T*& arr, int length); // Tablica prawie posortowana
   template<class T>
   void sortedTable(T*& arr, int length); // Tablica posortowana
   template<class T>
   void fewUniqueTable(T*& arr, int length); // Tablica "kilka unikalnych"
   template<class T>
   void fromFile(T *&arr, int& length); // Tablica wczytana z pliku
   template<class T>
   void deleteTable(T*& arr); // Usuniêcie tablicy

    void countsize(std::fstream &f, int& size);
    template<class T>
    void createTable(T*& arr, const int size);
    template<class T>
    void fillTableFromFile(T*& arr, const int size, std::fstream &f);

   void end();
   template<class T>
   void saveToFile(T* arr);
   void showElements();
   void showResults(int *table, TLabel *algName, TLabel *comparisions, TLabel *access, TLabel *changed, TLabel *stime);
   void clearResults(TLabel *algName, TLabel *comp, TLabel *access, TLabel *changed, TLabel *stime);
   void clearAllResults();
   void waitSignalOn();
   void waitSignalOff();

   bool isSorted(int *table);
   
   void sumResults();
   void changeSign(String text, TColor color);
   void PageChangeEdu();
   template<class T>
   void copyTable(const T *original, T *&tempTable);
   template<class T>
   void copyTables(const T* arr);
   float round(float var);

   bool isAmountGood();
   void checkAmount();
   bool isRepeatGood();
   void checkRepeat();

   

   // W¹tki:
   int W_ID; // Indentyfikator w¹tku
   unsigned int W_PD; // Pseudo-identyfikator w¹tku

public:		// User declarations
   void AlgorithmStartEdu(); // Funkcja dzia³aj¹ca na innym w¹tku
        __fastcall TfEducationalPage(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfEducationalPage *fEducationalPage;
//---------------------------------------------------------------------------
#endif
