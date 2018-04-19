 //---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StartingPage.h"
#include "DidacticPage.h"
#include "EducationalPage.h"
#include "AdvancedPage.h"
#include <dos.h>

#include <ctime>
#include <vector>
using namespace std;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfDidacticPage *fDidacticPage;



//---------------------------------------------------------------------------
__fastcall TfDidacticPage::TfDidacticPage(TComponent* Owner)
        : TForm(Owner)
{
  max_n = 30; // Okreœlenie maksmalnej iloœci s³upków
  center = (fDidacticPage->Width - PanelLeft->Width
                  - PanelRight->Width)/ 2 + PanelLeft->Width - 10;  // Obliczenie œrodka formatki dla wyœwietlanych s³upków
  delay = sbDelay->Position; // Nadanie pocz¹tkowej wartoœci opóŸnienia
  if_count = 0; // Nadanie pocz¹tkowej wartoœci porównañ
  arr_access = 0; // Nadanie pocz¹tkowej wartoœci dostêpów do tablicy

  fDidacticPage->ClientWidth = 230;  // Zmniejszenie wielkoœci formatki

  running = false;
  right_click = false;

  for(int i=0; i < max_n; i++)  // Stworzenie "niewidocznych" s³upków, dla dalszego u¿ytku
  {
      tab[i] = new TShape((TComponent*)(NULL));
      tab[i]->Parent = this;
      tab[i]->Width = 0;
      tab[i]->Height = 0;
      tab[i]->Left = 0;
      tab[i]->Top = 0;
      tab[i]->Brush->Color = clWhite;
  }

  DoubleBuffered = true;

}

void TfDidacticPage::mergeSortStart()
{
   mergeSort(tab, 0, n-1);
   unlock();
}

int __fastcall mergeSortThread(Pointer Parameter)
{
   fDidacticPage->mergeSortStart();
   ExitThread(GetExitCodeThread(mergeSortThread, NULL)); // usuniêcie w¹tku z pamiêci, od tego momentu w¹tku nie mo¿na ju¿ wstrzymaæ.
   return 0;
}


