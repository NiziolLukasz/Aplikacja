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

    if(left < n)
    {
        ++if_count;
        arr_access += 2;
    }
    if (left < n && arr[left] > arr[largest]) // If left child is larger than root
        largest = left;

    if(right < n)
    {
        ++if_count;
        arr_access += 2;
    }
    if (right < n && arr[right] > arr[largest]) // If right child is larger than largest so far
        largest = right;

    if (largest != root) // If largest is not root
    {
        arr_access += 2;
		arr_changed += 2;
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
        arr_access += 2;
		arr_changed += 2;
        swap(arr[0], arr[end]); // Move current root to end
        heapify(arr, end, 0); // call max heapify on the reduced heap
    }
}
//---------------------------------------------------------------------------

void mergeOneTable(int *arr, int l, int  s, int p){
   int *pom = new int[p-l + 1]; // pomocnicza tablica do ³¹czenia
   int i = l; // indeks pocz¹tku lewej tablicy
   int j = s + 1; // indeks pocz¹tku prawej tablicy
   int k = 0; // indeks pocz¹tku pomocniczej tablicy
   while(i <= s && j <= p)
   {
      ++if_count;
      arr_access += 2;
      if(arr[i] <= arr[j])
	  {
         pom[k++] = arr[i++];
		arr_access += 2;
		arr_changed += 1;
	  }
	  else
	  {
         pom[k++] = arr[j++];
		arr_access += 2;
		arr_changed += 1;
	  }
   }
   // reszta elementów lewej po³owy
   while(i <= s)
   {
      pom[k++] = arr[i++];
	  arr_access += 2;
	  arr_changed += 1;
   }
   // reszta elementów prawej po³owy
   while(j <= p)
   {
      pom[k++] = arr[j++];
	  arr_access += 2;
	  arr_changed += 1;
   }
   // skopiuj po³¹czon¹ pomocnicz¹ tablice do oryginalnej tabicy
   for(k = 0, i = l; i <= p; ++i, ++k)
   {
      arr[i] = pom[k];
	  arr_access += 2;
	  arr_changed += 1;
   }

   delete []pom;
}
//---------------------------------------------------------------------------

void mergeSortOneTable(int *arr, int l, int r)
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

void mergesortOneTable(int *arr, int n)
{
    mergeSortOneTable(arr, 0, n-1);
}
//---------------------------------------------------------------------------

void mergeHalfTable(int *arr, int left, int mid, int right){
	int n1 = mid - left + 1;
	int *temp_arr = new int [n1];

	int i = left; // indeks pocz¹tku lewej tablicy
	int j = mid + 1; // indeks pocz¹tku prawej tablicy
    int k = 0; // indeks pocz¹tku pomocniczej tablicy

	for(k = 0; k < n1; ++k, ++i){
		temp_arr[k] = arr[i];
        arr_access += 2;
		arr_changed += 1;		
	}

	k = 0;
    i = left;

	while(j <= right && k < n1){
        ++if_count;
		arr_access += 2;
		if(arr[j] < temp_arr[k]){
			arr[i++] = arr[j++];
            arr_access += 2;
			arr_changed += 1;
		}else{
			arr[i++] = temp_arr[k++];
            arr_access += 2;
			arr_changed += 1;
		}
	}
	while(k < n1){
		arr[i++] = temp_arr[k++];
        arr_access += 2;
		arr_changed += 1;
	}

	delete [] temp_arr;
}
//---------------------------------------------------------------------------

void mergeSortHalfTable(int *arr, int left, int right){
    if(left < right){
        int mid = (left + right) >> 1;
        mergeSortHalfTable(arr, left, mid);
        mergeSortHalfTable(arr, mid+1, right);
        mergeHalfTable(arr, left, mid, right);
    }
}
//---------------------------------------------------------------------------

void mergesortHalfTable(int *arr, int n)
{
    mergeSortHalfTable(arr, 0, n-1);
}
//---------------------------------------------------------------------------

int randPivot(int p, int q)
{
    int size = q - p + 1;
    return (p + rand() % size);
}
//---------------------------------------------------------------------------

int Partition(int *arr, int lo, int hi)
{
    //produce ramdom subscript
    int t = randPivot(lo, hi);
    swap(arr[t], arr[hi]);
	arr_access += 2;
	arr_changed += 2;

    int index = lo - 1;
    int key = arr[hi];
	arr_access += 1;
	
    for(int i = lo ; i < hi; i++)
    {
        ++if_count;
        if(arr[i] <= key)
        {
            swap(arr[++index], arr[i]);
            arr_access += 2;
			arr_changed += 2;
        }
    }
    swap(arr[++index], arr[hi]);
    arr_access += 2;
	arr_changed += 2;
    return index;
}
//---------------------------------------------------------------------------

