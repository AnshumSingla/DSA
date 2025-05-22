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

int FindPosition(int element, int in[], int size)
{
  for (int i = 0; i < size; i++)
    if (in[i] == element)
      return i;
  return -1;
}

Tree *Solve(int in[], int pre[], int &preOrderIndex, int inOrderStart, int inOrderEnd, int n)
{

  // Base case
  if (preOrderIndex >= n || inOrderStart > inOrderEnd)
    return NULL;

  int element = pre[preOrderIndex++];
  Tree *temp = new Tree(element);
  int position = FindPosition(element, in, n);
  temp->left = Solve(in, pre, preOrderIndex, inOrderStart, position - 1, n);
  temp->right = Solve(in, pre, preOrderIndex, position + 1, inOrderEnd, n);
  return temp;
}

Tree *Solve2(int in[], int post[], int &postOrderIndex, int inOrderStart, int inOrderEnd, int n)
{
  // Base case
  if (postOrderIndex < 0 || inOrderStart > inOrderEnd)
    return NULL;
  int element = post[postOrderIndex--];
  Tree *temp = new Tree(element);
  int position = FindPosition(element, in, n);
  temp->right = Solve2(in, post, postOrderIndex, position + 1, inOrderEnd, n);
  temp->left = Solve2(in, post, postOrderIndex, inOrderStart, position - 1, n);
  return temp;
}

Tree *PreToBinary(int in[], int pre[], int n)
{
  int preOrderIndex = 0;
  Tree *ans = Solve(in, pre, preOrderIndex, 0, n - 1, n); // 0 and n-1 are starting and ending index of inOrder
  return ans;
}

Tree *PostToBinary(int post[], int in[], int n)
{
  int postOrderIndex = n - 1;
  Tree *ans = Solve2(in, post, postOrderIndex, 0, n - 1, n);
}

void levelOrderTraversal(Tree *root)
{
  queue<Tree *> q;
  q.push(root);
  q.push(NULL);
  while (!q.empty())
  {
    Tree *temp = q.front();
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

int main()
{
  int n = 6;
  int in[n] = {3, 1, 4, 0, 5, 2}, pre[n] = {0, 1, 3, 4, 2, 5}, post[n] = {3, 4, 1, 5, 2, 0};
  Tree *h = PreToBinary(in, pre, n);
  levelOrderTraversal(h);
  cout << endl;
  h = PostToBinary(post, in, n);
  levelOrderTraversal(h);
}