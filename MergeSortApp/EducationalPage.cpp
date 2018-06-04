//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StartingPage.h"
#include "DidacticPage.h"
#include "EducationalPage.h"
#include "AdvancedPage.h"

#include <fstream>
#include <iomanip>
#include <iostream>

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
unsigned long long if_count; // iloœæ zliczonych porównañ
unsigned long long arr_access; // iloœæ zliczonych dostêpów do tablic
unsigned long long arr_changed; // iloœæ zliczonych zmian w tablicy

//---------------------------------------------------------------------------
__fastcall TfEducationalPage::TfEducationalPage(TComponent* Owner)
        : TForm(Owner)
{
	srand( time( NULL ) );

	n= sbAmount->Position; // Przypisanie pocz¹tkowej iloœci s³upków
    if_count = 0; // Nadanie pocz¹tkowej wartoœci licznika if'ów
    arr_access = 0; // Nadanie pocz¹tkowej wartoœci licznika dostêpów do tablicy
	arr_changed = 0; // Nadanie pocz¹tkowej wartoœci licznika zmian w tablicy
    time_sum = 0; // Nadanie pocz¹tkowej wartoœci licznika czasu

	first_run = true;
   
    DoubleBuffered = true;

    eAmount->Text = sbAmount->Position;
    rgTableTypes->Top = 97;
    fEducationalPage->ClientWidth = 230;  // Zmniejszenie wielkoœci formatki
}
//---------------------------------------------------------------------------
int __fastcall AlgorithmThread(Pointer Parameter);
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::mDydClick(TObject *Sender)
{
   PageChangeEdu();
   fEducationalPage->Hide();
   fDidacticPage->Show();
}	
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::mAdvClick(TObject *Sender)
{
   PageChangeEdu();
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
   PageChangeEdu();
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

void swap(int &a, int &b)
{
    int k = a;
    a = b;
    b = k;
}
//---------------------------------------------------------------------------

template<class T>
void heapify(T* arr, int n, int root)
{
    int largest = root;  // Initialize largest as root
    int left = 2*root + 1;
    int right = 2*root + 2;

    if(left < n) // Element aplikacji
    {
        ++if_count;
        arr_access += 2;
    }
    if (left < n && arr[left] > arr[largest]) // If left child is larger than root
        largest = left;

    if(right < n) // Element aplikacji
    {
        ++if_count;
        arr_access += 2;
    }
    if (right < n && arr[right] > arr[largest]) // If right child is larger than largest so far
        largest = right;

    if (largest != root) // If largest is not root
    {
        arr_access += 4; // Element aplikacji
		arr_changed += 2; // Element aplikacji
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify the affected sub-tree
    }
}

template<class T>
void heapSort(T* arr, int n)
{
    for (int root = n / 2 - 1; root >= 0; root--) // Build heap (rearrange array)
        heapify(arr, n, root);

    for (int end=n-1; end>=0; end--) // One by one extract an element from heap
    {
        arr_access += 4; // Element aplikacji
		arr_changed += 2; // Element aplikacji
        swap(arr[0], arr[end]); // Move current root to end
        heapify(arr, end, 0); // call max heapify on the reduced heap
    }
}
//---------------------------------------------------------------------------

template<class T>
void mergeOneTable(T *arr, int l, int  s, int p){
   T *pom = new T[p-l + 1]; // pomocnicza tablica do ³¹czenia
   int i = l; // indeks pocz¹tku lewej tablicy
   int j = s + 1; // indeks pocz¹tku prawej tablicy
   int k = 0; // indeks pocz¹tku pomocniczej tablicy
   while(i <= s && j <= p)
   {
      ++if_count; // Element aplikacji
      arr_access += 2; // Element aplikacji
      if(arr[i] <= arr[j])
	  {
         pom[k++] = arr[i++];
		arr_access += 2; // Element aplikacji
		arr_changed += 1; // Element aplikacji
	  }
	  else
	  {
         pom[k++] = arr[j++];
		arr_access += 2; // Element aplikacji
		arr_changed += 1; // Element aplikacji
	  }
   }
   // reszta elementów lewej po³owy
   while(i <= s)
   {
      pom[k++] = arr[i++];
	  arr_access += 2; // Element aplikacji
	  arr_changed += 1; // Element aplikacji
   }
   // reszta elementów prawej po³owy
   while(j <= p)
   {
      pom[k++] = arr[j++];
	  arr_access += 2; // Element aplikacji
	  arr_changed += 1; // Element aplikacji
   }
   // skopiuj po³¹czon¹ pomocnicz¹ tablice do oryginalnej tabicy
   for(k = 0, i = l; i <= p; ++i, ++k)
   {
      arr[i] = pom[k];
	  arr_access += 2; // Element aplikacji
	  arr_changed += 1; // Element aplikacji
   }

   delete []pom;
}
//---------------------------------------------------------------------------

template<class T>
void mergeSortOneTable(T *arr, int l, int r)
{
  if (l < r)
  {
    // To samo co (l+r)/2, ale unika przepe³nienia dla du¿ego l i r
    int m = l+(r-l)/2;

    // Sortowanie pierwszej i drugiej po³owy tablicy arr
    mergeSortOneTable(arr, l, m);
    mergeSortOneTable(arr, m+1, r);

    mergeOneTable(arr, l, m, r);
  }
}
//---------------------------------------------------------------------------

template<class T>
void mergesortOneTable(T *arr, int length)
{
    mergeSortOneTable(arr, 0, length-1);
}
//---------------------------------------------------------------------------

template<class T>
void mergeHalfTable(T *arr, int left, int mid, int right){
    arr_access += 2;
    ++if_count;
    if(arr[mid] <= arr[mid+1])
    {
        return;
    }
	int n1 = mid - left + 1;
	T *temp_arr = new T [n1];

	int i = left; // indeks pocz¹tku lewej tablicy
	int j = mid + 1; // indeks pocz¹tku prawej tablicy
    int k = 0; // indeks pocz¹tku pomocniczej tablicy

	for(k = 0; k < n1; ++k, ++i){
		temp_arr[k] = arr[i];
        arr_access += 2; // Element aplikacji
		arr_changed += 1; // Element aplikacji
	}

	k = 0;
    i = left;

    ++if_count; // Element aplikacji
    arr_access += 2; // Element aplikacji
	while(j <= right && k < n1)
    {
        ++if_count; // Element aplikacji
		arr_access += 2; // Element aplikacji
		if(arr[j] < temp_arr[k])
        {
			arr[i++] = arr[j++];
            arr_access += 2; // Element aplikacji
			arr_changed += 1; // Element aplikacji
		}else
        {
			arr[i++] = temp_arr[k++];
            arr_access += 2; // Element aplikacji
			arr_changed += 1; // Element aplikacji
		}
	}
	while(k < n1)
    {
		arr[i++] = temp_arr[k++];
        arr_access += 2; // Element aplikacji
		arr_changed += 1; // Element aplikacji
	}
	delete [] temp_arr;
}
//---------------------------------------------------------------------------

template<class T>
void mergeSortHalfTable(T *arr, int left, int right){
    if(left < right){
        int mid = (left + right) >> 1;
        mergeSortHalfTable(arr, left, mid);
        mergeSortHalfTable(arr, mid+1, right);
        mergeHalfTable(arr, left, mid, right);
    }
}
//---------------------------------------------------------------------------

template<class T>
void mergesortHalfTable(T *arr, int length)
{
    mergeSortHalfTable(arr, 0, length-1);
}
//---------------------------------------------------------------------------

template<class T>
void quicksort(T *x ,int first,int last)
{
    int pivot,j,temp,i;

    if(first<last)
    {
		pivot=first;
		i=first;
		j=last;

        while(i<j)
        {
            arr_access += 2; // Element aplikacji
            ++if_count; // Element aplikacji
			while(x[i]<=x[pivot]&&i<last)
            {
				i++;
                arr_access += 2; // Element aplikacji
                ++if_count; // Element aplikacji
            }
            arr_access += 2; // Element aplikacji
            ++if_count; // Element aplikacji
			while(x[j]>x[pivot])
            {
				j--;
                arr_access += 2; // Element aplikacji
                ++if_count; // Element aplikacji
            }
			if(i<j)
            {
				temp=x[i];
				x[i]=x[j];
				x[j]=temp;
                arr_access += 4; // Element aplikacji
                arr_changed += 2; // Element aplikacji
			}
		}

        temp=x[pivot];
		x[pivot]=x[j];
		x[j]=temp;
        arr_access += 4; // Element aplikacji
        arr_changed += 2; // Element aplikacji

		quicksort(x,first,j-1);
		quicksort(x,j+1,last);

    }
}
//---------------------------------------------------------------------------

template<class T>
void quickSort(T *arr, int length)
{
    quicksort(arr, 0, length-1);
}
//---------------------------------------------------------------------------

void  TfEducationalPage::clearAllResults()
{
   clearResults(lMS1, lCompMS1, lArrAccessMS1, lArrChangedMS1, lSortTimeMS1);
   clearResults(lMSHalf, lCompMSHalf, lArrAccessMSHalf, lArrChangedMSHalf, lSortTimeMSHalf);
   clearResults(lHS, lCompHS, lArrAccessHS, lArrChangedHS, lSortTimeHS);
   clearResults(lQS, lCompQS, lArrAccessQS, lArrChangedQS, lSortTimeQS);
}

void __fastcall TfEducationalPage::rgTableTypesClick(TObject *Sender)
{
   clearAllResults();

	changeSign("Setup...", clGray);

   rgTableTypes->Top = 33;
   eRepeat->Text = 1;

   if(fEducationalPage->Width < 640)
      tFormatAnim->Enabled = true; // W³¹czenie animacji rozsuniêcia formatki

   showElements();
}
//---------------------------------------------------------------------------

void TfEducationalPage::showElements()
{
   bGenerate->Visible = true;
   lRepeat->Visible = true;
   eRepeat->Visible = true;

   option = rgTableTypes->ItemIndex;
   if(option == 8)
   {
      lAmountName->Visible = false;
      eAmount->Visible = false;
      sbAmount->Visible = false;

      bGenerate->Top = 408;
      bGenerate->Caption = "Load file...";
   }
   else
   {
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
   clearAllResults();

   bSaveSorted->Enabled = false; // Zablokuj przycisk "Save..." od tablicy posortowanej
   bSaveResults->Enabled = false;

   if(option != 8) // Je¿eli nie wczytujemy z piku, to...
   {
		changeSign("Generating...",clNavy); 
   }else
   {
		changeSign("Loading...", clNavy);
   }

   if(!first_run) // Przy pierwszym odpaleniu, pomiñ usuwanie tablicy
   {
	   waitSignalOn();
      deleteTable(tab); // Usuñ tablice
	  deleteTable(tab_MS1); // Usuñ tablice
	  deleteTable(tab_MSHalf); // Usuñ tablice
	  deleteTable(tab_HS); // Usuñ tablice
	  deleteTable(tab_QS); // Usuñ tablice
	  waitSignalOff();
   }

   first_run = false; // Ustaw "flage". Tablica wygenerowana przynajmniej 1 raz
   if(option != 8) // Je¿eli nie wczytujemy z piku, to...
   {
      n = sbAmount->Position; // Ustaw wielkoœæ tablicy
      createTable(tab, n); // Stwórz tablice
   }
	waitSignalOn();
  switch(option) // Utworzenie tablicy wed³ug wybranej opcji
  {
    case 0: randomTable(tab, n);
            break;
    case 1: reversedTable(tab, n);
            break;
    case 2: constantTable(tab, n);
            break;
    case 3: arrowUpTable(tab, n);
            break;
    case 4: arrowDownTable(tab, n);
            break;
    case 5: almostSortedTable(tab, n);
            break;
    case 6: fewUniqueTable(tab, n);
            break;
    case 7: sortedTable(tab, n);
            break;
    case 8: fromFile(tab, n);
            break;
  }
	waitSignalOff();
   if(option != 8) // Je¿eli nie wczytujemy z piku, to...
   {
		changeSign("Table generated", clNavy);
   }else
   {
        if(!opened)
        {
            changeSign("Setup...", clGray);
            return;
        }
		changeSign("Loaded", clNavy);
   }
   
   bSaveUnsorted->Enabled = true; // Odblokuj przycisk "Save..." od tablicy nieposortowanej

   bStart->Enabled = true; // Odblokowanie przycisku "Start". Umo¿liwienie wystartowania algorytmu
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::sbAmountChange(TObject *Sender)
{
   bGenerate->Enabled = true;
   eAmount->Text = sbAmount->Position;
}
//---------------------------------------------------------------------------
template<class T>
void TfEducationalPage::randomTable(T*& arr, int length)
{
    for(int i=0; i < length; i++)
    {
        arr[i] = rand() % 200000;
    }
}
//---------------------------------------------------------------------------

template<class T>
void TfEducationalPage::reversedTable(T*& arr, int length)
{
   do
   {
      arr[0] = rand() % 200000;
   }while(arr[0] < 20000);

    for(int i=1; i < length; i++)
    {
        arr[i] = arr[i-1] - (rand() % 2000);
    }
}
//---------------------------------------------------------------------------

template<class T>
void TfEducationalPage::constantTable(T*& arr, int length)
{
  int random = rand() % 20000;

  for(int i=0; i < length; i++)
  {
      arr[i] = random;
  }
}
//---------------------------------------------------------------------------

template<class T>
void TfEducationalPage::arrowDownTable(T*& arr, int length)
{
   do
   {
      arr[0] = rand() % 200000;
   }while(arr[0] < 20000);

   for(int i=1; i < length; i++)
   {
      arr[i] = (i > n/2)? arr[i-1] - rand() % 2000 : arr[i-1] + rand() % 2000;
   }
}
//---------------------------------------------------------------------------

template<class T>
void TfEducationalPage::arrowUpTable(T*& arr, int length)
{
   do
   {
      arr[0] = -(rand() % 200000);
   }while(arr[0] < -20000);

   for(int i=1; i < length; i++)
   {
      arr[i] = (i > n/2)? arr[i-1] + rand() % 2000 : arr[i-1] - rand() % 2000;
   }
}
//---------------------------------------------------------------------------

template<class T>
void TfEducationalPage::almostSortedTable(T*& arr, int length)
{
  do
  {
      arr[0] = -(rand() % 20000);
  }while(arr[0] < -10000);

  for(int i=1; i < length; i++)
  {
        arr[i] = arr[i-1] + (rand() % 2000);
  }
  int random;
  int how_many = 0.1 * length;

  for(int i=0; i < how_many; i++)
  {
      random = rand() % length;
      arr[random] = rand() % 20000;
  }

}
//---------------------------------------------------------------------------

template<class T>
void TfEducationalPage::fewUniqueTable(T*& arr, int length)
{
    int tab_length;
    if(length > 10000)
        tab_length = 0.001 * length;
    else if(length > 100)
        tab_length = 0.1 * length;
    else
        tab_length = 3;
  T *tabRand = new T[tab_length];
  for(int i = 0; i< tab_length; i++)
  {
    tabRand[i] = rand() % 2000000;
  }

  for(int i=0; i < length; i++)
  {
      arr[i] = tabRand[rand() % tab_length];
  }
  delete [] tabRand;
}
//---------------------------------------------------------------------------

template<class T>
void TfEducationalPage::sortedTable(T*& arr, int length)
{
   do
   {
      arr[0] = -(rand() % 20000);
   }while(arr[0] < -10000);

    for(int i=1; i < length; i++)
    {
        arr[i] = arr[i-1] + (rand() % 2000);
    }
}
//---------------------------------------------------------------------------


void TfEducationalPage::countsize(std::fstream &f, int& size)
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
void TfEducationalPage::createTable(T*& arr, const int size)
{
    arr = new T[size];
}
//---------------------------------------------------------------------------

template<class T>
void TfEducationalPage::fillTableFromFile(T*& arr, const int size, std::fstream &f)
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
void TfEducationalPage::fromFile(T*& arr, int& size)
{
    if( OpenDialog->Execute() ) // Otworzenie dialogu, do wybrania pliku
    {
        opened = true;
        waitSignalOn(); // Zakumnikowanie u¿ytkownika o trwaj¹cych pracach

        std::fstream file(OpenDialog->FileName.c_str(), std::ios::in); // Otworzenie pliku
        if (!file)
        {
            ShowMessage("B³¹d pliku!!!");
            return;
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
void TfEducationalPage::deleteTable(T*& arr){
  delete [] arr;
}
//---------------------------------------------------------------------------

void TfEducationalPage::clearResults(TLabel *algName, TLabel *comp, TLabel *access, TLabel *changed, TLabel *stime)
{
    algName->Color = clBtnFace;
    comp->Caption = 0;
    access->Caption = 0;
    changed->Caption = 0;
	stime->Caption = 0;
}
//---------------------------------------------------------------------------

template<class T>
void TfEducationalPage::copyTable(const T *original, T *&tempTable)
{
	for(int i=0; i < n; i++)
	{
		tempTable[i] = original[i];
	}
}
//---------------------------------------------------------------------------

template<class T>
void TfEducationalPage::copyTables(const T* arr){
    createTable(tab_MS1, n);
	copyTable(arr, tab_MS1);
	createTable(tab_MSHalf, n);
	copyTable(arr, tab_MSHalf);
	createTable(tab_HS, n);
	copyTable(arr, tab_HS);
	createTable(tab_QS, n);
    copyTable(arr, tab_QS);
}

void __fastcall TfEducationalPage::bStartClick(TObject *Sender)
{
   bStart->Enabled = false; // Zablokowanie przycisku Start. Uniemo¿liwienie w³¹czenia algorytmu podczas jego dzia³ania
   PanelLeft->Enabled = false; // Zablokowanie lewego panelu. Uniemo¿liwienie zmian, podczas dzia³ania algorytmu
   bGenerate->Enabled = false; // Zablokowanie przycisku "Generate again". Tak jak w lini wy¿ej, tylko ¿e z efektem wizuanym

   changeSign("Sorting...", clGreen);

   W_ID = BeginThread(NULL, 0, AlgorithmThread, this, 0, W_PD); // Zaczêcie w¹tku i uruchomienie algorytmów
}
//---------------------------------------------------------------------------

bool TfEducationalPage::isSorted(int *table)
{
   for(int i=1; i < n; i++)
   {
      if(table[i-1] > table[i])
         return false;
   }
   return true;
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::tFormatAnimTimer(TObject *Sender)
{
   fEducationalPage->Width += 20;
   fEducationalPage->Left -= 10;
   if(fEducationalPage->Width >= 882)
   {
      tFormatAnim->Enabled = false;
   }
}
//---------------------------------------------------------------------------

void TfEducationalPage::sumResults()
{
   float div = StrToFloat(eRepeat->Text);
   comparision_sum += if_count / div;
   access_sum += arr_access / div;
   changed_sum += arr_changed / div;
   time_sum += stime / div;
   if_count = 0;
   arr_access = 0;
   arr_changed = 0;
   stime = 0;
}
//---------------------------------------------------------------------------

void TfEducationalPage::sort(void (*algorithm)(int*, int), int* array, int length,
                    int repeat, TLabel* lName, TLabel* lComp, TLabel* lAccess, TLabel *lChanged, TLabel* lTime)
{
    waitSignalOn();
	for(int index = 0; index < repeat; ++index)
    {
        copyTable(tab, array);
        clock_t begin_time = clock();
        algorithm(array, length);
        stime = (int)(clock() - begin_time );
        sumResults();
    }
	waitSignalOff();
    showResults(array, lName, lComp, lAccess, lChanged, lTime);
}
//---------------------------------------------------------------------------

void TfEducationalPage::AlgorithmStartEdu()
{
   int repeat = StrToInt(eRepeat->Text);
   
   waitSignalOn();
   copyTables(tab);
   waitSignalOff();

   sort(&mergesortOneTable, tab_MS1, n, repeat, lMS1, lCompMS1, lArrAccessMS1, lArrChangedMS1, lSortTimeMS1);
   sort(&mergesortHalfTable, tab_MSHalf, n, repeat, lMSHalf, lCompMSHalf, lArrAccessMSHalf, lArrChangedMSHalf, lSortTimeMSHalf);
   sort(&heapSort, tab_HS, n, repeat, lHS, lCompHS, lArrAccessHS, lArrChangedHS, lSortTimeHS);

   if((eAmount->Text > 61000 && rgTableTypes->ItemIndex == 5) ||
      ((rgTableTypes->ItemIndex == 1 || rgTableTypes->ItemIndex == 2 || rgTableTypes->ItemIndex == 7) && eAmount->Text > 28000))
   {
      lCompQS->Caption = "Stack";
      lArrAccessQS->Caption = "Over";
      lArrChangedQS->Caption = "Flow";
      lSortTimeQS->Caption = "!";
   }
   else
   {
       sort(&quickSort, tab_QS, n, repeat, lQS, lCompQS, lArrAccessQS, lArrChangedQS, lSortTimeQS);
   }

   end();
}
//---------------------------------------------------------------------------

int __fastcall AlgorithmThread(Pointer Parameter)
{
   fEducationalPage->AlgorithmStartEdu();
   ExitThread(GetExitCodeThread(AlgorithmThread, NULL)); // usuniêcie w¹tku z pamiêci, od tego momentu w¹tku nie mo¿na ju¿ wstrzymaæ.
   return 0;
}
//---------------------------------------------------------------------------

float TfEducationalPage::round(float var)
{
    long long value = (long long)(var * 100 + .5);
    return (float)value / 100;
}
//---------------------------------------------------------------------------

void TfEducationalPage::showResults(int *table, TLabel *algName, TLabel *comparisions, TLabel *access, TLabel *changed, TLabel *stime)
{
   comparisions->Caption = round(comparision_sum);
   access->Caption = round(access_sum);
   changed->Caption = round(changed_sum);
   stime->Caption = round(time_sum);
   comparision_sum = 0;
   access_sum = 0;
   changed_sum = 0;
   time_sum = 0;

   if(algName->Color != clRed)
   {
	   if(isSorted(table))
	   {
		  algName->Color = clLime;
	   }
	   else
	   {
		  algName->Color = clRed;
	   }
	   Repaint();
   }
}
//---------------------------------------------------------------------------

void TfEducationalPage::end()
{
	changeSign("Completed", clGreen);

   PanelLeft->Enabled = true; // Odblokowanie lewego panelu. Odblokowanie mo¿liwoœci wyboru.
   bGenerate->Enabled = true; // Odblokowanie przycisku "Generate again". Tak jak w lini wy¿ej, tylko ¿e z efektem wizuanym

   if(lMS1->Color != clRed &&
        lMSHalf->Color != clRed &&
		lHS->Color != clRed &&
        lQS->Color != clRed)
   {
        bSaveSorted->Enabled = true; // Odblokuj przycisk "Save..." od tablicy posortowanej
        bSaveResults->Enabled = true;
   }
}
//---------------------------------------------------------------------------
void TfEducationalPage::changeSign(String text, TColor color)
{
    lSign->Caption = text; // Ustaw komunikat
    lSign->Font->Color = color; // Ustaw kolor komunikatu
    Repaint(); // Odœwie¿ formatke
}

//---------------------------------------------------------------------------
template <class T>
bool isString(T* t) { return false;  } // normal case returns false

template <>
bool isString(char* t) { return true; }  // but for char* or String.c_str() returns true

template<class T>
void TfEducationalPage::saveToFile(T* arr)
{
   if(SaveDialog->Execute()) // Otwórz SaveDialog
   {
      waitSignalOn();

      std::fstream file; // Utworzenie zmiennej plikowej
      file.open(SaveDialog->FileName.c_str(), std::ios::out); // Otworzenie pliku

      if( file.good() == true ) // Sprawdzenie czy plik siê otworzy³
      {
         lSign2->Visible = true;

         if(isString(arr))
         {
            file << arr;
         }
         else
         {
           for(int i=0; i < n; i++)
           {
              file << arr[i] << ";";
           }
         }
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

void __fastcall TfEducationalPage::bSaveUnsortedClick(TObject *Sender)
{
	waitSignalOn();
	
	SaveDialog->FileName = "Unsorted table";
	saveToFile(tab);
	
	waitSignalOff();
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::bSaveSortedClick(TObject *Sender)
{
	waitSignalOn();
	
	SaveDialog->FileName = "Sorted table";
	saveToFile(tab_MS1);

	waitSignalOff();
}	
//---------------------------------------------------------------------------
bool TfEducationalPage::isAmountGood()
{
    int value;
	return ( TryStrToInt(eAmount->Text, value) ||
			value > sbAmount->Max ||
			value < sbAmount->Min );
}
void TfEducationalPage::checkAmount()
{
    if( !isAmountGood() )
    {
        ShowMessage("Invalid integer value entered, \ntry again between "
                     + IntToStr(sbAmount->Min) + " - " + IntToStr(sbAmount->Max));
        eAmount->Text = 1000;
        eAmount->SetFocus();
    }

    sbAmount->Position = StrToInt(eAmount->Text);
    Repaint();
}
//---------------------------------------------------------------------------
bool TfEducationalPage::isRepeatGood()
{
    int value;
	return (TryStrToInt(eRepeat->Text, value) || 
			( StrToInt(eRepeat->Text)) < 1);
}
void TfEducationalPage::checkRepeat()
{
    if( !isRepeatGood() )
    {
        ShowMessage("Invalid integer value entered, try again.");
        eRepeat->Text = 1;
        eRepeat->SetFocus();
    }
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::bSaveResultsClick(TObject *Sender)
{
    std::ostringstream str;
    str << "Type of table: " << rgTableTypes->Items->Strings[rgTableTypes->ItemIndex].c_str() << "\n"
        << "Table type: " << "Integer" << "\n"
        << "Number of repetitions: " << StrToInt(eRepeat->Text) << "\n"
        << "Size of the table: " << n << "\n\n"
        << lAlgoritmName->Caption.c_str() << "\t\t" << lComparisons->Caption.c_str() << "\t\t" << lArrAccess->Caption.c_str() << "\t\t" << lArrChanged->Caption.c_str() << "\t\t" << lSortTime->Caption.c_str() << "\n"
        << lMS1->Caption.c_str() << std::setw(16) << lCompMS1->Caption.c_str() << std::setw(21) << lArrAccessMS1->Caption.c_str() << std::setw(21) << lArrChangedMS1->Caption.c_str() << std::setw(16) << lSortTimeMS1->Caption.c_str() << "\n"
        << lMSHalf->Caption.c_str() << std::setw(13) << lCompMSHalf->Caption.c_str() << std::setw(21) << lArrAccessMSHalf->Caption.c_str() << std::setw(21) << lArrChangedMSHalf->Caption.c_str() << std::setw(16) << lSortTimeMSHalf->Caption.c_str() << "\n"
        << lHS->Caption.c_str() << std::setw(23) << lCompHS->Caption.c_str() << std::setw(21) << lArrAccessHS->Caption.c_str() << std::setw(21) << lArrChangedHS->Caption.c_str() << std::setw(16) << lSortTimeHS->Caption.c_str() << "\n"
        << lQS->Caption.c_str() << std::setw(22) << lCompQS->Caption.c_str() << std::setw(21) << lArrAccessQS->Caption.c_str() << std::setw(21) << lArrChangedQS->Caption.c_str() << std::setw(16) << lSortTimeQS->Caption.c_str() << "\n"
        ;

   AnsiString result = str.str().c_str();
   SaveDialog->FileName = "Results";
   saveToFile(result.c_str());
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::eRepeatExit(TObject *Sender)
{
   checkRepeat();
}
//---------------------------------------------------------------------------


void __fastcall TfEducationalPage::eAmountExit(TObject *Sender)
{
   checkAmount();
}
//---------------------------------------------------------------------------

void TfEducationalPage::PageChangeEdu()
{
   eRepeat->Text = 1;
   eAmount->Text = 1000;
   sbAmount->Position = 1000;

   rgTableTypes->Top = 97;
   bGenerate->Visible = false;
   lRepeat->Visible = false;
   eRepeat->Visible = false;
   lAmountName->Visible = false;
   eAmount->Visible = false;
   sbAmount->Visible = false;
   rgTableTypes->ItemIndex = -1;

   fEducationalPage->Left = 840; // przesuniêcie formatki na œrodek ekranu
   fEducationalPage->ClientWidth = 230;  // Zmniejszenie wielkoœci formatki
}
//---------------------------------------------------------------------------

void TfEducationalPage::waitSignalOn()
{
   lSign2->Visible = true;
   Repaint();
}
//---------------------------------------------------------------------------

void TfEducationalPage::waitSignalOff()
{
   lSign2->Visible = false;
   Repaint();
}
//---------------------------------------------------------------------------








