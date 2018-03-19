//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StartingPage.h"
#include "DidacticPage.h"
#include <dos.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfDidacticPage *fDidacticPage;

int n = 20;
//---------------------------------------------------------------------------
__fastcall TfDidacticPage::TfDidacticPage(TComponent* Owner)
        : TForm(Owner)
{


}

/* £¹czy dwie podtablice arr[].
   Pierwsza podtablica to arr[l..m]
   Druga podtablica to arr[m+1..r]
*/

   void TfDidacticPage::mergeShape(TShape *arr[], int l, int m, int r) /* l - left, m - middle, r- right */
{

    int i, j, k;
    int n1 = m - l + 1; /* iloœæ elementów w pierwszej podtablicy */
    int n2 =  r - m; /* iloœæ elementów w drugiej podtablicy */

    /* Tworzenie pomocniczych tablic */
    int *L = new int [n1];
    int *R = new int [n2];

    /* Skopiowanie danych do pomocniczych tablic L[] i R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i]->Height;
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j]->Height;

    /* £¹czenie pomocniczych tablic spowrotem do arr[l..r]*/
    i = 0; /* Pocz¹tkowy indeks pierwszej podtablicy */
    j = 0; /* Pocz¹tkowy indeks drugiej podtablicy */
    k = l; /* Pocz¹tkowy indeks po³¹czonej podtablicy */
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k]->Height = L[i];
            i++;

        }
        else
        {
            arr[k]->Height = R[j];
            j++;
        }
        arr[k]->Repaint();
        k++;
    }
    /* Skopiowanie pozosta³ych elementów podtablicy L[], jeœli jakieœ istniej¹ */
    while (i < n1)
    {
        arr[k]->Height = L[i];
        arr[k]->Repaint();
        
        i++;
        k++;
    }
    /* Skopiowanie pozosta³ych elementów podtablicy R[], jeœli jakieœ istniej¹ */
    while (j < n2)
    {
        arr[k]->Height = R[j];
        arr[k]->Repaint();
        
        j++;
        k++;
    }
    delete [] L;
    delete [] R;
    Sleep(1000);
}

void TfDidacticPage::mergeShapeSort(TShape *arr[], int l, int r)
{
    for(int i=0; i < n; i++)
    {
        arr[i]->Brush->Color = clWhite;
        arr[i]->Repaint();
    }

    if (l < r)
    {

        /* To samo co (l+r)/2, ale unika przepe³nienia dla du¿ego l i r */
        int m = l+(r-l)/2;
        for(int i=0; i < m; i++)
        {
                arr[i]->Brush->Color = clBlack;
                arr[i]->Repaint();
        }

        /* Sortowanie pierwszej i drugiej po³owy tablicy arr*/
        mergeShapeSort(arr, l, m);
        mergeShapeSort(arr, m+1, r);
        mergeShape(arr, l, m, r);
    }
}
//---------------------------------------------------------------------------



void __fastcall TfDidacticPage::bGenerateClick(TObject *Sender)
{
        for(int i=0; i < n; i++)
        {
                delete tab[i];
        }
        tab[0] = new TShape((TComponent*)(NULL));
        tab[0]->Parent = this;
        tab[0]->Width = 15;
        tab[0]->Height = -10;
        tab[0]->Left = 300;
        tab[0]->Top = 400;
        tab[0]->Brush->Color = clWhite;
        tab[0]->Repaint();

        for(int i=1; i<n; i++)
        {
                tab[i] = new TShape((TComponent*)(NULL));
                tab[i]->Parent = this;
                tab[i]->Width = tab[0]->Width;
                tab[i]->Height = tab[i-1]->Height + tab[0]->Height;
                tab[i]->Left = tab[0]->Width + tab[i-1]->Left;
                tab[i]->Top = tab[0]->Top;
                tab[i]->Brush->Color = clWhite;
                tab[i]->Repaint();
        }
}
//---------------------------------------------------------------------------

void __fastcall TfDidacticPage::bStartClick(TObject *Sender)
{
        mergeShapeSort(tab, 0, n-1);
}
//---------------------------------------------------------------------------

void __fastcall TfDidacticPage::sbAmountChange(TObject *Sender)
{
        eAmount->Text = sbAmount->Position;
}
//---------------------------------------------------------------------------

void __fastcall TfDidacticPage::eAmountChange(TObject *Sender)
{
        if(eAmount->Text >= '1' && eAmount->Text <= '100')
                sbAmount->Position = eAmount->Text.ToInt();

}
//---------------------------------------------------------------------------

void __fastcall TfDidacticPage::sbDelayChange(TObject *Sender)
{
        AnsiString caption = ((sbDelay->Position) / 1000.0);
        caption += " sec";
        lDelayNumber->Caption = caption;

}
//---------------------------------------------------------------------------

void __fastcall TfDidacticPage::ImagePauseClick(TObject *Sender)
{
        // TODO : Oprogramowaæ zatrzymanie siê algorytmu sortowania
        ImagePause->Visible = false;
        ImagePlay->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TfDidacticPage::ImagePlayClick(TObject *Sender)
{
        // TODO : Oprogramowaæ wznowienie pracy algorytmu sortowania
        ImagePause->Visible = true;
        ImagePlay->Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall TfDidacticPage::Start1Click(TObject *Sender)
{
        fDidacticPage->Close();
        fStartingPage->Show();

}
//---------------------------------------------------------------------------

