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
int max_n, n, center, delay, if_count;

//---------------------------------------------------------------------------
__fastcall TfDidacticPage::TfDidacticPage(TComponent* Owner)
        : TForm(Owner)
{
        max_n = 30;
        center = (fDidacticPage->Width - PanelLeft->Width
                        - PanelRight->Width)/ 2 + PanelLeft->Width - 10;
        delay = sbDelay->Position;
        n= sbAmount->Position;
        if_count = 0;

        fDidacticPage->ClientWidth = 231;

        for(int i=0; i < max_n; i++)
        {
                tab[i] = new TShape((TComponent*)(NULL));
                tab[i]->Parent = this;
                tab[i]->Width = 0;
                tab[i]->Height = 0;
                tab[i]->Left = 0;
                tab[i]->Top = 0;
                tab[i]->Brush->Color = clWhite;
        }

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
    lComparisonsAmount->Caption = ++if_count;
    for (i = 0; i < n1; i++)
    {
        L[i] = -arr[l + i]->Height;
        lComparisonsAmount->Caption = ++if_count;
    }
    lComparisonsAmount->Caption = ++if_count;
    for (j = 0; j < n2; j++)
    {
        R[j] = -arr[m + 1+ j]->Height;
        lComparisonsAmount->Caption = ++if_count;
    }

    /* ��czenie pomocniczych tablic spowrotem do arr[l..r]*/
    i = 0; /* Pocz�tkowy indeks pierwszej podtablicy */
    j = 0; /* Pocz�tkowy indeks drugiej podtablicy */
    k = l; /* Pocz�tkowy indeks po��czonej podtablicy */
    sBlue->Visible = true;
    sRed->Visible = true;
    sYellow->Visible = true;
    sRed->Left = arr[i + l]->Left;
    sBlue->Left = arr[m + 1+ j]->Left;
    sYellow->Left = arr[k]->Left;
    Repaint();
    Sleep(delay);
    lComparisonsAmount->Caption = ++if_count;
    while (i < n1 && j < n2)
    {
        sRed->Left = arr[i + l]->Left;
        sBlue->Left = arr[m + 1+ j]->Left;
        sYellow->Left = arr[k]->Left;

        lComparisonsAmount->Caption = ++if_count;
        if (L[i] <= R[j])
        {
            arr[k]->Height = -L[i];
            i++;
        }
        else
        {
            arr[k]->Height = -R[j];
            j++;
        }
        Repaint();
        Sleep(delay);
        k++;
        lComparisonsAmount->Caption = ++if_count;
    }
    /* Skopiowanie pozosta�ych element�w podtablicy L[], je�li jakie� istniej� */
    lComparisonsAmount->Caption = ++if_count;
    while (i < n1)
    {
        sRed->Left = arr[i + l]->Left;
        sYellow->Left = arr[k]->Left;
        arr[k]->Height = -L[i];

        i++;
        k++;

        Repaint();
        Sleep(delay);
        lComparisonsAmount->Caption = ++if_count;
    }
    /* Skopiowanie pozosta�ych element�w podtablicy R[], je�li jakie� istniej� */
    lComparisonsAmount->Caption = ++if_count;
    while (j < n2)
    {
        sBlue->Left = arr[m + 1+ j]->Left;
        sYellow->Left = arr[k]->Left;
        arr[k]->Height = -R[j];
        j++;
        k++;
        Repaint();
        Sleep(delay);
        lComparisonsAmount->Caption = ++if_count;
    }
    delete [] L;
    delete [] R;
}

void TfDidacticPage::mergeSort(TShape *arr[], int l, int r)
{
    delay = sbDelay->Position;
    lComparisonsAmount->Caption = ++if_count;
    if (l < r)
    {
        /* To samo co (l+r)/2, ale unika przepe�nienia dla du�ego l i r */
        int m = l+(r-l)/2;

        /* Sortowanie pierwszej i drugiej po�owy tablicy arr*/

        for(int i=m; i>=0; i--) // Rozsuni�cie lewej cz�ci tablicy
        {
                arr[i]->Left += -4;
        }
        for(int i=m+1; i<n; i++) // Rozsuni�cie prawej cz�ci tablicy
        {
                arr[i]->Left += 4;
        }
        Repaint();
        Sleep(delay);
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        for(int i=m; i>=0; i--) // Zsuni�cie lewej cz�ci tablicy
        {
                arr[i]->Left += 4;
        }
        for(int i=m+1; i<n; i++) // Zsuni�cie prawej cz�ci tablicy
        {
                arr[i]->Left += -4;
        }
        Repaint();
        Sleep(delay);
        merge(arr, l, m, r);
        sRed->Visible = false;
        sBlue->Visible = false;
        sYellow->Visible = false;
    }
}

