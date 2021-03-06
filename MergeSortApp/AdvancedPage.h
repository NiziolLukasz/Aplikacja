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
#include <ExtCtrls.hpp>
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
   TButton *bSortFile;
   TOpenDialog *OpenDialog;
   TSaveDialog *SaveDialog;
   TLabel *lSign2;
    TRadioGroup *rgTypes;
   TMenuItem *About1;
   void __fastcall mDidClick(TObject *Sender);
   void __fastcall mEduClick(TObject *Sender);
   void __fastcall mExitClick(TObject *Sender);
   void __fastcall mStartClick(TObject *Sender);
   void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
   void __fastcall bSortFileClick(TObject *Sender);
   void __fastcall About1Click(TObject *Sender);
private:	// User declarations

    int* tab_int;
    double *tab_double;
    AnsiString* tab_string;
    int n;
    bool opened;
    

   template<class T>
   void loadFile(T*& arr, int& length);
   std::string loadStringFromFile();
   void sortArray();
   template<class T>
   void saveToFile(T* arr);
   void saveStirngToFile(AnsiString* str);
   int stringSize(std::string str);
   void stringToArray(AnsiString* arr, std::string str);

   template<class T>
   void checkIsSorted(const T* arr);
   void waitSignalOn();
   void waitSignalOff();

   template<class T>
   void start(T*& tab);
   void startString();
   template<class T>
   bool isSorted(const T* arr, const int length);
   template<class T>
   String arrayToStr(const T* arr);

   // W�tki:
   int W_ID; // Indentyfikator w�tku
   unsigned int W_PD; // Pseudo-identyfikator w�tku

public:		// User declarations
    void AlgorithmStartAdv(); // Funkcja dzia�aj�ca na innym w�tku

        __fastcall TfAdvancedPage(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfAdvancedPage *fAdvancedPage;
//---------------------------------------------------------------------------
#endif
