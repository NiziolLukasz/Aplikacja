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
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfEducationalPage *fEducationalPage;
int const max_n = 10000000;
//---------------------------------------------------------------------------
__fastcall TfEducationalPage::TfEducationalPage(TComponent* Owner)
        : TForm(Owner)
{
   n= sbAmount->Position; // Przypisanie pocz�tkowej ilo�ci s�upk�w
   if_count = 0; // Przypisanie pocz�tkowej warto�ci zliczania if'�w
   arr_access = 0; // Nadanie pocz�tkowej warto�ci dost�p�w do tablicy

   DoubleBuffered = true;
   sorted = false;

   eAmount->Text = sbAmount->Position;
   rgTableTypes->Top = 97;
   fEducationalPage->ClientWidth = 230;  // Zmniejszenie wielko�ci formatki
}
//---------------------------------------------------------------------------
int __fastcall AlgorithmThread(Pointer Parameter);

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

/* ��czy dwie podtablice arr[].
   Pierwsza podtablica to arr[l..m]
   Druga podtablica to arr[m+1..r]
*/
void TfEducationalPage::merge(int *&arr, int l, int m, int r) /* l - left, m - middle, r- right */
{

    int i, j, k;
    int n1 = m - l + 1; // ilo�� element�w w pierwszej podtablicy
    int n2 =  r - m; // ilo�� element�w w drugiej podtablicy

    // Tworzenie pomocniczych tablic
    int *L = new int [n1];
    int *R = new int [n2];

    // Skopiowanie danych do pomocniczych tablic L[] i R[]
    //++if_count;

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];

        arr_access += 1;
       // ++if_count;
    }
   // ++if_count;

    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1+ j];

        arr_access += 1;
      //  ++if_count;
    }

    // ��czenie pomocniczych tablic spowrotem do arr[l..r]
    i = 0; // Pocz�tkowy indeks pierwszej podtablicy
    j = 0; // Pocz�tkowy indeks drugiej podtablicy
    k = l; // Pocz�tkowy indeks po��czonej podtablicy

    //if(i<n1) // Zabezpieczenie, gdy i < n1 jest prawd�, wtedy mamy 2 por�wnania i<n1 i j<n2
    //  ++if_count;
    //++if_count;

    while (i < n1 && j < n2)
    {
        ++if_count;
        arr_access += 1;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;

            arr_access += 1;
        }
        else
        {
            arr[k] = R[j];
            j++;

            arr_access += 1;
        }

        k++;

        //if(i<n1) // Zabezpieczenie, gdy i < n1 jest prawd�, wtedy mamy 2 por�wnania i<n1 i j<n2
        //    ++if_count;
        //++if_count;
    }
    // Skopiowanie pozosta�ych element�w podtablicy L[], je�li jakie� istniej�
    //++if_count;
    while (i < n1)
    {
        arr[k] = L[i];

        arr_access += 1;

        i++;
        k++;

       // ++if_count;
    }
    // Skopiowanie pozosta�ych element�w podtablicy R[], je�li jakie� istniej�
    //++if_count;
    while (j < n2)
    {
        arr[k] = R[j];

        arr_access += 1;

        j++;
        k++;

       // ++if_count;
    }

    // Usuni�cie dodatkowch tablic
    delete [] L;
    delete [] R;
}
//---------------------------------------------------------------------------

void TfEducationalPage::mergeSort(int *&arr, int l, int r)
{
  //++if_count;

  if (l < r)
  {
    // To samo co (l+r)/2, ale unika przepe�nienia dla du�ego l i r
    int m = l+(r-l)/2;

    // Sortowanie pierwszej i drugiej po�owy tablicy arr
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);

    merge(arr, l, m, r);
  }
}
//---------------------------------------------------------------------------


