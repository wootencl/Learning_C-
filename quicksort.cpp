#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

void quicksort(vector<int>& items, int left, int right);
void printArray(vector<int> array);
int partition(vector<int>& items, int left, int right);

int main(int argc, char* argv[])
{
  srand( time(NULL) );
  int numberOfItems = atoi(argv[1]);
  vector<int> items;
  for (int i = 0; i<numberOfItems ;i++)
  {
    items.push_back(rand()%100);
  }
  printArray(items);

  quicksort(items, 0, items.size());

  printArray(items);
  return 0;
}

void quicksort(vector<int>& items, int left, int right)
{
  int index;
  if(items.size()>1)
  {
    index = partition(items, left, right);
    if (left < index-1)
    {
      quicksort(items, left, index-1);
    }
    if (right > index)
    {
      quicksort(items, index, right);
    }
  }
}

int partition(vector<int>& items, int left, int right)
{
  int i = left, j = right, pivot = items[left];
  while (i <= j)
  {
    while (items[i] < pivot) { i++; }
    while (items[j] > pivot) { j--; }
    if (i <= j)
    {
      swap(items[j], items[i]);
      i++;
      j--;
    }
  }
  return i;
}

void printArray(vector<int> array)
{
  int j;
  cout << "[";
  for (j=0 ; j<array.size()-1 ; j++)
  {
    cout << array[j] << ", ";
  }
  cout << array[j] << "]" << endl;
}
