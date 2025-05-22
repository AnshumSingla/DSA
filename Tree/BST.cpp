#include <iostream>
#include <queue>
using namespace std;

// Inorder LNR
// Postorder LRN
// Preorder NLR

class Tree
{
public:
  int data;
  Tree *right;
  Tree *left;
  Tree(int data)
  {
    this->data = data;
    this->left = this->right = NULL;
  }
};

void levelOrderTraversal(Tree *root)
{
  queue<Tree *> q;
  q.push(root);
  q.push(NULL);
  while (!q.empty())
  {
    Tree *root = q.front();
    q.pop();
    if (root == NULL)
    { // level completion check krde
      cout << endl;
      if (!q.empty())
        q.push(NULL);
    }
    else
    {
      cout << root->data << " ";
      if (root->left)
        q.push(root->left);
      if (root->right)
        q.push(root->right);
    }
  }
}

Tree *BST(Tree *root, int data)
{
  if (root == NULL)
    return new Tree(data);

  if (data != -1 && data < root->data)
    root->left = BST(root->left, data);

  else if (data != -1 && data > root->data)
    root->right = BST(root->right, data);

  return root;
}

Tree *takeInput(Tree *root)
{
  int data;
  while (true)
  {
    cout << "Enter next element (-1 to stop): ";
    cin >> data;
    if (data == -1)
      break;
    root = BST(root, data);
  }
  return root;
}

bool isPresent(Tree *temp, int data)
{
  if (temp == NULL)
    return false;

  if (temp->data == data)
  {
    cout << "It is present" << endl;
    return true;
  }

  if (temp->data > data)
    return isPresent(temp->left, data);

  if (temp->data < data)
    return isPresent(temp->right, data);
  return false;
}

int minVal(Tree *root)
{
  while (root->left)
    root = root->left;

  return root->data;
}

Tree *deleteElement(Tree *root, int data)
{
  if (root == NULL)
    return root;

  if (root->data == data)
  {
    // 0 child
    if (!root->left && !root->right)
    {
      delete root;
      return root;
    }

    // 1 child

    // Left
    if (root->left && !root->right)
    {
      Tree *temp = root->left;
      delete root;
      return temp;
    }

    // Right
    if (root->right && !root->left)
    {
      Tree *temp = root->right;
      delete root;
      return temp;
    }

    // 2 child
    if (root->left && root->right)
    {
      int mini = minVal(root->right);
      root->data = mini;
      root->right = deleteElement(root->right, mini);
      return root;
    }
  }

  else if (root->data > data)
  {
    root->left = deleteElement(root->left, data);
    return root;
  }
  else
  {
    root->right = deleteElement(root->right, data);
    return root;
  }
}

int main()
{
  int data;
  cout << "Enter root value (-1 to stop): ";
  cin >> data;
  Tree *bst = NULL;
  bst = BST(bst, data);
  takeInput(bst);
  cout << endl;
  cout << "Enter data to find in tree" << endl;
  cin >> data;
  isPresent(bst, data);
  levelOrderTraversal(bst);
  cout << "Enter the data to delete" << endl;
  cin >> data;
  deleteElement(bst, data);
  levelOrderTraversal(bst);
}