void __fastcall TfEducationalPage::rgTableTypesClick(TObject *Sender)
{
   lSign->Caption = "Setup...";
   lSign->Font->Color = clGray;

   rgTableTypes->Top = 33;

   if(fEducationalPage->Width < 640)
      tFormatAnim->Enabled = true; // W��czenie animacji rozsuni�cia formatki

   showElements();
}
//---------------------------------------------------------------------------

void TfEducationalPage::showElements()
{
   bGenerate->Visible = true;
   lRepeat->Visible = false;
   eRepeat->Visible = false;

   option = rgTableTypes->ItemIndex;
   if(option == 8)
   {
      lAmountName->Visible = false;
      eAmount->Visible = false;
      sbAmount->Visible = false;

      bGenerate->Top = 368;
      bGenerate->Caption = "Load file...";
   }
   else
   {
      if(option == 0)
      {
         lRepeat->Visible = true;
         eRepeat->Visible = true;
      }

      lAmountName->Visible = true;
      eAmount->Visible = true;
      sbAmount->Visible = true;

      bGenerate->Top = 477;
      bGenerate->Caption = "Generate numbers";
   }
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::bGenerateClick(TObject *Sender)
{
   clearResults(lMS2, lCompMS2, lArrMS2);
   clearResults(lMS1, lCompMS1, lArrMS1);
   clearResults(lMShalf, lCompMShalf, lArrMShalf);
   clearResults(lQS, lCompQS, lArrQS);

   bSaveSorted->Enabled = false; // Zablokuj przycisk "Save..." od tablicy posortowanej
   bSaveResults->Enabled = false; 

   if(!checkAmount()){
      return;
   }

   if(option != 8) // Je�eli nie wczytujemy z piku, to...
   {
      lSign->Caption = "Generating..."; // Ustaw komunikat
      lSign->Font->Color = clNavy; // Ustaw kolor komunikatu
   }
   Repaint(); // Od�wiez widok

   sorted = false; // Ustawiam "flage" m�wi�ca, �e algorytm jest nie posortowany

   unsorted_arr = ""; // Wyczyszczenie zmiennych
   sorted_arr = "";  //
   
   if(!first_run) // Przy pierwszym odpaleniu, pomi� usuwanie tablicy
   {
      deleteTable(tab); // Usu� tablice
   }

   first_run = false; // Ustaw "flage". Tablica wygenerowana przynajmniej 1 raz
   if(option != 8) // Je�eli nie wczytujemy z piku, to...
   {
      n = sbAmount->Position; // Ustaw wielko�� tablicy
      tab = new int [n]; // Stw�rz tablice
   }

  switch(option) // Utworzenie tablicy wed�ug wybranej opcji
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

   if(option != 8) // Je�eli nie wczytujemy z piku, to...
   {
      
      lSign->Caption = "Table generated"; // Ustaw komunikat
      lSign->Font->Color = clNavy; // Ustaw kolor komunikatu
   }
   lSign2->Visible = true;
   unsorted_arr = getTable(tab);
   lSign2->Visible = false;
   bSaveUnsorted->Enabled = true; // Odblokuj przycisk "Save..." od tablicy nieposortowanej

   bStart->Enabled = true; // Odblokowanie przycisku "Start". Umo�liwienie wystartowania algorytmu
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::sbAmountChange(TObject *Sender)
{
   bGenerate->Enabled = true;
   eAmount->Text = sbAmount->Position;
}
//---------------------------------------------------------------------------
void TfEducationalPage::randomTable()
{
   // TOCHANGE: zmieni� jako� randomizacje, mo�e da� uzytkownikowi wyb�r?
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
   std::string stringTab; // Utwo�enie stringa do przechowania warto�ci z pliku
   if( OpenDialog->Execute() ) // Otworzenie dialogu, do wybrania pliku
   {
      const char *file_name = OpenDialog->FileName.c_str(); // Pobranie nazwy pliku

      std::fstream file; // Utworzenie zmiennej plikowej
      file.open(file_name, std::ios::in); // Otworzenie pliku
      if( file.good() == true ) // Sprawdzenie czy plik si� otworzy�
      {
         getline(file, stringTab); // Pobranie ca�ej lini z pliku
         file.close(); // Zamknij plik
      }
   }

   int pos, j = 0, size = 0; // pos - pozycja ";", j - id tablicy,
   std::size_t found = stringTab.find(";"); // Wyszukanie ";" w stringu
   while(found != std::string::npos) // Je�li wyszukana warto�� nie jest maksymaln� warto�ci� size_t, to...
   {
         size++; // Zwi�ksz wielko�� tablicy o 1
         found = stringTab.find(";",found+1); // Ponownie wyszukaj ";", zaczynaj�c od poprzedniego + 1 miejsca
   }
   n = size; // Ustaw obliczon� wielko�� tablicy pod zmienn� globaln�
   tab = new int [n]; // Stw�rz tablice

    while(!stringTab.empty()) // Je�li string nie jest pusty, to...
    {
      pos = stringTab.find(";"); // Znajd� miejsce ";"
      tab[j] = StrToInt(stringTab.substr(0, pos).c_str()); // Skopiuj cz�� stringa, a potem zamie� na int i wrzu� do tablicy
      stringTab.erase(0, pos + 2); // Usu� wyko�ystan� ju� cz�� stringa, wraz z ";"
      j++; // Zwi�ksz id tablicy o 1
    }
}
//---------------------------------------------------------------------------

void TfEducationalPage::deleteTable(int *&arr){
  delete [] arr;
}
//---------------------------------------------------------------------------

void TfEducationalPage::clearResults(TLabel *algName, TLabel *comp, TLabel *arr)
{
   algName->Color = clBtnFace;
   comp->Caption = 0;
   arr->Caption = 0;
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::bStartClick(TObject *Sender)
{
   bStart->Enabled = false; // Zablokowanie przycisku Start. Uniemo�liwienie w��czenia algorytmu podczas jego dzia�ania

   PanelLeft->Enabled = false; // Zablokowanie lewego panelu. Uniemo�liwienie zmian, podczas dzia�ania algorytmu
   bGenerate->Enabled = false; // Zablokowanie przycisku "Generate again". Tak jak w lini wy�ej, tylko �e z efektem wizuanym

   lSign->Caption = "Sorting...";
   lSign->Font->Color = clGreen;
   Repaint();

   if(option == 0)
   {
      for(int i=0; i < eRepeat; i++)
      {
         W_ID = BeginThread(NULL, 0, AlgorithmThread, this, 0, W_PD); // Zacz�cie w�tku i uruchomienie algorytm�w
      }
   }else
   {
      W_ID = BeginThread(NULL, 0, AlgorithmThread, this, 0, W_PD); // Zacz�cie w�tku i uruchomienie algorytm�w
   }
}

//---------------------------------------------------------------------------

String TfEducationalPage::getTable(int *&arr)
{
   AnsiString table = "";
   for(int i=0; i < n; i++)
   {
      table += IntToStr(arr[i]) + "; ";
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



void __fastcall TfEducationalPage::tFormatAnimTimer(TObject *Sender)
{
   fEducationalPage->Width += 20;
   if(fEducationalPage->Width >= 640)
   {
      tFormatAnim->Enabled = false;
   }
}
//---------------------------------------------------------------------------
void TfEducationalPage::AlgorithmStart()
{
   mergeSort(tab, 0, n-1);
   showResults(lMS2, lCompMS2, lArrMS2);
   end();
}
//---------------------------------------------------------------------------

int __fastcall AlgorithmThread(Pointer Parameter)
{
   fEducationalPage->AlgorithmStart();
   ExitThread(GetExitCodeThread(AlgorithmThread, NULL)); // usuni�cie w�tku z pami�ci, od tego momentu w�tku nie mo�na ju� wstrzyma�.
   return 0;
}
//---------------------------------------------------------------------------

void TfEducationalPage::showResults(TLabel *algName, TLabel *comp, TLabel *arr)
{
   comp->Caption = if_count;
   arr->Caption = arr_access;
   sorted = isSorted();
   if(sorted)
   {
      algName->Color = clGreen;
   }
   else
   {
      algName->Color = clRed;
   }
   Repaint();
}
//---------------------------------------------------------------------------

void TfEducationalPage::end()
{
   lSign->Caption = "Completed";

   PanelLeft->Enabled = true; // Odblokowanie lewego panelu. Odblokowanie mo�liwo�ci wyboru.
   bGenerate->Enabled = true; // Odblokowanie przycisku "Generate again". Tak jak w lini wy�ej, tylko �e z efektem wizuanym

   bSaveSorted->Enabled = true; // Odblokuj przycisk "Save..." od tablicy posortowanej
   bSaveResults->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::bLoadFileClick(TObject *Sender)
{
   fromFile();
   lSign->Caption = "Loaded";
   lSign->Font->Color = clNavy;
}
//---------------------------------------------------------------------------

void TfEducationalPage::saveToFile(AnsiString str)
{
   if(SaveDialog->Execute()) // Otw�rz SaveDialog
   {
      const char *file_name = SaveDialog->FileName.c_str(); // Pobranie nazwy pliku
      std::fstream file; // Utworzenie zmiennej plikowej
      file.open(file_name, std::ios::out); // Otworzenie pliku

      if( file.good() == true ) // Sprawdzenie czy plik si� otworzy�
      {
         lSign2->Visible = true;

         file << str.c_str();
         file.close(); // Zamknij plik

         lSign2->Visible = false;
      }else
      {
         ShowMessage("B��d pliku!!!");
         return;
      }
   }

}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::bSaveUnsortedClick(TObject *Sender)
{

   SaveDialog->FileName = "Unsorted table";
   saveToFile(unsorted_arr);

}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::bSaveSortedClick(TObject *Sender)
{
   lSign2->Visible = true;
   sorted_arr = getTable(tab);
   lSign2->Visible = false;

   SaveDialog->FileName = "Sorted table";
   saveToFile(sorted_arr);
}
//---------------------------------------------------------------------------

bool TfEducationalPage::checkAmount()
{
   int value;
    if( !TryStrToInt(eAmount->Text, value) ||
         value > sbAmount->Max ||
         value < sbAmount->Min )
    {
        ShowMessage("Invalid integer value entered, \ntry again between "
                     + IntToStr(sbAmount->Min) + " - " + IntToStr(sbAmount->Max));
        eAmount->SetFocus();

        return false;
    }

    sbAmount->Position = value;
    Repaint();

    return true;
}
//---------------------------------------------------------------------------

bool TfEducationalPage::checkRepeat()
{
   int value;
    if( !TryStrToInt(eRepeat->Text, value) ||
         ( StrToInt(eRepeat->Text)) > 0 )
    {
        ShowMessage("Invalid integer value entered, try again.");
        eRepeat->SetFocus();

        return false;
    }

    return true;
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::bSaveResultsClick(TObject *Sender)
{
   AnsiString results = lAlgoritmName->Caption + "\t\t" +  lComparisons->Caption + "\t\t" + lArrAccess->Caption + "\n" +
                        lMS2->Caption + "\t" + lCompMS2->Caption + "\t\t\t" + lArrMS2->Caption + "\n" +
                        lMS1->Caption + "\t" + lCompMS1->Caption + "\t\t\t" + lArrMS1->Caption + "\n" +
                        lMShalf->Caption + "\t" + lCompMShalf->Caption + "\t\t\t" + lArrMShalf->Caption + "\n" +
                        lQS->Caption + "\t\t" + lCompQS->Caption + "\t\t\t" + lArrQS->Caption + "\n";

   SaveDialog->FileName = "Results";
   saveToFile(results);
}
//---------------------------------------------------------------------------


