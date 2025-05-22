#include <iostream>
#include <queue>
using namespace std;

class heap
{
  int arr[100];
  int size;

public:
  heap()
  {
    arr[0] = -1;
    size = 0;
  }
  void insert(int data)
  {
    size++;
    int index = size;
    arr[index] = data;
    while (index > 1)
    {
      int parent = index / 2;
      if (arr[parent] < arr[index])
      {
        swap(arr[parent], arr[index]);
        index = parent;
      }
      else
        return;
    }
  }

  void print()
  {
    for (int i = 1; i <= size; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  void deleteRoot()
  {
    if (size == 0)
    {
      cout << "Heap is empty" << endl;
      return;
    }
    int index = size;
    arr[1] = arr[index];
    size--;
    index = 1;
    while (index < size)
    {
      int leftIndex = index * 2;
      int rightIndex = index * 2 + 1;

      if (leftIndex < size && arr[index] < arr[leftIndex])
      {
        swap(arr[index], arr[leftIndex]);
        index = leftIndex;
      }

      else if (rightIndex < size && arr[index] < arr[rightIndex])
      {
        swap(arr[index], arr[leftIndex]);
        index = rightIndex;
      }
      else
        return;
    }
  }
};

void heapify(int arr[], int n, int i)
{
  int largest = i;
  int right = 2 * i + 1;
  int left = 2 * i;

  if (right <= n && arr[right] > arr[largest])
    largest = right;

  if (left <= n && arr[left] > arr[largest])
    largest = left;

  if (largest != i)
  {
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n)
{
  while (n > 1)
  {
    swap(arr[1], arr[n]);
    n--;
    heapify(arr, n, 1);
  }
}

int main()
{
  heap h;
  h.insert(50);
  h.insert(55);
  h.insert(53);
  h.insert(52);
  h.insert(54);
  h.deleteRoot();
  h.print();
  int arr[10] = {-1, 5, 3, 17, 10, 84, 19, 6, 22, 9};
  int n = 9;
  for (int i = n / 2; i > 0; i--)
    heapify(arr, n, i);

  for (int i = 1; i <= n; i++)
    cout << arr[i] << " ";
  cout << endl;

  cout << "Sorted heap" << endl;

  heapSort(arr, n);

  for (int i = 1; i <= n; i++)
    cout << arr[i] << " ";
  cout << endl;

  // max heap using pq
  priority_queue<int> pq;
  // pq ch sab kuch apne aap set hojega for max heap since it is the property of the pq

  // min heap using pq
  priority_queue<int, vector<int>, greater<int>> minHeap;
  // data type, container, comparison defaults for these params are vector and less which are used in max heap after this pq will manage
  // everything
}
