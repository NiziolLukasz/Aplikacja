//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int n = 20;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
/* £¹czy dwie podtablice arr[].
   Pierwsza podtablica to arr[l..m]
   Druga podtablica to arr[m+1..r]
*/
template <typename T>
   void merge(T arr[], int l, int m, int r) /* l - left, m - middle, r- right */
{
    int i, j, k;
    int n1 = m - l + 1; /* iloœæ elementów w pierwszej podtablicy */
    int n2 =  r - m; /* iloœæ elementów w drugiej podtablicy */

    /* Tworzenie pomocniczych tablic */
    T * L = new T [n1];
    T * R = new T [n2];

    /* Skopiowanie danych do pomocniczych tablic L[] i R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* £¹czenie pomocniczych tablic spowrotem do arr[l..r]*/
    i = 0; /* Pocz¹tkowy indeks pierwszej podtablicy */
    j = 0; /* Pocz¹tkowy indeks drugiej podtablicy */
    k = l; /* Pocz¹tkowy indeks po³¹czonej podtablicy */
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Skopiowanie pozosta³ych elementów podtablicy L[], jeœli jakieœ istniej¹ */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Skopiowanie pozosta³ych elementów podtablicy R[], jeœli jakieœ istniej¹ */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete [] L;
    delete [] R;
}

template <typename T>
void mergeSort(T arr[], int l, int r)
{
    if (l < r)
    {
        /* To samo co (l+r)/2, ale unika przepe³nienia dla du¿ego l i r */
        int m = l+(r-l)/2;

        /* Sortowanie pierwszej i drugiej po³owy teblicy arr*/
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
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


