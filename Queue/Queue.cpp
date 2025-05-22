#include <iostream>
using namespace std;

class Queue
{
public:
  int size;
  int front;
  int rear;
  int *arr;
  Queue()
  {
    size = 100001;
    arr = new int[size];
    front = 0;
    rear = 0;
  }
  void push(int data)
  {
    if (size - rear > 1)
    {
      rear++;
      arr[rear] = data;
    }
  }
  void pop()
  {
    if (front <= rear)
      front++;
  }
  int sizeQ()
  {
    return rear - front;
  }
  bool isEmpty()
  {
    return (rear - front) == 0;
  }
};

int main()
{
  Queue q1;
  cout << q1.isEmpty() << endl;
  q1.push(5);
  q1.push(7);
  cout << q1.isEmpty() << endl;
  cout << q1.sizeQ() << endl;
  return 0;
}