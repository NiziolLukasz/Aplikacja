//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StartingPage.h"
#include "DidacticPage.h"
#include "EducationalPage.h"
#include "AdvancedPage.h"

#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfAdvancedPage *fAdvancedPage;
//---------------------------------------------------------------------------
__fastcall TfAdvancedPage::TfAdvancedPage(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
int __fastcall AlgorithmThread(Pointer Parameter);

//---------------------------------------------------------------------------
void __fastcall TfAdvancedPage::mDidClick(TObject *Sender)
{
   fAdvancedPage->Hide();
   fDidacticPage->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfAdvancedPage::mEduClick(TObject *Sender)
{
   fAdvancedPage->Hide();
   fEducationalPage->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfAdvancedPage::mExitClick(TObject *Sender)
{
   fStartingPage->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfAdvancedPage::mStartClick(TObject *Sender)
{
   fAdvancedPage->Hide();
   fStartingPage->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfAdvancedPage::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   fStartingPage->Close();
}
//---------------------------------------------------------------------------
void TfAdvancedPage::merge(int *&arr, int l, int m, int r) /* l - left, m - middle, r- right */
{

    int i, j, k;
    int n1 = m - l + 1; // ilo�� element�w w pierwszej podtablicy
    int n2 =  r - m; // ilo�� element�w w drugiej podtablicy

    // Tworzenie pomocniczych tablic
    int *L = new int [n1];
    int *R = new int [n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }

    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1+ j];
    }

    // ��czenie pomocniczych tablic spowrotem do arr[l..r]
    i = 0; // Pocz�tkowy indeks pierwszej podtablicy
    j = 0; // Pocz�tkowy indeks drugiej podtablicy
    k = l; // Pocz�tkowy indeks po��czonej podtablicy

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

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Usuni�cie dodatkowch tablic
    delete [] L;
    delete [] R;
}
//---------------------------------------------------------------------------

void TfAdvancedPage::mergeSort(int *&arr, int l, int r)
{
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

void TfAdvancedPage::loadFileToArray(int*& arr, int &length)
{
   std::string stringTab; // Utwo�enie stringa do przechowania warto�ci z pliku
   if( OpenDialog->Execute() ) // Otworzenie dialogu, do wybrania pliku
   {
      waitSignalOn();

      std::fstream file; // Utworzenie zmiennej plikowej
      file.open(OpenDialog->FileName.c_str(), std::ios::in); // Otworzenie pliku
      if( file.good() == true ) // Sprawdzenie czy plik si� otworzy�
      {
         getline(file, stringTab); // Pobranie ca�ej lini z pliku
         file.close(); // Zamknij plik
      }else
      {
         ShowMessage("B��d pliku!!!");
         return;
      }
   }

   int pos, j = 0, size = 0; // pos - pozycja ";", j - id tablicy,
   std::size_t found = stringTab.find(";"); // Wyszukanie ";" w stringu
   while(found != std::string::npos) // Je�li wyszukana warto�� nie jest maksymaln� warto�ci� size_t, to...
   {
         size++; // Zwi�ksz wielko�� tablicy o 1
         found = stringTab.find(";",found+1); // Ponownie wyszukaj ";", zaczynaj�c od poprzedniego + 1 miejsca
   }
   length = size; // Ustaw obliczon� wielko�� tablicy pod zmienn� globaln�
   arr = new int [n]; // Stw�rz tablice

    while(!stringTab.empty()) // Je�li string nie jest pusty, to...
    {
      pos = stringTab.find(";"); // Znajd� miejsce ";"
      tab[j] = StrToInt(stringTab.substr(0, pos).c_str()); // Skopiuj cz�� stringa, a potem zamie� na int i wrzu� do tablicy
      stringTab.erase(0, pos + 2); // Usu� wyko�ystan� ju� cz�� stringa, wraz z ";"
      j++; // Zwi�ksz id tablicy o 1
    }

   waitSignalOff();
}
//---------------------------------------------------------------------------

String TfAdvancedPage::arrayToStr(const int *&arr)
{
   waitSignalOn();

   AnsiString table = "";
   for(int i=0; i < n; i++)
   {
      table += IntToStr(arr[i]) + "; ";
   }

   waitSignalOff();

   return table;
}
//---------------------------------------------------------------------------

void TfAdvancedPage::saveToFile(AnsiString str)
{
   if(SaveDialog->Execute()) // Otw�rz SaveDialog
   {
      waitSignalOn();

      std::fstream file; // Utworzenie zmiennej plikowej
      file.open(SaveDialog->FileName.c_str(), std::ios::out); // Otworzenie pliku

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

   waitSignalOff();
}
//---------------------------------------------------------------------------

bool TfAdvancedPage::isSorted(int*& arr, int length)
{
   waitSignalOn();

   for(int i=1; i < length; i++)
   {
      if(arr[i-1] > arr[i])
      {
         return false;
      }
   }

   waitSignalOff();

   return true;
}
//---------------------------------------------------------------------------

void TfAdvancedPage::checkIsSorted()
{
   if(!isSorted(tab, n))
   {
      ShowMessage("The array is not sorted!!");
      SaveDialog->FileName = "Not sorted array";
   }
   else
   {
      SaveDialog->FileName = "Sorted array";
   }
}
//---------------------------------------------------------------------------

void TfAdvancedPage::waitSignalOn()
{
   lSign2->Visible = true;
   Repaint();
}
//---------------------------------------------------------------------------

void TfAdvancedPage::waitSignalOff()
{
   lSign2->Visible = false;
   Repaint();
}
//---------------------------------------------------------------------------

void TfAdvancedPage::sortArray()
{
   W_ID = BeginThread(NULL, 0, AlgorithmThread, this, 0, W_PD); // Zacz�cie w�tku i uruchomienie algorytm�w
}
//---------------------------------------------------------------------------

void TfAdvancedPage::AlgorithmStart()
{
   waitSignalOn();

   mergeSort(tab, 0, n-1);

   waitSignalOff();

   checkIsSorted();
   saveToFile(arrayToStr(tab));
   bSortFile->Enabled = true;
}
//---------------------------------------------------------------------------

int __fastcall AlgorithmThread(Pointer Parameter)
{
   fAdvancedPage->AlgorithmStart();
   ExitThread(GetExitCodeThread(AlgorithmThread, NULL)); // usuni�cie w�tku z pami�ci, od tego momentu w�tku nie mo�na ju� wstrzyma�.
   return 0;
}

void __fastcall TfAdvancedPage::bSortFileClick(TObject *Sender)
{
   bSortFile->Enabled = false;
   loadFileToArray(tab, n);
   sortArray();

   // TODELETE
   //WaitForSingleObject(AlgorithmThread, INFINITE);
   //checkIsSorted();
   //saveToFile(arrayToStr(tab));
   //bSortFile->Enabled = true;
}
//---------------------------------------------------------------------------

