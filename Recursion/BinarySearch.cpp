#include <iostream>
using namespace std;

int binarySearch(int s, int e, int arr[], int key)
{
  if (s > e)
    return -1; // key not found
  int mid = s + (e - s) / 2;

  if (arr[mid] == key)
    return mid; // key found at mid
  else if (arr[mid] > key)
    return binarySearch(s, mid - 1, arr, key); // search in the left half
  else
    return binarySearch(mid + 1, e, arr, key); // search in the right half
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int size = sizeof(arr) / sizeof(arr[0]);
  int key = 1;

  int result = binarySearch(0, size - 1, arr, key);

  if (result != -1)
    cout << "Element found at index: " << result << endl;
  else
    cout << "Element not found" << endl;

  return 0;
}
