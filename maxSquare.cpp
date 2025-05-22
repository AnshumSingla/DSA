#include <iostream>
#include <vector>
using namespace std;

int maxSquare(vector<vector<int>> &mat)
{
  int n = mat.size();
  int m = mat[0].size();
  vector<vector<int>> dp(n, vector<int>(m, 0));
  int maxSide = 0;

  // Copy first row and column as base
  for (int i = 0; i < n; ++i)
  {
    dp[i][0] = mat[i][0];
    maxSide = max(maxSide, dp[i][0]);
  }
  for (int j = 0; j < m; ++j)
  {
    dp[0][j] = mat[0][j];
    maxSide = max(maxSide, dp[0][j]);
  }

  // Fill rest of the dp table
  for (int i = 1; i < n; ++i)
  {
    for (int j = 1; j < m; ++j)
    {
      if (mat[i][j] == 1)
      {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
        maxSide = max(maxSide, dp[i][j]);
      }
    }
  }

  return maxSide;
}

int main()
{
  vector<vector<int>> mat = {
      {0, 1, 1, 0, 1},
      {1, 1, 0, 1, 0},
      {0, 1, 1, 1, 0},
      {1, 1, 1, 1, 0},
      {1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0}};

  int result = maxSquare(mat);
  cout << "Maximum size of square sub-matrix with all 1s: " << result << endl;

  return 0;
}