void __fastcall TfDidacticPage::bGenerateClick(TObject *Sender)
{
        PanelRight->Enabled = true;
        lComparisonsAmount->Caption = if_count = 0;
        n = sbAmount->Position;
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
        n = sbAmount->Position;
        lComparisonsAmount->Caption = if_count = 0;

        iPause->Visible = true;
        iPlay->Visible = false;

        PanelLeft->Enabled = false;
        bGenerate->Enabled = false;
        mergeSort(tab, 0, n-1);
        PanelLeft->Enabled = true;
        bGenerate->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfDidacticPage::sbAmountChange(TObject *Sender)
{
        bGenerate->Enabled = true;
        PanelRight->Enabled = false;
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
        deleteTable();

        srand( time( NULL ) );

        for(int i=0; i < n; i++)
        {
                tab[i]->Width = 15;
                tab[i]->Height = -((rand() % 300) + 5);
                tab[i]->Left = (tab[i]->Width) * (i%n) + center - (n*tab[i]->Width)/2;
                tab[i]->Top = 400;
        }
        Repaint();
}
//---------------------------------------------------------------------------

void TfDidacticPage::reversedTable()
{
        deleteTable();

        for(int i=0, j=n; i < n; i++, j--)
        {
                tab[i]->Width = 15;
                tab[i]->Height = -10 * (j+1);
                tab[i]->Left = (tab[i]->Width) * (i%n) + center - (n*tab[i]->Width)/2;
                tab[i]->Top = 400;
        }
        Repaint();
}
//---------------------------------------------------------------------------

void TfDidacticPage::constantTable()
{
        deleteTable();

        srand( time( NULL ) );

        int height =  (rand() % 300) + 2;

        for(int i=0; i < n; i++)
        {
                tab[i]->Width = 15;
                tab[i]->Height = - height;
                tab[i]->Left = (tab[i]->Width) * (i%n) + center - (n*tab[i]->Width)/2;
                tab[i]->Top = 400;
        }
        Repaint();
}
//---------------------------------------------------------------------------


void TfDidacticPage::arrowDownTable()
{
        deleteTable();
        int temp = 0;
        if(n > 20 && n < 28)
           temp = 40;
        else if(n >= 28)
           temp = 60;
        for(int i=0, j = n; i < n; i++, j--)
        {
                if(j <= i)
                   j = i + 1;
                tab[i]->Width = 15;
                tab[i]->Height = (-10 * (2.5*j)) + (10 * n) + temp;
                tab[i]->Left = (tab[i]->Width) * (i%n) + center - (n*tab[i]->Width)/2;
                tab[i]->Top = 400;
        }
        Repaint();
}
//---------------------------------------------------------------------------

void TfDidacticPage::arrowUpTable()
{
        deleteTable();

        for(int i=0, j = 0; i < n; i++)
        {
                if(i > n/2)
                   j--;
                else
                   j++;
                tab[i]->Width = 15;
                tab[i]->Height = (-10 * (2.5*j));
                tab[i]->Left = (tab[i]->Width) * (i%n) + center - (n*tab[i]->Width)/2;
                tab[i]->Top = 400;
        }
        Repaint();
}
//---------------------------------------------------------------------------

void TfDidacticPage::almostSortedTable()
{
        deleteTable();

        srand( time( NULL ) );

        for(int i=0, j=n; i < n; i++, j--)
        {
                tab[i]->Width = 15;
                tab[i]->Height = -10 * (j+1);
                tab[i]->Left = (tab[i]->Width) * (i%n) + center - (n*tab[i]->Width)/2;
                tab[i]->Top = 400;
        }
        int rand1;
        if(n > 4)
        {
           for(int i=0; i < n/4; i++)
           {
                rand1 = rand() % n;
                tab[rand1]->Height = -((rand() % 300) + 5);
           }
        }
        else
        {
           rand1 = rand() % n;
           tab[rand1]->Height = -((rand() % 300) + 5);
        }
        Repaint();
}
//---------------------------------------------------------------------------

void TfDidacticPage::fewUniqueTable()
{
        deleteTable();

        srand( time( NULL ) );
        int tab_length = (n>9)? 5 : 2;
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

        int rand1;
        for(int i=0; i < n; i++)
        {
                tab[i]->Width = 15;
                do{
                        rand1 = rand() % n;
                }while(temp[rand1] == 0);
                tab[i]->Height = temp[rand1];
                temp[rand1] = 0;
                tab[i]->Left = (tab[i]->Width) * (i%n) + center - (n*tab[i]->Width)/2;
                tab[i]->Top = 400;
        }
        Repaint();
        delete [] tabRand;
        delete [] temp;
}
//---------------------------------------------------------------------------

void TfDidacticPage::sortedTable()
{
        deleteTable();

        for(int i=0; i < n; i++)
        {
                tab[i]->Width = 15;
                tab[i]->Height = -10 * (i+1);
                tab[i]->Left = (tab[i]->Width) * (i%n) + center - (n*tab[i]->Width)/2;
                tab[i]->Top = 400;
        }
        Repaint();
}

//---------------------------------------------------------------------------

void __fastcall TfDidacticPage::rgTableTypesClick(TObject *Sender)
{
        rgTableTypes->Top = 33;
        lAmount->Visible = true;
        sbAmount->Visible = true;
        bGenerate->Visible = true;
        fDidacticPage->Width = 990;
        bGenerateClick(this);
}
//---------------------------------------------------------------------------
void TfDidacticPage::deleteTable(){
        for(int i=0; i < max_n; i++)
        {
                tab[i]->Width = 0;
                tab[i]->Height = 0;
                tab[i]->Left = 0;
                tab[i]->Top = 0;
                tab[i]->Brush->Color = clWhite;
        }
        Repaint();
}

//---------------------------------------------------------------------------


