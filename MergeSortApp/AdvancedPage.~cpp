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
void fillTableFromFile(T*& arr, const int size, std::fstream &f)
{
    T temp;
    int i=0;

    while(f >> temp)
    {
        arr[i++] = temp;
        f.ignore(); // zignorowanie znaku rozdzielaj¹cego
    }

}
//---------------------------------------------------------------------------

template<class T>
void TfAdvancedPage::loadFile(T*& arr, int& size)
{
    if( OpenDialog->Execute() ) // Otworzenie dialogu, do wybrania pliku
    {
        opened = true;
        waitSignalOn(); // Zakumnikowanie u¿ytkownika o trwaj¹cych pracach

        std::fstream file(OpenDialog->FileName.c_str(), std::ios::in); // Otworzenie pliku
        if (!file)
        {
            ShowMessage("B³¹d pliku!!!");
            opened = false;
        }
        else
        {
            countsize(file, size); // oblicz wielkoœæ tablicy
            createTable(arr, size); // Stwórz tablice
            fillTableFromFile(arr, size, file);
        }
        file.close(); //Zamkniêcie pliku tekstowego

        waitSignalOff(); // Zakumnikowanie u¿ytkownika o zakoñczeniu prac
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
   if(SaveDialog->Execute()) // Otwórz SaveDialog
   {
      waitSignalOn();

      std::fstream file; // Utworzenie zmiennej plikowej
      file.open(SaveDialog->FileName.c_str(), std::ios::out); // Otworzenie pliku

      if( file.good() == true ) // Sprawdzenie czy plik siê otworzy³
      {

         for(int i=0; i < n; i++)
         {
            file << arr[i] << ";";
         }
         file.close(); // Zamknij plik

      }else
      {
         ShowMessage("B³¹d pliku!!!");
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
template<class T>
void TfAdvancedPage::start(T*& tab)
{
   loadFile(tab, n);
    if(!opened)
    {
        bSortFile->Enabled = true;
        return;
    }
    waitSignalOn();

    mergeSort(tab, 0, n-1);

    waitSignalOff();

    if(opened)
    {
        checkIsSorted(tab);
        saveToFile(tab);
        delete [] tab;
    }
    bSortFile->Enabled = true;
}

void TfAdvancedPage::AlgorithmStartAdv()
{
    switch(rgTypes->ItemIndex)
    {
        case 0: start(tab_int);
                break;
        case 1: start(tab_double);
                break;
        case 2: startString();
                break;
    }
}
//---------------------------------------------------------------------------

int __fastcall AlgorithmThreadAdv(Pointer Parameter)
{
   fAdvancedPage->AlgorithmStartAdv();
   ExitThread(GetExitCodeThread(AlgorithmThreadAdv, NULL)); // usuniêcie w¹tku z pamiêci, od tego momentu w¹tku nie mo¿na ju¿ wstrzymaæ.
   return 0;
}

void __fastcall TfAdvancedPage::bSortFileClick(TObject *Sender)
{
   bSortFile->Enabled = false;
   sortArray();
}
//---------------------------------------------------------------------------

int TfAdvancedPage::stringSize(std::string str)
{
   int size = 0;
   std::size_t found = str.find(";"); // Wyszukanie ";" w stringu
   while(found != std::string::npos) // Jeœli wyszukana wartoœæ nie jest maksymaln¹ wartoœci¹ size_t, to...
   {
         ++size; // Zwiêksz wielkoœæ tablicy o 1
         found = str.find(";",found+1); // Ponownie wyszukaj ";", zaczynaj¹c od poprzedniego + 1 miejsca
   }
   return size;
}
//---------------------------------------------------------------------------

void TfAdvancedPage::stringToArray(AnsiString* arr, std::string str)
{
   int pos, j= 0;
   while(!str.empty()) // Jeœli string nie jest pusty, to...
   {
       pos = str.find(";"); // ZnajdŸ miejsce ";"
       arr[j] = str.substr(0, pos).c_str(); // Skopiuj czêœæ stringa
       str.erase(0, pos + 1); // Usuñ wyko¿ystan¹ ju¿ czêœæ stringa, wraz z ";"
       j++; // Zwiêksz id tablicy o 1
   }
}
//---------------------------------------------------------------------------

std::string TfAdvancedPage::loadStringFromFile()
{
   std::string str; // Utwo¿enie stringa do przechowania wartoœci z pliku
   if( OpenDialog->Execute() ) // Otworzenie dialogu, do wybrania pliku
   {
       opened = true;

       waitSignalOn(); // Zakumnikowanie u¿ytkownika o trwaj¹cych pracach
       std::fstream file(OpenDialog->FileName.c_str(), std::ios::in); // Otworzenie pliku
       if (!file)
       {
           ShowMessage("B³¹d pliku!!!");
           opened = false;
       }
       else
       {
           getline(file, str); // Pobranie ca³ej lini z pliku
       }
       file.close(); //Zamkniêcie pliku tekstowego

       waitSignalOff(); // Zakumnikowanie u¿ytkownika o zakoñczeniu prac
   }
   else
   {
       opened = false;
   }

   return str;
}
//---------------------------------------------------------------------------

void TfAdvancedPage::saveStirngToFile(AnsiString* str)
{
   if(SaveDialog->Execute()) // Otwórz SaveDialog
    {
      waitSignalOn();

      std::fstream file; // Utworzenie zmiennej plikowej
      file.open(SaveDialog->FileName.c_str(), std::ios::out); // Otworzenie pliku

      if( file.good() == true ) // Sprawdzenie czy plik siê otworzy³
      {
         for(int i=0; i < n; i++)
         {
            file << str[i].c_str() << ";";
         }
         file.close(); // Zamknij plik
      }else
      {
         ShowMessage("B³¹d pliku!!!");
      }
      waitSignalOff();
    }
}
//---------------------------------------------------------------------------
void TfAdvancedPage::startString()
{
   std::string str = loadStringFromFile(); // Utwo¿enie stringa do przechowania wartoœci z pliku
   
   if(!opened)
    {
        bSortFile->Enabled = true;
        return;
    }   
	
   n = stringSize(str);
   tab_string = new AnsiString [n];
   stringToArray(tab_string, str);
   
   waitSignalOn();

   mergeSort(tab_string, 0, n-1);

   waitSignalOff();
	
	if(opened)
    {
		checkIsSorted(tab_string);
		saveStirngToFile(tab_string);
		delete [] tab_string;
	}
   bSortFile->Enabled = true;
}





