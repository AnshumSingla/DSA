#include <iostream>
#include <vector>
using namespace std;

#define V 5

bool isSafe(int v, bool graph[V][V], vector<int> &path, int pos)
{
  // Check if current vertex is adjacent to the previous vertex in path
  if (!graph[path[pos - 1]][v])
    return false;

  // Check if vertex has already been included
  for (int i = 0; i < pos; i++)
    if (path[i] == v)
      return false;

  return true;
}

bool hamCycleUtil(bool graph[V][V], vector<int> &path, int pos)
{
  if (pos == V)
  {
    // If last vertex is connected to the first vertex
    return graph[path[pos - 1]][path[0]] == 1;
  }

  for (int v = 1; v < V; v++)
  {
    if (isSafe(v, graph, path, pos))
    {
      path[pos] = v;

      if (hamCycleUtil(graph, path, pos + 1))
        return true;

      path[pos] = -1; // Backtrack
    }
  }
  return false;
}

bool hamCycle(bool graph[V][V])
{
  vector<int> path(V, -1);
  path[0] = 0; // Start from vertex 0

  if (!hamCycleUtil(graph, path, 1))
  {
    cout << "No Hamiltonian Cycle exists.\n";
    return false;
  }

  // Print Hamiltonian Cycle
  cout << "Hamiltonian Cycle exists:\n";
  for (int i = 0; i < V; i++)
    cout << path[i] << " ";
  cout << path[0] << endl; // Return to starting point
  return true;
}

int main()
{
  bool graph[V][V] = {
      {0, 1, 0, 1, 0},
      {1, 0, 1, 1, 1},
      {0, 1, 0, 0, 1},
      {1, 1, 0, 0, 1},
      {0, 1, 1, 1, 0}};

  hamCycle(graph);
  return 0;
}
