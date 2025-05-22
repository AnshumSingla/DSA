#include <iostream>
using namespace std;

class CircularQueue
{
public:
  int size;
  int front;
  int rear;
  int *arr;

  CircularQueue(int size)
  {
    arr = new int[size];
    front = -1;
    rear = -1;
  }

  bool enqueue(int value)
  {
    if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
    {
      cout << "Queue is full" << endl;
      return false;
    }
    else if (front == -1)
      rear = front = 0;

    else if (rear == size - 1 && front != 0)
    {
      rear = 0;
      arr[rear] = value;
    }
    else
    {
      rear++;
      arr[rear] = value;
    }
    arr[rear] = value;
    return true;
  }

  int dequeue()
  {
    if (front == -1)
    {
      cout << "queue is empty" << endl;
      return -1;
    }
    int ans = arr[front];
    arr[front] = -1;
    if (front == rear)
      front = rear = -1;

    else if (front == size - 1)
      front = 0;
    else
      front++;
    return ans;
  }

  bool isEmpty()
  {
    return ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)));
  }
};