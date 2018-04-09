//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("StartingPage.cpp", fStartingPage);
USEFORM("AdvancedPage.cpp", fAdvancedPage);
USEFORM("DidacticPage.cpp", fDidacticPage);
USEFORM("EducationalPage.cpp", fEducationalPage);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TfStartingPage), &fStartingPage);
                 Application->CreateForm(__classid(TfAdvancedPage), &fAdvancedPage);
                 Application->CreateForm(__classid(TfDidacticPage), &fDidacticPage);
                 Application->CreateForm(__classid(TfEducationalPage), &fEducationalPage);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
