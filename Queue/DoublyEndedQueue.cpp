#include <iostream>
using namespace std;

class queue
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

  bool push_back(int val)
  {
    if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
    {
      cout << "Queue is full" << endl;
      return false;
    }
    else if (front == -1)
      front = rear = 0;
    else if (rear == size - 1 && front != 0)
      rear = 0;
    else
      rear++;

    arr[rear] = val;
    return true;
  }

  bool push_front(int val)
  {
    if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
    {
      cout << "Queue is full" << endl;
      return false;
    }
    else if (front == -1)
      front = rear = 0;
    else if (front == 0)
      front = size - 1; // Front nu push krake left leke jane naki right
    else
      front--;
    arr[front] = val;
    return true;
  }

  int pop_front()
  {
    if (front == -1)
    {
      cout << "Queue is empty" << endl;
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

  int pop_back()
  {
    if (front == -1)
    {
      cout << "Queue is empty" << endl;
      return -1;
    }
    int ans = arr[rear];
    arr[rear] = -1;
    if (front == rear)
      front = rear = -1;
    else if (rear == 0)
      rear = size - 1;
    else
      rear--;
    return ans;
  }
};