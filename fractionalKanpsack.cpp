#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to store item with profit and weight
struct Item
{
  int profit, weight;
};

// Comparison function to sort items by profit/weight ratio
bool cmp(Item a, Item b)
{
  double r1 = (double)a.profit / a.weight;
  double r2 = (double)b.profit / b.weight;
  return r1 > r2;
}

// Function to return maximum total profit in the knapsack
double fractionalKnapsack(int W, vector<Item> items)
{
  // Sort items by profit/weight ratio
  sort(items.begin(), items.end(), cmp);

  double totalProfit = 0.0;

  for (Item i : items)
  {
    if (W >= i.weight)
    {
      // Take full item
      W -= i.weight;
      totalProfit += i.profit;
    }
    else
    {
      // Take fraction of item
      totalProfit += i.profit * ((double)W / i.weight);
      break;
    }
  }

  return totalProfit;
}

int main()
{
  vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
  int W = 50;

  double maxProfit = fractionalKnapsack(W, items);
  cout << "Maximum Profit: " << maxProfit << endl;

  return 0;
}
