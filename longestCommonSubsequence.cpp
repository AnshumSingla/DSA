#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find LCS
string longestCommonSubsequence(string s1, string s2)
{
  int m = s1.length(), n = s2.length();
  // Create DP table
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  // Build the DP table (bottom-up)
  for (int i = 1; i <= m; ++i)
  {
    for (int j = 1; j <= n; ++j)
    {
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  // Reconstruct the LCS string from the DP table
  int i = m, j = n;
  string lcs = "";
  while (i > 0 && j > 0)
  {
    if (s1[i - 1] == s2[j - 1])
    {
      lcs = s1[i - 1] + lcs;
      --i;
      --j;
    }
    else if (dp[i - 1][j] > dp[i][j - 1])
      --i;
    else
      --j;
  }

  return lcs;
}

int main()
{
  string s1 = "AGGTAB";
  string s2 = "GXTXAYB";

  string lcs = longestCommonSubsequence(s1, s2);

  cout << "Longest Common Subsequence = " << lcs << endl;

  return 0;
}