/* £¹czy dwie podtablice arr[].
   Pierwsza podtablica to arr[l..m]
   Druga podtablica to arr[m+1..r]
*/
void TfDidacticPage::merge(TShape *arr[], int l, int m, int r) /* l - left, m - middle, r- right */
{

    int i, j, k;
    int n1 = m - l + 1; // iloœæ elementów w pierwszej podtablicy
    int n2 =  r - m; // iloœæ elementów w drugiej podtablicy

    // Tworzenie pomocniczych tablic
    int *L = new int [n1];
    int *R = new int [n2];

    // Skopiowanie danych do pomocniczych tablic L[] i R[]
    lComparisonsAmount->Caption = ++if_count;
    for (i = 0; i < n1; i++)
    {
        L[i] = -arr[l + i]->Height;

        lArrAccessAmount->Caption = arr_access + 2;
        lComparisonsAmount->Caption = ++if_count;
    }
    lComparisonsAmount->Caption = ++if_count;
    for (j = 0; j < n2; j++)
    {
        R[j] = -arr[m + 1+ j]->Height;

        lArrAccessAmount->Caption = arr_access + 2;
        lComparisonsAmount->Caption = ++if_count;
    }

    // £¹czenie pomocniczych tablic spowrotem do arr[l..r]
    i = 0; // Pocz¹tkowy indeks pierwszej podtablicy
    j = 0; // Pocz¹tkowy indeks drugiej podtablicy
    k = l; // Pocz¹tkowy indeks po³¹czonej podtablicy

    // Uwidocznienie znaczników
    sBlue->Visible = true;
    sRed->Visible = true;
    sYellow->Visible = true;

    //Przesuniêcie znaczników na miejsce startowe
    sRed->Left = arr[i + l]->Left;
    sBlue->Left = arr[m + 1+ j]->Left;
    sYellow->Left = arr[k]->Left;

    Repaint();
    
    if(right_click) // Je¿eli zosta³ klikniêty przycisk "w prawo" w "Step by step"
    {
      right_click = false; // Zmiana "flagi" na wy³¹czon¹, poniewa¿ czynnoœæ zosta³a ju¿ wykonana
      SuspendThread((Pointer)W_ID); // Zatrzymanie w¹tku inaczej zatrzymanie sortowania
    }else
      Sleep(delay);

    if(i<n1) // Zabezpieczenie, gdy i < n1 jest prawd¹, wtedy mamy 2 porównania i<n1 i j<n2
      lComparisonsAmount->Caption = ++if_count;
    lComparisonsAmount->Caption = ++if_count;
    while (i < n1 && j < n2)
    {
        sRed->Left = arr[i + l]->Left;
        sBlue->Left = arr[m + 1+ j]->Left;
        sYellow->Left = arr[k]->Left;

        lComparisonsAmount->Caption = ++if_count;
        lArrAccessAmount->Caption = arr_access + 2;
        if (L[i] <= R[j])
        {
            arr[k]->Height = -L[i];
            i++;

            lArrAccessAmount->Caption = arr_access + 2;
        }
        else
        {
            arr[k]->Height = -R[j];
            j++;

            lArrAccessAmount->Caption = arr_access + 2;
        }
        Repaint();
        

        if(right_click) // Je¿eli zosta³ klikniêty przycisk "w prawo" w "Step by step"
        {
            right_click = false; // Zmiana "flagi" na wy³¹czon¹, poniewa¿ czynnoœæ zosta³a ju¿ wykonana
            SuspendThread((Pointer)W_ID); // Zatrzymanie w¹tku inaczej zatrzymanie sortowania
        }else
          Sleep(delay);

        k++;

        if(i<n1) // Zabezpieczenie, gdy i < n1 jest prawd¹, wtedy mamy 2 porównania i<n1 i j<n2
            lComparisonsAmount->Caption = ++if_count;
        lComparisonsAmount->Caption = ++if_count;
    }
    // Skopiowanie pozosta³ych elementów podtablicy L[], jeœli jakieœ istniej¹
    lComparisonsAmount->Caption = ++if_count;
    while (i < n1)
    {
        sRed->Left = arr[i + l]->Left;
        sYellow->Left = arr[k]->Left;

        arr[k]->Height = -L[i];

        lArrAccessAmount->Caption = arr_access + 2;

        i++;
        k++;

        Repaint();
        

        if(right_click) // Je¿eli zosta³ klikniêty przycisk "w prawo" w "Step by step"
        {
            right_click = false; // Zmiana "flagi" na wy³¹czon¹, poniewa¿ czynnoœæ zosta³a ju¿ wykonana
            SuspendThread((Pointer)W_ID); // Zatrzymanie w¹tku inaczej zatrzymanie sortowania
        }else
          Sleep(delay);

        lComparisonsAmount->Caption = ++if_count;
    }
    // Skopiowanie pozosta³ych elementów podtablicy R[], jeœli jakieœ istniej¹
    lComparisonsAmount->Caption = ++if_count;
    while (j < n2)
    {
        sBlue->Left = arr[m + 1+ j]->Left;
        sYellow->Left = arr[k]->Left;

        arr[k]->Height = -R[j];

        lArrAccessAmount->Caption = arr_access + 2;

        j++;
        k++;
        Repaint();
        

        if(right_click) // Je¿eli zosta³ klikniêty przycisk "w prawo" w "Step by step"
        {
            right_click = false; // Zmiana "flagi" na wy³¹czon¹, poniewa¿ czynnoœæ zosta³a ju¿ wykonana
            SuspendThread((Pointer)W_ID); // Zatrzymanie w¹tku inaczej zatrzymanie sortowania
        }else
          Sleep(delay);

        lComparisonsAmount->Caption = ++if_count;
    }

    // Usuniêcie dodatkowch tablic
    delete [] L;
    delete [] R;
}

void TfDidacticPage::mergeSort(TShape *arr[], int l, int r)
{
  lComparisonsAmount->Caption = ++if_count;

  if (l < r)
  {
    // To samo co (l+r)/2, ale unika przepe³nienia dla du¿ego l i r
    int m = l+(r-l)/2;

    // Sortowanie pierwszej i drugiej po³owy tablicy arr

    for(int i=m; i>=0; i--) // Rozsuniêcie lewej czêœci tablicy
    {
        arr[i]->Left += -4;
    }
    for(int i=m+1; i<n; i++) // Rozsuniêcie prawej czêœci tablicy
    {
        arr[i]->Left += 4;
    }
    Repaint();
    

    if(right_click) // Je¿eli zosta³ klikniêty przycisk "w prawo" w "Step by step"
    {
      right_click = false; // Zmiana "flagi" na wy³¹czon¹, poniewa¿ czynnoœæ zosta³a ju¿ wykonana
      SuspendThread((Pointer)W_ID); // Zatrzymanie w¹tku inaczej zatrzymanie sortowania
    }else
      Sleep(delay);

    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);

    for(int i=m; i>=0; i--) // Zsuniêcie lewej czêœci tablicy
    {
        arr[i]->Left += 4;
    }
    for(int i=m+1; i<n; i++) // Zsuniêcie prawej czêœci tablicy
    {
        arr[i]->Left += -4;
    }
    Repaint();
    

    if(right_click) // Je¿eli zosta³ klikniêty przycisk "w prawo" w "Step by step"
    {
      right_click = false; // Zmiana "flagi" na wy³¹czon¹, poniewa¿ czynnoœæ zosta³a ju¿ wykonana
      SuspendThread((Pointer)W_ID); // Zatrzymanie w¹tku inaczej zatrzymanie sortowania
    }else
      Sleep(delay);

    merge(arr, l, m, r);

    // Wy³¹czenie widocznoœci wskaŸników po ukoñczeniu funkcji merge
    sRed->Visible = false;
    sBlue->Visible = false;
    sYellow->Visible = false;
  }
}

