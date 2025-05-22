#include <iostream>
using namespace std;

void insertionSort(int arr[], int size)
{
  for (int i = 1; i < size; i++)
  {
    int temp = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > temp)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }
}

int main()
{
  int arr[] = {5, 9, 3, 7, 2, 55, 4, 5, 7, 9, 16, 54};
  insertionSort(arr, 12);
  for (int i = 0; i < 12; i++)
    cout << arr[i] << " ";
  return 0;
}