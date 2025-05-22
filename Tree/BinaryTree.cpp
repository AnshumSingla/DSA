#include <iostream>
#include <queue>
using namespace std;

// INORDER PREORDER POSTORDER
// LNR     NLR      LRN

class tree
{
public:
  int data;
  tree *left;
  tree *right;
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
  return root;
}

void levelOrderTraversal(tree *root)
{
  queue<tree *> q;
  q.push(root);
  q.push(NULL);
  while (!q.empty())
  {
    tree *temp = q.front();
    q.pop();
    if (temp == NULL)
    { // level completion check krde
      cout << endl;
      if (!q.empty())
        q.push(NULL);
    }
    else
    {
      cout << temp->data << " ";
      if (temp->left)
        q.push(temp->left);
      if (temp->right)
        q.push(temp->right);
    }
  }
}

void inOrder(tree *root)
{
  if (root == NULL)
    return;
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

void preOrder(tree *root)
{
  if (root == NULL)
    return;
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

void postOrder(tree *root)
{
  if (root == NULL)
    return;
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
int main()
{
  tree *root = NULL;
  root = buildTree(root);
  levelOrderTraversal(root);
  inOrder(root);
  cout << endl;
  preOrder(root);
  cout << endl;
  postOrder(root);
  delete root;
  return 0;
}