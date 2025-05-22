#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void topologicalSort(int v, vector<bool> &visited, stack<int> &s, vector<vector<int>> &graph, int n)
{
  visited[v] = true;
  for (int i = 0; i < n; i++)
  {
    if (graph[v][i] && !visited[i])
    {
      topologicalSort(i, visited, s, graph, n);
    }
  }
  s.push(v);
}

int main()
{
  int n;
  cout << "Enter the number of vertices: ";
  cin >> n;

  vector<bool> visited(n, false);
  stack<int> s;

  vector<vector<int>> graph(n, vector<int>(n, 0));
  
  cout << "Enter pairs of vertices (from to) that have an edge between them:\n";
  for (int i = 0; i < n; i++)
  {
    int from, to;
    cin >> from >> to;
    if (from >= 0 && from < n && to >= 0 && to < n)
    {
      graph[from][to] = 1;
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      topologicalSort(i, visited, s, graph, n);
    }
  }

  cout << "Topological Sort: ";
  while (!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }
  return 0;
}
