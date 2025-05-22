#include <iostream>
using namespace std;

void selectionSort(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    int min = i;
    for (int j = i + 1; j < size; j++)
    {
      if (arr[min] > arr[j])
        min = j;
    }
    swap(arr[min], arr[i]);
  }
}

int main()
{
  int arr[5] = {5, 9, 3, 7, 2};
  selectionSort(arr, 5);
  for (int i = 0; i < 5; i++)
  {
    cout << arr[i] << " ";
  }

  return 0;
}