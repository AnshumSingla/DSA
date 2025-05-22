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
};

void insertAtHead(Node *&head, int d)
{
  Node *temp = new Node(d);
  temp->next = head;
  head = temp;
}

void insertAtTail(Node *&tail, int d)
{
  Node *temp = new Node(d);
  tail->next = temp;
  tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int pos, int d)
{

  Node *temp = head;
  Node *insert = new Node(d);
  int cnt = 1;

  if (pos == 1)
  {
    insertAtHead(head, d);
    return;
  }

  while (cnt < pos - 1)
  {
    temp = temp->next;
    cnt++;
  }

  if (temp->next == NULL)
  {
    insertAtTail(tail, d);
    return;
  }

  insert->next = temp->next;
  temp->next = insert;
}

void print(Node *&head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

void deletion(Node *&head, Node *&tail, int pos)
{
  if (pos == 1)
  {
    Node *temp = head;
    head = head->next;
    temp = NULL;
    delete temp;
    return;
  }
  else
  {
    Node *curr = head;
    Node *prev = NULL;
    int cnt = 1;
    while (cnt < pos)
    {
      prev = curr;
      curr = curr->next;
      cnt++;
    }
    // Update the tail
    if (curr->next == NULL)
      tail = prev;
    prev->next = curr->next;
    curr = NULL;
    delete curr;
  }
}

void reverse(Node *&head)
{
  Node *curr = head;
  Node *prev = NULL;
  while (head->next != NULL)
  {
    curr = head;
    head = head->next;
    curr->next = prev;
    prev = curr;
  }
  head->next = prev;
}

void recursionReverse(Node *&head, Node *prev)
{
  Node *curr = head;
  if (head->next == NULL)
  {
    head->next = prev;
    return;
  }
  else
  {
    curr = head;
    head = head->next;
    curr->next = prev;
    prev = curr;
  }
  recursionReverse(head, prev);
}

int mid(Node *&head, Node *&tail)
{
  Node *x2 = head;
  Node *x = head;
  while (x2->next != NULL)
  {
    if (x2->next->next == NULL)
      return x->next->data;
    x2 = x2->next->next;
    x = x->next;
  }
  return x->data;
}

void sort(Node *&head, Node *&tail)
{
  Node *temp = head;
  Node *tempKaNext = temp->next;
  while (temp != NULL)
  {
    Node *min = temp;
    while (tempKaNext != NULL)
    {
      if (min->data > tempKaNext->data)
        min = tempKaNext;
      tempKaNext = tempKaNext->next;
    }

    if (min != temp)
      swap(min->data, temp->data);
    temp = temp->next;
  }
}

int main()
{
  Node *node1 = new Node(10);
  Node *head = node1;
  Node *tail = node1;
  print(head);
  insertAtHead(head, 5);
  print(head);
  insertAtTail(tail, 11);
  print(head);
  insertAtPosition(head, tail, 3, 2);
  print(head);
  deletion(head, tail, 4);
  print(head);
  cout << "head " << head->data << " tail " << tail->data << endl;
  reverse(head);
  print(head);
  recursionReverse(head, NULL);
  print(head);
  insertAtHead(head, 12);
  print(head);
  cout << mid(head, tail) << endl;
  // recursionReverseKOrder(head, tail, head, NULL, 2);
  sort(head, tail);
  print(head);
  return 0;
}