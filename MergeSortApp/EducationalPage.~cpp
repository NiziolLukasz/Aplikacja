//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StartingPage.h"
#include "DidacticPage.h"
#include "EducationalPage.h"
#include "AdvancedPage.h"

#include <fstream>

 #include <process.h>
 #include <time.h>
 #include <vector>
 #include<windows.h>
 #include<sstream>
                  using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfEducationalPage *fEducationalPage;
int const max_n = 1000000;
//---------------------------------------------------------------------------
__fastcall TfEducationalPage::TfEducationalPage(TComponent* Owner)
        : TForm(Owner)
{
   n= sbAmount->Position; // Przypisanie pocz¹tkowej iloœci s³upków
   if_count = 0; // Przypisanie pocz¹tkowej wartoœci zliczania if'ów
   arr_access = 0; // Nadanie pocz¹tkowej wartoœci dostêpów do tablicy
   sTime = "";

   DoubleBuffered = true;

   rgTableTypes->Top = 97;
   fEducationalPage->ClientWidth = 230;  // Zmniejszenie wielkoœci formatki
}
//---------------------------------------------------------------------------
int __fastcall mergeSortThreadEdu(Pointer Parameter);


/* £¹czy dwie podtablice arr[].
   Pierwsza podtablica to arr[l..m]
   Druga podtablica to arr[m+1..r]
*/
void TfEducationalPage::merge(int *arr, int l, int m, int r) /* l - left, m - middle, r- right */
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
        L[i] = arr[l + i];

        lArrAccessAmount->Caption = arr_access + 2;
        lComparisonsAmount->Caption = ++if_count;
    }
    lComparisonsAmount->Caption = ++if_count;

    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1+ j];

        lArrAccessAmount->Caption = arr_access + 2;
        lComparisonsAmount->Caption = ++if_count;
    }

    // £¹czenie pomocniczych tablic spowrotem do arr[l..r]
    i = 0; // Pocz¹tkowy indeks pierwszej podtablicy
    j = 0; // Pocz¹tkowy indeks drugiej podtablicy
    k = l; // Pocz¹tkowy indeks po³¹czonej podtablicy

    if(i<n1) // Zabezpieczenie, gdy i < n1 jest prawd¹, wtedy mamy 2 porównania i<n1 i j<n2
      lComparisonsAmount->Caption = ++if_count;
    lComparisonsAmount->Caption = ++if_count;

    while (i < n1 && j < n2)
    {
        lComparisonsAmount->Caption = ++if_count;
        lArrAccessAmount->Caption = arr_access + 2;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;

            lArrAccessAmount->Caption = ++arr_access;
        }
        else
        {
            arr[k] = R[j];
            j++;

            lArrAccessAmount->Caption = arr_access + 2;
        }

        k++;

        if(i<n1) // Zabezpieczenie, gdy i < n1 jest prawd¹, wtedy mamy 2 porównania i<n1 i j<n2
            lComparisonsAmount->Caption = ++if_count;
        lComparisonsAmount->Caption = ++if_count;
    }
    // Skopiowanie pozosta³ych elementów podtablicy L[], jeœli jakieœ istniej¹
    lComparisonsAmount->Caption = ++if_count;
    while (i < n1)
    {
        arr[k] = L[i];

        lArrAccessAmount->Caption = arr_access + 2;

        i++;
        k++;

        lComparisonsAmount->Caption = ++if_count;
    }
    // Skopiowanie pozosta³ych elementów podtablicy R[], jeœli jakieœ istniej¹
    lComparisonsAmount->Caption = ++if_count;
    while (j < n2)
    {
        arr[k] = R[j];

        lArrAccessAmount->Caption = arr_access + 2;

        j++;
        k++;

        lComparisonsAmount->Caption = ++if_count;
    }

    // Usuniêcie dodatkowch tablic
    delete [] L;
    delete [] R;
}
//---------------------------------------------------------------------------

