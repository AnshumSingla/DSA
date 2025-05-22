#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &graph, vector<int> &colors, int v, int c, int n)
{
  for (int i = 0; i < n; i++)
  {
    if (graph[v][i] && colors[i] == c)
      return false;
  }
  return true;
}

bool graphColoringUtil(vector<vector<int>> &graph, int m, vector<int> &colors, int v, int n)
{
  if (v == n)
    return true;

  for (int c = 0; c < m; c++)
  {
    if (isSafe(graph, colors, v, c, n))
    {
      colors[v] = c;
      if (graphColoringUtil(graph, m, colors, v + 1, n))
        return true;
      colors[v] = -1;
    }
  }
  return false;
}

int main()
{
  int n;
  cout << "Enter the number of vertices: ";
  cin >> n;

  int m;
  cout << "Enter the number of colors: ";
  cin >> m;

  vector<vector<int>> graph(n, vector<int>(n, 0));
  cout << "Enter the adjacency matrix:\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      cout << "Enter value for position [" << i << "][" << j << "]: ";
      cin >> graph[i][j];
      graph[j][i] = graph[i][j];
    }
  }

  vector<int> colors(n, -1);

  if (graphColoringUtil(graph, m, colors, 0, n))
  {
    cout << "Solution exists!\nColor assignments: ";
    for (int i = 0; i < n; i++)
    {
      cout << colors[i] << " ";
    }
  }
  else
  {
    cout << "Solution does not exist for " << m << " colors";
  }

  return 0;
}