void quickSort(int *arr, int lo, int hi)
{
    if(lo < hi)
    {
        int index = Partition(arr, lo, hi);
        quickSort(arr, lo, index-1);
        quickSort(arr, index+1, hi);
    }
}
//---------------------------------------------------------------------------

void quicksort(int *arr, int n)
{
    quickSort(arr, 0, n-1);
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
      deleteTable(tab); // Usuñ tablice
	  deleteTable(tab_MS1); // Usuñ tablice
	  deleteTable(tab_MSHalf); // Usuñ tablice
	  deleteTable(tab_HS); // Usuñ tablice
	  deleteTable(tab_QS); // Usuñ tablice
   }

   first_run = false; // Ustaw "flage". Tablica wygenerowana przynajmniej 1 raz
   if(option != 8) // Je¿eli nie wczytujemy z piku, to...
   {
      n = sbAmount->Position; // Ustaw wielkoœæ tablicy
      tab = new int [n]; // Stwórz tablice 
   }

  switch(option) // Utworzenie tablicy wed³ug wybranej opcji
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

   if(option != 8) // Je¿eli nie wczytujemy z piku, to...
   {
        copyTables();
		changeSign("Table generated", clNavy);
   }else
   {
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
void TfEducationalPage::randomTable()
{
   // TOCHANGE: zmieniæ jakoœ randomizacje, mo¿e daæ uzytkownikowi wybór?

    for(int i=0; i < n; i++)
    {
        tab[i] = rand() % 200000;
    }
}
//---------------------------------------------------------------------------

void TfEducationalPage::reversedTable()
{
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
  int random = rand() % 20000;

  for(int i=0; i < n; i++)
  {
      tab[i] = random;
  }
}
//---------------------------------------------------------------------------


void TfEducationalPage::arrowDownTable()
{
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
   std::string stringTab; // Utwo¿enie stringa do przechowania wartoœci z pliku
   if( OpenDialog->Execute() ) // Otworzenie dialogu, do wybrania pliku
   {
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
   n = size; // Ustaw obliczon¹ wielkoœæ tablicy pod zmienn¹ globaln¹
   tab = new int [n]; // Stwórz tablice

    while(!stringTab.empty()) // Jeœli string nie jest pusty, to...
    {
      pos = stringTab.find(";"); // ZnajdŸ miejsce ";"
      tab[j] = StrToInt(stringTab.substr(0, pos).c_str()); // Skopiuj czêœæ stringa, a potem zamieñ na int i wrzuæ do tablicy
      stringTab.erase(0, pos + 1); // Usuñ wyko¿ystan¹ ju¿ czêœæ stringa, wraz z ";"
      j++; // Zwiêksz id tablicy o 1
    }
}
//---------------------------------------------------------------------------

void TfEducationalPage::deleteTable(int *arr){
  delete [] arr;
}
//---------------------------------------------------------------------------

void TfEducationalPage::clearResults(TLabel *algName, TLabel *comp, TLabel *access, TLabel *changed, TLabel *time)
{
    algName->Color = clBtnFace;
    comp->Caption = 0;
    access->Caption = 0;
    changed->Caption = 0;
	time->Caption = 0;
}
//---------------------------------------------------------------------------

void TfEducationalPage::copyTable(const int *original, int *&tempTable)
{
	tempTable = new int[n];
	for(int i=0; i < n; i++)
	{
		tempTable[i] = original[i];
	}
}
//---------------------------------------------------------------------------

void TfEducationalPage::copyTables(){
    copyTable(tab, tab_MS1);
    copyTable(tab, tab_MSHalf);
	copyTable(tab, tab_HS);
    copyTable(tab, tab_QS);
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

String TfEducationalPage::getTable(int *arr)
{
   AnsiString table = "";
   for(int i=0; i < n; i++)
   {
      table += IntToStr(arr[i]) + ";";
   }
   return table;
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

void TfEducationalPage::sumResults(float time)
{
   float div = StrToFloat(eRepeat->Text);
   comparision_sum += if_count / div;
   access_sum += arr_access / div;
   changed_sum += arr_changed / div;
   time_sum += time / div;
   if_count = 0;
   arr_access = 0;
   arr_changed = 0;
}
//---------------------------------------------------------------------------

void TfEducationalPage::sort(void (*algorithm)(int*, int), int* array, int length,
                    int repeat, TLabel* lName, TLabel* lComp, TLabel* lAccess, TLabel *lChanged, TLabel* lTime){
    for(int index = 0; index < repeat; ++index)
    {
        clock_t begin_time = clock();
        algorithm(array, length);
        float time = float(clock() - begin_time ) / CLOCKS_PER_SEC;
        sumResults(time);
    }
    showResults(array, lName, lComp, lAccess, lChanged, lTime);
}
//---------------------------------------------------------------------------

void TfEducationalPage::AlgorithmStart()
{
   int repeat = StrToInt(eRepeat->Text);

   sort(&mergesortOneTable, tab_MS1, n, repeat, lMS1, lCompMS1, lArrAccessMS1, lArrChangedMS1, lSortTimeMS1);
   sort(&mergesortHalfTable, tab_MSHalf, n, repeat, lMSHalf, lCompMSHalf, lArrAccessMSHalf, lArrChangedMSHalf, lSortTimeMSHalf);
   sort(&heapSort, tab_HS, n, repeat, lHS, lCompHS, lArrAccessHS, lArrChangedHS, lSortTimeHS);
   sort(&quicksort, tab_QS, n, repeat, lQS, lCompQS, lArrAccessQS, lArrChangedQS, lSortTimeQS);

   end();
}
//---------------------------------------------------------------------------

int __fastcall AlgorithmThread(Pointer Parameter)
{
   fEducationalPage->AlgorithmStart();
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

void TfEducationalPage::showResults(int *table, TLabel *algName, TLabel *comparisions, TLabel *access, TLabel *changed, TLabel *time)
{
   comparisions->Caption = round(comparision_sum);
   access->Caption = round(access_sum);
   changed->Caption = round(changed_sum);
   time->Caption = round(time_sum);
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
void __fastcall TfEducationalPage::bLoadFileClick(TObject *Sender)
{
   fromFile();
}
//---------------------------------------------------------------------------

void TfEducationalPage::saveToFile(AnsiString str)
{
   if(SaveDialog->Execute()) // Otwórz SaveDialog
   {
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

}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::bSaveUnsortedClick(TObject *Sender)
{
	lSign2->Visible = true;
	Repaint();
	
	SaveDialog->FileName = "Unsorted table";
	saveToFile(getTable(tab));
	
	lSign2->Visible = false;
	Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::bSaveSortedClick(TObject *Sender)
{
	lSign2->Visible = true;
	Repaint();
	
	SaveDialog->FileName = "Sorted table";
	saveToFile(getTable(tab_MS1));
	
	lSign2->Visible = false;
	Repaint();
}	
//---------------------------------------------------------------------------

void TfEducationalPage::checkAmount()
{
   int value;
    if( !TryStrToInt(eAmount->Text, value) ||
         value > sbAmount->Max ||
         value < sbAmount->Min )
    {
        ShowMessage("Invalid integer value entered, \ntry again between "
                     + IntToStr(sbAmount->Min) + " - " + IntToStr(sbAmount->Max));
        eAmount->SetFocus();
    }

    sbAmount->Position = value;
    Repaint();
}
//---------------------------------------------------------------------------

void TfEducationalPage::checkRepeat()
{
   int value;
    if( !TryStrToInt(eRepeat->Text, value) ||
         ( StrToInt(eRepeat->Text)) < 1 )
    {
        ShowMessage("Invalid integer value entered, try again.");
        eRepeat->SetFocus();

    }
}
//---------------------------------------------------------------------------

void __fastcall TfEducationalPage::bSaveResultsClick(TObject *Sender)
{
   AnsiString results = lAlgoritmName->Caption + "\t\t" +  lComparisons->Caption + "\t\t" + lArrAccess->Caption + "\t\t" + lArrChanged->Caption + "\t\t\t\t" + lSortTime->Caption + "\n" +
                        lMS1->Caption + "\t" + lCompMS1->Caption + "\t\t\t\t" + lArrAccessMS1->Caption + "\t\t\t\t" + lArrChangedMS1->Caption + "\t\t\t\t" + lSortTimeMS1->Caption + "\n" +
                        lMSHalf->Caption + "\t" + lCompMSHalf->Caption + "\t\t\t\t" + lArrAccessMSHalf->Caption + "\t\t\t\t" + lArrChangedMSHalf->Caption + "\t\t\t\t" + lSortTimeMSHalf->Caption + "\n" +
						lHS->Caption + "\t\t\t" + lCompHS->Caption + "\t\t\t\t" + lArrAccessHS->Caption + "\t\t\t\t" + lArrChangedHS->Caption + "\t\t\t\t" + lSortTimeHS->Caption + "\n" +
                        lQS->Caption + "\t\t\t" + lCompQS->Caption + "\t\t\t\t" + lArrAccessQS->Caption + "\t\t\t\t" + lArrChangedQS->Caption + "\t\t\t\t" + lSortTimeQS->Caption + "\n";

   SaveDialog->FileName = "Results";
   saveToFile(results);
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
   rgTableTypes->Top = 97;
   fEducationalPage->Left = 840; // przesuniêcie formatki na œrodek ekranu
   fEducationalPage->ClientWidth = 230;  // Zmniejszenie wielkoœci formatki
}



