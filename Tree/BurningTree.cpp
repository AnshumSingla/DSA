#include <iostream>
using namespace std;

class tree
{
public:
  int data;
  tree *right;
  tree *left;
  tree(int data)
  {
    this->data = data;
    this->left = this->right = NULL;
  }
};

tree *buildTree(tree *root)
{
  cout << "Enter the data: " << endl;
  int data;
  cin >> data;
  root = new tree(data);
  if (data == -1)
    return NULL;
  cout << "Enter the data on the left of " << data << endl;
  root->left = buildTree(root->left);
  cout << "Enter the data on the right of " << data << endl;
  root->right = buildTree(root->right);
}

int burnTree(int val, tree *root)
{
  tree *temp = root;
  while (val != temp->data)
  {
  }
}

int main()
{
  tree *root = NULL;
  root = buildTree(root);
  return 0;
}