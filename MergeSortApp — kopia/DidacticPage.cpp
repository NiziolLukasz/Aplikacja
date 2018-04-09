//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StartingPage.h"
#include "DidacticPage.h"
#include <dos.h>
#include <ctime>
#include <vector>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfDidacticPage *fDidacticPage;
int max_n, n, center, delay, if_count;
// max_n - maxymalna ilo�c s�upk�w
// n - aktualna ilo�c s��pk�w
// center - �rodek formatki dla wy�wietlanych s�upk�w
// delay - warto�� op�nienia sortowania
// if_count - ilo�� zliczonych por�wna�

// TEST
//int l,r; // Lewy i prawy koniec tablicy
int left_check, right_check; // Sprawdza czy algorytm dotar� do lewego/prawego ko�ca tablicy. 0 - nie, 1 - tak
std::vector <int> l, m, r, l_count, r_count;
int merge_stage;

// Merge viarables:
int x, // Pocz�tkowy indeks pierwszej podtablicy
y,     // Pocz�tkowy indeks drugiej podtablicy
z;     // Pocz�tkowy indeks po��czonej podtablicy
int n1; // ilo�� element�w w pierwszej podtablicy
int n2; // ilo�� element�w w drugiej podtablicy
/* Tworzenie pomocniczych tablic */
int *L, *R;
// End of merge viarables

// TEST

//---------------------------------------------------------------------------
__fastcall TfDidacticPage::TfDidacticPage(TComponent* Owner)
        : TForm(Owner)
{
        max_n = 30; // Okre�lenie maksmalnej ilo�ci s�upk�w
        center = (fDidacticPage->Width - PanelLeft->Width
                        - PanelRight->Width)/ 2 + PanelLeft->Width - 10;  // Obliczenie �rodka formatki dla wy�wietlanych s�upk�w
        delay = sbDelay->Position; // Przypisanie pocz�tkowej warto�ci op�nienia
        n= sbAmount->Position; // Przypisanie pocz�tkowej ilo�ci s�upk�w
        if_count = 0; // Przypisanie pocz�tkowej warto�ci zliczania if'�w

        // TEST
        l.push_back(0);
        r.push_back(n-1);
        l_count.push_back(0);
        r_count.push_back(0);
        merge_stage = 0;
        left_check = right_check = 0;
        // TEST

        fDidacticPage->ClientWidth = 231;  // Zmniejszenie wielko�ci formatki

        for(int i=0; i < max_n; i++)  // Stworzenie "niewidocznych" s�upk�w, dla dalszego u�ytku
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
    int n1 = m - l + 1; // ilo�� element�w w pierwszej podtablicy
    int n2 =  r - m; // ilo�� element�w w drugiej podtablicy

    // Tworzenie pomocniczych tablic
    int *L = new int [n1];
    int *R = new int [n2];

    // Skopiowanie danych do pomocniczych tablic L[] i R[]
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

    // ��czenie pomocniczych tablic spowrotem do arr[l..r]
    i = 0; // Pocz�tkowy indeks pierwszej podtablicy
    j = 0; // Pocz�tkowy indeks drugiej podtablicy
    k = l; // Pocz�tkowy indeks po��czonej podtablicy

    // Uwidocznienie znacznik�w
    sBlue->Visible = true;
    sRed->Visible = true;
    sYellow->Visible = true;

    //Przesuni�cie znacznik�w na miejsce startowe
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
    // Skopiowanie pozosta�ych element�w podtablicy L[], je�li jakie� istniej�
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
    // Skopiowanie pozosta�ych element�w podtablicy R[], je�li jakie� istniej�
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

    // Usuni�cie dodatkowch tablic
    delete [] L;
    delete [] R;
}

