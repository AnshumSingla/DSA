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

void transpose(SparseMatrix a[])
{
  for (int i = 1; i <= a[0].row + 1; i++)
    swap(a[i].row, a[i].col);

  for (int i = 1; i <= a[0].value; i++)
  {
    int min = i;
    for (int j = i + 1; j <= a[0].value; j++)
      // Sorting based on row first, and if rows are the same, then by column
      if (a[j].row < a[min].row || (a[j].row == a[min].row && a[j].col < a[min].col))
        min = j;
    if (min != i)
    {
      swap(a[min], a[i]);
    }
  }
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
      SparseMatrix(0, 3, 20),
      SparseMatrix(1, 3, 25),
      SparseMatrix(2, 0, 8),
      SparseMatrix(2, 2, 9),
      SparseMatrix(3, 1, 23)};
  transpose(a);
  displaySparseMatrix(a);
  return 0;
}