#include <iostream>
using namespace std;

class SparseMatrix
{
public:
  int row;
  int col;
  int value;

  SparseMatrix(int r = 0, int c = 0, int v = 0) : row(r), col(c), value(v) {}
};

SparseMatrix *addSparseMatrix(SparseMatrix A[], SparseMatrix B[])
{
  if (A[0].row != B[0].row || A[0].col != B[0].col)
  {
    cout << "Matrices have different dimensions, cannot add them." << endl;
    return nullptr;
  }

  int maxSize = A[0].value + B[0].value + 1;
  SparseMatrix *result = new SparseMatrix[maxSize];
  int i = 1, j = 1, k = 1;

  result[0].row = A[0].row;
  result[0].col = A[0].col;
  result[0].value = 0;

  while (i <= A[0].value && j <= B[0].value)
  {
    if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col))
    {
      result[k++] = A[i++];
    }
    else if (B[j].row < A[i].row || (B[j].row == A[i].row && B[j].col < A[i].col))
    {
      result[k++] = B[j++];
    }
    else
    {
      result[k].row = A[i].row;
      result[k].col = A[i].col;
      result[k].value = A[i].value + B[j].value;
      if (result[k].value != 0)
      {
        k++;
      }
      i++;
      j++;
    }
  }

  while (i <= A[0].value)
  {
    result[k++] = A[i++];
  }

  while (j <= B[0].value)
  {
    result[k++] = B[j++];
  }

  result[0].value = k - 1;
  return result;
}

void displaySparseMatrix(SparseMatrix matrix[])
{
  cout << "Row\tCol\tValue\n";
  for (int i = 0; i <= matrix[0].value; i++)
  {
    cout << matrix[i].row << "\t" << matrix[i].col << "\t" << matrix[i].value << endl;
  }
}

int main()
{
  SparseMatrix a[] = {
      SparseMatrix(4, 4, 5),
      SparseMatrix(0, 1, 10),
      SparseMatrix(0, 3, 12),
      SparseMatrix(2, 2, 5),
      SparseMatrix(3, 0, 15),
      SparseMatrix(3, 1, 12)};

  SparseMatrix b[] = {
      SparseMatrix(4, 4, 5),
      SparseMatrix(0, 3, 20),
      SparseMatrix(1, 3, 25),
      SparseMatrix(2, 0, 8),
      SparseMatrix(2, 2, 9),
      SparseMatrix(3, 1, 23)};

  SparseMatrix *result = addSparseMatrix(a, b);

  if (result != nullptr)
  {
    cout << "Resultant Sparse Matrix:" << endl;
    displaySparseMatrix(result);
    delete[] result;
  }

  return 0;
}