void TfEducationalPage::mergeSort(int *arr, int l, int r)
{
  lComparisonsAmount->Caption = ++if_count;

  if (l < r)
  {
    // To samo co (l+r)/2, ale unika przepe³nienia dla du¿ego l i r
    int m = l+(r-l)/2;

    // Sortowanie pierwszej i drugiej po³owy tablicy arr
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);

    merge(arr, l, m, r);
  }
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::mDydClick(TObject *Sender)
{
   fEducationalPage->Hide();
   fDidacticPage->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::mAdvClick(TObject *Sender)
{
   fEducationalPage->Hide();
   fAdvancedPage->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::mExitClick(TObject *Sender)
{
   fStartingPage->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::mStartClick(TObject *Sender)
{
   fEducationalPage->Hide();
   fStartingPage->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   fStartingPage->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::rgTableTypesClick(TObject *Sender)
{
   rgTableTypes->Top = 33;
   lAmount->Visible = true;
   sbAmount->Visible = true;
   bGenerate->Visible = true;

   if(fEducationalPage->Width < 640)
      tFormatAnim->Enabled = true; // W³¹czenie animacji rozsuniêcia formatki

   lSign->Caption = "Setup...";
   lSign->Font->Color = clGray;

   //bGenerateClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::bGenerateClick(TObject *Sender)
{
   if(!first_run)
   {
      deleteTable();
   }

   mOutput->Lines->Clear();
   first_run = false;
   bStart->Enabled = true; // Odblokowanie przycisku "Start". Umo¿liwienie wystartowania algorytmu

   int option = rgTableTypes->ItemIndex;

   if(option != 8)
   {
      n = sbAmount->Position;
      tab = new int [n];
   }

  switch(option)
  {
    case 0: randomTable();
            break;
    case 1: reversedTable();
            break;
    case 2: constantTable();
            break;
    case 3: arrowUpTable();
            break;
    case 4: arrowDownTable();
            break;
    case 5: almostSortedTable();
            break;
    case 6: fewUniqueTable();
            break;
    case 7: sortedTable();
            break;
    case 8: fromFile();
            break;
  }

   lSign->Caption = "Table generated";
   lSign->Font->Color = clNavy;

   mInput->Lines->Clear();
   mInput->Lines->Append(showTable());
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::sbAmountChange(TObject *Sender)
{
   bGenerate->Enabled = true;
   lAmount->Caption = sbAmount->Position;
}
//---------------------------------------------------------------------------
void TfEducationalPage::randomTable()
{
   // TOCHANGE: zmieniæ jakoœ randomizacje, mo¿e daæ uzytkownikowi wybór?
    srand( time( NULL ) );

    for(int i=0; i < n; i++)
    {
        tab[i] = rand() % 200000;
    }
}
//---------------------------------------------------------------------------

void TfEducationalPage::reversedTable()
{
   srand( time( NULL ) );

   do
   {
      tab[0] = rand() % 200000;
   }while(tab[0] < 20000);

    for(int i=1; i < n; i++)
    {
        tab[i] = tab[i-1] - (rand() % 2000);
    }
}
//---------------------------------------------------------------------------

void TfEducationalPage::constantTable()
{
  srand( time( NULL ) );

  int random = rand() % 20000;

  for(int i=0; i < n; i++)
  {
      tab[i] = random;
  }
}
//---------------------------------------------------------------------------


void TfEducationalPage::arrowDownTable()
{
   srand(time(NULL));

   do
   {
      tab[0] = rand() % 200000;
   }while(tab[0] < 20000);

   for(int i=1; i < n; i++)
   {
      tab[i] = (i > n/2)? tab[i-1] - rand() % 2000 : tab[i-1] + rand() % 2000;
   }
}
//---------------------------------------------------------------------------

void TfEducationalPage::arrowUpTable()
{
  srand(time(NULL));

   do
   {
      tab[0] = -(rand() % 200000);
   }while(tab[0] < -20000);

   for(int i=1; i < n; i++)
   {
      tab[i] = (i > n/2)? tab[i-1] + rand() % 2000 : tab[i-1] - rand() % 2000;
   }
}
//---------------------------------------------------------------------------

void TfEducationalPage::almostSortedTable()
{
  srand( time( NULL ) );

  do
  {
      tab[0] = -(rand() % 20000);
  }while(tab[0] < -10000);

  for(int i=1; i < n; i++)
  {
        tab[i] = tab[i-1] + (rand() % 2000);
  }
  int random;
  int how_many;
  if(n < 4)
      how_many = 1;
  else if(n < 10)
      how_many = 2;
  else if(n < 50)
      how_many = 5;
  else if(n < 1000)
      how_many = 30;
  else
      how_many = 100;

  for(int i=0; i < how_many; i++)
  {
      random = rand() % n;
      tab[random] = rand() % 20000;
  }

}
//---------------------------------------------------------------------------

void TfEducationalPage::fewUniqueTable()
{
  srand( time( NULL ) );

  int tab_length;
   if(n < 6)
      tab_length = 2;
   else if(n < 10)
      tab_length = 3;
   else if(n < 14)
      tab_length = 5;
   else if (n < 100)
      tab_length = 7;
   else
      tab_length = 10;

  int *tabRand = new int[tab_length];
  int *temp = new int[n];
  for(int i = 0; i< tab_length; i++)
  {
    tabRand[i] = rand() % 2000000;
  }
  for(int i=0; i<n; i++)
  {
      temp[i] = tabRand[i % tab_length];
  }

  int rand1;
  for(int i=0; i < n; i++)
  {
      do{
              rand1 = rand() % n;
      }while(temp[rand1] == 0);
      tab[i] = temp[rand1];
      temp[rand1] = 0;
  }
  delete [] tabRand;
  delete [] temp;
}
//---------------------------------------------------------------------------

void TfEducationalPage::sortedTable()
{
  srand( time( NULL ) );

   do
   {
      tab[0] = -(rand() % 20000);
   }while(tab[0] < -10000);

    for(int i=1; i < n; i++)
    {
        tab[i] = tab[i-1] + (rand() % 2000);
    }
}
//---------------------------------------------------------------------------

void TfEducationalPage::fromFile()
{
   string stringTab;
   if( OpenDialog->Execute() )
   {
      const char *file_name = OpenDialog->FileName.c_str();

      std::fstream file;
      file.open(file_name, std::ios::in);
      if( file.good() == true )
      {
         getline(file, stringTab);
         mInput->Lines->Append(stringTab.c_str());
         file.close();
      }
   }


//---------------------------------------------------------------------------

void TfEducationalPage::deleteTable(){
  delete [] tab;
}
void __fastcall TfEducationalPage::bStartClick(TObject *Sender)
{
   lComparisonsAmount->Caption = if_count = 0; // Zresetowanie licznika porównañ
   lArrAccessAmount->Caption = arr_access = 0; // Zresetowanie licznika dostêpów
   lTimeAmount->Caption = "0:00";
   min =0;
   Timer->Tag = 0;

   bStart->Enabled = false; // Zablokowanie przycisku Start. Uniemo¿liwienie w³¹czenia algorytmu podczas jego dzia³ania

   PanelLeft->Enabled = false; // Zablokowanie lewego panelu. Uniemo¿liwienie zmian, podczas dzia³ania algorytmu
   bGenerate->Enabled = false; // Zablokowanie przycisku "Generate again". Tak jak w lini wy¿ej, tylko ¿e z efektem wizuanym

   lSign->Caption = "Sorting...";
   lSign->Font->Color = clGreen;
   Repaint();

   Timer->Enabled = true;


   mergeSort(tab, 0, n-1);
   //W_ID = BeginThread(NULL, 0, mergeSortThreadEdu, this, 0, W_PD); // Zaczêcie w¹tku i uruchomienie funkcji mergeSort
   end();
}
//---------------------------------------------------------------------------

String TfEducationalPage::showTable()
{
   String table = "";
   for(int i=0; i < n; i++)
   {
      table += IntToStr(tab[i]) + ";";
   }
   return table;
}
//---------------------------------------------------------------------------

bool TfEducationalPage::isSorted()
{
   for(int i=1; i < n; i++)
   {
      if(tab[i-1] > tab[i])
         return false;
   }
   return true;
}
//---------------------------------------------------------------------------


void __fastcall TfEducationalPage::TimerTimer(TObject *Sender)
{
   ++Timer->Tag;

   if(Timer->Tag % 60 == 0)
      ++min;
   sec = Timer->Tag % 60;

   sTime = IntToStr(min) + ":";
   sTime += (sec < 10) ? "0" + IntToStr(sec) : IntToStr(sec);
   lTimeAmount->Caption = sTime;


}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::tFormatAnimTimer(TObject *Sender)
{
   fEducationalPage->Width += 20;
   if(fEducationalPage->Width >= 640)
   {
      tFormatAnim->Enabled = false;
   }
}
//---------------------------------------------------------------------------
void TfEducationalPage::mergeSortStartEdu()
{
   mergeSort(tab, 0, n-1);
   end();
}
//---------------------------------------------------------------------------

int __fastcall mergeSortThreadEdu(Pointer Parameter)
{
   fEducationalPage->mergeSortStartEdu();
   ExitThread(GetExitCodeThread(mergeSortThreadEdu, NULL)); // usuniêcie w¹tku z pamiêci, od tego momentu w¹tku nie mo¿na ju¿ wstrzymaæ.
   return 0;
}
//---------------------------------------------------------------------------
void TfEducationalPage::end()
{
   Timer->Enabled = false;

   if(isSorted())
   {
      lSign->Caption = "Sorted";
      lSign->Font->Color = clGreen;
   }
   else
   {
      lSign->Caption = "Unsorted";
      lSign->Font->Color = clRed;
   }

   mOutput->Lines->Clear();
   mOutput->Lines->Append(showTable());

   PanelLeft->Enabled = true; // Odblokowanie lewego panelu. Odblokowanie mo¿liwoœci wyboru.
   bGenerate->Enabled = true; // Odblokowanie przycisku "Generate again". Tak jak w lini wy¿ej, tylko ¿e z efektem wizuanym

}
