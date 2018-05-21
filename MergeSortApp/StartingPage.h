//---------------------------------------------------------------------------

#ifndef StartingPageH
#define StartingPageH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfStartingPage : public TForm
{
__published:	// IDE-managed Components
        TButton *bDidacticPage;
        TButton *bAdvancedPage;
        TButton *bEducationPage;
   TPanel *Panel;
        void __fastcall bDidacticPageClick(TObject *Sender);
        void __fastcall bEducationPageClick(TObject *Sender);
        void __fastcall bAdvancedPageClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfStartingPage(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfStartingPage *fStartingPage;
//---------------------------------------------------------------------------
#endif
