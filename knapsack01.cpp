#include <iostream>
#include <vector>
using namespace std;

void knapsack(int N, int W, vector<int> &profit, vector<int> &weight)
{
  vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

  // Build DP table
  for (int i = 1; i <= N; i++)
  {
    for (int w = 0; w <= W; w++)
    {
      if (weight[i - 1] <= w)
        dp[i][w] = max(dp[i - 1][w], profit[i - 1] + dp[i - 1][w - weight[i - 1]]);
      else
        dp[i][w] = dp[i - 1][w];
    }
  }

  // Backtrack to find selected items
  int w = W;
  vector<int> selectedItems;
  for (int i = N; i > 0 && w > 0; i--)
  {
    if (dp[i][w] != dp[i - 1][w])
    {
      selectedItems.push_back(i); // Item i was included
      w -= weight[i - 1];
    }
  }

  // Output
  cout << "Items selected: ";
  for (int i = selectedItems.size() - 1; i >= 0; i--)
    cout << "Item " << selectedItems[i] << " ";
  cout << "\nMaximum profit: " << dp[N][W] << endl;
}

int main()
{
  int N = 4, W = 7;
  vector<int> profit = {5, 3, 8, 6};
  vector<int> weight = {2, 3, 4, 5};

  knapsack(N, W, profit, weight);

  return 0;
}
