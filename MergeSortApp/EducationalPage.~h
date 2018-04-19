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
   TLabel *lAmount;
   TScrollBar *sbAmount;
   TButton *bGenerate;
   TRadioGroup *rgTableTypes;
   TMemo *mInput;
   TMemo *mOutput;
   TButton *bStart;
   TLabel *lSign;
   TTimer *tFormatAnim;
   TLabel *lComparisonsAmount;
   TLabel *lComparisonsName;
   TLabel *lArrAccessName;
   TLabel *lArrAccessAmount;
   TOpenDialog *OpenDialog;
   TButton *bShowUnsorted;
   TLabel *lShowUnsorted;
   TLabel *lShowSorted;
   TButton *bShowSorted;
   TLabel *lSign2;
   TButton *bSaveUnsorted;
   TButton *bSaveSorted;
   TSaveDialog *SaveDialog;
   TLabel *Label1;
   TMemo *mResults;
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
   void __fastcall bShowUnsortedClick(TObject *Sender);
   void __fastcall bShowSortedClick(TObject *Sender);
   void __fastcall bLoadFileClick(TObject *Sender);
   void __fastcall bSaveUnsortedClick(TObject *Sender);
   void __fastcall bSaveSortedClick(TObject *Sender);
private:	// User declarations
   int n, if_count, arr_access, option;
   AnsiString unsorted_arr, sorted_arr;
   bool first_run, sorted, clickedSorted, clickedUnsorted;

   // n - aktualna wielkoœæ tablicy
   // if_count - iloœæ zliczonych porównañ
   // arr_access - iloœæ zliczonych dostêpów do tablicy
   // time -
   // min -
   // sec -
   // first_run -


   int *tab; // Tablica wartoœci

   void merge(int *&arr, int l, int m, int r); // Algorytm ³¹czenia
   void mergeSort(int *&arr, int l, int r); // Algorytm sortowania

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

   void deleteTable(int *&arr); // Usuniêcie tablicy

   void showTable(bool &flagClicked, AnsiString &str, TMemo *&memo, TButton *button, bool saveClick);
   void saveTable(bool &flagClicked, AnsiString &str, TMemo *&memo, TButton *button, bool saveClick);

   bool isSorted();
   String getTable(int *&arr); // Zwraca Stringa z wartoœciami tabeli np. "26; 54; 23; "

   void end();
   
   // W¹tki:
   int W_ID; // Indentyfikator w¹tku
   unsigned int W_PD; // Pseudo-identyfikator w¹tku

public:		// User declarations
   void mergeSortStartEdu(); // Funkcja dzia³aj¹ca na innym w¹tku
        __fastcall TfEducationalPage(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfEducationalPage *fEducationalPage;
//---------------------------------------------------------------------------
#endif