void TfDidacticPage::mergeSort(TShape *arr[], int l, int r)
{
    delay = sbDelay->Position; // od�wierzenie warto�ci op�nienia
    lComparisonsAmount->Caption = ++if_count;
    if (l < r)
    {
        // To samo co (l+r)/2, ale unika przepe�nienia dla du�ego l i r
        int m = l+(r-l)/2;

        // Sortowanie pierwszej i drugiej po�owy tablicy arr

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

        // Wy��czenie widoczno�ci wska�nik�w po uko�czeniu funkcji merge
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
        tMergeSort->Interval = sbDelay->Position;
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


void __fastcall TfDidacticPage::tMergeSortTimer(TObject *Sender)
{
        int tm, tl, tr;
        tl = l[tMergeSort->Tag];
        tr = r[tMergeSort->Tag];

           m.push_back(l[tMergeSort->Tag]+(r[tMergeSort->Tag]-l[tMergeSort->Tag])/2);
           tm = m[tMergeSort->Tag];
           if(left_check == 0 || right_check == 0) // Dzielenie tablicy
           {
             if(left_check == 0)
             {
                  if(!(l[tMergeSort->Tag] < r[tMergeSort->Tag]))
                  {
                        left_check = 1;
                        return;
                  }

                  for(int i=m[tMergeSort->Tag]; i>=0; i--) // Rozsuni�cie lewej cz�ci tablicy
                  {
                         tab[i]->Left += -4;
                  }
                  for(int i=m[tMergeSort->Tag]+1; i<n; i++) // Rozsuni�cie prawej cz�ci tablicy
                  {
                        tab[i]->Left += 4;
                  }
                  Repaint();

                  l.push_back(l[tMergeSort->Tag]);
                  r.push_back(m[tMergeSort->Tag]);

                  l_count.push_back(1);
                  tMergeSort->Tag++;
             }
             else if(right_check == 0)
             {
                    if(!(l[tMergeSort->Tag] < r[tMergeSort->Tag]))
                  {
                        right_check = 1;
                        return;
                  }

                  for(int i=m[tMergeSort->Tag]; i>=0; i--) // Rozsuni�cie lewej cz�ci tablicy
                  {
                        tab[i]->Left += -4;
                  }
                  for(int i=m[tMergeSort->Tag]+1; i<n; i++) // Rozsuni�cie prawej cz�ci tablicy
                  {
                        tab[i]->Left += 4;
                  }
                  Repaint();

                  l.push_back(m[tMergeSort->Tag] + 1);
                  r.push_back(r[tMergeSort->Tag]);

                  r_count.push_back(1);
                  tMergeSort->Tag++;
             } // Koniec dzielenia tablicy
             else   // ��czenie tablicy
             {
                switch(merge_stage)
                { // Etap czekania
                  case 0: break;

                  // Etap inicjalizacji zmiennych
                  case 1:
                  {
                        n1 = m[tMergeSort->Tag] - l[tMergeSort->Tag] + 1; /* ilo�� element�w w pierwszej podtablicy */
                        n2 = r[tMergeSort->Tag] - m[tMergeSort->Tag]; /* ilo�� element�w w drugiej podtablicy */

                        /* Tworzenie pomocniczych tablic */
                        L = new int [n1];
                        R = new int [n2];

                        /* Skopiowanie danych do pomocniczych tablic L[] i R[] */
                        lComparisonsAmount->Caption = ++if_count;
                        for (x = 0; x < n1; x++)
                        {
                            L[x] = -tab[l[tMergeSort->Tag] + x]->Height;
                            lComparisonsAmount->Caption = ++if_count;
                        }
                        lComparisonsAmount->Caption = ++if_count;
                        for (y = 0; y < n2; y++)
                        {
                            R[y] = -tab[m[tMergeSort->Tag] + 1 + y]->Height;
                            lComparisonsAmount->Caption = ++if_count;
                        }

                        x = 0; /* Pocz�tkowy indeks pierwszej podtablicy */
                        y = 0; /* Pocz�tkowy indeks drugiej podtablicy */
                        z = l[tMergeSort->Tag]; /* Pocz�tkowy indeks po��czonej podtablicy */

                        // Uwidocznienie znacznik�w
                        sBlue->Visible = true;
                        sRed->Visible = true;
                        sYellow->Visible = true;

                        //Przesuni�cie znacznik�w na miejsce startowe
                        sRed->Left = tab[x + l[tMergeSort->Tag]]->Left;
                        sBlue->Left = tab[m[tMergeSort->Tag] + 1 + y]->Left;
                        sYellow->Left = tab[z]->Left;

                        Repaint();

                        merge_stage++;
                        return;
                  }

                  // Etap sortowania przez por�wnywanie
                  case 2:
                  {
                        lComparisonsAmount->Caption = ++if_count;
                        if (x < n1 && y < n2)  // if == while, poniewa� jeste�my w Timerze
                        {
                            sRed->Left = tab[x + l[tMergeSort->Tag]]->Left;
                            sBlue->Left = tab[m[tMergeSort->Tag] + 1 + y]->Left;
                            sYellow->Left = tab[z]->Left;

                            lComparisonsAmount->Caption = ++if_count;
                            if (L[x] <= R[y])
                            {
                                tab[z]->Height = -L[x];
                                x++;
                            }
                            else
                            {
                                tab[z]->Height = -R[y];
                                y++;
                            }
                            z++;
                            lComparisonsAmount->Caption = ++if_count;
                            Repaint();
                            return;
                        }

                        merge_stage++;
                        return;

                  }

                  // Etap skopiowania pozosta�ych element�w podtablicy L
                  case 3:
                  {
                        // Skopiowanie pozosta�ych element�w podtablicy L[], je�li jakie� istniej�
                        lComparisonsAmount->Caption = ++if_count;
                        if (x < n1) // if == while, poniewa� jeste�my w Timerze
                        {
                            sRed->Left = tab[x + l[tMergeSort->Tag]]->Left;
                            sYellow->Left = tab[z]->Left;
                            tab[z]->Height = -L[x];

                            x++;
                            z++;

                            Repaint();
                            lComparisonsAmount->Caption = ++if_count;

                            return;
                        }

                        merge_stage++;
                        return;
                  }

                  // Etap skopiowania pozosta�ych element�w podtablicy R
                  case 4:
                  {
                        // Skopiowanie pozosta�ych element�w podtablicy R[], je�li jakie� istniej�
                        lComparisonsAmount->Caption = ++if_count;
                        if (y < n2) // if == while, poniewa� jeste�my w Timerze
                        {
                            sBlue->Left = tab[m[tMergeSort->Tag] + 1 + y]->Left;
                            sYellow->Left = tab[z]->Left;
                            tab[z]->Height = -R[y];
                            y++;
                            z++;
                            Repaint();
                            lComparisonsAmount->Caption = ++if_count;

                            return;
                        }

                        merge_stage++;
                        return;
                  }

                  // Etap wyj�cia z ��czenia element�w
                  case 5:
                  {
                        // Usuni�cie dodatkowch tablic
                        delete [] L;
                        delete [] R;

                        l.pop_back();
                        m.pop_back();
                        r.pop_back();
                        tMergeSort->Tag--;
                        merge_stage = 0;
                        return;
                  }
                }

                // Je�eli ostatni element r_count b�dzie r�wny 1, to oznacza, �e nadal dzia�amy na prawej cz�ci tablicy
                // w przeciwnym wypadku b�dzie to oznacza�o, �e prawa cz�� tablicy zosta�a posortowana
                // Identycznie dla l_count jak wy�ej
                  if(r_count.back() == 1 || l_count.back() == 1) // Sprawdzenie czy jeste�my w prawej i lewej cz�ci tablicy
                  {
                    r_count.pop_back();
                    merge_stage++;

                    for(int i=m[tMergeSort->Tag]; i>=0; i--) // Rozsuni�cie lewej cz�ci tablicy
                    {
                          tab[i]->Left += 4;
                    }
                    for(int i=m[tMergeSort->Tag]+1; i<n; i++) // Rozsuni�cie prawej cz�ci tablicy
                    {
                          tab[i]->Left += -4;
                    }
                    Repaint();
                  }
                  else
                  {
                    l_count.pop_back();
                    right_check = 0;
                  }
             }  // Koniec ��czenia tablicy
           }

}
//---------------------------------------------------------------------------

void __fastcall TfDidacticPage::FormClose(TObject *Sender,
      TCloseAction &Action)
{
        fStartingPage->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfDidacticPage::Button1Click(TObject *Sender)
{
        if(tMergeSort->Enabled == false)
                tMergeSort->Enabled = true;
        else
                tMergeSort->Enabled = false;
}
//---------------------------------------------------------------------------

