#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int arr[], int x, int n)
{
  int l = 0, r = n - 1;
  int mid = l + (r - l) / 2;
  while (mid <= r && mid >= l && r >= l)
  {
    if (arr[mid] == x)
      return mid;
    else if (arr[mid] > x)
    {
      r = mid - 1;
    }
    else if (arr[mid] < x)
    {
      l = mid + 1;
    }
    mid = l + (r - l) / 2;
  }
  return -1;
}

void merge(vector<int> &arr, int l, int mid, int r)
{
  int n1 = mid - l + 1, n2 = r - mid;
  vector<int> left(n1), right(n2);

  for (int i = 0; i < n1; i++)
    left[i] = arr[l + i];

  for (int i = 0; i < n2; i++)
    right[i] = arr[i + mid + 1];

  int i = 0, j = 0, k = l;

  while (i < n1 && j < n2)
  {
    if (left[i] <= right[j])
    {
      arr[k] = left[i];
      i++;
    }
    else
    {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = left[i];
    k++;
    i++;
  }
  while (j < n2)
  {
    arr[k] = right[j];
    k++;
    j++;
  }
}

void mergeSort(vector<int> &arr, int l, int r)
{
  if (l >= r)
    return;

  int mid = l + (r - l) / 2;

  mergeSort(arr, l, mid);
  mergeSort(arr, mid + 1, r);
  merge(arr, l, mid, r);
}

int maxSum(vector<int> arr)
{
  int maxSoFar = arr[0];
  int currSum = arr[0];

  for (int i = 0; i < arr.size(); i++)
  {
    currSum = max(arr[i], currSum + arr[i]);
    maxSoFar = max(currSum, maxSoFar);
  }

  return maxSoFar;
}

int main()
{
  int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
  cout << binarySearch(arr, 2, 10) << endl;

  vector<int> arr1 = {12, 11, 13, 5, 6, 7};
  mergeSort(arr1, 0, arr1.size() - 1);

  for (int i = 0; i < arr1.size(); i++)
  {
    cout << arr1[i] << ',';
  }
  cout << endl;
  vector<int> arr2 = {-2, -5, 6, -2, -3, 1, 5, -6};

  cout << maxSum(arr2) << endl;

  return 0;
}