void __fastcall TfDidacticPage::bGenerateClick(TObject *Sender)
{
  PanelRight->Enabled = true; // Odblokowanie prawego panelu. Odblokowanie mo¿liwoœci kontroli algorytmu.
  bStart->Enabled = true; // Odblokowanie przycisku "Start". Umo¿liwienie wystartowania algorytmu

  n = sbAmount->Position; // Przypisanie pocz¹tkowej iloœci s³upków
  int option = rgTableTypes->ItemIndex; // Sprawdzenie wybranej opcji w tabeli "Table types"

  switch(option) // Utworzenie tablicy wed³ug wybranej opcji
  {
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
   delay = sbDelay->Position; // Zaktualizowanie wartoœci opóŸnienia
   lComparisonsAmount->Caption = if_count = 0; // resetujê licznik porównañ
   lArrAccessAmount->Caption = arr_access = 0; // Zresetowanie licznika dostêpów
   running = true; // Ustawiam "flagê" mówi¹c¹, ¿e ju¿ algorytm siê uruchomi³

   iPause->Visible = true; // Prze³¹czenie widocznoœci przycisków
   iPlay->Visible = false; //

   bSkip->Enabled = true; // Odblokowania przycisku Stop. W³¹czenie mo¿liwoœci zatrzymania algorytmu
   bStart->Enabled = false; // Zablokowanie przycisku Start. Uniemo¿liwienie w³¹czenia algorytmu podczas jego dzia³ania

   PanelLeft->Enabled = false; // Zablokowanie lewego panelu. Uniemo¿liwienie zmian, podczas dzia³ania algorytmu
   bGenerate->Enabled = false; // Zablokowanie przycisku "Generate again". Tak jak w lini wy¿ej, tylko ¿e z efektem wizuanym

   W_ID = BeginThread(NULL, 0, mergeSortThread, this, 0, W_PD); // Zaczêcie w¹tku i uruchomienie funkcji mergeSort
}
//---------------------------------------------------------------------------

void __fastcall TfDidacticPage::sbAmountChange(TObject *Sender)
{
  bGenerate->Enabled = true; // Odblokowanie przycisku "Generate again". Umo¿liwienie wygenerowania nowej tablicy, z powodu zmiany iloœci elementów
  PanelRight->Enabled = false; // Zablokowanie prawego panelu. Blokada mo¿liwoœci kontrolowania algorytmu, z powodu zmiany wielkoœci sortowanych elementów
  lAmount->Caption = sbAmount->Position; // Przedstawienie wybranej wartoœci
}
//---------------------------------------------------------------------------


void __fastcall TfDidacticPage::sbDelayChange(TObject *Sender)
{
  AnsiString caption = ((sbDelay->Position) / 1000.0); // Zmodyfikowanie wybranej wartoœci
  caption += " sec"; // Dodanie na koñcu wybranej wartoœci s³owa "sec" tzn. "seconds"
  lDelayNumber->Caption = caption; // Przedstawienie wybranej wartoœci
  delay = sbDelay->Position; // Zaktualizowanie wartoœci opóŸnienia
}
//---------------------------------------------------------------------------

void __fastcall TfDidacticPage::iPauseClick(TObject *Sender)
{
   SuspendThread((Pointer)W_ID); // Zatrzymanie w¹tku inaczej zatrzymanie sortowania

   iPause->Visible = false; // Prze³¹czenie widocznoœci przycisków
   iPlay->Visible = true; //
}
//---------------------------------------------------------------------------

void __fastcall TfDidacticPage::iPlayClick(TObject *Sender)
{
  if(!running) // Je¿eli sortowanie jeszcze siê nie usuchomi³o
   {
      bStartClick(this); // Uruchom sortowanie poraz pierwszy
   }
  else
      ResumeThread((Pointer)W_ID); // Wznowienie w¹tku inaczej wznowienie sortowania

  iPause->Visible = true; // Prze³¹czenie widocznoœci przycisków
  iPlay->Visible = false; //
}
//---------------------------------------------------------------------------


void __fastcall TfDidacticPage::mStartClick(TObject *Sender)
{
  fDidacticPage->Hide();
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

  for(int i=0; i < n; i++)
  {
    tab[i]->Width = 15;
    tab[i]->Height = -10 * (i+1);
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
   rgTableTypes->Top = 33; // Przesuniêcie tabeli wy¿ej i zrobienie miejsca dla przycisków

   lAmount->Visible = true; // Uwidocznienie przycisków
   sbAmount->Visible = true; //
   bGenerate->Visible = true; //

   if(fDidacticPage->Width < 990)
      tFormatAnim->Enabled = true; // W³¹czenie animacji rozsuniêcia formatki

   bGenerateClick(this); // Wygenerowanie wybranej tablicy
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



void __fastcall TfDidacticPage::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   fStartingPage->Close();
}
//---------------------------------------------------------------------------



void __fastcall TfDidacticPage::iRightClick(TObject *Sender)
{
   if(!running) // Je¿eli sortowanie jeszcze siê nie usuchomi³o
   {
      bStartClick(this); // Uruchom sortowanie poraz pierwszy
   }
   else
      ResumeThread((Pointer)W_ID);

   iPause->Visible = false; // Prze³¹czenie widocznoœci przycisków
   iPlay->Visible = true; //

   step = 1; // Ustawienie kroku przesuniêcia
   how_much = 8; // Ustawienie dystansu przesuniêcia
   last = iRight->Left; // Zapamiêtanie umiejscowienia przycisku
   tAnim->Interval = 10; // Ustawienie szybkoœci przesuniêcia

   tAnim->Enabled = true; // W³¹czenie animacji ruchu palca w prawo
   iRight->Enabled = false; // Zablokowanie ponownego klikniêcia przycisku do czasu zakoñczenia animacji

   right_click = true;
}
//---------------------------------------------------------------------------

void __fastcall TfDidacticPage::tAnimTimer(TObject *Sender)
{
   iRight->Left += step; // Przesuniêcie przycisku o dany krok
   if(iRight->Left <= last) // Je¿eli przycisk wróci na swoje miejsce
   {
      tAnim->Enabled = false; // Zakoñczenie animacji
      iRight->Enabled = true; // Umo¿liwienie ponownego wciœniêcia przycisku
   }

   if(iRight->Left > last + how_much) // Je¿eli osi¹gniemy wyznaczon¹ odleg³oœæ przesuniêcia
      step = -step; // Odwrócenie przesuniêcia tzn. powrót przycisku na swoje miejsce

}
//---------------------------------------------------------------------------

void __fastcall TfDidacticPage::tFormatAnimTimer(TObject *Sender)
{
   fDidacticPage->Width += 20;
   if(fDidacticPage->Width >= 990)
   {
      tFormatAnim->Enabled = false;
   }
}
//---------------------------------------------------------------------------



void __fastcall TfDidacticPage::mEduClick(TObject *Sender)
{
   fDidacticPage->Hide();
   fEducationalPage->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfDidacticPage::mAdvClick(TObject *Sender)
{
   fDidacticPage->Hide();
   fAdvancedPage->Show();   
}
//---------------------------------------------------------------------------

void __fastcall TfDidacticPage::mExitClick(TObject *Sender)
{
   fStartingPage->Close();   
}
//---------------------------------------------------------------------------



void __fastcall TfDidacticPage::bSkipClick(TObject *Sender)
{
   delay = 0;

   iPause->Visible = false; // Prze³¹czenie widocznoœci przycisków
   iPlay->Visible = true; //

   PanelRight->Enabled = false; // Zablokowanie prawego panelu. Uniemo¿liwienie kontroli zatrzymanego ju¿ algorytmu.
   bSkip->Enabled = false; // Zablokowanie przycisku "Stop". Tak jak w lini wy¿ej, tylko ¿e z efektem wizuanym
   bStart->Enabled = false; // Zablokowanie przycisku "Start". Tak jak w lini wy¿ej, tylko ¿e z efektem wizuanym


   if(iPause->Visible)  // Je¿eli w¹tek jest zatrzymany
      ResumeThread((Pointer)W_ID); // Wznowienie w¹tku inaczej wznowienie sortowania
}
//---------------------------------------------------------------------------
void TfDidacticPage::unlock()
{
   PanelLeft->Enabled = true; // Odblokowanie lewego panelu. Odblokowanie mo¿liwoœci wyboru.
   bGenerate->Enabled = true; // Odblokowanie przycisku "Generate again". Tak jak w lini wy¿ej, tylko ¿e z efektem wizuanym
}
