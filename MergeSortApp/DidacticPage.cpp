//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StartingPage.h"
#include "DidacticPage.h"
#include <dos.h>
#include <ctime>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfDidacticPage *fDidacticPage;

int n = 20;
//---------------------------------------------------------------------------
__fastcall TfDidacticPage::TfDidacticPage(TComponent* Owner)
        : TForm(Owner)
{
        fDidacticPage->ClientWidth = 231;

}
int TfDidacticPage::min(int x, int y)
{
        return (x < y) ? x : y;
}

/* ��czy dwie podtablice arr[].
   Pierwsza podtablica to arr[l..m]
   Druga podtablica to arr[m+1..r]
*/

void TfDidacticPage::merge(TShape *arr[], int l, int m, int r) /* l - left, m - middle, r- right */
{

    int i, j, k;
    int n1 = m - l + 1; /* ilo�� element�w w pierwszej podtablicy */
    int n2 =  r - m; /* ilo�� element�w w drugiej podtablicy */

    /* Tworzenie pomocniczych tablic */
    int *L = new int [n1];
    int *R = new int [n2];

    /* Skopiowanie danych do pomocniczych tablic L[] i R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i]->Height;
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j]->Height;

    /* ��czenie pomocniczych tablic spowrotem do arr[l..r]*/
    i = 0; /* Pocz�tkowy indeks pierwszej podtablicy */
    j = 0; /* Pocz�tkowy indeks drugiej podtablicy */
    k = l; /* Pocz�tkowy indeks po��czonej podtablicy */
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
    /* Skopiowanie pozosta�ych element�w podtablicy L[], je�li jakie� istniej� */
    while (i < n1)
    {
        arr[k]->Height = L[i];
        arr[k]->Repaint();
        
        i++;
        k++;
    }
    /* Skopiowanie pozosta�ych element�w podtablicy R[], je�li jakie� istniej� */
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

void TfDidacticPage::mergeSort(TShape *arr[], int l, int r)
{
    if (l < r)
    {

        /* To samo co (l+r)/2, ale unika przepe�nienia dla du�ego l i r */
        int m = l+(r-l)/2;

        /* Sortowanie pierwszej i drugiej po�owy tablicy arr*/
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void __fastcall TfDidacticPage::bGenerateClick(TObject *Sender)
{
        int option = rgTableTypes->ItemIndex;
        switch(option){
                case 0: randomTable();
                        bGenerate->Enabled = true;
                        break;
                case 1: reversedTable();
                        bGenerate->Enabled = false;
                        break;
                case 2: constantTable();
                        bGenerate->Enabled = true;
                        break;
                case 3: arrowUpTable();
                        bGenerate->Enabled = false;
                        break;
                case 4: arrowDownTable();
                        bGenerate->Enabled = false;
                        break;
                case 5: almostSortedTable();
                        bGenerate->Enabled = true;
                        break;
                case 6: fewUniqueTable();
                        bGenerate->Enabled = true;
                        break;
                case 7: sortedTable();
                        bGenerate->Enabled = false;
                        break;
        }
}
//---------------------------------------------------------------------------

void __fastcall TfDidacticPage::bStartClick(TObject *Sender)
{
        mergeSort(tab, 0, n-1);
}
//---------------------------------------------------------------------------

void __fastcall TfDidacticPage::sbAmountChange(TObject *Sender)
{
        lAmount->Caption = sbAmount->Position;
}
//---------------------------------------------------------------------------


void __fastcall TfDidacticPage::sbDelayChange(TObject *Sender)
{
        AnsiString caption = ((sbDelay->Position) / 1000.0);
        caption += " sec";
        lDelayNumber->Caption = caption;

}
//---------------------------------------------------------------------------

void __fastcall TfDidacticPage::iPauseClick(TObject *Sender)
{
        // TODO : Oprogramowa� zatrzymanie si� algorytmu sortowania
        iPause->Visible = false;
        iPlay->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TfDidacticPage::iPlayClick(TObject *Sender)
{
        // TODO : Oprogramowa� wznowienie pracy algorytmu sortowania
        iPause->Visible = true;
        iPlay->Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall TfDidacticPage::Start1Click(TObject *Sender)
{
        fDidacticPage->Close();
        fStartingPage->Show();
}
//---------------------------------------------------------------------------

void TfDidacticPage::randomTable()
{
        srand( time( NULL ) );
        for(int i=0; i < n; i++)
        {
                delete tab[i];
        }

        for(int i=0; i < n; i++)
        {
                tab[i] = new TShape((TComponent*)(NULL));
                tab[i]->Parent = this;
                tab[i]->Width = 15;
                tab[i]->Height = -((rand() % 300) + 5);
                tab[i]->Left = (tab[i]->Width) * (i%n) + 300;
                tab[i]->Top = 400;
                tab[i]->Brush->Color = clWhite;
                tab[i]->Repaint();
        }
}
//---------------------------------------------------------------------------

void TfDidacticPage::reversedTable()
{
        for(int i=0; i < n; i++)
        {
                delete tab[i];
        }

        for(int i=0; i < n; i++)
        {
                tab[i] = new TShape((TComponent*)(NULL));
                tab[i]->Parent = this;
                tab[i]->Width = 15;
                tab[i]->Height = -10 * (i+1);
                tab[i]->Left = (tab[i]->Width) * (i%n) + 300;
                tab[i]->Top = 400;
                tab[i]->Brush->Color = clWhite;
                tab[i]->Repaint();
        }
}
//---------------------------------------------------------------------------

void TfDidacticPage::constantTable()
{
        srand( time( NULL ) );
        for(int i=0; i < n; i++)
        {
                delete tab[i];
        }
        int height =  (rand() % 300) + 2;

        for(int i=0; i < n; i++)
        {
                tab[i] = new TShape((TComponent*)(NULL));
                tab[i]->Parent = this;
                tab[i]->Width = 15;
                tab[i]->Height = - height;
                tab[i]->Left = (tab[i]->Width) * (i%n) + 300;
                tab[i]->Top = 400;
                tab[i]->Brush->Color = clWhite;
                tab[i]->Repaint();
        }
}
//---------------------------------------------------------------------------


void TfDidacticPage::arrowDownTable()
{
        for(int i=0; i < n; i++)
        {
                delete tab[i];
        }

        for(int i=0, j = n; i < n; i++, j--)
        {
                if(j < i)
                   j = i;
                tab[i] = new TShape((TComponent*)(NULL));
                tab[i]->Parent = this;
                tab[i]->Width = 15;
                tab[i]->Height = (-10 * (2.5*j)) + 240;
                tab[i]->Left = (tab[i]->Width) * (i%n) + 300;
                tab[i]->Top = 400;
                tab[i]->Brush->Color = clWhite;
                tab[i]->Repaint();
        }

}
//---------------------------------------------------------------------------

void TfDidacticPage::arrowUpTable()
{
        for(int i=0; i < n; i++)
        {
                delete tab[i];
        }

        for(int i=0, j = 0; i < n; i++)
        {
                if(i > n/2)
                   j--;
                else
                   j++;
                tab[i] = new TShape((TComponent*)(NULL));
                tab[i]->Parent = this;
                tab[i]->Width = 15;
                tab[i]->Height = (-10 * (2.5*j));
                tab[i]->Left = (tab[i]->Width) * (i%n) + 300;
                tab[i]->Top = 400;
                tab[i]->Brush->Color = clWhite;
                tab[i]->Repaint();
        }
}
//---------------------------------------------------------------------------

void TfDidacticPage::almostSortedTable()
{
        srand( time( NULL ) );
        for(int i=0; i < n; i++)
        {
                delete tab[i];
        }

        for(int i=0, j=n; i < n; i++, j--)
        {
                tab[i] = new TShape((TComponent*)(NULL));
                tab[i]->Parent = this;
                tab[i]->Width = 15;
                tab[i]->Height = -10 * (j+1);
                tab[i]->Left = (tab[i]->Width) * (i%n) + 300;
                tab[i]->Top = 400;
                tab[i]->Brush->Color = clWhite;
                tab[i]->Repaint();
        }
        int rand1;
        if(n > 4)
        {
           for(int i=0; i < n/4; i++)
           {
                rand1 = rand() % n;
                tab[rand1]->Height = -((rand() % 300) + 5);
                tab[rand1]->Repaint();

           }
        }
        else
        {
           rand1 = rand() % n;
           tab[rand1]->Height = -((rand() % 300) + 5);
           tab[rand1]->Repaint();
        }

}
//---------------------------------------------------------------------------

void TfDidacticPage::fewUniqueTable()
{
        srand( time( NULL ) );
        int tab_length = (int)(n/3)+ n%3;
        int *tabRand = new int[tab_length];
        int *temp = new int[n];
        for(int i = 0; i< tab_length; i++)
        {
                tabRand[i] = -(rand() % 300 + 5);
        }
        for(int i=0; i<n; i++)
        {
                temp[i] = tabRand[i % tab_length];
        }

        for(int i=0; i < n; i++)
        {
                delete tab[i];
        }


        int rand1;
        for(int i=0; i < n; i++)
        {
                tab[i] = new TShape((TComponent*)(NULL));
                tab[i]->Parent = this;
                tab[i]->Width = 15;
                do{
                        rand1 = rand() % n;
                }while(temp[rand1] == 0);
                tab[i]->Height = temp[rand1];
                temp[rand1] = 0;
                tab[i]->Left = (tab[i]->Width) * (i%n) + 300;
                tab[i]->Top = 400;
                tab[i]->Brush->Color = clWhite;
                tab[i]->Repaint();
        }
        delete [] tabRand;
        delete [] temp;
}
//---------------------------------------------------------------------------

void TfDidacticPage::sortedTable()
{
        for(int i=0; i < n; i++)
        {
                delete tab[i];
        }

        for(int i=0, j=n; i < n; i++, j--)
        {
                tab[i] = new TShape((TComponent*)(NULL));
                tab[i]->Parent = this;
                tab[i]->Width = 15;
                tab[i]->Height = -10 * (j+1);
                tab[i]->Left = (tab[i]->Width) * (i%n) + 300;
                tab[i]->Top = 400;
                tab[i]->Brush->Color = clWhite;
                tab[i]->Repaint();
        }
}

//---------------------------------------------------------------------------

void __fastcall TfDidacticPage::rgTableTypesClick(TObject *Sender)
{
        rgTableTypes->Top = 33;
        lAmount->Visible = true;
        sbAmount->Visible = true;
        bGenerate->Visible = true;
        fDidacticPage->Width = 946;
        bGenerateClick(this);  
}
//---------------------------------------------------------------------------









