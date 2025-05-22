#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }

  ~Node()
  {
    int value = this->data;
    if (this->next != NULL)
    {
      delete next;
      this->next = NULL;
    }
    cout << "The memory is free for node with data " << value << endl;
  }
};

void insertAtTail(int after, int insert, Node *&tail)
{
  Node *insertion = new Node(insert);
  Node *temp = tail;
  // Empty list
  if (tail == NULL)
  {
    tail = insertion;
    insertion->next = insertion;
    return;
  }
  // Non-Empty list
  else
  {
    while (temp->data != after)
    {
      temp = temp->next;
    }
    insertion->next = temp->next;
    temp->next = insertion;
  }
}

void deletion(Node *&tail, int d)
{
  Node *temp = tail;
  Node *prev = NULL;
  while (temp->data != d)
  {
    prev = temp;
    temp = temp->next;
  }
  prev->next = temp->next;
  temp->next = NULL;
  delete temp;
}

void print(Node *&tail)
{
  Node *temp = tail;
  // Rather than adding an if block we can update the while's condition
  do
  {
    cout << temp->data << " ";
    temp = temp->next;
  } while (temp != tail);
  cout << endl;
}

bool testLL(Node *&tail)
{
  Node *temp = tail;
  do
  {
    temp = temp->next;
  } while (temp != tail);
  return temp == tail;
}

int main()
{
  Node *node1 = NULL;
  Node *tail = node1;

  insertAtTail(0, 3, tail);
  print(tail);
  // cout << tail->data << endl;

  insertAtTail(3, 5, tail);
  print(tail);
  cout << "data: " << tail->data << endl;

  insertAtTail(5, 7, tail);
  print(tail);
  cout << "data: " << tail->data << endl;

  deletion(tail, 5);
  print(tail);
  cout << "data: " << tail->data << endl;

  cout << testLL(tail) << endl;
  return 0;
}