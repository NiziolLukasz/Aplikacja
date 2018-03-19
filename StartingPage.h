//---------------------------------------------------------------------------

#ifndef StartingPageH
#define StartingPageH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TfStartingPage : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
private:	// User declarations
public:		// User declarations
        __fastcall TfStartingPage(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfStartingPage *fStartingPage;
//---------------------------------------------------------------------------
#endif
