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
int __fastcall AlgorithmThreadAdv(Pointer Parameter);

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

template<class T>
void merge(T *arr, int left, int mid, int right){
	int n1 = mid - left + 1;
	T *temp_arr = new int [n1];
	
	int i = left; // indeks pocz¹tku lewej tablicy
	int j = mid + 1; // indeks pocz¹tku prawej tablicy
    int k = 0; // indeks pocz¹tku pomocniczej tablicy

	for(k = 0; k < n1; ++k, ++i){
		temp_arr[k] = arr[i];
	}
	
	k = 0;
    i = left;

	while(j <= right && k < n1){
		if(arr[j] < temp_arr[k]){
			arr[i++] = arr[j++];
		}else{
			arr[i++] = temp_arr[k++];
		}
	}
	while(k < n1){
		arr[i++] = temp_arr[k++];
	}

	delete [] temp_arr;
}
//---------------------------------------------------------------------------

template<class T>
void mergeSort(T *arr, int left, int right){
    if(left < right){
        int mid = (left + right) >> 1;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}
//---------------------------------------------------------------------------

void TfAdvancedPage::loadFileToArray(int*& arr, int &length)
{
   std::string stringTab; // Utwo¿enie stringa do przechowania wartoœci z pliku
   if( OpenDialog->Execute() ) // Otworzenie dialogu, do wybrania pliku
   {
      waitSignalOn();

      std::fstream file; // Utworzenie zmiennej plikowej
      file.open(OpenDialog->FileName.c_str(), std::ios::in); // Otworzenie pliku
      if( file.good() == true ) // Sprawdzenie czy plik siê otworzy³
      {
         getline(file, stringTab); // Pobranie ca³ej lini z pliku
         file.close(); // Zamknij plik
      }else
      {
         ShowMessage("B³¹d pliku!!!");
         return;
      }
   }

   int pos, j = 0, size = 0; // pos - pozycja ";", j - id tablicy,
   std::size_t found = stringTab.find(";"); // Wyszukanie ";" w stringu
   while(found != std::string::npos) // Jeœli wyszukana wartoœæ nie jest maksymaln¹ wartoœci¹ size_t, to...
   {
         size++; // Zwiêksz wielkoœæ tablicy o 1
         found = stringTab.find(";",found+1); // Ponownie wyszukaj ";", zaczynaj¹c od poprzedniego + 1 miejsca
   }
   length = size; // Ustaw obliczon¹ wielkoœæ tablicy pod zmienn¹ globaln¹
   arr = new int [n]; // Stwórz tablice

    while(!stringTab.empty()) // Jeœli string nie jest pusty, to...
    {
      pos = stringTab.find(";"); // ZnajdŸ miejsce ";"
      tab[j] = StrToInt(stringTab.substr(0, pos).c_str()); // Skopiuj czêœæ stringa, a potem zamieñ na int i wrzuæ do tablicy
      stringTab.erase(0, pos + 1); // Usuñ wyko¿ystan¹ ju¿ czêœæ stringa, wraz z ";"
      j++; // Zwiêksz id tablicy o 1
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
      table += IntToStr(arr[i]) + ";";
   }

   waitSignalOff();

   return table;
}
//---------------------------------------------------------------------------

void TfAdvancedPage::saveToFile(AnsiString str)
{
   if(SaveDialog->Execute()) // Otwórz SaveDialog
   {
      waitSignalOn();

      std::fstream file; // Utworzenie zmiennej plikowej
      file.open(SaveDialog->FileName.c_str(), std::ios::out); // Otworzenie pliku

      if( file.good() == true ) // Sprawdzenie czy plik siê otworzy³
      {
         lSign2->Visible = true;

         file << str.c_str();
         file.close(); // Zamknij plik

         lSign2->Visible = false;
      }else
      {
         ShowMessage("B³¹d pliku!!!");
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
   W_ID = BeginThread(NULL, 0, AlgorithmThreadAdv, this, 0, W_PD); // Zaczêcie w¹tku i uruchomienie algorytmów
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

int __fastcall AlgorithmThreadAdv(Pointer Parameter)
{
   fAdvancedPage->AlgorithmStart();
   ExitThread(GetExitCodeThread(AlgorithmThreadAdv, NULL)); // usuniêcie w¹tku z pamiêci, od tego momentu w¹tku nie mo¿na ju¿ wstrzymaæ.
   return 0;
}

void __fastcall TfAdvancedPage::bSortFileClick(TObject *Sender)
{
   bSortFile->Enabled = false;
   loadFileToArray(tab, n);
   sortArray();

   // TODELETE
   //WaitForSingleObject(AlgorithmThreadAdv, INFINITE);
   //checkIsSorted();
   //saveToFile(arrayToStr(tab));
   //bSortFile->Enabled = true;
}
//---------------------------------------------------------------------------

