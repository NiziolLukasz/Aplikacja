//---------------------------------------------------------------------------

#ifndef AdvancedPageH
#define AdvancedPageH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TfAdvancedPage : public TForm
{
__published:	// IDE-managed Components
   TMainMenu *MainMenu;
   TMenuItem *mFile;
   TMenuItem *mStart;
   TMenuItem *mGoTo;
   TMenuItem *mDid;
   TMenuItem *mEdu;
   TMenuItem *mExit;
   TMenuItem *mHelp;
   TMenuItem *mAbout;
   TButton *bSortFile;
   TOpenDialog *OpenDialog;
   TSaveDialog *SaveDialog;
   TLabel *lSign2;
   void __fastcall mDidClick(TObject *Sender);
   void __fastcall mEduClick(TObject *Sender);
   void __fastcall mExitClick(TObject *Sender);
   void __fastcall mStartClick(TObject *Sender);
   void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
   void __fastcall bSortFileClick(TObject *Sender);
private:	// User declarations

   int *tab;
   double *tab_double;
   String tab_string;
   int n;

   template <class T>
   void merge(T *arr, int left, int mid, int right);
   template<class T>
   void mergeSort(T *arr, int left, int right);

   void loadFileToArray(int*& arr, int& length);
   void sortArray();
   void saveToFile(AnsiString str);
   void checkIsSorted();
   void waitSignalOn();
   void waitSignalOff();

   bool isSorted(int*& arr, int length);
   String arrayToStr(const int*& arr);

   // W¹tki:
   int W_ID; // Indentyfikator w¹tku
   unsigned int W_PD; // Pseudo-identyfikator w¹tku

public:		// User declarations
   void AlgorithmStart(); // Funkcja dzia³aj¹ca na innym w¹tku

        __fastcall TfAdvancedPage(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfAdvancedPage *fAdvancedPage;
//---------------------------------------------------------------------------
#endif
