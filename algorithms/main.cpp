#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// taken from google doc
void
insertionSort (int arr[], int n)
{
  int i, key;
  for (i = 1; i < n; i++)
    {
      key = arr[i];
      int j = i - 1;
      for (; j >= 0 && arr[j] > key; j--)
	arr[j + 1] = arr[j];

      arr[j + 1] = key;
    }
}

// end insertion sort

void
Swap (int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}
void
merge (int A[], int low, int high, int mid)
{
     // We have low to mid and mid+1 to high already sorted.
	int i, j, k, 
temp[high-low+1]; // temporary array to hold the output
 
	// Merge most of the two halves into temp[]. One half will have some leftover.
	for ( i = low, k = 0, j = mid + 1; i <= mid && j <= high; k++)
	    temp[k] = A[i] < A[j] ? A[i++] : A[j++];

// Assert: i==mid xor j==high, so one and only one of these 2 loops will actually run.
	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
		temp[k++] = A[i++];
	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
		temp[k++] = A[j++];

	// Assign sorted data stored in temp[] to A[].
	for (i = low; i <= high; i++)
		A[i] = temp[i-low];

}

// Your plain vanilla mergeSort, not jazzed up, to sort [part of] an array, A[low..high]
void
JazzSort (int A[], int low, int high)
{

  if (high < 30)
    {				// if array size < 30, need to call insertion sort because it is faster
      insertionSort (A, high + 1);
      return;
    }
  if (high <= low)
    return;

  int mid = (low + high) / 2;	// integer division

  // mergeSort each half.
  JazzSort (A, low, mid);
  JazzSort (A, mid + 1, high);

  // Merge them to get sorted output.
  merge (A, low, high, mid);
}


int
Partition (int arr[], int start, int end)
{
  int index = start;
  int pivot = arr[end - 1];
  for (int i = start; i < end - 1; i++)
    if (arr[i] <= pivot)
      Swap (arr[index++], arr[i]);

  Swap (arr[index], arr[end - 1]);

  return index;
}

// introspective quicksort
void
QuickSort (int arr[], int start, int end, bool flag)
{				// static variables
  static int calls = 0;
  static int bot = 0;
  static int top = 0;
  if (end <= start)
    return;
  if (flag)
    {				// change value of the variables if its the first time running this function
      calls = 0;
      bot = start;
      top = end;
      flag = false;}
      
  int within = (end + 1) * .05;
  if (calls == 5)
    return;
  if (calls == 4)
    {
      cout << "danger! possible O(n^2) detected. switching to mergesort. " <<endl;
      JazzSort (arr, bot, top);
      calls++;
      return;
    }


  int index = Partition (arr, start, end);
  if (((index >= (end - within)) || (index <= (start + within)))
      && ((end - start) > 3))
    {
      ++calls;
    }
  QuickSort (arr, start, index, flag);
  QuickSort (arr, index + 1, end, flag);
}


int
main ()
{
  // initialize array sizes
  const int asize25 = 25;
  const int asize5 = 5;
  const int asize40 = 40;
  const int asize500 = 500;
  const int asize512 = 512;
  const int asize400 = 400;
  // end size initialization

  // create arrays given the numbers you gave us
  int A[asize500];
  int B[asize25];
  int C[asize5];
  int D[asize40];
  int E[asize512];
  int F[asize500];
  int G[asize400];
  // end array creation
  string line;			// line for getline loop

  fstream stuff ("not");	// open file

  int li = 0;			// line index
  // for insertionSort testing
  while (getline (stuff, line, ' ') && li != asize500)
    {				// array A initialized
      A[li] = stoi (line);
      li++;
    }
  li = 0;
  B[li] = stoi (line);		// value is lost when entering the next while loop, so we have to do this to prevent data loss
  li++;
  while (getline (stuff, line, ' ') && li != asize25)
    {				// array B initialized
      B[li] = stoi (line);
      li++;
    }
  li = 0;
  C[li] = stoi (line);
  li++;
  while (getline (stuff, line, ' ') && li != asize5)
    {				//array C
      C[li] = stoi (line);
      li++;
    }
  li = 0;
  D[li] = stoi (line);
  li++;
  while (getline (stuff, line, ' ') && li != asize40)
    {				// array D
      D[li] = stoi (line);
      li++;
    }
  li = 0;
  E[li] = stoi (line);
  li++;
  while (getline (stuff, line, ' ') && li != asize512)
    {				// array E
      E[li] = stoi (line);
      li++;
    }
  li = 0;
  F[li] = stoi (line);
  li++;
  while (getline (stuff, line, ' ') && li != asize500)
    {				// array F
      F[li] = stoi (line);
      li++;
    }
  li = 0;
  G[li] = stoi (line);
  li++;
  while (getline (stuff, line, ' ') && li != asize400)
    {				// array G
      G[li] = stoi (line);
      li++;
    }
  // end array initialization
  
  // calling sorting functions for each array
  QuickSort (A, 0, asize500-1, true);
  for (int i = 0; i < asize500; i++)
    {
      cout << A[i] << " ";
    }
  cout << "\n\n";

  QuickSort (B, 0, asize25-1, true);
  for (int i = 0; i < asize25; i++)
    {
      cout << B[i] << " ";
    }

  cout << "\n\n";
  QuickSort (G, 0, asize400-1, true);
  for (int i = 0; i < asize400; ++i)
    {
      cout << G[i] << " ";
    }
     cout << "\n\n";   
  QuickSort(C,0,asize5-1,true);
    for (int i = 0; i < asize5; ++i)
    {
      cout << C[i] << " ";
    }
    cout << "\n\n";
  insertionSort(D,39);
  for (int i = 0; i < asize40-1; ++i)
    {
      cout << D[i] << " ";
    }
    cout << "\n\n";
   QuickSort(E,0,asize512-1,true);
  for (int i = 0; i < asize512-1; ++i)
    {
      cout << E[i] << " ";
    }
    cout << "\n\n"; 
  JazzSort(F,0,asize500);
  for (int i = 0; i < asize500; ++i)
    {
      cout << F[i] << " ";
    }
  
  




  return 0;

}
