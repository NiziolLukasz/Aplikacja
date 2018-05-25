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
   bool opened;

   template<class T>
   void loadFile(T*& arr, int& length);
   void sortArray();
   template<class T>
   void saveToFile(T* arr);
   template<class T>
   void checkIsSorted(const T* arr);
   void waitSignalOn();
   void waitSignalOff();

   template<class T>
   bool isSorted(const T* arr, const int length);
   template<class T>
   String arrayToStr(const T* arr);

   // W�tki:
   int W_ID; // Indentyfikator w�tku
   unsigned int W_PD; // Pseudo-identyfikator w�tku

public:		// User declarations
   void AlgorithmStart(); // Funkcja dzia�aj�ca na innym w�tku

        __fastcall TfAdvancedPage(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfAdvancedPage *fAdvancedPage;
//---------------------------------------------------------------------------
#endif
