#include <iostream>
using namespace std;

class stack
{
public:
  int top;
  int size;
  int *arr;
  stack(int size)
  {
    this->size = size;
    arr = new int[size];
    top = -1;
  }

  void push(int data)
  {
    if (size - top > 1)
    {
      top++;
      arr[top] = data;
    }
  }
  void pop()
  {
    if (top > -1)
      top--;
  }
  void peek()
  {
    if (top > -1 && top < size)
      cout << arr[top] << endl;
  }
  bool isEmpty()
  {
    return top == -1;
  }
};

int main()
{
  stack s1(3);
  s1.push(5);
  s1.push(6);
  s1.peek();
  s1.pop();
  s1.peek();
  return 0;
}