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
	T *temp_arr = new T [n1];
	
	int i = left; // indeks pocz�tku lewej tablicy
	int j = mid + 1; // indeks pocz�tku prawej tablicy
    int k = 0; // indeks pocz�tku pomocniczej tablicy

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

void countsize(std::fstream &f, int& size)
{
    size = 0;
    char text;
    while (!f.eof()) //loops until end of user specified file
    {
        f.get(text); //gets char from input file
        if(text == ';')
        {
            ++size;
        }
    }
    --size;
    f.clear();
  f.seekg(0, std::ios::beg);
}
//---------------------------------------------------------------------------

template<class T>
void createTable(T*& arr, const int size)
{
    arr = new T[size];
}
//---------------------------------------------------------------------------

template<class T>
void fillTable(T*& arr, const int size, std::fstream &f)
{
    T temp;
    int i=0;
    while(f >> temp)
    {
        arr[i++] = temp;
        f.ignore(); // zignorowanie ";"
    }
}
//---------------------------------------------------------------------------

template<class T>
void TfAdvancedPage::loadFile(T*& arr, int& size)
{
    if( OpenDialog->Execute() ) // Otworzenie dialogu, do wybrania pliku
    {
        opened = true;
        waitSignalOn(); // Zakumnikowanie u�ytkownika o trwaj�cych pracach

        std::fstream file(OpenDialog->FileName.c_str(), std::ios::in); // Otworzenie pliku
        if (!file)
        {
            ShowMessage("B��d pliku!!!");
            return;
        }
        else
        {
            countsize(file, size); // oblicz wielko�� tablicy
            createTable(arr, size); // Stw�rz tablice
            fillTable(arr, size, file);
        }
        file.close(); //Zamkni�cie pliku tekstowego

        waitSignalOff(); // Zakumnikowanie u�ytkownika o zako�czeniu prac
    }
    else
    {
        opened = false;
    }
}
//---------------------------------------------------------------------------

template<class T>
String TfAdvancedPage::arrayToStr(const T *arr)
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

template<class T>
void TfAdvancedPage::saveToFile(T* arr)
{
   if(SaveDialog->Execute()) // Otw�rz SaveDialog
   {
      waitSignalOn();

      std::fstream file; // Utworzenie zmiennej plikowej
      file.open(SaveDialog->FileName.c_str(), std::ios::out); // Otworzenie pliku

      if( file.good() == true ) // Sprawdzenie czy plik si� otworzy�
      {
         lSign2->Visible = true;

         for(int i=0; i < n; i++)
         {
            file << arr[i] << ";";
         }
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

template<class T>
bool TfAdvancedPage::isSorted(const T* arr, const int length)
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

template<class T>
void TfAdvancedPage::checkIsSorted(const T* arr)
{
   if(!isSorted(arr, n))
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
   W_ID = BeginThread(NULL, 0, AlgorithmThreadAdv, this, 0, W_PD); // Zacz�cie w�tku i uruchomienie algorytm�w
}
//---------------------------------------------------------------------------

void TfAdvancedPage::AlgorithmStart()
{
    waitSignalOn();

    mergeSort(tab, 0, n-1);

    waitSignalOff();

    if(opened)
    {
        checkIsSorted(tab);
        saveToFile(tab);
    }
    bSortFile->Enabled = true;
}
//---------------------------------------------------------------------------

int __fastcall AlgorithmThreadAdv(Pointer Parameter)
{
   fAdvancedPage->AlgorithmStart();
   ExitThread(GetExitCodeThread(AlgorithmThreadAdv, NULL)); // usuni�cie w�tku z pami�ci, od tego momentu w�tku nie mo�na ju� wstrzyma�.
   return 0;
}

void __fastcall TfAdvancedPage::bSortFileClick(TObject *Sender)
{
   bSortFile->Enabled = false;
   loadFile(tab, n);
   if(!opened)
   {
        return;
   }
   sortArray();
}
//---------------------------------------------------------------------------


