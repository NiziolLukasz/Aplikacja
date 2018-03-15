//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFDidactic *FDidactic;
int n = 20;
//---------------------------------------------------------------------------
__fastcall TFDidactic::TFDidactic(TComponent* Owner)
        : TForm(Owner)
{

}

/* £¹czy dwie podtablice arr[].
   Pierwsza podtablica to arr[l..m]
   Druga podtablica to arr[m+1..r]
*/

   void TFDidactic::mergeShape(TShape *arr[], int l, int m, int r) /* l - left, m - middle, r- right */
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
            //arr[k] = L[i];
            arr[k]->Height = L[i];
            i++;
        }
        else
        {
            arr[k]->Height = R[j];
            j++;
        }
        k++;
    }
 
    /* Skopiowanie pozosta³ych elementów podtablicy L[], jeœli jakieœ istniej¹ */
    while (i < n1)
    {
        arr[k]->Height = L[i];
        i++;
        k++;
    }

    /* Skopiowanie pozosta³ych elementów podtablicy R[], jeœli jakieœ istniej¹ */
    while (j < n2)
    {
        arr[k]->Height = R[j];
        j++;
        k++;
    }
    delete [] L;
    delete [] R;
    Timer1->Enabled = true;
}

void TFDidactic::mergeShapeSort(TShape *arr[], int l, int r)
{
    if (l < r)
    {
        /* To samo co (l+r)/2, ale unika przepe³nienia dla du¿ego l i r */
        int m = l+(r-l)/2;

        /* Sortowanie pierwszej i drugiej po³owy teblicy arr*/
        mergeShapeSort(arr, l, m);
        mergeShapeSort(arr, m+1, r);

        mergeShape(arr, l, m, r);
    }
}
//---------------------------------------------------------------------------



void __fastcall TFDidactic::BGenerateClick(TObject *Sender)
{
        tab[0] = new TShape((TComponent*)(NULL));
        tab[0]->Parent = this;
        tab[0]->Width = 15;
        tab[0]->Height = -10;
        tab[0]->Left = 300;
        tab[0]->Top = 400;
        tab[0]->Brush->Color = clWhite;

        for(int i=1; i<n; i++)
        {
                tab[i] = new TShape((TComponent*)(NULL));
                tab[i]->Parent = this;
                tab[i]->Width = tab[0]->Width;
                tab[i]->Height = tab[i-1]->Height + tab[0]->Height;
                tab[i]->Left = tab[0]->Width + tab[i-1]->Left;
                tab[i]->Top = tab[0]->Top;
                tab[i]->Brush->Color = clWhite;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFDidactic::BStartClick(TObject *Sender)
{
        Timer1->Enabled = false;
        Timer1->Enabled = true;
        mergeShapeSort(tab, 0, n-1);
}
//---------------------------------------------------------------------------



void __fastcall TFDidactic::SBAmountChange(TObject *Sender)
{
        EAmount->Text = SBAmount->Position;
}
//---------------------------------------------------------------------------



void __fastcall TFDidactic::EAmountChange(TObject *Sender)
{
        if(EAmount->Text >= '1' && EAmount->Text <= '100')
                SBAmount->Position = EAmount->Text.ToInt();

}
//---------------------------------------------------------------------------

void __fastcall TFDidactic::SBDelayChange(TObject *Sender)
{
        AnsiString caption = ((SBDelay->Position) / 1000.0);
        caption += " sec";
        LDelayNumber->Caption = caption;

}
//---------------------------------------------------------------------------


